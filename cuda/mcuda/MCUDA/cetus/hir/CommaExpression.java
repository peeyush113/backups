package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Represents expressions separated by the comma
 * operator in C or C++.  The entire expression evaluates
 * to the last expression in the list.
 */
public class CommaExpression extends Expression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = CommaExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public CommaExpression(List expr_list)
  {
    object_print_method = class_print_method;

    if (expr_list == null
        || expr_list.size() < 2)
      throw new IllegalArgumentException();

    Iterator iter = expr_list.iterator();
    while (iter.hasNext())
    {
      Expression expr = (Expression)iter.next();
      addExpression(expr);
    }
  }

  public void addExpression(Expression expr)
  {
    if (expr.getParent() != null)
      throw new IllegalArgumentException();

    children.add(expr);
    expr.setParent(this);
  }

  public Object clone()
  {
    CommaExpression o = (CommaExpression)super.clone();
    return o; 
  }

  /**
   * Prints a CommaExpression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(CommaExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("(");
    Tools.printListWithCommas(expr.children, stream);
    p.print(")");
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
