
package cetus.treewalk;

//This tree walker works only with C language

//Jan 25, 2004

import java.lang.*;
import java.util.*;

import cetus.hir.*;

public class CTreeWalk extends CTreeWalkBase
{

	//----------------------------------------//
	Stack			semantic_stack		= null;	
	Stack			symbol_table_stack	= null;	//gives a pointer to the latest symbol table
	TranslationUnit	TU					= null;			

	protected class semantic_stack_separator
	{
		int	NodeID = -1;

		public semantic_stack_separator(int _node_id)
		{
			NodeID = _node_id;
		}
		public int getNodeID()
		{
			return NodeID;
		}
		public String toString()
		{
			return "<separator: NodeID = " + NodeID + ">";
		}
	};
	protected String TU_filename = "default.c";		//the treewalker is responsible for walking a tree of that particular src file

	public void setFileName(String _filename)
	{
		TU_filename = _filename;
	}

	public TranslationUnit getTranslationUnit()
	{
		return TU;
	}

	//display the semantic stack contents
	public void semantic_stack_display()
	{
		System.out.println("\n ---- Semantic Stack ---- ");
		for (int i = 0; i < semantic_stack.size(); i ++)
		{
			Object o = semantic_stack.get(i);
			System.out.println("<ClassName: " + o.getClass().getName() + " | Content: " + o.toString() + ">");
		}
		System.out.println(" ---- Stack Top ---- \n\n");
	}

	//this would return a unique internal name
	protected static int internal_name_id = 0;

	protected String getInternalName()
	{
		String result = "__CETUS_INTERNAL_" + Integer.toString(internal_name_id);
		internal_name_id ++;

		return result;
	}

	//----------------------------------------//

    protected boolean debug_display = true;

    public CTreeWalk()
    {
        super();
		semantic_stack		= new Stack();
		symbol_table_stack	= new Stack();
    }

    protected boolean action____abstract_declarator__pointer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__pointer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{

		}
		else
		{
			//there should be a list of specs on top of the semantic stack already
			List	spec_list		= (List)(semantic_stack.pop());
			Declarator	decl		= null;
			LinkedList	param_list	= null;
			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____abstract_declarator__direct_abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__direct_abstract_declarator() NodeID = " + node.getNodeID());
        }

		//nothing to do, since there should be a declarator on top of the stack already.
        return true;
    }

    protected boolean action____abstract_declarator__pointer__direct_abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__pointer__direct_abstract_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
			LinkedList	param_list	= null;

			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____abstract_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____abstract_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____additive_expression__multiplicative_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____additive_expression__multiplicative_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */

        return true;
    }

    protected boolean action____additive_expression__additive_expression__PLUS_SIGN__multiplicative_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____additive_expression__additive_expression__PLUS_SIGN__multiplicative_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.ADD, right));
        }

        return true;
    }

    protected boolean action____additive_expression__additive_expression__MINUS_SIGN__multiplicative_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____additive_expression__additive_expression__MINUS_SIGN__multiplicative_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.SUBTRACT, right));
        }

        return true;
    }

    protected boolean action____additive_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____additive_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____additive_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____and_expression__equality_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____and_expression__equality_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____and_expression__and_expression__AMPERSAND__equality_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____and_expression__and_expression__AMPERSAND__equality_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.BITWISE_AND, right));
        }

        return true;
    }

    protected boolean action____and_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____and_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____and_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____argument_expression_list__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____argument_expression_list__assignment_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push((new ChainedList()).addLink((Expression)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____argument_expression_list__argument_expression_list__COMMA__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____argument_expression_list__argument_expression_list__COMMA__assignment_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression expr = (Expression)semantic_stack.pop();
			List list = (List)semantic_stack.peek();
			list.add(expr);
        }

        return true;
    }

    protected boolean action____argument_expression_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____argument_expression_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____argument_expression_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____assignment_expression__conditional_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__conditional_expression() NodeID = " + node.getNodeID());
        }

        return true;
    }

    protected boolean action____assignment_expression__unary_expression__assignment_operator__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__unary_expression__assignment_operator__assignment_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          Expression right      = (Expression)semantic_stack.pop();
          AssignmentOperator op = (AssignmentOperator)semantic_stack.pop();
          Expression left       = (Expression)semantic_stack.pop();

          semantic_stack.push(new AssignmentExpression(left, op, right));
        }

        return true;
    }

    protected boolean action____assignment_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____assignment_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____assignment_operator__EQUAL_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__EQUAL_SIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.NORMAL);
        return true;
    }

    protected boolean action____assignment_operator__MUL_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__MUL_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.MULTIPLY);
        return true;
    }

    protected boolean action____assignment_operator__DIV_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__DIV_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.DIVIDE);
        return true;
    }

    protected boolean action____assignment_operator__MOD_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__MOD_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.MODULUS);
        return true;
    }

    protected boolean action____assignment_operator__ADD_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__ADD_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.ADD);
        return true;
    }

    protected boolean action____assignment_operator__SUB_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__SUB_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.SUBTRACT);
        return true;
    }

    protected boolean action____assignment_operator__LEFT_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__LEFT_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.SHIFT_LEFT);
        return true;
    }

    protected boolean action____assignment_operator__RIGHT_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__RIGHT_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.SHIFT_RIGHT);
        return true;
    }

    protected boolean action____assignment_operator__AND_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__AND_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.BITWISE_AND);
        return true;
    }

    protected boolean action____assignment_operator__XOR_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__XOR_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.BITWISE_EXCLUSIVE_OR);
        return true;
    }

    protected boolean action____assignment_operator__OR_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__OR_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.BITWISE_INCLUSIVE_OR);
        return true;
    }

    protected boolean action____assignment_operator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____assignment_operator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____cast_expression__unary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__unary_expression() NodeID = " + node.getNodeID());
        }

		//don't necessarily need to explicitly cast it.

        return true;
    }

    protected boolean action____cast_expression__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Expression	expr			= (Expression)(semantic_stack.pop());
			List		type_name_list	= (List)(semantic_stack.pop());

			semantic_stack.push(new Typecast(type_name_list, expr));
		}

        return true;
    }

    protected boolean action____cast_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____cast_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

	//compound_statement --> xxx must result in a compounded statement object on the semantic stack
    protected boolean action____compound_statement__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____compound_statement__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		//this routine will only be called once, since no child
		CompoundStatement	cmpd_stmt = new CompoundStatement();
		semantic_stack.push(cmpd_stmt);

		//since empty compound statement, no need to update the symbol_table_stack

        return true;
    }

	//we are taking a differnet approach here, in order not to make the stack too big
	//we would create the cmpd_stmt object in the beginning, and then let the branches below add the statements into the compound statement
    protected boolean action____compound_statement__LEFT_BRACE__statement_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____compound_statement__LEFT_BRACE__statement_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//create an object for compound statement, and then update the symboltable stack.
			CompoundStatement	cmpd_stmt = new CompoundStatement();
			
			semantic_stack.push(cmpd_stmt);
			symbol_table_stack.push(cmpd_stmt);			
			//System.out.println("---- after compoundstmt before action ---- ");
			//semantic_stack_display();
		}
		else
		{
			symbol_table_stack.pop();
			//semantic_stack_display();
			//nothing to do
			//semantic_stack_display();
		}

		return true;
    }

    protected boolean action____compound_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____compound_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____compound_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conditional_expression__logical_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conditional_expression__logical_or_expression() NodeID = " + node.getNodeID());
        }

        return true;
    }

    protected boolean action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__conditional_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__conditional_expression() NodeID = " + node.getNodeID());
        }


        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression f	= (Expression)semantic_stack.pop();
			Expression t	= (Expression)semantic_stack.pop();
			Expression cond = (Expression)semantic_stack.pop();

			semantic_stack.push(new ConditionalExpression(cond, t, f));
        }

        return true;
    }

    protected boolean action____conditional_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conditional_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */
 
        errorExit("action____conditional_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____constant_expression__conditional_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____constant_expression__conditional_expression() NodeID = " + node.getNodeID());
        }

		/* nothing to do */
        return true;
    }

    protected boolean action____constant_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____constant_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____constant_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration__function_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__function_definition() NodeID = " + node.getNodeID());
        }

		//nothing to be done here
        return true;
    }

    protected boolean action____declaration__simple_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__simple_declaration() NodeID = " + node.getNodeID());
        }

        //nothing to do here
        return true;
    }

    protected boolean action____declaration__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__SEMICOLON() NodeID = " + node.getNodeID());
        }
		
		//nothing to do here
        return true;
    }

    protected boolean action____declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration_list__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_list__declaration() NodeID = " + node.getNodeID());
        }

		//nothing needs to be done
		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	decl_list = new LinkedList();
			Declaration	decl = (Declaration)(semantic_stack.pop());
			decl_list.add(decl);
			semantic_stack.push(decl_list);
		}

        return true;
    }

    protected boolean action____declaration_list__declaration_list__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_list__declaration_list__declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			LinkedList	decl_list	= (LinkedList)(semantic_stack.peek());
			
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____declaration_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____declaration_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration_specifiers__storage_class_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__storage_class_specifier() NodeID = " + node.getNodeID());
        }
		
		//storage class specifier is much easier to handle
        if (__action_status__ == __ACTION_BEFORE__)
        {
			//nothing
		}
		else
		{
			//pick the one on the top of the stack and put it into the list
			Specifier	item		= (Specifier)(semantic_stack.pop());
			LinkedList	spec_list	= new LinkedList();
			spec_list.add(item);

			semantic_stack.push(spec_list);
		}

        return true;
    }

    protected boolean action____declaration_specifiers__declaration_specifiers__storage_class_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__declaration_specifiers__storage_class_specifier() NodeID = " + node.getNodeID());
        }

		//decl specifiers will be handled recursively,
		//just need to handle storage class specifier
        if (__action_status__ == __ACTION_BEFORE__)
        {
			//nothing
		}
		else
		{
			//pick the one on the top of the stack and put it into the list
			Specifier  item			= (Specifier)(semantic_stack.pop());
			LinkedList spec_list	= (LinkedList)(semantic_stack.peek());

			spec_list.add(item);
		}

        return true;
    }

    protected boolean action____declaration_specifiers__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__type_specifier() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {	
		}
		else
		{
			//there should be a user specifier on top of the semantic stack
			//create a linked list and put it back into the semantic stack
			Specifier	spec = (Specifier)(semantic_stack.pop());
			LinkedList	spec_list = new LinkedList();
			spec_list.add(spec);
			semantic_stack.push(spec_list);
		}

