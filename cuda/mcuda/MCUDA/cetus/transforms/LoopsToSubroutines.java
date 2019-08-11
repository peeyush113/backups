package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;

/**
 * Extracts all loops of a program into their own subroutines;
 * assumes the SingleDeclarator pass has been run on the program.
 * The subroutines are numbered sequentially such that the
 * first loop of a procedure <var>foo</var> is extracted to
 * <var>foo_L0</var>, the second loop to <var>foo_L1</var>
 * and so forth.  If an extracted loop contains other loops,
 * then those loops are recursively extracted, so for example,
 * <var>foo_L0_L0</var> would be the first inner loop of the
 * first loop of <var>foo</var>.
 */
public class LoopsToSubroutines
{
  private static String pass_name = "[LoopsToSubroutines]";

  private Program program;
  private CallGraph cg;

  private LoopsToSubroutines(Program program)
  {
    this.program = program;
    cg = new CallGraph(program);
  }

  private boolean changeGotoDone(Loop loop)
  {
    boolean changed = false;
    Traversable t = (Traversable)loop;
    BreadthFirstIterator iter = new BreadthFirstIterator(t);
    while (true)
    {
      try {
        GotoStatement g = (GotoStatement)iter.next(GotoStatement.class);
        if (g.toString().equals("goto _done;"))
        {
          changed = true;
          ((CompoundStatement)g.getParent()).addStatementBefore(g,
             new ExpressionStatement(new AssignmentExpression(new Identifier("__early"), AssignmentOperator.NORMAL, new IntegerLiteral(1))));
        }
      } catch (NoSuchElementException e) {
        break;
      }
    }

    return changed;
  }

  private boolean hasGotoDone(Loop loop)
  {
    Traversable t = (Traversable)loop;

    BreadthFirstIterator iter = new BreadthFirstIterator(t);
    while (true)
    {
      try {
        GotoStatement g = (GotoStatement)iter.next(GotoStatement.class);
        if (g.toString().equals("goto _done;"))
          return true;
      } catch (NoSuchElementException e) {
        break;
      }
    }

    return false;
  }

