package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class UnaryExpression extends Expression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = UnaryExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  protected UnaryOperator op;

  public UnaryExpression(UnaryOperator op, Expression expr)
  {
    object_print_method = class_print_method;

    this.op = op;

    expr.setParent(this);
    children.add(expr);
  }

  public Object clone()
  {
    UnaryExpression o = (UnaryExpression)super.clone();
    o.op = op;
    return o;
  }

  /**
   * Prints a unary expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(UnaryExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (expr.needs_parens)
      p.print("(");

    if (expr.op == UnaryOperator.POST_DECREMENT
        || expr.op == UnaryOperator.POST_INCREMENT)
    {
      expr.getExpression().print(stream);
      p.print(" ");
      expr.op.print(stream);
      p.print(" ");
    }
    else
    {
      p.print(" ");
      expr.op.print(stream);
      p.print(" ");
      expr.getExpression().print(stream);
    }

    if (expr.needs_parens)
      p.print(")");
  }

  public boolean equals(Object o)
  {
    UnaryExpression expr = null;

    try {
      expr = (UnaryExpression)o;
    } catch (ClassCastException e) {
      return false;
    }

    return (op == expr.op
            && getExpression().equals(expr.getExpression()));
  }

  /**
   * Returns the expression.
   *
   * @return the expression.
   */
  public Expression getExpression()
  {
    return (Expression)children.get(0);
  }

  /**
   * Returns the operator of the expression.
   *
   * @return the operator.
   */
  public UnaryOperator getOperator()
  {
    return op;
  }

  public int hashCode()
  {
    return op.hashCode() + getExpression().hashCode();
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

  public void setExpression(Expression expr)
  {
    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    getExpression().setParent(null);
    expr.setParent(this);
    children.set(0, expr);
  }
}
