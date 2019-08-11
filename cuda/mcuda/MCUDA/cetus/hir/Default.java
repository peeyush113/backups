package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a default for use with switch.
 */
public class Default extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Default.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create a new default.
   */
  public Default()
  {
    object_print_method = class_print_method;
  }

  /**
   * Prints a default label to a stream.
   *
   * @param label The default label to print.
   * @param stream The stream on which to print the default label.
   */
  public static void defaultPrint(Default label, OutputStream stream)
  {
    (new PrintStream(stream)).print("default:");
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
}
