package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class IntegerLiteral extends Literal
{
  private static Method class_print_method;

  //specifically used to handle 
  private static Method hex_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = IntegerLiteral.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);

      hex_print_method = params[0].getMethod("printHex", params);

    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private long value;
  private String suffix;

  public IntegerLiteral(long value)
  {
    object_print_method = class_print_method;
    this.value = value;
    this.suffix = null;
  }

  public IntegerLiteral(long value, String suffix)
  {
    object_print_method = class_print_method;
    this.value = value;
    this.suffix = suffix;
  }

	/**
	*	construct an IntegerLiteral from a string and set the proper print method
	*/
	public IntegerLiteral(String _int_str)
	{
        //String	D = "[0-9]";
        //String	L = "[a-zA-Z_]";
        String  H = "[a-fA-F0-9]";
        //String  E = "[Ee][+-]?(" + D + ")+";
        //String  FS	= "(f|F|l|L)";
        String  IS	= "(u|U|l|L)*";

        String const1 = "0[xX](" + H + ")+(" + IS + ")?";
        //String const2 = "0(" + D + ")+(" + IS + ")?";
        //String const3 = "(" + D + ")+(" + IS+ ")?";
        //String const4 = L + "?'(\\.|[^\\'])+'";	//weird
        //String const5 = "(" + D + ")+(" + E + ")(" + FS + ")?";
        //String const6 = "(" + D + ")*.(" + D + ")+(" + E + ")?" + FS + "?";
        //String const7 = "(" + D + ")+.(" + D + ")*(" + E + ")?" + FS + "?";

        //String	int_exp = const1 + "|" + const2 + "|" + const3;
		//String	float_exp = const5 + "|" + const6 + "|" + const7;

		String	int_hex_exp = const1;
		//String	int_dec_exp = const2 + "|" + const3;

		if (_int_str.matches(int_hex_exp) == true)
		{
			//set the print method
			//this.setPrintMethod(this.printHex);
			object_print_method = hex_print_method;
		}
		else
		{
		    object_print_method = class_print_method;
		}

		this.value = (Long.decode(_int_str)).longValue();
          this.suffix = null;
	}

  public Object clone()
  {
    IntegerLiteral o = (IntegerLiteral)super.clone();
    o.value = value;
    o.suffix = suffix;
    return o;
  }

  /**
   * Prints a literal to a stream.
   *
   * @param lit The literal to print.
   * @param stream The stream on which to print the literal.
   */
  public static void defaultPrint(IntegerLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print(Long.toString(lit.value));
    if (lit.suffix != null)
      p.print(lit.suffix);
  }

  public boolean equals(Object o)
  {
    IntegerLiteral i = null;
    try {
      i = (IntegerLiteral)o;
    } catch (ClassCastException e) {
      return false;
    }
    return (i.value == value);
  }

  public long getValue()
  {
    return value;
  }

  public int hashCode()
  {
    return toString().hashCode();
  }

  public static void printHex(IntegerLiteral lit, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("0X" + Long.toHexString(lit.value));
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

  public void setValue(long value)
  {
    this.value = value;
  }
}
