package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class UsingDeclaration extends Declaration
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = UsingDeclaration.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private IDExpression expr;

  public UsingDeclaration(IDExpression expr)
  {
    object_print_method = class_print_method;
    this.expr = expr;
  }

  public static void defaultPrint(UsingDeclaration decl, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("using ");
    decl.expr.print(stream);
    p.print(";");
  }

  public List getDeclaredSymbols()
  {
    return new LinkedList();
  }
}
