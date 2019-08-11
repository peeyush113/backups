package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class FloatLiteral extends Literal
{
  private static Method class_print_method;
  private boolean isDouble = true;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = FloatLiteral.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private double value;

  public FloatLiteral(double value)
  {
    object_print_method = class_print_method;
    this.value = value;
  }

  public FloatLiteral(double value, boolean isDouble)
  {
    object_print_method = class_print_method;
    this.value = value;
    this.isDouble = isDouble;
  }

  public Object clone()
  {
    FloatLiteral o = (FloatLiteral)super.clone();
    o.value = value;
    return o;
  }

  /**
   * Prints a literal to a stream.
   *
   * @param lit The literal to print.
   * @param stream The stream on which to print the literal.
   */
  public static void defaultPrint(FloatLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    String txt = (new Double(lit.value)).toString();
    if(!(lit.isDouble))
      txt = txt + 'f';
    p.print(txt);
    //p.print((new Double(lit.value)).toString());
  }

  public boolean equals(Object o)
  {
    FloatLiteral f = null;
    try {
      f = (FloatLiteral)o;
    } catch (ClassCastException e) {
      return false;
    }
    return (f.value == value);
  }

  public double getValue()
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

  public void setValue(double value)
  {
    this.value = value;
  }
}
