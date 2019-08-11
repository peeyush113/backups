package cetus.transforms;

import java.util.*;

import cetus.exec.*;
import cetus.hir.*;

public abstract class DeviceTransformPass extends TransformPass
{
  protected DeviceTransformPass(Program program)
  {
    super(program);
  }

  public abstract void transformProcedure(Procedure proc);

  //Override this function if something needs to be applied to 
  //kernel prototypes as well.
  public void transformPrototype(ProcedureDeclarator pDecl)
  {
    return;
  }

  public void start()
  {
    HashSet skip_set = Driver.getSkipProcedureSet();

    BreadthFirstIterator iter = new BreadthFirstIterator(program);
    iter.pruneOn(Procedure.class);
    Set<Class> set = new HashSet<Class>();
    set.add(Procedure.class);
    set.add(ProcedureDeclarator.class);

    for (;;)
    {
      Procedure proc = null;
      ProcedureDeclarator pDecl = null;

      try {
        Object o = iter.next(set);
	if(o instanceof Procedure)
	  proc = (Procedure)o;
	else //ProcedureDeclarator
	  pDecl = (ProcedureDeclarator)o;
      } catch (NoSuchElementException e) {
        break;
      }

      if(proc != null)
      {
	List specs = proc.getReturnType();
	if(!(specs.contains(Specifier.GLOBAL)) && 
	    !(specs.contains(Specifier.DEVICE)))
	  continue;

	if (!skip_set.contains(proc.getName().toString()))
	{
	  Tools.printlnStatus(getPassName() + " examining procedure " + proc.getName(), 2);
	  transformProcedure(proc);
	}
	else
	{
	  Tools.printlnStatus(getPassName() + " skipping procedure " + proc.getName(), 2);
	}
      }
      else if (pDecl != null)
      {
	//Function prototypes are the only thing that will show up here, 
	//(Pruned on Procedure.)  The parent will have the leading specs, 
	//and is a variable type.
	VariableDeclaration prototype = 
	  (VariableDeclaration)pDecl.getParent();

	String functionName = pDecl.getDirectDeclarator().toString();

	List specs = prototype.getSpecifiers();
	
	if(!(specs.contains(Specifier.GLOBAL)) &&
	    !(specs.contains(Specifier.DEVICE)))
	  continue;

	if (!skip_set.contains(functionName))
	{
	  Tools.printlnStatus(getPassName() + " examining procedure " + functionName, 2);
	  transformPrototype(pDecl);
	}
	else
	{
	  Tools.printlnStatus(getPassName() + " skipping procedure " + functionName, 2);
	}
      }

    }
  }
}
