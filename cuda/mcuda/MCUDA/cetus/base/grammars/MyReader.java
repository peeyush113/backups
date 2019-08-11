package cetus.base.grammars;

import java.io.*;
import antlr.*;
import cetus.hir.*;

import java.lang.reflect.*;
import java.util.*;


class MyReader  
{
	public static Method class_print_method;
  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = TranslationUnit.class;
      params[1] = OutputStream.class;
      class_print_method = MyReader.class.getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }
  public static void printlnList(List list, OutputStream stream)
  {
  	Printable pr = null;
    boolean skip = false;
    String pragma = null;
    String value = null;
    PrintStream p = new PrintStream(stream);
    if (list != null)
    {
      Iterator iter = list.iterator();
      while (iter.hasNext()){
      	pr = ((Printable)iter.next());
      	if(pr instanceof Annotation){
      		ByteArrayOutputStream bs = new ByteArrayOutputStream(); 
		    pr.print(bs);
		    pragma = bs.toString();
		    value = pragma.substring(7).trim();
					
			if(value.startsWith("endinclude")){
					skip = false;
						
			}
			else if(value.startsWith("startinclude")){
					skip = true;
					value = value.substring(13) + "\n\n";
					p.print(value);
					 p.println("");
										
			}
			else if(skip == false){
			
      		pr.print(stream);
      		 p.println("");
      		}
				 
						
      	}
      	else if(skip == false){
      	
      		pr.print(stream);
      		 p.println("");
      	}
      }
      
        
    }
  }
  public static void defaultPrint(TranslationUnit tunit, OutputStream stream)
  {
    printlnList(tunit.getChildren(), stream);
  }
  public static void main(String[] args){
	
    String preprocessor = "cpp -C";
	String currfile = null;
	int i = 0;
    for(i =0 ; i < args.length;i++)
    {
	
      File f = null,myf=null;
      String tname = null;
	currfile = args[i];
// pre step to handle header files
	String prename = null;
      try{
		DataInputStream dis = null;
	    dis = new DataInputStream(new FileInputStream(currfile));
		PreCLexer lexer = new PreCLexer ( dis );
		PreCParser parser = new PreCParser ( lexer );
		
			PrintStream old = System.out;
			FileOutputStream myout = null;
			myf = File.createTempFile("cppinput",".c",(new File(currfile)).getAbsoluteFile().getParentFile());
			
			myout = new FileOutputStream(myf);
        	prename = myf.getCanonicalPath();
        	//System.out.println(prename);
			//System.setOut(new PrintStream(myout));
			parser.programUnit(new PrintStream(myout));
			//System.setOut(old);
			
		
    
  	}
    catch ( Exception e )
    {
	 		              System.err.println ( "exception: " + e);
						              e.printStackTrace();
    }
      //System.gc();
      //long before = Runtime.getRuntime().totalMemory();

      /* Run cpp on the input file and output to a temporary file. */

      try {
        f = File.createTempFile("cppoutput",".c");
        tname = f.getCanonicalPath();

//        String cmd = preprocessor + " " + currfile;
	String cmd = preprocessor + " " + prename;
	//System.out.println(cmd);
        Process p = Runtime.getRuntime().exec(cmd);

        BufferedReader inReader = new BufferedReader(new 
          InputStreamReader(p.getInputStream()));

        PrintStream outStream = new PrintStream(new FileOutputStream(f));

        String s = null;
        while ((s = inReader.readLine()) != null)
        {
//        	System.err.println(s);
          outStream.println(s);
        }

        p.waitFor();
      }
      catch (java.io.IOException e) {
        System.err.println("Fatal error creating temporary file: " + e);
        System.exit(1);
      }
      catch (java.lang.InterruptedException e) {
        System.err.println("Fatal error starting preprocessor: " + e);
        System.exit(1);
      }

      NewCLexer lexer = null;
      try {
        lexer = new NewCLexer(new DataInputStream(new FileInputStream(tname)));
        /*
         * Added 6 Feb 2003 
         */
         lexer.setOriginalSource(currfile);
      }
      catch (FileNotFoundException e) {
        System.err.println("Fatal error opening temporary file: " + e);
        System.exit(1);
      }

      lexer.setTokenObjectClass("cetus.base.grammars.CToken");
      lexer.initialize();

      NewCParser parser = new NewCParser(lexer);
	  parser.getPreprocessorInfoChannel(lexer.getPreprocessorInfoChannel());
	  /*
       * Added 6 Feb 2003 
       */
      parser.setLexer(lexer);
      //parser.setASTNodeType(TNode.class.getName());
      //TNode.setTokenVocabulary("cetus.base.grammars.GNUCTokenTypes");
      try {
        TranslationUnit tunit = parser.translationUnit(null);
		
        if (tunit == null)
        {
          System.err.println("Fatal error processing " + currfile);
          /* Delete the temporary file. */                                                                                              
		        f.delete();                                                                                                                   
				      myf.delete();
		  System.exit(1);
        }

        //tunit.setFilename(currfile);
        //tunits.set(i, tunit);
        //tunits.add(tunit);
		//tunit.setProgram(prog);
		
      
      /* remove c extension */
      currfile = currfile.replaceAll("[.]",".new.");
      	
		PrintStream outStream  = null;
      try {
        outStream = new PrintStream(new FileOutputStream(currfile));}
      catch (FileNotFoundException e) {
        System.err.println("could not write output file " + currfile);
        return;
      }
    
	/*
		tunit.setPrintMethod(class_print_method);
		tunit.print(outStream);
	*/
	defaultPrint(tunit,outStream);
      }
	  catch (antlr.TokenStreamException e) {
	  	System.err.println("Unexpected Token while parsing: " +currfile+ e);
		/* Delete the temporary file. */                                                                                              
		      f.delete();                                                                                                                   
			        myf.delete();
		System.exit(1);
	  }
      catch (antlr.RecognitionException e) {
        System.err.println("Fatal error building AST: " + currfile+e);
		/* Delete the temporary file. */                                                                                              
		      f.delete();                                                                                                                   
			        myf.delete();
        System.exit(1);
      }
      /* Delete the temporary file. */
      f.delete();
      myf.delete();
      //System.gc();
      //long after = Runtime.getRuntime().totalMemory();

      //Tools.debugMsg(currfile + " used " + (after - before) + " bytes");
    }
  }
}
