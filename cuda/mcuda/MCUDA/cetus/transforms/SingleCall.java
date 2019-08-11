package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.exec.*;
import cetus.hir.*;

/**
 * Transforms a program such that every statement contains
 * at most one function call.  In the case of nested calls,
 * the innermost calls will be called first.  Temporaries
 * are introduced to hold the results of function calls.
 */
public class SingleCall extends ProcedureTransformPass
{
  public SingleCall(Program program)
  {
    super(program);
  }

  private int countFunctionCalls(Traversable root)
  {
    int total = 0;
    BreadthFirstIterator iter = new BreadthFirstIterator(root);

    while (iter.hasNext())
    {
      if (iter.next() instanceof FunctionCall)
        ++total;
    }

    return total;
  }

  public void transformProcedure(Procedure proc)
  {
    String temp_base = "_tmp";
    int temp_num = 0;

    List list = findStatementsWithMultipleCalls(proc);

    Iterator iter = list.iterator();
    while (iter.hasNext())
    {
      ExpressionStatement stmt = (ExpressionStatement)iter.next();

      Tools.printStatus(getPassName() + " removing multiples in ", 3);
      Tools.printlnStatus(stmt, 3);

      /* make a list of the FunctionCalls in reverse BFS order */
      LinkedList<FunctionCall> call_list = new LinkedList<FunctionCall>();

      BreadthFirstIterator bfs = new BreadthFirstIterator(stmt);
      while (bfs.hasNext())
      {
        FunctionCall call;

        try {
          call = (FunctionCall)bfs.next(FunctionCall.class);
        } catch (NoSuchElementException e) {
          break;
        }

        call_list.addFirst(call);
      }

      /* unwrap the function calls in that order */

      CompoundStatement new_code = new CompoundStatement();

      Iterator call_list_iter = call_list.iterator();
      while (call_list_iter.hasNext())
      {
        FunctionCall call = (FunctionCall)call_list_iter.next();

        List tmp_type = (new ChainedList()).addAllLinks(call.getReturnType());

        while (tmp_type.remove(Specifier.STATIC));
        while (tmp_type.remove(Specifier.EXTERN));

        /* if the return type is void, we don't need a variable to hold its return value */
        if (!(tmp_type.size() == 1 && tmp_type.get(0) == Specifier.VOID))
        {
          String temp_name = temp_base + temp_num;
          temp_num++;

          Identifier x = new Identifier(temp_name);

          new_code.addDeclaration(new VariableDeclaration(tmp_type, new VariableDeclarator(new Identifier(temp_name))));
          new_code.addStatement(new ExpressionStatement(new AssignmentExpression(new Identifier(temp_name),
            AssignmentOperator.NORMAL, x)));

          x.swapWith(call);
        }
      }

      stmt.swapWith(new_code);
      new_code.addStatement(stmt);
    }
  }

  private List findStatementsWithMultipleCalls(Traversable root)
  {
    LinkedList<ExpressionStatement> call_list = new LinkedList<ExpressionStatement>();

    BreadthFirstIterator iter = new BreadthFirstIterator(root);
    iter.pruneOn(ExpressionStatement.class);

    for (;;)
    {
      ExpressionStatement stmt = null;

      try {
        stmt = (ExpressionStatement)iter.next(ExpressionStatement.class);
      } catch (NoSuchElementException e) {
        break;
      }

      if (countFunctionCalls(stmt) > 1)
        call_list.add(stmt);
    }

    return call_list;
  }

  public String getPassName()
  {
    return new String("[SingleCall]");
  }
}
