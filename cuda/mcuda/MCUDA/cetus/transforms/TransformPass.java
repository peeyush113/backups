package cetus.transforms;

import cetus.hir.*;

public abstract class TransformPass
{
  protected Program program;

  protected TransformPass(Program program)
  {
    this.program = program;
  }

  public abstract String getPassName();

  public static void run(TransformPass pass)
  {
    Tools.printlnStatus(pass.getPassName() + " begin", 1);
    pass.start();
    Tools.printlnStatus(pass.getPassName() + " end", 1);
  }

  public abstract void start();
}
