 
/* VHDL to C++ translator    

   Copyright (C) 1999, 2000 Edwin Naroska.

   V2CC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   V2CC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with V2CC; see the file COPYING.  If not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.

 */

/* This program translates the original VHDL source into C++.
 
   Usage:

   v2cc [-v] [-l lib] file...

       -v             verbose
       -l lib         use lib as the WORK library, default is "."
       -o file        write output to FILE
       --depend=file  write dependency information to FILE

       file...        the design units to translate

*/

using namespace std;

#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_GETOPT_H
#include <getopt.h>
#endif
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <algorithm>

#include <freehdl/vaul.h>
#include "mapping.h"
#include "v2cc-chunk.h"
#include "v2cc-util.h"


// Declare here for now -- TLD
void emit_includes(string &str);
string sprint_acl(list<string> &acl_list, const string acl_object);
pIIR_LibraryUnit get_library_unit(pIIR_DeclarativeRegion d);


// ******************************************************************************************
// Implementation of member functions declared in v2cc.h
// ******************************************************************************************

// Returns true if range r and the current instance cover the same
// range
bool 
RangeDescriptor::is_equal_to(const RangeDescriptor &r) 
{
  assert(range_attribute == NULL);// Currently not supported
  return (left == r.left) && (right == r.right) && (direction == r.direction);
}

// Convert a RangeDescriptor into corresponding integer values and
// the direction. A boolean vector is returned where each item stores
// whether the corresponding bound could be statically determined
// (true).
StaticRangeDescriptor<lint, IR_Direction>
RangeDescriptor::rangedes_to_lint(RegionStack &rstack)
{
  StaticRangeDescriptor<lint, IR_Direction> range;
  range.valid.resize (3);

  string str;
  bool ok = true;

  // If range is not explicit then return false
  if (!is_explicit_range()) {
    fill(range.valid.begin(), range.valid.end(), false);
    return range;
  }

  // Try to convert the left bounds to integer values
  constant_fold(left, rstack);
  if (valid_folded_value(left))
    range.left = get_folded_value(left).long_value();
  else
    ok = false; // If the expression is not simple then flag an error
  
  range.valid [0] = ok;

  // Store range direction
  range.dir = direction;
  range.valid [1] = true;

  // Try to convert the right bounds to integer values
  ok = true;
  constant_fold(right, rstack);
  if (valid_folded_value(right))
    range.right = get_folded_value(right).long_value();
  else
    ok = false; // If the expression is not simple then flag an error

  range.valid [2] = ok;

  return range;
}


// Convert a RangeDescriptor into corresponding double values and
// the direction. A boolean vector is returned where each item stores
// whether the corresponding bound could be statically determined
// (true).
StaticRangeDescriptor<double, IR_Direction>
RangeDescriptor::rangedes_to_double(RegionStack &rstack)
{
  StaticRangeDescriptor<double, IR_Direction> range;
  range.valid.resize (3);

  string str;
  bool ok = true;
  
  // If range is not explicit then return false
  if (!is_explicit_range()) {
    fill(range.valid.begin(), range.valid.end(), false);
    return range;
  }

  // Try to convert the left bounds to integer values
  constant_fold(left, rstack);
  if (valid_folded_value(left))
    range.left = get_folded_value(left).double_value();
  else
    ok = false; // If the expression is not simple then flag an error
  
  range.valid [0] = ok;

  // Store range direction
  range.dir = direction;
  range.valid [1] = true;

  // Try to convert the right bounds to integer values
  ok = true;
  constant_fold(right, rstack);
  if (valid_folded_value(right))
    range.right = get_folded_value(right).double_value();
  else
    ok = false; // If the expression is not simple then flag an error

  range.valid [2] = ok;

  return range;
}


