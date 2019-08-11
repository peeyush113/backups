
package cetus.cctreewalk;

//this parser takes the dump text line by line and create the tree
import java.lang.*;
import java.util.*;
import java.io.*;

public class DumpParser
{
	Hashtable	node_table;

	public DumpParser()
	{
		node_table = new Hashtable(1000);
	}

	//returns the root of the syntax tree
	public GeneralSyntaxNode run(String	_dump_file_name)
	{
		int	count_nodes = 0;

		GeneralSyntaxNode	tree_root = null;

		try
		{
			BufferedReader	dump_file	= new BufferedReader(new FileReader(_dump_file_name));
			String			line		= dump_file.readLine();	//skip the first line, you must have already known the file name

			while ((line = dump_file.readLine()) != null)
			{
				//ignore empty lines
				if (line.trim().length() > 4)
				{
					tree_root = parseLine(line);
					count_nodes ++;
				}
			}

			dump_file.close();
			System.out.println(count_nodes + " nodes parsed");

			//now tree_root should point to the root of the syntax tree
			if (node_table.size() != 1)
			{
				System.out.println("DumpParser Error: " + _dump_file_name + " ends up with " + node_table.size() + " root(s) !");
				System.exit(1);
			}
		}
		catch (IOException err)
		{
			System.out.println("I/O Error: " + err.toString());
			System.exit(1);
		}

		return tree_root;
	}

	class NodeBase
	{
		int		NodeID;
		String	NodeInfo;

		public NodeBase(int _NodeID, String _NodeInfo)
		{
			NodeID		= _NodeID;
			NodeInfo	= new String(_NodeInfo);
		}
	};

	//returns the LHS node, the final return should be the root
	public GeneralSyntaxNode parseLine(String _line)
	{
//Oct 20, 03, patch to the \"fdfdf\" problem in the string literal, \"abcd\" in the dump should be interpreted as "abcd"
		//_line = _line.replaceAll("\\\\\"", "\"");
		//change it in GeneralSyntaxNode, which is much easier to handle

		CCTypeHash		typename_hash	= new CCTypeHash();

		String			line	= new String(_line);

		//for debugging purposes
		//System.out.println("Input: " + line);

		//divide into LHS and RHS
		int		left_end_index	= line.indexOf("->");
		String	LHS				= line.substring(0, left_end_index);
		String	RHS_temp		= line.substring(left_end_index + 2);

		//get rid of the starting and ending brackets in RHS
		int		start_bracket	= RHS_temp.indexOf('{');
		int		end_bracket		= RHS_temp.lastIndexOf('}');
		String	RHS				= RHS_temp.substring(start_bracket + 1, end_bracket); //string without {}

		//LHS format is relatively simple
		StringTokenizer st_2		= new StringTokenizer(LHS, "\" ");
		int			LHS_node_id		= Integer.parseInt(st_2.nextToken());
		String		LHS_node_info	= st_2.nextToken();

		NodeBase	LHS_NodeBase	= new NodeBase(LHS_node_id, LHS_node_info);

		//create a new node, and then add the RHS nodes (must be ready or leaves) into the children list
		GeneralSyntaxNode	_LHS_syntax_node = createNode(LHS_NodeBase);

		//handle line #
		if (st_2.hasMoreTokens() == true)
		{
			int line_num = Integer.parseInt(st_2.nextToken());
			_LHS_syntax_node.setLineNum(line_num);
		}


		//RHS is much more complex, due to \", \\, etc.
		//this lexer is hand-coded
		char[]	char_sequence	= RHS.toCharArray();
		int		lexer_index		= 0;
		int		sequence_length	= RHS.length();
		while (lexer_index < sequence_length)
		{
			if (char_sequence[lexer_index] == '\"')
			{
				//blaz ahead to find the matching "
				int		probe_index = lexer_index + 1;
				boolean	match = false;
				while (probe_index < sequence_length)
				{
					if (char_sequence[probe_index] == '\"' && char_sequence[probe_index-1] != '\\')
					{
						match						= true;
						String	node_str			= RHS.substring(lexer_index+1, probe_index).trim();	//excluding the ""
						
						//we can't use a StringTokenizer here because there could be spaces in a string literal
						int		first_space_index	= node_str.indexOf(' ');
						int		RHS_node_id			= Integer.parseInt(node_str.substring(0, first_space_index));

						String	RHS_node_remain		= node_str.substring(first_space_index).trim();
						//now get the node_info and line # out
						String	RHS_node_info;
						int		rhs_line_num = -1;
						if (RHS_node_remain.startsWith("\\\"") == true)	//it's a string literal
						{
							int last_quote_index = RHS_node_remain.lastIndexOf("\\\"");
							RHS_node_info = RHS_node_remain.substring(0, last_quote_index + 2).trim();
							RHS_node_remain = RHS_node_remain.substring(last_quote_index + 2).trim();

							if (RHS_node_remain.length() > 0)	//if still more there
							{
								StringTokenizer	st_remain = new StringTokenizer(RHS_node_remain, " ");
								if (st_remain.hasMoreTokens() == true)
								{
									rhs_line_num = Integer.parseInt(st_remain.nextToken());
								}
							}
						}
						else	//not a string literal, can use stringtokenizer
						{
							StringTokenizer	st_remain = new StringTokenizer(RHS_node_remain, " ");
							RHS_node_info = new String(st_remain.nextToken());

							if (st_remain.hasMoreTokens() == true)
							{
								rhs_line_num = Integer.parseInt(st_remain.nextToken());								
							}
						}

						NodeBase	RHS_NodeBase	= new NodeBase(RHS_node_id, RHS_node_info);

						GeneralSyntaxNode	child_syntax_node = fetchNode(RHS_NodeBase);

						//set the line #
						child_syntax_node.setLineNum(rhs_line_num);
						child_syntax_node.setParent(_LHS_syntax_node);	//set the parent pointer

						_LHS_syntax_node.addChildLast(child_syntax_node);

						lexer_index = probe_index;
						break;
					}
					probe_index ++;
				}

				if (match == false)
				{
					System.out.println("Error: \"es doesn't match");
					System.exit(1);
				}
			}
			lexer_index ++;
		}

		//put the LHS node into the hashtable in case it's a child of another node
		hashSyntaxNode(LHS_node_id, _LHS_syntax_node);
		return _LHS_syntax_node;
	}

