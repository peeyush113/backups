package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class Simplifier
{
  public static final int NOTHING = 0;
  public static final int INTEGER_ARITHMETIC = 1;
  public static final int FLOAT_ARITHMETIC = 2;

  private int options;

  public Simplifier()
  {
    options = INTEGER_ARITHMETIC | FLOAT_ARITHMETIC;
  }

  public Simplifier(int options)
  {
    this.options = options;
  }

  private Expression getCoefficient(Expression expr)
  {
    if (expr instanceof UnaryExpression)
    {
      UnaryExpression uexpr = (UnaryExpression)expr;

      if (uexpr.getOperator() == UnaryOperator.MINUS)
        return new IntegerLiteral(-1 * ((IntegerLiteral)getCoefficient(uexpr.getExpression())).getValue());
      else if (uexpr.getOperator() == UnaryOperator.PLUS)
        return getCoefficient(uexpr.getExpression());
    }
    else if (expr instanceof BinaryExpression)
    {
      BinaryExpression bexpr = (BinaryExpression)expr;

      if (bexpr.getOperator() == BinaryOperator.MULTIPLY)
        return bexpr.getLHS();
    }

    return new IntegerLiteral(1);
  }

  private Expression getVariable(Expression expr)
  {
    if (expr instanceof UnaryExpression)
    {
      UnaryExpression uexpr = (UnaryExpression)expr;

      if (uexpr.getOperator() == UnaryOperator.MINUS
          || uexpr.getOperator() == UnaryOperator.PLUS)
        return getVariable(uexpr.getExpression());
    }
    else if (expr instanceof BinaryExpression)
    {
      BinaryExpression bexpr = (BinaryExpression)expr;

      if (bexpr.getOperator() == BinaryOperator.MULTIPLY)
        return bexpr.getRHS();
    }

    return expr;
  }

  private boolean sameTermOrNegated(Expression e1, Expression e2)
  {
    String e1_str = e1.toString();
    String e2_str = e2.toString();

    if (e1 instanceof UnaryExpression
        && ((UnaryExpression)e1).getOperator() == UnaryOperator.MINUS)
      e1_str = ((UnaryExpression)e1).getExpression().toString();

    if (e2 instanceof UnaryExpression
        && ((UnaryExpression)e2).getOperator() == UnaryOperator.MINUS)
      e2_str = ((UnaryExpression)e2).getExpression().toString();

    return e1_str.compareTo(e2_str) == 0;
  }

  private Expression addition(BinaryExpression top)
  {
    Expression ret_val = null;

    /* check for 0 + x */
    try {
      IntegerLiteral lhs = (IntegerLiteral)top.getLHS();
      if (lhs.getValue() == 0)
        return (Expression)top.getRHS().clone();
    } catch (ClassCastException e) {
    }

    /* check for 1 + 2 */
    try {
      IntegerLiteral lhs = (IntegerLiteral)top.getLHS();
      IntegerLiteral rhs = (IntegerLiteral)top.getRHS();

      if ((options & INTEGER_ARITHMETIC) != 0)
        ret_val = new IntegerLiteral(lhs.getValue() + rhs.getValue());
    } catch (ClassCastException e) {
    }

    if (ret_val != null)
      return ret_val;

    /* check for 1.0 + 2.0 */
    try {
      FloatLiteral lhs = (FloatLiteral)top.getLHS();
      FloatLiteral rhs = (FloatLiteral)top.getRHS();

      if ((options & FLOAT_ARITHMETIC) != 0)
        ret_val = new FloatLiteral(lhs.getValue() + rhs.getValue());
    } catch (ClassCastException e) {
    }

    if (ret_val != null)
      return ret_val;

    /* check for x + x, x + (-x), etc. */
    Expression lhs = top.getLHS();
    Expression lhs_coeff = getCoefficient(lhs);
    Expression lhs_var = getVariable(lhs);

    Expression rhs = top.getRHS();
    Expression rhs_coeff = getCoefficient(rhs);
    Expression rhs_var = getVariable(rhs);

    if (lhs_var.toString().compareTo(rhs_var.toString()) == 0)
    {
      Expression coeff = new IntegerLiteral(((IntegerLiteral)lhs_coeff).getValue() +
                                            ((IntegerLiteral)rhs_coeff).getValue());
      ret_val = new BinaryExpression(coeff, BinaryOperator.MULTIPLY, (Expression)lhs_var.clone());
    }

    if (ret_val != null)
      return ret_val;

    return top;
  }

  private Expression multiplication(BinaryExpression top)
  {
    try {
      IntegerLiteral lhs = (IntegerLiteral)top.getLHS();

      if (lhs.getValue() == 0)
        return new IntegerLiteral(0);
      else if (lhs.getValue() == 1)
        return (Expression)top.getRHS().clone();
    } catch (ClassCastException e) {
    }

    return top;
  }

  public Expression run(Expression expr)
  {
    if (expr == null)
      return null;

    Expression copy = (Expression)expr.clone();

    UnaryExpression temp = new UnaryExpression(UnaryOperator.PLUS, copy);

    boolean changed = true;
    while (changed)
    {
      changed = simplify(temp);
    }

    return temp.getExpression();
  }

  private boolean simplify(Expression top)
  {
    String initial = top.toString();

    System.err.println("attempting to simplify: " + initial);

    PostOrderIterator iter = new PostOrderIterator(top);

    while (iter.hasNext())
    {
      Expression expr = (Expression)iter.next();

      if (expr instanceof BinaryExpression)
      {
        BinaryExpression bexpr = (BinaryExpression)expr;

        /* get rid of subtraction */
        if (bexpr.getOperator() == BinaryOperator.SUBTRACT)
        {
          bexpr.setOperator(BinaryOperator.ADD);
          bexpr.getRHS().swapWith(new UnaryExpression(UnaryOperator.MINUS, (Expression)bexpr.getRHS().clone()));
        }
        
        if (!(bexpr.getLHS() instanceof BinaryExpression)
            && bexpr.getRHS() instanceof BinaryExpression)
          bexpr.getLHS().swapWith(bexpr.getRHS());

        if (bexpr.getLHS() instanceof BinaryExpression
            && !(bexpr.getRHS() instanceof BinaryExpression))
        {
          BinaryExpression lhs = (BinaryExpression)bexpr.getLHS();

          if (sameTermOrNegated(lhs.getLHS(), bexpr.getRHS()))
            lhs.getRHS().swapWith(bexpr.getRHS());
          else if (sameTermOrNegated(lhs.getRHS(), bexpr.getRHS()))
            lhs.getLHS().swapWith(bexpr.getRHS());
        }

        if (bexpr.getOperator() == BinaryOperator.ADD)
          bexpr.swapWith(addition(bexpr));
        else if (bexpr.getOperator() == BinaryOperator.MULTIPLY)
          bexpr.swapWith(multiplication(bexpr));
      }

    }

    return (initial.compareTo(top.toString()) != 0);
  }

  public static Expression subtract(Expression e1, Expression e2)
  {
    BinaryExpression be = new BinaryExpression((Expression)e1.clone(),
      BinaryOperator.SUBTRACT, (Expression)e2.clone());
    return (new Simplifier()).run(be);
  }
}
