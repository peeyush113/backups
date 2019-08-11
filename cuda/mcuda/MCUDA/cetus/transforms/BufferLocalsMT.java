package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;
import cetus.transforms.MCUDAUtils;

/**
 * Creates arrays for local data so that individual threads in a 
 * serialized context can access a unique local store.  
 * Assumes that the single-declaration a serialize threads passes have 
 * already run.
 * 
 * Future EnforceSyncs passes will likely make the optimizations 
 * done in this pass unsound, so it is strongly encouraged that 
 * this pass be run after all EnforceSyncs passes.
 * 
 * This pass cannot be run more than once per function.
 * 
 * TODO: Optimize for cases where local data actually doesn't 
 * need to be buffered.
 */
public class BufferLocalsMT extends KernelTransformPass
{
  public String getPassName()
  {
    return new String("[BufferLocals-MCUDA]");
  }

  public BufferLocalsMT(Program program)
  {
    super(program);
  }

  public void MakeArray(VariableDeclaration vDecl, Traversable root)
  {
    //First, make the declarator itself an array
    VariableDeclarator declarator = 
      (VariableDeclarator)vDecl.getDeclarator(0);
    List specs = declarator.getArraySpecifiers();

    specs.add(new ArraySpecifier(MCUDAUtils.getMaxNumThreads()));

    boolean isArray = (declarator.getArraySpecifiers().size() != 0);

    //And for every instance referencing this declaration, 
    //make it an array access.
    //We might need several copies of an array access to 
    //put in the parse tree, so make a template to copy from
    ArrayAccess variableStore = 
      new ArrayAccess((Expression)declarator.getDirectDeclarator().clone(),
	  		MCUDAUtils.getLocalTID());

    ArrayAccess variableStoreZero = 
      new ArrayAccess((Expression)declarator.getDirectDeclarator().clone(),
	  		new IntegerLiteral(0));

    
    variableStore.setParens(true);
    variableStoreZero.setParens(true);

    
    PostOrderIterator iter = new PostOrderIterator(root);
    iter.pruneOn(Declarator.class);

    while(iter.hasNext())
    {
      Identifier variableID = null;

      try{
	variableID = (Identifier)iter.next(Identifier.class);
      } catch (NoSuchElementException e) {
        return;
      }
      
      //If we've just found the original declaration, return
      if(variableID.getParent() == declarator)
	continue;

      if(variableID.findDeclaration() == vDecl)
      {
//	if(isArray)
//	{
	  //Assuming Parent is an Array Access
//	  ArrayAccess temp = (ArrayAccess)variableID.getParent();
//	  temp.addIndex(MCUDAUtils.getLocalTID());
//	}
//	else
        //If it's an access outside of the thread loops, don't 
        //buffer it.  Instead, just access element 0
  	if(MCUDAUtils.getThreadLoopBody(variableID) == null)
	{
	  variableID.swapWith((Expression)variableStoreZero.clone());
	  continue;
	}
	//And, if it's a field of another variable, it doesn't need to be 
	//buffered
	if(variableID.getParent() instanceof AccessExpression &&
	    ((BinaryExpression)variableID.getParent()).getRHS() == variableID)
	{
	  continue;
	}

	
	variableID.swapWith((Expression)variableStore.clone());
      }
    }
  } 

  public void transformProcedure(Procedure proc)
  {
    
    PostOrderIterator iter = new PostOrderIterator(proc);
    
    while(iter.hasNext())
    {
      VariableDeclaration vDecl;
    
      try {
        vDecl = (VariableDeclaration)iter.next(VariableDeclaration.class);
      } catch (NoSuchElementException e) {
        return;
      }
 
      //Shared variables are always declared block-granular, 
      //and never need to be buffered.
      if(vDecl.getSpecifiers().contains(Specifier.SHARED))
	continue;

      //The rest of this function is a hack around emulating 
      //a live-range analysis.  We're trying to see if the live 
      //range of a variable fits within a single block.
      //
      //Eventually, this should be coupled with some kind of SSA, 
      //so that variables that have live ranges in different blocks, 
      //but none that cross block boundaries, can also be detected.

      
      //First check.  If the declaration for the variable is 
      //contained within an existing thread loop, it doesn't 
      //need to be buffered.
      if(MCUDAUtils.getThreadLoopBody(vDecl) != null)
	continue;

      
      //Second Check: Count the number of blocks in which this variable is 
      //accessed.  If the answer is 1 or 0 (unused variable?), don't buffer.
      List<CompoundStatement> threadBlocks = MCUDAUtils.GetThreadBlocks(proc);

      int numBlocksAccessing = 0;
      int i;
      
      for(i = 0; i < threadBlocks.size() && numBlocksAccessing <= 1; i++)
      {
	
	Traversable root = threadBlocks.get(i);

	DepthFirstIterator iter2 = new DepthFirstIterator(root);

	while(iter2.hasNext())
	{
	  Identifier id = null;

	  try {
	    id = (Identifier)iter2.next(Identifier.class);
	  } catch (NoSuchElementException e) {
            break;
          }
 
	  //If it's a field of another variable, it's not a real reference  
	  if(id.getParent() instanceof AccessExpression &&
	      ((BinaryExpression)id.getParent()).getRHS() == id)
	  {
	    continue;
	  }

	  if(id.findDeclaration() == vDecl)
	  {
	    //Okay, we've got an access
	    numBlocksAccessing++;
	    break;
	  }

	}
      }

      if(numBlocksAccessing > 1)
      {
	MakeArray(vDecl, vDecl.getParent().getParent());
      }
      
    }

  }
  
}
