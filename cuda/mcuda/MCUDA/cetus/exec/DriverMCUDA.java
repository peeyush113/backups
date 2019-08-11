package cetus.exec;

import java.io.*;
import java.util.*;

import cetus.analysis.*;
import cetus.hir.*;
import cetus.transforms.*;

/**
 * Implements the command line parser and controls pass ordering.
 * Users may extend this class by overriding runPasses
 * (which provides a default sequence of passes).  The derived
 * class should pass an instance of itself to the run method.
 * Derived classes have access to a protected {@link Program Program} object.
 */
public class DriverMCUDA extends Driver
{
 
  /**
   * Runs analysis and optimization passes on the program.
   */
  public void runPasses()
  {
    InlineDeviceFunctions.run(program);
    //Should be fixed, but it currently needed.
    TransformPass.run(new SeparateInitializers(program));
    TransformPass.run(new AnsiDeclarations(program));
    //InlineDeviceFunctions.run(program);
    //TransformPass.run(new UniformLoops(program));
    TransformPass.run(new WrapDeviceParams(program));
    //TransformPass.run(new SeparateInitializers(program));
    TransformPass.run(new SerializeThreads(program));
    TransformPass.run(new EnforceSyncs(program));
    TransformPass.run(new BufferLocals(program));
    if(getOptionValue("Xpilot") != null)
      TransformPass.run(new ScalarDim3(program));
    ClearCUDASpecs.run(program);
  }

  public DriverMCUDA()
  {
    super();
    options.add("mcuda_nolib", 
		"Create an implicitly parallel C program with no execution library");
    options.add("Xpilot", "Enable Xpilot compatibility transformations");
  }
  /**
   * Entry point for Cetus; creates a new Driver object,
   * and calls run on it with args.
   *
   * @param args Command line options.
   */
  public static void main(String[] args)
  {
    (new DriverMCUDA()).run(args);
  }
}

