package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.hir.*;

/**
 * Transforms a program such that every declaration contains
 * at most one declarator.  The declarations are kept in order,
 * so for example "int x, y, z;" becomes "int x; int y; int z;"
 */
public class SingleDeclarator
{
  private static String pass_name = "[SingleDeclarator]";

  private Program program;

  private SingleDeclarator(Program program)
  {
    this.program = program;
  }

  private void eliminateMultipleDeclarators(VariableDeclaration decl)
  {
    Tools.printStatus(pass_name + " eliminating multiples in ", 3);
    Tools.printlnStatus(decl, 3);

    DeclarationStatement stmt = (DeclarationStatement)decl.getParent();
    SymbolTable outer = (SymbolTable)stmt.getParent();

    VariableDeclaration placeholder = new VariableDeclaration(new LinkedList());
    outer.addDeclarationAfter(decl, placeholder);

    stmt.detach();

    for (int i = decl.getNumDeclarators() - 1; i >= 0; --i)
    {
      Declarator d = decl.getDeclarator(i);

      outer.addDeclarationAfter(placeholder,
        new VariableDeclaration(decl.getSpecifiers(), (Declarator)d.clone()));
    }

    ((DeclarationStatement)placeholder.getParent()).detach();
  }

  public static void run(Program program)
  {
    Tools.printlnStatus(pass_name + " begin", 1);

    SingleDeclarator pass = new SingleDeclarator(program);
    pass.start();

    Tools.printlnStatus(pass_name + " end", 1);
  }

  private void start()
  {
    DepthFirstIterator i = new DepthFirstIterator(program);

    Set<Class> set = new HashSet<Class>();
    set.add(Procedure.class);
    set.add(VariableDeclaration.class);

    for (;;)
    {
      Procedure proc = null;
      VariableDeclaration decl = null;

      try {
        Object o = i.next(set);
        if (o instanceof Procedure)
          proc = (Procedure)o;
        else
          decl = (VariableDeclaration)o;
      } catch (NoSuchElementException e) {
        break;
      }

      if (proc != null)
      {
        Tools.printlnStatus(pass_name + " examining procedure " + proc.getName(), 2);
      }
      else  
      {
        if (decl.getNumDeclarators() > 1)
          eliminateMultipleDeclarators(decl);
      }
    }
  }
}
