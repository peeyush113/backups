#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#if HAVE_SOCKET
#include <sys/socket.h>
#endif

extern "C" {
#include <regex.h>
}

#define KERNEL
#include <freehdl/kernel-acl.hh>
#include <freehdl/kernel-flags.hh>
#include <freehdl/kernel-kernel-class.hh>
#include <freehdl/kernel-name-stack.hh>
#include <freehdl/kernel-map-list.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-persistent-dump.hh>
#include <freehdl/kernel-persistent-cdfg-dump.hh>
#include <freehdl/kernel-dump.hh>
#include <freehdl/kernel-db.hh>
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-fhdl-stream.hh>

#ifdef PERFMON_STATISTICS
#include "pcounter.hh"
#endif


// The kernel. Note, there is only a single instantiation of
// the kernel_class
kernel_class kernel;

//global variables:
#define BUFSIZE (sizeof(long)*8 + 1)
#define LIMIT_SIZE 200000 
#define STOCK_TIME_BUFFER_SIZE 29
char stock_time[STOCK_TIME_BUFFER_SIZE];
fstream file;
string timescale_unit = "ns";
int timescale = 1;
int coef_str_length = 7;
bool quiet = false; 

buffer_stream dump_buffer;
buffer_stream file_buffer;
FILE* info_file = NULL;
FILE* index_file = NULL;
FILE* string_file = NULL;
extern void write_info_file(list<Xinfo_data_descriptor*> &xinfo_desc, FILE* info_file, 
			    FILE* index_file, FILE* string_file);


// Time calculation
void print_sim_time(fhdl_ostream_t &outp)
{
  outp << "Simulation time = " << time_to_string (kernel.get_sim_time ()) 
       << " + " << kernel.get_delta () << "d\n";
}


// writes the content of file_buffer in the VCD file
// then cleans it.
void write_in_file(buffer_stream &file_buffer)
{
  file << file_buffer.str();
  file_buffer.clean();
}


// vcd_mapping_table: opens file and reads user_defined translation table
Tmap 
get_map_list( char* fileTranslation)
{
  char ch;
  int j = 0;
  int i = 0;
  char buf[80]; 
  string value;
  string instance_name;
  ifstream g(fileTranslation);
  Tmap table;
  while( !(g.eof()))
    {
      g.get(ch);
      if (ch == '#') {
	while (ch != '\n') g.get(ch);
	j = 0;
	i = 0;
      } else if (ch == '(' ){
	do {
	  g.get(ch);
	  if (ch != '\'' && ch != ' ' && ch != ',')  buf[j++] = ch;
	}
	while( ch != ')');
	buf[j-1] = '\0';
	value = buf;
	table[instance_name] = strdup(value.c_str());
      } else if (ch == ')'){
      } else if (ch == '\n'){
      } else {
	do {
	  buf[i++] = ch;
	  g.get(ch);
	}
	while(ch != ' ');
	buf[i] = '\0';
	instance_name = buf;
      }
    }
  g.close();

 return table;
}


// This function verfies the alpha-numeric of file names. Returns false
// if d is not a valid file name 
bool
char_verifier(const char* d)
{ 
  const static char* test_table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
  
  if (d == NULL) return false;
  
  while (*d != '\0') {
    const char *test_char = test_table;
    while (*test_char != '\0')
      if (*test_char == *d) 
	break;
      else
	test_char++;
    if (*test_char == '\0')
      return false;
    d++;
  }

  return true;
}


// creates the dumped signal lists

void
create_dumper_processes(sig_info_base *sinfo, type_info_interface *info, 
			name_stack &nstack, acl *a)
{
  switch (info->id) {
  case ARRAY:
    {
      array_info &ainfo = *(array_info*)info;

      if (ainfo.element_type->id == ENUM)
	break;

      const int lb = ainfo.left_bound; 
      const int rb = ainfo.right_bound;

      // Create a new acl with size 1 greater than acl a and copy
      // content of a to new acl
      const int new_acl_size = (a == NULL? 0 : a->get_size()) + 1;
      acl *new_acl = new(new_acl_size) acl;
      if (a != NULL)
	*new_acl = *a; 
      // Add a dummy element so that the current size of new_acl is set
      // appropriately
      *new_acl << -1;
      
      // For each element of the array call create_dumper_process
      // recursively
      if (lb <= rb)
	{
	  for (int i = lb; i <= rb; i++) 
	    {
	      new_acl->set(new_acl_size - 1, i);
	      create_dumper_processes(sinfo, ainfo.element_type, nstack, new_acl);
	    }
	} else {
	  for (int i = lb; i >= rb; i--) 
	    {
	      new_acl->set(new_acl_size - 1, i);
	      create_dumper_processes(sinfo, ainfo.element_type, nstack, new_acl);
	    }
	}
      
      delete new_acl;
      return; // We're done, so return
      break;
    }

  case RECORD:
    {
      record_info &rinfo = *(record_info*)info;
      const int length = rinfo.record_size;
      // Create a new acl with size 1 greater than acl a and copy
      // content of a to new acl
      const int new_acl_size = (a == NULL? 0 : a->get_size()) + 1;
      acl *new_acl = new(new_acl_size) acl;
      if (a != NULL)
	*new_acl = *a; 
      // Add a dummy element so that the current size of new_acl is set
      // appropriately
      *new_acl << -1;
      
      // For each element of the array call create_dumper_process
      // recursively
      for (int i = 0; i < length; i++) 
	{
	  new_acl->set(new_acl_size - 1, i);
	  create_dumper_processes(sinfo, rinfo.element_types [i], nstack, new_acl);
	}
      
      delete new_acl;
      return; // We're done, so return
      break;
    }

  default:
    break;
  }

  // Create a dumper process for the entire instance
  nstack.push(signal_dump_process_list.size() + 1);
  signal_dump* dumper_proc = new signal_dump(nstack, sinfo, a);
  signal_dump_process_list.push_back(dumper_proc);
  //and finally pops the name stack and deletes the acces code list
  nstack.pop();
}


