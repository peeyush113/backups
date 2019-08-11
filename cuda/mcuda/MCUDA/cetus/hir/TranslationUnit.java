package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

import cetus.base.grammars.*;
import cetus.exec.*;
import cetus.treewalker.*;

/**
 * Represents a single source file of the program.
 * A TranslationUnit is a collection of Declarations
 * and DeclarationStatements. The compilation of a
 * Program may involve several TranslationUnits.
 */
public final class TranslationUnit
  implements Printable, SymbolTable, Traversable
{
  private static Method class_print_method;
  private Method object_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = TranslationUnit.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /** The name of the original source file. */
  private String input_filename;

  /** The name of the modified source file. */
  private String output_filename;

  /** The parent Program object. */
  private Traversable parent;

  /** A list of Declarations and DeclarationStatements. */
  private LinkedList<Traversable> children;

  /** Maps IDExpressions to Declarations. */
  private HashMap<IDExpression,Declaration> symbol_table;

  /** This nested class continuously reads from the output
   * or error stream of an external parser and reproduces
   * the data on the JVM's output or error stream.
   */
  private class PipeThread extends Thread
  {
    private BufferedReader source;
    private PrintStream dest;

    PipeThread(BufferedReader source, PrintStream dest)
    {
      this.source = source;
      this.dest = dest;
    }

    public void run()
    {
      String s = null;
      try {
        while ((s = source.readLine()) != null)
          dest.println(s);
      } catch (IOException e) {
        dest.println("cetus: I/O error on redirection, " + e);
      }
    }
  }

  /**
   * Create an empty translation unit associated with a file.
   *
   * @param input_filename The file name for this TranslationUnit
   */
  public TranslationUnit(String input_filename)
  {
    object_print_method = class_print_method;

    this.input_filename = input_filename;

    /* form the output filename by taking the filename portion of the input name
       and prepending the output directory name */
    int last_slash = input_filename.lastIndexOf('/');
    this.output_filename = Driver.getOptionValue("outdir") + "/"
      + input_filename.substring(last_slash + 1);

    /* This is null because the translation unit doesn't belong to a program yet. */
    parent = null;
    children = new LinkedList();
    symbol_table = new HashMap();
  }

  public void addDeclaration(Declaration decl)
  {
    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      /* these two need followed by a semicolon, so they must be
         declaration statements */
      DeclarationStatement stmt = new DeclarationStatement(decl);
      children.add(stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(decl);
      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  public void addFirstDeclaration(Declaration decl)
  {
    if (decl.getParent() != null)
      throw new NotAnOrphanException();

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      /* these two need followed by a semicolon, so they must be
         declaration statements */
      DeclarationStatement stmt = new DeclarationStatement(decl);
      children.add(0, stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(0, decl);
      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  public void addDeclarationBefore(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    /* the reference declaration may have been turned into a
       declaration statement, so look for that if the first search
       fails */
    if (index == -1)
    {
      if (ref.getParent() instanceof DeclarationStatement)
        index = Tools.indexByReference(children, ref.getParent());

      /* if we still can't find it, then it's not a valid reference point */
      if (index == -1)
        throw new IllegalArgumentException();
    }

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      /* these two need followed by a semicolon, so they must be
         declaration statements */
      DeclarationStatement stmt = new DeclarationStatement(decl);
      children.add(index, stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(index, decl);
      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  public void addDeclarationAfter(Declaration ref, Declaration decl)
  {
    int index = Tools.indexByReference(children, ref);

    if (index == -1)
    {
      if (ref.getParent() instanceof DeclarationStatement)
        index = Tools.indexByReference(children, ref.getParent());

      if (index == -1)
        throw new IllegalArgumentException();
    }

    if (decl instanceof VariableDeclaration
        || decl instanceof Enumeration)
    {
      /* these two need followed by a semicolon, so they must be
         declaration statements */
      DeclarationStatement stmt = new DeclarationStatement(decl);
      children.add(index + 1, stmt);
      stmt.setParent(this);
    }
    else
    {
      children.add(index + 1, decl);
      decl.setParent(this);
    }

    Tools.addSymbols(this, decl);
  }

  /**
   * Prints a translation unit to a stream.
   *
   * @param tunit The translation unit to print.
   * @param stream The stream on which to print the translation unit.
   */
  public static void defaultPrint(TranslationUnit tunit, OutputStream stream)
  {
    Tools.printlnList(tunit.children, stream);
  }

  public Declaration findSymbol(IDExpression name)
  {
    return Tools.findSymbol(this, name);
  }

  public List getChildren()
  {
    return children;
  }

  /**
   * Returns the original filename for the translation unit.
   *
   * @return the original filename for the translation unit.
   */
  public String getInputFilename()
  {
    return input_filename;
  }

  /**
   * Returns the filename for the modified version of the translation unit.
   *
   * @return the filename for the modified version of the translation unit.
   */
  public String getOutputFilename()
  {
    return output_filename;
  }

  public Traversable getParent()
  {
    return parent;
  }

  public List getParentTables()
  {
    return Tools.getParentTables(this);
  }

  public HashMap getTable()
  {
    return symbol_table;
  }

  /**
   * Parse this translation unit.
   *
   * @throws IOException if there is a problem accessing any file.
   */
  public void parse() throws IOException
  {
    if (Driver.getOptionValue("antlr") != null)
      parseAntlr();
    else
      parseExternal();
  }

  /**
   * Parse the associated input file using the Antlr 
   * parser and create IR for this translation unit.
   *
   * @throws IOException if there is any problem accessing the file.
   */
  protected void parseAntlr()
  {
    String currfile = input_filename;
    String filename = null;
    File f = null,myf=null;
    byte[] barray = null;
      //InputStream source = null;  
      // pre step to handle header files
      // Insert markers for start and end of a header file
    String prename = null;

    /* Create the Antlr-derived lexer and parser through the ClassLoader
       so antlr.jar will be required only if the Antlr parser is used. */

    Class[] params = new Class[1];
    Object[] args = new Object[1];

    try  {
      Class class_PreCLexer  = getClass().getClassLoader().loadClass("cetus.base.grammars.PreCLexer");
      params[0] = InputStream.class;
      args[0] = new DataInputStream(new FileInputStream(currfile));
      PreCLexer lexer = (PreCLexer)class_PreCLexer.getConstructor(params).newInstance(args);

      Class class_PreCParser = getClass().getClassLoader().loadClass("cetus.base.grammars.PreCParser");
      params[0] = getClass().getClassLoader().loadClass("antlr.TokenStream");
      args[0] = lexer;
      PreCParser parser = (PreCParser)class_PreCParser.getConstructor(params).newInstance(args);

      File dir = new File (".");
      String currdir = dir.getCanonicalPath();
  
      File ff = new File(currfile);
      filename = ff.getName();
      prename = "cppinput_" + filename;
      myf = new File(currdir, prename);
      myf.deleteOnExit();    
      FileOutputStream fo = new FileOutputStream(myf);
      parser.programUnit(new PrintStream(fo));
      fo.close();
    } catch (ClassNotFoundException e) {
      System.err.println("cetus: could not load class " + e);
      System.exit(1);
    } catch (NoSuchMethodException e) {
      System.err.println("cetus: could not find constructor " + e);
      System.exit(1);
    } catch (IllegalAccessException e) {
      System.err.println("cetus: could not access constructor " + e);
      System.exit(1);
    } catch (InstantiationException e) {
      System.err.println("cetus: constructor failed " + e);
      System.exit(1);
    } catch (FileNotFoundException e) {
      System.err.println("cetus: could not read input file " + e);
      System.exit(1);
    } catch (IOException e) {
      System.err.println("cetus: could not create intermdiate output file " + e);
      System.exit(1);
    } catch (Exception e) {
      System.err.println("cetus: exception: " + e);
      e.printStackTrace();
      System.exit(1);
    }

    // Run cpp on the input file and output to a temporary file. 

    try {
      ByteArrayOutputStream bo = new ByteArrayOutputStream(50000);
      PrintStream outStream = new PrintStream(bo);

      String cmd = Driver.getOptionValue("preprocessor") + " " + prename;
      Process p = Runtime.getRuntime().exec(cmd);
  
      BufferedReader inReader = new BufferedReader(new InputStreamReader(p.getInputStream()));
      BufferedReader errReader = new BufferedReader(new InputStreamReader(p.getErrorStream()));  

      PipeThread out_pipe = new PipeThread(inReader, outStream);
      PipeThread err_pipe = new PipeThread(errReader, System.err);

      out_pipe.start();
      err_pipe.start();

      if (p.waitFor() != 0)
      {
        System.err.println("cetus: preprocessor terminated with exit code " + p.exitValue());
        System.exit(1);
      }

      out_pipe.join();
      err_pipe.join();

      barray = bo.toByteArray();

      //----------------
      //System.out.write(barray, 0, Array.getLength(barray));

    } catch (java.io.IOException e) {
      System.err.println("Fatal error creating temporary file: " + e);System.exit(1);
    } catch (java.lang.InterruptedException e) {
      System.err.println("Fatal error starting preprocessor: " + e);System.exit(1);
    } 
  
    // Actual antlr parser is called

    try {
      Class class_NewCLexer = getClass().getClassLoader().loadClass("cetus.base.grammars.NewCLexer");
      params[0] = InputStream.class;
      args[0] = new DataInputStream(new ByteArrayInputStream(barray));
      NewCLexer lexer = (NewCLexer)class_NewCLexer.getConstructor(params).newInstance(args);

      lexer.setOriginalSource(filename);
      lexer.setTokenObjectClass("cetus.base.grammars.CToken");
      lexer.initialize();

      Class class_NewCParser = getClass().getClassLoader().loadClass("cetus.base.grammars.NewCParser");
      params[0] = getClass().getClassLoader().loadClass("antlr.TokenStream");
      args[0] = lexer;
      NewCParser parser = (NewCParser)class_NewCParser.getConstructor(params).newInstance(args);

      parser.getPreprocessorInfoChannel(lexer.getPreprocessorInfoChannel());
      parser.setLexer(lexer);
      parser.translationUnit(this);
    } catch (Exception e) {
      System.err.println("Parse error: " + e);
      System.exit(1);
    }

    try {
      Class[] pparams = new Class[2];
      pparams[0] = TranslationUnit.class;
      pparams[1] = OutputStream.class;
      object_print_method = pparams[0].getMethod("defaultPrint2", pparams);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  /**
   * Parse the associated input file using an external
   * parser and create IR for this translation unit.
   *
   * @throws IOException if there is any problem accessing the file.
   */
  protected void parseExternal() throws IOException
  {
    /* parser can be a symlink to any parser program that can dump
       parse trees in graphviz format.  If your parser does not
       accept the arguments below, we suggest that you make parser a
       symlink to an executable shell script that does what you want.
       (Or, you could just hack this code and recompile Cetus.) */

    Vector<String> cmd = new Vector<String>();

    cmd.add("./parser");
    cmd.add("--dump-parse-trees");

    if (Driver.getOptionValue("echo") != null)
      cmd.add("--echo");

    /* The preprocessor is either cpp -C or gcc -E but they are specified as
       simply "cpp" or "gcc".  Passing "--preprocessor='cpp -C'" on the
       command-line causes many programs to parse that as two arguments, with
       the second being -C'".  It's up to the parser program itself to add
       preprocessor flags when it invokes the preprocessor. */
    cmd.add("--preprocessor=" + Driver.getOptionValue("preprocessor"));
    cmd.add(input_filename);

    try {
      Process p = Runtime.getRuntime().exec(cmd.toArray(new String[1]));

      /* read the parser's output stream */
      /* Note: Yes, this is reading the output stream even though it says getInputStream.
         Sun's naming conventions are weird like that. */
      BufferedReader parser_stdout = new BufferedReader(new InputStreamReader(p.getInputStream()));

      /* read the parser's error stream */
      BufferedReader parser_stderr = new BufferedReader(new InputStreamReader(p.getErrorStream()));

      /* Redirect all output from the parser to the JVM's output and error streams. */
      PipeThread out_pipe = new PipeThread(parser_stdout, System.out);
      PipeThread err_pipe = new PipeThread(parser_stderr, System.err);

      out_pipe.start();
      err_pipe.start();

      /* Wait on the parser to finish. */
      if (p.waitFor() != 0)
      {
        System.err.println("cetus: parser terminated with exit code " + p.exitValue());
        System.exit(1);
      }

      out_pipe.join();
      err_pipe.join();
    } catch (InterruptedException e) {
      System.err.println("cetus: interrupted waiting for parser to finish");
    }

    if (input_filename.endsWith(".cc") || input_filename.endsWith(".cpp"))
    {
      /* C++ */

      DagParser dag_parser = new DagParser();
      TreeNode tree_root = dag_parser.run(input_filename + ".dag");

      CCTreeWalker cc_treewalk = new CCTreeWalker(input_filename);
      TranslationUnit tu = cc_treewalk.run(tree_root);

      children = tu.children;
      for (Traversable t : children)
        t.setParent(this);

      symbol_table = tu.symbol_table;
    }
    else if (input_filename.endsWith(".c"))
    {
      /* C */

      DagParser dag_parser = new DagParser();
      TreeNode tree_root = dag_parser.run(input_filename + ".dag");

      CTreeWalker c_treewalk = new CTreeWalker(input_filename);
      TranslationUnit tu = c_treewalk.run(tree_root);

      children = tu.children;
      for (Traversable t : children)
        t.setParent(this);

      symbol_table = tu.symbol_table;
    }
    else
    {
      System.out.println("File name \"" + input_filename + "\" is not a valid C or C++ filename. Quitting ...\n");
      System.exit(1);
    }
  }

  public static void defaultPrint2(TranslationUnit tunit, OutputStream stream)
  {
    Printable pr = null;
    boolean skip = false;
    String pragma = null;
    String value = null;
    PrintStream p = new PrintStream(stream);
    String expand = Driver.getOptionValue("expand-user-header");

    Iterator iter = tunit.children.iterator();
    while (iter.hasNext())
    {
      pr = ((Printable)iter.next());
      if (pr instanceof Annotation)
      {
        ByteArrayOutputStream bs = new ByteArrayOutputStream(); 
        pr.print(bs);
        pragma = bs.toString();
   
        if (pragma.length() >= 7)
          value = pragma.substring(7).trim();
        else
          value = pragma;

        if (value.startsWith("endinclude"))
        {
          if (expand == null || (value.indexOf("\"") == -1 && value.indexOf(">") == -1))
	  //if (expand == null || value.indexOf("\"") == -1)
            skip = false;
        }
        else if (value.startsWith("startinclude"))
        {
          if (expand == null || (value.indexOf("\"") == -1 && value.indexOf("<") == -1))
	  //if (expand == null || value.indexOf("\"") == -1)
	  {
            skip = true;
            value = value.substring(13) + "\n\n";
            p.print(value);
            //p.println("");
          }
        }
        else if (skip == false)
        {
          pr.print(stream);
          p.println("");
        }          
      } // end if(pr instance of Annotation)
      else if (skip == false)
      {
        pr.print(stream);
        p.println("");
      }
    }
  }

  /**
   * Prints this translation unit to the output file with which it is
   * associated.
   *
   * @throws FileNotFoundException if an output file could not be opened.
   */
  public void print() throws FileNotFoundException
  {
    print(new FileOutputStream(output_filename));
  }

  public void print(OutputStream stream)
  {
    if (object_print_method == null)
      return;

    Object[] args = new Object[2];
    args[0] = this;
    args[1] = stream;

    try {
      object_print_method.invoke(null, args);
    } catch (IllegalAccessException e) {
      System.err.println(e);
      e.printStackTrace();
    } catch (InvocationTargetException e) {
      System.err.println(e.getCause());
      e.printStackTrace();
    }
  }

  public void removeChild(Traversable child)
  {
    int index = Tools.indexByReference(children, child);

    if (index == -1)
      throw new NotAChildException();

    child.setParent(null);
    children.remove(index);

    /* removing a declaration removes the declared symbols */
    if (child instanceof Declaration)
      Tools.removeSymbols(this, (Declaration)child);
    else if (child instanceof DeclarationStatement)
      Tools.removeSymbols(this, ((DeclarationStatement)child).getDeclaration());
  }

  public void setChild(int index, Traversable t)
  {
    if (t.getParent() != null)
      throw new NotAnOrphanException();

    /* detach the old child at position index and remove any declared symbols */
    Traversable old = (Traversable)children.get(index);

    old.setParent(null);

    if (old instanceof Declaration)
      Tools.removeSymbols(this, (Declaration)old);
    else if (old instanceof DeclarationStatement)
      Tools.removeSymbols(this, ((DeclarationStatement)old).getDeclaration());

    if (t instanceof VariableDeclaration
        || t instanceof Enumeration)
    {
      /* these two need followed by a semicolon, so they must be
         declaration statements */
      DeclarationStatement stmt = new DeclarationStatement((Declaration)t);
      children.set(index, stmt);
      stmt.setParent(this);
    }
    else if (t instanceof Declaration
             || t instanceof DeclarationStatement)
    {
      children.set(index, t);
      t.setParent(this);
    }
    else
      throw new IllegalArgumentException();
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

  /**
   * Sets the output filename for the translation unit.
   *
   * @param output_filename The output filename for the translation unit.
   */
  public void setOutputFilename(String output_filename)
  {
    this.output_filename = output_filename;
  }

  /**
   * Sets the parent program for this translation unit.
   * @param t The parent program.
   */
  public void setParent(Traversable t)
  {
    if (!t.getChildren().contains(this))
      throw new NotAChildException();

    if (t instanceof Program)
      parent = t;
    else
      throw new IllegalArgumentException();
  }

  /**
   * Overrides the print method for this object only.
   *
   * @param m The new print method.
   */
  public void setPrintMethod(Method m)
  {
    object_print_method = m;
  }
}
