package cetus.transforms;

import cetus.hir.*;
import java.util.*;

/**
 * Searches for small functions that can be inlined
 * and inlines their code into the call site.
 */
public class Inline
{
  private static String pass_name = "[Inline]";

  /**
   * John A. Stratton
   * For derivative classes, it makes sense to have the program be protected
   */
  protected Program program;
  private int threshold;

  public Inline(Program program, int threshold)
  {
    this.program = program;
    this.threshold = threshold;
  }

  private HashSet<String> findInlineCandidates()
  {
    HashSet<String> candidates = new HashSet<String>();

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

      if (proc.getBody().countStatements() < threshold)
        candidates.add(proc.getName().toString());
    }

    return candidates;
  }

  protected void inlineCall(FunctionCall call)
  {
    /* get the Procedure object for the call */
    Procedure proc = call.getProcedure();

    /* check that the number of arguments == number of params */
    if (call.getNumArguments() != proc.getNumParameters())
    {
      System.err.println(pass_name + " call to procedure " + proc.getName().toString()
        + " appears to have an incorrect number of arguments");
      return;
    }

    /* clone the body of the Procedure object */
    CompoundStatement inlined_code = (CompoundStatement)proc.getBody().clone();

    /* iterate over inline_code, find a use of a parameter, and replace
       it with its corresponding argument */
    List params = proc.getParameters();
    List args = call.getArguments();
    int n = call.getNumArguments();

    for (int i = 0; i < n; ++i)
      Tools.replaceAll(inlined_code, (IDExpression)((VariableDeclaration)params.get(i)).getDeclaredSymbols().get(0), (Expression)args.get(i));

    /* insert the body into the call site before the call */
    Traversable t = call;
    while (!(t instanceof Statement))
      t = t.getParent();
    Statement stmt = (Statement)t;

    ((CompoundStatement)stmt.getParent()).addStatementBefore(stmt, inlined_code);

    if (call.getParent() instanceof BinaryExpression
        || call.getParent() instanceof FunctionCall)
    {
      /* Case 1: x = foo(); x = foo() + y; bar(foo()); */

      /* TODO: make sure that the single return pass has been run so that
         there is only one return and there is a return variable */

      /* get the name of the return variable and replace the call
         with a copy */
      ReturnStatement ret = (ReturnStatement)(new BreadthFirstIterator(inlined_code)).next(ReturnStatement.class);
      Expression ret_var = ret.getExpression();

      call.swapWith((Expression)ret_var.clone());

      /* TODO: move the declaration of the return variable to before the
         inlined_code */

      /* find the declaration of the return variable */
      Declaration decl = Tools.findSymbol(inlined_code, (IDExpression)ret_var);

      DeclarationStatement decl_stmt = (DeclarationStatement)decl.getParent();

      decl_stmt.detach();

      ((CompoundStatement)inlined_code.getParent()).addDeclaration(decl);
    }
    else
    {
      /* Case 2: foo(); */

      /* eliminate the call */
      stmt.detach();
    }

    /* eliminate any ReturnStatements from inlined_code */
    DepthFirstIterator inline_iter = new DepthFirstIterator(inlined_code);
    inline_iter.pruneOn(ReturnStatement.class);

    for (;;)
    {
      ReturnStatement ret = null;

      try {
        ret = (ReturnStatement)inline_iter.next(ReturnStatement.class);
      } catch (NoSuchElementException e) {
        break;
      }

      ret.detach();
    }
  }

  public static void run(Program program, int threshold)
  {
    Tools.printlnStatus(pass_name + " begin", 1);
    (new Inline(program, threshold)).start();
    Tools.printlnStatus(pass_name + " end", 1);
  }

  public void start()
  {
    HashSet<String> candidates = findInlineCandidates();

    DepthFirstIterator iter = new DepthFirstIterator(program);

    for (;;)
    {
      FunctionCall call = null;

      try {
        call = (FunctionCall)iter.next(FunctionCall.class);
      } catch (NoSuchElementException e) {
        break;
      }

      if (candidates.contains(call.getName().toString()))
        inlineCall(call);
    }
  }
}
