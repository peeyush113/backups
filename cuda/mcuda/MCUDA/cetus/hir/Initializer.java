package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class Initializer implements Cloneable, Printable, Traversable 
{
  /* two types of initializers - value initializers (single
     values and array of values) and constructors

     = Expression
     = { List of Expressions }

     What about...?
     my_class y(1, 2);
  */

  private static Method class_print_method;
  private Method object_print_method;

  protected Traversable parent;
  protected ArrayList children;
  private boolean is_list;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Initializer.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  protected Initializer()
  {
    children = new ArrayList(1);
  }

  public Initializer(Expression value)
  {
    object_print_method = class_print_method;

    children = new ArrayList(1);
    children.add(value);
    value.setParent(this);
    is_list = false;
  }

  public Initializer(List values)
  {
    object_print_method = class_print_method;

    children = new ArrayList(values.size());
    Iterator iter = values.iterator();
    while (iter.hasNext())
    {
      Traversable t = (Traversable)iter.next();

      /* children must be expressions, or initializers of the list form */

      if (t instanceof Expression
          || t instanceof Initializer)
      {
        children.add(t);
        t.setParent(this);
      }
      else
      {
        System.out.println("Class = " + t.getClass().getName());
        if (((Initializer)t).children == null)
        {
          System.out.println("Null children !");
        }
        throw new IllegalArgumentException();
      }
    }

    is_list = true;
  }

  public Object clone()
  {
    Initializer o = null;

    try {
      o = (Initializer)super.clone();
    } catch (CloneNotSupportedException e) {
      throw new InternalError();
    }

    o.object_print_method = object_print_method;
    o.parent = null;

    o.children = new ArrayList(children.size());
    Iterator iter = children.iterator();
    while (iter.hasNext())
    {
      Object c = iter.next();

      if (c instanceof Expression)
      {
        Expression expr = (Expression)((Expression)c).clone();
        o.children.add(expr);
        expr.setParent(o);
      }
      else
      {
        Initializer init = (Initializer)((Initializer)c).clone();
        o.children.add(init);
        init.setParent(o);
      }
    }

    return o;
  }

  /**
   * Prints an initializer to a stream.
   *
   * @param init The initializer to print.
   * @param stream The stream on which to print the initializer.
   */
  public static void defaultPrint(Initializer init, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (!(init.parent != null && init.parent instanceof Initializer))
      p.print(" = ");

    if (init.is_list)
    {
      p.print(" { ");
      Tools.printListWithCommas(init.children, stream);
      p.print(" } ");
    }
    else
    {
      Tools.printList(init.children, stream);
    }
  }

  public List getChildren()
  {
    return children;
  }

  public Traversable getParent()
  {
    return parent;
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
      throw new InternalError();
    } catch (InvocationTargetException e) {
      throw new InternalError();
    }
  }

  public void removeChild(Traversable child)
  {
    throw new UnsupportedOperationException("Initializers do not support removal of arbitrary children.");
  }

  public void setChild(int index, Traversable t)
  {
    children.set(index, t);
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

  public void setParent(Traversable t)
  {
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
}
