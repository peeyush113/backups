package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class Identifier extends IDExpression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Identifier.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private String name;
	private Declarator decl = null;
	private VariableDeclaration decls = null;

  public Identifier(String name)
  {
    super(false);

    object_print_method = class_print_method;
    this.name = new String(name);
  }

  public Identifier(boolean global, String name)
  {
    super(global);

    object_print_method = class_print_method;
    this.name = new String(name);
  }

  public Object clone()
  {
    Identifier o = (Identifier)super.clone();
    o.name = new String(name);
    return o;
  }

  /**
   * Prints an identifier to a stream.
   *
   * @param ident The identifier to print.
   * @param stream The stream on which to print the identifier.
   */
  public static void defaultPrint(Identifier ident, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    if (ident.typename)
      p.print("typename ");

    if (ident.global)
      p.print("::");

    p.print(ident.name);
  }

  public boolean equals(Object o)
  {
    Identifier ident = null;

    try {
      ident = (Identifier)o;
    } catch (ClassCastException e) {
      return false;
    }

    return (name.compareTo(ident.name) == 0);
  }

  public int hashCode()
  {
    /* see the IDExpression grandparent class for the toString implementation */
    return toString().hashCode();
  }
}