const char* command_table[]={
  "q", "quit", "n", "next", "c", "cycle", "r", "run", "dump", "d", 
  "don", "doff", "dc", "ds", "ds_view", "nds", "s", "show", "dv", "wdd",
  "wddl", "h", "help", "db_view", NULL
};

// This function validates the input command
bool
nu_clear(string &d)
 { 
   int i = 0; 
   const char* regex_n = d.c_str();
   while (true)
     { 
       const char* regex_i = command_table[i++];
       if (regex_i == NULL) 
	 return false;
       if (strcmp(regex_i, regex_n) == 0) 
	 return true;   
     }

   return false;
 }


// time conversion  function
char*  
time_conversion(const lint &tval, const int &coef_str_length )
{
  // store the time value in fs the tmp_time_buffer
  char *cursor = stock_time + STOCK_TIME_BUFFER_SIZE - 1;
  char *pos_end_cursor =  stock_time + STOCK_TIME_BUFFER_SIZE - 1;
  lint l = tval;
  *(cursor--) = '\0';
  while (l > 0) {
    lint new_l = l / 10;
    int diff = l - (new_l << 3) - (new_l << 1);
    *(cursor--) = (char)diff + '0';
    l = new_l;
  }
  const int str_len = (int)(pos_end_cursor-cursor);
  // calculates the difference between the string lengths
  const int diff =  str_len - coef_str_length;
  // if this difference is positiv(i.e: time value is greater 
  // than coefficient time, which actually presents timescale
  if (diff > 0) {
    strcpy(stock_time,(cursor+1));
    stock_time[diff] = '\0';
  } else if(diff == 0) {
    // the case occurs when the time grid (timescale + timeunit) is too
    // small to represent the change of the signal
    stock_time[0] = '0';
    stock_time[1] = '\0';
  } else if(diff < 0) {
    stock_time[0] = '0';
    stock_time[1] = '\0';
  }
  return  stock_time;
}

// time unit conversion function: converts the time unit to the given unit

int time_unit_conversion(string &tsu)
{
  lint coef_conversion = 1000000;
  dump_buffer.clean();

  if (tsu == "s")
    coef_conversion = 1000000000000000LL;
  else if (tsu == "ms")
    coef_conversion = 100000000000LL;
  else if (tsu == "us")
    coef_conversion = 1000000000LL;
  else if (tsu == "ns")
    coef_conversion = 1000000LL;
  else if (tsu == "ps")
    coef_conversion = 1000LL;
  else if (tsu == "fs")
    coef_conversion = 1LL;

  coef_conversion = coef_conversion * timescale;
  dump_buffer  << coef_conversion ;
  coef_str_length = dump_buffer.str_len();

  return  coef_str_length;
}


//f_log2 function used to determine the size of each signal type 
int f_log2(lint x)
{
  int log = 0;
  do
    {
      x = x/2;
      log++;
    }
  while(x != 0);
  return log;
}


// vcd_file function

void vcd_file (char* fileName, string &cmd)
{

  // store the time in the vcd_file
   lint tval = kernel.get_sim_time();
   //if tval >= 0 call time_conversion function to convert time
   // then write it in the file
   if (tval >= 0 )
   file_buffer << '#' << time_conversion(tval, coef_str_length) << '\n';
   // switch the dump cases and store  the informtion in vcd_file
   // dump and dump on  case
   if (cmd == "d" || cmd == "dump" || cmd == "don" ) 
     {
       if (cmd == "d" || cmd == "dump") {file_buffer << "$dumpvars" << '\n';}
       else {file_buffer << "$dumpon" <<'\n';}
       int count = 0;
       list<signal_dump*>::iterator ig = signal_dump_process_list.begin();
       for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
	    it != signal_dump_process_list.end(); it++) 
	 {
	   if ((*it)->sname != (*ig)->sname) 
	       //delete dump_buffer to alow a new storage
	       dump_buffer.clean();
	   // call the vcd_print function into calling write_value function  
	   (*it)->write_value();
	   ig = it;
	 }
     }  
   // dump off case
   else if (cmd == "doff") 
     {
       file_buffer << "$dumpoff" << '\n'; 
       const char* dump_pointer = dump_buffer.str();
       for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
	    it != signal_dump_process_list.end(); it++) 
	 {
	   // call the vcd_print function
	   (*it)->type->vcd_print(dump_buffer, (*it)->reader_pointer,(*it)->translation_table, false);
	   // all signals are assigned to 'x' or 'bx' then written in the file
	   if (dump_pointer[0] == 'b')
	     file_buffer <<"bx" << ' ' << (*it)->vcd_signal_identifier << '\n';
	   else 
	     file_buffer <<'x'<< ' ' << (*it)->vcd_signal_identifier << '\n';
	 }
     }
   file_buffer << "$end" <<'\n' ;
}

