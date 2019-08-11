#include <stdio.h>
#include <stdlib.h>

#include "mapping.h"

int
main (int argc, const char **argv)
{
  v2cc_mapper *m = make_v2cc_mapper ();

  m->add_default_libdirs ();

  if (argc == 3)
    {
      char *fn = m->find_design_file (argv[1], argv[2]);
      if (fn)
	{
	  printf ("%s\n", fn);
	  delete fn;
	}
    }
  else
    {
      fprintf (stderr, "usage: %s lib unit\n", argv[0]);
      exit (1);
    }

  exit (0);
}
