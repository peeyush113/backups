#ifndef FREEHDL_VAUL_TYPES_H
#define FREEHDL_VAUL_TYPES_H

#include <freehdl/vaul-printer.h>
#include <freehdl/tree-supp.h>

enum VAUL_ObjectClass {
  VAUL_ObjClass_None,
  VAUL_ObjClass_Signal,
  VAUL_ObjClass_Variable,
  VAUL_ObjClass_Constant,
  VAUL_ObjClass_File
};

struct vaul_id_set {

    vaul_id_set(int dummy = 0);
    ~vaul_id_set();

    void add(pIIR_TextLiteral);
    void remove(pIIR_TextLiteral);
    void init();

    bool contains(pIIR_TextLiteral);
    bool is_last(pIIR_TextLiteral);

private:
    pIIR_TextLiteral *ids;
    int n_ids;
};

struct IIR_Type;

struct vaul_incomplete_type_use
{
  vaul_incomplete_type_use *next;
  IIR_Type **ref;
};

pIIR_Type vaul_get_base (tree_base_node *);
VAUL_ObjectClass vaul_get_class (tree_base_node *);
IR_Mode vaul_get_mode (tree_base_node *);
pIIR_Type vaul_get_type (tree_base_node *);
pIIR_InterfaceList vaul_get_generics (tree_base_node *);
pIIR_InterfaceList vaul_get_ports (tree_base_node *);
void vaul_set_generics (tree_base_node *, pIIR_InterfaceList generics);
void vaul_set_ports (tree_base_node *, pIIR_InterfaceList ports);
pIIR_ConcurrentStatementList vaul_get_stats (tree_base_node *);
IR_StaticLevel vaul_compute_static_level (tree_base_node *);
void vaul_print_to_ostream (tree_base_node *, std::ostream& o);

#endif
