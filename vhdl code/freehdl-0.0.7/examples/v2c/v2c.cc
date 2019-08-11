/* VHDL to pseudo C translator    

   Copyright (C) 1994-1997 University of Dortmund
   Department of Electrical Engineering, AG SIV

   VAUL is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   VAUL is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with VAUL; see the file COPYING.  If not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.


 */

/* This is a small program that shows how one could parse the
   generated syntax graph.

   It translates the original VHDL code to something similar to
   C. (Once upon a time, the generated C code could actually be
   compiled!) But many semantics of VHDL are too complicated to be
   easily translated into C.

   Usage:

   v2c [-v -l lib] file...

       -v             verbose
       -n             don't use declaration cache
       -l lib         use lib as the WORK library, default is "."
       
       file...        the design units to translate

*/

#include <freehdl/vaul.h>
#include <freehdl/tree-supp.h>
#include "v2c-chunk.h"

#include <ctype.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <stdlib.h>

/* Exit the program with a usage message.
*/
void
usage ()
{
  fprintf (stderr, "usage: %s [-v] [-n] [-g num] [-l lib] file...\n",
	   vaul_application_name);
  exit (1);
}

bool verbose = false;
vaul_parser_options parser_options;

/* The default working library. Can be overwritten with the
   -l command line option.
*/
const char *libname = ".";

struct mypool : vaul_pool {
  vaul_design_unit *get (char *library, char *name);
};

bool try_vhdl_source (char *fn)
{
  for (char *cp = fn; *cp; cp++)
    *cp = tolower(*cp);
  return access (fn, R_OK) == 0;
}

char *
find_vhdl_source (char *l, char *n)
{
  char *fn = vaul_aprintf ("vlib/%s/%s.vhd", l, n);
  if (try_vhdl_source (fn))
    return fn;
  free (fn);
  fn = vaul_aprintf ("vlib/%s/%s.vhdl", l, n);
  try_vhdl_source (fn);
  return fn;
}

vaul_design_unit *
mypool::get (char *l, char *n)
{
  vaul_design_unit *du = vaul_pool::get (l, n);
  if (du == NULL)
    {
      char *fn = find_vhdl_source (l, n);
      vaul_design_file df(fn, NULL, parser_options);

      if (df.is_error () && df.get_error () == ENOENT)
	{
	  /* Be silent about non-existent files.  maybe we don't need
	     it after all.  This happens with use work.all, for
	     example. */

	  /* XXX - this is slow, of course.  Better find a way to
     	     avoid following use clauses needlessly. */
	  
	  if(verbose)
	    fprintf (stderr, "psst: %s: %s\n", fn, df.get_error_desc ());
	  free (fn);
	  return NULL;
	}

      fprintf (stderr, "for %s/%s: reading %s\n", l, n, fn);

      begin_session (l);
      while (vaul_design_unit *du = df.read_design_unit (this))
	{
	  insert (du);
	  if (du->is_error ())
	    du->print_err (fn);
	  du->release();
	}
      if (df.is_error ())
	df.print_err (fn);
      end_session ();

      free (fn);
      
      du = vaul_pool::get (l, n);
    }

  return du;
}

mypool vaul;

extern int optind, opterr;
extern char *optarg;
extern "C" int getopt (int, char *const *, const char *);

/* Parse FILE and output translation of all contained units to STDOUT.
   In case of failure, prints some messages to STDERR and
   return FALSE, else returns TRUE.  */
bool emit (vaul_pool *pool, char *file);

/* Various translators for various node types. The occasional
   INT parameter controls indentation.
*/
void emit (pIIR_Declaration, int);
void emit (pIIR_Type);
void emit (pIIR_InterfaceDeclaration);
void emit (pIIR_SequentialStatementList, int);
void emit (pIIR_Expression);
void emit (pIIR_TypeList);
void emit (pIIR_Range);
void emit_block (pIIR_BlockStatement, int);
void emit_binding (pIIR_Declaration,
		   pIIR_AssociationList, pIIR_AssociationList);
void emit (pIIR_ConcurrentStatementList, int);
#if 0
void emit (pIIR_ConfigurationSpecification);
#endif
void emit (pIIR_BindingIndication);
void emit (pVAUL_DelayMechanism);

void emit_decls (pIIR_DeclarativeRegion, int);
void emit_id (pIIR_Declaration);
void emit_id (pIIR_Type);
bool emit_associations (pIIR_AssociationList assocs,
			pIIR_InterfaceList formals);
void emit_builtin_id (IR_Kind);
void emit_lit (pIIR_Literal lit);
void emit_delay (IR_DelayMechanism, pIIR_Expression time);

void emit_attributes (pIIR_Declaration d, int l);

void init_fire_chunk ();
void init_vaul_chunk ();
void init_vaulgens_chunk ();
void init_v2c_chunk ();

int
main (int argc, char *argv[])
{
    int opt;

    vaul_application_name = "v2c";

    opterr = 0;

    while ((opt=getopt (argc, argv, "vnl:g:")) != -1) {
      switch (opt)
	{
	case 'v':
	  verbose = true;
	  parser_options.set_fullnames (true);
	  parser_options.set_debug (true);
	  tree_set_verbose (true);
	  break;
	case 'l':
	  libname =  optarg;
	  break;
	case 'n':
	  parser_options.set_nocache (true);
	  break;
	case 'g':
	  tree_set_gc_thresh (atoi (optarg));
	  break;
	case '?':
	  usage ();
	  break;
	}
    }

    if (optind >= argc || argc-1 > optind)
      usage ();

    init_v2c_chunk ();

    bool success = true;
    vaul.begin_session ((char*)libname);
    while (optind < argc)
      {
	success = emit (&vaul, argv[optind]) && success;
	optind++;
      }
    vaul.end_session ();
    return success? 0 : 1;
}

