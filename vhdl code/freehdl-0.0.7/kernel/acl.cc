#include <freehdl/kernel-acl.hh>
#include <freehdl/std-vhdl-types.hh>


acl *free_acl[MAX_ACL_DEPTH + 1]; // List of acl objects that are currently not in use

pacl tmpacl = new(100) acl; // temporary acl instance with 100 elements (should be enough
			    // for most cases!
pacl tmpacl1 = new(100) acl; // temporary acl instance with 100 elements (should be enough
                             // for most cases!
pacl tmpacl2 = new(100) acl; // temporary acl instance with 100 elements (should be enough
                             // for most cases!

bool 
acl::operator==(const acl &a) {
  if (this == NULL)
    return a.end();
  int i = 0;
  while (!end() && !a.end()) {
    if (get(i) != ACL_RANGE) {
      if (get(i) != a.get(i)) return false;
      i++;
    } else {
      if (a.get(i) != ACL_RANGE) return false;
      int low1 = get(i+2) == to? get(i+1) : get(i+3);
      int high1 = get(i+2) == to? get(i+3) : get(i+1);
      int low2 = a.get(i+2) == to? a.get(i+1) : a.get(i+3);
      int high2 = a.get(i+2) == to? a.get(i+3) : a.get(i+1);
      if (low1 != low2 || high1 != high2) return false;
      i += 3;
    }
  }
  return true;
}


// *****************************************************************
// Some function  which are used only within kernel code. Usually,
// these function would be defined as methods of the acl class. 
// However, as they are used by kernel modules only we define 
// them as normal functions keeping the acl class as slim as 
// possible.
// *****************************************************************


// Count levels an acl consists of. Note that a range is counted as a
// single level.
int
count_levels(const pacl a)
{
  int levels = 0;
  pacl ac = a;

  while (!ac->end()) {
    if (ac->get() == ACL_RANGE)
      ac += 3;
    ac++;
    levels++;
  }

  return levels;
}


// Get acl pointer associated with level "level". Note that a range is
// counted as a single level.
pacl
get_level(const pacl a, const int level)
{
  pacl ac = a;
  int level_counter = level;
  while (--level_counter > 0) {
    if (ac->get() == ACL_RANGE)
      ac += 3;
    ac++;
  }
  return ac;
}


// Creates a new acl containing levels begin to end (not included)
// from original acl a
pacl
clone_levels(const pacl a, const int begin, const int end)
{
  pacl first = get_level(a, begin);
  pacl last = get_level(a, end - 1);
  pacl new_aclp = new(last - first + 1) acl;
  for (pacl iter = first; iter != last; iter++)
    *new_aclp << iter->get();

  return new_aclp;
}



// Returns current acl entry in left, dir and right. A single number
// is converted into a range "number" to "number". If no range or
// index is specified then a null range 1 to 0 is returned. Function
// returns a pointer to the next acl entry.
pacl
get_entry_data(pacl a, int &left, range_direction &dir, int &right)
{
  if (a->end()) {
    left = 1;
    dir = to;
    right = 0;
    return a;
  }

  left = (a++)->get();
  if (left == ACL_RANGE) {
    left = (a++)->get();
    dir = (a++)->get() == 0? to : downto;
    right = (a++)->get();
  } else {
    dir = to;
    right = left;
  }
  return a;
}
