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
public class AnsiDeclarations extends ProcedureTransformPass
{
  public AnsiDeclarations(Program program)
  {
    super(program);
  }

  public void transformProcedure(Procedure proc)
  {
    DepthFirstIterator iter = new DepthFirstIterator(proc);

    while(iter.hasNext())
    {
      CompoundStatement scope;
      
      try {
	scope=(CompoundStatement)iter.next(CompoundStatement.class);
      } catch (NoSuchElementException e) {
	break;
      }

      List statements = scope.getChildren();

      int i = 0;
      int currentStmt = i;
      while(i < statements.size())
      {
	Statement nextStmt = (Statement)statements.get(currentStmt);
	
	if(nextStmt instanceof DeclarationStatement)
	  currentStmt++;
	else
	{
	  nextStmt.detach();
	  scope.addStatement(nextStmt);
	}
	  
	i++;
      }
   
    }
  }

	

  public String getPassName()
  {
    return new String("[AnsiDeclarations]");
  }
}