// Convert a RangeDescriptor into corresponding integer value strings
// and the direction strings. If a bound is not locally static then
// appropriate code is emitted to extract the corresponding values
// from the object. A boolean vector is returned where each item
// stores whether the corresponding bound could be statically
// determined (true).
StaticRangeDescriptor<string, string>
RangeDescriptor::rangedes_to_string(RegionStack &rstack, id_type t)
{
  StaticRangeDescriptor<string, string> range;
  range.valid.resize (3);

  bool ok = true;

  // First, try to constant fold the range attribute expression
  constant_fold_rangedes(rstack);

  if (range_attribute != NULL) {
    // Range is specified via the RANGE or REVERSE_RANGE attribute
    
    bool reverse_range;
    if (range_attribute->is(IR_ATTR_ARRAY_RANGE))
      reverse_range = false;
    else if (range_attribute->is(IR_ATTR_ARRAY_REVERSE_RANGE))
      reverse_range = true;
    else
      assert(false);

    string info_instance_str;
    if (range_attribute->array != NULL) {
      // The range attribute has been applied on an array
      // instance. First, emit code to extract the info instance from
      // the array.
      emit_expr (range_attribute->array, info_instance_str, rstack, t);
      info_instance_str += ".info";
      
    } else {
      // The range attribute has been applied on an array type. Emit
      // code to reference the range corresponding info instance.
      info_instance_str += qid(get_declaration(range_attribute->array_type), rstack, INFO) + "_INFO";
      
    }
    
    // Get index number. Note that the index number must be locally
    // static.
    int index_number = 1;
    if (range_attribute->index != NULL)
      index_number = (int)get_folded_value(range_attribute->index).long_value();
    // Build code to access the array info instance which
    // corresponds with the index_number
    for (int i = 1; i < index_number; i++)
      info_instance_str = "((array_info*)" + info_instance_str + "->element_type)";

    // Print left, right and direction string depending on whether the
    // attribute RANGE or REVERSE_RANGE is used. When printing the
    // bounds check whether the bounds can be determined at compile
    // time.
    if (left != NULL) {
      constant_fold(left, rstack);
      range.valid [0] = emit_expr (left, range.left, rstack, t);
    } else {
      if (reverse_range)
	range.left = info_instance_str + "->right_bound";
      else
	range.left = info_instance_str + "->left_bound";
      range.valid [0] = false;
    }

    if (right != NULL && left != NULL) {
      range.dir = direction == IR_DIRECTION_UP? "to" : "downto";
      range.valid [1] = true;
    } else {
      if (reverse_range)
	range.dir =  "(" + info_instance_str + "->index_direction==to?downto:to)";
      else
	range.dir = info_instance_str + "->index_direction";
      range.valid [1] = false;
    }

    if (right != NULL) {
      constant_fold(right, rstack);
      range.valid [2] = emit_expr (right, range.right, rstack, t);
    } else {
      if (reverse_range)
	range.right = info_instance_str + "->left_bound";
      else
	range.right = info_instance_str + "->right_bound";
      range.valid [2] = false;
    }

  } else {
    // Range is explicit defined

    // Convert the left bounds to integer values
    constant_fold(left, rstack);
    range.valid [0] = emit_expr (left, range.left, rstack, t);
    
    // Store range direction
    range.dir = direction == IR_DIRECTION_UP? "to" : "downto";
    range.valid [1] = true;
    
    constant_fold(right, rstack);
    range.valid [2] = emit_expr (right, range.right, rstack, t);
  }

  return range;
}