struct my_consumer : vaul_consumer {

  void init ();

  virtual void push_conc_context (pIIR_DeclarativeRegion context);
  virtual bool consume_conc_stat (pIIR_ConcurrentStatement stat);
  virtual void pop_conc_context (pIIR_DeclarativeRegion context);

  int interested;

  pIIR_DeclarativeRegion context;
  int indent;

  virtual bool consume_pbody_decl (pIIR_Declaration decl);
};

bool
emit (vaul_pool *pool, char *file)
{
  vaul_design_file df(file, NULL, parser_options);
  my_consumer consumer;

  bool success = true;
  consumer.init ();
  while (vaul_design_unit *du = df.read_design_unit (pool, &consumer))
    {
      pool->insert (du);
      if (du->is_error ())
	{
	  du->print_err (file);
	  success = false;
	}
      else
	{
	  pIIR_DeclarativeRegion unit = du->get_tree ();
	  // tree_print ("topunit", unit, 5);
	  if (unit->is(IR_PACKAGE_DECLARATION)
	      || unit->is(IR_CONFIGURATION_DECLARATION))
	    emit (unit, 0);
	}
      du->release();
      consumer.init ();
    }
  if (df.is_error ())
    {
      df.print_err (file);
      success = false;
    }

  return success;
}

/* Return a string of L spaces, but at most 30.  
 */
const char *
spaces (int l)
{
  if (l < 0)
    return "<<";
  if (l > 30)
    l = 30;
  return "                              " + (30-l);
}

void
my_consumer::init ()
{
  context = NULL;
  indent = 0;
  interested = false;
}

/* Return true for all contexts of concurrent statements that we are
   willing to deal with incrementally.
*/
bool
is_composite_context (pIIR_DeclarativeRegion context)
{
  return (context->is(IR_ARCHITECTURE_DECLARATION)
	  || context->is(IR_BLOCK_STATEMENT));
}

bool
is_leaf_stat (pIIR_ConcurrentStatement stat)
{
  return (stat->is(IR_PROCESS_STATEMENT)
	  || stat->is(IR_COMPONENT_INSTANTIATION_STATEMENT)
	  || stat->is(IR_CONCURRENT_GENERATE_STATEMENT));
}

void emit_comp_interface (pIIR_Component c);

void m_emit_start_of_context (pIIR_ArchitectureDeclaration a, int l)
{
  pIIR_EntityDeclaration e = a->entity;

  printf ("architecture<");
  emit_id (e);
  printf ("> ");
  emit_id (a);
  printf (" (");
  emit_comp_interface (a);
  printf (")\n");
  printf ("{\n");
  emit_decls (a, 2);
  printf ("\n");
  // XXX - emit disconnect specs
}

void m_emit_end_of_context (pIIR_ArchitectureDeclaration ctx, int l)
{
  printf ("}\n");
  emit_attributes (ctx, l);
}

void m_emit_start_of_context (pIIR_BlockStatement bs, int l)
{
  printf ("%sblock ", spaces(l));
  emit_binding (bs, bs->generic_map_aspect, bs->port_map_aspect);
  printf ("\n%s{\n", spaces (l));
  emit_decls (bs, l+2);
  if (bs->declarations)
    printf ("\n");
}

void m_emit_end_of_context (pIIR_BlockStatement ctx, int l)
{
  printf ("%s}\n", spaces (l));
  emit_attributes (ctx, l);
}

void
my_consumer::push_conc_context (pIIR_DeclarativeRegion ctx)
{
  interested = is_composite_context (ctx);
  context = ctx;

  if (interested)
    {
      if (parser->n_errors == 0)
	emit_start_of_context (context, indent);
      indent += 2;
    }
}

void
my_consumer::pop_conc_context (pIIR_DeclarativeRegion ctx)
{
  if (interested)
    {
      indent -= 2;
      if (parser->n_errors == 0)
	emit_end_of_context (context, indent);
    }
  else if (parser->n_errors == 0)
    {
      if (context->is(IR_CONCURRENT_STATEMENT))
	{
	  printf ("%s", spaces(indent));
	  emit_conc_stat (context, indent);
	}
      else
	emit (context, indent);
    }
    
  interested = ctx && is_composite_context (ctx);
  context = ctx;
}

bool
my_consumer::consume_conc_stat (pIIR_ConcurrentStatement stat)
{
  if (interested)
    {
      if (is_leaf_stat (stat) && parser->n_errors == 0)
	{
	  printf ("%s", spaces (indent));
	  emit_conc_stat (stat, indent);
	}
      return false;
    }
  else
    return true;
}

bool
my_consumer::consume_pbody_decl (pIIR_Declaration decl)
{
  if (parser->n_errors == 0)
    emit (decl, 0);
  return false;
}

/* Emit an UglyIdentifier as a beautiful_identifier.  */
void
emit_id (pIIR_TextLiteral idnode)
{
  char *id = idnode->text.to_chars();
  if (*id == '\\' || *id == '\'')
    printf ("%s", id);
  else 
    {
      bool break_on_caps = false;
      while (*id) 
	{
	  if (isupper(*id) && break_on_caps)
	    putchar('_');
	  break_on_caps = islower(*id);
	  putchar(tolower(*id++));
	}
    }
}

void emit_noqual_id (pIIR_Declaration);

/* Emit the qualified identifier of an declaration. Overloadable names
   are decorated to make them unique, but only if we are verbose.
*/
void
emit_qual_id (pIIR_Declaration d, const char *qual)
{
  if (d->is (IR_LIBRARY_UNIT))
    emit_id (pIIR_LibraryUnit(d)->library_name);
  else if (d->declarative_region)
    emit_qual_id (d->declarative_region, qual);
  printf ("%s", qual);
  emit_noqual_id (d);
}

