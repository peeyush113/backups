package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class CharLiteral extends Literal
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = CharLiteral.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private char value;

  public CharLiteral(char value)
  {
    object_print_method = class_print_method;
    this.value = value;
  }

  public Object clone()
  {
    CharLiteral o = (CharLiteral)super.clone();
    o.value = value;
    return o;
  }

  /**
   * Prints a literal to a stream.
   *
   * @param lit The literal to print.
   * @param stream The stream on which to print the literal.
   */
  public static void defaultPrint(CharLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("'" + lit.value + "'");
  }

  public boolean equals(Object o)
  {
    CharLiteral ch = null;
    try {
      ch = (CharLiteral)o;
    } catch (ClassCastException e) {
      return false;
    }
    return (ch.value == value);
  }

  public char getValue()
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

  public void setValue(char value)
  {
    this.value = value;
  }
}
