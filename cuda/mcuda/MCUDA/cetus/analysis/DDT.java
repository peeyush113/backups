package cetus.analysis;

import java.io.*;
import java.util.*;
import cetus.hir.*;

/**
 * The DDT (Data Dependence Test) pass attempts to identify
 * parallel loops within the program.
 */
public class DDT extends LoopAnalysisPass
{
  /**
   * Represents a pair of array index expressions to be compared, as in
   * the i and j in A[i] and B[j].
   */
  private class SubscriptPair
  {
    public Expression e1;
    public Expression e2;

    public SubscriptPair()
    {
      e1 = null; e2 = null;
    }

    public String toString()
    {
      return new String(e1.toString() + "," + e2.toString());
    }
  }

  public DDT(Program program)
  {
    super(program);
  }

  /**
   * Attempts to prove whether the loop is parallel or not.
   *
   * @return true if the loop is parallel and false if it
   *   could not be proven parallel.
   */
  public void analyzeLoop(Loop loop)
  {
    /* get the def and use sets for the loop body */
    Set<Expression> def_set = DataFlow.mayDefine(loop.getBody());
    Set<Expression> use_set = DataFlow.getUseSet(loop.getBody());

    /* partition the defs into scalar and array defs */
    Set<Expression>  scalar_def_set = new TreeSet<Expression>();
    Set<ArrayAccess> array_def_set  = new TreeSet<ArrayAccess>();

    DataFlow.partitionScalarsAndArrays(scalar_def_set, array_def_set, def_set);

    /* partition the uses into scalar and array uses */
    Set<Expression>  scalar_use_set = new TreeSet<Expression>();
    Set<ArrayAccess> array_use_set  = new TreeSet<ArrayAccess>();

    DataFlow.partitionScalarsAndArrays(scalar_use_set, array_use_set, use_set);

    /* test scalar variables for dependence, but ignore those that are
       private or reduction variables */

    TreeSet<Expression> private_set   = new TreeSet<Expression>();
    TreeSet<Expression> reduction_set = new TreeSet<Expression>();

    /* get the private and reduction sets from annotations before
       the loop */
    getPrivateAndReductionSets(private_set, reduction_set, loop);

    for (Expression def : scalar_def_set)
    {
      for (Expression use : scalar_use_set)
      {
        if (def.toString().compareTo(use.toString()) == 0
            && !private_set.contains(def)
            && !reduction_set.contains(def))
        {
          markSerial(loop);
          return;
        }
      }
    }

    /* test arrays for dependence
       TODO: array privatization is not implemented so it is ignored here
    */

    /* obtain the set of induction variables, which includes the loop counter
       for the current loop and any enclosing loops */
    Vector<InductionVariable> induction_variables = getInductionVariables(loop);

    System.out.println("induction variables are: " + induction_variables.toString());

    for (ArrayAccess def : array_def_set)
    {
      /* test output dependencies */
      for (ArrayAccess def2 : array_def_set)
      {
        if (def != def2
            && !testArrayDependence(def, def2, induction_variables))
        {
          System.out.println("dependence found: " + def + " and " + def2);
          markSerial(loop);
          return;
        }
      }

      /* test true and anti dependencies */
      for (ArrayAccess use : array_use_set)
      {
        if (!testArrayDependence(def, use, induction_variables))
        {
          System.out.println("dependence found: " + def + " and " + use);
          markSerial(loop);
          return;
        }
      }
    }

    System.out.println("loop was parallel");

    /* loop was proved parallel */
    markParallel(loop);
  }

  /** Finds the set of induction variables that appear in the group */
  private Vector<InductionVariable> complexityOf(Vector<SubscriptPair> group, Vector<InductionVariable> induction_variables)
  {
    Vector<InductionVariable> result = new Vector<InductionVariable>();

    for (InductionVariable ivar : induction_variables)
    {
      for (SubscriptPair pair : group)
      {
        if (Tools.containsExpression(pair.e1, ivar.variable)
            || Tools.containsExpression(pair.e2, ivar.variable))
        {
          result.add(ivar);
        }
      }
    }

    return result;
  }

  /** Partitions the subscript pairs into groups that 
   * use the same induction variables.
   */
  private Vector<Vector<SubscriptPair>> formMinimalCoupledGroups(Vector<SubscriptPair> pair_vector, Vector<InductionVariable> induction_variables)
  {
    /* start with each pair in a separate group */

    Vector<Vector<SubscriptPair>> group_vector = new Vector<Vector<SubscriptPair>>();

    int n = pair_vector.size();
    for (int i = 0; i < n; ++i)
    {
      Vector<SubscriptPair> group = new Vector<SubscriptPair>();
      group.add(pair_vector.get(i));
      group_vector.add(group);
    }

    /* merge groups that refer to the same loop counter */

    n = induction_variables.size();
    for (int i = 0; i < n; ++i)
    {
      int k = -1;

      int m = group_vector.size();

      for (int j = 0; j < m; ++j)
      {
        Vector<SubscriptPair> group = group_vector.get(j);

        if (groupContains(group, induction_variables.get(i)))
        {
          if (k == -1)
            k = j;
          else
          {
            group_vector.get(k).addAll(group);
            group_vector.remove(j);
            --m;
          }
        }
      }
    }

    return group_vector;
  }