void
emit_noqual_id (pIIR_Declaration d)
{
  if (d->declarator) 
    {
      if (d->is(IR_ENUMERATION_LITERAL) && verbose) 
	{
	  emit_noqual_id (pIIR_EnumerationLiteral(d)->subtype->declaration);
	  printf ("_");
	  if (d->declarator->is(IR_CHARACTER_LITERAL)) 
	    {
	      IR_Character ch = d->declarator->text[1];
	      if (isalnum(ch))
		printf ("%c", ch);
	      else
		printf ("%2x", unsigned(ch));
	    }
	  else
	    emit_id (d->declarator);
	}
      else
	{
	  emit_id (d->declarator);

	  if (d->is(IR_SUBPROGRAM_DECLARATION) && verbose) 
	    {
	      for(pIIR_InterfaceList il =
		    pIIR_SubprogramDeclaration(d)->interface_declarations;
		  il; il = il->rest)
		{
		  printf ("__");
		  emit_qual_id (il->first->subtype->declaration, "_");
		}
	      if(d->is(IR_FUNCTION_DECLARATION))
		{
		  printf ("__");
		  emit_qual_id (pIIR_FunctionDeclaration(d)->return_type->declaration, "_");
		}
	    }
	}
      printf ("_%d", d->seqno);
    }
  else
    printf("<anonymous>");
}

void
emit_id (pIIR_Declaration d)
{
  if (verbose)
    emit_qual_id (d, "::");
  else
    emit_noqual_id (d);
}

void
emit_id (pIIR_Type t)
{
  if (t->declaration)
    emit_id (t->declaration);
  else
    printf ("<anonymous %s>", t->kind_name());;
}

/* Emit all decls of a scope.
*/
void
emit_decls (pIIR_DeclarativeRegion s, int l)
{
  for (pIIR_DeclarationList dl = s->declarations; dl; dl = dl->rest)
    emit(dl->first, l);
}

/* Emit the definition of type T. If it is a subtype, try to express
   it in terms of its base type.
*/
void
m_emit_def (pIIR_Subtype t)
{
  if (t->immediate_base->declaration)
    emit_id (t->immediate_base->declaration);
  else
    emit_def (t->immediate_base);
}

void
m_emit_def (pIIR_IntegerType t)
{
  printf("int");
}

void
m_emit_def (pIIR_PhysicalType t)
{
  printf("int");
}

void
m_emit_def (pIIR_FloatingType t)
{
  printf("double");
}

void
m_emit_def (pIIR_EnumerationType t)
{
  printf("enum { ");
  for(pIIR_EnumerationLiteralList el = t->enumeration_literals;
      el; el = el->rest)
    {
      emit_id (el->first);
      if (el->rest)
	printf (", ");
    }
  printf(" }");
}

void
m_emit_def (pIIR_ArrayType t)
{
  emit (t->element_type);
  for(pIIR_TypeList it = t->index_types; it; it = it->rest) 
    {
      printf ("[");
      emit (it->first);
      printf ("]");
    }
}

void
m_emit_def (pIIR_RecordType t)
{
  printf("struct {\n");
  for (pIIR_ElementDeclarationList elts = t->element_declarations; elts;
       elts = elts->rest)
    {
      pIIR_ElementDeclaration re = elts->first;
      printf ("  ");
      emit (re->subtype);
      printf (" ");
      emit_id (re->declarator);
      printf (";\n");
    }
  printf ("}");
}

void
m_emit_def (pIIR_AccessType t)
{
  emit (t->designated_type);
  printf ("*");
}

void
m_emit_def (pIIR_FileType t)
{
  printf ("file<");
  emit (t->type_mark);
  printf (">");
}

void
m_emit_def (pIIR_Type t)
{
  printf ("/* emit_def %s */", t->kind_name ());
}

void
emit_comp_interface (pIIR_Component c)
{
  pIIR_InterfaceList gens = vaul_get_generics (c);
  pIIR_InterfaceList ports = vaul_get_ports (c);
  pIIR_InterfaceList i;

  for (i = gens; i; i = i->rest) 
    {
      emit (i->first);
      if (i->rest || ports)
	printf (", ");
    }
  for (i = ports; i; i = i->rest) 
    {
      emit (i->first);
      if (i->rest)
	printf (", ");
    }
}

void
emit_comp_body (pIIR_Component c)
{
  printf ("{\n");
  emit_decls (c, 2);
  printf ("\n");
  // XXX - emit disconnect specs
  emit (vaul_get_stats(c), 2);
  printf ("}\n");
}

char *
constant_fold_string_expr (pIIR_Expression e)
{
  if (e->is(IR_ARRAY_LITERAL_EXPRESSION)) 
    {
      char *val = pIIR_ArrayLiteralExpression(e)->value->text.to_chars();
      val = vaul_xstrdup (val+1);
      val[strlen(val)-1] = '\0';
      return val;
    }

  if (e->is(IR_FUNCTION_CALL))
    {
      pIIR_FunctionCall fc = pIIR_FunctionCall(e);
      if (fc->function->declarator
	  && vaul_name_eq (fc->function->declarator, "\"&\""))
	{
	  char *val = vaul_aprintf ("");
	  for (pIIR_AssociationList al = fc->parameter_association_list;
	       al; al = al->rest)
	    {
	      char *val1 = constant_fold_string_expr (al->first->actual);
	      if (val1 == NULL) 
		{
		  free (val);
		  return NULL;
		}
	      char *val2 = vaul_aprintf("%s%s", val, val1);
	      free (val);
	      free (val1);
	      val = val2;
	    }
	  return val;
	}
      else
	return NULL;
    }

  return NULL;
}

/* Emit a declaration. This can probably be done with less code...
*/