  private void extractLoops(Procedure proc, List loops, boolean outermost)
  {
    Iterator iter = loops.iterator();
    int loop_num = 0;

    SymbolTable global_table = (SymbolTable)proc.getParent();

    boolean immediately_recursive = cg.callsSelf(proc);

    while (iter.hasNext())
    {
      Loop loop = (Loop)iter.next();

      String new_proc_name = proc.getName().toString() + "_L" + loop_num++;

      Tools.printlnStatus(pass_name + " creating new procedure " + new_proc_name, 2);

      /* need to create 2 things: the new procedure where we are moving the
         loop to, and a function call to the new procedure which we will use
         to replace the loop  */

      List<Specifier> new_proc_ret_type = (new ChainedList<Specifier>()).addLink(Specifier.STATIC);

      boolean has_goto_done = false;

      if (outermost)
        has_goto_done = changeGotoDone(loop);
      else
        has_goto_done = hasGotoDone(loop);

      if (has_goto_done)
        new_proc_ret_type.add(Specifier.INT);
      else
        new_proc_ret_type.add(Specifier.VOID);

      Procedure new_proc = new Procedure(new_proc_ret_type,
                                         new ProcedureDeclarator(new Identifier(new_proc_name), new LinkedList(), (List)null),
                                         new CompoundStatement());

      if (immediately_recursive)
      {
        /* need a prototype of the procedure in the extracted loop procedure */
        new_proc.getBody().addDeclaration(new VariableDeclaration((new ChainedList()).addAllLinks(proc.getReturnType()),
          new ProcedureDeclarator((IDExpression)proc.getName().clone(), (new ChainedList()).addAllLinks(proc.getParameters()),
                         new ChainedList())));
      }

      if (outermost && has_goto_done)
      {
        Declarator d = new VariableDeclarator(new Identifier("__early"));
        new_proc.getBody().addDeclaration(new VariableDeclaration(Specifier.INT, d));
        d.setInitializer(new Initializer(new IntegerLiteral(0)));
      }

      FunctionCall call_to_new_proc = new FunctionCall(new Identifier(new_proc_name));

      /* find the variables used inside the loop and also the
         declarations that appear inside the loop */

      Set use_set = DataFlow.getUseSet((Traversable)loop);
      Set def_set = DataFlow.mayDefine((Traversable)loop);
      Set decl_set = getDeclSet((Traversable)loop);

      Tools.printlnStatus(pass_name + " loop use set: " + use_set.toString(), 3);
      Tools.printlnStatus(pass_name + " loop def set: " + def_set.toString(), 3);

      /* fill in the parameter list of the new procedure and
         the argument list of the new call */

      Iterator i = use_set.iterator();
      while (i.hasNext())
      {
        IDExpression expr = (IDExpression)i.next();
        Declaration decl = expr.findDeclaration();

        /* Global variables in the use or def sets do not need passed
           into the new procedure because they are already accessible. */
        if (global_table.findSymbol(expr) == decl)
          continue;

        /* if this is not a structure member and
           if this is not a variable declared inside the loop */
        if (decl != null && !decl_set.contains(decl))
        {
          VariableDeclaration cloned_decl = (VariableDeclaration)decl.clone();
          Expression cloned_expr = (Expression)expr.clone();

          /* Don't want static variables passed as static parameters
             because static isn't allowed in parameter lists.  The while
             loop is here to remove all instances of static (although it
             would be weird to have more than one, it is legal). */
          while (cloned_decl.getSpecifiers().remove(Specifier.STATIC));

          /* Remove any initializers.  We assume the SingleDeclarator pass
             was previously run so there is exactly one Declarator here. */
          cloned_decl.getDeclarator(0).setInitializer(null);

          /* Need to pass as pointers variables redefined by the loop
             and struct variables.  A consequence is expr's in the arg list
             need to be &expr and uses of the variables need modified. */
          if (def_set.contains(cloned_expr)
              || (isStructure(cloned_decl) && !isPointer(cloned_decl) && !isPointer(cloned_decl.getDeclarator(0))))
          {
            /* FIXME: This should really go on the declarator, but right now that
               doesn't seem to work and this does work. */
            cloned_decl.getSpecifiers().add(PointerSpecifier.UNQUALIFIED);
           
            /* Need to pass the address of the variable. */ 
            UnaryExpression address_of = new UnaryExpression(UnaryOperator.ADDRESS_OF, cloned_expr);
            address_of.setParens(false);
            cloned_expr = address_of;

            /* Inside the extracted loop we must dereference the variables
               that we have turned into pointers.  Structures are also
               handled by this since (*s).x is equivalent to s->x */
            UnaryExpression deref = new UnaryExpression(UnaryOperator.DEREFERENCE, (Expression)expr.clone());
            Tools.replaceAll((Traversable)loop, expr, deref);
          }          

          new_proc.addDeclaration(cloned_decl);
          call_to_new_proc.addArgument(cloned_expr);
        }
      }

      /* Put call_to_new_proc inside new_proc and then
         swap it with the loop.  The call will end up where the loop
         was and the loop will end up in the new procedure. */
      Statement stmt = null;
      if (has_goto_done)
        stmt = new IfStatement(call_to_new_proc, new GotoStatement(new Identifier("_done")));
      else
        stmt = new ExpressionStatement(call_to_new_proc);

      new_proc.getBody().addStatement(stmt);
      stmt.swapWith((Statement)loop);

      new_proc.getBody().addStatement(new Label(new Identifier("_done")));
      if (has_goto_done)
      {
        VariableDeclaration vdec = (VariableDeclaration)new_proc.getBody().findSymbol(new Identifier("__early"));
        if (isPointer(vdec) || isPointer(vdec.getDeclarator(0)))
          new_proc.getBody().addStatement(new ReturnStatement(new UnaryExpression(UnaryOperator.DEREFERENCE, new Identifier("__early"))));
        else
          new_proc.getBody().addStatement(new ReturnStatement(new Identifier("__early")));
      }
      else
        new_proc.getBody().addStatement(new ReturnStatement());
            
      /* put new_proc before the calling proc (avoids prototypes) */
      ((TranslationUnit)proc.getParent()).addDeclarationBefore(proc, new_proc);

      /* Recursively extract inner loops from the new procedure.
         Recursively extracting the outer loop would lead to infinite
         recursion, so we need to find the outer loops of the *body*
         of the current loop. */
      extractLoops(new_proc, findOuterLoops(loop.getBody()), false);
    }
  }

