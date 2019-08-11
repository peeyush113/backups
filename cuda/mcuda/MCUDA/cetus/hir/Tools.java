package cetus.hir;

import java.io.*;
import java.util.*;

import cetus.exec.*;

/**
 * A collection of useful static methods that operate on the IR.
 * In general, code goes here if it is used by multiple classes
 * that have no common ancestor.  Java does not have multiple
 * inheritence, and it seems better to put the code here instead
 * of introducing extra classes to solve the problem.  Note that
 * interfaces cannot solve the problem because you cannot provide
 * an implementation of a method within an interface. 
 */
public abstract class Tools
{
  /**
   * Java doesn't allow a class to be both abstract and final,
   * so this private constructor prevents any derivations.
   */
  private Tools()
  {
  }

  /**
   * Adds symbols to a symbol table and checks for duplicates.
   *
   * @param table The symbol table to add the symbols to.
   * @param decl The declaration of the symbols.
   * @throws DuplicateSymbolException if there are conflicts with
   *   any existing symbols in the table.
   */
  public static void addSymbols(SymbolTable table, Declaration decl)
  {
    List names = decl.getDeclaredSymbols();
    Iterator iter = names.iterator();

    HashMap symbol_table = table.getTable();

    while (iter.hasNext())
    {
      IDExpression expr = (IDExpression)iter.next();

      if (!(decl instanceof Procedure) && symbol_table.containsKey(expr)){
        //throw new DuplicateSymbolException(expr.toString() + " is already in this table");
        //System.err.println("[WARNING] " + expr.toString() + " is already in this table");
	  }
	  else
        symbol_table.put(expr, decl);
    }
  }

  /**
   * Searches the IR tree beginning at t for the Expression e.
   * 
   * @return true if t contains e and false otherwise
   */
  public static boolean containsExpression(Traversable t, Expression e)
  {
    return (t.toString().indexOf(e.toString()) != -1);
  }

  /**
   * Counts the number of times that the Expression e appears in
   * the IR tree t.
   *
   * @return the number of times e appears in t
   */
  public static int countExpressions(Traversable t, Expression e)
  {
    String t_string = t.toString();
    String e_string = e.toString();
    int e_string_length = e_string.length();

    int i, n = 0;

    while ((i = t_string.indexOf(e_string)) != -1)
    {
      ++n;

      t_string = t_string.substring(i + e_string_length);
    }

    return n;
  }

  /**
   * Finds the first instance of the Expression e in the IR tree t.
   *
   * @return an expression from t that matches e
   */
  public static Expression findExpression(Traversable t, Expression e)
  {
    DepthFirstIterator iter = new DepthFirstIterator(t);
    String e_string = e.toString();

    for (;;)
    {
      Expression t_e;

      try {
        t_e = (Expression)iter.next(Expression.class);
      } catch (NoSuchElementException nse) {
        break;
      }

      if (t_e.toString().compareTo(e_string) == 0)
        return t_e;
    } 

    return null;
  } 

  /**
   * Searches for a symbol by name in the table.  If the symbol is
   * not in the table, then parent tables will be searched breadth-first.
   *
   * @param table The initial table to search.
   * @param name The name of the symbol to locate.
   *
   * @return a Declaration if the symbol is found, or null if it is not found.
   *    The Declaration may contain multiple declarators, of which name will
   *    be one, unless the SingleDeclarator pass has been run on the program.
   */
  public static Declaration findSymbol(SymbolTable table, IDExpression name)
  {
    LinkedList tables_to_search = new LinkedList();
    tables_to_search.add(table);

    /* Treat tables_to_search as a queue of tables, adding parent
       tables to the end of the list if name isn't in the current table. */
    while (!tables_to_search.isEmpty())
    {
      SymbolTable st = (SymbolTable)tables_to_search.removeFirst();
      
	  Declaration decl = (Declaration)st.getTable().get(name);

      if (decl != null)
        return decl;

      tables_to_search.addAll(st.getParentTables());
    }

    return null;
  }

  static List getParentTables(Traversable obj)
  {
    LinkedList list = new LinkedList();

    Traversable p = obj.getParent();
    while (p != null)
    {
      try {
        SymbolTable st = (SymbolTable)p;
        list.add(st);
        break;
      } catch (ClassCastException e) {
        p = p.getParent();
      }
    }

    return list;
  }

  /**
   * Returns a randomly-generated name that is not found in the table.
   *
   * @param table The table to search.
   *
   * @return a unique name.
   */
  public static Identifier getUnusedSymbol(SymbolTable table)
  {
    String name = null;
    Identifier ident = null;
    Random rand = new Random();

    String alphabet = new String("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_");

    do {
      name = "";
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      name += alphabet.charAt(rand.nextInt(52));
      ident = new Identifier(name);
      /**
       * John A. Stratton
       * Bug fix: leave when we -don't- get an existing symbol
       */
    } while (findSymbol(table, ident) != null);

    return ident;
  }

  /**
   * The standard indexOf methods on lists use the equals method
   * when searching for an object; sometimes we want to use ==
   * and this method provides that service.
   *
   * @param list The list to search.
   * @param obj The object sought.
   *
   * @return the index of the object or -1 if it cannot be found.
   */
  public static int indexByReference(List list, Object obj)
  {
    int index = 0;

    Iterator iter = list.iterator();
    while (iter.hasNext())
    {
      if (iter.next() == obj)
        return index;
      else
        index++;
    }

    return -1;
  }

  /**
   * Calls print on every element of the list; does not put any
   * spaces or other text between the elements.
   *
   * @param list The list to print, which must contain only Printable objects.
   * @param stream The stream on which to print.
   */
  public static void printList(List list, OutputStream stream)
  {
    if (list != null)
    {
      Iterator iter = list.iterator();
      while (iter.hasNext())
        ((Printable)iter.next()).print(stream);
    }
  }

