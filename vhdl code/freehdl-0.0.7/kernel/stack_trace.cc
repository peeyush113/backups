
#ifdef HAVE_EXECINFO_H
// If system execinfo.h is defined on the current system then include
// this header file.
#include <execinfo.h>
#endif

#include <freehdl/kernel-stack-trace.hh>
#include <map>

#define MAX_FRAMES 256
#define MAXLINE 1024


map<string, string> stack_trace_result_map;


// local function used to convert a generated C++ function name back to VHDL name
string c2v_name(const char * cname);

void trace_source(buffer_stream &str, bool vhdl_only, const char * exefile)
{
// If execinfo.h is not present on the current system then
// trace_source body is replaced by single "return"
// statement. execinfo.h is required in order to print stack trace
// information in case of a simulator runtime error (e.g., in case of
// a range violation)! However, this function is not required to make
// the simulator work.
#ifdef HAVE_EXECINFO_H
 
  void  *array[MAX_FRAMES];
  int    arraySize = MAX_FRAMES;
  int    symCount = 0;
  char **symNames = NULL;
  int    index;
  char   buff[MAXLINE], command[MAXLINE];
  FILE  *fpipe;

  symCount = backtrace( array, arraySize );
  symNames = backtrace_symbols( array, arraySize );

  memset(buff, '\0', 1);
  for ( index=0; index<symCount; index++ ){
	// the symNames[index] contains address information in a format
	// like [0x123...], we only need the address inside the square brackets.
	// This address will be put into buff
	char  *pchar;
	if ( (pchar = strstr(symNames[index], "[0x")) == NULL)
	  continue;

	pchar++; // skip over '['
	int addr_length = 0;
	while (*(pchar+addr_length) != '\0' && *(pchar+addr_length) != ']')
	  addr_length++;
	strncat (buff, pchar, addr_length);
	strcat(buff, " "); // hexical addresses are seperated by " "
  }

  // Test whether we already translated the same stack trace data
  // before. Typically, this happens if the same "error" or "warning"
  // is emitted over and over again.
  string key = buff;
  if (stack_trace_result_map.find (key) == stack_trace_result_map.end ())
    {
      // No, we do not have an appropriate entry in the map. Hence,
      // generate the data via the external program "addr2line".
      snprintf(command, sizeof(command), \
	       "addr2line --demangle -f -e %s %s", exefile, buff);
      // create a pipe
      fpipe = popen(command, "r");
      
      string s;
      int lines = 0; // a counter of lines to be outputed
      // from now on, buff is used to hold the results from 'addr2line'
      // process the result returned from 'addr2line'
      if (vhdl_only)
	{
	  char previous_line[MAXLINE];
	  string vname; // used to take the results from c2v_name()
	  while (fgets(buff, MAXLINE, fpipe) != NULL){
	    if (strstr(buff, ".vhdl") != NULL ||
		strstr(buff, ".vhd") != NULL ){
	      lines++;
	      if(lines == 1)
		s += "in ";
	      else
		s += "called from ";
	      // each time when a line containing '.vhdl' or '.vhd' is found,
	      // the previous line should contain the function name.
	      // call c2v_name() to convert the name into VHDL names
		vname = c2v_name(previous_line);
		s += vname + " at line " + buff;
	    }
	    strcpy(previous_line, buff);
	  }
	}
      else
	{ // output all the lines as is
	  while (fgets(buff, MAXLINE, fpipe) != NULL){
	    lines++;
	    if(lines == 1)
	      s +=  string ("in ") + buff;
	    else if (lines%2 == 1)
	      s += string ("called from ") + buff;
	  }
	}

      pclose(fpipe);

      str << s;
      // Store data into map for future useage.
      stack_trace_result_map [key] = s;

    }
  else
    // If there is an appropriate entry in the map then get the
    // associated message from the map.
    str << stack_trace_result_map [key];
  
  if (symNames != NULL)
    free (symNames);

#endif /* #ifdef HAVE_EXECINFO_H */
 
  return;
}


string c2v_name(const char * cname){

  string _library;
  string _entity;
  string _architecture;
  string _process;
  string _procedure;
  string vname;
  char   c[10];
  int num = 0;
  const int length = strlen(cname);
  const char *pchar = cname;

  while (*pchar != '\0') {
	if (*pchar == '_' || pchar == cname) {
	  if (*pchar == '_')
		++pchar;

	  switch(*(pchar)) {
	  case 'L':
		if (!isdigit(*(++pchar)))
		  break;
		num = 1;
		while(isdigit(*(pchar+num)))
		  num++;
		strncpy(c, pchar, num);
		pchar += num;
		num = atoi(c);
		if ((pchar + num - cname) > length)
		  break;
		_library.assign(pchar, num);
		pchar += num;
		break;
	  case 'E':
		if (!isdigit(*(++pchar)))
		  break;
		num = 1;
		while(isdigit(*(pchar+num)))
		  num++;
		strncpy(c, pchar, num);
		pchar += num;
		num = atoi(c);
		if ((pchar + num - cname) > length)
		  break;
		_entity.assign(pchar, num);
		pchar += num;
		break;
	  case 'A':
		if (!isdigit(*(++pchar)))
		  break;
		num = 1;
		while(isdigit(*(pchar+num)))
		  num++;
		strncpy(c, pchar, num);
		pchar += num;
		num = atoi(c);
		if ((pchar + num - cname) > length)
		  break;
		_architecture.assign(pchar, num);
		pchar += num;
		break;
	  case 'P':
		if (!isdigit(*(++pchar)))
		  break;
		num = 1;
		while(isdigit(*(pchar+num)))
		  num++;
		strncpy(c, pchar, num);
		pchar += num;
		num = atoi(c);
		if ((pchar + num - cname) > length)
		  break;
		_process.assign(pchar, num);
		if (_process[0] == '_')
		  // process name is generated with '_' at the beginning
		  _process.erase(0, 1); 
		pchar += num;
		break;
	  case 'X':
		if (!isdigit(*(++pchar)))
		  break;
		num = 1;
		while(isdigit(*(pchar+num)))
		  num++;
		strncpy(c, pchar, num);
		pchar += num;
		num = atoi(c);
		if ((pchar + num - cname) > length)
		  break;
		_procedure.assign(pchar, num);
		pchar += num;
		break;
	  default:
		++pchar;
	  }
	}
	else
	  ++pchar;
	if ((pchar-cname) > length)
	  break;
  }

  if (_procedure.size() > 0)
	vname = "procedure :" + _library + ":" + _entity + "(" + \
	  _architecture +"):" + _process + ":" + _procedure;
  else
	vname = "process :" + _library + ":" + _entity + "(" + \
	  _architecture +"):" + _process;
  return vname;
}
