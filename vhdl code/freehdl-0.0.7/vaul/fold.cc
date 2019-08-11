/* simple constant folding for universal integers

   Copyright (C) 2000 Marius Vollmer

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

bool
psr::evaluate_locally_static_universal_integer (pIIR_Expression e, int &n)
{
  // XXX - should be done by the backend but we decided to have a
  // simple version here to reduce dependencies while the code
  // generator is still changing rapidly.

  if (e->static_level < IR_LOCALLY_STATIC)
    {
      error ("%:%n is not locally static", e, e);
      return false;
    }

  if (e->is(IR_ABSTRACT_LITERAL_EXPRESSION))
    {
      pIIR_AbstractLiteralExpression ale = pIIR_AbstractLiteralExpression(e);
      n = 0;
      if (ale->value->is(IR_INTEGER_LITERAL))
	{
	  pIIR_IntegerLiteral l = pIIR_IntegerLiteral(ale->value);
	  for (int i = 0; i < l->text.len(); i++)
	    {
	      IR_Character c = l->text[i];
	      if(c == '_')
		continue;
	      if(c >= '0' && c <= '9')
		n = n*10 + c-'0';
	      else 
		{
		  info ("XXX - unsupported abstract literal syntax");
		  return false;
		}
	    }

	  if (e->is(IR_PHYSICAL_LITERAL))
	    {
	      // account for unit
	      pIIR_PhysicalUnit u = pIIR_PhysicalLiteral(e)->unit;
	      if (u->multiplier)
		{
		  int m;
		  if (!evaluate_locally_static_universal_integer 
		      (u->multiplier, m))
		    return false;
		  n *= m;
		}
	    }

	  return true;
	}
      else
	{
	  info ("XXX - unsupported literal: %n", ale);
	  return false;
	}
    }
  else if (e->is(IR_SIMPLE_REFERENCE))
    {
      pIIR_ObjectDeclaration d = pIIR_SimpleReference(e)->object;
      if (d->is(IR_CONSTANT_DECLARATION))
	return evaluate_locally_static_universal_integer (d->initial_value,
							  n);
    }
  else if (e->is(IR_FUNCTION_CALL))
    {
      pIIR_FunctionCall fc = pIIR_FunctionCall(e);
      pIIR_AssociationList pal = fc->parameter_association_list;
      pIIR_FunctionDeclaration f = fc->function;

      if (pal == NULL || (pal->rest && pal->rest->rest != NULL))
	{
	  error ("%:%n can not be used in a locally static"
		 " integer expression", e, f);
	  return false;
	}

      int arg1;
      if (!evaluate_locally_static_universal_integer(pal->first->actual, arg1))
	return false;
      
      if (pal->rest == NULL)   // one arg
	{
	  if (vaul_name_eq (f->declarator, "\"+\""))
	    n = arg1;
	  else if (vaul_name_eq (f->declarator, "\"-\""))
	    n = -arg1;
	  else if (vaul_name_eq (f->declarator, "abs"))
	    n = abs (arg1);
	  else
	    {
	      error ("%:%n can not be used in a locally static"
		     " integer expression", e, f);
	      return false;
	    }
	  return true;
	}
      
      int arg2;
      if (!evaluate_locally_static_universal_integer (pal->rest->first->actual,
						      arg2))
	return false;

      if (vaul_name_eq (f->declarator, "\"+\""))
	n = arg1 + arg2;
      else if (vaul_name_eq (f->declarator, "\"-\""))
	n = arg1 - arg2;
      else if (vaul_name_eq (f->declarator, "\"*\""))
	n = arg1 * arg2;
      else if (vaul_name_eq (f->declarator, "\"/\""))
	{
#if 0
	  if (pal->first->actual->subtype->is (IR_PHYSICAL_TYPE))
	    {
	      info ("XXX - no physical types allowed here yet");
	      return false;
	    }
#endif
	  n = arg1 / arg2;
	}
      else if (vaul_name_eq (f->declarator, "\"mod\""))
	n = arg1 % arg2;  // XXX - correct?
      else if (vaul_name_eq (f->declarator, "\"rem\""))
	n = arg1 % arg2;  // XXX - correct?
      else
	{
	  error ("%:%n can not be used in a locally static"
		 " integer expression", e, f);
	  return false;
	}
      return true;
    }

  info("%:XXX - %s should not appear in a locally static "
       "integer expression",  e, e->kind_name());
  return false;
}
