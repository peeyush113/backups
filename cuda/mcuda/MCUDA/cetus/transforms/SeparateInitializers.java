package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.exec.*;
import cetus.hir.*;

/**
 * Transforms a program such that every variable declaration 
 * within a program has no initializer.  The declared initializers 
 * are separated into independent statements.  Requires that 
 * the single declaration pass has been run first.
 */
public class SeparateInitializers extends KernelTransformPass
{
  public SeparateInitializers(Program program)
  {
    super(program);
  }

  public void transformProcedure(Procedure proc)
  {
    DepthFirstIterator iter = new DepthFirstIterator(proc);

    while(iter.hasNext())
    {
      DeclarationStatement declStmt;
      
      try {
	declStmt=(DeclarationStatement)iter.next(DeclarationStatement.class);
      } catch (NoSuchElementException e) {
	break;
      }
   
      //Skip over annotations, or other unknown declaration types.
      if(!(declStmt.getDeclaration() instanceof VariableDeclaration))
	continue;
      
      //TODO: make this compatible with function prototype 
      //declarations.
      VariableDeclaration vDecl = 
	(VariableDeclaration)declStmt.getDeclaration();
      
      VariableDeclarator variable = 
	(VariableDeclarator)vDecl.getDeclarator(0);

      Initializer vInit = variable.getInitializer();
      
      if(vInit == null)
	continue;

      // Check to see if the initialization is an invariant 
      // initialization of a const value

      if(((variable.getSpecifiers()).contains(Specifier.CONST)))
      {
	DepthFirstIterator temp_iter = new DepthFirstIterator(vInit);

	try {
	  Identifier test = (Identifier)iter.next(Identifier.class);
	} catch (NoSuchElementException e) {
	  continue;
	}
      }

      //TODO: make compatible with array initializers.  
      //Only handles scalar expression initializers right now.
      List children = vInit.getChildren();
      
      if(children.size() > 1 ||
	  !( children.get(0) instanceof Expression ) )
	throw new UnsupportedInput("Only primitive initializers are currently supported");


      Expression initExpr = 
	(Expression)((Expression)children.get(0)).clone();
      
      //Unlink the initializer
      //This really should work, but it doesn't
      variable.setInitializer(null);
      Identifier vID = 
	(Identifier)variable.getDirectDeclarator().clone();

      AssignmentExpression vAssign =
	new AssignmentExpression(vID, AssignmentOperator.NORMAL, initExpr);

      ExpressionStatement vStmt = new ExpressionStatement(vAssign);

      //Making some assumptions about the parse tree.
      //Parent of a Vdecl with an initializer must be a DeclStmt, and 
      //the parent of a DeclStmt must be a CompoundStmt
	
      CompoundStatement scope = (CompoundStatement)declStmt.getParent();

      scope.addStatementAfter(declStmt, vStmt);
    }
  }

	

  public String getPassName()
  {
    return new String("[SeparateInitializers]");
  }
}
