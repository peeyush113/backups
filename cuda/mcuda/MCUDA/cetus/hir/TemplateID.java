package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class TemplateID extends IDExpression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = TemplateID.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private String name;

  public TemplateID(String name)
  {
    super(false);

    object_print_method = class_print_method;
    this.name = name;
  }

  public TemplateID(String name, List args)
  {
    super(false);

    object_print_method = class_print_method;
    this.name = name;
    for (Object o : args)
    {
      children.add(o);
      ((Traversable)o).setParent(this);
    }
  }

  public Object clone()
  {
    TemplateID o = (TemplateID)super.clone();
    o.name = name;
    return o;
  }

  /**
   * Prints an identifier to a stream.
   *
   * @param ident The identifier to print.
   * @param stream The stream on which to print the identifier.
   */
  public static void defaultPrint(TemplateID ident, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (ident.global)
      p.print("::");

    p.print(ident.name);
    p.print("<");
    /* print template arguments */
    p.print(">");
  }

  public boolean equals(Object o)
  {
    TemplateID ident = null;

    try {
      ident = (TemplateID)o;
    } catch (ClassCastException e) {
      return false;
    }

    return (name.equals(ident.name));
  }

  public int hashCode()
  {
    return toString().hashCode();
  }
}