// Same as previos method. However, string are generated according
// to CDFG rules.
StaticRangeDescriptor<string, string>
RangeDescriptor::cdfg_rangedes_to_string(RegionStack &rstack, id_type t)
{
  StaticRangeDescriptor<string, string> range;
  range.valid.resize (3);
  bool ok = true;

  // First, try to constant fold the range attribute expression
  constant_fold_rangedes(rstack);

  if (range_attribute != NULL) {
    // Range is specified via the RANGE or REVERSE_RANGE attribute
    
    bool reverse_range;
    if (range_attribute->is(IR_ATTR_ARRAY_RANGE))
      reverse_range = false;
    else if (range_attribute->is(IR_ATTR_ARRAY_REVERSE_RANGE))
      reverse_range = true;
    else
      assert(false);

    string info_instance_str;
    if (range_attribute->array != NULL) {
      // The range attribute has been applied on an array
      // instance. First, emit code to extract the info instance from
      // the array.
      cdfg_emit_expr (range_attribute->array, info_instance_str, rstack, t);
      
    } else {
      // The range attribute has been applied on an array type. Emit
      // code to reference the range corresponding info instance.
      info_instance_str = 
	get_escaped_string(get_long_name(get_declaration(range_attribute->array_type)));
      
    }
    
    // Get index number. Note that the index number must be locally
    // static.
    int index_number = 1;
    if (range_attribute->index != NULL)
      index_number = (int)get_folded_value(range_attribute->index).long_value();
    string index_number_string = to_string(index_number);

    // Print left, right and direction string depending on whether the
    // attribute RANGE or REVERSE_RANGE is used. When printing the
    // bounds check whether the bounds can be determined directly.
    if (left != NULL) {
      constant_fold(left, rstack);
      range.valid [0] = cdfg_emit_expr (left, range.left, rstack, t);
    } else {
      if (reverse_range)
	range.left = "(create-array-attribute-call right " + info_instance_str + " " + index_number_string + ")";
      else
	range.left = "(create-array-attribute-call left " + info_instance_str + " " + index_number_string + ")";
      range.valid [0] = false;
    }

    if (right != NULL && left != NULL) {
      range.dir = direction == IR_DIRECTION_UP? "to" : "downto";
      range.valid [1] = true;
    } else {
      if (reverse_range)
	range.dir = "(create-array-attribute-call-reverse direction " + info_instance_str + " " + index_number_string + ")";
      else
	range.dir = "(create-array-attribute-call direction " + info_instance_str + " " + index_number_string + ")";
      range.valid [1] = false;
    }

    if (right != NULL) {
      constant_fold(right, rstack);
      range.valid [2] = cdfg_emit_expr (right, range.right, rstack, t);
    } else {
      if (reverse_range)
	range.right = "(create-array-attribute-call left " + info_instance_str + " " + index_number_string + ")";
      else
	range.right = "(create-array-attribute-call right " + info_instance_str + " " + index_number_string + ")";
      range.valid [2] = false;
    }

  } else {
    // Range is explicit defined

    // Convert the left bounds to integer values
    constant_fold(left, rstack);
    range.valid [0] = cdfg_emit_expr (left, range.left, rstack, t);
    
    // Store range direction
    range.dir = direction == IR_DIRECTION_UP? "to" : "downto";
    range.valid [1] = true;
    
    constant_fold(right, rstack);
    range.valid [2] = cdfg_emit_expr (right, range.right, rstack, t);
  }

  return range;
}



int
RangeDescriptor::constant_fold_rangedes(RegionStack &rstack)
{
  int error_count = 0;

  if (range_attribute != NULL) {
    vector<RangeDescriptor> range_des_vec;

    if (range_attribute->array != NULL) {
      // There is nothing to do if the array subtype is an
      // unconstrained array type
      if (!is_constrained_array_type(range_attribute->array->subtype))
	return 0;
      // Get range descriptors from array object
      range_des_vec = get_discrete_range(range_attribute->array->subtype, rstack, IR_NOT_STATIC);
    } else if (range_attribute->array_type != NULL)
      // Get range descriptors from array type
      range_des_vec = get_discrete_range(range_attribute->array_type, rstack, IR_NOT_STATIC);
    else
      assert(false);
  
    // Constant fold corresponding range descriptor
    int dim_number = 1;
    if (range_attribute->index) {
      constant_fold(range_attribute->index, rstack);
      assert(valid_folded_value(range_attribute->index));
      dim_number = folded_value(range_attribute->index).long_value();
    }
    RangeDescriptor &range_des = range_des_vec[dim_number - 1];
    error_count += range_des.constant_fold_rangedes(rstack);
  
    if (range_des.range_attribute != NULL)
      return error_count;

    if (range_attribute->is(IR_ATTR_ARRAY_RANGE)) {
      left = range_des.left;
      direction = range_des.direction;
      right = range_des.right;
    } else if (range_attribute->is(IR_ATTR_ARRAY_REVERSE_RANGE)) {
      left = range_des.right;
      direction = range_des.direction == IR_DIRECTION_UP? IR_DIRECTION_DOWN : IR_DIRECTION_UP;
      right = range_des.left;
    } else
      assert(false);
  }

  if (left != NULL)
    if (left->is(IR_EXPRESSION))
      error_count += constant_fold(pIIR_Expression(left), rstack);
    else
      error_count += constant_fold(pIIR_Literal(left), rstack);

  if (right != NULL)
    if (right->is(IR_EXPRESSION))
      error_count += constant_fold(pIIR_Expression(right), rstack);
    else
      error_count += constant_fold(pIIR_Literal(right), rstack);

  return error_count;
}



/* Exit the program with a usage message.  */
void
usage ()
{
  fprintf (stderr, "usage: %s [-v] [-l lib] [-L libdir] file...\n", vaul_application_name);
  exit (1);
}

vaul_parser_options parser_options;

bool try_vhdl_source (char *fn)
{
  for (char *cp = fn; *cp; cp++)
    *cp = tolower(*cp);
  return access (fn, R_OK) == 0;
}

