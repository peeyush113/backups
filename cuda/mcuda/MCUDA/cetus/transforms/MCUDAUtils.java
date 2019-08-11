package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;
import cetus.base.grammars.Pragma;

/* Utility functions for MCUDA transformations */

public class MCUDAUtils
{
  public static int __NUM_DIMS = 3;

  public static String getTIDString()
  {
    return new String("threadIdx");
  }

  public static String getParamsString()
  {
    return new String("__params");
  }

  public static String getBDIMString()
  {
    return new String("blockDim");
  }

  public static String getGDIMString()
  {
    return new String("gridDim");
  }

  public static String getBIDXString()
  {
    return new String("blockIdx");
  }

  public static String getLocalTIDString()
  {
    return new String("__threadIndex");
  }

  public static List getTidID()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add( new Identifier(getTIDString()) );
    }
    else {
      //Non-recursive
      retval.add( getTidID(0) );
      retval.add( getTidID(1) );
      retval.add( getTidID(2) );
    }

    return retval;
  }

  public static Expression getTidID(int entry)
  {
    if(Driver.getOptionValue("Xpilot") == null)
    {
      return new AccessExpression((Identifier)getTidID().get(0), 
	  		AccessOperator.MEMBER_ACCESS,
		 	new Identifier(getDimEntry(entry)));
    }
    else {
      return new Identifier( 
	  (getTIDString() + "_" + getDimEntry(entry)));
    }
  }

  public static Identifier getParamsID()
  {
    return new Identifier(getParamsString());
  }

  public static List getBdimID()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add( new Identifier(getBDIMString()) );
    }
    else {
      //Non-recursive
      retval.add( getBdimID(0) );
      retval.add( getBdimID(1) );
      retval.add( getBdimID(2) );
    }

    return retval;
  }

  public static Expression getBdimID(int entry)
  {
    if(Driver.getOptionValue("Xpilot") == null)
    {
      return new AccessExpression((Identifier)getBdimID().get(0), 
	  		AccessOperator.MEMBER_ACCESS,
		 	new Identifier(getDimEntry(entry)));
    }
    else {
      return new Identifier( 
	  (getBDIMString() + "_" + getDimEntry(entry)));
    }
  }
  
  public static List getGdimID()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add( new Identifier(getGDIMString()) );
    }
    else {
      //Non-recursive
      retval.add( getGdimID(0) );
      retval.add( getGdimID(1) );
    }

    return retval;
  }

  public static Expression getGdimID(int entry)
  {
    if(Driver.getOptionValue("Xpilot") == null)
    {
      return new AccessExpression((Identifier)getGdimID().get(0), 
	  		AccessOperator.MEMBER_ACCESS,
		 	new Identifier(getDimEntry(entry)));
    }
    else {
      return new Identifier( 
	  (getGDIMString() + "_" + getDimEntry(entry)));
    }
  }

  public static List getBidxID()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add( new Identifier(getBIDXString()) );
    }
    else {
      //Non-recursive
      //2-D only
      retval.add( getBidxID(0) );
      retval.add( getBidxID(1) );
    }

    return retval;
  }

  public static Expression getBidxID(int entry)
  {
    if(Driver.getOptionValue("Xpilot") == null)
    {
      return new AccessExpression((Identifier)getBidxID().get(0), 
	  		AccessOperator.MEMBER_ACCESS,
		 	new Identifier(getDimEntry(entry)));
    }
    else {
      return new Identifier( 
	  (getBIDXString() + "_" + getDimEntry(entry)));
    }
  }
  
  public static Identifier getLocalTID()
  {
    return new Identifier(getLocalTIDString());
  }

  public static String getDimEntry(int idx)
  {
    if(idx == 0)
      return new String("x");
    else if (idx == 1)
      return new String("y");
    else if (idx == 2)
      return new String("z");
    else 
      throw new UnsupportedOperationException("3-D dimensions only");
  }
 
  public static String getDim3String()
  {
    return new String("dim3");
  }

  public static Identifier getDim3ID()
  {
    return new Identifier(getDim3String());
  }

  public static UserSpecifier getDim3Type()
  {
    return new UserSpecifier(getDim3ID());
  }

  public static List getTidDecl()
  {   
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add(new VariableDeclaration(getDim3Type(), 
	             new VariableDeclarator((Identifier)getTidID().get(0))));
    }
    else {
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getTidID(0))));
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getTidID(1))));
      retval.add(new VariableDeclaration(Specifier.INT,
    			new VariableDeclarator((Identifier)getTidID(2))));
    }

    return retval;
  }

  public static List<VariableDeclaration> getBidxDecl()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add(new VariableDeclaration(getDim3Type(),
                     new VariableDeclarator((Identifier)getBidxID().get(0))));
    }
    else {
      //BlockIDs are only 2-D
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getBidxID(0))));
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getBidxID(1))));
    }

    return retval;
  }

  public static List<VariableDeclaration> getBdimDecl()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add(new VariableDeclaration(getDim3Type(),
                     new VariableDeclarator((Identifier)getBdimID().get(0))));
    }
    else {
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getBdimID(0))));
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getBdimID(1))));
      retval.add(new VariableDeclaration(Specifier.INT,
    			new VariableDeclarator((Identifier)getBdimID(2))));
    }

    return retval;
  }

  public static List<VariableDeclaration> getGdimDecl()
  {
    List retval = new ChainedList();
    if(Driver.getOptionValue("Xpilot") == null)
    {
      retval.add(new VariableDeclaration(getDim3Type(),
	             new VariableDeclarator((Identifier)getGdimID().get(0))));
    }
    else {
      //Grids are only 2-D
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getGdimID(0))));
      retval.add(new VariableDeclaration(Specifier.INT,
	    		new VariableDeclarator((Identifier)getGdimID(1))));
    }

    return retval;
  }

  public static Expression getMaxNumThreads()
  {
    return new IntegerLiteral(512);
  }
 
  
  public static List<VariableDeclaration> getKernelParams()
  {
    List paramList = new ChainedList();
    VariableDeclarator params = new VariableDeclarator(getParamsID());
    List paramsType = new ChainedList();
    paramsType.add(Specifier.CONST);
    paramsType.add(Specifier.VOID);
    paramsType.add(PointerSpecifier.UNQUALIFIED);
    VariableDeclaration paramDecl; 
   
    if(Driver.getOptionValue("mcuda_nolib") == null)
    {
      paramDecl = new VariableDeclaration(paramsType, params);
      paramList.add(paramDecl);
    }
    
    paramList.addAll(getBidxDecl());
    paramList.addAll(getBdimDecl());
    paramList.addAll(getGdimDecl());

    return paramList;
  }

  public static FunctionCall getSync()
  {
    Identifier syncName = new Identifier("__syncthreads");
    
    FunctionCall syncCall = new FunctionCall(syncName);

    return syncCall;
  }

  public static boolean isThreadLoopBody(CompoundStatement stmt)
  {
    //Look for a loop annotation.  Must be a direct child 
    //of the compound statement.
    FlatIterator iter = new FlatIterator(stmt);

    while(iter.hasNext())
    {
      DeclarationStatement loopMarkStmt;
      Annotation loopMark;
      
      try{
	loopMarkStmt = 
	  (DeclarationStatement)iter.next(DeclarationStatement.class);
      } catch (NoSuchElementException e) {
	break;
      }

      if(loopMarkStmt.getDeclaration() instanceof Annotation)
      {
	loopMark = (Annotation)loopMarkStmt.getDeclaration();
        if(loopMark.getText().compareTo("__MCUDA_THREAD_BODY") == 0)
	  return true;
      }
    }
    return false;
  }

  public static boolean isThreadLoop(ForLoop loop)
  {
    //Look for a loop annotation.  Must be a direct child 
    //of the compound statement.
    
    FlatIterator iter = new FlatIterator(loop.getBody());
    while(iter.hasNext())
    {
      DeclarationStatement loopMarkStmt;
      Annotation loopMark;
      
      try{
	loopMarkStmt = 
	  (DeclarationStatement)iter.next(DeclarationStatement.class);
      } catch (NoSuchElementException e) {
	break;
      }
      
      if(loopMarkStmt.getDeclaration() instanceof Annotation)
      {
	loopMark = (Annotation)loopMarkStmt.getDeclaration();
        if(loopMark.getText().compareTo("__MCUDA_OUTER_LOOP") == 0)
	  return true;
      }
    }
    return false;
  }


    
  public static CompoundStatement getThreadLoopBody(Traversable node)
  {
    while(node.getParent() != null)
    {
      node = node.getParent();
      if(node instanceof CompoundStatement)
      {
	if(isThreadLoopBody((CompoundStatement)node))
	{
	  return (CompoundStatement)node;
	}
      }
    }

    return null;
  }
      
  public static ForLoop getOuterThreadLoop(Traversable node)
  {
    while(node.getParent() != null)
    {
      node = node.getParent();
      if(node instanceof ForLoop)
      {
	if(isThreadLoop((ForLoop)node))
	{
	  return (ForLoop)node;
        }
      }
    }

    return null;
  }

  public static List<CompoundStatement> GetThreadBlocks(Traversable root)
  {
    List<CompoundStatement> blocks = new ChainedList();
    
    DepthFirstIterator iter = new DepthFirstIterator(root);

    while(iter.hasNext())
    {
      CompoundStatement block = null;
      
      try{
	block = (CompoundStatement)iter.next(CompoundStatement.class);
      } catch (NoSuchElementException e) {
	break;
      }

      if(isThreadLoopBody(block))
      {
	blocks.add(block);
      }
    }

    return blocks;

  }
  
  public static ForLoop NewNestedThreadLoop(int threadDim,
			CompoundStatement body)
  {
    Annotation threadLoop = new Annotation("__MCUDA_THREAD_BODY");
    threadLoop.setPrintMethod(Annotation.print_as_comment_method);
    body.addDeclaration(threadLoop);
    Statement prev = body;
    
    for(int i = 0; i < threadDim; i++)
    {

      // Put together the initialization
      //Identifier tid = getTidID();
      //Identifier element = new Identifier(getDimEntry(i));
      
      Expression tidAccess = getTidID(i);
      
      Expression assignTid = 
	  new AssignmentExpression(tidAccess, AssignmentOperator.NORMAL, 
	      				new IntegerLiteral((long)0));

      if(i == threadDim - 1)
      {
	//Outermost loop.  Also initialze the local thread ID
	AssignmentExpression assignLocalTid = 
	  new AssignmentExpression(MCUDAUtils.getLocalTID(), 
	      				AssignmentOperator.NORMAL, 
					new IntegerLiteral(0));
	List expressions = new ChainedList();
	expressions.add(assignTid);
	expressions.add(assignLocalTid);
	CommaExpression totalAssign = new CommaExpression(expressions);
        assignTid = totalAssign;
      }
	
      ExpressionStatement assignTidStmt = new ExpressionStatement(assignTid);


      //Put together the comparison
      Expression bdimAccess = getBdimID(i);

      BinaryExpression tidComp = 
	  new BinaryExpression((Expression)tidAccess.clone(), 
	     				BinaryOperator.COMPARE_LT, 
	      				bdimAccess);
      
      //Put together the update
      Expression tidUpdate = 
	  new UnaryExpression(UnaryOperator.POST_INCREMENT, 
	      			(Expression)tidAccess.clone());
      
      if(i == 0)
      {
	//Innermost loop, also update the local thread index
	UnaryExpression localTidUpdate = 
	  new UnaryExpression(UnaryOperator.POST_INCREMENT, 
	      			MCUDAUtils.getLocalTID());
	//ExpressionStatement localUpdateStmt = 
	//  new ExpressionStatement(localTidUpdate);
	//((CompoundStatement)prev).addStatement(localUpdateStmt);
	
	List expressions = new ChainedList();
	expressions.add(tidUpdate);
	expressions.add(localTidUpdate);
	CommaExpression totalUpdate = new CommaExpression(expressions);
        tidUpdate = totalUpdate;
      }

      //Create the for loop
      ForLoop nextLevel = new ForLoop(assignTidStmt, tidComp, tidUpdate, prev);

      //And get ready for the next iteration
      prev = nextLevel;
    }

    Annotation threadLoopBegin = new Annotation("__MCUDA_OUTER_LOOP");

    threadLoopBegin.setPrintMethod(Annotation.print_as_comment_method);
    ((ForLoop)prev).addDeclaration(threadLoopBegin);

    return (ForLoop)prev;
  }

}
