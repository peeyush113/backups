package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class EscapeLiteral extends Literal
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = EscapeLiteral.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private char value;
  private String name;
  public EscapeLiteral(String name)
  {
  	char c = name.charAt(2);
    switch(c){
        					case 'a':
        					c = '\7';
        					break;
        					case 'b':
        					c = '\b';
        					break;
        					case 'f':
        					c = '\f';
        					break;
        					case 'n':
        					c = '\n';
        					break;
        					case 'r':
        					c = '\r';
        					break;
        					case 't':
        					c = '\t';
        					break;
        					case 'v':
        					c = '\14';
        					break;
        					case '\\':
        					c = '\\';
        					break;
        					case '?':
        					c = '\77';
        					break;
        					case '\'':
        					c = '\'';
        					break;
        					case '\"':
        					c = '\"';
        					break;
        					case 'x':
        						c = (char)Integer.parseInt(name.substring(3,name.length()-1),16);
        					break;
        					default:
        						if(c <= '7' && c >= '0'){
        							c = (char)Integer.parseInt(name.substring(2,name.length()-1),8);
        						}
        						else{
        							c = '?';
        							Tools.printlnStatus("Unrecognized Escape Sequence "+name,0);
        						}
        					break;
    }
    object_print_method = class_print_method;
    this.name = name;
    this.value = c;
  }

  public Object clone()
  {
    EscapeLiteral o = (EscapeLiteral)super.clone();
    o.value = value;
    o.name = name;
    return o;
  }

  /**
   * Prints a literal to a stream.
   *
   * @param lit The literal to print.
   * @param stream The stream on which to print the literal.
   */
  public static void defaultPrint(EscapeLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print(lit.name);
  }

  public boolean equals(Object o)
  {
    EscapeLiteral ch = null;
    try {
      ch = (EscapeLiteral)o;
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