/* ---- This is major revision ----
        if (__action_status__ == __ACTION_BEFORE__)
        {	
			//put a semantic stack separator into the semantic stack
			//this separator is necessary because more complexed structures may push multiple descriptors into the stack, e.g. struct union, etc.
			//so we know the list should be under the separator
			semantic_stack_separator	separator = new semantic_stack_separator(node.getNodeID());
			semantic_stack.push(separator);
        }
		else
		{
			//need to pick the specifiers up and add them into the list
			//pop the semantic stack one by one till it hits the separator buried by this routine
			LinkedList	temp_list	= new LinkedList();
			Object		item		= semantic_stack.pop();
			
			while ( !(item instanceof semantic_stack_separator) )
			{
				temp_list.add(item);
				item = semantic_stack.pop();
			}
			if (((semantic_stack_separator)item).getNodeID() != node.getNodeID())
			{
				errorExit("Error: semantic_stack is corrupted.");
			}
			//now the specifiers list is on top of semantic stack
			item = semantic_stack.peek();
			((LinkedList)item).addAll((Collection)temp_list);
		}
*/
        return true;
    }

    protected boolean action____declaration_specifiers__declaration_specifiers__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__declaration_specifiers__type_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			// nothing to do
		}
		else
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.peek());
			spec_list.add(spec);
		}

