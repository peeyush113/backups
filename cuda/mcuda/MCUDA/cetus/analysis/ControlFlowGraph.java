package cetus.analysis;

import java.util.*;
import java.io.*;

import cetus.hir.*;

/**
 * A control-flow graph of the program.
 */
public class ControlFlowGraph
{
  private static String pass_name = "[ControlFlowGraph]";

  BasicBlock rootBB = new BasicBlock();
  HashMap procBB = new HashMap();
  HashMap proccalls = new HashMap();
  ArrayList bblist = new ArrayList();
  ArrayList bbtoadjust = new ArrayList();
  BasicBlock entrybb,exitbb,currpred;
  Stack scopexitstack = new Stack(), scopentrystack = new Stack();
  Stack breakstack = new Stack(), continuestack = new Stack(), switchstack = new Stack();

  public ControlFlowGraph(Program prog)
  {
    BreadthFirstIterator iter = new BreadthFirstIterator(prog);
    iter.pruneOn(Procedure.class);

    for (;;)
    {
      Procedure proc = null;

      try {
        proc = (Procedure)iter.next(Procedure.class);
      } catch (NoSuchElementException e) {
        break;
      }

      Tools.printlnStatus(pass_name + " creating CFG for procedure "
                          + proc.getName().toString(), 2);

      ProcBasicBlock l_bb = getBBforProc(proc);
      procBB.put(proc, l_bb);

      String name = proc.getName().toString();
      if (name.equals("main") || name.equals("MAIN__"))
        rootBB = l_bb.entryBB;
    }

    //System.err.println("Adjusting BBs for Calls");
    //adjustBBforCalls();
    optimizeBasicBlocks();
  }

  private boolean containsFC(Statement p_stmt)
  {
    boolean hasFC = false ;
    //Get an iterator on the Statement
    DepthFirstIterator l_dir = new DepthFirstIterator(p_stmt);
    while(l_dir.hasNext()) {
      try {
        FunctionCall fc = (FunctionCall) l_dir.next(FunctionCall.class);
        if (fc.getProcedure() != null)
          return true ;
      } catch (NoSuchElementException e) {
        hasFC = false ;
      }
    }

    return hasFC ;
  }

  public BasicBlock getRoot()
  {
    return rootBB;
  }

  /**
   * Removes redundant empty blocks.
   */
  private void optimizeBasicBlocks()
  {
    Iterator bbiter = bblist.iterator();
    ArrayList bbrem = new ArrayList();

    while (bbiter.hasNext())
    {
      BasicBlock bbl = (BasicBlock) bbiter.next();

      if (bbl.preds.size() == 1 && bbl.succs.size() == 1)
      {
        if (bbl.statements.size() == 0)
        {
          BasicBlock bpred = (BasicBlock)bbl.preds.get(0);
          BasicBlock bsucc = (BasicBlock)bbl.succs.get(0);
          bpred.addSuccessor(bsucc); bsucc.addPredecessor(bpred);
          bpred.succs.remove(bbl); bsucc.preds.remove(bbl);
          bbl.preds.remove(bpred); bbl.succs.remove(bsucc);
          bbrem.add(bbl);
        }
      }
    }

    bblist.removeAll(bbrem);
  }

  private void adjustBBforCalls()
  {
    for (int i=0;i<bbtoadjust.size();i++)
    {
      BasicBlock bbl = (BasicBlock)bbtoadjust.get(i);
      if (bbl.succs.size() > 1) {
        System.err.println("Too many return points");
        System.exit(-1);
      }
      BasicBlock retblock = (BasicBlock) bbl.succs.get(0);
      bbl.succs.remove(0);
      //DepthFirstIterator l_dir = new DepthFirstIterator(bbl.cs);
      List l_dir = bbl.statements ;
      System.err.println("Adjusting --");
      Tools.printlnList(bbl.statements, System.err);
      for (int j=0; j<l_dir.size(); j++) {
        Object o = l_dir.get(j);
        if (!(o instanceof ExpressionStatement)) {
          System.err.println("This should be a functioncall");
          break;
        }
        Expression l_ex = ((ExpressionStatement)o).getExpression();
        DepthFirstIterator l_di = new DepthFirstIterator(l_ex);
        while (l_di.hasNext()) {
          Object l_o = l_di.next();
          if (!(l_o instanceof FunctionCall)) continue ;
          FunctionCall fc = (FunctionCall) l_o;
          if (fc == null)break;
          ProcBasicBlock pBB = (ProcBasicBlock) procBB.get(fc.getProcedure());
          //BasicBlock pBB = (BasicBlock) procBB.get(fc.getProcedure());
          if (pBB != null) {
            bbl.addSuccessor(pBB.entryBB);
            pBB.addSuccessor(retblock);
          }
        }
      }
    }
  }

