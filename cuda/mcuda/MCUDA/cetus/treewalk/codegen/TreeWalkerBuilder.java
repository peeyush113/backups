
package cetus.treewalk.codegen;

import java.lang.*;
import java.io.*;
import java.util.*;

import cetus.treewalk.*;

public class  TreeWalkerBuilder
{
  BufferedReader  grammar_input;

  BufferedWriter  treewalk_base_output;
  BufferedWriter  treewalk_output;

  public static void main(String[] args) 
  {
    TreeWalkerBuilder  app = new TreeWalkerBuilder(args);
    app.run();
  }

  public TreeWalkerBuilder(String[] args)
  {
    if (args.length < 1)
    {
      printUsage();
      System.exit(1);
    }

    System.out.println("\nInput Grammar File: " + args[0] + "\nOutput Java File: \nCCTreeWalkBase.java -- Tree walk framework;\nCCTreeWalk.java -- Semantic routines;\n");

    try
    {
      grammar_input      = new BufferedReader(new FileReader(args[0]));
      treewalk_base_output  = new BufferedWriter(new FileWriter("CCTreeWalkBase.java"));
      treewalk_output      = new BufferedWriter(new FileWriter("CCTreeWalk.java"));

      if (grammar_input == null)
      {
        System.out.println("Unable to open input grammar file: " + args[0]);
        System.exit(1);
      }
      if (treewalk_base_output == null
        || treewalk_output == null)
      {
        System.out.println("Unable to write to CCTreeWalkBase.java or CCTreeWalk.java");
        System.exit(1);
      }
    }
    catch (IOException err)
    {
      System.out.println("I/O error in constructor: " + err.toString());
      System.exit(1);
    }
  }

