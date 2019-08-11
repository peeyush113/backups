package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a label for use with gotos.
 */
public class Label extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Label.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private Identifier name;

  /**
   * Create a new label.
   */
  public Label(Identifier name)
  {
    object_print_method = class_print_method;
    this.name = name;
    name.setParent(this);
  }

  /**
   * Prints a label to a stream.
   *
   * @param label The label to print.
   * @param stream The stream on which to print the label.
   */
  public static void defaultPrint(Label label, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    label.name.print(stream);
    p.print(":");
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
   * Returns the string for this Label
   *
   */
  public Identifier getName(){
  	return name;
  }
}
