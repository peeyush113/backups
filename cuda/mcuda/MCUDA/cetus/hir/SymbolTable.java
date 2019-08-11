package cetus.hir;

import java.util.*;

public interface SymbolTable
{
  /**
   * Add a declaration to the end of the set of declarations
   * and place the declared symbols in the symbol table.
   *
   * @param decl The declaration to add.
   */
  void addDeclaration(Declaration decl);

  /**
   * Add a declaration before the reference declaration.
   *
   * @param ref The reference point.
   * @param decl The declaration to add.
   */
  void addDeclarationBefore(Declaration ref, Declaration decl);

  /**
   * Add a declaration after the reference declaration.
   *
   * @param ref The reference point.
   * @param decl The declaration to add.
   */
  void addDeclarationAfter(Declaration ref, Declaration decl);

  /**
   * Retrieves the declaration for a symbol, possibly searching
   * through parent symbol tables.
   *
   * @param name The name of the symbol.
   */
  Declaration findSymbol(IDExpression name);

  /**
   * Returns a list of symbol tables that are parents
   * of this table in the distributed symbol table graph.
   * A list is necessary because representing multiple
   * inheritence in C++ requires it.  Note that the parent
   * tables are not necessarily tables of the immediate
   * parent.  The list is all symbol tables enclosing this
   * object which appear at the same level such that no
   * other symbol tables appear between this object and
   * those tables.
   *
   * @return a List of SymbolTables.
   */
  List getParentTables();

  /**
   * Provides direct access to the symbol table;
   * it's generally not a good idea to modify this directly.
   *
   * @return a map of IDExpressions to Declarations.
   */
  HashMap getTable();
}
