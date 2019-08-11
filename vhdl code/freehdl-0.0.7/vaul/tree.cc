/* reading and writing the abstract graph

   Copyright (C) 1994-1997, 2003 University of Dortmund
   Department of Electrical Engineering, AG SIV

   VAUL is free software; you can redistribute it and/or modify it
   under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   VAUL is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General
   Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with VAUL; see the file COPYING.LIB.  If not, write
   to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA.


*/

#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-util.h>
#include "vaulgens-chunk.h"

#include <assert.h>
#include <stdlib.h>

using namespace std;

vaul_id_set::vaul_id_set(int dummy)
{
    ids = NULL;
    n_ids = 0;
}

void vaul_id_set::init()
{
    free(ids);
    ids = NULL;
    n_ids = 0;
}

vaul_id_set::~vaul_id_set()
{
    init();
}

void 
vaul_id_set::add (pIIR_TextLiteral id)
{
  for (int i = 0; i < n_ids; i++)
    if (ids[i] == NULL) 
      {
	ids[i] = id;
	return;
      }
  ids = (pIIR_TextLiteral *)vaul_xrealloc (ids,
					  (n_ids+1)*sizeof(pIIR_TextLiteral *));
  ids[n_ids++] = id;
}

void
vaul_id_set::remove (pIIR_TextLiteral id)
{
  for (int i = 0; i < n_ids; i++)
    if (vaul_name_eq (ids[i], id))
      ids[i] = NULL;
}

bool
vaul_id_set::contains (pIIR_TextLiteral id)
{
  for (int i = 0; i < n_ids; i++)
    if (vaul_name_eq(ids[i], id))
      return true;
  return false;
}

bool
vaul_id_set::is_last (pIIR_TextLiteral id)
{
  if (n_ids <= 0) return false;
  return vaul_name_eq(ids[n_ids - 1], id);
}

void
m_vaul_print_to_ostream (IIR_PosInfo_TextFile *p, ostream &o)
{
  o << p->file_name << ":" << p->line_number;
}

void
m_vaul_print_to_ostream (IIR_PosInfo_Sheet *s, ostream &o)
{
  o << s->sheet_name << "(" << s->x_coordinate
    << "," << s->y_coordinate << ")";
}

void
m_vaul_print_to_ostream (pIIR_Root n, ostream &o)
{
  o << "FIXME(" << n->kind_name () << ")";
}

void
m_vaul_print_to_ostream (IIR_TextLiteral *l, ostream &o)
{
  o << l->text;
}

void
m_vaul_print_to_ostream (IIR_IntegerLiteral *l, ostream &o)
{
  o << l->text;
}

void
m_vaul_print_to_ostream (IIR_FloatingPointLiteral *l, ostream &o)
{
  o << l->text;
}

void
m_vaul_print_to_ostream (IIR_Declaration *n, ostream &o)
{
  if (n->declarator)
    o << n->declarator;
  else
    o << "<anonymous>";
}

void
m_vaul_print_to_ostream (pVAUL_SimpleName n, ostream &o)
{
  o << n->id;
}

void
m_vaul_print_to_ostream (pVAUL_AttributeName n, ostream &o)
{
  o << n->prefix << "'" << n->attribute;
}

void
m_vaul_print_to_ostream (pVAUL_SelName n, ostream &o)
{
  o << n->prefix << "." << n->suffix;
}

void
m_vaul_print_to_ostream (pVAUL_IftsName n, ostream &o)
{
  o << n->prefix << "(...)";
}

void
m_vaul_print_to_ostream (pIIR_Type n, ostream &o)
{
  if (n->declaration)
    o << n->declaration;
  else if (n->is(IR_INTEGER_TYPE))
    o << "<integer>";
  else if (n->is(IR_FLOATING_TYPE))
    o << "<real>";
  else
    o << "<" << n->kind_name() << ">";
}

