package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents a declarator for a Procedure in
 * a VariableDeclaration.
 */
public class ProcedureDeclarator extends Declarator
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ProcedureDeclarator.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private ExceptionSpecification espec;

  private void initialize(IDExpression direct_decl, List params)
  {
    object_print_method = class_print_method;
    trailing_specs = new LinkedList();

    if (direct_decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(direct_decl);
    direct_decl.setParent(this);

    Iterator iter = params.iterator();
    while (iter.hasNext())
    {
      Declaration decl = (Declaration)iter.next();

      if (decl.getParent() != null)
        throw new NotAnOrphanException();

      children.add(decl);
      decl.setParent(this);
    }
  }

  public ProcedureDeclarator(IDExpression direct_decl, List params)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
  }

  public ProcedureDeclarator(IDExpression direct_decl, List params, List trailing_specs)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
    this.trailing_specs.addAll(trailing_specs); 
  }

  public ProcedureDeclarator(List leading_specs, IDExpression direct_decl, List params)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
    this.leading_specs.addAll(leading_specs);
  }

  public ProcedureDeclarator(List leading_specs, IDExpression direct_decl,
    List params, List trailing_specs, ExceptionSpecification espec)
  {
    super(1 + params.size());
    initialize(direct_decl, params);
    this.leading_specs.addAll(leading_specs);
    this.trailing_specs.addAll(trailing_specs);
    this.espec = espec;
  }

  public void addParameter(Declaration decl)
  {
    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(decl);
    decl.setParent(this);
  }

  public void addParameterBefore(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
      throw new IllegalArgumentException();

    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(index, decl);
    decl.setParent(this);
  }

  public void addParameterAfter(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
      throw new IllegalArgumentException();

    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    children.add(index + 1, decl);
    decl.setParent(this);
  }

  public Object clone()
  {
    ProcedureDeclarator d = (ProcedureDeclarator)super.clone();
    IDExpression id  = (IDExpression)getDirectDeclarator().clone();
    d.children.add(id);	
    id.setParent(d);
    if (children.size() > 1)
    {
      List tmp = (new ChainedList()).addAllLinks(children);
      tmp.remove(0);
      Iterator iter = tmp.iterator();
      while (iter.hasNext())
      {
         Declaration decl = (Declaration)iter.next();

         decl = (Declaration)decl.clone();
         d.children.add(decl);
         decl.setParent(d);
     }
      
    }
    d.leading_specs = (new ChainedList()).addAllLinks(leading_specs);
    d.trailing_specs = (new ChainedList()).addAllLinks(trailing_specs);
    d.espec = espec;

    return d;
  }

  /**
   * Prints a procedure declarator to a stream.
   *
   * @param dec The declarator to print.
   * @param stream The stream on which to print the declarator.
   */
  public static void defaultPrint(ProcedureDeclarator dec, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    Tools.printList(dec.leading_specs, stream);

	dec.getDirectDeclarator().print(stream);
   
    if (dec.children.size() > 1)
    {
      List tmp = (new ChainedList()).addAllLinks(dec.children);
      tmp.remove(0);
      p.print("(");
      Tools.printListWithCommas(tmp, stream);
      p.print(")");
    }
	else
		p.print("(  )");
    Tools.printListWithSeparator(dec.trailing_specs, stream, " ");

    

  }

  public IDExpression getDirectDeclarator()
  {
    return (IDExpression)children.get(0);
  }

  public List<Declaration> getParameters()
  {
    List tmp = (new ChainedList()).addAllLinks(children);
    tmp.remove(0);
    return tmp;
  }

  /**
   * Returns the symbol declared by this declarator.
   */
  public IDExpression getSymbol()
  {
    return getDirectDeclarator();
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
}
