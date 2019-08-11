package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Represents a C or C++ enumeration
 */
public class Enumeration extends Declaration 
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Enumeration.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private Identifier name;

  /**
   * Creates an enumeration.
   *
   * @param name The name of the enumeration.
   * @param declarators A list of declarators to use as the enumerators.
   *   For enumerations that are not consecutive, initializers should be
   *   placed on the declarators.
   */
  public Enumeration(Identifier name, List declarators)
  {
    object_print_method = class_print_method;

    if (name == null
        || !Tools.verifyHomogeneousList(declarators, Declarator.class))
      throw new IllegalArgumentException();

    this.name = name;

    Iterator iter = declarators.iterator();
    while (iter.hasNext())
    {
      Declarator d = (Declarator)iter.next();
      children.add(d);
      d.setParent(this);
    }
  }

  /**
   * Prints an enumeration to a stream.
   *
   * @param decl The enumeration to print.
   * @param stream The stream on which to print the enumeration.
   */
  public static void defaultPrint(Enumeration decl, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("enum ");
    decl.name.print(stream);
    p.print(" { ");
    Tools.printListWithCommas(decl.children, stream);
    p.print(" }");
  }

  public List getDeclaredSymbols()
  {
    return (new ChainedList()).addLink(name);
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