/* ---- This is a major revision ----
        if (__action_status__ == __ACTION_BEFORE__)
        {	
			//put a separator, and then a temp LinkedList into the stack, so the inner decl_specifiers can add to the temp list
			semantic_stack_separator	separator = new semantic_stack_separator(node.getNodeID());
			semantic_stack.push(separator);
			LinkedList temp_list = new LinkedList();
			semantic_stack.push(temp_list);
		}
		else
		{
			//pop all the stuffs, and add into the LinkedList under the separator buried by this node
			LinkedList	temp_list	= new LinkedList();
			Object		item		= semantic_stack.pop();

			while ( !(item instanceof semantic_stack_separator) )
			{
				if (item instanceof LinkedList)
				{
					temp_list.addAll((Collection)item);
				}
				else
				{
					temp_list.add(item);
				}
				item = semantic_stack.pop();
			}
			if (((semantic_stack_separator)item).getNodeID() != node.getNodeID())
			{
				errorExit("Error: semantic_stack is corrupted.");
			}

			//now the specifiers list is on top of semantic stack
			item = semantic_stack.peek();
			((LinkedList)item).addAll((Collection)temp_list);
		}
*/
        return true;
    }

    protected boolean action____declaration_specifiers__type_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__type_qualifier() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
			//nothing
		}
		else
		{
			LinkedList	spec_list	= new LinkedList();
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			spec_list.add(spec);
			semantic_stack.push(spec_list);
/* ---- This is a major revision ----
			//pick the one on the top of the stack and put it into the list
			Object item			= semantic_stack.pop();
			Object temp_list	= semantic_stack.peek();
			((LinkedList)temp_list).add(item);
*/
		}

        return true;
    }

    protected boolean action____declaration_specifiers__declaration_specifiers__type_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__declaration_specifiers__type_qualifier() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
			//nothing
		}
		else
		{
			Specifier	spec = (Specifier)(semantic_stack.pop());
			List		spec_list = (List)(semantic_stack.peek());
			spec_list.add(spec);

/* ---- This is a major revision ----
			//pick the one on the top of the stack and put it into the list
			Object item			= semantic_stack.pop();
			Object temp_list	= semantic_stack.peek();
			((LinkedList)temp_list).add(item);			
*/
		}

        return true;
    }

    protected boolean action____declaration_specifiers__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_specifiers__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____declaration_specifiers__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

	//declarator ends up with a Declarator object on top of the stack
	//don't know how to handle some declarators properly yet
	protected boolean action____declarator__pointer__direct_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator__pointer__direct_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do at this new version
		}
		else
		{
			//the stack layout should be: list -- declarator
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		ptr_list	= (List)(semantic_stack.pop());
			List		param_list	= null;

			//have to assume *abc[] could happen, so this is the only solution.
			//otherwise we can avoid output like: int *(p)
			semantic_stack.push(new Declarator(ptr_list, decl, param_list));
		}

		return true;
    }

    protected boolean action____declarator__direct_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator__direct_declarator() NodeID = " + node.getNodeID());
        }

		//in this case, there should be a declarator object on the stack already. just do nothing
        return true;
    }

    protected boolean action____declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{

		}       
		else
		{
			Declarator	decl	= (Declarator)(semantic_stack.pop());

			LinkedList spec_list = null;
			LinkedList param_list = null;

			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}
		
		return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		LinkedList	spec_list = new LinkedList();
		spec_list.add(ArraySpecifier.UNBOUNDED);
		Declarator	decl_item = null;
		LinkedList	param_list = null;

        semantic_stack.push(new Declarator(spec_list, decl_item, param_list));

        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Expression	expr = (Expression)(semantic_stack.pop());

			ArraySpecifier	array_spec	= new ArraySpecifier(expr);
			LinkedList		spec_list	= new LinkedList();
			spec_list.add(array_spec);
			Declarator		decl		= null;
			LinkedList		param_list	= null;

			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			LinkedList	param_list	= null;

			semantic_stack.push(new Declarator(decl.getSymbol(), param_list, ArraySpecifier.UNBOUNDED));				
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Expression	expr		= (Expression)(semantic_stack.pop());
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			LinkedList	param_list	= null;

			semantic_stack.push(new Declarator(decl.getSymbol(), param_list, new ArraySpecifier(expr)));				
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		//just need to push an empty Declarator into the stack
		LinkedList param_list = null;
		Declarator	decl_item = null;
		semantic_stack.push(new Declarator(decl_item, param_list));
        
        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//there should be a linked list on top of the stack
			LinkedList	spec_list = null;
			Declarator	decl_item = null;
			LinkedList	param_list = (LinkedList)(semantic_stack.pop());

			semantic_stack.push(new Declarator(spec_list, decl_item, (LinkedList)param_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			LinkedList	param_list	= new LinkedList();
			LinkedList	spec_list	= null;
			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			List	param_list	= (List)(semantic_stack.pop());
			Declarator	decl	= (Declarator)(semantic_stack.pop());
			LinkedList	spec_list = null;

			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_abstract_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_declarator__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__IDENTIFIER() NodeID = " + node.getNodeID());
        }
		
		String id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();
		semantic_stack.push(new Declarator(new Identifier(id_name)));

		//System.out.println(" **** " + id_name + " is added as a declarator **** ");

        return true;
    }

    protected boolean action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }
		
		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else	
		{
			//there should be a declarator on top of the stack -- nothing to do		
			Declarator	decl = (Declarator)(semantic_stack.pop());
			List		leading_spec_list = null;
			List		param_list		= null;	//new LinkedList();

			semantic_stack.push(new Declarator(leading_spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }
        if (__action_status__ == __ACTION_BEFORE__)
        {
			//nothing before we expand the declarator on the RHS
        }
		else
		{
			Expression		const_expr	= (Expression)(semantic_stack.pop());
			Declarator		decl		= (Declarator)(semantic_stack.pop());

			IDExpression	id_expr		= ((Declarator)decl).getSymbol();
			LinkedList		list_param	= null;

			semantic_stack.push(new Declarator(id_expr, list_param, new ArraySpecifier(const_expr)));
		}

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do before declarator is expanded
		}
		else
		{
			Declarator		decl		= (Declarator)(semantic_stack.pop());
			IDExpression	id_expr		= ((Declarator)decl).getSymbol();

			LinkedList		list_param	= null;

			semantic_stack.push(new Declarator(id_expr, list_param, new ArraySpecifier()));
		}

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			List		param_type_list = (List)(semantic_stack.pop());
			Declarator	decl			= (Declarator)(semantic_stack.pop());
			List		trailing_spec_list = null;

			semantic_stack.push(new Declarator(decl.getSymbol(), param_type_list, trailing_spec_list));
		}

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
			//nothing to be done
        }
		else
		{
			List		param_type_list = new LinkedList();
			Declarator	decl			= (Declarator)(semantic_stack.pop());
			List		trailing_specs	= null;

			semantic_stack.push(new Declarator(decl.getSymbol(), param_type_list, trailing_specs));
		}

        return true;
    }

    protected boolean action____direct_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */
		System.out.println("\n\n\n ====>> " + ((GeneralSyntaxNode)(node.getChild(0))).getInfoString() + "    typecode = " + ((GeneralSyntaxNode)(node.getChild(0))).getTypeCode() + "\n\n\n");

        errorExit("action____direct_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____enum_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enum_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			String		unique_name	= TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
			String		id_name		= unique_name;
			List		enum_list	= (List)(semantic_stack.pop());

			SymbolTable	sym_table	= (SymbolTable)(symbol_table_stack.peek());
			sym_table.addDeclaration(new cetus.hir.Enumeration(new Identifier(id_name), enum_list));
			
			semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));
        }

        return true;
    }

    protected boolean action____enum_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enum_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			List	enum_list	= (List)(semantic_stack.pop());
			//need to make sure it's chile #1
			String	id_name		= (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();

			SymbolTable	sym_table	= (SymbolTable)(symbol_table_stack.peek());
			sym_table.addDeclaration(new cetus.hir.Enumeration(new Identifier(id_name), enum_list));
			
			semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));
        }

        return true;
    }

    protected boolean action____enum_specifier__ENUM__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enum_specifier__ENUM__IDENTIFIER() NodeID = " + node.getNodeID());
        }

		//should leave an enum specifier on top of the stack. ---- not very sure, though
		//String		unique_name	= TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());

		String		id_name		= (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();

		//List		enum_list	= null;		//(List)(semantic_stack.pop());

		//SymbolTable	sym_table	= (SymbolTable)(symbol_table_stack.peek());
		//sym_table.addDeclaration(new cetus.hir.Enumeration(new Identifier(id_name), enum_list));
			
		semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));

        return true;
    }

    protected boolean action____enum_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enum_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____enum_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____enumerator__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator__IDENTIFIER() NodeID = " + node.getNodeID());
        }

		String	id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();
        semantic_stack.push(new Declarator(new Identifier(id_name)));
        return true;
    }

    protected boolean action____enumerator__IDENTIFIER__EQUAL_SIGN__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator__IDENTIFIER__EQUAL_SIGN__constant_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			String id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();

			Initializer init = new Initializer((Expression)semantic_stack.pop());
			Declarator	decl = new Declarator(new Identifier(id_name));
			decl.setInitializer(init);
			semantic_stack.push(decl);
        }

        return true;
    }

    protected boolean action____enumerator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____enumerator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____enumerator_list__enumerator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_list__enumerator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Declarator decl = (Declarator)semantic_stack.pop();
			semantic_stack.push((new ChainedList()).addLink(decl));
        }

        return true;
    }

    protected boolean action____enumerator_list__enumerator_list__COMMA__enumerator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_list__enumerator_list__COMMA__enumerator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Declarator	decl = (Declarator)semantic_stack.pop();
			List		list = (List)semantic_stack.peek();
			list.add(decl);
        }

        return true;
    }

    protected boolean action____enumerator_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____enumerator_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____equality_expression__relational_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____equality_expression__relational_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____equality_expression__equality_expression__EQ_OP__relational_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____equality_expression__equality_expression__EQ_OP__relational_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right	= (Expression)semantic_stack.pop();
			Expression left		= (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.COMPARE_EQ, right));
        }

        return true;
    }

    protected boolean action____equality_expression__equality_expression__NE_OP__relational_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____equality_expression__equality_expression__NE_OP__relational_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          Expression right      = (Expression)semantic_stack.pop();
          Expression left       = (Expression)semantic_stack.pop();

          semantic_stack.push(new BinaryExpression(left, BinaryOperator.COMPARE_NE, right));
        }

        return true;
    }

    protected boolean action____equality_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____equality_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____equality_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exclusive_or_expression__and_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exclusive_or_expression__and_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____exclusive_or_expression__exclusive_or_expression__CARET__and_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exclusive_or_expression__exclusive_or_expression__CARET__and_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right      = (Expression)semantic_stack.pop();
			Expression left       = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.BITWISE_EXCLUSIVE_OR, right));
        }

        return true;
    }

    protected boolean action____exclusive_or_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exclusive_or_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____exclusive_or_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____expression__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression__assignment_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____expression__expression__COMMA__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression__expression__COMMA__assignment_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          Expression right      = (Expression)semantic_stack.pop();
          Expression left       = (Expression)semantic_stack.pop();

          semantic_stack.push(new CommaExpression( (new ChainedList()).addLink(left).addLink(right) ));
        }

        return true;
    }

    protected boolean action____expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

	//should end up with a statement on top of the semantic stack
    protected boolean action____expression_statement__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_statement__SEMICOLON() NodeID = " + node.getNodeID());
        }

		//create an empty expr statement and place it on top of the stack
		semantic_stack.push(new NullStatement());

        return true;
    }

    protected boolean action____expression_statement__expression__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_statement__expression__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Expression	expr = (Expression)(semantic_stack.pop());

			ExpressionStatement expr_stmt = new ExpressionStatement(expr);
			semantic_stack.push(expr_stmt);
		}

        return true;
    }

    protected boolean action____expression_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____expression_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_definition__declaration_specifiers__declarator__compound_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_definition__declaration_specifiers__declarator__compound_statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//can't do much here because the creation of Procedure requires the full body of the function
		}
		else
		{
			//semantic_stack_display();
			CompoundStatement	cmpd_stmt		= (CompoundStatement)(semantic_stack.pop());
			Declarator			decl			= (Declarator)(semantic_stack.pop());
			List				decl_spec_list	= (List)(semantic_stack.pop());
			Procedure			proc			= new Procedure(decl_spec_list, decl, cmpd_stmt);
			
			//clear the compound statement on the symbol table stack.
			//symbol_table_stack.pop();
			
			//TranslationUnit		tran_unit		= (TranslationUnit)symbol_table_stack.peek();
			//tran_unit.addDeclaration(proc);
			semantic_stack.push(proc);
		}

        return true;
    }

    protected boolean action____function_definition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_definition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____function_definition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____inclusive_or_expression__exclusive_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____inclusive_or_expression__exclusive_or_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____inclusive_or_expression__inclusive_or_expression__VERTICAL_BAR__exclusive_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____inclusive_or_expression__inclusive_or_expression__VERTICAL_BAR__exclusive_or_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right      = (Expression)semantic_stack.pop();
			Expression left       = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.BITWISE_INCLUSIVE_OR, right));
        }

        return true;
    }

    protected boolean action____inclusive_or_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____inclusive_or_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____inclusive_or_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____init_declarator__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator__declarator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			//nothing to do, since there should be a declarator on top of the stack already.
			//semantic_stack.push(new Declarator((Identifier)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____init_declarator__declarator__EQUAL_SIGN__initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator__declarator__EQUAL_SIGN__initializer() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			//there should be an initializer and a declarator in the stack
			Initializer init	= (Initializer)(semantic_stack.pop());
			Declarator	decl	= (Declarator)(semantic_stack.peek());

			decl.setInitializer(init);
			//semantic_stack.push(decl);
        }

        return true;
    }

    protected boolean action____init_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____init_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____init_declarator_list__init_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator_list__init_declarator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			LinkedList	decl_list	= new LinkedList();
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			decl_list.add(decl);
			semantic_stack.push(decl_list);

			//add casts to enforce type
			//semantic_stack.push((new ChainedList()).addLink(semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____init_declarator_list__init_declarator_list__COMMA__init_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator_list__init_declarator_list__COMMA__init_declarator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Declarator	decl = (Declarator)semantic_stack.pop();
			List		list = (List)semantic_stack.peek();
			list.add(decl);
        }        

        return true;
    }

    protected boolean action____init_declarator_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____init_declarator_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____initializer__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__assignment_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new Initializer((Expression)(semantic_stack.pop())));
		}

        return true;
    }

    protected boolean action____initializer__LEFT_BRACE__initializer_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__LEFT_BRACE__initializer_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			List	init_list = (List)(semantic_stack.pop());
			semantic_stack.push(new Initializer(init_list));
		}

        return true;
    }

    protected boolean action____initializer__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new Initializer((List)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____initializer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */
        errorExit("action____initializer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____initializer_list__initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_list__initializer() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push((new ChainedList()).addLink((Initializer)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____initializer_list__initializer_list__COMMA__initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_list__initializer_list__COMMA__initializer() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Initializer init = (Initializer)semantic_stack.pop();
			List list = (List)semantic_stack.peek();
			list.add(init);
        }

        return true;
    }

    protected boolean action____initializer_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */
        errorExit("action____initializer_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____iteration_statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Statement	stmt = (Statement)(semantic_stack.pop());
			Expression	expr = (Expression)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("while statement: while()\nlabel: stmt\n is not supported");
			}

			semantic_stack.push(new WhileLoop(expr, stmt));
		}
        return true;
    }

    protected boolean action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			Statement	stmt = (Statement)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("do statement: do\nlabel: stmt\n is not supported");
			}

			semantic_stack.push(new DoLoop(stmt, expr));
		}		

        return true;
    }

    protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Statement			stmt			= (Statement)(semantic_stack.pop());
			ExpressionStatement	expr_stmt_cond	= (ExpressionStatement)(semantic_stack.pop());
			ExpressionStatement expr_stmt_init	= (ExpressionStatement)(semantic_stack.pop());
			Expression			expr_step		= null;

			if (stmt instanceof TW_StatementList)
			{
				errorExit("for stmt: for(...)\nlabel: stmt\nis not supported.");
			}

			semantic_stack.push(new ForLoop(expr_stmt_init, expr_stmt_cond.getExpression(), expr_step, stmt));
		}
		
        return true;
    }

    protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__expression__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Object obj = semantic_stack.pop();
			System.out.println("**** class name = " + obj.getClass().getName() + " ****");
			Statement			stmt			= (Statement)obj;
			//Statement			stmt			= (Statement)(semantic_stack.pop());
			Expression			expr_step		= (Expression)(semantic_stack.pop());
			ExpressionStatement	expr_stmt_cond	= (ExpressionStatement)(semantic_stack.pop());
			ExpressionStatement	expr_stmt_init	= (ExpressionStatement)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("for stmt: for(...)\nlabel: stmt\n is not supported.");
			}

			semantic_stack.push(new ForLoop(expr_stmt_init, expr_stmt_cond.getExpression(), expr_step, stmt));
		}		

		return true;
    }

    protected boolean action____iteration_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____iteration_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____jump_statement__GOTO__IDENTIFIER__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__GOTO__IDENTIFIER__SEMICOLON() NodeID = " + node.getNodeID());
        }
		
		GeneralSyntaxNode	child		= (GeneralSyntaxNode)(node.getChild(1));
		String				identifier	= new String(child.getInfoString());

		semantic_stack.push(new GotoStatement(new Identifier(identifier)));
        return true;
    }

    protected boolean action____jump_statement__CONTINUE__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__CONTINUE__SEMICOLON() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new ContinueStatement());
		return true;
    }

    protected boolean action____jump_statement__BREAK__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__BREAK__SEMICOLON() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new BreakStatement());
        return true;
    }

    protected boolean action____jump_statement__RETURN__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__RETURN__SEMICOLON() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new ReturnStatement());
		return true;
    }

    protected boolean action____jump_statement__RETURN__expression__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__RETURN__expression__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new ReturnStatement(expr));
		}

		return true;
    }

    protected boolean action____jump_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */
		System.out.println("Child infostring = " + ((GeneralSyntaxNode)node.getChild(0)).getInfoString() 
			+ " typecode = " + ((GeneralSyntaxNode)node.getChild(0)).getTypeCode());
        errorExit("action____jump_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____labeled_statement__IDENTIFIER__COLON__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____labeled_statement__IDENTIFIER__COLON__statement() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Statement		stmt	= (Statement)(semantic_stack.pop());
			String			name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString();
			Identifier		id_name = new Identifier(name);
		  
			TW_StatementList	stmt_list = new TW_StatementList();
			stmt_list.addStatement(new Label(id_name));
			stmt_list.addStatement(stmt);

			semantic_stack.push(stmt_list);
        }

        return true;
    }

    protected boolean action____labeled_statement__CASE__constant_expression__COLON__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____labeled_statement__CASE__constant_expression__COLON__statement() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Statement	stmt = (Statement)semantic_stack.pop();
			Expression	expr = (Expression)semantic_stack.pop();

			TW_StatementList	stmt_list = new TW_StatementList();
			stmt_list.addStatement(new Case(expr));
			stmt_list.addStatement(stmt);
			
			semantic_stack.push(stmt_list);

			//semantic_stack.push(new Case(expr));
			//semantic_stack.push(stmt);
        }

        return true;
    }

    protected boolean action____labeled_statement__DEFAULT__COLON__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____labeled_statement__DEFAULT__COLON__statement() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          Statement stmt = (Statement)semantic_stack.pop();

		  TW_StatementList	stmt_list = new TW_StatementList();
		  stmt_list.addStatement(new Default());
		  stmt_list.addStatement(stmt);
		  
		  semantic_stack.push(stmt_list);

          //semantic_stack.push(new Default());
          //semantic_stack.push(stmt);
        }        

        return true;
    }

    protected boolean action____labeled_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____labeled_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____labeled_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____logical_and_expression__inclusive_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_and_expression__inclusive_or_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.LOGICAL_AND, right));
        }

        return true;
    }

    protected boolean action____logical_and_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_and_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____logical_and_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____logical_or_expression__logical_and_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_or_expression__logical_and_expression() NodeID = " + node.getNodeID());
        }

        /* do nothing */
        return true;
    }

    protected boolean action____logical_or_expression__logical_or_expression__OR_OP__logical_and_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_or_expression__logical_or_expression__OR_OP__logical_and_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.LOGICAL_OR, right));
        }

        return true;
    }

    protected boolean action____logical_or_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_or_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____logical_or_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____multiplicative_expression__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__cast_expression() NodeID = " + node.getNodeID());
        }

		//nothing to do, since no explicit cast is necessary

        return true;
    }

    protected boolean action____multiplicative_expression__multiplicative_expression__ASTERISK__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__multiplicative_expression__ASTERISK__cast_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.MULTIPLY, right));
        }

        return true;
    }

    protected boolean action____multiplicative_expression__multiplicative_expression__SLASH__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__multiplicative_expression__SLASH__cast_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          Expression right = (Expression)semantic_stack.pop();
          Expression left  = (Expression)semantic_stack.pop();

          semantic_stack.push(new BinaryExpression(left, BinaryOperator.DIVIDE, right));
        }

        return true;
    }

    protected boolean action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__cast_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          Expression right = (Expression)semantic_stack.pop();
          Expression left  = (Expression)semantic_stack.pop();

          semantic_stack.push(new BinaryExpression(left, BinaryOperator.MODULUS, right));
        }

        return true;
    }

    protected boolean action____multiplicative_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____multiplicative_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration__declaration_specifiers__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__declaration_specifiers__declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else	//this should end up with a declaration on top of the stack
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_list, decl));
		}

        return true;
    }

    protected boolean action____parameter_declaration__declaration_specifiers__abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__declaration_specifiers__abstract_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_list, decl));	
		}

        return true;
    }

    protected boolean action____parameter_declaration__declaration_specifiers(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__declaration_specifiers() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			List	spec_list = (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_list));
		}

        return true;
    }

    protected boolean action____parameter_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_list__parameter_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_list__parameter_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//need to create a new list, and put it on the stack
			LinkedList	param_list	= new LinkedList();
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			param_list.add(decl);
			semantic_stack.push(param_list);
		}

		return true;
    }

    protected boolean action____parameter_list__parameter_list__COMMA__parameter_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_list__parameter_list__COMMA__parameter_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			List		decl_list	= (List)(semantic_stack.peek());
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____parameter_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_type_list__parameter_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_type_list__parameter_list() NodeID = " + node.getNodeID());
        }
		
		//there should be list of parameters on top of the stack, just do nothing in this case

        return true;
    }

	//this case is not supported now
	//don't know what to do either, at this time.
    protected boolean action____parameter_type_list__parameter_list__COMMA__ELLIPSIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_type_list__parameter_list__COMMA__ELLIPSIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declaration	decl		= new VariableDeclaration(new Declarator(new Identifier("...")));
			List		param_list	= (List)(semantic_stack.peek());
			param_list.add(decl);
		}

        return true;
    }

    protected boolean action____parameter_type_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_type_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_type_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____pointer__ASTERISK(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pointer__ASTERISK() NodeID = " + node.getNodeID());
        }

		//leave a pointer specifier on top of the stack
		LinkedList	ptr_list = new LinkedList();
		ptr_list.add(PointerSpecifier.UNQUALIFIED);
		semantic_stack.push(ptr_list);

        return true;
    }

    protected boolean action____pointer__ASTERISK__type_qualifier_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pointer__ASTERISK__type_qualifier_list() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do here
		}
		else
		{
			LinkedList	spec_list = (LinkedList)(semantic_stack.peek());
			spec_list.addFirst(PointerSpecifier.UNQUALIFIED);
		}

        return true;
    }

    protected boolean action____pointer__ASTERISK__pointer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pointer__ASTERISK__pointer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			LinkedList	ptr_list = (LinkedList)(semantic_stack.peek());
			ptr_list.addFirst(PointerSpecifier.UNQUALIFIED);
		}

        return true;
    }

    protected boolean action____pointer__ASTERISK__type_qualifier_list__pointer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pointer__ASTERISK__type_qualifier_list__pointer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			LinkedList	spec_list	= (LinkedList)(semantic_stack.pop());
			LinkedList	ptr_list	= (LinkedList)(semantic_stack.peek());
			
			ptr_list.addAll(spec_list);
			ptr_list.addFirst(PointerSpecifier.UNQUALIFIED);
		}

        return true;
    }

    protected boolean action____pointer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pointer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____pointer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__primary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__primary_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing
		}
		else
		{
			//nothing, there should be a primary expression on top of the stack.
		}

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//there should be two expressions on top of the stack.
			Object index = semantic_stack.pop();
			Object array = semantic_stack.pop();
			if ((index instanceof Expression) && (array instanceof Expression))
			{
				semantic_stack.push(new ArrayAccess((Expression)array, (Expression)index));
			}
			else
			{
				semantic_stack_display();
				errorExit("Error: semantic stack mismatch ! expecting post_expr[expr]");
			}

		}
		
        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Object ftn = semantic_stack.pop();
			if (ftn instanceof Expression)
			{
				semantic_stack.push(new FunctionCall((Expression)ftn));
			}
			else
			{
				semantic_stack_display();
				errorExit("semantic stack mismatch ! expecting ftn() !");
			}
		}

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__argument_expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__argument_expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//one should be a list, the other should be expr
			Object arg_list = semantic_stack.pop();
			Object expr		= semantic_stack.pop();
	
			if ( (arg_list instanceof java.util.List)
				&& (expr instanceof Expression) )
			{
				semantic_stack.push(new FunctionCall((Expression)expr, (java.util.List)arg_list));
			}
			else
			{
				semantic_stack_display();
				errorExit("Error: semantic stack mismatch ! expecting expr(arg_list) !");
			}
		}

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__DOT__IDENTIFIER(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__DOT__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			String		id_name	= ((GeneralSyntaxNode)(node.getChild(2))).getInfoString().trim();
			Identifier	right	= new Identifier(id_name);
			
			Expression	left	= (Expression)(semantic_stack.pop());

			semantic_stack.push(new AccessExpression(left, AccessOperator.MEMBER_ACCESS, (Expression)right));
        }

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__PTR_OP__IDENTIFIER(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__PTR_OP__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			String		id_name	= ((GeneralSyntaxNode)(node.getChild(2))).getInfoString().trim();
			Identifier	right	= new Identifier(id_name);
			Expression	left	= (Expression)semantic_stack.pop();

			semantic_stack.push(new AccessExpression(left, AccessOperator.POINTER_ACCESS, right));
        }

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__INC_OP(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__INC_OP() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new UnaryExpression(UnaryOperator.POST_INCREMENT, (Expression)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__DEC_OP(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__DEC_OP() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new UnaryExpression(UnaryOperator.POST_DECREMENT, (Expression)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____postfix_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____postfix_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____primary_expression__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        GeneralSyntaxNode child = (GeneralSyntaxNode)node.getChild(0);
        semantic_stack.push(new Identifier(child.getInfoString()));
        return true;
    }

    protected boolean action____primary_expression__CONSTANT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__CONSTANT() NodeID = " + node.getNodeID());
        }

        /* TODO - handle more than one type of constant */
        String	D = "[0-9]";
        String	L = "[a-zA-Z_]";
        String  H = "[a-fA-F0-9]";
        String  E = "[Ee][+-]?(" + D + ")+";
        String  FS	= "(f|F|l|L)";
        String  IS	= "(u|U|l|L)*";

        String const1 = "0[xX](" + H + ")+(" + IS + ")?";
        String const2 = "0(" + D + ")+(" + IS + ")?";
        String const3 = "(" + D + ")+(" + IS+ ")?";
        String const4 = L + "?'(\\.|[^\\'])+'";	//weird
        String const5 = "(" + D + ")+(" + E + ")(" + FS + ")?";
        String const6 = "(" + D + ")*.(" + D + ")+(" + E + ")?" + FS + "?";
        String const7 = "(" + D + ")+.(" + D + ")*(" + E + ")?" + FS + "?";

		//const1 + "|" + const2 + "|" + const3 + "|" + const4 + "|" + const5 + "|" + const6 + "|" + const7;
        String	int_exp = const1 + "|" + const2 + "|" + const3;
		String	float_exp = const5 + "|" + const6 + "|" + const7;

		String	int_hex_exp = const1;
		String	int_dec_exp = const2 + "|" + const3;

		//now grab the const string
		GeneralSyntaxNode	child		= (GeneralSyntaxNode)node.getChild(0);
		String				const_str	= new String(child.getInfoString());

		if (const_str.matches(int_exp) == true)
		{
			semantic_stack.push(new IntegerLiteral( (Integer.decode(const_str)).intValue() ));
		}
		else if (const_str.matches(float_exp) == true)
		{
			semantic_stack.push(new FloatLiteral(Double.parseDouble(const_str)));
		}
		else
		{
			errorExit("action____primary_expression__CONSTANT(): unable to parse constant: " + const_str);
		}

        return true;
    }

    protected boolean action____primary_expression__STRING_LITERAL(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__STRING_LITERAL() NodeID = " + node.getNodeID());
        }

		String str_lit = new String(((GeneralSyntaxNode)(node.getChild(0))).getInfoString());
		if (str_lit.startsWith("\"") && str_lit.endsWith("\""))
		{
			str_lit = str_lit.substring(1, str_lit.length()-1);
		}
        semantic_stack.push(new StringLiteral( str_lit ));
        return true;
    }

    protected boolean action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			//there should be an expression object left on the stack
			Object item = semantic_stack.peek();
			if (item instanceof Expression)
			{
				/* TODO - how to handle (expr) ? */
				//nothing to do, since there should be a an expression on top of the semantic stack
			}
			else
			{
				semantic_stack_display();
				errorExit("Error: semantic stack mismatch. Expecting Expression.");
			}
		}

        return true;
    }

    protected boolean action____primary_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____primary_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____relational_expression__shift_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__shift_expression() NodeID = " + node.getNodeID());
        }

		//do nothing

        return true;
    }

    protected boolean action____relational_expression__relational_expression__LEFT_ANGLE_BRACKET__shift_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__relational_expression__LEFT_ANGLE_BRACKET__shift_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.COMPARE_LT, right));
        }

        return true;
    }

    protected boolean action____relational_expression__relational_expression__RIGHT_ANGLE_BRACKET__shift_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__relational_expression__RIGHT_ANGLE_BRACKET__shift_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.COMPARE_GT, right));
        }

        return true;
    }

    protected boolean action____relational_expression__relational_expression__LE_OP__shift_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__relational_expression__LE_OP__shift_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.COMPARE_LE, right));
        }

        return true;
    }

    protected boolean action____relational_expression__relational_expression__GE_OP__shift_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__relational_expression__GE_OP__shift_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.COMPARE_GE, right));
        }

        return true;
    }

    protected boolean action____relational_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____relational_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Statement	stmt = (Statement)(semantic_stack.pop());
			Expression	expr = (Expression)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("if_statement: if ()\nlabel: stmt\nis not supported !");
			}

			semantic_stack.push(new IfStatement(expr, stmt));
		}

        return true;
    }

    protected boolean action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement__ELSE__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement__ELSE__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			Statement	false_stmt	= (Statement)(semantic_stack.pop());
			Statement	true_stmt	= (Statement)(semantic_stack.pop());
			Expression	expr		= (Expression)(semantic_stack.pop());

			if (true_stmt instanceof TW_StatementList)
			{
				errorExit("if_statement: if ()\nlabel: stmt\nis not supported !");
			}
			if (false_stmt instanceof TW_StatementList)
			{
				errorExit("if_statement: if ()\n    ...\nelse\nlabel: stmt\n is not supported !");
			}

			semantic_stack.push(new IfStatement(expr, true_stmt, false_stmt));
		}

		return true;
    }

	//don't know how to do it yet.
    protected boolean action____selection_statement__SWITCH__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__SWITCH__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing to do
		}
		else
		{
			CompoundStatement	cmpd_stmt	= (CompoundStatement)(semantic_stack.pop());
			Expression			expr		= (Expression)(semantic_stack.pop());

			SwitchStatement	sw_stmt = new SwitchStatement(expr);
			sw_stmt.setBody(cmpd_stmt);

			semantic_stack.push(sw_stmt);
		}
        return true;
    }

    protected boolean action____selection_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

		/* unused */
        errorExit("action____selection_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____shift_expression__additive_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____shift_expression__additive_expression() NodeID = " + node.getNodeID());
        }

        return true;
    }

    protected boolean action____shift_expression__shift_expression__LEFT_OP__additive_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____shift_expression__shift_expression__LEFT_OP__additive_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.SHIFT_LEFT, right));
        }

        return true;
    }

    protected boolean action____shift_expression__shift_expression__RIGHT_OP__additive_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____shift_expression__shift_expression__RIGHT_OP__additive_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.SHIFT_RIGHT, right));
        }

        return true;
    }

    protected boolean action____shift_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____shift_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____shift_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__declaration_specifiers__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__declaration_specifiers__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			/* This is major revision */
			//since it's doing nothing, we just need to clear all the specifiers
			List	spec_list = (List)(semantic_stack.pop());
			//spec_list.clear();
			semantic_stack.push(new VariableDeclaration(new Declarator(new Identifier(""))));

			/*
			//there should be a list on top of the stack
			Object list_item = semantic_stack.pop();
			if (list_item instanceof LinkedList)
			{
				//leave a declaration on top of the stack
				semantic_stack.push(new VariableDeclaration((LinkedList)list_item));
			}
			else
			{
				semantic_stack_display();
				errorExit("Error: expecting a LinkedList on top of the stack !\n");
			}*/
		}

        return true;
    }

    protected boolean action____simple_declaration__declaration_specifiers__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__declaration_specifiers__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
          List decl_list = (List)semantic_stack.pop();
          List specifiers  = (List)semantic_stack.pop();

          semantic_stack.push(new VariableDeclaration(specifiers, decl_list));
        }

        return true;
    }

    protected boolean action____simple_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____specifier_qualifier_list__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____specifier_qualifier_list__type_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			LinkedList	spec_list	= new LinkedList();
			spec_list.add(spec);
			semantic_stack.push(spec_list);
		}

		return true;
    }

    protected boolean action____specifier_qualifier_list__specifier_qualifier_list__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____specifier_qualifier_list__specifier_qualifier_list__type_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.peek());
			spec_list.add(spec);
		}

		return true;
    }

    protected boolean action____specifier_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____specifier_qualifier_list__type_qualifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Specifier spec = (Specifier)(semantic_stack.pop());
			LinkedList spec_list = new LinkedList();
			spec_list.add(spec);
			semantic_stack.push(spec_list);
		}

        return true;
    }

    protected boolean action____specifier_qualifier_list__specifier_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____specifier_qualifier_list__specifier_qualifier_list__type_qualifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.peek());
			spec_list.add(spec);
		}

		return true;
    }

    protected boolean action____specifier_qualifier_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____specifier_qualifier_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____specifier_qualifier_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____statement__labeled_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__labeled_statement() NodeID = " + node.getNodeID());
        }
		
		//nothing to do, there should be a TW_StatementList object on the top of the stack
		return true;
    }

    protected boolean action____statement__compound_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__compound_statement() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____statement__expression_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__expression_statement() NodeID = " + node.getNodeID());
        }

        //nothing to do, leave it on the stack
		return true;
    }

    protected boolean action____statement__selection_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__selection_statement() NodeID = " + node.getNodeID());
        }

		//nothing to do, leave it on the stack
        return true;
    }

    protected boolean action____statement__iteration_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__iteration_statement() NodeID = " + node.getNodeID());
        }

        //nothing to do, leave it on the stack
        return true;
    }

    protected boolean action____statement__jump_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__jump_statement() NodeID = " + node.getNodeID());
        }

        //nothing to do, leave the statement on the stack
        return true;
    }

    protected boolean action____statement__simple_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__simple_declaration() NodeID = " + node.getNodeID());
        }

        //build a decl statement from the declaration, which should reside on top of the stack
		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declaration				decl		= (Declaration)(semantic_stack.pop());
			DeclarationStatement	decl_stmt	= new DeclarationStatement(decl);

			semantic_stack.push(decl_stmt);
		}

        return true;
    }

    protected boolean action____statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____statement_list__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement_list__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing
		}
		else
		{
			//pick up the statement on the semantic stack and add it into the underlying compound statement
			Statement	stmt = (Statement)(semantic_stack.pop());

			//add into the compound statement
			CompoundStatement cmpd_stmt = (CompoundStatement)(symbol_table_stack.peek());

			if (stmt instanceof TW_StatementList)
			{
				LinkedList	stmt_list	= ((TW_StatementList)stmt).getStatementList();
				ListIterator	iter	= stmt_list.listIterator(0);
				while (iter.hasNext() == true)
				{
					cmpd_stmt.addStatement((Statement)iter.next());
				}
			}
			else
			{
				cmpd_stmt.addStatement(stmt);
			}

			//System.out.println("\n\n\n **** statement added into compound statement ****\n\n\n");
		}

        return true;
    }

	//almost handle in the same way, we don't need a separator in this case.
    protected boolean action____statement_list__statement_list__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement_list__statement_list__statement() NodeID = " + node.getNodeID());
        }
		
		if (__action_status__ == __ACTION_BEFORE__)
		{
			//nothing
		}
		else
		{
			//System.out.println(" ---- before popping the stmt_list -> stmt_list stmt ----");
			//semantic_stack_display();
			//pick up the statement on the semantic stack and add it into the underlying compound statement
			Statement	stmt = (Statement)(semantic_stack.pop());
			//add into the compound statement
			CompoundStatement	cmpd_stmt = (CompoundStatement)(symbol_table_stack.peek());

			if (stmt instanceof TW_StatementList)
			{
				LinkedList	stmt_list	= ((TW_StatementList)stmt).getStatementList();
				ListIterator	iter	= stmt_list.listIterator(0);
				while (iter.hasNext() == true)
				{
					cmpd_stmt.addStatement((Statement)iter.next());
				}
			}
			else
			{
				cmpd_stmt.addStatement(stmt);				
			}
		}		

        return true;
    }

    protected boolean action____statement_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____statement_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____storage_class_specifier__AUTO(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__AUTO() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.AUTO);
        return true;
    }

    protected boolean action____storage_class_specifier__EXTERN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__EXTERN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.EXTERN);
        return true;
    }

    protected boolean action____storage_class_specifier__REGISTER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__REGISTER() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.REGISTER);
        return true;
    }

    protected boolean action____storage_class_specifier__STATIC(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__STATIC() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.STATIC);
        return true;
    }

    protected boolean action____storage_class_specifier__TYPEDEF(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__TYPEDEF() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.TYPEDEF);
        return true;
    }

    protected boolean action____storage_class_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____storage_class_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_declaration__specifier_qualifier_list__struct_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declaration__specifier_qualifier_list__struct_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//semantic_stack.push(new semantic_stack_separator(node.getNodeID()));
		}
		else	//this would end up with a declaration on top of the stack
		{
			List	struct_decl_list	= (List)(semantic_stack.pop());
			List	spec_list			= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_list, struct_decl_list));
		}

        return true;
    }

    protected boolean action____struct_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____struct_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_declaration_list__struct_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declaration_list__struct_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			LinkedList	decl_list = new LinkedList();

			Declaration	decl	= (Declaration)(semantic_stack.pop());
			decl_list.add(decl);
			semantic_stack.push(decl_list);
		}

        return true;
    }

    protected boolean action____struct_declaration_list__struct_declaration_list__struct_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declaration_list__struct_declaration_list__struct_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			List		decl_list	= (List)(semantic_stack.peek());
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____struct_declaration_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declaration_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____struct_declaration_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_declarator__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator__declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//there should be a declarator on the stack already, do nothing
		}

        return true;
    }

    protected boolean action____struct_declarator__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator__COLON__constant_expression() NodeID = " + node.getNodeID());
        }

		//don't know how to handle this case yet
        errorExit("action____struct_declarator__COLON__constant_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_declarator__declarator__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator__declarator__COLON__constant_expression() NodeID = " + node.getNodeID());
        }

		//don't know how to handle this case yet.
        errorExit("action____struct_declarator__declarator__COLON__constant_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____struct_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_declarator_list__struct_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator_list__struct_declarator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
        }
		else
		{
			Declarator	decl = (Declarator)(semantic_stack.pop());
			LinkedList	decl_list = new LinkedList();
			decl_list.add(decl);
			semantic_stack.push(decl_list);
		}

        return true;
    }

    protected boolean action____struct_declarator_list__struct_declarator_list__COMMA__struct_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator_list__struct_declarator_list__COMMA__struct_declarator() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
        }
		else
		{
			Declarator	decl = (Declarator)(semantic_stack.pop());
			List		decl_list = (List)(semantic_stack.peek());
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____struct_declarator_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_declarator_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____struct_declarator_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_or_union__STRUCT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union__STRUCT() NodeID = " + node.getNodeID());
        }

		//in this case, we just need to push a String into the stack
		semantic_stack.push(new String("struct"));
        return true;
    }

    protected boolean action____struct_or_union__UNION(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union__UNION() NodeID = " + node.getNodeID());
        }

		//push "union"
		semantic_stack.push(new String("union"));
		return true;
    }

    protected boolean action____struct_or_union__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____struct_or_union__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_or_union_specifier__struct_or_union__IDENTIFIER__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union_specifier__struct_or_union__IDENTIFIER__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			// the stack lay out should be: struct/union(String) -- LinkedList
			LinkedList	decl_list		= (LinkedList)(semantic_stack.pop());
			String		struct_or_union	= ((String)(semantic_stack.pop())).trim();
			String		id_name			= (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();

			ClassDeclaration	class_decl = null;
			if (struct_or_union.compareTo("struct") == 0)
			{
				class_decl = new ClassDeclaration(ClassDeclaration.STRUCT, new Identifier((String)id_name));

				ListIterator	struc_decl_iter = decl_list.listIterator(0);	//iterator();
				while (struc_decl_iter.hasNext() == true)
				{
					class_decl.addDeclaration((Declaration)(struc_decl_iter.next()));
				}

				//add this class decl into the local symbol table, and put a user type specifier in the semantic stack
				Object	outer	= symbol_table_stack.peek();
				if (outer instanceof CompoundStatement)
				{
					CompoundStatement	cmpd_stmt = (CompoundStatement)outer;	//(symbol_table_stack.peek());
					cmpd_stmt.addDeclaration(class_decl);
				}
				else if (outer instanceof TranslationUnit)
				{
					TranslationUnit		tran_unit = (TranslationUnit)outer;
					tran_unit.addDeclaration(class_decl);
				}

				semantic_stack.push(new UserSpecifier(new Identifier("struct " + id_name)));
			}
			else if (struct_or_union.compareTo("union") == 0)
			{
				class_decl = new ClassDeclaration(ClassDeclaration.UNION, new Identifier((String)id_name));

				ListIterator	struc_decl_iter = decl_list.listIterator(0);	//iterator();
				while (struc_decl_iter.hasNext() == true)
				{
					class_decl.addDeclaration((Declaration)(struc_decl_iter.next()));
				}

				//add this class decl into the local symbol table, and put a user type specifier in the semantic stack
				Object	outer	= symbol_table_stack.peek();
				if (outer instanceof CompoundStatement)
				{
					CompoundStatement	cmpd_stmt = (CompoundStatement)outer;
					cmpd_stmt.addDeclaration(class_decl);
				}
				else if (outer instanceof TranslationUnit)
				{
					TranslationUnit		tran_unit = (TranslationUnit)outer;
					tran_unit.addDeclaration(class_decl);
				}

				semantic_stack.push(new UserSpecifier(new Identifier("union " + id_name)));
			}
			else
			{
				errorExit("struct_or_union can only be \"struct\" / \"union\".");
			}
		}

        return true;
    }

    protected boolean action____struct_or_union_specifier__struct_or_union__USERTYPE__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union_specifier__struct_or_union__USERTYPE__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		/* TODO: user type*/
		//don't know how to handle user type yet.
        errorExit("action____struct_or_union_specifier__struct_or_union__USERTYPE__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_or_union_specifier__struct_or_union__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union_specifier__struct_or_union__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//create a unique name first
			String unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());

			// the stack lay out should be: struct/union(String) -- LinkedList
			LinkedList	decl_list		= (LinkedList)(semantic_stack.pop());
			String		struct_or_union	= ((String)(semantic_stack.pop())).trim();
			String		id_name			= unique_name.trim();

			ClassDeclaration	class_decl = null;
			if (struct_or_union.compareTo("struct") == 0)
			{
				class_decl = new ClassDeclaration(ClassDeclaration.STRUCT, new Identifier(id_name));

				ListIterator	struc_decl_iter = decl_list.listIterator(0);	//iterator();
				while (struc_decl_iter.hasNext() == true)
				{
					class_decl.addDeclaration((Declaration)(struc_decl_iter.next()));
				}

				//add this class decl into the local symbol table, and put a user type specifier in the semantic stack
				Object	outer = symbol_table_stack.peek();
				if (outer instanceof CompoundStatement)
				{
					CompoundStatement	cmpd_stmt = (CompoundStatement)outer;
					cmpd_stmt.addDeclaration(class_decl);
				}
				else if (outer instanceof TranslationUnit)
				{
					TranslationUnit tran_unit = (TranslationUnit)outer;
					tran_unit.addDeclaration(class_decl);
				}

				semantic_stack.push(new UserSpecifier(new Identifier("struct " + id_name)));
			}
			else if (struct_or_union.compareTo("union") == 0)
			{
				class_decl = new ClassDeclaration(ClassDeclaration.UNION, new Identifier((String)id_name));

				ListIterator	struc_decl_iter = decl_list.listIterator(0);	//iterator();
				while (struc_decl_iter.hasNext() == true)
				{
					class_decl.addDeclaration((Declaration)(struc_decl_iter.next()));
				}

				//add this class decl into the local symbol table, and put a user type specifier in the semantic stack
				Object	outer = symbol_table_stack.peek();
				if (outer instanceof CompoundStatement)
				{
					CompoundStatement	cmpd_stmt = (CompoundStatement)outer;
					cmpd_stmt.addDeclaration(class_decl);
				}
				else if (outer instanceof TranslationUnit)
				{
					TranslationUnit tran_unit = (TranslationUnit)outer;
					tran_unit.addDeclaration(class_decl);
				}

				semantic_stack.push(new UserSpecifier(new Identifier("union " + id_name)));
			}
			else
			{
				errorExit("struct_or_union can only be \"struct\" / \"union\".");
			}
		}

        return true;
    }

    protected boolean action____struct_or_union_specifier__struct_or_union__IDENTIFIER(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union_specifier__struct_or_union__IDENTIFIER() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else	//this should leave a UserSpecifier on top of the stack
		{
			//the stack layout will be: struct/union
			String struct_or_union = ((String)(semantic_stack.pop())).trim();
			String id_name = (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();

			if ((struct_or_union.compareTo("struct") == 0)
				|| (struct_or_union.compareTo("union") == 0))
			{
				semantic_stack.push(new UserSpecifier(new Identifier(struct_or_union + " " + id_name)));
			}
			else
			{
				//semantic_stack_display();
				errorExit("Error: expecting struct/union id_name !\n");
			}
		}

        return true;
    }

    protected boolean action____struct_or_union_specifier__struct_or_union__USERTYPE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union_specifier__struct_or_union__USERTYPE() NodeID = " + node.getNodeID());
        }

		/* TODO: */
		//don't know what to do with usertype yet.
        errorExit("action____struct_or_union_specifier__struct_or_union__USERTYPE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____struct_or_union_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____struct_or_union_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____struct_or_union_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____translation_unit__declaration_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____translation_unit__declaration_list() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//create an object for translation unit
			TU = new TranslationUnit(TU_filename);
			if (TU == null)
			{
				errorExit("Error: Unable to create TranslationUnit.");
			}
			else
			{
				//insert the TU object into the symbol table stack
				symbol_table_stack.push(TU);
				semantic_stack.push(TU);	//later we can pop and add more declarations

				if (debug_display == true)
				{
					System.out.println("TranslationUnit created!");
					System.out.println("TranslationUnit pushed into symbol_table_stack & semantic stack");
				}
			}
			//semantic_stack_display();
		}
		else
		{
			LinkedList	decl_list = (LinkedList)(semantic_stack.pop());
			TranslationUnit	tran_unit = (TranslationUnit)(symbol_table_stack.peek());

			//add the declarations into the translation unit one by one
			ListIterator	decl_iter = decl_list.listIterator(0);
			while (decl_iter.hasNext())
			{
				Declaration	decl = (Declaration)(decl_iter.next());
				tran_unit.addDeclaration(decl);
			}

			symbol_table_stack.pop();	//clean the stacks
			semantic_stack.pop();
		}

        return true;
    }

    protected boolean action____translation_unit__empty(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____translation_unit__empty() NodeID = " + node.getNodeID());
        }

        if (debug_display == true)
        {
			System.out.println(TU_filename + " is empty -- nothing to be done.");
		}
        return true;
    }

    protected boolean action____translation_unit__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____translation_unit__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */
        errorExit("action____translation_unit__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_name__specifier_qualifier_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_name__specifier_qualifier_list() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			//there should be list of specs already, do nothing
		}

        return true;
    }

    protected boolean action____type_name__specifier_qualifier_list__abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_name__specifier_qualifier_list__abstract_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
		}
		else
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
			LinkedList	t_specs		= null;

			LinkedList	type_name_list = new LinkedList();
			type_name_list.add(new Declarator(spec_list, decl, t_specs));

			semantic_stack.push(type_name_list);
		}

		return true;
    }

    protected boolean action____type_name__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_name__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_name__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_qualifier__CONST(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_qualifier__CONST() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.CONST);
        return true;
    }

    protected boolean action____type_qualifier__VOLATILE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_qualifier__VOLATILE() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.VOLATILE);
        return true;
    }

    protected boolean action____type_qualifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_qualifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_qualifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_qualifier_list__type_qualifier() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
        }
		else	//this should end up with a linked list of Specifiers on top of the stack
		{
			LinkedList spec_list = new LinkedList();

			Specifier	spec = (Specifier)(semantic_stack.pop());
			spec_list.add(spec);

			//put the list on the stack
			semantic_stack.push(spec_list);
		}
		
		return true;
    }

    protected boolean action____type_qualifier_list__type_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_qualifier_list__type_qualifier_list__type_qualifier() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_BEFORE__)
        {
			//bury a separator into the stack
			semantic_stack.push(new semantic_stack_separator(node.getNodeID()));
        }
		else	//this should end up with a linked list of Specifiers on top of the stack
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.peek());

			spec_list.add(spec);
		}

        return true;
    }

    protected boolean action____type_qualifier_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_qualifier_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_qualifier_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__VOID(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__VOID() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.VOID);
        return true;
    }

    protected boolean action____type_specifier__CHAR(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CHAR() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.CHAR);
        return true;
    }

    protected boolean action____type_specifier__SHORT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__SHORT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.SHORT);
        return true;
    }

    protected boolean action____type_specifier__INT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__INT() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Specifier.INT);
        return true;
    }

    protected boolean action____type_specifier__LONG(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__LONG() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.LONG);
        return true;
    }

    protected boolean action____type_specifier__FLOAT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__FLOAT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.FLOAT);
        return true;
    }

    protected boolean action____type_specifier__DOUBLE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__DOUBLE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.DOUBLE);
        return true;
    }

    protected boolean action____type_specifier__SIGNED(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__SIGNED() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.SIGNED);
        return true;
    }

    protected boolean action____type_specifier__UNSIGNED(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNSIGNED() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.UNSIGNED);
        return true;
    }

    protected boolean action____type_specifier__struct_or_union_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__struct_or_union_specifier() NodeID = " + node.getNodeID());
        }

		//in this case, we would already have a specifier (UserSpecifier) on the stack
		//just do nothing
        return true;
    }

    protected boolean action____type_specifier__enum_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__enum_specifier() NodeID = " + node.getNodeID());
        }

		//there should be a user specifier on top of the stack already
        return true;
    }

    protected boolean action____type_specifier__USERTYPE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__USERTYPE() NodeID = " + node.getNodeID());
        }

		/* TODO: */
		//not clear what to do at this time
        errorExit("action____type_specifier__USERTYPE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__VA_LIST(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__VA_LIST() NodeID = " + node.getNodeID());
        }

		/* TODO: */
		//not clear what to do at this time
        errorExit("action____type_specifier__VA_LIST() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__WCHAR_T(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__WCHAR_T() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.WCHAR_T);
        return true;
    }

    protected boolean action____type_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

		//handle user type
        String	id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();
		semantic_stack.push(new UserSpecifier(new Identifier(id_name)));

        return true;
    }

    protected boolean action____unary_expression__postfix_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__postfix_expression() NodeID = " + node.getNodeID());
        }

		//there should be an expression on top of the stack.
		//nothing to do here

        return true;
    }

    protected boolean action____unary_expression__INC_OP__unary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__INC_OP__unary_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new UnaryExpression(UnaryOperator.PRE_INCREMENT, (Expression)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____unary_expression__DEC_OP__unary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__DEC_OP__unary_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new UnaryExpression(UnaryOperator.PRE_DECREMENT, (Expression)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____unary_expression__unary_operator__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__unary_operator__cast_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression expr = (Expression)semantic_stack.pop();
			UnaryOperator op = (UnaryOperator)semantic_stack.pop();
			semantic_stack.push(new UnaryExpression(op, expr));
        }

        return true;
    }

    protected boolean action____unary_expression__SIZEOF__unary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__SIZEOF__unary_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			semantic_stack.push(new SizeofExpression((Expression)semantic_stack.pop()));
        }

        return true;
    }

    protected boolean action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }
		
        if (__action_status__ == __ACTION_AFTER__)
        {
			List	spec_list = (List)(semantic_stack.pop());
			semantic_stack.push(new SizeofExpression(spec_list));
		}		

        return true;
    }

    protected boolean action____unary_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____unary_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_operator__AMPERSAND(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__AMPERSAND() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.ADDRESS_OF);
        return true;
    }

    protected boolean action____unary_operator__ASTERISK(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__ASTERISK() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.DEREFERENCE);
        return true;
    }

    protected boolean action____unary_operator__PLUS_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__PLUS_SIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.PLUS);
        return true;
    }

    protected boolean action____unary_operator__MINUS_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__MINUS_SIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.MINUS);
        return true;
    }

    protected boolean action____unary_operator__TILDE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__TILDE() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.BITWISE_COMPLEMENT);
        return true;
    }

    protected boolean action____unary_operator__BANG(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__BANG() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.LOGICAL_NEGATION);
        return true;
    }

    protected boolean action____unary_operator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        /* unused */

        errorExit("action____unary_operator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

}


