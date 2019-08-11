package cetus.analysis;

import cetus.hir.*;

public abstract class AnalysisPass
{
  protected Program program;

  protected AnalysisPass(Program program)
  {
    this.program = program;
  }

  public abstract String getPassName();

  public static void run(AnalysisPass pass)
  {
    Tools.printlnStatus(pass.getPassName() + " begin", 1);
    pass.start();
    Tools.printlnStatus(pass.getPassName() + " end", 1);
  }

  public abstract void start();
}
