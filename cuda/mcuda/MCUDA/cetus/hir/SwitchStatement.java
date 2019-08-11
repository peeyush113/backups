package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class SwitchStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = SwitchStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create a new switch statement.
   */
  public SwitchStatement(Expression value)
  {
    object_print_method = class_print_method;

    children.add(value);
    value.setParent(this);

    CompoundStatement stmt = new CompoundStatement();
    children.add(stmt);
    stmt.setParent(this);
  }

  public SwitchStatement(Expression value, CompoundStatement stmt)
  {
    object_print_method = class_print_method;

    children.add(value);
    value.setParent(this);

    children.add(stmt);
    stmt.setParent(this);
  }

  /**
   * Prints a switch statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(SwitchStatement stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("switch (");
    stmt.getExpression().print(stream);
    p.print(")\n");
    stmt.getBody().print(stream);
  }

  public CompoundStatement getBody()
  {
    return (CompoundStatement)children.get(1);
  }

  public Expression getExpression()
  {
    return (Expression)children.get(0);
  }

  public void setBody(CompoundStatement stmt)
  {
    getBody().setParent(null);
    children.set(1, stmt);
    stmt.setParent(this);
  }

  public void setExpression(Expression value)
  {
    getExpression().setParent(null);
    children.set(0, value);
    value.setParent(this);
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
