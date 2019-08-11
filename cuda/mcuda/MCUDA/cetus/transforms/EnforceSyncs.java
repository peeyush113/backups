package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;
import cetus.transforms.MCUDAUtils;
import cetus.transforms.UniformLoops;

/**
 * Enforces synchronization commands in a sequentialized version of the 
 * threaded code.  
 * Assumes that the CUDA programming guide is followed: 
 * synchronization points affected by control flow assume that 
 * the control flow is thread independent within a block.
 * You need to run the SerializeThreads pass before this makes sense.
 */
public class EnforceSyncs extends KernelTransformPass
{
  public String getPassName()
  {
    return new String("[EnforceSyncs-MCUDA]");
  }

  public EnforceSyncs(Program program)
  {
    super(program);
  }

  public void syncOnStmt(Statement sync)
  {
    //We can be sure that the parent is a statement
    CompoundStatement enclosure = MCUDAUtils.getThreadLoopBody(sync);

    if(enclosure.getChildren().contains(sync))
    {
      //Direct child of an existing thread loop.  
      //Strip all subsequent statements into a new loop.
      
      CompoundStatement bodyOne = enclosure;
      CompoundStatement bodyTwo = new CompoundStatement();
      ForLoop outerLoopOne = MCUDAUtils.getOuterThreadLoop(enclosure);
      CompoundStatement threadLoopContext = 
	(CompoundStatement)outerLoopOne.getParent();


      List children = enclosure.getChildren();

      int i = 0;
      
      while(i < children.size())
      {
	Statement node = (Statement)children.get(i);
	
	//Since we're splitting this statement, we'll need 
	//to move declarations up a level
	if(node instanceof DeclarationStatement)
	{
	  Declaration nodeDecl = 
	    ((DeclarationStatement)node).getDeclaration();
	  if(nodeDecl instanceof Annotation)
	  {
	    i++;
	    continue;
	  }
	  ((DeclarationStatement)node).detach();
	  threadLoopContext.addStatementBefore(outerLoopOne, node);
	}
	//If we find the syncpoint, break it off
	else
	{
	  if(node == sync)
	    break;
	  else
	    i++;
	}
	
      }

      sync.detach();

      while(i < children.size())
      {
	Statement node = (Statement)children.get(i);
	//Since we're splitting this statement, we'll need 
	//to move declarations up a level
	if(node instanceof DeclarationStatement)
	{
	  Declaration nodeDecl = 
	    ((DeclarationStatement)node).getDeclaration();
	  if(nodeDecl instanceof Annotation)
	  {
	    i++;
	    continue;
	  }
	  ((DeclarationStatement)node).detach();
	  threadLoopContext.addStatementBefore(outerLoopOne, node);
	}
	else
	{
	  //Regular statement.  Move it to the next block
	  node.detach();
	  bodyTwo.addStatement(node);
	}
      }

      threadLoopContext.addStatementAfter(outerLoopOne, sync);
      
      if(enclosure.countStatements() <= 1)
      {
	//Annotation only, no execution.  Get rid 
	// of it.
	outerLoopOne.detach();
      }
      
      if(bodyTwo.countStatements() != 0)
      {
        ForLoop outerLoopTwo = MCUDAUtils.NewNestedThreadLoop(3, bodyTwo);
        threadLoopContext.addStatementAfter(sync, outerLoopTwo);
      }
      
    }
    else
    {
      //There is other control stuff going on between the sync 
      // statement and the thread loop.  So, recursively, 
      // break this context, and then break parent contexts until 
      // we get to the enclosing thread loop.

      CompoundStatement immediateParent = 
	(CompoundStatement)sync.getParent();

      Statement controlStruct = 
	(Statement)immediateParent.getParent();

      if(controlStruct instanceof Loop)
      {
	(new UniformLoops(program)).transformLoop((Loop)controlStruct);
      }
      
      CompoundStatement threadLoopBodyOne = new CompoundStatement();
      CompoundStatement threadLoopBodyTwo = new CompoundStatement();

      List children = immediateParent.getChildren();
      
      int i = 0;

      while(i < children.size())
      {
	Statement child = (Statement)children.get(i);
	if(child instanceof DeclarationStatement)
	{
	  i++;
	  continue;
	}

	//Regular statement

	if(child == sync)
	  break;
	
	child.detach();
	threadLoopBodyOne.addStatement(child);
      }

      sync.detach();

      while(i < children.size())
      {
	Statement child = (Statement)children.get(i);
	child.detach();
	threadLoopBodyTwo.addStatement(child);
      }

      if(threadLoopBodyOne.countStatements() != 0)
      {
        ForLoop threadLoopOne = 
	  MCUDAUtils.NewNestedThreadLoop(3, threadLoopBodyOne);
        immediateParent.addStatement(threadLoopOne);
      }
      
      immediateParent.addStatement(sync);

      if(threadLoopBodyTwo.countStatements() != 0)
      {
	ForLoop threadLoopTwo = 
	  MCUDAUtils.NewNestedThreadLoop(3, threadLoopBodyTwo);
        immediateParent.addStatement(threadLoopTwo);
      }

      if(immediateParent.getParent() instanceof CompoundStatement)
      	syncOnStmt(immediateParent);
      else
	syncOnStmt((Statement)immediateParent.getParent());
    }
     
  }
    
  

  public void transformProcedure(Procedure proc)
  {
    PostOrderIterator iter = new PostOrderIterator(proc);
    FunctionCall syncTemplate = MCUDAUtils.getSync();
    
    while(iter.hasNext())
    {
      FunctionCall sync;
    
      try {
        sync = (FunctionCall)iter.next(FunctionCall.class);
      } catch (NoSuchElementException e) {
        break;
      }
    
      if(sync.getName().compareTo(syncTemplate.getName()) == 0)
      {
	//Danger here if the function call is not a simple 
	//Expression Statement
	Statement syncStmt = (Statement)sync.getParent();

	syncOnStmt(syncStmt);

	//if(MCUDAUtils.getThreadLoopBody(sync).getChildren().contains(sync))
	syncStmt.detach();
      } 
    }

    boolean madeChange = true;

    Set<Class> set = new HashSet<Class>();
    set.add(GotoStatement.class);
    set.add(SwitchStatement.class);
    set.add(BreakStatement.class);
    set.add(ContinueStatement.class);
    set.add(ReturnStatement.class);
    while(madeChange == true)
    {
      madeChange = false;
      iter = new PostOrderIterator(proc);
      Object o = null;
      
      while(iter.hasNext())
      {
	Statement irregularCF;
	
	try {
	  o = iter.next(set);
	} catch (NoSuchElementException e) {
	  break;
	}

	if(o instanceof GotoStatement)
	{
	  GotoStatement jump = (GotoStatement)o;
	  Label target = jump.getTarget();

	  if(MCUDAUtils.getThreadLoopBody(jump) != 
	      	MCUDAUtils.getThreadLoopBody(target))
	  {
	    syncOnStmt(jump);
	    syncOnStmt(target);
	    madeChange = true;
	  }
	  continue;
	}

	if(o instanceof SwitchStatement)
	  //Not handled yet.
	  continue;

	if(o instanceof BreakStatement)
	{
	  BreakStatement breakstmt = (BreakStatement)o;
	  syncOnStmt(breakstmt);
	  madeChange = true;
	  continue;
	}

	if(o instanceof ContinueStatement)
	  //Not handled yet.
	  continue;

	if(o instanceof ReturnStatement)
	{
	  ReturnStatement ret = (ReturnStatement)o;
	  syncOnStmt(ret);
	  madeChange = true;
	  continue;
	}
      }
    }		

  }
  
}
