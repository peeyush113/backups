package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * A statement that adds an entry to a symbol table.
 */
public class DeclarationStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = DeclarationStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create a declaration statement given a declaration.
   *
   * @param decl The declaration part of the statement.
   */
  public DeclarationStatement(Declaration decl)
  {
    object_print_method = class_print_method;

    children.add(decl);
    decl.setParent(this);
  }

  /**
   * Prints a statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(DeclarationStatement stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    stmt.getDeclaration().print(stream);

    if (stmt.getDeclaration().getClass() != Annotation.class)
      p.print(";");
  }

  /**
   * Returns the declaration part of the statement.
   *
   * @return the declaration part of the statement.
   */
  public Declaration getDeclaration()
  {
    return (Declaration)children.get(0);
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
