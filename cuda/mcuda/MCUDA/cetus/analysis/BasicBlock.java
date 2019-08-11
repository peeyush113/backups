package cetus.analysis;

import java.util.*;

import cetus.hir.*;

public class BasicBlock
{
  ArrayList statements;
  ArrayList preds;
  ArrayList succs;

  boolean visited = false;
  boolean calladjusted = false;

  public BasicBlock()
  {
    statements = new ArrayList();
    preds = new ArrayList();
    succs = new ArrayList();
  }

  public void addPredecessor(BasicBlock bb)
  {
    preds.add(bb);
  }

  public void addSuccessor(BasicBlock bb)
  {
    succs.add(bb);
  }
}
