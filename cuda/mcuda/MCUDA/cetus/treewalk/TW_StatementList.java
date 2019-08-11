
package cetus.treewalk;

//This tree walker works only with C language

//Jan 25, 2004

import java.lang.*;
import java.util.*;

import cetus.hir.*;


//TreeWalker statement list
/**
*	This class is only used during constructing the IR tree
*/
class  TW_StatementList	extends Statement
{
	LinkedList	stmt_list;

	public TW_StatementList()
	{
		stmt_list = new LinkedList();
	}

	public void addStatement(Statement _stmt)
	{
		if (_stmt instanceof TW_StatementList)
		{
			//need to add all the statements in the list
			LinkedList		st_list	= ((TW_StatementList)_stmt).getStatementList();
			ListIterator	iter	= st_list.listIterator(0);

			while (iter.hasNext() == true)
			{
				stmt_list.add(iter.next());
			}
		}
		else
		{
			stmt_list.add(_stmt);
		}
	}

	public LinkedList	getStatementList()
	{
		return stmt_list;
	}
}