  private ProcBasicBlock getBBforProc(Procedure proc)
  {
    //System.err.println("Getting CFG for "+l_p.getName().toString());
    //First empty all the stacks
    breakstack.clear(); continuestack.clear(); switchstack.clear();
    scopentrystack.clear(); scopexitstack.clear();

    ProcBasicBlock p_BB = new ProcBasicBlock();
    scopentrystack.push(p_BB.entryBB);
    scopexitstack.push(p_BB.exitBB);
//    p_BB.entryBB.cs.setParent(proc);
//    p_BB.exitBB.cs.setParent(proc);
    DeclarationStatement dc = new DeclarationStatement(new Annotation(proc.getName().toString()));
    p_BB.statements.add(dc);
    DeclarationStatement dc1 = new DeclarationStatement(new Annotation("Entry to "+proc.getName().toString()));
    DeclarationStatement dc2 = new DeclarationStatement(new Annotation("RETURN"));
    dc1.setParent(proc); dc2.setParent(proc);
    CompoundStatement l_cs = (CompoundStatement) proc.getBody();
    entrybb = p_BB.entryBB; exitbb = p_BB.exitBB;
    List arl1 = entrybb.statements;
    arl1.add(dc1);
    arl1 = exitbb.statements; arl1.add(dc2);
    currpred = entrybb;
    bblist.add(entrybb);bblist.add(exitbb);
    findBBs(l_cs,p_BB.exitBB);
    BasicBlock t_bbl = (BasicBlock) scopentrystack.pop() ;
    exitbb.addPredecessor(t_bbl); t_bbl.addSuccessor(exitbb);
    //BasicBlock t_bb2 = (BasicBlock) scopexitstack.pop() ;
    //if (!(t_bb1.equals(p_BB.entryBB) && t_bb2.equals(p_BB.exitBB))){
      //System.err.println("Stack scope error in proc "+l_p.getName().toString());
    //}
    return p_BB ;
  }

