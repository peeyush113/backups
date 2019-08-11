package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.exec.Driver;

/**
 * Represents the entire program.
 */
public final class Program implements Printable, Traversable
{
  private static Method class_print_method;
  private Method object_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = Program.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /** Every child is a TranslationUnit. An array list is used here in case
    * we want to do parallel parsing and need the indices.
    */
  private ArrayList<TranslationUnit> children;
 
  /**
   * Make an empty program.
   */ 
  public Program()
  {
    object_print_method = class_print_method;

    children = new ArrayList<TranslationUnit>(1);
  }

  /**
   * Make a program from a group of source files.
   *
   * @param files A list of strings that are source file names.
   */
  public Program(List<String> files)
  {
    object_print_method = class_print_method;

    children = new ArrayList<TranslationUnit>(files.size());

    for (String f : files)
      addTranslationUnit(new TranslationUnit(f));
  }

  /**
   * Make a program from a group of source files.
   *
   * @param files An array of strings that are source file names.
   */
  public Program(String[] files)
  {
    object_print_method = class_print_method;

    children = new ArrayList<TranslationUnit>(files.length);

    for (String f : files)
      addTranslationUnit(new TranslationUnit(f));
  }

  /**
   * Adds a translation unit to the program.
   *
   * @param tunit The translation unit to add.  Its parent
   * will be set to this program.
   */
  public void addTranslationUnit(TranslationUnit tunit)
  {
    if (tunit.getParent() != null)
      throw new NotAnOrphanException();

    children.add(tunit);
    tunit.setParent(this);
  }

  /**
   * Prints the entire program to a stream.
   *
   * @param prog The program to print.
   * @param stream The stream on which to print the program.
   */
  public static void defaultPrint(Program prog, OutputStream stream)
  {
    Tools.printlnList(prog.children, stream);
  }

  public List<TranslationUnit> getChildren()
  {
    return children;
  }

  public Traversable getParent()
  {
    /* a program has no parent */
    return null;
  }

  /**
   * Spawns threads to parse all of the translation units in parallel.
   *
   * @throws IOException if there is a problem accessing any file.
   */
  public void parallelParse() throws IOException
  {
    /* TODO */    
  }

  /**
   * Parse all of the translation units that belong to this program.
   *
   * @throws IOException if there is a problem accessing any file.
   */
  public void parse() throws IOException
  {
    for (TranslationUnit t : children)
      t.parse();
  }

  /**
   * Write all translation units to their respective files.
   *
   * @throws FileNotFoundException if a file could not be opened. 
   */
  public void print() throws IOException
  {
    String outdir = Driver.getOptionValue("outdir");

    /* make sure the output directory exists */
    try {
      File dir = new File(".");
      File fname = new File(dir.getCanonicalPath(), outdir);
      if (!fname.exists())
      {
        if (!fname.mkdir())
          throw new IOException("mkdir failed");
      }
    } catch (IOException e) {
      System.err.println("cetus: could not create output directory, " + e);
      System.exit(1);
    } catch (SecurityException e) {
      System.err.println("cetus: could not create output directory, " + e);
      System.exit(1);
    }

    for (TranslationUnit t : children)
      t.print();
  }

  public void print(OutputStream stream)
  {
    if (object_print_method == null)
      return;

    Object[] args = new Object[2];
    args[0] = this;
    args[1] = stream;

    try {
      object_print_method.invoke(null, args);
    } catch (IllegalAccessException e) {
      throw new InternalError(); 
    } catch (InvocationTargetException e) {
      throw new InternalError();
    }
  }

  public void removeChild(Traversable child)
  {
    int index = Tools.indexByReference(children, child);

    if (index == -1)
      throw new IllegalArgumentException();

    children.remove(index);
    child.setParent(null);
  }

  public void setChild(int index, Traversable t)
  {
    if (t.getParent() != null)
      throw new NotAnOrphanException();

    if (t instanceof TranslationUnit)
    {
      children.set(index, (TranslationUnit)t);
      t.setParent(this);
    }
    else
      throw new IllegalArgumentException();
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
   * Unsupported - the parent of a program is null and may not be changed.
   */
  public void setParent(Traversable t)
  {
    throw new UnsupportedOperationException();
  }

  /**
   * Overrides the print method for this object only.
   *
   * @param m The new print method.
   */
  public void setPrintMethod(Method m)
  {
    object_print_method = m;
  }
}
