package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * An expression that is a program symbol.
 */
public abstract class IDExpression extends Expression
{
  protected boolean global;
  protected boolean typename;

  /**
   * Creates an IDExpression for derived classes.
   *
   * @param global True if the expression needs to be prefixed by the scope
   *   resolution operator (::), false if it does not need it.
   */
  protected IDExpression(boolean global)
  {
    this.global = global;
    this.typename = false;
  }

  protected IDExpression(boolean global, boolean typename)
  {
    this.global = global;
    this.typename = typename;
  }

  public Object clone()
  {
    IDExpression o = (IDExpression)super.clone();
    o.global = global;
    o.typename = typename;
    return o;
  }

  /**
   * Performs a symbol table lookup of this expression on the nearest
   * enclosing SymbolTable.
   *
   * @return a Declaration for this expression or null if one cannot
   *   be found.
   */
  public Declaration findDeclaration()
  {
    Traversable t = this;

    if (getParent() == null)
      System.err.println("expr with no parent");

    while (t != null)
    {
      if (t instanceof SymbolTable)
        return ((SymbolTable)t).findSymbol(this);
      else
        t = t.getParent();
    }

    return null;
  }

  /**
   * This method is used to force it to be global.
   */
  public void setGlobal(boolean value)
  {
    global = value;
  }

  public void setTypename(boolean value)
  {
    typename = value;
  }
}
