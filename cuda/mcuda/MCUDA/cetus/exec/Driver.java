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
public class Driver
{
  /**
   * A mapping from option names to option values.
   */
  protected static CommandLineOptionSet options = new CommandLineOptionSet();

  /**
   * Override runPasses to do something with this object.
   * It will contain a valid program when runPasses is called.
   */
  protected Program program;

  /** The filenames supplied on the command line. */
  protected String[] filenames;

  /**
   * Constructor used by derived classes.
   */
  protected Driver()
  {
    options.add("antlr",
                "Use the antlr parser for C");
    options.add("callgraph",
                "Print the static call graph to stdout");
    options.add("cfg",
                "Print the control-flow graph to stdout");
    options.add("ddt",
                "Perform data dependence tests");
    options.add("echo",
                "Echo source code to stdout as it is processed");
    options.add("expand-user-header",
                "Expand user (non-standard) header file #includes into code");
    options.add("help",
                "Print this message");
    options.add("induction",
                "Perform induction variable substitution");
    options.add("inline", "N",
                "Inline calls to procedures with N statements or fewer");
    options.add("openmp",
                "Insert OpenMP pragmas");
    options.add("outdir", "dirname",
                "Set the output directory name (default is cetus_output)");
    options.add("normalize",
                "Normalize for loops so they begin at 0 and have a step of 1");
    options.add("parse-only",
                "Stop afte parsing; do not analyze or transform");
    options.add("preprocessor", "command",
                "Set the preprocessor command to use");
    options.add("privatize",
                "Perform privatization analysis");
    options.add("procs", "N",
                "Set the number of processors for parallel parsing");
    options.add("reduction",
                "Perform reduction variable analysis");
    options.add("skip-procedures", "proc1,proc2,...",
                "Causes all passes that observe this flag to skip the listed procedures");
    options.add("tloops-to-subroutines",
                "Extract all loops into subroutines");
    options.add("tsingle-call",
                "Transform all statements so they contain at most one function call");
    options.add("tsingle-declarator",
                "Transform all variable declarations so they contain at most one declarator");
    options.add("tsingle-return",
                "Transform all procedures so they have a single return statement"); 
    options.add("usage",
                "Print this message");
    options.add("verbosity", "N",
                "Degree of status messages (0-4) that you wish to see (default is 0)");
    options.add("version",
                "Print the version information");

  }

  /**
   * Returns the value of the given key or null
   * if the value is not set.  Key values are
   * set on the command line as <b>-option_name=value</b>.
   *
   * @return the value of the given key or null if the
   *   value is not set.
   */
  public static String getOptionValue(String key)
  {
    return options.getValue(key);
  }

  /**
   * Returns the set a procedure names that should be
   * excluded from transformations.  These procedure
   * names are specified with the skip-procedures
   * command line option by providing a comma-separated
   * list of names. */
  public static HashSet getSkipProcedureSet()
  {
    HashSet<String> proc_skip_set = new HashSet<String>();

    String s = getOptionValue("skip-procedures");
    if (s != null)
    {
      String[] proc_names = s.split(",");
      for (String name : proc_names)
        proc_skip_set.add(name);
    }

    return proc_skip_set;
  }

  /**
   * Parses command line options to Cetus.
   *
   * @param args The String array passed to main by the system.
   */
  protected void parseCommandLine(String[] args)
  {
    /* print a useful message if there are no arguments */
    if (args.length == 0)
    {
      printUsage();
      System.exit(1);
    }

    /* set default option values */
    setOptionValue("outdir", "cetus_output");
    setOptionValue("preprocessor", "cpp -C");
    setOptionValue("verbosity", "0");

    int i; /* used after loop; don't put inside for loop */
    for (i = 0; i < args.length; ++i)
    {
      String opt = args[i];

      if (opt.charAt(0) != '-')
        /* not an option -- skip to handling options and filenames */
        break;

      int eq = opt.indexOf('=');

      if (eq == -1)
      {
        /* no value on the command line, so just set it to "1" */
        String option_name = opt.substring(1);

        if (options.contains(option_name))
          setOptionValue(option_name, "1");
        else
          System.err.println("ignoring unrecognized option " + option_name);
      }
      else
      {
        /* use the value from the command line */
        String option_name = opt.substring(1, eq);

        if (options.contains(option_name))
          setOptionValue(option_name, opt.substring(eq + 1));
        else
          System.err.println("ignoring unrecognized option " + option_name);
      }
    }

    if (getOptionValue("help") != null || getOptionValue("usage") != null)
    {
      printUsage();
      System.exit(0);
    }

    if (getOptionValue("version") != null)
    {
      printVersion();
      System.exit(0);
    }

    if (i >= args.length)
    {
      System.err.println("No input files!");
      System.exit(1);
    }

    filenames = new String[args.length - i];
    for (int j = 0; j < filenames.length; ++j)
      filenames[j] = args[i++];
  }