  public void run()
  {
    ArrayList  list_of_productions = new ArrayList(150);

    String parser_src = "import java.lang.*;\nimport java.util.*;\n\nabstract public class CCTreeWalkBase implements CCTypeEnum\n{\n    protected static final int __ACTION_BEFORE__ = 0;\n    protected static final int __ACTION_AFTER__ = 1;\n\n    public CCTreeWalkBase()\n    {\n    }\n\n    public GeneralSyntaxNode run(GeneralSyntaxNode tree_root)\n    {\n        System.out.println(\"Start Walking the tree to solve ambiguities:\");\n        process_translation_unit(tree_root);\n\n        return tree_root;\n    }\n\n";
    parser_src += "    protected void errorExit(String _error_msg)\n    {\n        System.out.println(_error_msg);\n        System.exit(1);\n    }\n\n";
    
    String semantic_src = "import java.lang.*;\nimport java.util.*;\n\npublic class CCTreeWalk extends CCTreeWalkBase\n{\n    protected boolean debug_display = false;\n\n    public CCTreeWalk()\n    {\n        super();\n    }\n\n";

    try
    {
      String line;
      Production temp_production = null;  //temp pointer to a Production
      while ((line = grammar_input.readLine()) != null)
      {
        line = line.trim();
        if (line.length() > 0)
        {
          if (line.endsWith(":"))
          {
            String typename = line.substring(0, line.length()-1);
            temp_production = new Production(typename);
          }
          else if (line.equals(";"))
          {
            if (temp_production != null)
            {
              list_of_productions.add(temp_production);
            }
            temp_production = null;
          }
          else
          {
            if (line.startsWith("|") == true)
            {
              line = line.substring(1).trim();
            }
            temp_production.addRHS(line);
          }
        }
      }

      //now sort the productions
      int num_productions        = list_of_productions.size();
      Object[] array_of_productions  = list_of_productions.toArray();
      Arrays.sort(array_of_productions);

      //now generate code for each production
      CCSymbol2Name  sym_name_pool = new CCSymbol2Name();

      CCTypeHash    type_hash = new CCTypeHash();

      String semantic_action_prototypes = "";  //used to hold the abstract methods for the time being

      for (int i=0; i<num_productions; i++)
      {
        boolean has_ambiguity = false;
        temp_production = (Production)array_of_productions[i];
        System.out.print("\rGenerating code for production #" + (i+1) + ": [" + temp_production.LHS + "]                ");
        parser_src += "    protected boolean process_" + temp_production.LHS + "(GeneralSyntaxNode node)\n    {\n        int num_of_children = node.numOfChildren();\n\n";

        //now generate calls to each non-terminal child

        //all possible productions sharing the same LHS
        //generate section of code for each RHS entry
        int rhs_size = temp_production.RHS.size();
        for (int j = 0; j<rhs_size; j++)
        {
          String  semantic_action = "action____" + temp_production.LHS;  //semantic action

          String  rhs        = ((String)(temp_production.RHS.get(j))).trim();
          
          //handle two special cases -- empty and ambiguity
          //empty and ambiguity don't need to distinguish BEFORE and AFTER
          if (rhs.equals("/*empty*/") 
            || rhs.equals("/* empty */")
            || rhs.equals("/* empty*/")
            || rhs.equals("/*empty */"))
          {
            semantic_action += "__empty";

            String temp_parser_src = "";

            temp_parser_src += "        if (num_of_children == " + 0 + ")\n";
            temp_parser_src += "        {\n";
            temp_parser_src += "            boolean action_result = " + semantic_action + "(node);\n";
            temp_parser_src += "            if (action_result == true)\n";
            temp_parser_src += "            {\n";
            temp_parser_src += "                return true;\n";
            temp_parser_src += "            }\n";
            temp_parser_src += "            else\n";
            temp_parser_src += "            {\n";
            temp_parser_src += "                return false;\n";
            temp_parser_src += "            }\n";
            temp_parser_src += "        }\n\n";
            parser_src += temp_parser_src;

            String temp_semantic_src = "";
            temp_semantic_src += "    protected boolean " + semantic_action + "(GeneralSyntaxNode node)\n";
            semantic_action_prototypes += "    abstract protected boolean " + semantic_action + "(GeneralSyntaxNode node);\n";

            temp_semantic_src += "    {\n        if (debug_display == true)\n        {\n            System.out.println(\"Hit " + semantic_action + "() NodeID = \" + node.getNodeID());\n        }\n\n";
            temp_semantic_src += "        errorExit(\"" + semantic_action + "() hasn't been implemented yet.\");\n";
            temp_semantic_src += "        return false;\n";
            temp_semantic_src += "    }\n\n";
            
            semantic_src += temp_semantic_src;

            continue;
          }
          else if (rhs.equals("ambiguity") == true)
          {
            has_ambiguity = true;
            continue;
          }
/* ---- ambiguities will be handled in the default semantic action routines
          else if (rhs.equals("ambiguity") == true)
          {
            semantic_action += "__ambiguity";

            parser_src += "        if (num_of_children == " + 1 + ")\n";
            parser_src += "        {\n";
            parser_src += "            GeneralSyntaxNode child_1 = (GeneralSyntaxNode)(node.getChild(0));\n";
            parser_src += "            int child_1_type = child_1.getTypeCode();\n";
            parser_src += "            if (child_1_type == __ambiguity__)\n";
            parser_src += "            {\n";
            parser_src += "                boolean action_result = " + semantic_action + "(node);\n";  //the node itself will be passed into the semantic action routine
            parser_src += "                if (action_result == true)\n";
            parser_src += "                {\n";
            parser_src += "                    return true;\n";
            parser_src += "                }\n";
            parser_src += "                else\n";
            parser_src += "                {\n";
            parser_src += "                    System.out.println(\"CAUTION: [" + temp_production.LHS + "] --> [ambiguity] unsolved !\");\n";
            parser_src += "                    return false;\n";
            parser_src += "                }\n";
            parser_src += "            }\n";
            parser_src += "        }\n\n";

            semantic_src += "    protected boolean " + semantic_action + "(GeneralSyntaxNode node)\n";
            semantic_action_prototypes += "    abstract protected boolean " + semantic_action + "(GeneralSyntaxNode node);\n";

            semantic_src += "    {\n        if (debug_display == true)\n        {\n            System.out.println(\"Hit " + semantic_action + "(GeneralSyntaxNode node)\");\n        }\n\n";
            semantic_src += "        errorExit(\"" + semantic_action + "(GeneralSyntaxNode node) hasn't been implemented yet.\");\n";
            semantic_src += "        return false;\n";
            semantic_src += "    }\n\n";
            
            continue;
          }
*/
          //now let's handle the general case in a quite similar way, but need to handle the calls to the non-terminal children
          StringTokenizer rhs_st    = new StringTokenizer(rhs, " \t\n\r\f");
          int        num_elem  = rhs_st.countTokens();

          parser_src += "        if (num_of_children == " + num_elem + ")\n";
          parser_src += "        {\n";
          //get all the children nodes
          for (int k = 0; k < num_elem; k++)
          {
            parser_src += "            GeneralSyntaxNode  child_" + (k + 1) + " = (GeneralSyntaxNode)(node.getChild(" + k + "));\n";
            parser_src += "            int  child_" + (k+1) + "_type = child_" + (k+1) + ".getTypeCode();\n";
          }

          String  ftn_calls = "";    //calling the children
          String  test_result = "                if (";    //test return value of semantic action

          //check the children types        
          parser_src += "\n            if (";
          boolean    children_called = false;
          for (int k = 0; k < num_elem; k++)
          {
            String child = rhs_st.nextToken().trim();  //pick a RHS element

            //need to translate the symbol ends with '' into their corresponding names
            if (child.startsWith("'") && child.endsWith("'"))
            {
              child = child.substring(1, child.length()-1);
            }
            String child_name = sym_name_pool.getName(child).trim();

            semantic_action += "__" + child_name;  //add the non-terminal, keyword, or the name of the sym

            int child_type = type_hash.getEnumValue(child);
            //non-terminals and symbols will be correct, capitalized keywords will not be recognized
            if (child_type >=1 && child_type < 1000)  //must be a non-terminal, need to call process routine
            {
              children_called = true;
              ftn_calls += "                boolean result_" + (k+1) + " = process_" + child_name + "(child_" + (k+1) + ");\n";
              test_result += "result_" + (k+1);
            }
            else  //unknown type, keyword, or symbol op, etc. leaf already, ignore
            {
              test_result += "true";
            }

            parser_src += "child_" + (k+1) + "_type == __" + child_name + "__";  //good for non-terminals, keywords, and symbols
            if (k < num_elem - 1)
            {
              parser_src += "\n               &&";
              test_result += " && ";
            }
            else
            {
              parser_src += ")\n            {\n";
              test_result += ")\n                {\n                    return true;\n                }\n                else\n                {\n                    System.out.println(\"CAUTION: [" + temp_production.LHS + "] --> [" + rhs + "] returns false.\");\n" + "                    return false;\n                }\n";
            }            
          }

          if (children_called == true)
          {
            parser_src += "                boolean action_result_before = " + semantic_action + "(node, __ACTION_BEFORE__);\n\n";
            parser_src += ftn_calls;
            parser_src += "\n                boolean action_result_after = " + semantic_action + "(node, __ACTION_AFTER__);\n\n";
            parser_src += "                if ((action_result_before && action_result_after) == false)\n";
          }
          else
          {
            parser_src += "                boolean action_result = " + semantic_action + "(node);\n\n";
            parser_src += "                if (action_result == false)\n";
          }

          parser_src += "                {\n";
          parser_src += "                    return false;\n";
          parser_src += "                }\n";
          parser_src += test_result;
          parser_src += "            }\n";
          parser_src += "        }\n\n";

          String temp_src = "";
          if (children_called == true)
          {
            temp_src += "    protected boolean " + semantic_action + "(GeneralSyntaxNode node, int __action_status__)\n";
          }
          else
          {
            temp_src += "    protected boolean " + semantic_action + "(GeneralSyntaxNode node)\n";
          }

          temp_src += "    {\n        if (debug_display == true)\n        {\n            System.out.println(\"Hit " + semantic_action + "() NodeID = \" + node.getNodeID());\n        }\n\n";
          temp_src += "        errorExit(\"" + semantic_action + "() hasn't been implemented yet.\");\n";
          temp_src += "        return false;\n";
          temp_src += "    }\n\n";
          semantic_src += temp_src;

          if (children_called == true)
          {
            semantic_action_prototypes += "    abstract protected boolean " + semantic_action + "(GeneralSyntaxNode node, int __action_status__);\n";
          }
          else
          {
            semantic_action_prototypes += "    abstract protected boolean " + semantic_action + "(GeneralSyntaxNode node);\n";
          }
        }

/*
        parser_src += "        System.out.println(\"CAUTION: [" + temp_production.LHS + "] has invalid children. [\" + num_of_children + \" child(ren) ]\");\n";
        parser_src += "        return false;\n";
*/
        parser_src += "        return action____" + temp_production.LHS + "__default_semantic_action(node);\n";

        semantic_src += "    protected boolean action____" + temp_production.LHS + "__default_semantic_action(GeneralSyntaxNode node)\n";
        semantic_src += "    {\n        if (debug_display == true)\n        {\n            System.out.println(\"Hit action____" + temp_production.LHS + "__default_semantic_action() NodeID = \" + node.getNodeID());\n        }\n\n";
        if (has_ambiguity == true)
        {
          semantic_src += "//------- You need to handle ambiguity here -------//\n";
        }
        semantic_src += "        errorExit(\"action____" + temp_production.LHS + "__default_semantic_action() hasn't been implemented yet.\");\n";
        semantic_src += "        return false;\n";
        semantic_src += "    }\n\n";

        semantic_action_prototypes += "    abstract protected boolean action____" + temp_production.LHS + "__default_semantic_action(GeneralSyntaxNode node);\n";

        parser_src += "    }\n\n";
      }
      System.out.println();

      parser_src += semantic_action_prototypes + "\n";
      parser_src += "}\n\n";
      semantic_src += "}\n\n";

      //now write to the files
      writeMessage(treewalk_base_output, parser_src);
      writeMessage(treewalk_output, semantic_src);          
    }
    catch (IOException err)
    {
      System.out.println("I/O Error: " + err.toString());
      System.exit(1);  
    }

    end();
  }

  protected void end()
  {
    try
    {
      treewalk_base_output.close();
      treewalk_output.close();      
    }
    catch (IOException err)
    {
      System.out.println("Error, Unable to close files:\n" + err.toString());
      System.exit(1);
    }
  }

  protected void writeMessage(BufferedWriter _output_file, String str)
  {
    try
    {
      _output_file.write(str);
      _output_file.newLine();
    }
    catch (IOException  err)
    {
      System.out.println("I/O Error: " + err.toString());
      System.exit(1);
    }
  }

  protected void printUsage()
  {
    System.out.println("Usage: TreeWalkerBuilder input_grammar_file");
  }

}