char *
find_vhdl_source (char *l, char *n)
{
  char *fn = vaul_aprintf ("../libvaul/vlib/%s/%s.vhd", l, n);
  if (try_vhdl_source (fn))
    return fn;
  free (fn);
  fn = vaul_aprintf ("../libvaul/vlib/%s/%s.vhdl", l, n);
  try_vhdl_source (fn);
  return fn;
}

mypool::mypool () {
  mapper = make_v2cc_mapper ();
  dependencies_file = NULL;
}

vaul_design_unit *
mypool::get (char *l, char *n)
{
  vaul_design_unit *du = vaul_pool::get (l, n);
  if (du == NULL)
    {
      char *fn = mapper->find_design_file (l, n);

      if (fn == NULL)
	return NULL;

      if (codegen_options.get_verbose ())
	fprintf (stderr, "reading %s.%s from %s\n", l, n, fn);

      // We are only interested in packages and entities, so we
      // instruct the parser to skip over the rest.
      vaul_parser_options opts = parser_options;
      opts.set_skip_bodies (true);
      vaul_design_file df(fn, NULL, opts);

      begin_session (l);
      while (vaul_design_unit * du = df.read_design_unit (this))
	{
	  insert (du);
	  if (du->is_error ())
	    du->print_err (fn);
	  du->release ();
	}
      if (df.is_error ())
	df.print_err (fn);
      end_session ();

      du = vaul_pool::get (l, n);

      if (dependencies_file && du && !du->is_error ())
	fprintf (dependencies_file, " %s", fn);

      delete[] fn;
    }

  return du;
}

mypool vaul;

#ifndef HAVE_GETOPT_H
struct option {
  const char *name;
  int has_arg;
  int *flag;
  int val;
};

#define no_argument       0
#define required_argument 1
#define optional_argument 2

extern "C" int getopt_long (int argc, char * const argv[],
			    const char *optstring,
			    const struct option *longopts, int *longindex);
#endif /* HAVE_GETOPT_H */

extern int optind, opterr;
extern char *optarg;

/* Parse FILE and output translation of all contained units to
   strings. Return true on success, false otherwise.
*/
bool emit (vaul_pool *pool, char *file, string &str, string &cdfg_str, string &main_cc_str);

void init_v2cc_chunk ();

bool dry_run = false;

struct option long_options[] = {
  { "relaxed-component-visibility", 0, 0, 0 },
  { "depend", required_argument, 0, 0 },
  { 0, 0, 0, 0 }
};