void
emit_prototype (pIIR_SubprogramDeclaration s)
{
  if (s->is(IR_FUNCTION_DECLARATION))
    emit (pIIR_FunctionDeclaration(s)->return_type);
  else
    printf ("void");
  printf (" ");
  emit_id (s);
  printf (" (");
  
  for(pIIR_InterfaceList il = s->interface_declarations; il; il = il->rest)
    {
      emit (il->first);
      if (il->rest)
	printf (", ");
    }
  printf (")");
}

void
emit (pIIR_Declaration d, int l)
{
  emit_decl (d, l);
  emit_attributes (d, l);
}

void
emit_attributes (pIIR_Declaration d, int l)
{
  for (pIIR_AttributeValueList avl = d->attributes; avl; avl = avl->rest)
    {
      pIIR_AttributeValue av = avl->first;

      printf ("%sattribute ", spaces(l));
      emit_id (d);
      printf ("'");
      emit_id (av->attribute);
      printf (" = ");
      char *str = constant_fold_string_expr (av->value);
      if (str)
	{
	  printf ("\"%s\"", str);
	  free (str);
	}
      else
	emit (av->value);
      printf (";\n");
    }
}

void
m_emit_decl (pIIR_Declaration d, int l)
{
  // catch-all for ignored declarations.
  printf ("%s/* %s ", spaces(l), d->kind_name());
  emit_id (d);
  printf (" */\n");
}

void
m_emit_decl (pIIR_SubprogramDeclaration s, int l)
{
  emit_prototype (s);
  if (s->subprogram_body == NULL)
    printf (";\n");
  else
    {
      printf ("\n{\n");
      emit_decls (s, 2);
      if (s->declarations)
	printf ("\n");
      emit (s->subprogram_body, 2);
      printf ("}\n\n");

      // If this is a toplevel subprogram in a package body, toss the
      // sequential statements.
      if (s->declarative_region->is(IR_PACKAGE_BODY_DECLARATION))
	s->subprogram_body = NULL;
    }
}

void
m_emit_decl (pIIR_VariableDeclaration v, int l)
{
  printf ("%s", spaces(l));
  emit (v->subtype);
  printf (" ");
  emit_id (v);
  if (v->initial_value) 
    {
      printf (" = ");
      emit (v->initial_value);
      /* Toss the initial value, it might be huge and isn't needed
         anymore. */
      v->initial_value = NULL;
    }
  printf(";\n");
}

void
m_emit_decl (pIIR_ConstantDeclaration c, int l)
{
  printf ("%s", spaces(l));
  if (!c->initial_value)
    printf ("extern ");
  printf ("const ");
  emit (c->subtype);
  printf (" ");
  emit_id (c);
  if (c->initial_value) 
    {
      printf (" = ");
      emit (c->initial_value);
      /* Toss the initial value, it might be huge and isn't needed
         anymore. */
      c->initial_value = NULL;
    }
  printf(";\n");
}

void
m_emit_decl (pIIR_FileDeclaration f, int l)
{
  // A file. The file name is in the INITIAL_VALUE slot.

  printf ("%s", spaces(l));
  emit (f->subtype);
  printf (" ");
  emit_id( f);
  if (f->file_logical_name)
    {
      printf (" = open (");
      emit (f->file_logical_name);
      if (f->file_open_expression) 
	{
	  printf (", ");
	  emit (f->file_open_expression);
	}
      printf (")");
    }
  printf (";\n");
}

void
m_emit_decl (pIIR_SignalDeclaration s, int l)
{
  // A signal, much like any other object.

  printf ("%ssig<", spaces(l));
  emit (s->subtype);
  printf ("> ");
  emit_id (s);
  if (s->initial_value) 
    {
      printf (" = ");
      emit (s->initial_value);
      /* Toss the initial value, it might be huge and isn't needed
         anymore. */
      s->initial_value = NULL;
    }
  printf(";\n");
}

void
m_emit_decl (pIIR_TypeDeclaration t, int l)
{
  // A type. We give types names with typedef and then later refer
  // to them via these names. Anonymous types are not defined.

  printf ("%s", spaces(l));
  printf ("typedef ");
  emit_def (t->type);
  printf (" ");
  emit_id (t);
  printf (";\n");
}

void
m_emit_decl (pIIR_PackageDeclaration p, int l)
{
  // A package.  Just emit all declarations in it.

  printf("\n/* package %s\n*/\n\n", p->declarator->text.to_chars ());
  emit_decls (p, 0);
}

void
m_emit_decl (pIIR_PackageBodyDeclaration pb, int l)
{
  // A package body.  Just emit all declarations in it.

  printf("\n/* package body %s\n*/\n\n", pb->declarator->text.to_chars ());
  emit_decls (pb, 0);
}

void
m_emit_decl (pIIR_EntityDeclaration e, int l)
{
  // A entity. Emit its interface and its block.
  
  printf ("entity ");
  emit_id (e);
  printf (" (");
  emit_comp_interface (e);
  printf (")\n");
  emit_comp_body (e);
}

void
m_emit_decl (pIIR_ArchitectureDeclaration a, int l)
{
  pIIR_EntityDeclaration e = a->entity;

  printf ("architecture<");
  emit_id (e);
  printf ("> ");
  emit_id (a);
  printf (" (");
  emit_comp_interface (a);
  printf (")\n");
  emit_comp_body (a);
}

void
m_emit_decl (pIIR_ConfigurationDeclaration c, int l)
{
  // A configuration...

  printf("\n/* configuration %s\n*/\n\n", c->declarator->text.to_chars());
}

void
m_emit_decl (pIIR_ComponentDeclaration c, int l)
{
  // A component. Emit its interface.

  printf ("%scomponent ", spaces(l));
  emit_id (c);
  printf (" (");
  emit_comp_interface (c);
  printf (");\n");
}


