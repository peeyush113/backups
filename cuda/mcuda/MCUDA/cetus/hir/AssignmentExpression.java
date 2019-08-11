package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class AssignmentExpression extends BinaryExpression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = AssignmentExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Creates an assignment expression.
   *
   * @param lhs The lefthand expression.
   * @param op An assignment operator.
   * @param rhs The righthand expression.
   */
  public AssignmentExpression(Expression lhs, AssignmentOperator op, Expression rhs)
  {
    super(lhs, op, rhs);
  }

  public Object clone()
  {
    return (AssignmentExpression)super.clone();
  }

  /**
   * Prints an assignment expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(AssignmentExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("(");
    ((Printable)expr.children.get(0)).print(stream);
    expr.op.print(stream);
    ((Printable)expr.children.get(1)).print(stream);
    p.print(")");
  }

  /**
   * Returns the operator of the expression.
   *
   * @return the operator.
   */
  public AssignmentOperator getOperator()
  {
    return (AssignmentOperator)op;
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
   * Sets the operator for the expression.
   *
   * @param op The operator.
   */
  public void setOperator(AssignmentOperator op)
  {
    this.op = op;
  }
}