//chooses the right vcd_signal_identifier
char* choose_identifier(char *tab)
{
  int index = 0;
  while(1)
    {
      if (tab[index] == 0) 
	tab[index] = 33;
      else 
	tab[index]++;
      if(tab[index] > 126) 
	{
	  tab[index] = 33;
	  index++;
	} 
      else break;
    }

  return  tab;	
}



//file get_size_range: writes size of signal and range of array in file
int 
get_size_range(fhdl_ostream_t &outp, list<signal_dump*>::iterator it, ostringstream &range, int &size)
{
  array_info *ainfo = ((array_info*)(*it)->type);
  array_info *element_ainfo = (array_info*)(ainfo->element_type);
  
  // *****************************************************************
  // first, tests the element type( case array)
  // *****************************************************************
  if (ainfo->id == ARRAY) {

    //****************************************************************
    // test of the direction (case to):
    //****************************************************************
    if (ainfo->index_direction == to) {
      // tests the subelement type. If it is an array or integer:
      if (ainfo->element_type->id == ARRAY ||ainfo->element_type->id == INTEGER)
	{
	  //*****************************
	  // if it's an array:
	  //****************************
	  if (ainfo->element_type->id == ARRAY){

	    //**********************************************
	    // tests the subelement direction( to or downto) 
	    //**********************************************
	    if (element_ainfo->index_direction == downto)
	      // if downto then defines the range from left to right:
	      range << "[" << element_ainfo->left_bound << ":"
		    << element_ainfo->right_bound << "]";
	    else 
	      // else(if to) then defines the range from right to left:
	      range <<"["<< element_ainfo->right_bound <<":"
		    << element_ainfo->left_bound << "]";
	    //then determes the size of this array: 
	    size = element_ainfo->length;
	    //else: i.e if the subelement is integer type
	  } else {
	    //then calculates the difference between its right and left bounds
	    lint x = (lint)element_ainfo->right_bound - (lint)element_ainfo->left_bound ;
	    x = x < 0? -x : x;
	    // then uses the function f_log2 to determine the binary size of this element:
	    size = f_log2(x);
	    range << "";
	  }
	  // else if the subelement is neither an array nor an integer(i.e: enum or real)
	} else {
	  // then the range is determined from right to left of the array element
	  range  << "[" << ainfo->right_bound << ":" <<ainfo->left_bound << "]";
	  // and the size is the length of this array 
	  size = ainfo->length;
	}

      //diplays a warning on the screen indicating the inversion range of this array.
      //This will be done if quiet si true:  
      if (!quiet)
	outp <<"warning: Direction of signal " << (*it)->instance_name.c_str() 
	     <<"["<<ainfo->left_bound<< " to " << ainfo->right_bound <<"]" 
	     << "  will be converted to "<<"["<<ainfo->right_bound
	     <<" downto "<<ainfo->left_bound<<"]"<<" in  VCD file\n";

      // *****************************************************************
      // case downto of direction test:
      // *****************************************************************
    }else if (ainfo->index_direction == downto) {

      //*******************************************************
      // tests the subelement type when it is array or integer:
      //*******************************************************
      if (ainfo->element_type->id == ARRAY || ainfo->element_type->id == INTEGER)
	{

	  //*********************
	  // if it's an array:
	  //********************
	  if (ainfo->element_type->id == ARRAY){

	    //**********************************************
	    // tests subelements direction (may be "to" or "downto") 
	    //**********************************************
	    if (element_ainfo->index_direction == downto)
	      // if downto then defines the range from left to right:
	      range << "["<< element_ainfo->left_bound 
			  <<":"<<element_ainfo->right_bound <<"]";
	    else 
	      // else(if to) then defines the range from right to left:
	      range <<"[" << element_ainfo->right_bound 
			  <<":"<<element_ainfo->left_bound << "]";
	    //then calculates the difference between its right and left bounds
	    size = element_ainfo->length;
	    //else: i.e if the subelement is integer type
	  } else {
	    //then calculates the difference between its right and left bounds
	    lint x = (lint)element_ainfo->right_bound - (lint)element_ainfo->left_bound ;
	    // then uses the function f_log2 to determine the binary size of this element:
	    size = f_log2(x < 0? -x : x);
	    range << "";
	  }
	  // else if the subelement is neither array nor integer(i.e: enum or real)
	}else {
	  // then the range is determined from right to left of the array element
	  range << "[" <<ainfo->left_bound << ":" <<ainfo->right_bound << "]";
	  // and the size is the length of this array 
	  size = ((array_info*)(*it)->type)->length;
	}
    }

    // *****************************************************************
    // now test the element type (integer case)
    // *****************************************************************
  } else if ((*it)->type->id == INTEGER) {
    integer_info_base *iinfo = ((integer_info_base*)(*it)->type);
    // then calculate the difference between its right and left bounds to determine the range
    lint x = (lint)(iinfo->left_bound) - (lint)(iinfo->right_bound);
    // and use f_log2 function to determine the binary size of this element
    size = f_log2(x < 0? -x : x);
    range <<"";
    // if the element is neither integer nor array: 
  } else {
    // then the element size is determined...
    size = (*it)->type->size;
    range <<"";
  }

  return size;
}