  /**
   * Parses all of the files listed in <var>filenames</var>
   * and creates a {@link Program Program} object.
   */
  protected void parseFiles()
  {
    try {
      program = new Program(filenames);
      program.parse();
    } //catch (TreeWalkException e) {
      //System.err.println("failed to build IR from syntax tree");
      //System.err.println(e);
      //System.exit(1);
    //}
    catch (IOException e) {
      System.err.println("I/O error parsing files");
      System.err.println(e);
      System.exit(1);
    } catch (Exception e) {
      System.err.println("Miscellaneous exception while parsing files: " + e);
      e.printStackTrace();
      System.exit(1);
    }
  }

  /**
   * Prints the list of options that Cetus accepts.
   */
  public void printUsage()
  {
    String usage = "cetus.exec.Driver [option]... [file]...\n";
    usage += options.getUsage();
    System.err.println(usage);
  }

  /**
   * Prints the compiler version.
   */
  public void printVersion()
  {
    System.err.println("Cetus 0.5.0 - A Source-to-Source Compiler for C, C++, and Java");
    System.err.println("http://cobweb.ecn.purdue.edu/ParaMount/Cetus");
    System.err.println("Copyright (C) 2002-2007 ParaMount Research Group");
    System.err.println("Purdue University - School of Electrical & Computer Engineering");
  }

  /**
   * Runs this driver with args as the command line.
   *
   * @param args The command line from main.
   */
  public void run(String[] args)
  {
    parseCommandLine(args);

    parseFiles();

    if (getOptionValue("parse-only") != null)
    {
      System.err.println("parsing finished and parse-only option set");
      System.exit(0);
    }

    runPasses();

    Tools.printlnStatus("Printing...", 1);

    try {
      program.print();
    } catch (IOException e) {
      System.err.println("could not write output files: " + e);
      System.exit(1);
    }
  }

  /**
   * Runs analysis and optimization passes on the program.
   */
  public void runPasses()
  {
    /* check for option dependences */

    /* in each set of option strings, the first option requires the
       rest of the options to be set for it to run effectively */
    String[][] pass_prerequisites = { { "inline", "tsingle-call", "tsingle-return" },
                                      { "openmp", "ddt" } };

    for (int i = 0; i < pass_prerequisites.length; ++i)
    {
      if (getOptionValue(pass_prerequisites[i][0]) != null)
      {
        for (int j = 1; j < pass_prerequisites[i].length; ++j)
        {
          if (getOptionValue(pass_prerequisites[i][j]) == null)
          {
            System.out.println("WARNING: " + pass_prerequisites[i][0] + " flag is set but " + pass_prerequisites[i][j] + " is not set");
            System.out.println("WARNING: turning on " + pass_prerequisites[i][j]);
            setOptionValue(pass_prerequisites[i][j], "1");
          }
        }
      }
    }

    if (getOptionValue("callgraph") != null)
    {
      CallGraph cg = new CallGraph(program);
      cg.print(System.out);
    }

    if (getOptionValue("cfg") != null)
    {
      ControlFlowGraph cfg = new ControlFlowGraph(program);
      cfg.print(System.out);
    }

    if (getOptionValue("tsingle-declarator") != null)
    {
      SingleDeclarator.run(program);
    }

    if (getOptionValue("tsingle-call") != null)
    {
      TransformPass.run(new SingleCall(program));
    }

    if (getOptionValue("tsingle-return") != null)
    {
      TransformPass.run(new SingleReturn(program));
    }

    if (getOptionValue("normalize") != null)
    {
      TransformPass.run(new LoopNormalization(program));
    }

    if (getOptionValue("tloops-to-subroutines") != null)
    {
      LoopsToSubroutines.run(program);
    }

    if (getOptionValue("inline") != null)
    {
      Inline.run(program, Integer.valueOf(getOptionValue("inline")).intValue());
    }

    if (getOptionValue("induction") != null)
    {
      TransformPass.run(new Induction(program));
    }

    if (getOptionValue("privatize") != null)
    {
      AnalysisPass.run(new Privatization(program));
    }

    if (getOptionValue("reduction") != null)
    {
      AnalysisPass.run(new Reduction(program));
    }

    if (getOptionValue("ddt") != null)
    {
      AnalysisPass.run(new DDT(program));
    }

    if (getOptionValue("openmp") != null)
    {
      TransformPass.run(new OpenMP(program));
    }

  }

  /**
   * Sets the value of the option represented by <i>key</i> to
   * <i>value</i>.
   *
   * @param key The option name.
   * @param value The option value.
   */
  private static void setOptionValue(String key, String value)
  {
    options.setValue(key, value);
  }

  /**
   * Entry point for Cetus; creates a new Driver object,
   * and calls run on it with args.
   *
   * @param args Command line options.
   */
  public static void main(String[] args)
  {
    (new Driver()).run(args);
  }
}

