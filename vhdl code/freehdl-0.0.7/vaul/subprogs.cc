/* functions, procedures and interfaces

   Copyright (C) 1994-1997 University of Dortmund
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

#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-util.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define psr vaul_parser

static bool
check_for_proper_type (pIIR_Type t)
{
  if (t->is(IR_ACCESS_TYPE)
      || t->is(IR_FILE_TYPE))
    return false;
  else if (t->is(IR_ARRAY_TYPE))
    return check_for_proper_type (pIIR_ArrayType(t)->element_type);
  else if (t->is(IR_RECORD_TYPE))
    {
      for (pIIR_ElementDeclarationList el =
	     pIIR_RecordType(t)->element_declarations;
	   el; el = el->rest)
	if (!check_for_proper_type (el->first->subtype->base))
	  return false;
    }
  return true;
}

pIIR_InterfaceDeclaration
psr::build_Interface (pIIR_TextLiteral declarator,
		      pIIR_Type subtype,
		      pIIR_Expression value,
		      VAUL_ObjectClass obj_class,
		      IR_Mode mode,
		      bool bus)
{
  // XXX - merge the validate functions with this.

  if (declarator == NULL || subtype == NULL)
    return NULL;

  if (obj_class == VAUL_ObjClass_None)
    obj_class = cur_default_obj_class;
  if (obj_class != VAUL_ObjClass_File && mode == IR_UNKNOWN_MODE)
    mode = IR_IN_MODE;
  if (obj_class == VAUL_ObjClass_None)
    {
      if (mode == IR_IN_MODE)
	obj_class = VAUL_ObjClass_Constant;
      else
	obj_class = VAUL_ObjClass_Variable;
    }

  if (obj_class == VAUL_ObjClass_Constant
      || obj_class == VAUL_ObjClass_Signal)
    {
      if (!check_for_proper_type (subtype->base))
	error ("%:%n is an illegal type for %n",
	       declarator, subtype, declarator);
    }
  else if (obj_class == VAUL_ObjClass_File)
    {
      if (!subtype->base->is (IR_FILE_TYPE))
	error ("%:file parameter %n must have a file type",
	       declarator, declarator);
    }
  
  switch (obj_class)
    {
    case VAUL_ObjClass_Constant:
      return mIIR_ConstantInterfaceDeclaration (declarator->pos,
						declarator,
						subtype,
						value,
						mode,
						bus);
    case VAUL_ObjClass_Variable:
      return mIIR_VariableInterfaceDeclaration (declarator->pos,
						declarator,
						subtype,
						value,
						mode,
						bus);
    case VAUL_ObjClass_Signal:
      return mIIR_SignalInterfaceDeclaration (declarator->pos,
					      declarator,
					      subtype,
					      value,
					      mode,
					      bus,
					      IR_NO_SIGNAL_KIND);
    case VAUL_ObjClass_File:
      return mIIR_FileInterfaceDeclaration (declarator->pos,
					    declarator,
					    subtype,
					    value,
					    mode,
					    bus);
    default:
      info ("XXX - no object class for interface?");
      return NULL;
    }
}

void
psr::validate_interface (pIIR_SubprogramDeclaration s,
			 pIIR_InterfaceDeclaration i)
{
  if (s == NULL || i == NULL)
    return;
  
  VAUL_ObjectClass obj_class = vaul_get_class (i);

  if (obj_class == VAUL_ObjClass_File)
    {
      if (i->mode != IR_UNKNOWN_MODE)
	{
	  error ("%:file parameters can not have a mode", i);
	  i->mode = IR_UNKNOWN_MODE;
	}
    }
  else if (i->mode == IR_UNKNOWN_MODE)
    i->mode = IR_IN_MODE;

  if (s->is(IR_PROCEDURE_DECLARATION))
    {
      if (i->mode == IR_BUFFER_MODE || i->mode == IR_LINKAGE_MODE) 
	{
	  error ("%:illegal mode for %n", i, i);
	  i->mode = IR_INOUT_MODE;
	}
    }
  else 
    {
      if (i->mode != IR_IN_MODE) 
	{
	  error("%:%n must have mode 'in'", i, i);
	  i->mode = IR_IN_MODE;
	}
    }

  if (i->initial_value)
    {
      // Check whether a default value is allowed.

      if (obj_class == VAUL_ObjClass_Signal)
	{
	  error ("%: %n can not have a default value because it is a signal",
		 i->initial_value, i);
	  i->initial_value = NULL;
	}
      else if (obj_class == VAUL_ObjClass_Variable
	       && i->mode != IR_IN_MODE)
	{
	  error ("%: %n can not have a default value because it is a variable"
		 " of mode other than `in'", i->initial_value, i);
	  i->initial_value = NULL;
	}
    }


}

void
psr::validate_port (pIIR_InterfaceDeclaration i)
{
  if (i == NULL)
    return;
  
  VAUL_ObjectClass obj_class = vaul_get_class (i);

  if (obj_class != VAUL_ObjClass_Signal)
    error ("%:port %n must be a signal", i, i);
  if (i->mode == IR_UNKNOWN_MODE)
    i->mode = IR_IN_MODE;

  if (i->initial_value)
    {
      // Check whether a default value is allowed.

      if (i->mode == IR_LINKAGE_MODE)
	{
	  error ("%: %n can not have a default value because it has mode"
		 " linkage", i->initial_value, i);
	  i->initial_value = NULL;
	}
    }
}

void
psr::validate_generic (pIIR_InterfaceDeclaration i)
{
  if (i == NULL)
    return;
  
  VAUL_ObjectClass obj_class = vaul_get_class (i);

  if (obj_class != VAUL_ObjClass_Constant)
    error("%:generic %n must be a constant", i, i);
  if (i->mode != IR_IN_MODE) 
    {
      if (i->mode != IR_UNKNOWN_MODE)
	error ("%:generic must have mode 'in'", i, i);
      i->mode = IR_IN_MODE;
    }
}
