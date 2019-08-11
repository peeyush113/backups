package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;
import cetus.transforms.MCUDAUtils;

/**
 * Interfaces a function call to the MCUDA runtime library.
 * First creates a type definition for this function's parameter 
 * struction.  
 * Then modifies the current function to now accept the implicit 
 * block and grid variables of the CUDA programming model, 
 * in addition to a pointer to an instance of the parameter structure.
 * Lastly, creates a new function with the original function 
 * signature, whose sole purpose is to construct the paramter 
 * structure, and pass the kernel invocation to the runtime.  
 * The kernel function is renamed and passed as one of the 
 * kernel invocation parameters.  
 */
public class SerializeThreads extends KernelTransformPass
{
  public String getPassName()
  {
    return new String("[SerializeThreads-MCUDA]");
  }

  public SerializeThreads(Program program)
  {
    super(program);
  }

  public void transformProcedure(Procedure proc)
  {
    CompoundStatement body = proc.getBody();
    CompoundStatement newBody = new CompoundStatement();
    
    proc.setBody(newBody);
    
    List<VariableDeclaration> tidDecl = MCUDAUtils.getTidDecl();
    //Slightly cheating here.  We're going to call the
    //thread indices "shared" variables, to eliminate 
    //later issues with accessing non-shared variables 
    //using the thread index
    
    for(int i = 0; i < tidDecl.size(); i++)
    {
      VariableDeclaration currentDecl = tidDecl.get(i);
      tidDecl.get(i).getSpecifiers().add(Specifier.SHARED);
      newBody.addDeclaration(tidDecl.get(i));
    }

    VariableDeclarator localTid = 
      new VariableDeclarator(MCUDAUtils.getLocalTID());

    List tidSpecs = new ChainedList();
    tidSpecs.add(Specifier.SHARED);
    tidSpecs.add(Specifier.INT);
    
    VariableDeclaration localTidDecl = 
      new VariableDeclaration(tidSpecs, localTid);
    
    newBody.addDeclaration(localTidDecl);
    newBody.addStatement(MCUDAUtils.NewNestedThreadLoop(3, body));
    
    return;
  }
  
}
