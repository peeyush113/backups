package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class BinaryExpression extends Expression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = BinaryExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  protected BinaryOperator op;

  /**
   * Creates a binary expression.
   *
   * @param lhs The lefthand expression.
   * @param op A binary operator.
   * @param rhs The righthand expression.
   */
  public BinaryExpression(Expression lhs, BinaryOperator op, Expression rhs)
  {
    super(2);

    object_print_method = class_print_method;

    children.add(lhs);
    lhs.setParent(this);

    this.op = op;

    children.add(rhs);
    rhs.setParent(this);
  }

  public Object clone()
  {
    BinaryExpression o = (BinaryExpression)super.clone();
    o.op = op;
    return o;
  }

  /**
   * Prints a binary expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(BinaryExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (expr.needs_parens)
      p.print("(");

    expr.getLHS().print(stream);
    expr.op.print(stream);
    expr.getRHS().print(stream);

    if (expr.needs_parens)
      p.print(")");
  }

  /**
   * Returns the lefthand expression.
   *
   * @return the lefthand expression.
   */
  public Expression getLHS()
  {
    return (Expression)children.get(0);
  }

  /**
   * Returns the operator of the expression.
   *
   * @return the operator.
   */
  public BinaryOperator getOperator()
  {
    return op;
  }

  /**
   * Returns the righthand expression.
   *
   * @return the righthand expression.
   */
  public Expression getRHS()
  {
    return (Expression)children.get(1);
  }

  /**
   * Overrides the class print method, so that all subsequently
   * created objects will use the supplied method.
   *
   * @param m The new print method.
   */
  static public void setClassPrintMethod(Method m)
  {
    class_print_method = m;
  }

  /**
   * Sets the lefthand expression.
   *
   * @param expr The new lefthand expression.  It must not be
   *   the child of another expression.
   */
  public void setLHS(Expression expr)
  {
    if (expr == null)
      throw new IllegalArgumentException();

    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    getLHS().parent = null;
    children.set(0, expr); 
  }

  /**
   * Sets the operator for the expression.
   *
   * @param op The operator.
   */
  public void setOperator(BinaryOperator op)
  {
    this.op = op;
  }

  /**
   * Sets the righthand expression.
   *
   * @param expr The new righthand expression.  It must not be
   *   the child of another expression.
   */
  public void setRHS(Expression expr)
  {
    if (expr == null)
      throw new IllegalArgumentException();

    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    getRHS().parent = null;
    children.set(1, expr);
  }
}