/* Refer to a type. If it has a name, use that. Otherwise be more
   verbose.
*/
void
emit (pIIR_Type t)
{
  if (t->declaration)
    emit_id (t->declaration);
  else if(t->is(IR_SUBTYPE)) 
    {
      emit (pIIR_Subtype(t)->immediate_base);
      if (t->is(IR_SCALAR_SUBTYPE))
	{
	  pIIR_ScalarSubtype s = pIIR_ScalarSubtype (t);
	  if (s->range)
	    {
	      printf (" ");
	      emit (s->range);
	    }
	}
      else if (t->is(IR_ARRAY_SUBTYPE))
	{
	  pIIR_ArraySubtype a = pIIR_ArraySubtype (t);
	  if (a->constraint)
	    {
	      printf (" ");
	      emit (a->constraint);
	    }
	}
    }
  else
    emit_def (t);
}

void
emit (pIIR_TypeList c)
{
  while (c == NULL)
    {
      printf ("[");
      emit (c->first);
      printf ("]");
      c = c->rest;
    }
}

/* Emit an interface element for use in a parameter list
*/
void
emit (pIIR_InterfaceDeclaration i)
{
  VAUL_ObjectClass obj_class = vaul_get_class (i);

  if(obj_class == VAUL_ObjClass_Signal) 
    {
      printf ("sig<");
      emit (i->subtype);
      printf (">");
    } 
  else
    emit (i->subtype);

  if (obj_class == VAUL_ObjClass_Variable)
    printf ("&");

  if (i->declarator) 
    {
      printf (" ");
      emit_id (i);
    }
  if (i->initial_value) 
    {
      printf (" = ");
      emit (i->initial_value);
    }
}

/* Emit all statements of SL, indented to L spaces.
*/
void emit (pIIR_SequentialStatementList sl, int l)
{
  while (sl)
    {
      pIIR_SequentialStatement s = sl->first;

      // Every statement might have a label
      if (s->label)
	{
	  emit_id (s->label->declarator);
	  printf (":\n");
	}
      printf ("%s", spaces(l));
      emit_stat (s, l);
      sl = sl->rest;
    }
}

void
m_emit_stat (pIIR_NullStatement, int l)
{
  // This one is easy
  printf(";\n");
}

void
m_emit_stat (pIIR_ReturnStatement r, int l)
{
  // Almost as easy.

  if (r->return_expression)
    {
      printf ("return ");
      emit (r->return_expression);
      printf (";\n");
    }
  else
    printf ("return;\n");
}

void
m_emit_stat (pIIR_VariableAssignmentStatement a, int l)
{
  emit (a->target);
  printf (" = ");
  emit (a->expression);
  printf(";\n");
}

void
m_emit_stat (pIIR_IfStatement is, int l)
{
  printf ("if(");
  emit (is->condition);
  printf (") {\n");
  emit (is->then_sequence, l+2);
  if (is->else_sequence)
    {
      printf ("%s} else {\n", spaces(l));
      emit (is->else_sequence, l+2);
    }
  printf("%s}\n", spaces(l));
}

void
m_emit_stat (pIIR_CaseStatement cs, int l)
{
  // A case statement. This is probably too complicated. We should
  // somehow unify ranges and subtypes
  
  printf ("switch(");
  emit (cs->expression);
  printf (") {\n");
  for (pIIR_CaseStatementAlternativeList cal = cs->case_statement_alternatives;
       cal; cal = cal->rest)
    {
      for (pIIR_ChoiceList cl = cal->first->choices; cl; cl = cl->rest)
	{
	  pIIR_Choice c = cl->first;
	  if (c->is(IR_CHOICE_BY_OTHERS))
	    printf ("%sdefault:\n", spaces(l));
	  else 
	    {
	      printf ("%scase ", spaces(l));
	      if (c->is(IR_CHOICE_BY_EXPRESSION))
		emit (pIIR_ChoiceByExpression(c)->value);
	      else if (c->is(IR_CHOICE_BY_RANGE))
		{
		  emit (pIIR_ChoiceByRange(c)->range);
#if 0
		  pVAUL_GenAssocElem ae = nRangeChoice(c)->range;
		  if (ae->is(VAUL_RANGE_ASSOC_ELEM))
		    emit (pVAUL_RangeAssocElem(ae)->range);
		  else if (ae->is(VAUL_SUBTYPE_ASSOC_ELEM))
		    emit (pVAUL_SubtypeAssocElem(ae)->type);
#endif
		}
	      else
		printf ("%s", c->kind_name());
	      printf (":\n");
	    }
	}
      emit (cal->first->sequence_of_statements, l+2);
      printf ("%sbreak;\n", spaces(l+2));
    }
  printf ("%s}\n", spaces(l));
}

void
m_emit_stat (pIIR_LoopStatement ls, int l)
{
  if (ls->is(IR_WHILE_LOOP_STATEMENT))
    {
      printf ("while(");
      emit (pIIR_WhileLoopStatement(ls)->condition);
      printf(")");
    }
  else if (ls->is(IR_FOR_LOOP_STATEMENT))
    {
      pIIR_ForLoopStatement fl = pIIR_ForLoopStatement (ls);
      printf ("for (");
      emit (fl->iterator->subtype);
      printf (" ");
      emit_id (fl->iterator);
      printf (")");
    }
  else
    printf ("while(1)");

  printf (" {\n");
  emit (ls->sequence_of_statements, l+2);
  printf ("%s}\n", spaces(l));
}

void
m_emit_stat (pIIR_ProcedureCallStatement pcs, int l)
{
  // A procedure call.

  pIIR_ProcedureDeclaration p = pcs->procedure;
  emit_id (p);
  printf (" (");
  emit_associations (pcs->actual_parameter_part, p->interface_declarations);
  printf (");\n");
}