// decides the case of up and/or down scope and writes module name.
void hierarchy (int &n_count, int &o_count, char* stock_var, string &old_value)
{
  /***********************************************************/
  /* This rountine copies the module names in array stock_mod*/
  /***********************************************************/
  const int len = strlen(stock_var);
#ifdef HAVE_ALLOCA
  char *stock_var_cpy = (char*)alloca((len+1) * sizeof(char));
  char **stock_mod = (char**)alloca(n_count * sizeof(char*));
#else
  char *stock_var_cpy = (char*)malloc((len+1) * sizeof(char));
  char **stock_mod = (char**)malloc(n_count * sizeof(char*));
#endif 
  strcpy(stock_var_cpy,stock_var);
  int i = 1;
  for (int h = len; h >= 0; h--) { 
    // every module is referenced with ':' in the instance name
    if (stock_var_cpy[h] == ':') {
      stock_mod[n_count-(i++)] = &stock_var_cpy[h+1];
      stock_var_cpy[h] = '\0';
    }
  }
  
  // i should NEVER be greater than (n_count+1)!
  v_assert(i > (n_count + 1), "i > n_count");

  regex_t preg;// used in regular expression function
  const char *regex_i = old_value.c_str();// used in
  // regular expression function
  const char *regex_n = stock_mod[0];// used in regular
  // expression function. 
  //Calculates the difference between the new count and the last count 
  const int diff = n_count - o_count;
  // if this difference is positiv(i.e: that we go down in the module
  // hierarchies)
  if ( diff > 0){
    // write in the file the new modules names until the last one
    for(int i = o_count; i < n_count; i++)
      file << "$scope module  "<< stock_mod[i]<<"  $end" <<endl;
    // if not(i.e: that we go up in the module hierarchies) 
  } else if(diff < 0) {
    int j = 0;
    for (int i = 0; i < n_count; i++){ 
      // and the regex_n to new module name in the stock module name
      regex_n = stock_mod[i];
      // then we find the existence of this module using regular
      // expression function
      regcomp(&preg, regex_n, REG_NOSUB);
      int h = regexec(&preg,  regex_i, 0, NULL, REG_NOTEOL);
      // if the new name dont exist, the boucle will be breaked
      if (h != 0)
	break;
      // else we go down in the stocked module names
      else 
	j++;
    }
    //then writes the new module names in the file 
    for (int i = j; i <= (j - diff); i++)
      file <<"$upscope " <<"  " << "$end" << endl;
    for (int i = j; i < n_count; i++)
      file <<"$scope module  " <<stock_mod[i] <<"  " << "$end" << endl;
    
    // if the differnce is equal to zero(i.e: we are in the same
    // hierarchy)
  }else if (diff == 0){
    int j = 0;
    for (int i = 0; i < n_count; i++){ 
      // and the regex_n to new module name in the stock module name
      regex_n = stock_mod[i];
      // then we find the existence of this module using regular
      // expression function
      regcomp(&preg, regex_n, REG_NOSUB);
      int h = regexec(&preg,  regex_i, 0, NULL, REG_NOTEOL);
      // if the new name dont exist, the boucle will be breaked
      if (h != 0) 
	break;
      // else we go down in the stocked module names
      else 
	j++;
    }
    //then writes the new module names in the file
    for ( int i = j;i < n_count; i++)
      file <<"$upscope " <<"  " << "$end" << endl;
    for ( int i = j;i < n_count; i++)
      file <<"$scope module  " <<stock_mod[i] <<"  " << "$end" << endl;
    
  }
#ifndef HAVE_ALLOCA
  free (stock_var_cpy);
  free (stock_mod);
#endif
}


// Separates instance strings like ":addcomp:test:a" into sections (":" are removed) 
inline vector<string>
split (const string &path)
{
  vector<string> result;
  for (unsigned int i = 0; i < path.size (); i++)
    if (path [i] == ':')
      result.push_back ("");
    else
      result.back () += path [i];

  return result;
}


// Searches for the first element (strating from the beginning) that
// are not equal. Returns the number of element that is not equal.
inline int 
find_different_element (const vector<string> &str1, const vector<string> &str2)
{
  for (unsigned int i = 0; i < min (str1.size (), str2.size ()); i++)
    if (str1 [i] != str2 [i])
      return i;
  
  return min (str1.size (), str2.size ());
}


//Initial_values function:

void write_header(fhdl_ostream_t &outp, char* fileName)
{ 
  // { ???, INTEGER, ENUM, FLOAT, PHYSICAL, RECORD, ARRAY, ACCESS, VHDLFILE};
  static const char *id_str_table[] = { "???", "integer", "trireg", 
					"real", "time", "???", "reg", "???", "???" };
  char tab[5] = "\0\0\0\0";// used to calculate signal identifiers
  // (each character is in range 33 to 126)
  int size = 0;// size of signal(for array its length)
  string old_value; //used to store
  //the last instance name, which is executed
  int o_count = 0;// used to count how many ':' in old_value

  //write in file, date, version and timescale
  file << "$date" << endl;
  file << "     " << __DATE__<<"  "<<__TIME__<<endl;
  file << "$end" << endl;
  file << "$version" << endl;
  file << "    " << "FREEHDL " PACKAGE_VERSION << endl;
  file << "$end" << endl;
  file << "$timescale" << endl;
  file << "    " << timescale<<" "<<timescale_unit<< endl;
  file <<"$end" << endl;

  vector<string> current_path;

  // presents the dumped signal lists to define the modules and variables and write them in the file
  for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
       it != signal_dump_process_list.end(); it++) 
    {
      ostringstream range;
      //call get_size_range function
      get_size_range(outp, it, range, size);

      // get path name vector for current signal
      vector<string> path_vec = split ((*it)->instance_name);
      path_vec.pop_back ();

      // get first element that is not equal
      const unsigned int diff = find_different_element (path_vec, current_path);
      
      while (diff < current_path.size ())
	{
	  file <<"$upscope $end" << endl;
	  current_path.pop_back ();
	}

      for (unsigned int i = diff; i < path_vec.size (); i++)
	{
	  file << "$scope module " << path_vec [i] << " $end" << endl;
	  current_path.push_back (path_vec [i]);
	}

      // Check whether a space must be inserted between the value and
      // the signal identifier and print indentifier. No space is
      // inserted for bit enumeration types (bit, boolean, std_logic,
      // std_ulogic).
      if ((*it)->translation_table != NULL &&
	  (*it)->type->id == ENUM)
	strcpy((*it)->vcd_signal_identifier, choose_identifier(tab)); 
      else {
	strcpy((*it)->vcd_signal_identifier + 1, choose_identifier(tab)); 
	(*it)->vcd_signal_identifier[0] = ' ';
      }
      // and finally writes in file signal value, name and identifier
      file << "$var " << "  " << id_str_table[int((*it)->type->id)] << " " 
	   << size << " " << tab << " " << (*it)->name.c_str()+1 << range.str()
	   << " " << "$end" << endl;
    }

  while (current_path.size () > 0)
    {
      file << "$upscope $end" << endl;
      current_path.pop_back ();
    }
  file <<"$enddefinitions"<<" "<<"$end" << endl;
}


// Print-help

void print_help(fhdl_ostream_t &outp)
{
  outp << "Available commands:\n";
  outp << "  h          : prints list of available commands\n";
  outp << "  c <number> : execute cycles = execute <number> simulation cycles\n";
  outp << "  n          : next = execute next simulation cycle\n";
  outp << "  q          : quit = quit simulation\n";
  outp << "  r <time>   : run = execute simulation for <time>\n";
  outp << "  d          : dump = dump signals\n";
  outp << "  doff       : dump off = stop dumping signals\n";
  outp << "  don        : dump on = continue dumping signals\n";
  outp << "  s          : show = show signal values\n";
  outp << "  dv         : dump var  = dump a signal from the signal lists\n";
  outp << "  ds         : dump show  = shows the list of dumped signals\n"; 
  outp << "  nds        : number  show  = shows the number  of dumped signals\n";
  outp << "  wdd        : write binary design info\n"; 
  outp << "  wddl       : write design info using a CDFG style syntax\n"; 
  outp << "  db_view    : print kernel database\n";
  outp << "  dc [-f <filename>] [-t <timescale> <time unit>] [-cfg <translation file>] [-q] :"
          "control waveform dumping\n";
#ifdef EVENT_PROFILE
  outp << "  p <file>   : event profile information write to <file>\n";
#endif
}

// scc function: presents the kernel function

