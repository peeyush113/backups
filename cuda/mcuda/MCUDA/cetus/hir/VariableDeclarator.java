package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a declarator for a variable in
 * a VariableDeclaration.
 */
public class VariableDeclarator extends Declarator
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = VariableDeclarator.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private void initialize(IDExpression direct_decl)
  {
    object_print_method = class_print_method;
    trailing_specs = new LinkedList();

    if (direct_decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(direct_decl);
    direct_decl.setParent(this);
  }

  /**
   * Create a new VariableDeclarator.
   */
  public VariableDeclarator(IDExpression direct_decl)
  {
    initialize(direct_decl);
  }

  public VariableDeclarator(IDExpression direct_decl, List trailing_specs)
  {
    initialize(direct_decl);
    this.trailing_specs.addAll(trailing_specs);
  }

  public VariableDeclarator(IDExpression direct_decl, Specifier spec)
  {
    initialize(direct_decl);
    this.trailing_specs.add(spec);
  }

  public VariableDeclarator(List leading_specs, IDExpression direct_decl)
  {
    initialize(direct_decl);
    this.leading_specs.addAll(leading_specs);
  }

  public VariableDeclarator(List leading_specs, IDExpression direct_decl,
    List trailing_specs)
  {
    initialize(direct_decl);
    this.leading_specs.addAll(leading_specs);
    this.trailing_specs.addAll(trailing_specs);
  }

  public VariableDeclarator(Specifier spec, IDExpression direct_decl)
  {
    initialize(direct_decl);
    this.leading_specs.add(spec);
  }

  public Object clone()
  {
    VariableDeclarator d = (VariableDeclarator)super.clone();
	if (children.size() > 0)
    {
      IDExpression id  = (IDExpression)getDirectDeclarator().clone();
      d.children.add(id);	
      id.setParent(d);
      if(getInitializer() != null){
      
      	Initializer init = (Initializer)getInitializer().clone();
      	d.setInitializer(init);
      }
      
    }
    d.leading_specs = (new ChainedList()).addAllLinks(leading_specs);
    d.trailing_specs = (new ChainedList()).addAllLinks(trailing_specs);

    return d;
  }

  /**
   * Prints a variable declarator to a stream.
   *
   * @param dec The declarator to print.
   * @param stream The stream on which to print the declarator.
   */
  public static void defaultPrint(VariableDeclarator dec, OutputStream stream)
  {
//  	PrintStream p = new PrintStream(stream);
    Tools.printListWithSeparator(dec.leading_specs, stream, " ");
//    p.print(" ");
    dec.getDirectDeclarator().print(stream);
    Tools.printListWithSeparator(dec.trailing_specs, stream, " ");
	if (dec.getInitializer() != null)
	{
	      dec.getInitializer().print(stream);
	}
  }

  public IDExpression getDirectDeclarator()
  {
    return (IDExpression)children.get(0);
  }

  public List getSpecifiers()
  {
    return leading_specs;
  }

  /**
   * Returns the symbol declared by this declarator.
   */
  public IDExpression getSymbol()
  {
    return getDirectDeclarator();
  }

  public List getTrailingSpecifiers()
  {
    return trailing_specs;
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
  
  public Initializer getInitializer()
  {
    if (children.size() > 1)
      return (Initializer)children.get(1);
    else
      return null;
  }
  
  public void setInitializer(Initializer init)
  {
    if (getInitializer() != null)
    {
      getInitializer().setParent(null);
      
      if (init != null)
      {
        children.set(1, init);
        init.setParent(this);
      }
      // John A. Stratton: February 2008;
      // Clearing of children is unnecesary.  Only the 
      // previous intializers need to be removed.  
      else
      {
	children.remove(1);
        //children.clear();
      }
    }
    else
    {
      if (init != null)
      {
        children.add(init);
        init.setParent(this);
      }
      else
        children.clear();
    }
  }
}
