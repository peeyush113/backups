package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class  BooleanLiteral  extends Literal
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = BooleanLiteral.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private boolean value;

  public BooleanLiteral(boolean value)
  {
    object_print_method = class_print_method;
    this.value = value;
  }

  public Object clone()
  {
    BooleanLiteral o = (BooleanLiteral)super.clone();
    o.value = value;
    return o;
  }

  /**
   * Prints a literal to a stream.
   *
   * @param lit The literal to print.
   * @param stream The stream on which to print the literal.
   */
  public static void defaultPrint(BooleanLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print(Boolean.toString(lit.value));
  }

  public boolean equals(Object o)
  {
    BooleanLiteral b = null;
    try {
      b = (BooleanLiteral)o;
    } catch (ClassCastException e) {
      return false;
    }
    return (b.value == value);
  }

  /**
   * Returns the boolean value.
   *
   * @return the value of this BooleanLiteral.
   */
  public boolean getValue()
  {
    return value;
  }

  public int hashCode()
  {
    return toString().hashCode();
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
  
  /**
   * Set the boolean value of this object.
   */
  public void setValue(boolean value)
  {
    this.value = value;
  }
}