void scc(fhdl_istream_t &inp, fhdl_ostream_t &outp) {

  //Declaration of needed parameters
  bool header_written = true;
  bool dump_done = false;
  bool open_file = true;
  char fileName[80] = "wave.dmp";
  string cmd;
  
  //file_buffer initialisation
  file_buffer.clean();
  // print help on the screen
  if (!quiet) print_help(outp);

  // Print the current simulation time
  if (!quiet) print_sim_time(outp);
 

  while (true) {

    if (!inp.eof()) {
      // Output prompt
      if (!quiet) outp << "> "; outp.flush();
      // Read next command to excute
      inp >> cmd;

    } else
      cmd = "q";
 
    // Quit simulation
    if (cmd == "q" || cmd == "quit"){

       //Writing the file buffer in the waveform file
       write_in_file(file_buffer);
       return;

      // Print help screen
    } else if (cmd == "h" || cmd == "help") {
      print_help(outp);

      // Simulate the next cycle
    } else if (cmd == "n" || cmd == "next") {

      //call initial_values function
      if (header_written && dump_done){
	file.open(fileName, ios::out);
	write_header(outp, fileName);
	header_written = false;
      }
      // Execute next simulation cycle
      kernel.next_cycle();
      // Print simulation time
      if (!quiet) print_sim_time(outp);

    // Cycle
    } else if (cmd == "c" || cmd == "cycle") {
      STATISTICS(int counter_start = kernel.executed_processes_counter;);
      STATISTICS(int transactions_counter = kernel.created_transactions_counter;);
      //call write_header function
      if ( header_written && dump_done){
	file.open(fileName, ios::out);
	write_header(outp, fileName);
	header_written = false;
      }
      if (!quiet) outp << "Number of cycles to execute? "; outp.flush();
      int cycles;
      inp >> cycles;
      if (!quiet) outp << "Executing " << cycles << " simulation cycles.\n";
      while (cycles--) {
	// Execute next simulation cycle
	kernel.next_cycle();
      }
      // Print simulation time
      if (!quiet) {
	print_sim_time(outp);
	outp << "\n";
	STATISTICS(outp << kernel.executed_processes_counter - counter_start 
		   << " processes were executed.\n";);
	STATISTICS(outp << kernel.created_transactions_counter -  transactions_counter
		   << " transaction were created.\n";);
      }

    // Run
    } else if (cmd == "r" || cmd == "run") {
      if (!quiet)
	outp << "Run simulation for which time span? "; outp.flush();
      int val, i;
      inp >> val;
      string time_unit;
      inp >> time_unit;
      if (!quiet)
	outp << "\n";

      for (i=0; i < L3std_Q8standard_I4time::unit_count; i++)
	if (!strcmp(time_unit.c_str(), L3std_Q8standard_I4time::units[i])) break;
      if (i == L3std_Q8standard_I4time::unit_count) {
	kernel_error_stream << "Unknown time unit " << time_unit << "\n";
	continue;
      }
       //call initial_values function
      if ( header_written && dump_done){
	file.open(fileName, ios::out);
	write_header(outp, fileName);
	header_written = false;
      }
      STATISTICS(int counter_start = kernel.executed_processes_counter;);
      STATISTICS(int transactions_counter = kernel.created_transactions_counter;);

      lint time_value = kernel.get_sim_time();
      time_value = time_value + L3std_Q8standard_I4time::scale[i] * (lint)val;
      if (!quiet) {
	outp << "Simulating model to time " << val << " " << time_unit << "\n";
      }
      
#ifdef PERFMON_STATISTICS
      start_pcounter(main_argc, main_argv);
#endif

      // Perform simulation
      kernel.do_sim(time_value);

#ifdef PERFMON_STATISTICS
      end_pcounter();
#endif

      // Print simulation time
      if (!quiet) {
	print_sim_time(outp);
	outp << "\n";
	STATISTICS(outp << kernel.executed_processes_counter - counter_start << 
		   " processes were executed.\n";);
	STATISTICS(outp << kernel.created_transactions_counter - transactions_counter 
		   << " transaction were created.\n";);
      }
      
    // Print all signals
    } else if (cmd == "s" || cmd == "show") {
      // Setup connection to the kernel data base
      db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);

      for (signal_map_t::iterator iter = signal_name_table.begin (); iter != signal_name_table.end (); iter++)
	{
	  sig_info_base *sig = iter->second;

	  buffer_stream s;
	  s.clean();
	  outp << sig_info_ext.get (sig).instance_name << " = ";
	  sig->type->print(s, (sig)->reader_pointer, VHDL_PRINT_MODE);
	  outp << s.str() << "\n";
	}

      // dump a set of signal
    } else if (cmd == "dv"){
      // Setup connection to the kernel data base and get entry
      // associated with the current sig info pointer.
      db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);

      // read signal name
      inp >> cmd; 
      name_stack nstack;
      nstack.push("Dumper");
      regex_t preg;
      regcomp(&preg, cmd.c_str(), REG_EXTENDED | REG_NOSUB | REG_ICASE | REG_NEWLINE);

      for (signal_map_t::iterator iter = signal_name_table.begin (); iter != signal_name_table.end (); iter++)
	{
	  sig_info_base *sig = iter->second;

	  int h = regexec(&preg, sig_info_ext.get (sig).instance_name.c_str(), 0, NULL, 0);  
	  if (h == 0 &&
	      !(sig_info_ext.get (sig).kernel_flags & IS_DUMPED)) {
	    // call signal_dump creation function
	    create_dumper_processes(sig, sig->type, nstack, NULL);
	    sig_info_ext.get (sig).kernel_flags |= IS_DUMPED;
	  }
	}
      dump_done = true;

      // Optimize wait_elements in order to save memory and runtime
      kernel.compact_wait_elements();

      // dump all signals
    } else if (cmd == "d" || cmd == "dump") {
      // Setup connection to the kernel data base
      db_explorer<db_key_type::sig_info_base_p, db_entry_type::sig_info_extension> sig_info_ext (kernel_db);

      name_stack nstack;
      nstack.push("dumper");

      for (signal_map_t::iterator iter = signal_name_table.begin (); iter != signal_name_table.end (); iter++)
	{
	  sig_info_base *sig = iter->second;

	  // call signal_dump list creation function
	  if (!(sig_info_ext.get (sig).kernel_flags & IS_DUMPED)) {
	    create_dumper_processes(sig, sig->type, nstack, NULL);
	    sig_info_ext.get (sig).kernel_flags |= IS_DUMPED;
	  }
	}

      nstack.pop();
      dump_done = true;

      // Optimize wait_elements in order to save memory and runtime
      kernel.compact_wait_elements();

      //call initial_values function
      if (header_written && dump_done){
	file.open(fileName, ios::out);
	write_header(outp, fileName);
	header_written = false;
      }
      //calling the vcd_file function
      vcd_file(fileName, cmd);

      // Continue dumping signals
    } else if (cmd == "don") {
      for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
	   it != signal_dump_process_list.end(); it++) 
	(*it)->dump_on();
      vcd_file(fileName, cmd);

    // Stop dumping signals
    } else if (cmd == "doff") {
      for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
	   it != signal_dump_process_list.end(); it++) 
	(*it)->dump_off();
      vcd_file(fileName, cmd);

      // Print  dumped signal lists 
    } else if (cmd == "ds" || cmd == "ds_view") {
      outp <<"Dumped signal lists is: " << "\n";
      for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
	   it != signal_dump_process_list.end(); it++) 
	{ 
	  dump_buffer.clean();
	  outp << (*it)->instance_name << " = ";
	  (*it)->type->vcd_print(dump_buffer, (*it)->reader_pointer,(*it)->translation_table, false);
	  outp << dump_buffer.str() << "\n";
	}

      // Print  number of dumped signals:
    } else if (cmd == "nds" ) {
      int j = 0;
      
      for (list<signal_dump*>::iterator it = signal_dump_process_list.begin(); 
	   it != signal_dump_process_list.end(); it++) j++; 
      outp <<"The number of dumped signals is: "<<  j  << "\n";

      //Dump process configuration
    } else if (cmd == "dc" ) {

      char buffer[1000];
      inp.get(buffer, 1000, '\n');
      stringstream sub_cmd;
      sub_cmd << buffer;

      while (!sub_cmd.eof()) {
	// Read command parameter
	sub_cmd >> cmd;
	if (cmd =="-f"){
	  char test_fileName[1000];
	  sub_cmd >> test_fileName;
	  // valid file name?
	  if (!char_verifier(test_fileName))
	    kernel_error_stream << "'" << test_fileName << "' is not a valid file name! Output file name is set to 'wave.dmp'!\n";
	  else
	    strcpy(fileName, test_fileName);

	} else if (cmd =="-t"){
	  sub_cmd >> timescale; 
	  sub_cmd >> timescale_unit;
	  // call the time_unit_conversion function to convert time
	  time_unit_conversion(timescale_unit);
	} else if (cmd == "-q"){ 
	  // assign quiet to false dont allow a display on screen of comments
	  quiet = true;
	} else if (cmd == "-cfg") {
	  // name of the file containing translation table
	  char fileTranslation[1000];
	  // read file contenent translation table of each user_defined type
	  sub_cmd >> fileTranslation;
	  // valid file name?
	  if (!char_verifier(fileTranslation))
	    kernel_error_stream << "'" << fileTranslation << "' is not a valid file name!\n";
	  else
	    // call the reading file to get user defined translation table
	    mapping_translation_table = get_map_list( fileTranslation);
	} else
	  break;
      }

      // Writes design database in binary mode
    } else if (cmd == "wdd" ) {
      //Opening the corresponding files to write in
      buffer_stream file_name;
      file_name.clean();
      file_name << kernel.executable_name << ".data";
      info_file   = fopen(file_name.str(),"wb");// data file
      file_name.clean();
      file_name << kernel.executable_name << ".index";
      index_file  = fopen(file_name.str(),"wb");// Index file
      file_name.clean();
      file_name << kernel.executable_name <<".string";
      string_file = fopen(file_name.str(),"wb"); // string file
      //call the funtion to write in files
      write_info_file(Xinfo_descriptors, info_file, index_file, string_file);
      //Close files
      fclose(info_file);
      fclose(index_file);
      fclose(string_file);

      // Write design database in cdfg style
    } else if (cmd == "wddl" ) {
      string ddbl_file_name = string(kernel.executable_name) + ".ddb.lsp";
      ofstream ddbl_stream(ddbl_file_name.c_str());
      //call the funtion to write design database
      write_cdfg_info_file(Xinfo_descriptors, ddbl_stream);
      //Close files
      ddbl_stream.close();

      // Print content of kernel database
     } else if (cmd == "db_view") {

      for (db::key_iterator iter = kernel_db.begin (); iter != kernel_db.end (); iter++)
	{
	  db_base::db_key_entry_pair &entry = kernel_db.find (*iter);
	  outp << entry.first->get_name () << "(" << (int)((long)(*iter).value) << ") :"; 
	  for (unsigned int i = 0; i < entry.second.size (); i++)
	    if (entry.second [i] != NULL)
	      outp << " " << entry.second [i]->get_name ();

	  outp << "\n";
	}
     }