void
m_vaul_print_to_ostream (pIIR_Subtype n, ostream &o)
{
  if (n->declaration == NULL)
    {
      pIIR_Type t = n;
      while (t->is(IR_SUBTYPE) && t->declaration == NULL)
	t = pIIR_Subtype(t)->immediate_base;
      o << t;
      if (n->is(IR_SCALAR_SUBTYPE))
	{
	  pIIR_ScalarSubtype s = pIIR_ScalarSubtype (n);
	  if (s->range)
	    o << " " << s->range;
	}
      else if (n->is(IR_ARRAY_SUBTYPE))
	{
	  pIIR_ArraySubtype a = pIIR_ArraySubtype (n);
	  if (a->constraint)
	    o << " " << a->constraint;
	}
    }
  else
    o << n->declaration->declarator;
}

void
m_vaul_print_to_ostream (pIIR_ArrayType n, ostream &o)
{
  if (n->declaration == NULL)
    {
      o << (n->is(VAUL_SUBARRAY_TYPE)? "subarray(" : "array(");
      for (pIIR_TypeList il = n->index_types; il; il=il->rest)
	{
	  o << il->first;
	  if (il->rest)
	    o << ", ";
	}
      o << ") of " << n->element_type;
    }
  else
    o << n->declaration->declarator;
}

void
m_vaul_print_to_ostream (pIIR_AccessType n, ostream &o)
{
  if (n->declaration == NULL)
    o << "access to " << n->designated_type;
  else
    o << n->declaration->declarator;
}

void
m_vaul_print_to_ostream (pIIR_PhysicalType n, ostream &o)
{
  o << n->declaration;
}

void
m_vaul_print_to_ostream (pIIR_EnumerationLiteral n, ostream &o)
{
  o << n->declarator << " (" << n->subtype << ")";
}

void
m_vaul_print_to_ostream (pIIR_EnumLiteralReference n, ostream &o)
{
  o << n->value->declarator;
}

void
m_vaul_print_to_ostream (pIIR_SubprogramDeclaration n, ostream &o)
{
  if (n->is(IR_FUNCTION_DECLARATION) && !pIIR_FunctionDeclaration(n)->pure)
    o << "impure ";
  o << n->declarator << "(";
  for(pIIR_InterfaceList il = n->interface_declarations; il; il = il->rest)
    o << il->first->subtype << (il->rest? ",":"");
  o << ")";
  if (n->is(IR_FUNCTION_DECLARATION))
    o << " return " << pIIR_FunctionDeclaration(n)->return_type;
}

void
m_vaul_print_to_ostream (pIIR_ExplicitRange n, ostream &o)
{
  o << n->left << (n->direction == IR_DIRECTION_UP? " to " : " downto ") 
    << n->right;
}

void
m_vaul_print_to_ostream (pIIR_ArrayRange n, ostream &o)
{
  o << n->array
    << (n->is(IR_ATTR_ARRAY_RANGE)? "'RANGE" : "'REVERSE_RANGE")
    << "[" << n->index << "]";
}

void
m_vaul_print_to_ostream (pIIR_TypeList n, ostream &o)
{
  o << "(";
  while (n) 
    {
      o << n->first;
      n = n->rest;
      if (n)
	o << ", ";
    }
  o << ")";
}

void
m_vaul_print_to_ostream (pIIR_SimpleReference n, ostream &o)
{
  o << n->object;
}

void
m_vaul_print_to_ostream (pIIR_SliceReference n, ostream &o)
{
  o << "slice of " << n->array;
}

void
m_vaul_print_to_ostream (pIIR_FunctionCall n, ostream &o)
{
  o << "call of " << n->function;
}

void
m_vaul_print_to_ostream (pIIR_AbstractLiteralExpression n, ostream &o)
{
  o << n->value;
}

void
m_vaul_print_to_ostream (pIIR_ArrayLiteralExpression n, ostream &o)
{
  o << n->value;
}

void
m_vaul_print_to_ostream (pIIR_PhysicalLiteral n, ostream &o)
{
  o << n->value << " " << n->unit;
}

void
m_vaul_print_to_ostream (pVAUL_AmbgArrayLitRef n, ostream &o)
{
  o << n->value;
}

void
m_vaul_print_to_ostream (pIIR_ArrayReference n, ostream &o)
{
  o << "array element of " << n->array;
}

void
m_vaul_print_to_ostream (pIIR_RecordReference n, ostream &o)
{
  if (n->element && n->record)
    o << n->record << "." << n->element->declarator;
  else if (n->record)
    o << "element of " << n->record->subtype;
  else
    o << "???";
}

