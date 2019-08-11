package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a C-style do-while loop.
 */
public class DoLoop extends Statement implements Loop, SymbolTable
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = DoLoop.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private HashMap symbol_table;

  public DoLoop(Statement body, Expression condition)
  {
    object_print_method = class_print_method;
    symbol_table = new HashMap(4);

    children.add(body);
    body.setParent(this);
    children.add(condition);
    condition.setParent(this);
  }

  public void addDeclaration(Declaration decl)
  {
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
  }

  /**
   * Prints a loop to a stream.
   *
   * @param loop The loop to print.
   * @param stream The stream on which to print the loop.
   */
  public static void defaultPrint(DoLoop loop, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.println("do");
    loop.getBody().print(stream);
    p.print("while");
    p.print("(");
    loop.getCondition().print(stream);
    p.println(");");
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public Statement getBody()
  {
    return (Statement)children.get(0);
  }

  public Expression getCondition()
  {
    return (Expression)children.get(1);
  }

  public List getParentTables()
  {
    return Tools.getParentTables(this);
  }

  public HashMap getTable()
  {
    return symbol_table;
  }

  public void setBody(Statement body)
  {
    if (body.getParent() != null)
      throw new NotAnOrphanException();

    if (getBody() != null)
      getBody().setParent(null);

    children.set(0, body);
    body.setParent(this);
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

  public void setCondition(Expression cond)
  {
    if (cond.getParent() != null)
      throw new NotAnOrphanException();

    if (getCondition() != null)
      getCondition().setParent(null);

    children.set(1, cond);
    cond.setParent(this);
  }
}
