package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class StringLiteral extends Literal
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = StringLiteral.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private String value;

  public StringLiteral(String s)
  {
    object_print_method = class_print_method;
    value = s;
  }

  public Object clone()
  {
    StringLiteral o = (StringLiteral)super.clone();
    o.value = value;
    return o;
  }

  /**
   * Prints a literal to a stream.
   *
   * @param lit The literal to print.
   * @param stream The stream on which to print the literal.
   */
  public static void defaultPrint(StringLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("\"" + lit.value + "\"");
  }

  public boolean equals(Object o)
  {
    StringLiteral s = null;
    try {
      s = (StringLiteral)o;
    } catch (ClassCastException e) {
      return false;
    }
    return (s.value == value);
  }

  public String getValue()
  {
    return value;
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

  public void setValue(String value)
  {
    this.value = value;
  }

  /**
   * Removes outer quotes from the string; this class automatically
   * prints quotes around the string so it does not need to store them.
   * Thus, if you create a StringLiteral with a String that already has
   * quotes around it, you will have double quotes, and may need to call
   * this method.  The method has no effect if there are no quotes.
   */
  public void stripQuotes()
  {
    String quote = "\"";

    if (value.startsWith(quote) && value.endsWith(quote))
      value = value.substring(1, value.length() - 1);
  }
}
