package cetus.transforms;

import java.util.*;

import cetus.exec.*;
import cetus.hir.*;
import cetus.analysis.DataFlow;
import cetus.analysis.InductionVariable;

/**
 * This pass performs induction variable substitution
 * to attempt to remove all auxiliary induction
 * variables from each loop.
 */
public class Induction extends LoopTransformPass
{
  public Induction(Program program)
  {
    super(program);
  }

  public String getPassName()
  {
    return new String("[Induction]");
  }

  private Set<Expression> findAuxilliaryInductionVariables(Loop loop, InductionVariable primary_iv)
  {
    /* the set of auxiliary induction variables that will be returned */
    Set<Expression> ivs = new TreeSet<Expression>();

    /* variables that were rejected as IVs */
    Set<Expression> rejected_ivs = new TreeSet<Expression>();

    /* find the def set for the loop body so that later we'll be able to
       determine if an expression is constant within the loop */
    TreeSet<Expression> def_set = DataFlow.mayDefine(loop.getBody());

    /* the loop index itself is defined at the end of each iteration */
    def_set.add(primary_iv.variable);

    /* populate the set of auxiliary induction variables */
    DepthFirstIterator iter = new DepthFirstIterator(loop.getBody());

    for (;;)
    {
      Expression expr = null;

      try {
        expr = (Expression)iter.next(Expression.class);
      } catch (NoSuchElementException e) {
        break;
      }

      if (expr instanceof AssignmentExpression)
      {
        AssignmentExpression assign = (AssignmentExpression)expr;
        Expression lhs = assign.getLHS();

        /* the variable has already been rejected as an induction
           variable so ignore it */
        if (rejected_ivs.contains(lhs))
          continue;

        if (ivs.contains(lhs))
        {
          /* the variable has already been classified as an
             induction variable, but now it's being defined again,
             so we no longer should consider it an induction
             variable */

          ivs.remove(lhs);
          rejected_ivs.add(lhs);
        }
        else
        {
          AssignmentOperator op = assign.getOperator();

          if (op == AssignmentOperator.NORMAL)
          {
            Expression rhs = assign.getRHS();

            /* remove the lhs from the rhs expression,
               test if the resulting expression is loop invariant,
               if so, add it to ivs */ 
            if (isInvariant(Simplifier.subtract(rhs, lhs), def_set))
              ivs.add(lhs);
          }
          else if ((op == AssignmentOperator.ADD
                    || op == AssignmentOperator.SUBTRACT)
                   && isInvariant(assign.getRHS(), def_set))
          {
            /* covers: iv += invariant_expr;
                       iv -= invariant_expr; */
            ivs.add(lhs);
          }
        }
      }
      else if (expr instanceof UnaryExpression)
      {
        UnaryExpression uexpr = (UnaryExpression)expr;
        Expression nested_expr = uexpr.getExpression();

        if (UnaryOperator.hasSideEffects(uexpr.getOperator())
            && !rejected_ivs.contains(nested_expr))
        {
          if (ivs.contains(nested_expr))
          {
            ivs.remove(nested_expr);
            rejected_ivs.add(nested_expr);
          }
          else
            ivs.add(nested_expr);
        }
      }
    }

    return ivs;
  }

  /**
   * Determines if any definitions in def_set modify values used
   * in expr.
   */
  private boolean isInvariant(Expression expr, Set<Expression> def_set)
  {
    Set<Expression> use_set = DataFlow.getUseSet(expr);

    for (Expression e : def_set)
    {
      /* if the use set of expr contains anything defined in
         the def_set, then expr is not invariant */
      if (use_set.contains(e))
        return false;
    }

    /* nothing in expr was defined in def_set, so expr is invariant */
    return true;
  }