  /**
   * Finds all outer loops at a given level of IR.
   *
   * @return a list of loops
   */
  private List findOuterLoops(Traversable root)
  {
    LinkedList<Loop> loop_list = new LinkedList<Loop>();

    DepthFirstIterator iter = new DepthFirstIterator(root);
    iter.pruneOn(Loop.class);

    for (;;)
    {
      Loop loop = null;

      try {
        loop = (Loop)iter.next(Loop.class);
      } catch (NoSuchElementException e) {
        break;
      }

      loop_list.add(loop);
    }

    return loop_list;
  }

  private Set getDeclSet(Traversable root)
  {
    HashSet<Declaration> set = new HashSet<Declaration>();

    BreadthFirstIterator iter = new BreadthFirstIterator(root);

    for (;;)
    {
      Declaration decl = null;

      try {
        decl = (Declaration)iter.next(Declaration.class);
      } catch (NoSuchElementException e) {
        break;
      }

      set.add(decl);
    }

    return set;
  }

  private boolean isPointer(VariableDeclaration vdec)
  {
    Iterator iter = vdec.getSpecifiers().iterator();
    while (iter.hasNext())
    {
      if (iter.next() instanceof PointerSpecifier)
        return true;
    }

    return false;
  }

  private boolean isPointer(Declarator decl)
  {
    Iterator iter = decl.getSpecifiers().iterator();
    while (iter.hasNext())
    {
      if (iter.next() instanceof PointerSpecifier)
        return true;
    }

    return false;
  }

  private boolean isStructure(VariableDeclaration decl)
  {
    Iterator iter = decl.getSpecifiers().iterator();
    while (iter.hasNext())
    {
      Specifier spec = (Specifier)iter.next();
      if (spec instanceof UserSpecifier)
      {
        if (((UserSpecifier)spec).isStructure())
          return true;

        /* temp hack for f2c structure that is a typedef */
        if (spec.toString().equals("doublecomplex"))
          return true;
      }
    }

    return false;
  }

  public static void run(Program program)
  {
    Tools.printlnStatus(pass_name + " begin", 1);

    LoopsToSubroutines pass = new LoopsToSubroutines(program);
    pass.start();

    Tools.printlnStatus(pass_name + " end", 1);
  }

  private void start()
  {
    HashSet skip_set = Driver.getSkipProcedureSet();

    BreadthFirstIterator iter = new BreadthFirstIterator(program);
    iter.pruneOn(Procedure.class);

    for (;;)
    {
      Procedure proc = null;

      try {
        proc = (Procedure)iter.next(Procedure.class);
      } catch (NoSuchElementException e) {
        break;
      }

      String name = proc.getName().toString();

      if (!skip_set.contains(name))
      {
        Tools.printlnStatus(pass_name + " examining procedure " + name, 2);

        List loops = findOuterLoops(proc);
        if (!loops.isEmpty())
          extractLoops(proc, loops, true);
      }
      else
        Tools.printlnStatus(pass_name + " skipping procedure " + name, 2);
    }
  }
}
