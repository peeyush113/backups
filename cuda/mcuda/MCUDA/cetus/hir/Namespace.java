package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a block of declarations that share a common namespace.
 */
public class Namespace extends Declaration implements SymbolTable
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Namespace.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private IDExpression name;
  private HashMap symbol_table;

  /**
   * Creates an anonymous namespace.
   */
  public Namespace()
  {
    object_print_method = class_print_method;

    name = null;
  }

  /**
   * Creates a named namespace.
   *
   * @param name The name of the namespace.
   */
  public Namespace(IDExpression name)
  {
    object_print_method = class_print_method;

    this.name = name;
  }

  public void addDeclaration(Declaration decl)
  {
    children.add(decl);
    /* TODO - symbol table & decl stmt */
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
  }

  /**
   * Prints a namespace to a stream.
   *
   * @param nspace The namespace to print.
   * @param stream The stream on which to print the namespace.
   */
  public static void defaultPrint(Namespace nspace, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("namespace ");
    if (nspace.name != null)
      nspace.name.print(stream);

    p.print("\n{\n");
    Tools.printlnList(nspace.children, stream);
    p.print("}");
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public List getDeclaredSymbols()
  {
    return (new ChainedList()).addLink(name);
  }

  public List getParentTables()
  {
    return Tools.getParentTables(this);
  }

  public HashMap getTable()
  {
    return symbol_table;
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
