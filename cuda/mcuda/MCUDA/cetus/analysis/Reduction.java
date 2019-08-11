package cetus.analysis; 

import cetus.hir.*;
import java.util.*;

/**
 * Performs reduction variable analysis to detect and annotate statements like
 * x = x + i in loops. An Annotation is added before loops that contain
 * reduction variables. The text of the Annotation is "reduce" and its map
 * includes the key "statement", with the Loop object as its value, and keys
 * for each of the reduction operations (+, -, etc) with a LinkedList of
 * variable names as their values.
 */
public class Reduction extends AnalysisPass
{
  /** Holds the names of all valid reduction variables (those that are
      written exactly once in a loop using a rhs that includes the same
      variable). */
  private HashSet<String> valid_set;

  /** Holds the names of all invalid reduction variables (those that are
      written more than once in a loop or with a rhs that does not
      include the same variable). */
  private HashSet<String> invalid_set;

  private HashMap<String, List<Expression>> op_to_vars;

  public Reduction(Program program)
  {
    super(program);
    this.valid_set = new HashSet<String>();
    this.invalid_set = new HashSet<String>();
    this.op_to_vars = new HashMap<String, List<Expression>>();
  }

  public String getPassName()
  {
    return new String("[Reduction]");
  }

  public void start()
  {
    BreadthFirstIterator iter = new BreadthFirstIterator(program);
    iter.pruneOn(Loop.class);

    for (;;)
    {
      Loop loop = null;

      try {
        loop = (Loop)iter.next(Loop.class);
      } catch (NoSuchElementException e) {
        break;
      }

      checkLoop(loop);

      /* Clean up for the next loop.  checkLoop may be invoked
         recursively, so this cleanup cannot be done within
         checkLoop. */
      valid_set.clear();
      invalid_set.clear();
      op_to_vars.clear();
    }
  }

  private void checkLoop(Loop loop)
  {
    FlatIterator iter = new FlatIterator(loop.getBody());

    /* Process the loop's body to construct the valid set. */
    while (iter.hasNext())
    {
      Statement stmt = (Statement)iter.next();

      if (stmt instanceof Loop)
      {
        /* recursively check any inner loops */
        checkLoop((Loop)stmt);
      }
      else if (stmt instanceof ExpressionStatement)
      {
        checkExpressionStatement((ExpressionStatement)stmt);  
      }
    }

//    System.out.println("op_to_vars = " + op_to_vars.toString());
//    System.out.println("valid set = " + valid_set.toString());

    Annotation note = new Annotation("reduce");

    Map<String, List<Expression>> map = new TreeMap<String, List<Expression>>();

    Iterator<Map.Entry<String,List<Expression>>> map_pairs = op_to_vars.entrySet().iterator();
    while (map_pairs.hasNext())
    {
      Map.Entry<String,List<Expression>> pair = map_pairs.next(); 

      LinkedList<Expression> list = (LinkedList<Expression>)pair.getValue();

      LinkedList<Expression> note_list = new LinkedList<Expression>();
 
      for (Expression e : list)
      {
        if (valid_set.contains(e.toString()))
          note_list.add(e);
      }

      map.put(pair.getKey().toString(), note_list); 
    }

    note.add("map", map);

    note.setPrintMethod(null);

    ((CompoundStatement)((Statement)loop).getParent()).addStatementBefore((Statement)loop, new DeclarationStatement(note));
  }

  private void checkExpressionStatement(ExpressionStatement stmt)
  {
    Expression top_expr = ((ExpressionStatement)stmt).getExpression();

    if (top_expr instanceof AssignmentExpression)
    {
      AssignmentExpression assignment = (AssignmentExpression)top_expr;

      Expression lhse = assignment.getLHS();
      Expression rhse = assignment.getRHS();

      /* this is used many times so store the converted string */
      String lhse_str = lhse.toString();

      if (lhse instanceof IDExpression)
      {
        AssignmentOperator assign_op = assignment.getOperator();
        int count = Tools.countExpressions(rhse, lhse);

        /* we want either a normal assignment where the lhs also
           appears on the rhs, or an abbreviated syntax (e.g., +=)
           where the lhs does not appear on the rhs */
        if ((assign_op == AssignmentOperator.NORMAL
             && count == 1) ||
            (assign_op != AssignmentOperator.NORMAL
             && count == 0))
        {
          if (valid_set.contains(lhse_str))
          {
            /* if it's already valid, then it's already been
               written once and this is the second time, so
               move it to the invalid set */
            invalid_set.add(lhse_str);
            valid_set.remove(lhse_str);
          }
          else if (!invalid_set.contains(lhse_str))
          {
            /* if it's not invalid, then it appears to be a
               reduction variable, so add it to the valid set */
            valid_set.add(lhse_str);

            /* discover the kind of reduction operation (+, etc) */
            String op;

            if (assign_op == AssignmentOperator.NORMAL)
              op = ((BinaryExpression)rhse).getOperator().toString();
            else
            {
              op = assign_op.toString();
              op = op.substring(0, op.length() - 1);
            }

            /* associate the reduction variable with its type of
               reduction operation */
            List<Expression> list = op_to_vars.get(op);
            
            if (list == null)
              list = new LinkedList<Expression>();

            list.add(lhse);

            op_to_vars.put(op, list);
          }
        }
        else
        {
          /* this assignment doesn't involve a reduction variable,
             but it does invalidate the lhs */

          if (valid_set.contains(lhse_str))
            valid_set.remove(lhse_str);

          invalid_set.add(lhse_str); 
        }
      }            
    }
  }

  public static Set<Expression> getReductionVariables(Map<String, List<Expression>> map)
  {
    HashSet<Expression> set = new HashSet<Expression>();

    Collection<List<Expression>> c = map.values();

    if (c != null)
    {
      for (List<Expression> list : c)
        set.addAll(list);
    }

    return set;
  }

  public static Map<String, List<Expression>> getOperatorToVariablesMap(Annotation note)
  {
    if (note.getText().compareTo("reduce") == 0)
      return (Map<String, List<Expression>>)note.getMap().get("map");
    else
      return new TreeMap<String, List<Expression>>();
  }
}
