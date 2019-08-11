package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a class, struct, or union.  These are actually specifiers
 * in C and C++, since variables can be declared immediately following
 * the class declaration, but that's mostly syntactic sugar.  We assume
 * it can be split into a class declaration followed by a variable
 * declaration.  We have a single class representing all three
 * (class, struct, union) because they are fundamentally the same
 * except for default access levels and storage layout, which
 * do not make a significant difference to source-to-source compilers.
 * Anonymous structs should be given a unique name (most compilers
 * do this internally anyway).
 */
public class ClassDeclaration extends Declaration
  implements SymbolTable
{
  private static Method class_print_method;
  public static final Method print_as_cpp;
  public static final Method print_as_java;
  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ClassDeclaration.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
      print_as_cpp = params[0].getMethod("printCpp", params);
      print_as_java = params[0].getMethod("printJava", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private static class Key
  {
    private static String[] name = { "class", "struct", "union", "interface" };

    private int value;

    public Key(int value)
    {
      this.value = value;
    }

    public void print(OutputStream stream)
    {
      PrintStream p = new PrintStream(stream);
      p.print(name[value]);
    }

    public String toString()
    {
      return name[value];
    }
  }

  public static final Key CLASS  = new Key(0);
  public static final Key STRUCT = new Key(1);
  public static final Key UNION  = new Key(2);
  public static final Key INTERFACE = new Key(3);

  /** For Java only: leading specifiers on the class
   * declaration itself, such as public or abstract. */
  private List class_specs;

  private Key type;
  private IDExpression name;
 
  /** For C++ only: Paired one-to-one with extends_list to
   * specify the type of inheritence. */
  private List extends_access_list;

  /** List of classes that this class extends. */
  private List extends_list;

  /** List of interfaces that this class implements. */
  private List implements_list;

  private HashMap symbol_table = new HashMap(4);

  /* TODO - constructor for a Java class (which allows
     specifiers before the "class" keyword) */

  public ClassDeclaration(List class_specs, Key type, IDExpression name)
  {
    object_print_method = class_print_method;

    this.class_specs = class_specs;
    this.type = type;
    this.name = name;

    extends_access_list = new LinkedList();
    extends_list = new LinkedList();
    implements_list = new LinkedList();
  }

  /**
   * Creates an empty class.
   *
   * @param type Must be one of CLASS, STRUCT, UNION, or INTERFACE.
   * @param name The name for the class.
   */
  public ClassDeclaration(Key type, IDExpression name)
  {
    object_print_method = class_print_method;

    class_specs = new LinkedList();

    this.type = type;
    this.name = name;

    extends_access_list = new LinkedList();
    extends_list = new LinkedList();
    implements_list = new LinkedList();
  }

  /**
   * Creates a class.
   *
   * @param type Must be one of CLASS, STRUCT, UNION, or INTERFACE.
   * @param name The name for the class.
   * @param no_body True if this a forward declaration.
   */
  public ClassDeclaration(Key type, IDExpression name, boolean no_body)
  {
    object_print_method = class_print_method;

    class_specs = new LinkedList();

    this.type = type;
    this.name = name;

    extends_access_list = new LinkedList();
    extends_list = new LinkedList();
    implements_list = new LinkedList();

    if (no_body)
      children = null;
  }

  public void addBaseClass(IDExpression name)
  {
    extends_access_list.add(null);
    extends_list.add(name);
  }

  public void addBaseClass(Specifier access, Identifier name)
  {
    extends_access_list.add(access);
    extends_list.add(name);
  }

  public void addBaseInterface(IDExpression name)
  {
    implements_list.add(name);
  }

  public void addDeclaration(Declaration decl)
  {
    if (children == null)
      throw new IllegalStateException();

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      DeclarationStatement stmt = new DeclarationStatement(decl);
      children.add(stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(decl);
      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
    {
      if (ref.getParent() instanceof DeclarationStatement)
        index = Tools.indexByReference(children, ref.getParent());

      if (index == -1)
        throw new IllegalArgumentException();
    }

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      DeclarationStatement stmt = new DeclarationStatement(decl);
      children.add(index, stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(index, decl);
      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
    {
      if (ref.getParent() instanceof DeclarationStatement)
        index = Tools.indexByReference(children, ref.getParent());

      if (index == -1)
        throw new IllegalArgumentException();
    }

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      DeclarationStatement stmt = new DeclarationStatement(decl);

      // if ref is last child
      if (index == children.size() - 1)
        children.add(stmt);
      else
        children.add(index + 1, stmt);

      stmt.setParent(this);
    }
    else
    {
      // if ref is last child
      if (index == children.size() - 1)
        children.add(decl);
      else
        children.add(index + 1, decl);

      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  /**
   * Prints a class to a stream.
   *
   * @param decl The class to print.
   * @param stream The stream on which to print the class.
   */
  public static void defaultPrint(ClassDeclaration decl, OutputStream stream)
  {
    printCpp(decl, stream);
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public List getDeclaredSymbols()
  {
    LinkedList list = new LinkedList();
	list.add(new Identifier(type+" "+name));
    return list;
  }

  public Key getKey()
  {
    return type;
  }

  public IDExpression getName()
  {
    return name;
  }

  public List getParentTables()
  {
    LinkedList list = new LinkedList();

    SymbolTable outer_table = (SymbolTable)getParent();

    Iterator iter = extends_list.iterator();
    while (iter.hasNext())
    {
      Identifier ident = (Identifier)iter.next();
      SymbolTable st = (SymbolTable)Tools.findSymbol(outer_table, ident);
      if (st != null)
        list.add(st);
    }

    iter = implements_list.iterator();
    while (iter.hasNext())
    {
      Identifier ident = (Identifier)iter.next();
      SymbolTable st = (SymbolTable)Tools.findSymbol(outer_table, ident);
      if (st != null)
        list.add(st);
    }

    list.add(outer_table);

    return list;
  }

  public HashMap getTable()
  {
    return symbol_table;
  }

  /**
   * Prints a C++ class to a stream.
   *
   * @param decl The class to print.
   * @param stream The stream on which to print the class.
   */
  public static void printCpp(ClassDeclaration decl, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    decl.type.print(stream);
    p.print(" ");
    decl.name.print(stream);

    if (decl.extends_access_list.size() > 0
        || decl.extends_list.size() > 0)
      p.print(" : ");

    Iterator iter = decl.extends_access_list.iterator();
    Iterator iter2 = decl.extends_list.iterator();
    while (iter.hasNext())
    {
      Specifier as = (Specifier)iter.next();
      Identifier ident = (Identifier)iter2.next();

      if (as != null)
        as.print(stream);

      ident.print(stream);
    }

    if (decl.children != null)
    {
      p.print("\n{\n");
      Tools.printlnList(decl.children, stream);
      p.println("};");
    }
    else
      p.println(";");
  }

  /**
   * Prints a Java class to a stream.
   *
   * @param decl The class to print.
   * @param stream The stream on which to print the class.
   */
  public static void printJava(ClassDeclaration decl, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
	Tools.printListWithSeparator(decl.class_specs, stream, " ");
  	p.print(" "); 
    decl.type.print(stream);
    p.print(" ");
    decl.name.print(stream);

    if (!decl.extends_list.isEmpty())
    {
      p.print(" extends ");
      ((Identifier)decl.extends_list.get(0)).print(stream);
    }

    if (!decl.implements_list.isEmpty())
    {
      p.print(" implements ");
      Tools.printListWithCommas(decl.implements_list, stream);
    }

    if (decl.children != null)
    {
      p.print("\n{\n");
      Tools.printlnList(decl.children, stream);
      p.println("}");
    }
    else
      p.println(";");
  }

  public void removeChild(Traversable child)
  {
    int index = Tools.indexByReference(children, child);

    if (index == -1)
      throw new IllegalArgumentException();

    children.remove(index);
    child.setParent(null);

    if (child instanceof Declaration)
      Tools.removeSymbols(this, (Declaration)child);
    else if (child instanceof DeclarationStatement)
      Tools.removeSymbols(this, ((DeclarationStatement)child).getDeclaration());
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
