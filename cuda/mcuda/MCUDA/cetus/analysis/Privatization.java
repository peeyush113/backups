package cetus.analysis;

import java.util.*;

import cetus.hir.*;

/**
 * Performs privatization analysis on all Loops within
 * a Program.  Scalars are handled by searching for
 * variables that are defined before they are used
 * within the loop.  
 */
public class Privatization extends LoopAnalysisPass
{
  public Privatization(Program program)
  {
    super(program);
  }

  /**
   * Performs privatization analysis on a single Loop and
   * places the result of the analysis in an Annotation
   * immediately before the Loop.
   */
  public void analyzeLoop(Loop loop)
  {
    TreeSet<Expression> private_set = new TreeSet<Expression>();
    TreeSet<Expression> used_set = new TreeSet<Expression>();

    /* upon seeing a define of an IDExpression
         already in used_set => do nothing
         not already in used_set => place in private_set   

       upon seeing a use of an IDExpression
         place in used_set
    */

    FlatIterator iter = new FlatIterator(loop.getBody());

    for (;;)
    {
      Statement stmt = null;
      
      try {
        stmt = (Statement)iter.next(Statement.class);
      } catch (NoSuchElementException e) {
        break;
      }

      Tools.printlnStatus(getPassName() + ": statement is " + stmt.toString(), 1);

      Set<Expression> stmt_use_set = DataFlow.getUseSet(stmt);
      Tools.printlnStatus(getPassName() + ":   use " + stmt_use_set.toString(), 1);

      Set<Expression> stmt_def_set = DataFlow.defines(stmt);
      Tools.printlnStatus(getPassName() + ":   def " + stmt_def_set.toString(), 1);

      used_set.addAll(stmt_use_set);

      for (Expression expr : stmt_def_set)
      {
        if (!used_set.contains(expr))
          private_set.add(expr);
      }

      Tools.printlnStatus(getPassName() + ":   private " + private_set.toString(), 1);
    }

    TreeSet<Expression> scalar_private = new TreeSet<Expression>();
    TreeSet<ArrayAccess> array_private = new TreeSet<ArrayAccess>();
    DataFlow.partitionScalarsAndArrays(scalar_private, array_private, private_set);

    TreeSet<Expression> scalar_used = new TreeSet<Expression>();
    TreeSet<ArrayAccess> array_used = new TreeSet<ArrayAccess>();
    DataFlow.partitionScalarsAndArrays(scalar_used, array_used, used_set);

    TreeSet<Expression> private_array_names = new TreeSet<Expression>();

    for (ArrayAccess a : array_private)
    {
      private_array_names.add(a.getArrayName());
    }

    for (ArrayAccess a : array_used)
    {
      if (!array_private.contains(a))
        private_array_names.remove(a.getArrayName());
    }

    scalar_private.addAll(private_array_names);

    Annotation note = new Annotation("private");
    note.setPrintMethod(null);
    note.getMap().put("variables", scalar_private);

    Tools.printlnStatus(getPassName() + ": adding private annotation " + scalar_private.toString(), 1);
    ((CompoundStatement)((Statement)loop).getParent()).addStatementBefore((Statement)loop, new DeclarationStatement(note));
  }

  public String getPassName()
  {
    return new String("[Privatization]");
  }

  public static Set<Expression> getPrivateSet(Annotation note)
  {
    if (note.getText().compareTo("private") == 0)
      return (Set<Expression>)note.getMap().get("variables");
    else
      return new TreeSet<Expression>();
  }

  public static String getPrivateString(Set private_set)
  {
    String variables = new String();

    for (Object e : private_set)
    {
      variables += e.toString();
      variables += ",";
    }

    if (variables.length() > 0)
      variables = variables.substring(0, variables.length() - 1);

    return variables;
  }
}
