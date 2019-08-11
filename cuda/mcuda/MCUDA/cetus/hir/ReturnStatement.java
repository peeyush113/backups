package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class ReturnStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ReturnStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /** Creates a "return nothing" statement.
   */
  public ReturnStatement()
  {
    object_print_method = class_print_method;
  }

  /** Creates a statement that returns an expression.
   *
   * @param expr The expression to return.
   */  
  public ReturnStatement(Expression expr)
  {
    object_print_method = class_print_method;
    children.add(expr);
    expr.setParent(this);
  }

  /**
   * Prints a break statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(ReturnStatement stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("return ");

    if (!stmt.children.isEmpty())
      ((Printable)stmt.children.get(0)).print(stream);

    p.print(";");
  }

  /**
   * Returns the expression that is being returned by this statement,
   * or null if nothing is being returned.
   *
   * @return the expression that is being returned by this statement,
   *   or null if nothing is being returned.
   */
  public Expression getExpression()
  {
    if (children.size() > 0)
      return (Expression)children.get(0);
    else
      return null;
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
