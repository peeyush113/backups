package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class TypeofSpecifier extends Specifier
{
  private Expression expr;
  private List type_id;

  public TypeofSpecifier(Expression expr)
  {
    this.expr = expr;
    this.type_id = null;
  }

  public TypeofSpecifier(List type_id)
  {
    this.expr = null;
    this.type_id = type_id;
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("typeof ( ");
    if (expr != null)
      expr.print(stream);
    else
      Tools.printListWithSeparator(type_id, stream, " ");
    p.print(" ) ");
  } 
}
