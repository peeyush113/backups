#ifndef FREEHDL_VAUL_CREATOR_BASE_H
#define FREEHDL_VAUL_CREATOR_BASE_H

#include <freehdl/fire.h>
#include <freehdl/vaul-pool.h>
#include <freehdl/vaul-dunit.h>

struct vaul_node_creator_base {
  vaul_design_unit *cur_du;
  tree_histogram hist;
  pIIR_PosInfo make_posinfo (int lineno);
};

void vaul_fix_static_level (pIIR_Type type);

#endif
