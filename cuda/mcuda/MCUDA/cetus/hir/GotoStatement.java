package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a case for use with switch.
 */
public class GotoStatement extends Statement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = GotoStatement.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private Expression value;

  /**
   * Create a new goto statement
   */
  public GotoStatement()
  {
    object_print_method = class_print_method;
  }

  /**
   * Create a new goto statement.
   */
  public GotoStatement(Expression value)
  {
    object_print_method = class_print_method;
    this.value = value;
    value.setParent(this);
  }

  /**
   * Prints a case label to a stream.
   *
   * @param label The case label to print.
   * @param stream The stream on which to print the case label.
   */
  public static void defaultPrint(GotoStatement label, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.print("goto ");
    label.value.print(stream);
    p.print(";");
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
  
  /**
   * Get the Label that this GotoStatement Jumps to
   *
   * @return Label 
   */
  
  public Label getTarget()
  {
  	Label retval = null;
	Label o = null;
  	DepthFirstIterator iter = new DepthFirstIterator(getProcedure());
	// find all Label's in this Procedure
	// JAS: bug fix.  Was iter.next(retval.getClass()), but retval == null
	while((o = (Label)iter.next(Label.class)) != null){
		// Find a match
		if(o.getName().equals(value)){
			retval = o;
			break;
		}
	}
	return retval;
  }
}
