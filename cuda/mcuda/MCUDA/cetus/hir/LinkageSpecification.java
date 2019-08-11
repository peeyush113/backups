package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents the <var>extern "C"</var> specification
 * in C++ programs.
 */
public class LinkageSpecification extends Declaration implements SymbolTable
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = LinkageSpecification.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private String calling_convention;
  private HashMap symbol_table;

  /**
   * Represents <var>extern "s" decl</var>.
   *
   * @param s The name of the other language.
   * @param decl The declaration whose linkage is being specified.
   */
  public LinkageSpecification(String s, Declaration decl)
  {
    object_print_method = class_print_method;

    calling_convention = s;
    children.add(decl);
  }

  /**
   * Represents <var>extern "s" { decl_list }</var>.
   *
   * @param s The name of the other language.
   * @param decl_list The declaration whose linkage is being specified.
   */
  public LinkageSpecification(String s, List decl_list)
  {
    object_print_method = class_print_method;

    calling_convention = s;
    children.addAll(decl_list);
  }

  public void addDeclaration(Declaration decl)
  {
    children.add(decl);
    /* TODO - decl stmt & symbol table entry */
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
  }

  /**
   * Prints a linkage specification block to a stream.
   *
   * @param spec The block to print.
   * @param stream The stream on which to print the block.
   */
  public static void defaultPrint(LinkageSpecification spec, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("extern \"");
    p.print(spec.calling_convention);
    p.print("\"\n{\n");
    Tools.printlnList(spec.children, stream);
    p.print("}");
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public List getDeclaredSymbols()
  {
    return new LinkedList();
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