  /*
  Examples of induction variables with loop index i starting at 0

                               closed form
    iv = iv + 1;  iv++;        iv_0 + i
    iv = iv + 2;  iv += 2;     iv_0 + 2*i
    iv = iv + x;  iv += x;     iv_0 + x*i;
    iv = iv + i;               iv_0 + (i*i + i) / 2

  */
  public void transformLoop(Loop loop)
  {
    if (!(loop instanceof ForLoop))
      return;

    /* identify the loop index variable */
    InductionVariable primary_iv = ((ForLoop)loop).identifyPrimaryInductionVariable();

    /* variables that look like auxiliary IVs */
    Set<Expression> ivs = findAuxilliaryInductionVariables(loop, primary_iv);
    System.out.println("auxiliary ivs are: " + ivs.toString());

    /* iterate over the ivs and insert declarations to save their initial values

       e.g., if x is an iv, insert x_0 = x
    */
   
    for (Expression e : ivs)
    {
      if (((SymbolTable)((Traversable)loop).getParent()).findSymbol(new Identifier(e.toString() + "_0")) == null)
      {
        VariableDeclarator dtor = new VariableDeclarator(new Identifier(e.toString() + "_0"));
        VariableDeclaration decl = new VariableDeclaration(Specifier.INT, dtor);

        ((CompoundStatement)((Traversable)loop).getParent()).addDeclaration(decl);
      }
    }

    for (Expression e : ivs)
    {
      AssignmentExpression assign = new AssignmentExpression(new Identifier(e.toString() + "_0"),
        AssignmentOperator.NORMAL, (Expression)e.clone());

      ((CompoundStatement)((Traversable)loop).getParent()).addStatementBefore((Statement)loop, new ExpressionStatement(assign));
    }

    /* make a second pass to find where the auxiliary ivs are defined
       and make substitutions on the rhs */

    DepthFirstIterator iter = new DepthFirstIterator(loop.getBody());

    for (;;)
    {
      Expression expr = null;

      try {
        expr = (Expression)iter.next(Expression.class);
      } catch (NoSuchElementException e) {
        break;
      }

      if (expr instanceof AssignmentExpression)
      {
        AssignmentExpression assign = (AssignmentExpression)expr;

        if (!ivs.contains(assign.getLHS()))
          continue;

        if (assign.getOperator() == AssignmentOperator.NORMAL)
        {
          /* iv = iv +/- invariant_expr */

          BinaryExpression be = new BinaryExpression((Expression)((BinaryExpression)assign.getRHS()).getRHS().clone(),
                                      BinaryOperator.MULTIPLY, (Expression)primary_iv.variable.clone());

          BinaryExpression be2 = new BinaryExpression(be, BinaryOperator.ADD, new Identifier(assign.getLHS().toString() + "_0"));

          assign.getRHS().swapWith(be2);
        }
        else if (assign.getOperator() == AssignmentOperator.ADD)
        {
          /* iv += invariant_expr */

          BinaryExpression be = new BinaryExpression((Expression)assign.getRHS().clone(),
                                      BinaryOperator.MULTIPLY, (Expression)primary_iv.variable.clone());

          BinaryExpression be2 = new BinaryExpression(be, BinaryOperator.ADD, new Identifier(assign.getLHS().toString() + "_0"));

          assign.getRHS().swapWith(be2);

          assign.setOperator(AssignmentOperator.NORMAL);
        }
        else if (assign.getOperator() == AssignmentOperator.SUBTRACT)
        {
          /* iv -= invariant_expr */

          BinaryExpression be = new BinaryExpression((Expression)assign.getRHS().clone(),
                                      BinaryOperator.MULTIPLY, (Expression)primary_iv.variable.clone());

          BinaryExpression be2 = new BinaryExpression(be, BinaryOperator.ADD, new Identifier(assign.getLHS().toString() + "_0"));

          assign.getRHS().swapWith(be2);

          assign.setOperator(AssignmentOperator.NORMAL);
        }
      }
      else if (expr instanceof UnaryExpression)
      {
        UnaryExpression uexpr = (UnaryExpression)expr;
        Expression nested_expr = uexpr.getExpression();

        if (!ivs.contains(nested_expr))
          continue;
        
        UnaryOperator op = uexpr.getOperator();

        if (op == UnaryOperator.POST_INCREMENT
            || op == UnaryOperator.PRE_INCREMENT)
        {
          /* iv++ or ++iv */

          /* TODO: need to make sure that any outer expression picks up the
             correct value from the substitution since iv++ and ++iv evaluate
             at different times */

          AssignmentExpression assign = new AssignmentExpression((Expression)nested_expr.clone(),
                                              AssignmentOperator.NORMAL, ((Expression)primary_iv.variable.clone()));

          expr.swapWith(assign);
        }
        else 
        {
          /* iv-- or --iv */

          AssignmentExpression assign = new AssignmentExpression((Expression)nested_expr.clone(),
                                              AssignmentOperator.NORMAL, ((Expression)primary_iv.variable.clone()));

          expr.swapWith(assign);
        }
      }
    }
  }
}
