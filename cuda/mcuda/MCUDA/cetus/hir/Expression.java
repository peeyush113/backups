package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Base class for all expressions.
 */
public abstract class Expression implements Cloneable, Comparable<Expression>, Printable, Traversable
{
  protected Method object_print_method;

  protected Traversable parent;

  /** All children must be Expressions. */
  protected ArrayList children;

  /** Determines whether this expression should have a set of parentheses
   * around it when printed.
   */
  protected boolean needs_parens;

  /** Constructor for derived classes; uses an initial size of one
   * for the list of children.
   */
  protected Expression()
  {
    parent = null;
    children = new ArrayList(1);
    needs_parens = true;
  }

  /** Constructor for derived classes; sets an initial size for the
   * list of children of this expression.
   *
   * @param size The initial size for the child list.
   */
  protected Expression(int size)
  {
    parent = null;
    children = new ArrayList(size);
    needs_parens = true;
  }

  /**
   * Creates and returns a deep copy of this expression. 
   *
   * @return a deep copy of this expression.
   */
  public Object clone()
  {
    Expression o = null;

    try {
      o = (Expression)super.clone();
    } catch (CloneNotSupportedException e) {
      throw new InternalError();
    }

    o.object_print_method = object_print_method;
    o.parent = null;

    if (children != null)
    {
      o.children = new ArrayList(children.size());
      Iterator iter = children.iterator();
      while (iter.hasNext())
      {
        Expression new_child = (Expression)((Expression)iter.next()).clone();
        new_child.setParent(o);
        o.children.add(new_child);
      }
    }
    else
      o.children = null;

    o.needs_parens = needs_parens;

    return o;
  }

  public int compareTo(Expression e)
  {
    if (equals(e))
      return 0;
    else
      return toString().compareTo(e.toString());
  }

  public boolean equals(Object o)
  {
    if (!(o instanceof Expression))
      return false;

    Expression expr = (Expression)o;

    /* The following two if statements are here because we
       set children to null for literals, which cannot
       have children.  Derived classes of Expression will
       provide their own equals method, but this is the
       best we can do here because there is nothing
       to compare if there are no children. */
    if (children == null && expr.children == null)
      return true;

    /* Both are not null at this point, so if one is and
       the other isn't, they cannot be equal. */
    if (children == null || expr.children == null)
      return false;

    Iterator iterA = children.iterator();
    Iterator iterB = expr.children.iterator();

    /* compare children in pairs */
    while (iterA.hasNext() && iterB.hasNext())
    {
      if (!iterA.next().equals(iterB.next()))
        return false;
    }

    /* leftovers mean they are not equal */
    if (iterA.hasNext() || iterB.hasNext())
      return false;
    else
      return true;
  }

  /**
   * Returns a list of subexpressions of this expression that match <var>expr</var>
   * using its equals method.
   *
   * @param expr The subexpression sought.
   * @return a list of matching subexpressions, which may be empty.
   */
  public List findExpression(Expression expr)
  {
    List result = new LinkedList();

    if (expr != null)
    {
      BreadthFirstIterator iter = new BreadthFirstIterator(this);
      while (iter.hasNext())
      {
        Object obj = iter.next();
 
        if (expr.equals(obj))
          result.add(obj);
      }
    }

    return result;
  }

  public List getChildren()
  {
    /* Literals have a null child list (space optimization -- programs have
       a large number of literals so not keeping a child list for each
       literal can save a lot of memory) but returning an empty list
       is often more polite to the caller. */

    if (children != null)
      return children;
    else
      return new LinkedList();
  }

  public Traversable getParent()
  {
    return parent;
  }

  /**
   * Get the Statement containing this Expression.
   *
   * @return the enclosing Statement or null if this Expression
   *   is not inside a Statement.
   */
  public Statement getStatement()
  {
    Traversable t = this;

    do {
      t = t.getParent();
    } while (t != null && !(t instanceof Statement));

    return (Statement)t;
  }

  public void print(OutputStream stream)
  {
    if (object_print_method == null)
      return;

    Object[] args = new Object[2];
    args[0] = this;
    args[1] = stream;

    try {
      object_print_method.invoke(null, args);
    } catch (IllegalAccessException e) {
      System.err.println(e);
      e.printStackTrace();
      System.exit(1);
    } catch (InvocationTargetException e) {
      System.err.println(e.getCause());
      e.printStackTrace();
      System.exit(1);
    }
  }

