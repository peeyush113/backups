package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents the access of an array or pointer variable: array[x][y]...
 */
public class ArrayAccess extends Expression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ArrayAccess.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Creates an array access with a single index expression.
   *
   * @param array An expression evaluating to an address.
   * @param index The expression with which to index the array.
   */
  public ArrayAccess(Expression array, Expression index)
  {
    super(2);

    object_print_method = class_print_method;

    children.add(array);
    array.setParent(this);

    children.add(index);
    index.setParent(this);
  }

  /**
   * Creates an array access with multiple index expressions.
   *
   * @param array An expression evaluating to an address.
   * @param indices A list of expressions with which to index the array.
   */
  public ArrayAccess(Expression array, List indices)
  {
    super(indices.size() + 1);

    object_print_method = class_print_method;

    children.add(array);
    array.setParent(this);

    setIndices(indices);
  }

  public void addIndex(Expression expr)
  {
    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    children.add(expr);
    expr.setParent(this);
  }

  public Object clone()
  {
    ArrayAccess o = (ArrayAccess)super.clone();
    return o;
  }

  /**
   * Prints an array access expression to a stream.
   *
   * @param expr The array access to print.
   * @param stream The stream on which to print the array access.
   */
  public static void defaultPrint(ArrayAccess expr, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    Iterator iter = expr.children.iterator();

    ((Printable)iter.next()).print(stream);

    while (iter.hasNext())
    {
      p.print("[");

      Object o = iter.next();
      ((Printable)o).print(stream);

      p.print("]");
    }
  }

  /**
   * Returns the expression being indexed.
   * Most often, the expression will be an Identifier,
   * but any expression that evaluates to an address is allowed.
   *
   * @return the expression being indexed.
   */
  public Expression getArrayName()
  {
    return (Expression)children.get(0);
  }

  /**
   * Gets the nth index expression of this array access.
   *
   * @param n The position of the index expression.
   * @throws IndexOutOfBoundsException if there is no expression at that position.
   * @return the nth index expression.
   */
  public Expression getIndex(int n)
  {
    return (Expression)children.get(n+1);
  }

  /**
   * Returns the number of index expressions used in this array access.
   *
   * @return the number of index expressions.
   */
  public int getNumIndices()
  {
    return children.size() - 1;
  }

  /**
   * Sets the nth index expression of this array access.
   *
   * @param n The position of the index expression.
   * @param expr The expression to use for the index.
   * @throws IndexOutOfBoundsException if there is no expression at that position.
   */
  public void setIndex(int n, Expression expr)
  {
    if (expr.getParent() != null)
      throw new NotAnOrphanException();

    children.set(n + 1, expr);
    expr.setParent(this);
  }

  /**
   * Set the list of index expressions.
   *
   * @param indices A list of expressions.
   */
  public void setIndices(List indices)
  {
    /* clear out everything but the first item */
    Expression name = (Expression)children.get(0);
    children.clear();
    children.add(name);

    Iterator iter = indices.iterator();
    while (iter.hasNext())
    {
      Expression expr = null;
      try {
        expr = (Expression)iter.next();
      } catch (ClassCastException e) {
        throw new IllegalArgumentException();
      }

      children.add(expr);
      expr.setParent(this);
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