  private void findBBs(Statement stmt, BasicBlock succ)
  {
    BasicBlock pred = (BasicBlock) scopentrystack.peek() ;
    //Expression Statements will be added to this pred block
    //If a new block needs to be created, it will become a successor of pred
    //and be pushed to the top of scopentrystack

    if (stmt instanceof IfStatement) {
      IfStatement ist = (IfStatement)stmt;
      BasicBlock ifentry = new BasicBlock(); bblist.add(ifentry);
      BasicBlock bblthen = new BasicBlock(); bblist.add(bblthen);
      BasicBlock ifexit = new BasicBlock(); bblist.add(ifexit);

      /*DeclarationStatement dc = new DeclarationStatement(new Annotation("endif"));
      dc.setParent(ist); ifexit.cs.getChildren().add(dc);*/
      pred.addSuccessor(ifentry); ifentry.addPredecessor(pred);
      scopentrystack.push(ifentry); scopexitstack.push(ifexit);

      ExpressionStatement l_est = new ExpressionStatement(ist.getControlExpression()) ;
      //Statement l_est = ist.getControlExpression().getStatement() ;
      l_est.setParent(ist);
      if (containsFC(l_est)) {
        BasicBlock condblock = new BasicBlock(); bblist.add(condblock);
        findBBs(l_est,condblock);
        ifentry = (BasicBlock) scopentrystack.pop();
        condblock.addPredecessor(ifentry); ifentry.addSuccessor(condblock);
        scopentrystack.push(condblock);
      } else {
        //ifentry.cs.addStatement(l_est);
        ifentry.statements.add(l_est);
      }
      ifentry = (BasicBlock)scopentrystack.pop();
      ifentry.addSuccessor(bblthen); bblthen.addPredecessor(ifentry);
      scopentrystack.push(bblthen);
      findBBs(ist.getThenStatement(), ifexit);
      bblthen = (BasicBlock) scopentrystack.pop() ;
      bblthen.addSuccessor(ifexit); ifexit.addPredecessor(bblthen);

      if (ist.getElseStatement() != null) {
        BasicBlock bbelse = new BasicBlock(); bblist.add(bbelse);
        ifentry.addSuccessor(bbelse); bbelse.addPredecessor(ifentry);
        scopentrystack.push(bbelse);
        findBBs(ist.getElseStatement(), ifexit);
        bbelse = (BasicBlock) scopentrystack.pop() ;
        bbelse.addSuccessor(ifexit); ifexit.addPredecessor(bbelse);
      } else {
        //The else path goes directly to ifexit
        ifentry.addSuccessor(ifexit); ifexit.addPredecessor(ifentry);
      }
      //A basic block boundary here
      scopentrystack.push(ifexit); scopexitstack.pop();
      return ;
    }

    if (stmt instanceof ForLoop) {
        ForLoop fl = (ForLoop) stmt ;
        //if (true) return ;
        BasicBlock loopentry = new BasicBlock(); bblist.add(loopentry);
        BasicBlock loopexit = new BasicBlock(); bblist.add(loopexit);
        BasicBlock loopcond = new BasicBlock(); bblist.add(loopcond);
        BasicBlock loopbody = new BasicBlock(); bblist.add(loopbody);
        BasicBlock loopstep = new BasicBlock(); bblist.add(loopstep);

        breakstack.push(loopexit); continuestack.push(loopstep);

        loopentry.addPredecessor(pred); pred.addSuccessor(loopentry);
        Statement l_init = fl.getInitialStatement();
        Statement l_cond = new ExpressionStatement(fl.getCondition());
        l_cond.setParent(fl);
        Statement l_step = new ExpressionStatement(fl.getStep());
        l_step.setParent(fl);
        Statement l_body = fl.getBody() ;

        scopentrystack.push(loopentry); scopexitstack.push(loopexit);
        findBBs(l_init,loopcond);

        loopentry = (BasicBlock) scopentrystack.peek();
        loopentry.addSuccessor(loopcond); loopcond.addPredecessor(loopentry);
        scopentrystack.push(loopcond);
        findBBs(l_cond, loopbody);

        loopentry = (BasicBlock) scopentrystack.peek();
        loopentry.addSuccessor(loopbody); loopbody.addPredecessor(loopentry);
        scopentrystack.push(loopbody);
        findBBs(l_body, loopexit);
        loopbody = (BasicBlock) scopentrystack.peek();
        loopbody.addSuccessor(loopstep); loopstep.addPredecessor(loopbody);
        scopentrystack.push(loopstep);
        findBBs(l_step, loopexit);

        BasicBlock bbl = (BasicBlock) scopentrystack.peek();
        bbl.addSuccessor(loopcond);
        loopcond.addPredecessor(bbl);
        loopexit.addPredecessor(loopentry); loopentry.addSuccessor(loopexit);
        scopentrystack.push(loopexit);

        breakstack.pop(); continuestack.pop();
        return ;
      }

      if (stmt instanceof DoLoop) {
        DoLoop fl = (DoLoop) stmt ;

        BasicBlock loopentry = new BasicBlock(); bblist.add(loopentry);
        BasicBlock loopexit = new BasicBlock(); bblist.add(loopexit);
        BasicBlock loopcond = new BasicBlock(); bblist.add(loopcond);
        BasicBlock bbl ;
        continuestack.push(loopcond); breakstack.push(loopexit);

        Statement l_cond = new ExpressionStatement(fl.getCondition());
        l_cond.setParent(fl);
        Statement l_body = fl.getBody();
        loopentry.addPredecessor(pred); pred.addSuccessor(loopentry);
        scopentrystack.push(loopentry); scopexitstack.push(loopexit);
        findBBs(l_body, loopcond);
        bbl = (BasicBlock) scopentrystack.pop();
        bbl.addSuccessor(loopcond); loopcond.addPredecessor(bbl);
        scopentrystack.push(loopcond);
        findBBs(l_cond, loopexit);
        bbl = (BasicBlock) scopentrystack.pop();
        bbl.addSuccessor(loopentry); loopentry.addPredecessor(bbl);
        bbl.addSuccessor(loopexit); loopexit.addPredecessor(bbl);
        scopentrystack.push(loopexit);

        continuestack.pop(); breakstack.pop();
        return ;
      }

      if (stmt instanceof WhileLoop) {
        WhileLoop fl = (WhileLoop) stmt ;

        BasicBlock loopentry = new BasicBlock(); bblist.add(loopentry);
        BasicBlock loopexit = new BasicBlock(); bblist.add(loopexit);
        BasicBlock loopcond = new BasicBlock(); bblist.add(loopcond);
        BasicBlock bbl ;
        DeclarationStatement l_dc ;
        continuestack.push(loopcond); breakstack.push(loopexit);
        /*
        l_dc = new DeclarationStatement(new Annotation("while loop condition"));
        l_dc.setParent(fl);
        loopcond.cs.getChildren().add(l_dc);
        l_dc = new DeclarationStatement(new Annotation("while loop body"));
        l_dc.setParent(fl);
        loopentry.cs.getChildren().add(l_dc);
        l_dc = new DeclarationStatement(new Annotation("end while loop"));
        l_dc.setParent(fl);
        loopexit.cs.getChildren().add(l_dc);
        */
        Statement l_cond = new ExpressionStatement(fl.getCondition());
        l_cond.setParent(fl);
        Statement l_body = fl.getBody();

        loopcond.addPredecessor(pred); pred.addSuccessor(loopcond);
        scopentrystack.push(loopcond); scopexitstack.push(loopexit);
        findBBs(l_cond, loopexit);
        bbl = (BasicBlock) scopentrystack.pop();
        bbl.addSuccessor(loopentry); loopentry.addPredecessor(bbl);
        bbl.addSuccessor(loopexit); loopexit.addPredecessor(bbl);
        scopentrystack.push(loopentry);
        findBBs(l_body, loopcond);
        bbl = (BasicBlock) scopentrystack.pop();
        bbl.addSuccessor(loopcond); loopcond.addPredecessor(bbl);
        //bbl.addSuccessor(loopexit); loopexit.addPredecessor(bbl);
        scopentrystack.push(loopexit);

        continuestack.pop(); breakstack.pop();
        return ;
      }

      if (stmt instanceof BreakStatement) {
        if (!breakstack.isEmpty()) {
          BasicBlock bbl = (BasicBlock) breakstack.peek();
          pred.addSuccessor(bbl); bbl.addPredecessor(pred);
          bbl = new BasicBlock(); bblist.add(bbl);
          scopentrystack.push(bbl);
        } else {
          System.err.println("Illegal break statement at line "+stmt.where());
        }
        return;
      }

      if (stmt instanceof ContinueStatement) {
        if (!continuestack.isEmpty()) {
          BasicBlock bbl = (BasicBlock) continuestack.peek();
          pred.addSuccessor(bbl); bbl.addPredecessor(pred);
          bbl = new BasicBlock(); bblist.add(bbl);
          scopentrystack.push(bbl);
        } else {
          System.err.println("Illegal continue statement at line "+stmt.where());
        }

        return;
      }

      if (stmt instanceof Case) {
        //I guess we need a new basic block for each case block
        //Assuming that the case expression does not contain fcalls
        Statement l_cex = new ExpressionStatement(((Case)stmt).getExpression());
        //ExpressionStatement l_cex = (ExpressionStatement)((Case)stmt).getExpression().getStatement();
        l_cex.setParent(stmt);
        if (containsFC(l_cex)){
          System.err.println("Function call in case exp, exiting");
          System.exit(-1);
        }
        BasicBlock bbcase = new BasicBlock(); bblist.add(bbcase);
        bbcase.statements.add(l_cex);
        //Check if pred has a predecessor, otherwise set pred to switchstatement
        pred.addSuccessor(bbcase); bbcase.addPredecessor(pred);
        if (pred.preds.size() == 0) {
          BasicBlock bbswitch = (BasicBlock)switchstack.peek();
          pred.addPredecessor(bbswitch); bbswitch.addSuccessor(pred);
        }
        scopentrystack.push(bbcase);
        return;
      }

      if (stmt instanceof Default) {
        BasicBlock bbl = new BasicBlock(); bblist.add(bbl);
        bbl.addPredecessor(pred); pred.addSuccessor(bbl);
        if (pred.preds.size() == 0) {
          BasicBlock bbswitch = (BasicBlock)switchstack.peek();
          pred.addPredecessor(bbswitch); bbswitch.addSuccessor(pred);
        }
        scopentrystack.push(bbl);
        return;
      }

      if (stmt instanceof SwitchStatement) {

        SwitchStatement fl = (SwitchStatement) stmt ;
        BasicBlock loopcond = new BasicBlock(); bblist.add(loopcond);
        BasicBlock loopbody = new BasicBlock(); bblist.add(loopbody);
        BasicBlock loopexit = new BasicBlock(); bblist.add(loopexit);
        BasicBlock bbl;

        pred.addSuccessor(loopcond); loopcond.addPredecessor(pred);
        scopentrystack.push(loopcond); scopexitstack.add(loopexit);
        breakstack.push(loopexit);
        ExpressionStatement l_es = new ExpressionStatement(fl.getExpression());
        l_es.setParent(fl);
        findBBs(l_es,loopexit);

        bbl = (BasicBlock) scopentrystack.pop();
        switchstack.push(bbl);
        bbl.addSuccessor(loopbody); loopbody.addPredecessor(bbl);
        scopentrystack.push(loopbody);
        findBBs(fl.getBody(),loopexit);

        bbl = (BasicBlock) scopentrystack.pop();
        bbl.addSuccessor(loopexit); loopexit.addPredecessor(bbl);
        scopentrystack.push(loopexit);
        switchstack.pop(); breakstack.pop();

        return ;
      }

      if (stmt instanceof ReturnStatement) {
        ReturnStatement fl = (ReturnStatement) stmt ;
        if (fl.getExpression() != null) {
          ExpressionStatement l_est = new ExpressionStatement(fl.getExpression());
          l_est.setParent(fl);
          findBBs(l_est,succ);
        }
        //Must end the basic block here
        BasicBlock bbl = (BasicBlock) scopentrystack.pop();
        bbl.addSuccessor(exitbb); exitbb.addPredecessor(bbl);
        bbl = new BasicBlock(); bblist.add(bbl);
        scopentrystack.push(bbl);
        return ;
      }
      if (stmt instanceof CompoundStatement) {
        List alist = stmt.getChildren() ;
        for(int i=0;i<alist.size();i++) {
          findBBs((Statement)alist.get(i),succ);
        }
        return ;
      }

      if (stmt instanceof ExpressionStatement) {
        handleExpressionStmt( ( (ExpressionStatement) stmt), pred, succ);
        return;
      }

      if (stmt instanceof DeclarationStatement) {
        return ;
      }

      System.err.println("######REACHED HAZY ZONE######");
      stmt.print(System.err);
      System.err.println("\n######################");

  }

