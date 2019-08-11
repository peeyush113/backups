
package cetus.cctreewalk;

/*This version is specifically designed for C language*/

import java.lang.*;
import java.io.*;
import java.util.*;

class DumpProcessor implements CCTypeEnum
{
	String	dump_file_name;

	String			output_file_name;
	BufferedWriter	output_file		= null;
	boolean			generate_output = false;

	int				ambiguity_node_left = 0;

	public static void main(String[] args) 
	{
		System.out.println("Test the parser-dump processor ...");
		DumpProcessor	app	= new DumpProcessor(args);
		app.run();
	}

	public DumpProcessor(String[] args)
	{
		if (args.length < 1)
		{
			System.out.println("Usage: java DumpProcessor file_name");
			System.exit(1);
		}

		dump_file_name = new String(args[0]);
		if (args.length > 1)
		{
			output_file_name = new String(args[1]);
			generate_output = true;
		}
	}

	public void run()
	{
		System.out.println("reading Syntax nodes from file: " + dump_file_name);

		DumpParser	parser = new DumpParser();
		GeneralSyntaxNode	tree_root = parser.run(dump_file_name);
	
		CCTreeWalk	cc_treewalk = new CCTreeWalk();
		cc_treewalk.setFileName("unknown.c");
		cc_treewalk.run(tree_root);

//		//need to walk the tree again to make sure there's no ambiguity node left
//		System.out.println("\nVerifying the pruned syntax tree ...\n");
//		verify_syntax_tree(tree_root);
//		System.out.println(ambiguity_node_left + " ambiguity node(s) found.");

		if (generate_output == true)
		{
			try
			{
				System.out.println("\nDumping pruned syntax tree ...\n");

				output_file = new BufferedWriter(new FileWriter(output_file_name));
				dump_pruned_tree(tree_root);
				output_file.close();
			}
			catch (IOException err)
			{
				System.out.println("IO Error in DumpProcessor.java: " + err.toString());
			}
		}
		System.out.println("< DONE >\n");
	}

	protected void dump_pruned_tree(GeneralSyntaxNode tree_node) throws IOException
	{
		int num_of_children = tree_node.numOfChildren();
		if (num_of_children <= 0)
		{
			return;
		}

		String line = "\"" + tree_node.getNodeID() + " " + tree_node.getInfoString() + "\" -> { ";
		for (int i=0; i<num_of_children; i++)
		{
			GeneralSyntaxNode	child_node = (GeneralSyntaxNode)(tree_node.getChild(i));
			line += "\"" + child_node.getNodeID() + " " + child_node.getInfoString(); // + "\" ";
			if (child_node.getLineNum() > 0)
			{
				line += " " + child_node.getLineNum();
			}
			line += "\" ";
			dump_pruned_tree(child_node);
		}
		line += "}";
		//now dump itself
		output_file.write(line);
		output_file.newLine();
	}

	protected void verify_syntax_tree(GeneralSyntaxNode tree_node)
	{
		int num_of_children = tree_node.numOfChildren();

		if (tree_node.getTypeCode() == __ambiguity__)
		{
			System.out.println("WARNING: ambiguity node left, NodeID = " + tree_node.getNodeID());
			ambiguity_node_left ++;
		}
		for (int i=0; i<num_of_children; i++)
		{
			GeneralSyntaxNode	child_node = (GeneralSyntaxNode)(tree_node.getChild(i));
			verify_syntax_tree(child_node);
		}
		return;
	}
}