  /**
   * Calls print on every element of the list and prints a newline
   * after each element.
   *
   * @param list The list to print, which must contain only Printable objects.
   * @param stream The stream on which to print.
   */
  public static void printlnList(List list, OutputStream stream)
  {
    if (list == null || list.size() == 0)
      return;

    PrintStream p = new PrintStream(stream);

    Iterator iter = list.iterator();
    while (iter.hasNext())
    {
      ((Printable)iter.next()).print(stream);
      p.println("");
    }
  }

  /**
   * Prints a Printable object to System.err if the
   * verbosity level is greater than min_verbosity.
   *
   * @param p A Printable object.
   * @param min_verbosity An integer to compare with the value
   *   set by the -verbosity command-line flag.
   */
  public static void printlnStatus(Printable p, int min_verbosity)
  {
    if (Integer.valueOf(Driver.getOptionValue("verbosity")).intValue() >= min_verbosity)
    {
      p.print(System.err);
      System.err.println("");
    }
  }

  /**
   * Prints a string to System.err if the
   * verbosity level is greater than min_verbosity.
   *
   * @param message The message to print.
   * @param min_verbosity An integer to compare with the value
   *   set by the -verbosity command-line flag.
   */
  public static void printlnStatus(String message, int min_verbosity)
  {
    if (Integer.valueOf(Driver.getOptionValue("verbosity")).intValue() >= min_verbosity)
      System.err.println(message);
  }

  /**
   * Prints a Printable object to System.err if the
   * verbosity level is greater than min_verbosity.
   *
   * @param p A Printable object.
   * @param min_verbosity An integer to compare with the value
   *   set by the -verbosity command-line flag.
   */
  public static void printStatus(Printable p, int min_verbosity)
  {
    if (Integer.valueOf(Driver.getOptionValue("verbosity")).intValue() >= min_verbosity)
      p.print(System.err);
  }

  /**
   * Prints a string to System.err if the
   * verbosity level is greater than min_verbosity.
   *
   * @param message The message to print.
   * @param min_verbosity An integer to compare with the value
   *   set by the -verbosity command-line flag.
   */
  public static void printStatus(String message, int min_verbosity)
  {
    if (Integer.valueOf(Driver.getOptionValue("verbosity")).intValue() >= min_verbosity)
      System.err.print(message);
  }

  /**
   * Calls print on every element of the list and prints a comma
   * and a space between elements.
   *
   * @param list The list to print, which must contain only Printable objects.
   * @param stream The stream on which to print.
   */
  public static void printListWithCommas(List list, OutputStream stream)
  {
    printListWithSeparator(list, stream, ", ");
  }

  /**
   * Calls print on every element of the list and prints a string between them.
   * If the list has a single element, no separator is printed.
   *
   * @param list The list to print, which must contain only Printable objects.
   * @param stream The stream on which to print.
   * @param separator A string to print between the objects.
   */
  public static void printListWithSeparator(List list, OutputStream stream, String separator)
  {
    if (list == null || list.size() == 0)
      return;

    PrintStream p = new PrintStream(stream);

    Iterator iter = list.iterator();
    if (iter.hasNext())
    {
      ((Printable)iter.next()).print(stream);
      while (iter.hasNext())
      {
        p.print(separator);
        ((Printable)iter.next()).print(stream);
      }
    }
  }

  /**
   * Replaces all instances of expression <var>x</var> on the IR tree
   * beneath <var>t</var> by <i>clones of</i> expression <var>y</var>.
   * Skips the immediate right hand side of member access expressions.
   *
   * @param t The location at which to start the search.
   * @param x The expression to be replaced.
   * @param y The expression to substitute.
   */
  public static void replaceAll(Traversable t, Expression x, Expression y)
  {
    BreadthFirstIterator iter = new BreadthFirstIterator(t);

    for (;;)
    {
      Expression o = null;

      try {
        o = (Expression)iter.next(x.getClass());
      } catch (NoSuchElementException e) {
        break;
      }

      if (o.equals(x))
      {
        if (o.getParent() instanceof AccessExpression
            && ((AccessExpression)o.getParent()).getRHS() == o)
        {
          /* don't replace these */
        }
        else
        {
          if (o.getParent() == null)
            System.err.println("[ERROR] this " + o.toString() + " should be on the tree");

          Expression copy = (Expression)y.clone();
          o.swapWith(copy);

          if (copy.getParent() == null)
            System.err.println("[ERROR] " + y.toString() + " didn't get put on tree properly");
        }
      }
    }
  }

  /**
   * Removes the symbols declared by the declaration from the symbol
   * table.
   *
   * @param table The table from which to remove the symbols.
   * @param decl The declaration of the symbols.
   */
  public static void removeSymbols(SymbolTable table, Declaration decl)
  {
    List names = decl.getDeclaredSymbols();
    Iterator iter = names.iterator();

    HashMap symbol_table = table.getTable();

    while (iter.hasNext())
    {
      IDExpression symbol = (IDExpression)iter.next();

      if (symbol_table.remove(symbol) == null)
      {
        System.err.println("Tools.removeSymbols could not remove entry for " + symbol.toString());
        System.err.println("table contains only " + symbol_table.toString());
      }
    }
  }

  /**
   * Verifies that every element of the list is of the same type.
   *
   * @param list The list to verify.
   * @param type The desired type for all elements.
   * @return true if all elements pass isInstance checks, false otherwise
   */
  public static boolean verifyHomogeneousList(List list, Class type)
  {
    Iterator iter = list.iterator();

    while (iter.hasNext())
    {
      if (!type.isInstance(iter.next()))
        return false;
    }

    return true;
  }

}
