package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.exec.*;
import cetus.hir.*;

/**
 * Transforms a program such that every procedure has at
 * most one return statement.  A new variable is introduced
 * to store the return value.  Each return statement is
 * replaced with a store of the return value followed by
 * a jump to a final return statement that returns the
 * variable.  This pass facilitates adding instrumentation
 * code immediately before a procedure's exit.
 */
public class SingleReturn extends ProcedureTransformPass
{
  public SingleReturn(Program program)
  {
    super(program);
  }

  public String getPassName()
  {
    return new String("[SingleReturn]");
  }

  public void transformProcedure(Procedure proc)
  {
    String done_label = "_done";
    String return_variable = "_ret_val";

    /* Get a list of the existing return statements in the procedure.
       Do not do this later or it will also find the new labeled return. */
    List list = findReturnStatements(proc);

    CompoundStatement body = proc.getBody();

    List ret_type = (new ChainedList()).addAllLinks(proc.getReturnType());
    while (ret_type.remove(Specifier.STATIC));    

    boolean ret_type_void = ret_type.size() == 1
                            && ret_type.get(0) == Specifier.VOID;

    if (!ret_type_void)
    {
      /* add a variable _ret_val of the same type as the procedure return type */

      /* check for implicit int (TODO - differentiate this from constructors) */
      if (ret_type.size() == 0)
        ret_type = (new ChainedList<Specifier>()).addLink(Specifier.INT);

      body.addDeclaration(new VariableDeclaration(ret_type,
                          new VariableDeclarator(new Identifier(return_variable))));
    }

    /* add a labeled return statement to the end of the procedure */

    body.addStatement(new Label(new Identifier(done_label)));

    if (!ret_type_void)
      body.addStatement(new ReturnStatement(new Identifier(return_variable)));
    else
      body.addStatement(new ReturnStatement());

    /* redirect the preexisting return statements to the labeled return */

    Iterator iter = list.iterator();
    while (iter.hasNext())
    {
      ReturnStatement stmt = (ReturnStatement)iter.next();

      if (ret_type_void)
      {
        stmt.swapWith(new GotoStatement(new Identifier(done_label)));
      }
      else
      {
        CompoundStatement new_code = new CompoundStatement();
        Identifier dummy = new Identifier("");

        new_code.addStatement(new ExpressionStatement(new AssignmentExpression(
          new Identifier(return_variable), AssignmentOperator.NORMAL, dummy)));
        dummy.swapWith(stmt.getExpression());
        new_code.addStatement(new GotoStatement(new Identifier(done_label)));
        stmt.swapWith(new_code);
      }
    }
  }

  private List findReturnStatements(Traversable root)
  {
    LinkedList<ReturnStatement> return_list = new LinkedList<ReturnStatement>();

    BreadthFirstIterator iter = new BreadthFirstIterator(root);
    iter.pruneOn(Expression.class); /* optimization */

    for (;;)
    {
      ReturnStatement stmt = null;

      try {
        stmt = (ReturnStatement)iter.next(ReturnStatement.class);
      } catch (NoSuchElementException e) {
        break;
      }

      return_list.add(stmt);
    }

    return return_list;
  }
}