int
main (int argc, char *argv[])
{
  int opt, option_index;
  const char *libname = "work";
  char *generated_cc_file_name = NULL;
  char *main_cc_file_name = NULL;
  
  vaul_application_name = "v2cc";

  opterr = 0;
  
  while ((opt=getopt_long (argc, argv, "vnl:L:RgDo:m:",
			   long_options, &option_index)) != -1)
    {
      switch (opt)
	{
	case 0:
	  {
	    switch (option_index)
	      {
	      case 0:  // allow_invisible_default_bindings_from_work
		parser_options.
		  set_allow_invisible_default_bindings_from_work (true);
		break;
	      case 1:  // depend
		{
		  FILE *depf = fopen (optarg, "w");
		  if (depf == NULL)
		    {
		      perror (optarg);
		      exit (1);
		    }
		  vaul.dependencies_file = depf;
		}
		break;
	      }
	  }
	  break;
	case 'v':
	  codegen_options.set_verbose (true);
	  parser_options.set_debug (true);
	  parser_options.set_fullnames (true);
	  tree_set_verbose (true);
	  break;
	case 'l':
	  libname =  optarg;
	  break;
	case 'L':
	  vaul.mapper->add_libdir (optarg);
	  break;
	case 'm':
	  codegen_options.set_emit_main_cc_code (true);
	  codegen_options.set_main_cc_filename (optarg);
	  break;
	case 'n':
	  dry_run = true;
	  break;
	case 'R':
	  codegen_options.set_emit_register_code (true);
	  break;
	case 'g':
	  codegen_options.set_emit_debug_code (true);
	  break;
	case 'D':
	  codegen_options.set_emit_cdfg_code (true);
	  break;
	case 'o':
	  generated_cc_file_name = strdup (optarg);
	  break;
	case '?':
	  usage ();
	  break;
	}
    }
  
  vaul.mapper->add_default_libdirs ();

  if (optind >= argc || argc-1 > optind)
    usage ();
  
  init_v2cc_chunk ();

  if (vaul.dependencies_file)
    fprintf (vaul.dependencies_file, "%s:", generated_cc_file_name);

  bool success = true;
  vaul.begin_session ((char*)libname);
  string str, cdfg_str, main_cc_str;
  vector<string> source_file_names; // Stores vhdl source files names
  emit_includes (str);					// #includes for sim
  while (optind < argc)
    {
      if (vaul.dependencies_file)
	fprintf (vaul.dependencies_file, " %s", argv[optind]);
      source_file_names.push_back (string (argv [optind]));
      success = emit (&vaul, argv[optind], str, cdfg_str, main_cc_str) && success;
      optind++;
    }

  if (success)
    {
      if (generated_cc_file_name != NULL) {
	ofstream outfile(generated_cc_file_name);
	outfile << str;
	outfile.close();
      } else {
	cout << str;
	cout.flush();
      }

      // If CDFG code shall be emitted ...
      if (codegen_options.get_emit_cdfg_code ()) 
	{
	  ofstream cdfg_file;
	  // Generate file name for CDFG code. Usually, the .vhdl
	  // extension is replaced by .cdfg.lsp
	  string file_name = source_file_names.front ();
	  file_name.erase(file_name.rfind('.'));
	  // If the file did not have any extension then use the first
	  // entire file name as base for the output file name
	  if (file_name == "")
	    file_name = source_file_names.front ();
	  file_name += ".cdfg.lsp";
	  cdfg_file.open(file_name.c_str());

	  // Write string to file
	  cdfg_file << cdfg_str;
	  cdfg_file.close(); // Close CDFG file
	}

      // If the main routine shall be emitted, then...
      if (codegen_options.get_emit_main_cc_code () &&
	  codegen_options.get_main_cc_filename () != "")
	{
	  ofstream main_cc_file;
	  main_cc_file.open (codegen_options.get_main_cc_filename ().c_str());

	  // Write string to file
	  main_cc_file << main_cc_str;
	  main_cc_file.close(); // Close CDFG file
	}
    }

  vaul.end_session ();

  if (vaul.dependencies_file)
    {
      fprintf (vaul.dependencies_file, "\n");
      fclose (vaul.dependencies_file);
      vaul.dependencies_file = NULL;
    }

  return success? 0 : 1;
}


bool
emit (vaul_pool *pool, char *file, string &str, string &cdfg_str, string &main_cc_str)
{
  vaul_design_file df(file, NULL, parser_options);

  // Create a root node to store global code. Note that it is
  // important to have an SINGLE root node for all designs stored in
  // the design file in order to keep track of global definitions
  // common to all current designs.
  pIIR_DeclarativeRegion root_node = new IIR_DeclarativeRegion(NULL, NULL, NULL, NULL, 0, NULL, NULL);
  // Protect node so that it it is not removed by the garbage
  // collector
  tree_protect(root_node);

  bool success = true;

  // Vector to store all design units that are found in the source
  // file.
  vector<vaul_design_unit *> du_vec;

  // First, parse *all* design units. This is done in order to be able
  // to find out which design units are dublicate and shall not be
  // emitted.
  while (vaul_design_unit *du = df.read_design_unit (pool))
    {
      pool->insert (du); 
      if (du->is_error ())
	{
	  du->print_err (file);
	  success = false;
	}
      du_vec.push_back (du);
    }

  // Check for duplicate design units. Note that it is legal in VHDL
  // to redefine a enitity. In this case, the last definition should
  // overide any previous ones... First, generate an id string for
  // each library unit.
  vector<string> ids (du_vec.size ());
  for (unsigned int i = 0; i < du_vec.size (); i++)
    {
      RegionStack rstack;
      rstack.push(root_node);
      // Generate a unique id string from 
      ids [i] = qid (du_vec [i]->get_tree (), rstack, id_type ());
    }
  // Finally, search for dublicates and mark all dublicates with the
  // exception of the last one.
  for (int i = du_vec.size () - 1; i >= 1; i--)
    {
      for (int j = i - 1; j >= 0; j--)
	if (ids [j] == ids [i])
	  {
	    codegen_error.info("%:warning: definition of library unit %n is overwritten by same named unit defined in line %;.", 
			       du_vec [j]->get_tree (), du_vec [j]->get_tree (),
			       du_vec [i]->get_tree ());
	    generate_code (du_vec [j]->get_tree ()) = false;
	  }
    }
  

  if (success && !dry_run)
    for (unsigned int i = 0; i < du_vec.size (); i++)
      {
	vaul_design_unit *du = du_vec [i];

	if (codegen_options.get_verbose ())
	  fprintf (stderr, "emitting %s/%s\n",
		   du->get_library (), du->get_name ());

	RegionStack rstack;
	// Remove declarations from root node and push it on the
	// context stack
	root_node->declarations = NULL;
	extended_declarations(root_node) = NULL;
	rstack.push(root_node);
	
	// Set prefix name for internal variables
	set_internal_prefix_start(du->get_tree(), rstack);

	// Check VHDL code and prepare code for code generation!
	pIIR_LibraryUnit lu = du->get_tree();
	if (explore_and_check(lu, rstack, true))
	  success = false;

	// Generate code if no error occured and if code shall be
	// generated for this library unit.
	if (success && generate_code (lu))
	  {
	    string code;
	    if (codegen_options.get_emit_debug_code ())
	      code = "#line 1000000 __FILE__\n";
	
	    emit_decl (lu, code, rstack, 0);
	    str += code;
	  }

	// If CDFG code shall be emitted ...
	if (success && codegen_options.get_emit_cdfg_code ()) 
	  {
	    // Call cdfg_emit_impl to print CDFG code into a string
	    cdfg_emit_impl(lu, cdfg_str, rstack, 0);
	  }
	
	// If main code shall be emitted ...
	if (success && codegen_options.get_emit_main_cc_code ()) 
	  {
	    main_cc_str = ""; // Only the last emitted main code is
	    // needed. Hence, clear string before
	    // calling emit_main.
	    emit_main (lu, main_cc_str, rstack, 0);
	  }
	
	// Push context from stack
	rstack.pop();
	
	if (codegen_error.n_errors)
	  exit(1);
      }

  for (unsigned int i = 0; i < du_vec.size (); i++)
    du_vec [i]->release();
  
  // Allow garbage collector to destroy root node
  tree_unprotect(root_node);

  return success;
}