void
m_vaul_print_to_ostream (pIIR_ElementDeclaration n, ostream &o)
{
  o << n->declarator;
}

void
m_vaul_print_to_ostream (pIIR_ChoiceByExpression n, ostream &o)
{
  o << n->value;
}

void
m_vaul_print_to_ostream (pIIR_ChoiceByRange n, ostream &o)
{
  o << n->range;
}

void
m_vaul_print_to_ostream (pIIR_ChoiceByOthers n, ostream &o)
{
  o << "others";
}

void
m_vaul_print_to_ostream (pVAUL_ChoiceByName n, ostream &o)
{
  o << n->name;
}

void
m_vaul_print_to_ostream (pVAUL_UnresolvedName n, ostream &o)
{
  o << n->name;
}

void
m_vaul_print_to_ostream (pIIR_QualifiedExpression n, ostream &o)
{
  o << n->subtype << "'(...)";
}

void
m_vaul_print_to_ostream (pVAUL_AmbgAggregate n, ostream &o)
{
  o << "( ";
  for (pVAUL_ElemAssoc ea = n->first_assoc; ea; ea = ea->next) 
    {
      for (pIIR_ChoiceList cl = ea->choices; cl; cl = cl->rest)
	{
	  o << cl->first;
	  if (cl->rest)
	    o <<  "| ";
	}
      if (ea->choices)
	o << " => ";
      o << ea->actual;
      if (ea->next)
	o << ", ";
    }
  o << " )";
}

void
m_vaul_print_to_ostream (pIIR_ArrayAggregate n, ostream &o)
{
  o << "(";
  for (pIIR_IndexedAssociationList ial = n->indexed_association_list;
       ial; ial = ial->rest) 
    {
      if (ial->first)
	o << ial->first;
      if (ial->rest)
	o << ", ";
    }
  o << ")";
}

void
m_vaul_print_to_ostream (pIIR_SingleIndexedAssociation n, ostream &o)
{
  if (n->index && n->value)
    o << n->index << " => " << n->value;
}

void
m_vaul_print_to_ostream (pIIR_RangeIndexedAssociation n, ostream &o)
{
  if (n->index_range && n->value)
    o << n->index_range << " => " << n->value;
}

void
m_vaul_print_to_ostream (pIIR_OthersIndexedAssociation n, ostream &o)
{
  if (n->value)
    o << "others => " << n->value;
}

void
m_vaul_print_to_ostream (pVAUL_RangeAssocElem n, ostream &o)
{
  o << n->range;
}

void
m_vaul_print_to_ostream (pVAUL_NamedAssocElem n, ostream &o)
{
  if (n->formal)
    o << n->formal << " => ";
  o << n->actual;
}

void
m_vaul_print_to_ostream (pVAUL_AmbgEnumLitRef n, ostream &o)
{
  o << n->set->name;
}

void
m_vaul_print_to_ostream (pIIR_Allocator n, ostream &o)
{
  o << "new ...";
}

static const char *
attr_name (pIIR_Expression e)
{
  const char *l = e->kind_name ();
  if (strncmp (l, "IIR_Attr_", 9) == 0)
    return l+9;
  else
    return "???";
}

void
m_vaul_print_to_ostream (pIIR_AttrTypeValue n, ostream &o)
{
  o << n->prefix << "'" << attr_name (n);
  if (n->argument)
    o << "(...)";
}

void
m_vaul_print_to_ostream (pIIR_AttrTypeFunc n, ostream &o)
{
  o << n->prefix << "'" << attr_name (n);
  if (n->argument)
    o << "(...)";
}

static int posinfo_size = 0;

static void
posinfo_stats ()
{
  fprintf (stderr, "Used %d for posinfos.\n", posinfo_size);
}

pIIR_PosInfo
vaul_node_creator_base::make_posinfo (int lineno)
{
#if 0
  if (posinfo_size == 0)
    atexit (posinfo_stats);
  posinfo_size += sizeof(IIR_PosInfo_TextFile);
#endif
  
  return new IIR_PosInfo_TextFile(cur_du->get_source (), lineno);
}