  private void handleExpressionStmt(ExpressionStatement stmt, BasicBlock pred, BasicBlock succ)
  {
    //System.err.println("###");stmt.print(System.err);System.err.println("\n###");
    if (containsFC(stmt)) {
      Expression ex = stmt.getExpression();
      //DepthFirstIterator l_dir = new DepthFirstIterator(ex);
      List l_li = ex.getChildren();
      BasicBlock retblock = new BasicBlock(); bblist.add(retblock);
      BasicBlock callblock = new BasicBlock(); bblist.add(callblock);
      pred.addSuccessor(callblock); callblock.addPredecessor(pred);
      //callblock.cs.addStatement(stmt);
      callblock.statements.add(stmt);
      bbtoadjust.add(callblock);
      for (int i=0;i<l_li.size();i++) {
        Object o = l_li.get(i);
        if (o instanceof FunctionCall) {
          FunctionCall fc = (FunctionCall) o;
          if (fc != null) {
            //Add the functioncall to the proccalls hasmap - adjust later
            Procedure l_pr = fc.getProcedure();
            if (l_pr != null) {
              if (proccalls.containsKey(l_pr)) {
                ArrayList l_ar = (ArrayList) proccalls.get(l_pr);
                l_ar.add(callblock);
              }
              else {
                ArrayList l_ar = new ArrayList();
                l_ar.add(callblock);
                proccalls.put(l_pr, l_ar);
              }
            }
          }
        }
      }
      callblock.addSuccessor(retblock); retblock.addPredecessor(callblock);
      scopentrystack.push(retblock);
    }
    else { //pred.cs.addStatement(stmt);
           pred.statements.add(stmt) ; }

  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    //Create clusters for all the bblocks in terms of procedures
    HashMap p_clusters = new HashMap();
    Iterator l_it = procBB.keySet().iterator();
    while(l_it.hasNext()) {
      p_clusters.put(l_it.next(), new ArrayList());
    }
    for(int i=0;i<bblist.size();i++){
      Procedure l_pr = getProc((BasicBlock)bblist.get(i));
      if (l_pr != null) {
        ArrayList l_ar = (ArrayList) p_clusters.get(l_pr);
        if (l_ar == null) {
          System.err.println("Null array for proc " + l_pr.toString());
        }
        else
          l_ar.add(new Integer(i));
      }
    }
    p.println("digraph G {");
    Iterator l_piter = p_clusters.keySet().iterator() ;
    while (l_piter.hasNext()) {
      Procedure l_p = (Procedure) l_piter.next();
      p.println("subgraph cluster"+l_p.getName().toString()+" { ");
      ArrayList l_bbls = (ArrayList) p_clusters.get(l_p);
      for(int j=0; j<l_bbls.size();j++) {
        p.print(" node"+l_bbls.get(j)+"; ");
      }
      p.println("label = \""+l_p.getName().toString()+"\";}\n");
    }
    ByteArrayOutputStream l_bar = new ByteArrayOutputStream();

    for(int i=0;i<bblist.size();i++) {
      //p.print(bblist.get(i).toString()+" {\n");
      p.print("node"+i+" [label=\"");
      BasicBlock bbl = (BasicBlock) bblist.get(i);

      Tools.printlnList(bbl.statements, l_bar);
      String l_s = l_bar.toString();
      l_s = l_s.replace('{',' ');
      l_s = l_s.replace('}',' ');
      l_s = l_s.replaceAll("\n"," \\\\n");
      l_s = l_s.replace('"','`');

      l_bar.reset();
      p.print(l_s);
      p.println("\"];");
    }
    for(int i=0;i<bblist.size();i++){
      BasicBlock bbl = (BasicBlock) bblist.get(i);
      for(int j=0;j<bbl.succs.size();j++) {
        BasicBlock succ = (BasicBlock) bbl.succs.get(j);
        int k = bblist.indexOf(succ);
        if (k<0) {
          System.err.println("Error, a bblock not found in the list");
        } else {
          p.print("node"+i+"->"+"node"+k+";");
        }
      }
    }

    int start = bblist.indexOf(getRoot());
    if (start < 0)
      start = 0;

    p.println("\nStart->node"+start);
    p.println("Start [shape=Mdiamond] ;");
    p.println("\n}");

  }

  private Procedure getProc(BasicBlock bbl)
  {
    //If bblock has statements, return their procedure, else return procedure
    //of successor
    if(bbl.statements.size() > 0) {
      Statement l_s = (Statement) bbl.statements.get(0);
      return l_s.getProcedure();
    } else {
      if(bbl.succs.size() < 1) {
        if(bbl.preds.size() > 1) {
          System.err.println("Procedure of a bblock not found");
          return null;
        } else {
          return getProc((BasicBlock)bbl.preds.get(0));
        }
      } else {
        return getProc((BasicBlock)bbl.succs.get(0));
      }
    }
  }
}
