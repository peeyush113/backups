package cetus.analysis;

import java.io.*;
import java.util.*;
import cetus.hir.*;

/**
 * A static call graph for the program.
 */
public class CallGraph
{
  public class Caller
  {
    private Statement callsite ;
    private Procedure callingproc;

    public Caller()
    {
      callsite= null ;
      callingproc = null ;
    }

    public Caller(Statement l_stmt)
    {
      callsite = l_stmt ;
      callingproc = l_stmt.getProcedure();
    }

    public Statement getCallSite()
    {
      return callsite;
    }

    public Procedure getCallingProc()
    {
      return callingproc;
    }
  }

  public class Node
  {
    private Procedure proc;
    private ArrayList callers;
    private ArrayList callees;

    public Node(Procedure proc)
    {
      this.proc = proc ;
      callers = new ArrayList(1);
      callees = new ArrayList(1);
    }

    public void addCaller(Statement stmt)
    {
      callers.add(new Caller(stmt));
    }

    public void addCallee(Procedure proc)
    {
      callees.add(proc);
    }

    public List getCallers()
    {
      return callers;
    }

    public List getCallees()
    {
      return callees;
    }
  }

  private Node root;
  private HashMap callgraph;

  /**
   * Creates a call graph for the program.
   * Assumes the graph is rooted at a procedure
   * called "main" or "MAIN__".  (The second is
   * used in f2c code.)
   *
   * @param program The program for which to create the call graph.
   */
  public CallGraph(Program program)
  {
    callgraph = new HashMap();

    /* add nodes for every procedure */
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

      Node node = new Node(proc);
      String name = proc.getName().toString();

      /* f2c code uses MAIN__ */
      if (name.equals("main") || name.equals("MAIN__"))
        root = node;

      callgraph.put(proc, node);
    }

    /* look for function calls and put them in the graph */

    iter = new BreadthFirstIterator(program);
    
    for (;;)
    {
      FunctionCall call = null;

      try {
        call = (FunctionCall)iter.next(FunctionCall.class);
      } catch (NoSuchElementException e) {
        break;
      }

      Node currproc = null, calledproc = null;
      Procedure l_currproc = call.getStatement().getProcedure();
      Procedure l_calledproc = call.getProcedure();

      /* l_calledproc will be null for system calls */
      if (l_calledproc != null)
      {
        currproc = (Node)callgraph.get(l_currproc);
        if (currproc != null)
          currproc.addCallee(l_calledproc);

        calledproc = (Node)callgraph.get(l_calledproc);
        if (calledproc != null)
          calledproc.addCaller(call.getStatement());
      }
    }
  }

  public boolean callsSelf(Procedure proc)
  {
    Node n = (Node)callgraph.get(proc);

    if (n != null && n.getCallees().contains(proc))
      return true;
    else
      return false;
  }

  /**
   * Access the graph directly as a hash map.
   *
   * @return a HashMap representing the graph.
   */
  public HashMap getCallGraph()
  {
    return callgraph;
  }

  /**
   * Access the root node of the graph.
   *
   * @return the root Node object.
   */
  public Node getRoot()
  {
    return root;
  }

  /**
   * Determines if the procedure is a leaf
   * of the call graph.
   *
   * @param proc A Procedure appearing in the call graph.
   * @return true if the procedure does not call
   *   and other procedures of the program (i.e.,
   *   library calls are ignored), or false
   *   otherwise.
   */
  public boolean isLeaf(Procedure proc)
  {
    Node node = (Node)callgraph.get(proc);
    return (node.getCallees().size() == 0);
  }

  public boolean isRecursive(Procedure proc)
  {
    HashSet seen = new HashSet();

    HashSet horizon = new HashSet();
    horizon.add(proc);

    while (!horizon.isEmpty())
    {
      Procedure p = (Procedure)horizon.iterator().next();
      Node n = (Node)callgraph.get(p);

      if (n != null && n.getCallees().contains(proc))
        return true;

      horizon.remove(p);
      seen.add(p);

      if (n != null)
      {
        Iterator iter = n.getCallees().iterator();
        while (iter.hasNext())
        {
          Object o = iter.next();
          if (!seen.contains(o))
            horizon.add(o);
        }
      }
    }

    return false;
  }

  /**
   * Prints the graph to a stream in
   * <a href="http://www.research.att.com/sw/tools/graphviz/">graphviz</a> format.
   *
   * @param stream The stream on which to print the graph.
   */
  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.println("digraph {\norientation=landscape;\nsize=\"11,8\";\n");
    Iterator l_iter = callgraph.keySet().iterator() ;

    while (l_iter.hasNext())
    {
      Procedure l_proc = (Procedure)l_iter.next();
      Node node = (Node)callgraph.get(l_proc);

      p.print(l_proc.getName().toString());
      p.print(" -> { ");

      Iterator iter = node.getCallees().iterator();
      while (iter.hasNext())
      {
        Procedure callee = (Procedure)iter.next();
        p.print(callee.getName().toString() + " ");
      }

      p.print("};\n");
    }

    p.print("}\n");
  }
}
