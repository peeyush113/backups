package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a case for use with switch.
 */
public class Case extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Case.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create a new case.
   *
   * @param expr The expression that activates the case.
   */
  public Case(Expression expr)
  {
    object_print_method = class_print_method;
 
    children.add(expr);
    expr.setParent(this);
  }

  /**
   * Prints a case label to a stream.
   *
   * @param label The case label to print.
   * @param stream The stream on which to print the case label.
   */
  public static void defaultPrint(Case label, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("case ");
    label.getExpression().print(stream);
    p.print(":");
  }

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
