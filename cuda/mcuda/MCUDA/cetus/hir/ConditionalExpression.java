package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents the only ternary expression in C and C++,
 * the &#63;: operator.
 */
public class ConditionalExpression extends Expression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ConditionalExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public ConditionalExpression(Expression condition, Expression true_expr, Expression false_expr)
  {
    super(3);

    object_print_method = class_print_method;

    children.add(condition);
    condition.setParent(this);
    children.add(true_expr);
    true_expr.setParent(this);
    children.add(false_expr);
    false_expr.setParent(this);
  }

  /**
   * Prints a conditional expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(ConditionalExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("(");
    expr.getCondition().print(stream);
    p.print(" ? ");
    expr.getTrueExpression().print(stream);
    p.print(" : ");
    expr.getFalseExpression().print(stream);
    p.print(")");
  }

  public Expression getCondition()
  {
    return (Expression)children.get(0);
  }

  public Expression getFalseExpression()
  {
    return (Expression)children.get(2);
  }

  public Expression getTrueExpression()
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

  public void setCondition(Expression expr)
  {
    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    getCondition().setParent(null);
    children.set(0, expr);
    expr.setParent(this);
  }

  public void setFalseExpression(Expression expr)
  {
    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    getFalseExpression().setParent(null);
    children.set(2, expr);
    expr.setParent(this);
  }

  public void setTrueExpression(Expression expr)
  {
    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    getTrueExpression().setParent(null);
    children.set(1, expr);
    expr.setParent(this);
  }
}