/*
 * Utility
 */

void
emit_includes(string &str)
{
  str += string ("#include <freehdl/kernel.h>\n") +
    string ("#include <freehdl/std.h>\n\n\n") 
    // + 
    //string ("#ifdef CC_FILE_NAME\n") +
    //string ("#undef CC_FILE_NAME\n") +
    //string ("#endif\n") +
    //string ("#define CC_FILE_NAME __FILE__\n")
    ;
}


// ******************************************************************************************
// Name: get_library_unit
//
// Description: returns library unit a declarative region belongs to
//
// Parameter: pIIR_DeclarativeRegion d = declarative region
// 
// Return value: library unit
//
// ******************************************************************************************

pIIR_LibraryUnit
get_library_unit(pIIR_DeclarativeRegion d)
{
  while (d != NULL && !d->is(IR_LIBRARY_UNIT)) {
    d = d->declarative_region;
  }
    
  return (pIIR_LibraryUnit)d;
}

// returns name of the libraray
char *
get_lib_name(pIIR_DeclarativeRegion r)
{
  pIIR_LibraryUnit lu = get_library_unit(r); 

  return lu->library_name->text.to_chars();
}


// ******************************************************************************************
// Name: m_get_operator_type (generic function)
//
// Description: returns type of an operator. Possible values are:
//   - NO_OP if the function does not denote an operator
//   - STD_OP if the funcion denotes an predefined VHDL operator
//   - BASIC_OP if the function denotes an operator defined in an 
//           IEEE library (e.g. numeric_std)
//   - USER_OP an user defined operator
//
// Parameter: pIIR_FunctionDeclaration f = pointer to function declaration
// 
// Return value: op_type
//
// ******************************************************************************************

op_type
m_get_operator_type(pIIR_ProcedureDeclaration pd)
{
  return NO_OP;
}

op_type
m_get_operator_type(pIIR_FunctionDeclaration fd)
{
  char *function_str = fd->declarator->text.to_chars(); // Get function name

  if (function_str[0] != '"') // Is function not an operator?
    return NO_OP;

  char *libname = get_lib_name(fd->declarative_region);

  if (!strcmp(libname, "std") ||
      fd->is(IR_PREDEFINED_FUNCTION_DECLARATION))
    // Function is defined in library "std" or a predefined VHDL
    // operator
    return STD_OP;
  else if (!strcmp(libname, "ieee"))
    // Function is defined in library "ieee"
    return BASIC_OP;
  else
    return USER_OP;
}





