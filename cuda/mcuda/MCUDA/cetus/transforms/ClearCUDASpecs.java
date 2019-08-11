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
public class ClearCUDASpecs
{
  private static String pass_name = "[ClearCUDASpecs-MCUDA]";
  private Program program;

  public ClearCUDASpecs(Program program)
  {
    this.program = program;
  }

  public static void run(Program program)
  {
    Tools.printlnStatus(pass_name + " begin", 1);

    ClearCUDASpecs pass = new ClearCUDASpecs(program);
    pass.start();

    Tools.printlnStatus(pass_name + " end", 1);
  }

  
  private void start()
  {
    DepthFirstIterator i = new DepthFirstIterator(program);
    i.pruneOn(VariableDeclaration.class);

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

	//If this was a device function, but not a kernel function or a 
	//host function, don't print it
	if((!proc.removeProcedureSpec(Specifier.GLOBAL)) && 
	     (!proc.removeProcedureSpec(Specifier.HOST)) &&
	     proc.removeProcedureSpec(Specifier.DEVICE))
	{
	  Tools.printlnStatus("Removing Procedure " + proc.getName(), 3);

	  Class params[] = new Class[2];
	  try {
	    params[0] = Procedure.class;
	    params[1] = OutputStream.class;
	    proc.setPrintMethod(params[0].getMethod("noPrint", params));
	  } catch (NoSuchMethodException e) {
	    throw new InternalError();
	  }
	}
	 /* 
	while(proc.removeProcedureSpec(Specifier.GLOBAL));
	while(proc.removeProcedureSpec(Specifier.DEVICE));
	while(proc.removeProcedureSpec(Specifier.HOST));
	*/
      }
      else
      {
        while (decl.getSpecifiers().remove(Specifier.SHARED));
        while (decl.getSpecifiers().remove(Specifier.LOCAL));
        while (decl.getSpecifiers().remove(Specifier.DEVICE));
        while (decl.getSpecifiers().remove(Specifier.CONSTANT));
      }
    }

    i = new DepthFirstIterator(program);
    i.pruneOn(Procedure.class);

    //Now we need to do a separate pass for prototypes
    for (;;)
    {
      ProcedureDeclarator pDecl = null;

      try {
        pDecl = (ProcedureDeclarator)i.next(ProcedureDeclarator.class);
      } catch (NoSuchElementException e) {
        break;
      }

      	//Function prototypes are the only thing that will show up here, 
	//(Pruned on Procedure.)  The parent will have the leading specs, 
	//and is a variable type.
      VariableDeclaration prototype = 
	(VariableDeclaration)pDecl.getParent();
      String functionName = pDecl.getDirectDeclarator().toString();

      List specs = prototype.getSpecifiers();
      while(specs.remove(Specifier.GLOBAL));
      while(specs.remove(Specifier.DEVICE));
      while(specs.remove(Specifier.HOST));
    }
   
  }
}
