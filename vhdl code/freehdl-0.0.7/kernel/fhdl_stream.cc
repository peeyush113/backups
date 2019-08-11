#define KERNEL
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sstream>
#include <assert.h>
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-fhdl-stream.hh>


// Error stream to output error messages generated by the kernel,
// e.g. to print error messages due to invalid simulator commands
// typed in by the user
fhdl_ostream_t kernel_error_stream;
// Normal output messages generated by the kernel code (e.g., to print
// signal values)
fhdl_ostream_t kernel_output_stream;
// Errors/notes printed by the model code (e.g., assert messages)
fhdl_ostream_t model_output_stream;
// Input stream 
fhdl_istream_t input_stream;

#ifdef HAVE_SOCKET
// Sockets addresses for socket based communication
struct sockaddr_un      serv_addr_kernel_error;
struct sockaddr_un      serv_addr_kernel_output;
struct sockaddr_un      serv_addr_model_output;
struct sockaddr_un      serv_addr_input;
#endif

/* *************************************************************
 *  fhdl_ostream_t
 * ************************************************************* */

fhdl_ostream_t::fhdl_ostream_t() 
{ 
  str = &cout; 
  socket_connection = active = false; 
};

void
fhdl_ostream_t::bind_to_stream(ostream &os) 
{
  active = true;
  str = &os;
  socket_connection = false;
}

void
fhdl_ostream_t::bind_to_socket(int s) 
{
#ifdef HAVE_SOCKET
  active = true;
  fd = s;
  socket_connection = true;
#else
  error (ERROR_NO_SOCKETS);
  assert (false);
#endif
}

fhdl_ostream_t &
fhdl_ostream_t::operator<<(char *p) 
{
  if (!socket_connection)
    *str << p;
  else
    {
      write(fd, p, strlen(p) + 1);
    }
  return *this;
}

fhdl_ostream_t &
fhdl_ostream_t::operator<<(const string &a) 
{
  if (!socket_connection)
    *str << a;
  else
    {
      write(fd, a.c_str(), a.size() + 1);
    }
  return *this;
}


template<class T>
inline string to_string(const T &i)
{
  stringstream lstr;
  lstr << i;
  return lstr.str();
}

fhdl_ostream_t &
fhdl_ostream_t::operator<<(const int i) 
{
  if (!socket_connection)
    *str << i;
  else {
    string str = to_string(i);
    write(fd, str.c_str(), str.size() + 1);
  }
  return *this;
}

fhdl_ostream_t &
fhdl_ostream_t::operator<<(const unsigned int i) 
{
  if (!socket_connection)
    *str << i;
  else {
    string str = to_string(i);
    write(fd, str.c_str(), str.size() + 1);
  }
  return *this;
}

fhdl_ostream_t &
fhdl_ostream_t::operator<<(const long long int i) 
{
  if (!socket_connection)
    *str << i;
  else {
    string str = to_string(i);
    write(fd, str.c_str(), str.size() + 1);
  }
  return *this;
}


/* *************************************************************
 *  fhdl_istream_t
 * ************************************************************* */

fhdl_istream_t::fhdl_istream_t() 
{ 
  str = &cin; 
  socket_connection = active = false; 
};

void 
fhdl_istream_t::bind_to_stream(istream &is) 
{
  active = true;
  str = &is;
  socket_connection = false;
}

void 
fhdl_istream_t::bind_to_socket(int s) 
{
#ifdef HAVE_SOCKET
  active = true;
  fd = s;
  socket_connection = true;
#else
  error (ERROR_NO_SOCKETS);
  assert (false);
#endif
}

fhdl_istream_t &
fhdl_istream_t::operator>>(string &a) 
{
  if (!socket_connection)
    *str >> a;
  else {
    a = "";
    char c;
    while (read(fd, &c, 1) == 1 &&
	   c != '\n' && c != ' ' && c != '\t')
      a += c;
  }
  return *this;
}



template<class T>
inline T to_integer(const string &s)
{
  stringstream lstr;
  lstr << s;
  T value;
  lstr >> value;
  return value;
}

fhdl_istream_t &
fhdl_istream_t::operator>>(int &i) 
{
  if (!socket_connection)
    *str >> i;
  else {
    string str;
    *this >> str;
    i = to_integer<int>(str);
  }
  return *this;
}

fhdl_istream_t &
fhdl_istream_t::operator>>(unsigned int &i) 
{
  if (!socket_connection)
    *str >> i;
  else {
    string str;
    *this >> str;
    i = to_integer<unsigned int>(str);
  }
  return *this;
}

fhdl_istream_t &
fhdl_istream_t::operator>>(long long int &i) 
{
  if (!socket_connection)
    *str >> i;
  else {
    string str;
    *this >> str;
    i = to_integer<long long int>(str);
  }
  return *this;
}


void 
fhdl_istream_t::get(char *buf, const int size, const char sep)
{
  if (!socket_connection)
    str->get(buf, size, sep);
  else {
    char c;
    int i = 0;
    while (i != size && 
	   read(fd, &c, 1) == 1 && c != sep)
      buf[i++] = c;
  }
}