  /** Creates a vector of subscript pairs from two array accesses by
   * pairing up the index expressions.
   */
  private Vector<SubscriptPair> formSubscriptPairs(ArrayAccess a1, ArrayAccess a2)
  {
    Vector<SubscriptPair> pair_vector = new Vector<SubscriptPair>();

    int n = a1.getNumIndices();

    for (int i = 0; i < n; ++i)
    {
      SubscriptPair pair = new SubscriptPair();

      pair.e1 = a1.getIndex(i);
      pair.e2 = a2.getIndex(i);

      pair_vector.add(pair);
    }

    return pair_vector;
  }

  private boolean groupContains(Vector<SubscriptPair> group, InductionVariable iv)
  {
    Expression var = iv.variable;

    for (SubscriptPair pair : group)
    {
      Expression expr = pair.e1;

      if (Tools.containsExpression(expr, var))
        return true;

      expr = pair.e2;

      if (Tools.containsExpression(expr, var))
        return true;
    }

    return false;
  }

  private Vector<InductionVariable> getInductionVariables(Loop loop)
  {
    Vector<InductionVariable> vars = new Vector<InductionVariable>();

    while (loop != null)
    {
      if (loop instanceof ForLoop)
      {
        ForLoop for_loop = (ForLoop)loop;

        vars.add(for_loop.identifyPrimaryInductionVariable());
      }

      /* get next enclosing loop */     
      Traversable t = (Traversable)loop;
      do {
        t = t.getParent();
      } while (t != null && !(t instanceof Loop));

      loop = (Loop)t; 
    }

    return vars;
  }

  public String getPassName()
  {
    return new String("[DDT]");
  }

  /**
   * Inspects annotations that immediately preceed the loop
   * for names of private and reduction variables.
   */
  private void getPrivateAndReductionSets(Set<Expression> private_set, Set<Expression> reduction_set, Loop loop)
  {
    private_set.clear();
    reduction_set.clear();

    List parents_children = ((Traversable)loop).getParent().getChildren();
    int loop_position = parents_children.indexOf(loop);

    for (int i = loop_position - 1; i >= 0; --i)
    {
      Object obj = parents_children.get(i);

      if (!(obj instanceof DeclarationStatement))
        break;

      DeclarationStatement decl_stmt = (DeclarationStatement)obj;
      Declaration decl = decl_stmt.getDeclaration();

      if (!(decl instanceof Annotation))
        break;

      Annotation note = (Annotation)decl;

      if (note.getText().compareTo("private") == 0)
      {
        Set vars = Privatization.getPrivateSet(note);

        private_set.addAll(vars);
      }
      else if (note.getText().compareTo("reduce") == 0)
      {
        Set vars = Reduction.getReductionVariables(Reduction.getOperatorToVariablesMap(note));

        reduction_set.addAll(vars);
      }
    }
  }

  /**
   * Adds an annotation before the loop indicating that
   * the loop is parallel.
   */
  private void markParallel(Loop loop)
  {
    Annotation note = new Annotation("DDT");
    note.add("result", "parallel");
    note.setPrintMethod(null);

    ((CompoundStatement)((Statement)loop).getParent()).addStatementBefore((Statement)loop, new DeclarationStatement(note));
  }

  /**
   * Adds an annotation before the loop indicating that
   * the loop is serial.
   */
  private void markSerial(Loop loop)
  {
    Annotation note = new Annotation("DDT");
    note.add("result", "serial");
    note.setPrintMethod(null);

    ((CompoundStatement)((Statement)loop).getParent()).addStatementBefore((Statement)loop, new DeclarationStatement(note)); 
  }

  private boolean testArrayDependence(ArrayAccess a1, ArrayAccess a2, Vector<InductionVariable> induction_variables)
  {
    System.out.println("testing possible array dep: " + a1.toString() + ", " + a2.toString());

    /* check if the array names match; if they don't, then the accesses are
       independent assuming no aliasing or out-of-bounds access */
    if (a1.getArrayName().toString().compareTo(a2.getArrayName().toString()) != 0)
      return true;

    /* form subscript pairs for the arrays; e.g., for a1[x1][y1] and a2[x2][y2]
       the pairs are (x1,x2) and (y1,y2) */
    Vector<SubscriptPair> subscript_pairs = formSubscriptPairs(a1, a2);

    System.out.println("subscript_pairs are " + subscript_pairs);

    /* partition subscript_pairs into groups that use the same induction variables */
    Vector<Vector<SubscriptPair>> min_coupled_groups = formMinimalCoupledGroups(subscript_pairs, induction_variables);

    System.out.println("min_coupled_groups are " + min_coupled_groups);

    /* perform a dependence test on each group separately */
    for (Vector<SubscriptPair> group : min_coupled_groups)
    {
      /* classify each group as ZIV, SIV, or MIV and apply an appropriate test */
      Vector<InductionVariable> ivars = complexityOf(group, induction_variables);

      switch (ivars.size())
      {
        case 0:
          if (testZIV(group))
            return true;

          break;

        case 1:
          if (testSIV(group, ivars.get(0)))
            return true;

          break;

        default:
          if (testMIV(group))
            return true;

          break;
      }
    }

    return false;
  }

