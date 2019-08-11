
/**
* This is a class visible only in cctreewalker package.
* The only reason for it's existence is to handle declarator tail.
* declarator tail in C++ is a separate structure from the 
* declarator id, which makes it very difficult to construct a
* proper declarator.
*
* The basic idea of using this class is to provide some 
* additional type information for the creation of declarator.
*/

package cetus.treewalk;

import java.lang.*;
import java.util.*;

import cetus.hir.*;

class  DeclaratorTail
{
	static final int PARAM_DECL_CLAUSE					= 0;
	static final int PARAM_DECL_CLAUSE_QUAL_SEQ			= 1;
	static final int PARAM_DECL_CLAUSE_EXCEPTION_SPEC	= 2;
	static final int PARAM_DECL_CLAUSE_QUAL_SEQ_EXCEPTION_SPEC = 3;
	static final int BRACKETS							= 4;
	static final int BRACKET_CONST_BRACKET				= 5;

	int			type		= -1;
	ArrayList	children	= new ArrayList();
	
	//by using different constructors, we specify the type of this tail implicitly
	public DeclaratorTail(LinkedList	param_decl_clause)
	{
		type = PARAM_DECL_CLAUSE;
		children.add(param_decl_clause);
	}

	public DeclaratorTail(LinkedList param_decl_clause, LinkedList qualifier_seq)
	{
		type = PARAM_DECL_CLAUSE_QUAL_SEQ;
		children.add(param_decl_clause);
		children.add(qualifier_seq);
	}

	public DeclaratorTail(LinkedList param_decl_clause, ThrowExpression throw_expr)
	{
		type = PARAM_DECL_CLAUSE_EXCEPTION_SPEC;
		children.add(param_decl_clause);
		children.add(throw_expr);
	}

	public DeclaratorTail(LinkedList param_decl_clause, LinkedList qualifier_seq, ThrowExpression throw_expr)
	{
		type = PARAM_DECL_CLAUSE_QUAL_SEQ_EXCEPTION_SPEC;
		children.add(param_decl_clause);
		children.add(qualifier_seq);
		children.add(throw_expr);
	}

	/**
	* This constructor is assumed to be "[]"
	*/
	public DeclaratorTail()
	{
		type = BRACKETS;
	}

	public DeclaratorTail(Expression expr)
	{
		type = BRACKET_CONST_BRACKET;
		children.add(expr);
	}

	public Object	getChild(int index)
	{
		return children.get(index);
	}

	public int getType()
	{
		return type;
	}
}
