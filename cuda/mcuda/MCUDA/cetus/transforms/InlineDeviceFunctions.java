package cetus.transforms;

import cetus.hir.*;
import java.util.*;

/**
 * Searches for small functions that can be inlined
 * and inlines their code into the call site.
 */
public class InlineDeviceFunctions extends Inline
{
  private static String pass_name = "[InlineDeviceFunctions]";

  public InlineDeviceFunctions(Program program)
  {
    super(program, 1);
  }

  protected HashSet<String> findInlineCandidates()
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

      List specs = proc.getReturnType();

      if(specs.contains(Specifier.GLOBAL) || 
	  specs.contains(Specifier.DEVICE))
      {
        candidates.add(proc.getName().toString());
      }
    }
    
    return candidates;
  }

  public static void run(Program program)
  {
    Tools.printlnStatus(pass_name + " begin", 1);
    (new InlineDeviceFunctions(program)).start();
    Tools.printlnStatus(pass_name + " end", 1);
  }

  public void start()
  {
    HashSet<String> candidates = findInlineCandidates();

    //Functions only need to be inlined into other device functions
    
    DepthFirstIterator iter = new DepthFirstIterator(program);
    iter.pruneOn(Procedure.class);

    for (;;)
    {
      Procedure device_function = null;

      try { 
	device_function = (Procedure)iter.next(Procedure.class);
      } catch (NoSuchElementException e) {
        break;
      }

      List specs = device_function.getReturnType();

      if(specs.contains(Specifier.GLOBAL) ||
	  specs.contains(Specifier.DEVICE) )
      {

	DepthFirstIterator iter2 = new DepthFirstIterator(device_function);
        for (;;)
        {
          FunctionCall call = null;

          try {
            call = (FunctionCall)iter2.next(FunctionCall.class);
          } catch (NoSuchElementException e) {
            break;
          }
    
          if (candidates.contains(call.getName().toString()))
            inlineCall(call);
        }
      }
      
    }
  
  }
  
}