	//returns the node in the hashtable, and remove it from the table so that it's properly mounted only to one parent.
	protected GeneralSyntaxNode fetchNode(NodeBase	_target)
	{
		GeneralSyntaxNode	_node = (GeneralSyntaxNode)(node_table.remove(new Integer(_target.NodeID)));
		if (_node == null)	
		{
			//this is a leaf node, just creat one leaf node and return
			GeneralSyntaxNode	leaf_node = new GeneralSyntaxNode(_target.NodeID, null, _target.NodeInfo);

			return leaf_node;
		}
		else
		{
			//not leaf, just return the node found
			return _node;
		}
	}

	protected GeneralSyntaxNode	createNode(NodeBase	_node)
	{
		//GeneralSyntaxNode	_new_node = new GeneralSyntaxNode(null, _node.NodeInfo);
		GeneralSyntaxNode	_new_node = new GeneralSyntaxNode(_node.NodeID, null, _node.NodeInfo);
		//may need further actions
		return _new_node;
	}

	protected int hashSyntaxNode(int _node_id, GeneralSyntaxNode _node_to_hash)
	{
		if (node_table.put(new Integer(_node_id), _node_to_hash) != null)	//means collision
		{
			System.out.println("DumpParser Fatal Error: collision in hashtable !");
			System.exit(1);
		}
		return node_table.size();
	}
}

/*
		StringTokenizer st_3	= new StringTokenizer(RHS, " ");
		while (st_3.hasMoreTokens() == true)
		{
			String		node_id_string			= st_3.nextToken().substring(1);	//skip " at the beginning
			String		node_info_string_temp	= st_3.nextToken();
			String		node_info_string		= node_info_string_temp.substring(0, node_info_string_temp.length()-1);	//get rid of the ending "

			int			RHS_node_id		= Integer.parseInt(node_id_string);
			String		RHS_node_info	= node_info_string;
			NodeBase	RHS_NodeBase	= new NodeBase(RHS_node_id, RHS_node_info);

			GeneralSyntaxNode	child_syntax_node	= fetchNode(RHS_NodeBase);
			child_syntax_node.setParent(_LHS_syntax_node);	//set the parent pointer
			_LHS_syntax_node.addChildLast(child_syntax_node);
		}
*/

