package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents an empty statement.  Empty statements need
 * to be preserved by the IR because there are some coding
 * "tricks" that rely on them.  For example, because a label
 * must appear before a statement, there is no way of putting
 * a label at the end of a block, so it's common to find a labeled
 * null statement there.
 */
public class NullStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = NullStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Create a new break statement.
   */
  public NullStatement()
  {
    object_print_method = class_print_method;
  }

  /**
   * Prints a null statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(NullStatement stmt, OutputStream stream)
  {
    (new PrintStream(stream)).print(";");
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
