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
public class DriverCUDA2MT extends Driver
{
 
  /**
   * Runs analysis and optimization passes on the program.
   */
  public void runPasses()
  {
    TransformPass.run(new SeparateInitializers(program));
    TransformPass.run(new AnsiDeclarations(program));
    InlineDeviceFunctions.run(program);
    //TransformPass.run(new UniformLoops(program));
    TransformPass.run(new WrapDeviceParams(program));
    //Should be fixed, but it currently needed.
    //TransformPass.run(new SeparateInitializers(program));
    TransformPass.run(new SerializeMicrothreads(program));
    TransformPass.run(new EnforceSyncsMT(program));
    TransformPass.run(new BufferLocalsMT(program));
    ClearCUDASpecs.run(program);
  }

  public DriverCUDA2MT()
  {
    super();
  }
  /**
   * Entry point for Cetus; creates a new Driver object,
   * and calls run on it with args.
   *
   * @param args Command line options.
   */
  public static void main(String[] args)
  {
    (new DriverCUDA2MT()).run(args);
  }
}

