package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class IfStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = IfStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create an <var>if</var> statement that has no <var>else</var> clause.
   *
   * @param condition The condition tested by the statement.
   * @param true_clause The code to execute if the condition is true.
   */
  public IfStatement(Expression condition, Statement true_clause)
  {
    object_print_method = class_print_method;

    if (condition == null || true_clause == null)
      throw new IllegalArgumentException();

    children.add(condition);
    condition.setParent(this);

    if (!(true_clause instanceof CompoundStatement))
    {
      CompoundStatement cs = new CompoundStatement();
      cs.addStatement(true_clause);
      true_clause = cs;
    }

    children.add(true_clause);
    true_clause.setParent(this);
  }

  /**
   * Create an <var>if</var> statement that has an <var>else</var> clause.
   *
   * @param condition The condition tested by the statement.
   * @param true_clause The code to execute if the condition is true.
   * @param false_clause The code to execute if the condition is false.
   */
  public IfStatement(Expression condition, Statement true_clause, Statement false_clause)
  {
    object_print_method = class_print_method;

    if (condition == null || true_clause == null || false_clause == null)
      throw new IllegalArgumentException();

    children.add(condition);
    condition.setParent(this);

    if (!(true_clause instanceof CompoundStatement))
    {
      CompoundStatement cs = new CompoundStatement();
      cs.addStatement(true_clause);
      true_clause = cs;
    }

    children.add(true_clause);
    true_clause.setParent(this);

    if (!(false_clause instanceof CompoundStatement))
    {
      CompoundStatement cs = new CompoundStatement();
      cs.addStatement(false_clause);
      false_clause = cs;
    }

    children.add(false_clause);
    false_clause.setParent(this);
  }

  /**
   * Prints a break statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(IfStatement stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("if (");
    stmt.getControlExpression().print(stream);
    p.print(")\n");

    stmt.getThenStatement().print(stream);

    Statement s = stmt.getElseStatement();
    if (s != null)
    {
      p.print("else\n");
      s.print(stream);
    }
  }

  public Expression getControlExpression()
  {
    return (Expression)children.get(0);
  }
  
  public void setControlExpression(Expression cond)
  {
    getControlExpression().setParent(null);
    children.set(0, cond);
    cond.setParent(this);
  }

  public Statement getThenStatement()
  {
    return (Statement)children.get(1);
  }

  public void setThenStatement(Statement stmt)
  {
    getThenStatement().setParent(null);
    children.set(1, stmt);
    stmt.setParent(this);
  }

  public Statement getElseStatement()
  {
    if (children.size() > 2)
      return (Statement)children.get(2);
    else
      return null;
  }

  public void setElseStatement(Statement stmt)
  {
    Statement s = getElseStatement();

    if (s != null)
    {
      s.setParent(null);
      children.set(2, stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(stmt);
      stmt.setParent(this);
    }
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