void
m_emit_stat (pIIR_WaitStatement ws, int l)
{
  printf ("wait");
  if (ws->sensitivity_list)
    {
      printf (" on ");
      for (pIIR_ExpressionList sn = ws->sensitivity_list; sn; sn = sn->rest) 
	{
	  emit (sn->first);
	  if (sn->rest)
	    printf(", ");
	}
    }

  if(ws->condition_clause) 
    {
      printf (" until ");
      emit (ws->condition_clause);
    }

  if (ws->timeout_clause) 
    {
      printf (" for ");
      emit (ws->timeout_clause);
    }

  printf(";\n");
}

void
m_emit_stat (pIIR_AssertionStatement as, int l)
{
  printf ("assert(");
  emit (as->assertion_condition);
  printf ("); /* ");
  emit (as->severity_expression);
  printf (" ");
  emit (as->report_expression);
  printf (" */\n");
}

void
m_emit_stat (pIIR_ReportStatement rs, int l)
{
  printf ("fputs (");
  emit (rs->report_expression);
  printf (", stderr); /* ");
  emit (rs->severity_expression);
  printf (" */\n");
}

void
m_emit_stat (pIIR_LoopControlStatement lcs, int indent)
{
  // Controlling the loop. For innermost loop, `break' and
  // `continue' are used directly. Outer loops are handled with
  // gotos. The needed labels are not yet emitted, though.

  pIIR_LoopStatement l = lcs->loop;
  if (lcs->condition) 
    {
      printf ("if(");
      emit (lcs->condition);
      printf(") ");
    }

  const char *stat = lcs->is(IR_EXIT_STATEMENT)? "break" : "continue";
  if (l && l->label)
    {
      printf ("goto ");
      emit_id (l->label->declarator);
      printf ("_%s;\n", stat);
    }
  else
    printf ("%s;\n", stat);
}

void
m_emit_stat (pIIR_SignalAssignmentStatement sa, int l)
{
  // A signal assignment.

  emit (sa->target);
  printf (" <~ ");
  emit_delay (sa->delay_mechanism, sa->reject_time_expression);
  for (pIIR_WaveformList wl = sa->waveform; wl; wl = wl->rest)
    {
      pIIR_WaveformElement we = wl->first;
      emit (we->value);
      if (we->time) 
	{
	  printf (" @ ");
	  emit (we->time);
	}
      if (wl->rest)
	printf (", ");
    }
  printf(";\n");
}

void
m_emit_stat (pIIR_SequentialStatement s, int l)
{
  printf ("/* emit statement %s */\n", s->kind_name ());
}

void
emit_delay (IR_DelayMechanism dm, pIIR_Expression time)
{
  if (dm == IR_TRANSPORT_DELAY)
    printf ("transport ");
  else if (dm == IR_INERTIAL_DELAY)
    {
      if (time)
	{
	  printf ("reject ");
	  emit (time);
	  printf (" ");
	}
      printf ("inertial ");
    }
}

/* Does ID refer to an operator?
 */
bool is_op(char *id)
{
    return id[0] == '"';
}

/* Translate the binary VHDL operator ID to a corresponding C
   operator.
*/
char *map_bin_op(char *id)
{
    if(is_op(id)) {
	char *op = vaul_xstrdup(id+1);
	op[strlen(op)-1] = '\0';
	if(!strcmp(op, "="))
	    op = (char*)"==";
	else if(!strcmp(op, ":="))
	    op = (char*)"=";
	else if(!strcmp(op, "/="))
	    op = (char*)"!=";
	else if(!strcmp(op, "mod"))
	    op = (char*)"%";
	else if(!strcmp(op, "or"))
	    op = (char*)"||";
	else if(!strcmp(op, "and"))
	    op = (char*)"&&";
	else if(!strcmp(op, "xor"))
	    op = (char*)"^";
	else if(!strcmp(op, "&"))
	    op = (char*)" concat ";
	return op;
    } else
	return NULL;
}

/* Translate the unary VHDL operator ID to a corresponding C operator.
*/
char *map_un_op(char *id)
{
    if(is_op(id)) {
	char *op = vaul_xstrdup(id+1);
	op[strlen(op)-1] = '\0';
	if(!strcmp("not", op))
	    op = (char*)"!";
	return op;
    } else
	return NULL;
}

/* Emit a physical unit. This done by expressing it in terms of
   its base unit.
*/
void
emit (pIIR_PhysicalUnit u)
{
  if (u->multiplier == NULL)
    printf ("1");
  else 
    {
      emit (u->multiplier);
      printf ("*");
      emit (u->unit_name);
    }
}

/* Emit an expression
*/
void
emit (pIIR_Expression e)
{
  static IR_StaticLevel sl = IR_NOT_STATIC;

  if(e == NULL)
    printf ("void");
  else
    {
      if (e->static_level > sl)
	{
	  printf ("<"); sl = IR_StaticLevel(sl+1);
	  emit (e);
	  printf (">"); sl = IR_StaticLevel(sl-1);
	}
      else
	emit_expr (e);
    }
}

void
m_emit_expr (pIIR_FunctionCall fc)
{
  // A function call. We try to output infix operators as
  // infix.

  // count the arguments
  int n_args = 0;
  for (pIIR_AssociationList al = fc->parameter_association_list;
       al; al = al->rest)
    n_args++;

  char *c_op;
  char *fid = fc->function->declarator->text.to_chars();
  if (n_args == 2 && (c_op = map_bin_op (fid)))
    {
      // A binary infix operator
      printf ("(");
      emit (fc->parameter_association_list->first->actual);
      printf ("%s", c_op);
      emit (fc->parameter_association_list->rest->first->actual);
      printf (")");
    }
  else if (n_args == 1 && (c_op = map_un_op (fid)))
    {
      // a unary prefix operator
      printf ("(");
      printf ("%s", c_op);
      emit (fc->parameter_association_list->first->actual);
      printf (")");
    } 
  else if (!is_op(fid)) 
    {
      // a ordinary function call
      emit_id (fc->function);
      printf (" (");
      emit_associations (fc->parameter_association_list,
			 fc->function->interface_declarations);
      printf (")");
    }
  else
    {
      // something strange
      printf ("(%s, %d args)", fid, n_args);
    }
}

