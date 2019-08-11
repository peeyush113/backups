#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "mapping.h"
#include "v2cc-util.h"



// Used to generate error messages
extern vaul_error_printer codegen_error;


// This function moves an item within a declaration region to the
// declarative region defined by static_declarative_region. E.g., if a
// constant has been defined in an architechture then it will be
// defined globally in the generated C++ code if the initialization
// value is locally static. This is done in order to prevent the code
// generator from generating an identical constant within each
// instance of the architecture.
void
reschedule_declaration_region(RegionStack &rstack)
{
  const bool is_architecture_top_region = 
    TopDeclarativeRegion (rstack)->is (IR_ARCHITECTURE_DECLARATION);

  pIIR_DeclarativeRegion active_region = ActiveDeclarativeRegion (rstack);
  pIIR_DeclarativeRegion root_region = RootDeclarativeRegion (rstack);

  pIIR_DeclarationList *dlp = &extended_declarations (active_region);
  while ((*dlp) != NULL) {
    pIIR_DeclarativeRegion static_region = static_declarative_region ((*dlp)->first);

    if ((*dlp)->first->is(IR_SUBPROGRAM_DECLARATION))
      optimize ((*dlp)->first, rstack);

    else if (static_region != NULL &&
	     active_region != root_region &&
	     static_region != active_region &&
	     ((*dlp)->first->is(IR_CONSTANT_DECLARATION) ||
	      (*dlp)->first->is(IR_TYPE_DECLARATION)) &&
	     // If we are processing architecture declarations and the
	     // object is static with respect to the entity, then do
	     // nothing as we cannot move declarations into entities. Same
	     // for package and package body declarations.
	     !(static_region->is (IR_ENTITY_DECLARATION) &&
	       active_region->is (IR_ARCHITECTURE_DECLARATION)) &&
	     !(static_region->is (IR_PACKAGE_DECLARATION) &&
	       active_region->is (IR_PACKAGE_BODY_DECLARATION))) 
      {
	//cout << (*dlp)->first->declarator->text.to_chars() << " " 
	//   << static_region->kind_name () << endl;
	// Test whether we are currently processing an architecture
	// and the object is static with respect to the entity
	// region. As we cannot insert any declarations into the
	// entity declaration list, move it to the architecture
	// declaration.
	if (is_architecture_top_region &&
	    static_region->is (IR_ENTITY_DECLARATION))
	  static_region = TopDeclarativeRegion (rstack);

	pIIR_DeclarationList *listp = 
	  get_last_rest_address (&extended_declarations (static_region));
	*listp =  new IIR_DeclarationList ((*dlp)->first->pos, (*dlp)->first, *listp);
	*dlp = (*dlp)->rest;
	continue;
      } 
    
    dlp = &(*dlp)->rest;
  }
}





// ******************************************************************************************
// Name: m_optimize, generic function
//
// Description: performs some optimizations on the node tree
//
// Return value: void
//
// ******************************************************************************************

void
m_optimize (pIIR_PredefinedFunctionDeclaration sp, RegionStack &rstack)
{
  rstack.push(sp);
  rstack.pop();
}



void
m_optimize (pIIR_SubprogramDeclaration sp, RegionStack &rstack)
{
  rstack.push(sp);  
  
  // Note that if the subprogram is declared in a package (or in
  // another subprogram that is declared in a package) then do not try
  // to move declaration as this might cause initialization races:

  // package race is
  //  function func return integer; 
  //  constant const : integer := func;
  // end package;
  // package body race is 
  //  function func return integer is 
  //   constant const2 : integer := 1;
  //  begin 
  //   return const2;
  //  end func;
  // end package body;

  // In the C++ code the package body is elaborated AFTER the package
  // declaration. Hence, if const2 is initialized globally, if will
  // get its initial value too late!
  pIIR_DeclarativeRegion top_region = TopDeclarativeRegion(rstack);
  if (!top_region->is(IR_PACKAGE_BODY_DECLARATION))
    {
      if (extended_declarations(sp) != NULL)
	reschedule_declaration_region (rstack);
    }

  rstack.pop();
}


void
m_optimize (pIIR_EntityDeclaration e, RegionStack &rstack)
{
  rstack.push(e);
  reschedule_declaration_region (rstack);
  if (e->entity_statement_part != NULL)
    optimize(e->entity_statement_part, rstack);
  rstack.pop();
}



void
m_optimize (pIIR_Type st, RegionStack &rstack)
{
}


void
m_optimize (pIIR_ArchitectureDeclaration a, RegionStack &rstack)
{
  rstack.push(a);

  if (extended_declarations(a) != NULL)
    reschedule_declaration_region (rstack);
  if (a->architecture_statement_part != NULL)
    optimize(a->architecture_statement_part, rstack);

  rstack.pop();
}


void
m_optimize (pIIR_ConcurrentStatementList csl, RegionStack &rstack)
{
  for (pIIR_ConcurrentStatementList l = csl; l; l = l->rest)
    optimize(l->first, rstack);
}


void
m_optimize (pIIR_ProcessStatement p, RegionStack &rstack)
{
  rstack.push(p);
  if (extended_declarations(p) != NULL)
    reschedule_declaration_region (rstack);
  rstack.pop();
}


// Do not re-order delcaration in packages as they will be already
// emitted at a global level. Re-scheduling may break correct
// initialization order!
void
m_optimize (pIIR_PackageDeclaration p, RegionStack &rstack)
{
  rstack.push(p);
  rstack.pop();
}


// Do not re-order delcaration in packages as they will be already
// emitted at a global level. Re-scheduling may break correct
// initialization order!
void
m_optimize (pIIR_PackageBodyDeclaration pb, RegionStack &rstack)
{
  rstack.push(pb);
  rstack.pop();
}


void
m_optimize (pIIR_ConfigurationDeclaration c, RegionStack &rstack)
{
  rstack.push(c);
  rstack.pop();
}


void
m_optimize (pIIR_ComponentInstantiationStatement cis, RegionStack &rstack)
{
  rstack.push(cis);
  rstack.pop();
}


void
m_optimize (pIIR_ComponentDeclaration c, RegionStack &rstack)
{
  rstack.push(c);
  rstack.pop();
}


void
m_optimize(pIIR_ConcurrentGenerateIfStatement gs, RegionStack &rstack)
{
  rstack.push(gs);
  if (extended_declarations(gs) != NULL)
    reschedule_declaration_region (rstack);
  if (gs->concurrent_statement_part!= NULL)
    optimize(gs->concurrent_statement_part, rstack);
  rstack.pop();
}


void
m_optimize(pIIR_ConcurrentGenerateForStatement gs, RegionStack &rstack)
{
  rstack.push(gs);
  if (extended_declarations(gs) != NULL)
    reschedule_declaration_region (rstack);
  if (gs->concurrent_statement_part != NULL)
    optimize(gs->concurrent_statement_part, rstack);
  rstack.pop();
}



