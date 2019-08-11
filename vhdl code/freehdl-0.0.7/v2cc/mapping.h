#ifndef MAPPING_H
#define MAPPING_H

struct v2cc_mapper {

  v2cc_mapper ();
  virtual ~v2cc_mapper ();

  virtual char *find_design_file (const char *lib, const char *unit) = 0;
  virtual void add_libdir (const char *libdir) = 0;
  virtual void add_default_libdirs () = 0;
};

v2cc_mapper *make_v2cc_mapper ();

#endif /* MAPPING_H */