void
m_emit_expr (pIIR_SimpleReference sor)
{
  // Referring to an object is done by referring to its
  // identifier
  
  emit_id (sor->object);
}

void
m_emit_expr (pIIR_AbstractLiteralExpression ale)
{
  // Literals are emitted literally, maybe multiplied with
  // a physical unit.

  if (ale->is(IR_PHYSICAL_LITERAL))
    printf ("(");

  emit_lit (ale->value);

  if (ale->is(IR_PHYSICAL_LITERAL))
    {
      printf ("*");
      emit (pIIR_PhysicalLiteral(ale)->unit);
      printf(")");
    }
}

void
emit_lit (pIIR_Literal l)
{
  if (l == NULL)
    printf ("1");
  else if (l->is(IR_TEXT_LITERAL))
    printf ("%s", pIIR_TextLiteral(l)->text.to_chars());
  else if (l->is(IR_INTEGER_LITERAL))
    printf ("%s", pIIR_IntegerLiteral(l)->text.to_chars());
  else if (l->is(IR_FLOATING_POINT_LITERAL))
    printf ("%s", pIIR_FloatingPointLiteral(l)->text.to_chars());
  else
    printf ("<%s>", l->kind_name ());
}

void
m_emit_expr (pIIR_TypeConversion tc)
{
  // A type cast

  printf ("((");
  emit (tc->subtype);
  printf (")(");
  emit (tc->expression);
  printf ("))");
}

void
m_emit_expr (pIIR_QualifiedExpression qe)
{
  emit (qe->expression);
}

void
m_emit_expr (pIIR_EnumLiteralReference elr)
{
  emit_id (elr->value);
}

void
m_emit_expr (pIIR_ArrayReference aor)
{
  emit (aor->array);
  for (pIIR_ExpressionList il = aor->indices; il; il = il->rest)
    {
      printf ("[");
      emit (il->first);
      printf ("]");
    }
}

void
m_emit_expr (pIIR_ArrayLiteralExpression ale)
{
  // Array literals are just strings for us...
  
  printf ("(");
  emit (ale->subtype);
  printf (") ");
  emit_lit (ale->value);
}

void
m_emit_expr (pIIR_RecordReference ror)
{
  emit (ror->record);
  printf (".");
  emit_id (ror->element->declarator);
}

void
m_emit_expr (pIIR_RecordAggregate ra)
{
  printf ("{ ");
  for (pIIR_ElementAssociationList al = ra->element_association_list;
       al; al = al->rest)
    {
      emit_id (al->first->element->declarator);
      printf (": ");
      emit (al->first->value);
      if (al->rest)
	printf (", ");
    }
  printf (" }");
}

void
m_emit_expr (pIIR_ArrayAggregate aa)
{
  printf ("{ ");
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list;
       al; al = al->rest) 
    {
      pIIR_IndexedAssociation ia = al->first;

      if (ia->is(IR_SINGLE_INDEXED_ASSOCIATION))
	{
	  if (pIIR_Expression idx = pIIR_SingleIndexedAssociation(ia)->index)
	    {
	      printf ("[");
	      emit (idx);
	      printf ("] = ");
	    }
	}
      else if (ia->is(IR_RANGE_INDEXED_ASSOCIATION))
	{
	  printf ("[");
	  emit (pIIR_RangeIndexedAssociation(ia)->index_range);
	  printf ("] %s ", ia->is(IR_SLICE_INDEXED_ASSOCIATION)? "=" : "fill");
	}
      else if (ia->is(IR_OTHERS_INDEXED_ASSOCIATION))
	printf("[others] = ");
      else
	printf ("%s =", ia->kind_name());
      emit (ia->value);
      if (al->rest)
	printf (", ");
    }
  printf(" }");
}

void
m_emit_expr (pIIR_SliceReference sr)
{
  emit (sr->array);
  printf ("[");
  emit (sr->range);
  printf ("]");
}

void
m_emit_expr (pIIR_AccessReference aor)
{
  printf("*");
  emit (aor->access);
}

void
m_emit_expr (pIIR_SignalAttr asr)
{
  emit_builtin_id (asr->kind());
  printf ("(");
  emit (asr->signal);
  printf (")");
}

void
m_emit_expr (pIIR_AttrSigFunc asf)
{
  emit_builtin_id (asf->kind());
  printf ("(");
  emit (asf->signal);
  printf(")");
}

void
m_emit_expr (pIIR_AttrTypeFunc atf)
{
  emit_builtin_id (atf->kind());
  printf("(");
  emit (atf->prefix);
  if (atf->argument) 
    {
      printf (", ");
      emit (atf->argument);
    }
  printf(")");
}

void
m_emit_expr (pIIR_AttrArrayFunc aa)
{
  emit_builtin_id (aa->kind());
  printf ("(");
  emit (aa->array);
  printf (", %d)", aa->index);
}

void
m_emit_expr (pIIR_Expression e)
{
  printf ("/* %s */", e->kind_name ());
} 

void
emit (pIIR_Range r)
{
  if (r->is (IR_EXPLICIT_RANGE)) 
    {
      pIIR_ExplicitRange er = pIIR_ExplicitRange(r);
      emit (er->left);
      printf (" %s ", er->direction == IR_DIRECTION_UP? "to" : "downto");
      emit (er->right);
    }
  else if (r->is(IR_ARRAY_RANGE))
    {
      printf ("%s(", r->is(IR_ATTR_ARRAY_RANGE)? "range" : "reverse_range");
      emit (pIIR_ArrayRange(r)->array);
      printf (", ");
      if (pIIR_ArrayRange(r)->index)
	emit (pIIR_ArrayRange(r)->index);
      else
	printf ("1");
      printf (")");
    } 
  else
    printf("/* emit range %s */", r->kind_name());
}

