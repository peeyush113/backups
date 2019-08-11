package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * 
 */
public class NamespaceAlias extends Declaration
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = NamespaceAlias.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private Identifier name;
  private IDExpression original;

  /**
   * Create a namespace alias.
   *
   * @param name The name for this alias.
   * @param original The name of the original namespace.
   */
  public NamespaceAlias(Identifier name, IDExpression original)
  {
    this.name = name;
    this.original = original;
  }

  /**
   * Prints an alias to a stream.
   *
   * @param alias The alias to print.
   * @param stream The stream on which to print the alias.
   */
  public static void defaultPrint(NamespaceAlias alias, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("namespace ");
    alias.name.print(stream);
    p.print(" = ");
    alias.original.print(stream); 
  }

  public List getDeclaredSymbols()
  {
    return (new ChainedList()).addLink(name);
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
