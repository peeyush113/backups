package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents the name of a C++ destructor.
 */
public class DestructorID extends IDExpression
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = DestructorID.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  public DestructorID(IDExpression class_name)
  {
    super(false);

    object_print_method = class_print_method;

    children.add(class_name);
    class_name.setParent(this);
  }

  public Object clone()
  {
    DestructorID o = (DestructorID)super.clone();
    return o;
  }

  /**
   * Prints a destructor to a stream.
   *
   * @param dest The destructor to print.
   * @param stream The stream on which to print the destructor.
   */
  public static void defaultPrint(DestructorID dest, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("~");
    dest.getClassName().print(stream);
  }

  public IDExpression getClassName()
  {
    return (IDExpression)children.get(0);
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
