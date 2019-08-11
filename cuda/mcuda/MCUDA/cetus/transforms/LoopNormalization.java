package cetus.transforms;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;

import cetus.analysis.InductionVariable;

import java.util.*;

/**
 * Transforms loops so they start with a lower bound of 0
 * and run to some upper bound with a stride of 1.
 */
public class LoopNormalization extends LoopTransformPass
{
  public LoopNormalization(Program program)
  {
    super(program);
  }

  public String getPassName()
  {
    return new String("[LoopNormalization]");
  }

  public void transformLoop(Loop loop)
  {
    if (!(loop instanceof ForLoop))
      return;

    ForLoop for_loop = (ForLoop)loop;

    /* identify the loop index variable */
    InductionVariable primary_iv = for_loop.identifyPrimaryInductionVariable();

    /* we don't need to do anything if the lower bound is already 0
       and the step is 1 */
    if (primary_iv.lower_bound == 0
        && primary_iv.step == 1)
      return;

    /* form the expression to replace all occurrences of the index i with:
         i * step + lower_bound
    */

    Expression replacement_value
      = new BinaryExpression(new BinaryExpression((Expression)primary_iv.variable.clone(),
                                                  BinaryOperator.MULTIPLY,
                                                  new IntegerLiteral(primary_iv.step)),
                             BinaryOperator.ADD,
                             new IntegerLiteral(primary_iv.lower_bound));

    /* replace all instances of the loop index with a copy of the new expression */
    Tools.replaceAll(for_loop.getBody(), primary_iv.variable, replacement_value);

    /* change the loop header to be i = 0; i < N; i++ */

    Statement init = for_loop.getInitialStatement();
    if (init instanceof ExpressionStatement)
    {
      Expression expr = ((ExpressionStatement)init).getExpression();
      if (expr instanceof AssignmentExpression)
      {
        ((AssignmentExpression)expr).setRHS(new IntegerLiteral(0));
      }
    }

    for_loop.setCondition(new BinaryExpression((Expression)primary_iv.variable.clone(),
                                               BinaryOperator.COMPARE_LT,
                                               new IntegerLiteral(primary_iv.countSteps())));

    for_loop.setStep(new UnaryExpression(UnaryOperator.PRE_INCREMENT, (Expression)primary_iv.variable.clone()));

    /* insert an assignment after the loop to correct i's value */

    Statement correction = new ExpressionStatement(new BinaryExpression((Expression)primary_iv.variable.clone(),
                                                                        AssignmentOperator.NORMAL,
                                                                        replacement_value));

    ((CompoundStatement)for_loop.getParent()).addStatementAfter(for_loop, correction);
  }
}