  private boolean testZIV(Vector<SubscriptPair> group)
  {
    System.out.println("testZIV:" + group);

    for (SubscriptPair pair : group)
    {
      if (pair.e1.toString().compareTo(pair.e2.toString()) != 0)
        return true;
    }

    return false;
  }

  private boolean testSIV(Vector<SubscriptPair> group, InductionVariable ivar)
  {
    System.out.println("testSIV: " + group);

    /* determine if we're dealing with a strong, weak, weak-zero, or weak-crossing SIV */

    for (SubscriptPair pair : group)
    {
      Expression e1 = Tools.findExpression(pair.e1, ivar.variable);
      int e1_coeff = 1;
      int e1_const = 0;

      Object obj = e1.getParent();
      if (obj instanceof BinaryExpression)
      {
        BinaryExpression be = (BinaryExpression)obj;

        if (be.getOperator() == BinaryOperator.MULTIPLY)
        {
          e1_coeff = (new Integer(be.getLHS().toString())).intValue();

          obj = be.getParent();

          if (obj instanceof BinaryExpression)
            be = (BinaryExpression)obj;
          else
            be = null;
        }

        if (be != null && be.getOperator() == BinaryOperator.ADD)
          e1_const = (new Integer(be.getRHS().toString())).intValue();
      }

      Expression e2 = Tools.findExpression(pair.e2, ivar.variable);
      int e2_coeff = 1;
      int e2_const = 0;

      obj = e2.getParent();
      if (obj instanceof BinaryExpression)
      {
        BinaryExpression be = (BinaryExpression)obj;

        if (be.getOperator() == BinaryOperator.MULTIPLY)
        {
          e2_coeff = (new Integer(be.getLHS().toString())).intValue();

          obj = be.getParent();

          if (obj instanceof BinaryExpression)
            be = (BinaryExpression)obj;
          else
            be = null;
        }

        if (be != null && be.getOperator() == BinaryOperator.ADD)
          e2_const = (new Integer(be.getRHS().toString())).intValue();
      }

      System.out.println("e1: " + Integer.toString(e1_coeff) + " * ivar + " + Integer.toString(e1_const));
      System.out.println("e2: " + Integer.toString(e2_coeff) + " * ivar + " + Integer.toString(e2_const));

      if (e1_coeff == e2_coeff)
      {
        /* strong SIV */

        int distance  = (e1_const - e2_const) / e1_coeff;
        int remainder = (e1_const - e2_const) % e1_coeff;

        if (remainder != 0 ||
            Math.abs(distance) > (ivar.upper_bound - ivar.lower_bound))
          return true;
      }
      else if (e1_coeff == -e2_coeff)
      {
        /* weak-crossing SIV */

        int intersection = (e2_const - e1_const) / (2 * e1_coeff);
        int remainder    = (e2_const - e1_const) % (2 * e1_coeff);

        if (remainder > 1 ||
            intersection < ivar.lower_bound ||
            intersection > ivar.upper_bound)
          return true;
      }
      else if (e1_coeff == 0 && e2_coeff != 0)
      {
        /* weak-zero SIV */ 

        int intersection = (e2_const - e1_const) / e2_coeff;
        int remainder    = (e2_const - e1_const) % e2_coeff;

        if (remainder != 0 ||
            intersection < ivar.lower_bound ||
            intersection > ivar.upper_bound)
          return true;
      }
      else if (e1_coeff != 0 && e2_coeff == 0)
      {
        /* weak-zero SIV */

        int intersection = (e2_const - e1_const) / e1_coeff;
        int remainder    = (e2_const - e1_const) % e1_coeff;

        if (remainder != 0 ||
            intersection < ivar.lower_bound ||
            intersection > ivar.upper_bound)
          return true;
      }
      else
      {
        /* GCD test */

        int gcd = GCD.compute(e1_coeff, e2_coeff);

        if ((e2_const - e1_const) % gcd != 0)
          return true;
      }
    }

    return false;
  }

  private boolean testMIV(Vector<SubscriptPair> group)
  {
    System.out.println("testMIV: " + group);
    return false;
  }
}
