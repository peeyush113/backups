package cetus.transforms;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;
import cetus.transforms.MCUDAUtils;

/**
 * John A. Stratton
 * This class translates accesses to the implicitly defined 
 * dim3 variables of a CUDA program into scalar varible accesses.  
 *
 * This is currently required for Xpilot bridge support.
 */
public class ScalarDim3 extends KernelTransformPass
{
  public String getPassName()
  {
    return new String("[ScalarDim3-MCUDA]");
  }

  public ScalarDim3(Program program)
  {
    super(program);
  }

  public void transformProcedure(Procedure proc)
  {
    List<Identifier> implicitvars = new ChainedList();
    List<Method> constructors = new ChainedList();

    Class[] params = new Class[1];
    Object[] args = new Object[1];
    params[0] = int.class;
    
    int dim_limit = 3;

    //Add each implicit variable, and the method which will 
    // produce the correct representation of it for the options 
    // currently set.
    try{
      implicitvars.add(new Identifier(MCUDAUtils.getBIDXString()));
      constructors.add(MCUDAUtils.class.getMethod("getBidxID", params));

      implicitvars.add(new Identifier(MCUDAUtils.getTIDString()));
      constructors.add(MCUDAUtils.class.getMethod("getTidID", params));

      implicitvars.add(new Identifier(MCUDAUtils.getBDIMString()));
      constructors.add(MCUDAUtils.class.getMethod("getBdimID", params));

      implicitvars.add(new Identifier(MCUDAUtils.getGDIMString()));
      constructors.add(MCUDAUtils.class.getMethod("getGdimID", params));

    } catch(NoSuchMethodException e) {
      throw new InternalError();
    }


    //For each variable and field, look for that variable-field access
    //  combination, and replace it with the correct representation.
    for(int variable = 0; variable < implicitvars.size(); variable++)
    {
      for(int entry = 0; entry < dim_limit; entry++)
      {

	AccessExpression old = 
	  new AccessExpression(implicitvars.get(variable), 
	      AccessOperator.MEMBER_ACCESS,
	      new Identifier(MCUDAUtils.getDimEntry(entry)));
	
	args[0] = entry;
	  
	Expression replacement;

	try{
	  replacement = 
	    (Expression)constructors.get(variable).invoke(null,args);
	} catch (IllegalAccessException e) {
	  throw new InternalError();
	} catch (InvocationTargetException e) {
	  throw new InternalError();
	}
	
	Tools.replaceAll(proc, old, replacement);
      }
    }

  }
  
}