#ifdef EVENT_PROFILE
     else if (cmd == "p" || cmd == "profile") {
      if (!quiet) outp << "Print into file: "; outp.flush();
      char filename[80];
      inp >> filename;
      if (!quiet) outp << "\n";
      kernel.event_report(filename);
    }
#endif
     else {
    // Check for valid command
       kernel_error_stream << "Unknown command '" << cmd << "'. Type h for help.\n";
       kernel_error_stream.flush();
     }
  }
}

// main program
int
kernel_main (int argc, char *argv[], handle_info *hinfo) {

  // Savely initialize the 'free_acl' memory
  memset (free_acl, 0, sizeof(acl*)*(MAX_ACL_DEPTH+1)); 

  // Store command line arguments
  main_argc = argc;
  main_argv = argv;
  // Set executable name
  kernel.executable_name = argv[0];

  // First, associate in/out streams with default streams
  kernel_error_stream.bind_to_stream(cerr);
  kernel_output_stream.bind_to_stream(cout);
  model_output_stream.bind_to_stream(cout);
  input_stream.bind_to_stream(cin);

  // Assue that the commands are read from stdin
  bool cmd_param = false;
  // Command buffer for command passed over as a command line
  // parameter
  stringstream cmd_stream;
  // Analyze command line parameters
  int i = 0;
  while (++i < argc) {
    if (!strcmp(argv[i], "-cmd")) {
      // Commands to execute are specified as a string. Each command
      // is separated by ';'
      cmd_param = true; // Store that commands are read from parameter
      // string. Split up the commands given in the command line string.
      i++;
      string cmds = string (i < argc? argv[i] : "");
      string cmd;
      for (unsigned int s = 0; s < cmds.size (); s++)
	{
	  // Search for ';' or end of string
	  if (cmds [s] == ';')
	    {
	      if (cmd != "")
		{
		  cmd_stream << cmd << endl;
		  cmd = "";
		}
	    }
	  else 
	    cmd += cmds [s];
	}
      if (cmd != "")
	cmd_stream << cmd << endl;

    } else if (!strcmp(argv[i], "-FHDLgui")) {
#ifdef HAVE_SOCKET
      // The simulator communicates with its environment via 4 socket
      // connections. The socket file base name is defined by the
      // command line parameter. The actual socket file names are
      // derived by appending 0, 1, 2 or 3 to the base name. 0 is
      // associated with a kernel error socket (to print messages
      // generated by the kernel (e.g., caused by an illegal simulator
      // command)), 1 represents the normal kernel output channel
      // (e.g., to list signal values), 2 is the model output channel
      // (e.g., to print assert messages) and 3 is the input channel.
      string FHDLgui_socket_base = argv[++i];

      int                     sockfd;

      // **********************************************
      // First, bind kernel error socket
      // **********************************************
      bzero((char *) &serv_addr_kernel_error, sizeof(serv_addr_kernel_error));
      serv_addr_kernel_error.sun_family = AF_UNIX;
      strcpy(serv_addr_kernel_error.sun_path, FHDLgui_socket_base.c_str());
      strcat(serv_addr_kernel_error.sun_path, "0");
      sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
      sockfd = 0; // if sockets are not supported, then 
      if (connect(sockfd, (struct sockaddr *) &serv_addr_kernel_error, 
		  strlen(serv_addr_kernel_error.sun_path) + sizeof(serv_addr_kernel_error.sun_family)))
	kernel_error_stream << "could not open socket '" << serv_addr_kernel_error.sun_path << "\n";
      else
	kernel_error_stream.bind_to_socket(sockfd);

      // **********************************************
      // Bind kernel output socket
      // **********************************************
      bzero((char *) &serv_addr_kernel_output, sizeof(serv_addr_kernel_output));
      serv_addr_kernel_output.sun_family = AF_UNIX;
      strcpy(serv_addr_kernel_output.sun_path, FHDLgui_socket_base.c_str());
      strcat(serv_addr_kernel_output.sun_path, "1");
      sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
      if (connect(sockfd, (struct sockaddr *) &serv_addr_kernel_output, 
		  strlen(serv_addr_kernel_output.sun_path) + sizeof(serv_addr_kernel_output.sun_family)))
	kernel_error_stream << "could not open socket '" << serv_addr_kernel_output.sun_path << "\n";
      else
	kernel_output_stream.bind_to_socket(sockfd);
      
      // **********************************************
      // Bind model output socket
      // **********************************************
      bzero((char *) &serv_addr_model_output, sizeof(serv_addr_model_output));
      serv_addr_model_output.sun_family = AF_UNIX;
      strcpy(serv_addr_model_output.sun_path, FHDLgui_socket_base.c_str());
      strcat(serv_addr_model_output.sun_path, "2");
      sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
      if (connect(sockfd, (struct sockaddr *) &serv_addr_model_output, 
		  strlen(serv_addr_model_output.sun_path) + sizeof(serv_addr_model_output.sun_family)))
	kernel_error_stream << "could not open socket '" << serv_addr_model_output.sun_path << "\n";
      else
	model_output_stream.bind_to_socket(sockfd);
      

      // **********************************************
      // Bind input socket
      // **********************************************
      bzero((char *) &serv_addr_input, sizeof(serv_addr_input));
      serv_addr_input.sun_family = AF_UNIX;
      strcpy(serv_addr_input.sun_path, FHDLgui_socket_base.c_str());
      strcat(serv_addr_input.sun_path, "3");
      sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
      if (connect(sockfd, (struct sockaddr *) &serv_addr_input, 
		  strlen(serv_addr_input.sun_path) + sizeof(serv_addr_input.sun_family)))
	kernel_error_stream << "could not open socket '" << serv_addr_input.sun_path << "\n";
      else
	input_stream.bind_to_socket(sockfd);

#else
      kernel_error_stream << "error: system does not have socket support!\n";
#endif

    } else if (!strcmp(argv[i], "-q")) {
      quiet = true;
    } else {
      kernel_error_stream << "Unkown command line argument '" << argv[i] << "'. Simulation run aborted!\n";
      exit(1);
    }
  }

  if (cmd_param) 
    input_stream.bind_to_stream((istream&)cmd_stream);

  // Call initialization functions. Note this does not inlcude the
  // init functions of the corresponding design units.
  run_init_funcs ();

  // Initialize default translation table for printing VCD dumps
  mapping_translation_table = signal_dump::get_default_translation_table();
  // Elaborate the VHDL model: instantiate all components, signals
  // and processes
  kernel.elaborate_model (hinfo);
  // Optimize wait_elements in order to save memory and runtime
  kernel.compact_wait_elements();
  // Execute processe the first time.
  kernel.execute_processes();
  // Read in command and execute them
  scc(input_stream, kernel_output_stream);
  // Close waveform file 
  file.close();

  return 0;
}


int
ttt(int j)
{
  for (int i = 0; i < j; i++)
    delete[] new char[i];
  return 0;
}
