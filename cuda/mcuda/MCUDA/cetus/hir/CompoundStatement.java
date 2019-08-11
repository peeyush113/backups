package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Represents a group of statements that are treated as a single
 * statement.
 */
public class CompoundStatement extends Statement implements SymbolTable
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = CompoundStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /** Maps IDExpressions to Declarations. */
  private HashMap symbol_table;

  /**
   * Creates an empty compound statement.
   */
  public CompoundStatement()
  {
    object_print_method = class_print_method;

    symbol_table = new HashMap(4);
  }

  /**
   * Adds a declaration after the last declaration; this models
   * the C language's requirement that all declarations appear
   * at the beginning of a block.
   *
   * @param decl The declaration to add.
   */
  /**
   * John A. Stratton
   * Actually, the more relaxed ordering is more typical programming 
   * style, and is allowed in CUDA, so to get a broader support, 
   * it needs to be done this way.
   */
  public void addDeclaration(Declaration decl)
  {
    DeclarationStatement stmt = new DeclarationStatement(decl);

    int i = 0;
    int size = children.size();

    //while (i < size && children.get(i) instanceof DeclarationStatement)
    //  i++;

    //children.add(i, stmt);
    children.add(stmt);
    stmt.setParent(this);

    Tools.addSymbols(this, decl);
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref.getParent());

    if (index == -1)
      throw new IllegalArgumentException();

    DeclarationStatement stmt = new DeclarationStatement(decl);
    children.add(index, stmt);
    stmt.setParent(this);

    Tools.addSymbols(this, decl);
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref.getParent());

    if (index == -1)
      throw new IllegalArgumentException();

    DeclarationStatement stmt = new DeclarationStatement(decl); 
    children.add(index + 1, stmt);
    stmt.setParent(this);

    Tools.addSymbols(this, decl);
  }

  /**
   * Adds a statement to the end of this compound statement.
   *
   * @param stmt The statement to add.
   */
  public void addStatement(Statement stmt)
  {
    children.add(stmt);
    stmt.setParent(this);

    if (stmt instanceof DeclarationStatement)
    {
      Declaration decl = ((DeclarationStatement)stmt).getDeclaration();
      Tools.addSymbols(this, decl);
    }
  }  

  /**
   * Add a new Statement Before this Statement
   *
   * @param new_stmt The Statement to be added
   * @param ref_stmt Reference point
   */
  public void addStatementBefore(Statement ref_stmt, Statement new_stmt)
  {
    int index = Tools.indexByReference(children, ref_stmt);

    if (index == -1)
      throw new IllegalArgumentException();

    children.add(index, new_stmt);
    new_stmt.setParent(this);

    if (new_stmt instanceof DeclarationStatement)
      Tools.addSymbols(this, ((DeclarationStatement)new_stmt).getDeclaration());
  }

  /**
   * Add a new Statement After this Statement
   *
   * @param new_stmt The Statement to be added
   * @param ref_stmt Reference point
   */
  public void addStatementAfter(Statement ref_stmt, Statement new_stmt)
  {
    int index = Tools.indexByReference(children, ref_stmt);

    if (index == -1)
      throw new IllegalArgumentException();

    children.add(index + 1, new_stmt);		
    new_stmt.setParent(this);

    if (new_stmt instanceof DeclarationStatement)
      Tools.addSymbols(this, ((DeclarationStatement)new_stmt).getDeclaration());
  }

  public Object clone()
  {
    CompoundStatement o = (CompoundStatement)super.clone();

    /* the Java Object.clone makes a shallow copy of the map, which is wrong */
    symbol_table.clear();

    /* use a flat iterator to find declarations and put them in the table */
    FlatIterator iter = new FlatIterator(o);

    for (;;)
    {
      DeclarationStatement decl_stmt = null;

      try {
        decl_stmt = (DeclarationStatement)iter.next(DeclarationStatement.class);
      } catch (NoSuchElementException e) {
        break;
      }

      Declaration decl = decl_stmt.getDeclaration();

      Tools.addSymbols(o, decl);
    }

    return o;
  }

  /**
   * Returns the total number of Statements contained within
   * this CompoundStatement.
   *
   * @return the number of statements within this compound statement
   */
  public int countStatements()
  {
    int n = 0;

    FlatIterator iter = new FlatIterator(this);

    for (;;)
    {
      Statement stmt = null;

      try {
        stmt = (Statement)iter.next(Statement.class);
      } catch (NoSuchElementException e) {
        break;
      } 

      if (stmt instanceof IfStatement)
      {
	//John A. Stratton: February 2008
	//Caused a null pointer exception in cases where the else 
	//case didn't exist
//        int then_count = ((CompoundStatement)((IfStatement)stmt).getThenStatement()).countStatements();
//        int else_count = ((CompoundStatement)((IfStatement)stmt).getElseStatement()).countStatements();

	Statement thenStmt = (((IfStatement)stmt).getThenStatement());
	Statement elseStmt = (((IfStatement)stmt).getElseStatement());
	int then_count = 0;
	int else_count = 0;
	if(thenStmt != null)
	{
	  if(thenStmt instanceof CompoundStatement)
	    then_count = ((CompoundStatement)thenStmt).countStatements();
	  else
	    then_count = 1;
	}

	if(elseStmt != null)
	{
	  if(elseStmt instanceof CompoundStatement)
	    else_count = ((CompoundStatement)elseStmt).countStatements();
	  else
	    else_count = 1;
	}

        if (then_count > else_count)
          n += then_count;
        else
          n += else_count;
      }
      else if (stmt instanceof CompoundStatement)
        n += ((CompoundStatement)stmt).countStatements();
      else
        ++n;
    }

    return n;
  }

  /**
   * Prints a statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(CompoundStatement stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.println("{");
    Tools.printlnList(stmt.children, stream);
    p.println("}");
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public List getParentTables()
  {
    return Tools.getParentTables(this);
  }

  public HashMap getTable()
  {
    return symbol_table;
  }

  public void removeChild(Traversable child)
  {
    int index = Tools.indexByReference(children, child);

    if (index == -1)
      throw new IllegalArgumentException();
    
    children.remove(index);
    child.setParent(null);

    if (child instanceof DeclarationStatement)
      Tools.removeSymbols(this, ((DeclarationStatement)child).getDeclaration());
  }
}