  public void printSelf(){
  	/*
	System.out.print("Source form: ");
	print(System.out);
	System.out.println("");
	*/
	if(this instanceof BinaryExpression)
		System.out.print(((BinaryExpression)this).getOperator());
	else
		System.out.print(getClass().getName().substring(10));
	if(this.parent instanceof Expression)	
		System.out.print(" "+"@"+hashCode());
  	Iterator iter = children.iterator();
	Expression e= null;
	while(iter.hasNext()){
		e = (Expression)iter.next();
		if(e.getChildren().size() != 0)
			System.out.print(" "+"@"+e.hashCode());
		else{
			System.out.print(" ");
			e.print(System.out);
		}
	}
  }

  public void removeChild(Traversable child)
  {
    throw new UnsupportedOperationException("Expressions do not support removal of arbitrary children.");
  }

  public void setChild(int index, Traversable t)
  {
    if (t.getParent() != null)
      throw new NotAnOrphanException();

    if (t instanceof Expression)
    {
      children.set(index, t);
      t.setParent(this);
    }
    else
      throw new IllegalArgumentException();
  }

  /**
   * Sets whether the expression needs to have
   * an outer set of parentheses printed around it.
   *
   * @param f True to use parens, false to not use parens.
   */
  public void setParens(boolean f)
  {
    needs_parens = f;
  }

  public void setParent(Traversable t)
  {
    /* expressions can appear in many places so it's probably not
       worth it to try and provide instanceof checks against t here */
    parent = t;
  }

  /**
   * Overrides the print method for this object only.
   *
   * @param m The new print method.
   */
  public void setPrintMethod(Method m)
  {
    object_print_method = m;
  }

  /**
   * Swaps two expression on the IR tree.  If neither
   * this expression nor <var>expr</var> has a parent,
   * then this function has no effect.  Otherwise,
   * each expression ends up with the other's parent and
   * exchange positions in the parents' lists of children.
   * 
   * @param expr The expression with which to swap this expression.
   * @throws IllegalArgumentException if <var>expr</var> is null.
   * @throws IllegalStateException if the types of the expressions
   *   are such that they would create inconsistent IR when swapped.
   */
  public void swapWith(Expression expr)
  {
    if (expr == null)
      throw new IllegalArgumentException();

    if (this == expr)
      /* swap with self does nothing */
      return;

    /* The rest of this must be done in a very particular order.
       Be EXTREMELY careful changing it. */

    Traversable this_parent = this.parent;
    Traversable expr_parent = expr.parent;

    int this_index = -1, expr_index = -1;

    if (this_parent != null)
    {
      this_index = Tools.indexByReference(this_parent.getChildren(), this);
      if (this_index == -1)
        throw new IllegalStateException();
    }

    if (expr_parent != null)
    {
      expr_index = Tools.indexByReference(expr_parent.getChildren(), expr);
      if (expr_index == -1)
        throw new IllegalStateException();
    }

    /* detach both so setChild won't complain */
    expr.parent = null; this.parent = null;

    if (this_parent != null)
      this_parent.setChild(this_index, expr);

    if (expr_parent != null)
      expr_parent.setChild(expr_index, this);
  }

  public String toString()
  {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    print(new PrintStream(baos));
    return baos.toString();
  }

  /**
   * Verifies three properties of this object:
   * (1) All children are not null, (2) the parent object has this
   * object as a child, (3) all children have this object as the parent.
   *
   * @throws IllegalStateException if any of the properties are not true.
   */
  public void verify() throws IllegalStateException
  {
    if (parent != null && !parent.getChildren().contains(this))
      throw new IllegalStateException("parent does not think this is a child");

    if (children != null)
    {
      if (children.contains(null))
        throw new IllegalStateException("a child is null");

      Iterator iter = children.iterator();
      while (iter.hasNext())
      {
        if (((Traversable)iter.next()).getParent() != this)
          throw new IllegalStateException("a child does not think this is the parent");
      }
    }
  }
}
