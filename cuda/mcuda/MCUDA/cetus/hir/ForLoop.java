package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.InductionVariable;

public class ForLoop extends Statement implements Loop, SymbolTable
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ForLoop.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private HashMap symbol_table;

  public ForLoop(Statement init, Expression condition,
                 Expression step, Statement body)
  {
    super(4);

    object_print_method = class_print_method;
    symbol_table = new HashMap(4);

    children.add(null);
    children.add(null);
    children.add(null);
    children.add(new CompoundStatement());

    setInitialStatement(init);
    setCondition(condition);
    setStep(step);
    setBody(body);
  }

  public void addDeclaration(Declaration decl)
  {
    ((CompoundStatement)getBody()).addDeclaration(decl);
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
  }

  /**
   * Prints a loop to a stream.
   *
   * @param loop The loop to print.
   * @param stream The stream on which to print the loop.
   */
  public static void defaultPrint(ForLoop loop, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("for (");

    if (loop.getInitialStatement() != null)
    {
      loop.getInitialStatement().print(stream);
      p.print(" ");
    }
    else
      p.print("; ");
   
    if (loop.getCondition() != null)
      loop.getCondition().print(stream);
 
    p.print("; ");

    if (loop.getStep() != null)
      loop.getStep().print(stream);

    p.println(")");

    loop.getBody().print(stream);
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public Statement getBody()
  {
    return (Statement)children.get(3);
  }

  public Expression getCondition()
  {
    return (Expression)children.get(1);
  }

  public Statement getInitialStatement()
  {
    return (Statement)children.get(0);
  }

  public List getParentTables()
  {
    return Tools.getParentTables(this);
  }

  public Expression getStep()
  {
    return (Expression)children.get(2);
  }

  public HashMap getTable()
  {
    return symbol_table;
  }

  public InductionVariable identifyPrimaryInductionVariable()
  {
    InductionVariable ivar = new InductionVariable();

    /* determine the name of the induction variable and the step */

    Expression step_expr = getStep();

    if (step_expr instanceof AssignmentExpression)
    {
      ivar.variable = (Expression)((AssignmentExpression)step_expr).getLHS().clone();
      ivar.step = (new Integer(((AssignmentExpression)step_expr).getRHS().toString())).intValue();
    }
    else if (step_expr instanceof UnaryExpression)
    {
      UnaryExpression uexpr = (UnaryExpression)step_expr;

      ivar.variable = (Expression)uexpr.getExpression().clone();

      UnaryOperator op = uexpr.getOperator();
      if (op == UnaryOperator.PRE_INCREMENT ||
          op == UnaryOperator.POST_INCREMENT)
        ivar.step = 1;
      else
        ivar.step = -1;
    }

    /* determine starting and ending bounds */

    Statement stmt = getInitialStatement();

    if (stmt instanceof DeclarationStatement)
    {
      Initializer init = ((VariableDeclaration)((DeclarationStatement)stmt).getDeclaration()).getDeclarator(0).getInitializer();
      ivar.lower_bound = (new Integer(init.toString())).intValue();
    }
    else // ExpressionStatement
    {
      Expression expr = ((AssignmentExpression)((ExpressionStatement)stmt).getExpression()).getRHS();
      ivar.lower_bound = (new Integer(expr.toString())).intValue();
    }

    BinaryExpression cond_expr = (BinaryExpression)getCondition();
    BinaryOperator op = cond_expr.getOperator();

    if (op == BinaryOperator.COMPARE_LT)
      ivar.upper_bound = (new Integer(cond_expr.getRHS().toString())).intValue() - ivar.step;
    else if (op == BinaryOperator.COMPARE_LE)
      ivar.upper_bound = (new Integer(cond_expr.getRHS().toString())).intValue();

    return ivar;
  }

  public void setBody(Statement body)
  {
    if (getBody() != null)
      getBody().setParent(null);

    if (body == null)
    {
      body = new CompoundStatement();
    }
    else if (!(body instanceof CompoundStatement))
    {
      CompoundStatement cs = new CompoundStatement();
      cs.addStatement(body);
      body = cs;
    }

    children.set(3, body);
    body.setParent(this);
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

  public void setCondition(Expression cond)
  {
    if (getCondition() != null)
      getCondition().setParent(null);

    children.set(1, cond);

    if (cond != null)
    {
      cond.setParent(this);
      cond.setParens(false);
    }
  }

  public void setInitialStatement(Statement stmt)
  {
    if (getInitialStatement() != null)
      getInitialStatement().setParent(null);

    children.set(0, stmt);

    if (stmt != null)
    {
      stmt.setParent(this);
      if (stmt instanceof DeclarationStatement)
      {
        Declaration decl = ((DeclarationStatement)stmt).getDeclaration();
        Tools.addSymbols(this, decl);
      }
    }
  }

  public void setStep(Expression step)
  {
    if (getStep() != null)
      getStep().setParent(null);

    children.set(2, step);

    if (step != null)
    {
      step.setParent(this);
      step.setParens(false);
    }
  }
}
