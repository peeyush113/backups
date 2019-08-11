#ifndef KERNEL_UTIL_H
#define KERNEL_UTIL_H

/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#include <sstream>
#include <string>

#if !defined __GNUC__ || __GNUC__ != 2
#include <ext/hash_map>
#else
#include <hash_map>
#endif

using namespace std;

#if !defined __GNUC__ || __GNUC__ != 2
using namespace __gnu_cxx;
#endif

// A hash function template used tp generate a hash number from
// pointer values.
template<class T>
class pointer_hash : public hash<unsigned long> {
public:
  size_t operator()(const T& x) const {
    return (*(hash<unsigned long> *)this)(((unsigned long)x)>>2);
  }
};


/* Convert an integer value into a string */
template <class T>
inline string
to_string(T i)
{
  stringstream lstr;
  lstr << i;
  return lstr.str();
}

/******************************************************
 * End of internal kernel definitions    
 ******************************************************/
#endif



#endif
