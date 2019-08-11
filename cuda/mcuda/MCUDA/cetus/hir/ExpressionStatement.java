package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * A statement with the purpose of evaluating an
 * expression for a side effect.
 */
public class ExpressionStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ExpressionStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create an expression statement given an expression.
   *
   * @param expr The expression part of the statement.
   */
  public ExpressionStatement(Expression expr)
  {
    object_print_method = class_print_method;

    children.add(expr);
    expr.setParent(this);
    expr.setParens(false);
  }

  /**
   * Prints a statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(ExpressionStatement stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    stmt.getExpression().print(stream);
    p.print(";");
  }

  /**
   * Returns the expression part of the statement.
   *
   * @return the expression part of the statement.
   */
  public Expression getExpression()
  {
    return (Expression)children.get(0);
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
}
