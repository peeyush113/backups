package cetus.transforms;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;

import cetus.analysis.InductionVariable;

import java.util.*;

/**
 * Changes all loops so that they have a single value/variable as their 
 * condition.  This requires that for loops be changed into while loops, 
 * so that initialization and updates can be done outside of the loop 
 * declaration.
 */
public class UniformLoops extends KernelTransformPass
{
  public UniformLoops(Program program)
  {
    super(program);
  }

  public String getPassName()
  {
    return new String("[UniformLoops]");
  }

  public void transformLoop(Loop loop)
  {
    //All loops implement Traversible and Statement, but 
    //we can't access them directly that way, so we cast.
    Traversable loopTree = (Traversable)loop;
    CompoundStatement loopContext = (CompoundStatement)loopTree.getParent();
    CompoundStatement body = (CompoundStatement)loop.getBody();
    Statement loopStmt = (Statement)loop;
    Expression cond = loop.getCondition();
    Identifier newCondition = null;

    
    if(loop instanceof ForLoop)
    {
      //Convert to a while loop
      ForLoop forloop = (ForLoop)loop;
      Statement init = forloop.getInitialStatement();
      forloop.setInitialStatement(null);
      loopContext.addStatementBefore(forloop, init);
      forloop.setBody(null);

      Expression update = forloop.getStep();
      forloop.setStep(null);

      Statement updateStmt = new ExpressionStatement(update);

      body.addStatement(updateStmt);

      
      WhileLoop newloop = new WhileLoop((Expression)cond.clone(), body);

      newloop.swapWith(forloop);

      loop = newloop;
      loopStmt = newloop;
    }
    


    //Okay, at this point, only the condition is in the loop definition
    //Check to see if the condition has any side effects
/*    PostOrderIterator iter = new PostOrderIterator(cond);
    boolean hasSideEffect = false;

    while(iter.hasNext() && !hasSideEffect)
    {
      Expression nextExpr;
      try{
	nextExpr = (Expression)iter.next(Expression.class);
      } catch (NoSuchElementException e) {
	break;
      }
      
      if(nextExpr instanceof FunctionCall ||
	  nextExpr instanceof AssignmentExpression)
      {
	hasSideEffect = true;
      }

      if(nextExpr instanceof UnaryExpression)
      {
	UnaryOperator op = ((UnaryExpression)nextExpr).getOperator();
	if(UnaryOperator.hasSideEffects(op))
	{
	  hasSideEffect = true;
	}
      }
    }	

    if(!hasSideEffect)
      return;
*/
    
    if(loop instanceof WhileLoop)
    {
      WhileLoop whileloop = (WhileLoop)loop;
      newCondition = Tools.getUnusedSymbol(whileloop);
      AssignmentExpression evaluate = 
        new AssignmentExpression(newCondition, 
	    				AssignmentOperator.NORMAL, 
					(Expression)cond.clone() );

    
      ExpressionStatement evalStmt = new ExpressionStatement(evaluate);
    
      body.addStatement(evalStmt);

      whileloop.setCondition((Expression)newCondition.clone());
    
      //Need to add a precondition evaluation if it's a while loop
    
      //Add the declaration to the parent
      VariableDeclarator condDecl = 
        new VariableDeclarator((Identifier)newCondition.clone());

      VariableDeclaration condDeclaration = 
        new VariableDeclaration(Specifier.INT, condDecl);

      DeclarationStatement declStmt = new DeclarationStatement(condDeclaration);

      loopContext.addStatementBefore(loopStmt, declStmt);    
      loopContext.addStatementBefore(whileloop, (Statement)evalStmt.clone());
    }

    if(loop instanceof DoLoop)
    {
      DoLoop doloop = (DoLoop)loop;
      newCondition = Tools.getUnusedSymbol(doloop);
      AssignmentExpression evaluate = 
        new AssignmentExpression(newCondition, 
	    				AssignmentOperator.NORMAL, 
					(Expression)cond.clone() );

    
      ExpressionStatement evalStmt = new ExpressionStatement(evaluate);
    
      body.addStatement(evalStmt);

      doloop.setCondition((Expression)newCondition.clone());
      //Add the declaration to the parent
      VariableDeclarator condDecl = 
        new VariableDeclarator((Identifier)newCondition.clone());

      VariableDeclaration condDeclaration = 
        new VariableDeclaration(Specifier.INT, condDecl);

      DeclarationStatement declStmt = new DeclarationStatement(condDeclaration);

      loopContext.addStatementBefore(loopStmt, declStmt);    
    }

  }

  public void transformProcedure(Procedure proc)
  {
    BreadthFirstIterator iter = new BreadthFirstIterator(proc);

    for (;;)
    {
      Loop loop = null;

      try {
        loop = (Loop)iter.next(Loop.class);
      } catch (NoSuchElementException e) {
        break;
      }

      transformLoop(loop);
    }
  }
}
