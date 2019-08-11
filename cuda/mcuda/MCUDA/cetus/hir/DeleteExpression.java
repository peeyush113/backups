package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class DeleteExpression extends Expression
{
  private	static Method class_print_method;

	/**
	* if global == true, it prints "::" ahead of delelte expression
	*/
  protected static boolean global;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = DeleteExpression.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private boolean array = false;

  public DeleteExpression(Expression expr)
  {
    super(1);

    this.array = false;
    children.add(expr);
    expr.setParent(this);

    global = false;
  }

  public DeleteExpression(boolean array, Expression expr)
  {
    super(1);

    this.array = array;
    children.add(expr);
    expr.setParent(this);

	global = false;
  }

	/**
	* force printing "::"
	*/
	public void setGlobal()
	{
		global = true;
	}

	/**
	* disable printing "::"
	*/
	public void clearGlobal()
	{
		global = false;
	}

	/**
	* returns true if it is set to be global.
	*/
	public boolean isGlobal()
	{
		return global;
	}

  public Object clone()
  {
    DeleteExpression o = (DeleteExpression)super.clone();
    o.array = array;

	o.global = this.global;
    return o;
  }

  /**
   * Prints a delete expression to a stream.
   *
   * @param expr The expression to print.
   * @param stream The stream on which to print the expression.
   */
  public static void defaultPrint(DeleteExpression expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (global == true)
    {
      p.print("::");
    }

    p.print("delete ");

    if (expr.array)
      p.print("[] ");

    expr.getExpression().print(stream);
  }

  public Expression getExpression()
  {
    return (Expression)children.get(0);
  }
}