bool
emit_associations (pIIR_AssociationList assocs, pIIR_InterfaceList formals)
{
  bool need_comma = false;

  for (pIIR_AssociationList al = assocs; al; al = al->rest)
    {
      pIIR_AssociationElement a = al->first;
      
      emit (a->formal);
      if (a->formal_conversion)
	{
	  printf ("/* converted by ");
	  emit_id (a->formal_conversion);
	  printf (" */");
	}
      printf (": ");
      emit (a->actual);

      need_comma = true;
      if (al->rest)
	printf (", ");
    }

  return need_comma;
}

void
emit_builtin_id (IR_Kind k)
{
  printf ("%s", tree_kind_name(k));
}

void
emit_block (pIIR_BlockStatement b, int l)
{
  printf ("%s{\n", spaces(l));
  emit_decls (b, l+2);
#if 0
  for (nDisconnectSpec ds = b->disconnect_specs; ds; ds = ds->next)
    {
      printf ("%sdis ", spaces(l+2));
      emit (ds->signal);
      printf (" after ");
      emit (ds->after);
      printf ("\n");
    }
#endif
  if (b->declarations && b->block_statement_part)
    printf ("\n");
  emit (b->block_statement_part, l+2);
  printf ("%s}\n", spaces(l));
}

void
emit (pIIR_ConcurrentStatementList s, int l)
{
  while (s)
    {
      printf ("%s", spaces(l));
      emit_conc_stat (s->first, l);
      s = s->rest;
    }
}

void
m_emit_conc_stat (pIIR_ProcessStatement p, int l)
{
  if (p->postponed)
    printf ("postponed ");
  if (p->guarded)
    printf ("(guarded) ");
  // if (p->orig_statement)
  //   printf ("(%s) ", p->orig_statement->kind_name ());
  printf ("process ");
  emit_id (p);
  printf (" (");
  if (p->is(IR_SENSITIZED_PROCESS_STATEMENT))
    for (pIIR_ExpressionList sl =
	   pIIR_SensitizedProcessStatement (p)->sensitivity_list;
	 sl; sl = sl->rest)
      {
	emit (sl->first);
	if (sl->rest)
	  printf (", ");
      }
  printf (")\n%s{\n", spaces(l));
  emit_decls (p, l+2);
  if (p->declarations)
    printf ("\n");
  emit (p->process_statement_part, l+2);
  printf ("%s}\n", spaces(l));
  printf("\n");
}

void
m_emit_conc_stat (pIIR_ComponentInstantiationStatement ci, int l)
{
  emit_binding (ci->binding->unit, ci->binding->generic_map_list,
		ci->binding->port_map_list);
  if (ci->configuration) 
    {
      printf (": ");
      emit (ci->configuration);
    }
  printf(";\n");
}

void
m_emit_conc_stat (pIIR_BlockStatement bs, int l)
{
  printf ("block ");
  emit_binding (bs, bs->generic_map_aspect, bs->port_map_aspect);
  printf ("\n%s{\n", spaces (l));
  emit_decls (bs, l+2);
  if (bs->declarations)
    printf ("\n");
  emit (bs->block_statement_part, l+2);
  printf ("%s}\n\n", spaces (l));
}

void
m_emit_conc_stat (pIIR_ConcurrentGenerateStatement gs, int l)
{
  printf ("generate ");
  if (gs->is(IR_CONCURRENT_GENERATE_IF_STATEMENT))
    {
      printf ("if ");
      emit (pIIR_ConcurrentGenerateIfStatement(gs)->condition);
    }
  else if (gs->is(IR_CONCURRENT_GENERATE_FOR_STATEMENT))
    {
      pIIR_ConcurrentGenerateForStatement f =
	pIIR_ConcurrentGenerateForStatement (gs);
      printf ("for (");
      emit (f->generate_parameter_specification->subtype);
      printf (" ");
      emit_id (f->generate_parameter_specification);
      printf (")");
    }
  printf (" {\n");
  emit (gs->concurrent_statement_part, l+2);
  printf ("%s}\n", spaces (l));
}

void
m_emit_conc_stat (pIIR_ConcurrentStatement cs, int l)
{
  printf ("/* %s */\n", cs->kind_name());
}

#if 0
void
emit (pIIR_ConfigurationSpecification s)
{
  emit_binding (s->unit, s->generic_map_list, s->port_map_list);
}
#endif

void
emit_binding (pIIR_Declaration unit,
	      pIIR_AssociationList generic_map, pIIR_AssociationList port_map)
{
  if (unit->is (IR_ARCHITECTURE_DECLARATION))
    {
      /* should be obsolete */
      emit_id (pIIR_ArchitectureDeclaration(unit)->entity);
      printf ("(");
      emit_id (unit);
      printf (")");
    }
  else if (unit->is (IR_ARCHITECTURE_REF))
    {
      pIIR_ArchitectureRef ref = pIIR_ArchitectureRef(unit);
      emit_id (ref->entity);
      if (ref->architecture_name)
	{
	  printf ("(");
	  emit_id (ref->architecture_name);
	  printf (")");
	}
    }
  else
    emit_id (unit);

  printf(" (");
  bool nc = emit_associations (generic_map, vaul_get_generics (unit));
  if (nc && port_map)
    printf (", ");
  emit_associations (port_map, vaul_get_ports (unit));
  printf(")");
}

void
emit (pIIR_BindingIndication b)
{
  emit_binding (b->unit, b->generic_map_list, b->port_map_list);
}
