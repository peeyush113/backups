package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class ThrowExpression extends Expression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ThrowExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public ThrowExpression(Expression expr)
  {
    super(1);

    object_print_method = class_print_method;

    children.add(expr);
    expr.setParent(this);
  }

  public Object clone()
  {
    ThrowExpression o = (ThrowExpression)super.clone();
    return o;
  }

  /**
   * Prints a throw expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(ThrowExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("throw ");
    expr.getExpression().print(stream);
  }

  public Expression getExpression()
  {
    return (Expression)children.get(0);
  }
}
