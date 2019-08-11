package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 *
 */
public class TemplateDeclaration extends Declaration
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = TemplateDeclaration.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private List params;

  public TemplateDeclaration(List params, Declaration decl)
  {
    object_print_method = class_print_method;

    this.params = params;

    children.add(decl);
    decl.setParent(this);
  }

  /**
   * Prints a template to a stream.
   *
   * @param decl The template to print.
   * @param stream The stream on which to print the namespace.
   */
  public static void defaultPrint(TemplateDeclaration decl, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("template < ");
    Tools.printListWithCommas(decl.params, stream);
    p.print(" > \n");
    decl.getDeclaration().print(stream);
  } 

  public Declaration getDeclaration()
  {
    return (Declaration)children.get(0);
  }

  public List getDeclaredSymbols()
  {
    return getDeclaration().getDeclaredSymbols();
  }
}
