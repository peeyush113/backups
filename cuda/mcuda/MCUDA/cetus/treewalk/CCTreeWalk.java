
package cetus.treewalk;

import java.lang.*;
import java.util.*;

import cetus.hir.*;

public class CCTreeWalk extends CCTreeWalkBase
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

    public CCTreeWalk()
    {
        super();
		semantic_stack		= new Stack();
		symbol_table_stack	= new Stack();
    }


/*
    protected boolean debug_display = false;
*/

	//write a function for this job, since it's appearing in many places
	protected String getStringLiteral(GeneralSyntaxNode node, int child_index)
	{
		String		str_lit		= new String(((GeneralSyntaxNode)(node.getChild(child_index))).getInfoString());

		if (str_lit.startsWith("\"") && str_lit.endsWith("\""))
		{
			str_lit = str_lit.substring(1, str_lit.length()-1);
		}

		return str_lit;
	}
	
	protected boolean action____STRING_LITERAL_seq__STRING_LITERAL(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____STRING_LITERAL_seq__STRING_LITERAL() NodeID = " + node.getNodeID());
        }

		LinkedList	str_lit_seq = new LinkedList();

		/*
		String		str_lit		= new String(((GeneralSyntaxNode)(node.getChild(0))).getInfoString());

		if (str_lit.startsWith("\"") && str_lit.endsWith("\""))
		{
			str_lit = str_lit.substring(1, str_lit.length()-1);
		}
*/
		str_lit_seq.add( new String( getStringLiteral(node, 0) ) );
		semantic_stack.push(str_lit_seq);

        return true;
    }

    protected boolean action____STRING_LITERAL_seq__STRING_LITERAL_seq__STRING_LITERAL(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____STRING_LITERAL_seq__STRING_LITERAL_seq__STRING_LITERAL() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			String		str_lit		= getStringLiteral(node, 1);
			LinkedList	str_lit_seq = (LinkedList)(semantic_stack.peek());
			str_lit_seq.add(new String(str_lit));
		}

        return true;
    }

    protected boolean action____STRING_LITERAL_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____STRING_LITERAL_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____STRING_LITERAL_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____abstract_declarator__ptr_operator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__ptr_operator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List		spec_list	= (List)(semantic_stack.pop());
			Declarator	decl		= null;
			LinkedList	param_list	= null;

			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____abstract_declarator__ptr_operator__abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__ptr_operator__abstract_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
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

		//nothing to do
        return true;
    }

    protected boolean action____abstract_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____abstract_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____abstract_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____access_specifier__PRIVATE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____access_specifier__PRIVATE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.PRIVATE);
        return true;
    }

    protected boolean action____access_specifier__PROTECTED(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____access_specifier__PROTECTED() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.PROTECTED);
        return true;
    }

    protected boolean action____access_specifier__PUBLIC(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____access_specifier__PUBLIC() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.PUBLIC);
        return true;
    }

    protected boolean action____access_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____access_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____access_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____additive_expression__multiplicative_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____additive_expression__multiplicative_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
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

//------- You need to handle ambiguity here -------//
        errorExit("action____additive_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____and_expression__equality_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____and_expression__equality_expression() NodeID = " + node.getNodeID());
        }

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

//------- You need to handle ambiguity here -------//
        errorExit("action____and_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____any_word__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____any_word__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        errorExit("action____any_word__IDENTIFIER() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____any_word__storage_class_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____any_word__storage_class_specifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____any_word__storage_class_specifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____any_word__cv_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____any_word__cv_qualifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____any_word__cv_qualifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____any_word__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____any_word__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____any_word__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_clobbers__STRING_LITERAL(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_clobbers__STRING_LITERAL() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_clobbers__STRING_LITERAL() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_clobbers__asm_clobbers__COMMA__STRING_LITERAL(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_clobbers__asm_clobbers__COMMA__STRING_LITERAL() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_clobbers__asm_clobbers__COMMA__STRING_LITERAL() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_clobbers__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_clobbers__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_clobbers__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__COLON__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__SCOPE__asm_operands__COLON__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__ASM__cv_qualifier__LEFT_PARENTHESIS__STRING_LITERAL_seq__COLON__asm_operands__SCOPE__asm_clobbers__RIGHT_PARENTHESIS__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_definition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_definition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_definition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_operand__STRING_LITERAL__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_operand__STRING_LITERAL__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_operand__STRING_LITERAL__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_operand__LEFT_BRACKET__IDENTIFIER__RIGHT_BRACKET__STRING_LITERAL__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_operand__LEFT_BRACKET__IDENTIFIER__RIGHT_BRACKET__STRING_LITERAL__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_operand__LEFT_BRACKET__IDENTIFIER__RIGHT_BRACKET__STRING_LITERAL__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_operand__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_operand__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_operand__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_operands__asm_operand(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_operands__asm_operand() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_operands__asm_operand() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_operands__asm_operands__COMMA__asm_operand(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_operands__asm_operands__COMMA__asm_operand() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_operands__asm_operands__COMMA__asm_operand() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____asm_operands__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____asm_operands__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____asm_operands__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____assignment_expression__conditional_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__conditional_expression() NodeID = " + node.getNodeID());
        }

        //nothing here
        return true;
    }

    protected boolean action____assignment_expression__logical_or_expression__assignment_operator__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__logical_or_expression__assignment_operator__assignment_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression			right	= (Expression)(semantic_stack.pop());
			AssignmentOperator	op		= (AssignmentOperator)(semantic_stack.pop());
			Expression			left	= (Expression)(semantic_stack.pop());

			semantic_stack.push(new AssignmentExpression(left, op, right));
		}
		
		return true;
    }

    protected boolean action____assignment_expression__throw_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__throw_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing here, just return an expression
		}

        return true;
    }

    protected boolean action____assignment_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

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

    protected boolean action____assignment_operator__RIGHT_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____assignment_operator__RIGHT_ASSIGN() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(AssignmentOperator.SHIFT_RIGHT);
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

        errorExit("action____assignment_operator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attrib__any_word(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attrib__any_word() NodeID = " + node.getNodeID());
        }

        errorExit("action____attrib__any_word() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attrib__any_word__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attrib__any_word__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____attrib__any_word__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attrib__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attrib__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____attrib__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attribute__ATTRIBUTE__LEFT_PARENTHESIS__LEFT_PARENTHESIS__attribute_list__RIGHT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attribute__ATTRIBUTE__LEFT_PARENTHESIS__LEFT_PARENTHESIS__attribute_list__RIGHT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____attribute__ATTRIBUTE__LEFT_PARENTHESIS__LEFT_PARENTHESIS__attribute_list__RIGHT_PARENTHESIS__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attribute__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attribute__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____attribute__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attribute_list__attrib(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attribute_list__attrib() NodeID = " + node.getNodeID());
        }

        errorExit("action____attribute_list__attrib() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attribute_list__attribute_list__COMMA__attrib(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attribute_list__attribute_list__COMMA__attrib() NodeID = " + node.getNodeID());
        }

        errorExit("action____attribute_list__attribute_list__COMMA__attrib() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attribute_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attribute_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____attribute_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attributes__attribute(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attributes__attribute() NodeID = " + node.getNodeID());
        }

        errorExit("action____attributes__attribute() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attributes__attributes__attribute(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attributes__attributes__attribute() NodeID = " + node.getNodeID());
        }

        errorExit("action____attributes__attributes__attribute() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____attributes__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____attributes__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____attributes__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_clause__COLON__base_specifier_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_clause__COLON__base_specifier_list() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing here, it's a list already
		}

        return true;
    }

    protected boolean action____base_clause__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_clause__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_clause__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__VIRTUAL__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__VIRTUAL__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__VIRTUAL__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__VIRTUAL__access_specifier__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__VIRTUAL__access_specifier__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__VIRTUAL__access_specifier__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__VIRTUAL__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__VIRTUAL__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__VIRTUAL__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__VIRTUAL__access_specifier__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__VIRTUAL__access_specifier__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__VIRTUAL__access_specifier__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__access_specifier__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__access_specifier__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__access_specifier__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__access_specifier__VIRTUAL__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__access_specifier__VIRTUAL__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__access_specifier__VIRTUAL__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__access_specifier__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__access_specifier__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__access_specifier__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__access_specifier__VIRTUAL__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__access_specifier__VIRTUAL__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__access_specifier__VIRTUAL__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier_list__base_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier_list__base_specifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier_list__base_specifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier_list__base_specifier_list__COMMA__base_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier_list__base_specifier_list__COMMA__base_specifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier_list__base_specifier_list__COMMA__base_specifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____base_specifier_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____base_specifier_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____base_specifier_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____block_declaration__simple_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__simple_declaration() NodeID = " + node.getNodeID());
        }

		//nothing to do here
        return true;
    }

    protected boolean action____block_declaration__asm_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__asm_definition() NodeID = " + node.getNodeID());
        }

        errorExit("action____block_declaration__asm_definition() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____block_declaration__namespace_alias_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__namespace_alias_definition() NodeID = " + node.getNodeID());
        }

		//nothing here, since namespace_aslias is already a declaration
        return true;
    }

    protected boolean action____block_declaration__using_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__using_declaration() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____block_declaration__using_directive(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__using_directive() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____block_declaration__EXTENSION__simple_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__EXTENSION__simple_declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____block_declaration__EXTENSION__simple_declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____block_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____block_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____block_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____boolean_literal__CTRUE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____boolean_literal__CTRUE() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(new BooleanLiteral(true));
        return true;
    }

    protected boolean action____boolean_literal__CFALSE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____boolean_literal__CFALSE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new BooleanLiteral(false));
        return true;
    }

    protected boolean action____boolean_literal__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____boolean_literal__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____boolean_literal__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____cast_expression__unary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__unary_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		spec_list = null;

			semantic_stack.push(new Typecast(spec_list, expr));
		}

        return true;
    }

    protected boolean action____cast_expression__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		spec_list = (List)(semantic_stack.pop());
			semantic_stack.push(new Typecast(spec_list, expr));
		}		

        return true;
    }

    protected boolean action____cast_expression__LEFT_PARENTHESIS__compound_statement__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__LEFT_PARENTHESIS__compound_statement__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____cast_expression__LEFT_PARENTHESIS__compound_statement__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____cast_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cast_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____cast_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____class_name__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____class_name__IDENTIFIER() NodeID = " + node.getNodeID());
        }

		String	str_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString();
		semantic_stack.push(new Identifier(str_name));

        return true;
    }

    protected boolean action____class_name__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____class_name__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET() NodeID = " + node.getNodeID());
        }

        errorExit("action____class_name__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____class_name__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____class_name__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET() NodeID = " + node.getNodeID());
        }

        errorExit("action____class_name__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____class_name__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____class_name__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____class_name__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

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

    protected boolean action____compound_statement__LEFT_BRACE__statement_seq__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____compound_statement__LEFT_BRACE__statement_seq__RIGHT_BRACE() NodeID = " + node.getNodeID());
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

        errorExit("action____compound_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____condition__expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____condition__expression() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____condition__type_specifier_seq__declarator__EQUAL_SIGN__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____condition__type_specifier_seq__declarator__EQUAL_SIGN__assignment_expression() NodeID = " + node.getNodeID());
        }

		errorExit("action____condition__ : if(int i = 0) hasn't been supported yet.");
		return false;
/*
		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	assign_expr = (Expression)(semantic_stack.pop());
			Initializer	init		= new Initializer(assign_expr);

			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
			LinkedList	param_list	= null;

			Declarator	init_decl	= new Declarator(spec_list, decl, param_list);
			init_decl.setInitializer(init);
		}

        return true; */
    }

    protected boolean action____condition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____condition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____condition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conditional_expression__logical_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conditional_expression__logical_or_expression() NodeID = " + node.getNodeID());
        }

        //nothing here
        return true;
    }

    protected boolean action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__assignment_expression() NodeID = " + node.getNodeID());
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

        errorExit("action____conditional_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____constant_expression__conditional_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____constant_expression__conditional_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____constant_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____constant_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____constant_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____constant_initializer__EQUAL_SIGN__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____constant_initializer__EQUAL_SIGN__constant_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression		const_expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new Initializer(const_expr));
		}

        return true;
    }

    protected boolean action____constant_initializer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____constant_initializer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____constant_initializer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_declarator__ptr_operator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_declarator__ptr_operator() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_declarator__ptr_operator() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_declarator__ptr_operator__conversion_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_declarator__ptr_operator__conversion_declarator() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_declarator__ptr_operator__conversion_declarator() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_function_id__OPERATOR__conversion_type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_function_id__OPERATOR__conversion_type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_function_id__OPERATOR__conversion_type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_function_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_function_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_function_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_type_id__type_specifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_type_id__type_specifier_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_type_id__type_specifier_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_type_id__type_specifier_seq__conversion_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_type_id__type_specifier_seq__conversion_declarator() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_type_id__type_specifier_seq__conversion_declarator() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____conversion_type_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____conversion_type_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____conversion_type_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ctor_initializer__COLON__mem_initializer_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ctor_initializer__COLON__mem_initializer_list() NodeID = " + node.getNodeID());
        }

        errorExit("action____ctor_initializer__COLON__mem_initializer_list() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ctor_initializer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ctor_initializer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____ctor_initializer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____cv_qualifier__CONST(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier__CONST() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.CONST);
        return true;
    }

    protected boolean action____cv_qualifier__VOLATILE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier__VOLATILE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.VOLATILE);
        return true;
    }

    protected boolean action____cv_qualifier__RESTRICT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier__RESTRICT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.RESTRICT);
        return true;
    }

    protected boolean action____cv_qualifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____cv_qualifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____cv_qualifier_seq__cv_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier_seq__cv_qualifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Specifier spec = (Specifier)(semantic_stack.pop());
			LinkedList	spec_list = new LinkedList();
			spec_list.add(spec);
			semantic_stack.push(spec_list);
		}

        return true;
    }

    protected boolean action____cv_qualifier_seq__cv_qualifier_seq__cv_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier_seq__cv_qualifier_seq__cv_qualifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			LinkedList	spec_list	= (LinkedList)(semantic_stack.peek());
			spec_list.add(spec);
		}

        return true;
    }

    protected boolean action____cv_qualifier_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____cv_qualifier_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____cv_qualifier_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____decl_specifier__storage_class_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier__storage_class_specifier() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____decl_specifier__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier__type_specifier() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____decl_specifier__function_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier__function_specifier() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____decl_specifier__FRIEND(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier__FRIEND() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.FRIEND);
        return true;
    }

    protected boolean action____decl_specifier__TYPEDEF(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier__TYPEDEF() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.TYPEDEF);
        return true;
    }

    protected boolean action____decl_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____decl_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____decl_specifier_seq__decl_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier_seq__decl_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	spec_list	= new LinkedList();
			Specifier	spec		= (Specifier)(semantic_stack.pop());

			semantic_stack.push(spec_list);
		}

		return true;
    }

    protected boolean action____decl_specifier_seq__decl_specifier_seq__decl_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier_seq__decl_specifier_seq__decl_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			LinkedList	spec_list	= (LinkedList)(semantic_stack.peek());
			spec_list.add(spec);
		}

        return true;
    }

    protected boolean action____decl_specifier_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____decl_specifier_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____decl_specifier_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration__block_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__block_declaration() NodeID = " + node.getNodeID());
        }

		//nothing to do
		//there should be a declaration on top of the stack already
        return true;
    }

    protected boolean action____declaration__function_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__function_definition() NodeID = " + node.getNodeID());
        }

		//nothing to do here
        return true;
    }

    protected boolean action____declaration__template_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__template_declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____declaration__template_declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration__explicit_instantiation(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__explicit_instantiation() NodeID = " + node.getNodeID());
        }

        errorExit("action____declaration__explicit_instantiation() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration__explicit_specialization(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__explicit_specialization() NodeID = " + node.getNodeID());
        }

        errorExit("action____declaration__explicit_specialization() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration__linkage_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__linkage_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____declaration__linkage_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration__namespace_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__namespace_definition() NodeID = " + node.getNodeID());
        }

		//TODO: not very sure if we need to do anything here
        return true;
    }

    protected boolean action____declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declaration_seq__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_seq__declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	decl_seq	= new LinkedList();
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			decl_seq.add(decl);
			semantic_stack.push(decl_seq);
		}		

        return true;
    }

    protected boolean action____declaration_seq__declaration_seq__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_seq__declaration_seq__declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			LinkedList	decl_seq	= (LinkedList)(semantic_stack.peek());
			
			decl_seq.add(decl);
		}

        return true;
    }

    protected boolean action____declaration_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declaration_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declaration_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declarator__direct_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator__direct_declarator() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____declarator__ptr_operator__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator__ptr_operator__declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		ptr_list	= (List)(semantic_stack.pop());
			List		param_list	= null;

			semantic_stack.push(new Declarator(ptr_list, decl, param_list));
		}

        return true;
    }

    protected boolean action____declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declarator_head__declarator_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_head__declarator_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Identifier	id = (Identifier)(semantic_stack.pop());
			semantic_stack.push(new Declarator(id));
		}

		return true;
    }

    protected boolean action____declarator_head__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_head__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing to do
		}

        return true;
    }

	//here, ptr_op is considered a PointerSpecifier
    protected boolean action____declarator_head__ptr_operator__declarator_head(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_head__ptr_operator__declarator_head() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator			decl		= (Declarator)(semantic_stack.pop());
			PointerSpecifier	ptr_spec	= (PointerSpecifier)(semantic_stack.pop());
			LinkedList			spec_list	= new LinkedList();
			spec_list.add(ptr_spec);
			LinkedList			param_list	= null;

			semantic_stack.push(new Declarator(spec_list, decl, param_list));
		}

		return true;
    }

    protected boolean action____declarator_head__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_head__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declarator_head__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declarator_id__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_id__id_expression() NodeID = " + node.getNodeID());
        }

		//nothing to do here
        return true;
    }

    protected boolean action____declarator_id__SCOPE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_id__SCOPE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____declarator_id__SCOPE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declarator_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declarator_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	param_decl_clause = (LinkedList)(semantic_stack.pop());
			semantic_stack.push(new DeclaratorTail(param_decl_clause));
		}

        return true;
    }

    protected boolean action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	qualifier_seq		= (LinkedList)(semantic_stack.pop());
			LinkedList	param_decl_clause	= (LinkedList)(semantic_stack.pop());
			semantic_stack.push(new DeclaratorTail(param_decl_clause, qualifier_seq));
		}

        return true;
    }

    protected boolean action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			ThrowExpression throw_expr		= (ThrowExpression)(semantic_stack.pop());
			LinkedList	param_decl_clause	= (LinkedList)(semantic_stack.pop());
			semantic_stack.push(new DeclaratorTail(param_decl_clause, throw_expr));
		}

        return true;
    }

    protected boolean action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			ThrowExpression throw_expr		= (ThrowExpression)(semantic_stack.pop());
			LinkedList	qualifier_seq		= (LinkedList)(semantic_stack.pop());
			LinkedList	param_decl_clause	= (LinkedList)(semantic_stack.pop());
			semantic_stack.push(new DeclaratorTail(param_decl_clause, qualifier_seq, throw_expr));
		}

        return true;
    }

    protected boolean action____declarator_tail__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new DeclaratorTail());
		return true;
    }

    protected boolean action____declarator_tail__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new DeclaratorTail(expr));
		}

        return true;
    }

    protected boolean action____declarator_tail__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declarator_tail__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____declarator_tail_seq__declarator_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail_seq__declarator_tail() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			DeclaratorTail	tail		= (DeclaratorTail)(semantic_stack.pop());
			LinkedList		tail_seq	= new LinkedList();
			tail_seq.add(tail);
			semantic_stack.push(tail_seq);
		}

        return true;
    }

    protected boolean action____declarator_tail_seq__declarator_tail_seq__declarator_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail_seq__declarator_tail_seq__declarator_tail() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			DeclaratorTail	tail		= (DeclaratorTail)(semantic_stack.pop());
			LinkedList		tail_seq	= (LinkedList)(semantic_stack.peek());
			tail_seq.add(tail);
		}

        return true;
    }

    protected boolean action____declarator_tail_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____declarator_tail_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____declarator_tail_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____delete_expression__DELETE__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____delete_expression__DELETE__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new DeleteExpression(expr));
		}

        return true;
    }

    protected boolean action____delete_expression__SCOPE__DELETE__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____delete_expression__SCOPE__DELETE__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression			expr		= (Expression)(semantic_stack.pop());
			DeleteExpression	del_expr	= new DeleteExpression(expr);
			del_expr.setGlobal();
			semantic_stack.push(del_expr);
		}

        return true;
    }

    protected boolean action____delete_expression__DELETE__LEFT_BRACKET__RIGHT_BRACKET__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____delete_expression__DELETE__LEFT_BRACKET__RIGHT_BRACKET__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new DeleteExpression(true, expr));
		}

        return true;
    }

    protected boolean action____delete_expression__SCOPE__DELETE__LEFT_BRACKET__RIGHT_BRACKET__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____delete_expression__SCOPE__DELETE__LEFT_BRACKET__RIGHT_BRACKET__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression			expr		= (Expression)(semantic_stack.pop());
			DeleteExpression	del_expr	= new DeleteExpression(true, expr);
			del_expr.setGlobal();
			semantic_stack.push(del_expr);
		}

        return true;
    }

    protected boolean action____delete_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____delete_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____delete_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List		param_list	= (List)(semantic_stack.pop());
			Declarator	decl		= null;
			semantic_stack.push(new Declarator(decl, param_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	qualifier_list	= (List)(semantic_stack.pop());
			List		param_list	= (List)(semantic_stack.pop());
			IDExpression	id_expr	= null;
			semantic_stack.push(new Declarator(id_expr, param_list, qualifier_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List		param_list	= (List)(semantic_stack.pop());
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			semantic_stack.push(new Declarator(decl, param_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	qualifier_list	= (List)(semantic_stack.pop());
			List		param_list	= (List)(semantic_stack.pop());
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			semantic_stack.push(new Declarator(decl.getSymbol(), param_list, qualifier_list));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		IDExpression	id_expr = null;
		LinkedList		param_list = null;
		semantic_stack.push(new Declarator(id_expr, param_list, new ArraySpecifier()));

        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	const_expr	= (Expression)(semantic_stack.pop());
			IDExpression	id_expr	= null;
			LinkedList	param_list	= null;
			semantic_stack.push(new Declarator(id_expr, param_list, new ArraySpecifier(const_expr)));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl = (Declarator)(semantic_stack.pop());
			LinkedList	param_list = null;

			semantic_stack.push(new Declarator(decl.getSymbol(), param_list, new ArraySpecifier()));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	const_expr	= (Expression)(semantic_stack.pop());
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			LinkedList	param_list	= null;

			semantic_stack.push(new Declarator(decl.getSymbol(), param_list, new ArraySpecifier(const_expr)));
		}

        return true;
    }

    protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl				= (Declarator)(semantic_stack.pop());
			List		leading_spec_list	= null;
			List		param_list			= null;	//new LinkedList();

			semantic_stack.push(new Declarator(leading_spec_list, decl, param_list));
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

    protected boolean action____direct_declarator__declarator_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__declarator_id() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			IDExpression	decl_id = (IDExpression)(semantic_stack.pop());
			semantic_stack.push(new Declarator(decl_id));
        }

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			List		param_list	= (List)(semantic_stack.pop());
			Declarator	decl		= (Declarator)(semantic_stack.pop());

			semantic_stack.push(new Declarator(decl, param_list));
        }

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			List		trailing_specs	= (List)(semantic_stack.pop());
			List		param_list		= (List)(semantic_stack.pop());
			Declarator	decl			= (Declarator)(semantic_stack.pop());

			semantic_stack.push(new Declarator(decl.getSymbol(), param_list, trailing_specs));
        }

        return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__exception_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_declaration_clause__RIGHT_PARENTHESIS__cv_qualifier_seq__exception_specification() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Declarator		decl		= (Declarator)(semantic_stack.pop());
			IDExpression	id_expr		= decl.getSymbol();

			LinkedList		list_param	= null;

			semantic_stack.push(new Declarator(id_expr, list_param, new ArraySpecifier()));
		}
		
		return true;
    }

    protected boolean action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression		const_expr	= (Expression)(semantic_stack.pop());
			Declarator		decl		= (Declarator)(semantic_stack.pop());
			IDExpression	id_expr		= decl.getSymbol();

			LinkedList		list_param	= null;

			semantic_stack.push(new Declarator(id_expr, list_param, new ArraySpecifier(const_expr)));
		}
		
		return true;
    }

    protected boolean action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			//there should be a declarator on top of the stack -- nothing to do	but to add ()

			Declarator	decl = (Declarator)(semantic_stack.pop());
			List		leading_spec_list = null;
			List		param_list		= null;	//new LinkedList();

			semantic_stack.push(new Declarator(leading_spec_list, decl, param_list));
		}

		return true;
    }

    protected boolean action____direct_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

	//this method returns the expr as an index expr in the array specifier
    protected boolean action____direct_new_declarator__LEFT_BRACKET__expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_new_declarator__LEFT_BRACKET__expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			LinkedList	expr_list = new LinkedList();
			expr_list.add(expr);
			semantic_stack.push(expr_list);
		}

        return true;
    }

    protected boolean action____direct_new_declarator__direct_new_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_new_declarator__direct_new_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr		= (Expression)(semantic_stack.pop());
			LinkedList	expr_list	= (LinkedList)(semantic_stack.peek());
			expr_list.addLast(expr);
		}

        return true;
    }

    protected boolean action____direct_new_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____direct_new_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____direct_new_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____enumerator_definition__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_definition__IDENTIFIER() NodeID = " + node.getNodeID());
        }

		String	id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();
        semantic_stack.push(new Declarator(new Identifier(id_name)));

        return true;
    }

    protected boolean action____enumerator_definition__IDENTIFIER__EQUAL_SIGN__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_definition__IDENTIFIER__EQUAL_SIGN__constant_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			String		id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();

			Initializer init	= new Initializer((Expression)(semantic_stack.pop()));
			Declarator	decl	= new Declarator(new Identifier(id_name));
			decl.setInitializer(init);
			semantic_stack.push(decl);
        }

        return true;
    }

    protected boolean action____enumerator_definition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_definition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____enumerator_definition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____enumerator_list__enumerator_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_list__enumerator_definition() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator decl = (Declarator)(semantic_stack.pop());
			LinkedList	enum_list = new LinkedList();
			enum_list.add(decl);
			semantic_stack.push(enum_list);
		}

        return true;
    }

    protected boolean action____enumerator_list__enumerator_list__COMMA__enumerator_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_list__enumerator_list__COMMA__enumerator_definition() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator decl = (Declarator)(semantic_stack.pop());
			LinkedList	enum_list = (LinkedList)(semantic_stack.peek());
			enum_list.add(decl);
		}

        return true;
    }

    protected boolean action____enumerator_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____enumerator_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____enumerator_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____equality_expression__relational_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____equality_expression__relational_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
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

        errorExit("action____equality_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_declaration__type_specifier_seq__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_declaration__type_specifier_seq__declarator() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_declaration__type_specifier_seq__declarator() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_declaration__type_specifier_seq__abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_declaration__type_specifier_seq__abstract_declarator() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_declaration__type_specifier_seq__abstract_declarator() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_declaration__type_specifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_declaration__type_specifier_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_declaration__type_specifier_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_declaration__ELLIPSIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_declaration__ELLIPSIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_declaration__ELLIPSIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____exception_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_specification__THROW__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_specification__THROW__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_specification__THROW__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_specification__THROW__LEFT_PARENTHESIS__type_id_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_specification__THROW__LEFT_PARENTHESIS__type_id_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_specification__THROW__LEFT_PARENTHESIS__type_id_list__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exception_specification__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exception_specification__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____exception_specification__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____exclusive_or_expression__and_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____exclusive_or_expression__and_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
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

        errorExit("action____exclusive_or_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____explicit_instantiation__TEMPLATE__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____explicit_instantiation__TEMPLATE__declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____explicit_instantiation__TEMPLATE__declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____explicit_instantiation__EXTERN__TEMPLATE__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____explicit_instantiation__EXTERN__TEMPLATE__declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____explicit_instantiation__EXTERN__TEMPLATE__declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____explicit_instantiation__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____explicit_instantiation__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____explicit_instantiation__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____explicit_specialization__TEMPLATE__LEFT_ANGLE_BRACKET__RIGHT_ANGLE_BRACKET__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____explicit_specialization__TEMPLATE__LEFT_ANGLE_BRACKET__RIGHT_ANGLE_BRACKET__declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____explicit_specialization__TEMPLATE__LEFT_ANGLE_BRACKET__RIGHT_ANGLE_BRACKET__declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____explicit_specialization__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____explicit_specialization__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____explicit_specialization__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____expression__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression__assignment_expression() NodeID = " + node.getNodeID());
        }

        //nothing here
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
			Expression	expr		= (Expression)(semantic_stack.pop());
			List		expr_list	= (List)(semantic_stack.peek());
			expr_list.add(expr);
        }

        return true;
    }

    protected boolean action____expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____expression_list__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_list__assignment_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	assignment_expr = (Expression)(semantic_stack.pop());
			LinkedList	expr_list		= new LinkedList();
			expr_list.add(assignment_expr);
			
			semantic_stack.push(expr_list);
		}

        return true;
    }

    protected boolean action____expression_list__expression_list__COMMA__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_list__expression_list__COMMA__assignment_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		expr_list = (List)(semantic_stack.peek());
			expr_list.add(expr);
		}

        return true;
    }

    protected boolean action____expression_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____expression_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____expression_statement__expression__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_statement__expression__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression			expr		= (Expression)(semantic_stack.pop());
			semantic_stack.push(new ExpressionStatement(expr));
		}

        return true;
    }

    protected boolean action____expression_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____expression_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____expression_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____for_init_statement__expression_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____for_init_statement__expression_statement() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____for_init_statement__simple_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____for_init_statement__simple_declaration() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Declaration	decl = (Declaration)(semantic_stack.pop());
			semantic_stack.push(new DeclarationStatement(decl));
        }

        return true;
    }

    protected boolean action____for_init_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____for_init_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____for_init_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_definition__function_prefix__compound_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_definition__function_prefix__compound_statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
			//compound statement will be created when processing compound_statement
		}
		else
		{
			CompoundStatement	cmpd_stmt	= (CompoundStatement)(semantic_stack.pop());
			Declarator			ftn_prefix	= (Declarator)(semantic_stack.pop());

			semantic_stack.push(new Procedure(ftn_prefix, cmpd_stmt));
		}

        return true;
    }

    protected boolean action____function_definition__function_prefix__ctor_initializer__compound_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_definition__function_prefix__ctor_initializer__compound_statement() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_definition__function_prefix__ctor_initializer__compound_statement() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_definition__function_prefix__function_try_block(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_definition__function_prefix__function_try_block() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_definition__function_prefix__function_try_block() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_definition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_definition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_definition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_prefix__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_prefix__declarator() NodeID = " + node.getNodeID());
        }

		//nothing to do here, already a declarator
        return true;
    }

    protected boolean action____function_prefix__decl_specifier_seq__declarator_head(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_prefix__decl_specifier_seq__declarator_head() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_seq	= (List)(semantic_stack.pop());
			LinkedList	param_list	= null;

			semantic_stack.push(new Declarator(spec_seq, decl, param_list));
		}

        return true;
    }

    protected boolean action____function_prefix__decl_specifier_seq__attributes__declarator_head(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_prefix__decl_specifier_seq__attributes__declarator_head() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_prefix__decl_specifier_seq__attributes__declarator_head() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_prefix__decl_specifier_seq__declarator_head__declarator_tail_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_prefix__decl_specifier_seq__declarator_head__declarator_tail_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_prefix__decl_specifier_seq__declarator_head__declarator_tail_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_prefix__decl_specifier_seq__attributes__declarator_head__declarator_tail_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_prefix__decl_specifier_seq__attributes__declarator_head__declarator_tail_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_prefix__decl_specifier_seq__attributes__declarator_head__declarator_tail_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_prefix__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_prefix__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____function_prefix__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_specifier__INLINE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_specifier__INLINE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.INLINE);
        return true;
    }

    protected boolean action____function_specifier__VIRTUAL(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_specifier__VIRTUAL() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.VIRTUAL);
        return true;
    }

    protected boolean action____function_specifier__EXPLICIT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_specifier__EXPLICIT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.EXPLICIT);
        return true;
    }

    protected boolean action____function_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_try_block__TRY__compound_statement__handler_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_try_block__TRY__compound_statement__handler_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_try_block__TRY__compound_statement__handler_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_try_block__TRY__ctor_initializer__compound_statement__handler_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_try_block__TRY__ctor_initializer__compound_statement__handler_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_try_block__TRY__ctor_initializer__compound_statement__handler_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____function_try_block__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____function_try_block__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____function_try_block__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____handler__CATCH__LEFT_PARENTHESIS__exception_declaration__RIGHT_PARENTHESIS__compound_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____handler__CATCH__LEFT_PARENTHESIS__exception_declaration__RIGHT_PARENTHESIS__compound_statement() NodeID = " + node.getNodeID());
        }

        errorExit("action____handler__CATCH__LEFT_PARENTHESIS__exception_declaration__RIGHT_PARENTHESIS__compound_statement() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____handler__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____handler__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____handler__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____handler_seq__handler(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____handler_seq__handler() NodeID = " + node.getNodeID());
        }

        errorExit("action____handler_seq__handler() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____handler_seq__handler_seq__handler(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____handler_seq__handler_seq__handler() NodeID = " + node.getNodeID());
        }

        errorExit("action____handler_seq__handler_seq__handler() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____handler_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____handler_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____handler_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____id_expression__unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____id_expression__unqualified_id() NodeID = " + node.getNodeID());
        }

		//nothing to do, there's an id_expr on top of the stack already.
        return true;
    }

    protected boolean action____id_expression__qualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____id_expression__qualified_id() NodeID = " + node.getNodeID());
        }

		//there should be an Id on top of the stack, do nothing.
        return true;
    }

    protected boolean action____id_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____id_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____id_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____inclusive_or_expression__exclusive_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____inclusive_or_expression__exclusive_or_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
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

        errorExit("action____inclusive_or_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____init_declarator__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator__declarator() NodeID = " + node.getNodeID());
        }
		
		//nothing here
        return true;
    }

    protected boolean action____init_declarator__declarator__initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator__declarator__initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer	init = (Initializer)(semantic_stack.pop());
			Declarator	decl = (Declarator)(semantic_stack.peek());
			decl.setInitializer(init);
		}

        return true;
    }

    protected boolean action____init_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____init_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
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
			Declarator	decl = (Declarator)(semantic_stack.pop());
			List		list = (List)(semantic_stack.peek());
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

        errorExit("action____init_declarator_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____initializer__EQUAL_SIGN__initializer_clause(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__EQUAL_SIGN__initializer_clause() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	init_clause = (LinkedList)(semantic_stack.pop());
			Initializer	init		= null;

			if (init_clause.size() == 1)
			{
				Expression	assignment_expr = (Expression)(init_clause.getFirst());
				init = new Initializer(assignment_expr);
			}
			else
			{
				init = new Initializer(init_clause);
			}

			semantic_stack.push(init);
		}
		
        return true;
    }

    protected boolean action____initializer__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	expr_list = (List)(semantic_stack.pop());
			semantic_stack.push(new Initializer(expr_list));
		}

        return true;
    }

    protected boolean action____initializer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____initializer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____initializer_clause__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_clause__assignment_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	assign_expr = (Expression)(semantic_stack.pop());
			LinkedList	expr_list	= new LinkedList();
			expr_list.add(assign_expr);
		}

        return true;
    }

    protected boolean action____initializer_clause__LEFT_BRACE__initializer_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_clause__LEFT_BRACE__initializer_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing here, it's already a list
		}

        return true;
    }

    protected boolean action____initializer_clause__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_clause__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing here, it's already a list
		}

        return true;
    }

    protected boolean action____initializer_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new LinkedList());
        return true;
    }

    protected boolean action____initializer_clause__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_clause__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____initializer_clause__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____initializer_list__initializer_clause(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_list__initializer_clause() NodeID = " + node.getNodeID());
        }

		//nothing here, just let the list stay on the stack
        return true;
    }

    protected boolean action____initializer_list__initializer_list__COMMA__initializer_clause(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_list__initializer_list__COMMA__initializer_clause() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//need to merge these two lists
			List		init_clause = (List)(semantic_stack.pop());
			LinkedList	init_list	= (LinkedList)(semantic_stack.peek());

			//now traverse init_clause, and add items one by one into init_list
			ListIterator	clause_iter = init_clause.listIterator(0);
			while (clause_iter.hasNext() == true)
			{
				init_list.add(clause_iter.next());
			}
		}

        return true;
    }

    protected boolean action____initializer_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____initializer_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____initializer_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____iteration_statement__WHILE__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__WHILE__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	stmt	= (Statement)(semantic_stack.pop());
			Expression	cond	= (Expression)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("while statement: while()\nlabel: stmt\n is not supported");
			}

			semantic_stack.push(new WhileLoop(cond, stmt));
		}

        return true;
    }

    protected boolean action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	cond = (Expression)(semantic_stack.pop());
			Statement	stmt = (Statement)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("do statement: do\nlabel: stmt\n is not supported");
			}

			semantic_stack.push(new DoLoop(stmt, cond));
		}

        return true;
    }

    protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__SEMICOLON__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__SEMICOLON__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	body_stmt	= (Statement)(semantic_stack.pop());
			Statement	init_stmt	= (Statement)(semantic_stack.pop());
			Expression	step_expr	= null;
			Expression	cond		= null;

			semantic_stack.push(new ForLoop(init_stmt, cond, step_expr, body_stmt));
		}
		
        return true;
    }

    protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__SEMICOLON__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__SEMICOLON__expression__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	body_stmt = (Statement)(semantic_stack.pop());
			Expression	step_expr = (Expression)(semantic_stack.pop());
			Statement	init_stmt = (Statement)(semantic_stack.pop());
			Expression	cond	  = null;

			semantic_stack.push(new ForLoop(init_stmt, cond, step_expr, body_stmt));
		}		

        return true;
    }

    protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__condition__SEMICOLON__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__condition__SEMICOLON__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	body_stmt	= (Statement)(semantic_stack.pop());
			Expression	step_expr	= null;
			Expression	cond		= (Expression)(semantic_stack.pop());
			Statement	init_stmt	= (Statement)(semantic_stack.pop());
			
			semantic_stack.push(new ForLoop(init_stmt, cond, step_expr, body_stmt));
		}		

        return true;
    }

    protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__condition__SEMICOLON__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__FOR__LEFT_PARENTHESIS__for_init_statement__condition__SEMICOLON__expression__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	body_stmt	= (Statement)(semantic_stack.pop());
			Expression	step_expr	= (Expression)(semantic_stack.pop());
			Expression	cond		= (Expression)(semantic_stack.pop());
			Statement	init_stmt	= (Statement)(semantic_stack.pop());
			
			semantic_stack.push(new ForLoop(init_stmt, cond, step_expr, body_stmt));
		}		

		return true;
    }

    protected boolean action____iteration_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____iteration_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____iteration_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
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

    protected boolean action____jump_statement__CONTINUE__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__CONTINUE__SEMICOLON() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(new ContinueStatement());
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

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new ReturnStatement(expr));
		}

        return true;
    }

    protected boolean action____jump_statement__GOTO__IDENTIFIER__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__GOTO__IDENTIFIER__SEMICOLON() NodeID = " + node.getNodeID());
        }

		GeneralSyntaxNode	child		= (GeneralSyntaxNode)(node.getChild(1));
		String				id_name		= new String(child.getInfoString());

		semantic_stack.push(new GotoStatement(new Identifier(id_name)));
        return true;
    }

    protected boolean action____jump_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____jump_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

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
			String			name	= ((GeneralSyntaxNode)(node.getChild(0))).getInfoString();
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
        }        

        return true;
    }

    protected boolean action____labeled_statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____labeled_statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____labeled_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____linkage_specification__EXTERN__STRING_LITERAL__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____linkage_specification__EXTERN__STRING_LITERAL__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____linkage_specification__EXTERN__STRING_LITERAL__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____linkage_specification__EXTERN__STRING_LITERAL__LEFT_BRACE__declaration_seq__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____linkage_specification__EXTERN__STRING_LITERAL__LEFT_BRACE__declaration_seq__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____linkage_specification__EXTERN__STRING_LITERAL__LEFT_BRACE__declaration_seq__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____linkage_specification__EXTERN__STRING_LITERAL__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____linkage_specification__EXTERN__STRING_LITERAL__declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____linkage_specification__EXTERN__STRING_LITERAL__declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____linkage_specification__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____linkage_specification__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____linkage_specification__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____literal__CONSTANT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____literal__CONSTANT() NodeID = " + node.getNodeID());
        }

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
        String	int_exp		= const1 + "|" + const2 + "|" + const3;
		String	float_exp	= const5 + "|" + const6 + "|" + const7;

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

    protected boolean action____literal__STRING_LITERAL_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____literal__STRING_LITERAL_seq() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			LinkedList	str_lit_seq = (LinkedList)(semantic_stack.pop());
			String		result = "";
			ListIterator	iter = str_lit_seq.listIterator(0);
			while (iter.hasNext() == true)
			{
				result += (String)(iter.next());
			}
			semantic_stack.push(new StringLiteral(result));
        }

        return true;
    }

    protected boolean action____literal__boolean_literal(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____literal__boolean_literal() NodeID = " + node.getNodeID());
        }

		//nothing to do, there should be a literal on top of the stack already.
        return true;
    }

    protected boolean action____literal__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____literal__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____literal__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____logical_and_expression__inclusive_or_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_and_expression__inclusive_or_expression() NodeID = " + node.getNodeID());
        }

        //nothing here
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

        errorExit("action____logical_and_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____logical_or_expression__logical_and_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____logical_or_expression__logical_and_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
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

        errorExit("action____logical_or_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer__mem_initializer_id__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer__mem_initializer_id__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer__mem_initializer_id__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer__mem_initializer_id__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer__mem_initializer_id__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer__mem_initializer_id__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer_id__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer_id__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer_id__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer_id__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer_id__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer_id__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer_list__mem_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer_list__mem_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer_list__mem_initializer() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer_list__mem_initializer_list__COMMA__mem_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer_list__mem_initializer_list__COMMA__mem_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer_list__mem_initializer_list__COMMA__mem_initializer() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____mem_initializer_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____mem_initializer_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____mem_initializer_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	spec_seq = (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_seq));
		}

        return true;
    }

    protected boolean action____member_declaration__decl_specifier_seq__attributes(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__attributes() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__attributes() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__member_declarator_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__member_declarator_list() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Specifier	spec		= null;
			List		decl_list	= (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec, decl_list));
		}

        return true;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_seq	= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__member_declarator_list_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__member_declarator_list_tail() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	declarator_list	= (LinkedList)(semantic_stack.pop());
			Declarator	decl			= (Declarator)(semantic_stack.pop());
			List		spec_list		= (List)(semantic_stack.pop());

			declarator_list.addFirst(decl);
			semantic_stack.push(new VariableDeclaration(spec_list, declarator_list));
		}

        return true;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__constant_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__constant_initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer		init		= (Initializer)(semantic_stack.pop());
			Declarator		decl		= (Declarator)(semantic_stack.pop());
			decl.setInitializer(init);
			List			spec_seq	= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__constant_initializer__member_declarator_list_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__constant_initializer__member_declarator_list_tail() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	decl_list_tail	= (LinkedList)(semantic_stack.pop());
			
			Initializer	const_init		= (Initializer)(semantic_stack.pop());
			Declarator	decl			= (Declarator)(semantic_stack.pop());
			decl.setInitializer(const_init);
			decl_list_tail.addFirst(decl);
			
			List		spec_list		= (List)(semantic_stack.pop());
			
			semantic_stack.push(new VariableDeclaration(spec_list, decl_list_tail));
		}

        return true;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__member_declarator_list_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__member_declarator_list_tail() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__member_declarator_list_tail() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__constant_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__constant_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__constant_initializer() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__constant_initializer__member_declarator_list_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__constant_initializer__member_declarator_list_tail() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__constant_initializer__member_declarator_list_tail() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__COLON__constant_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__COLON__constant_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__COLON__constant_expression__member_declarator_list_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__COLON__constant_expression__member_declarator_list_tail() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__COLON__constant_expression__member_declarator_list_tail() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__IDENTIFIER__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__IDENTIFIER__COLON__constant_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__IDENTIFIER__COLON__constant_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__decl_specifier_seq__IDENTIFIER__COLON__constant_expression__member_declarator_list_tail(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__decl_specifier_seq__IDENTIFIER__COLON__constant_expression__member_declarator_list_tail() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__decl_specifier_seq__IDENTIFIER__COLON__constant_expression__member_declarator_list_tail() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__scoped_unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__scoped_unqualified_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			QualifiedID		q_id	=	(QualifiedID)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(new Declarator(q_id)));
		}

        return true;
    }

    protected boolean action____member_declaration__SCOPE__scoped_unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__SCOPE__scoped_unqualified_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration__SCOPE__scoped_unqualified_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____member_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration_alt__function_definition(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration_alt__function_definition() NodeID = " + node.getNodeID());
        }

		//nothing to do here, Procedure is a Declaration already
        return true;
    }

    protected boolean action____member_declaration_alt__using_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration_alt__using_declaration() NodeID = " + node.getNodeID());
        }

		//nothing to do here, using declaration is a declaration already
        return true;
    }

    protected boolean action____member_declaration_alt__template_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration_alt__template_declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration_alt__template_declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declaration_alt__access_specifier__COLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration_alt__access_specifier__COLON() NodeID = " + node.getNodeID());
        }

		//nothing to do here, AccessLevel is a Declaration
        return true;
    }

    protected boolean action____member_declaration_alt__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declaration_alt__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declaration_alt__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declarator__declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator__declarator() NodeID = " + node.getNodeID());
        }

		//nothing to do here
        return true;
    }

    protected boolean action____member_declarator__declarator__constant_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator__declarator__constant_initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer	init = (Initializer)(semantic_stack.pop());
			Declarator	decl = (Declarator)(semantic_stack.peek());
			decl.setInitializer(init);
		}

        return true;
    }

    protected boolean action____member_declarator__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator__COLON__constant_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declarator__COLON__constant_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declarator__IDENTIFIER__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator__IDENTIFIER__COLON__constant_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declarator__IDENTIFIER__COLON__constant_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declarator_list__member_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator_list__member_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			LinkedList	decl_list	= new LinkedList();
			decl_list.add(decl);
			semantic_stack.push(decl_list);
		}

        return true;
    }

    protected boolean action____member_declarator_list__member_declarator_list__COMMA__member_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator_list__member_declarator_list__COMMA__member_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			LinkedList	decl_list	= (LinkedList)(semantic_stack.peek());
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____member_declarator_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declarator_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declarator_list_tail__COMMA__member_declarator_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator_list_tail__COMMA__member_declarator_list() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declarator_list_tail__COMMA__member_declarator_list() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_declarator_list_tail__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_declarator_list_tail__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_declarator_list_tail__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__SEMICOLON() NodeID = " + node.getNodeID());
        }

		//add an empty list onto the stack
		semantic_stack.push(new LinkedList());
        return true;
    }

    protected boolean action____member_specification__member_declaration__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_declaration__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			LinkedList	decl_list	= (LinkedList)(semantic_stack.pop());
			decl_list.add(decl);
			semantic_stack.push(decl_list);
		}

        return true;
    }

    protected boolean action____member_specification__member_declaration_alt(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_declaration_alt() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__member_declaration_alt() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__EXTENSION__member_declaration__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__EXTENSION__member_declaration__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__EXTENSION__member_declaration__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__EXTENSION__member_declaration_alt(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__EXTENSION__member_declaration_alt() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__EXTENSION__member_declaration_alt() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__member_specification__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_specification__SEMICOLON() NodeID = " + node.getNodeID());
        }

		//nothing to do here
        return true;
    }

    protected boolean action____member_specification__member_specification__member_declaration__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_specification__member_declaration__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration	decl		= (Declaration)(semantic_stack.pop());
			LinkedList	decl_list	= (LinkedList)(semantic_stack.peek());
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____member_specification__member_specification__member_declaration_alt(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_specification__member_declaration_alt() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__member_specification__member_declaration_alt() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__member_specification__EXTENSION__member_declaration__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_specification__EXTENSION__member_declaration__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__member_specification__EXTENSION__member_declaration__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__member_specification__EXTENSION__member_declaration_alt(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__member_specification__EXTENSION__member_declaration_alt() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__member_specification__EXTENSION__member_declaration_alt() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____member_specification__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____member_specification__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____member_specification__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____multiplicative_expression__pm_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__pm_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//do nothing here
		}

        return true;
    }

    protected boolean action____multiplicative_expression__multiplicative_expression__ASTERISK__pm_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__multiplicative_expression__ASTERISK__pm_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.MULTIPLY, right));			
		}

        return true;
    }

    protected boolean action____multiplicative_expression__multiplicative_expression__SLASH__pm_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__multiplicative_expression__SLASH__pm_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression right = (Expression)semantic_stack.pop();
			Expression left  = (Expression)semantic_stack.pop();

			semantic_stack.push(new BinaryExpression(left, BinaryOperator.DIVIDE, right));			
		}

        return true;
    }

    protected boolean action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__pm_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__pm_expression() NodeID = " + node.getNodeID());
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

//------- You need to handle ambiguity here -------//
        errorExit("action____multiplicative_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____namespace_alias_definition__NAMESPACE__IDENTIFIER__EQUAL_SIGN__qualified_namespace_specifier__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_alias_definition__NAMESPACE__IDENTIFIER__EQUAL_SIGN__qualified_namespace_specifier__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			IDExpression	original_name	= (IDExpression)(semantic_stack.pop());
			String			new_id_name		= ((GeneralSyntaxNode)(node.getChild(1))).getInfoString().trim();

			semantic_stack.push(new NamespaceAlias(new Identifier(new_id_name), original_name));
		}
		
		return true;
    }

    protected boolean action____namespace_alias_definition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_alias_definition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____namespace_alias_definition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____namespace_definition__NAMESPACE__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_definition__NAMESPACE__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		//Namespace is treated like a declaration
        semantic_stack.push(new Namespace());	//anonymous namespace

		return false;
    }

    protected boolean action____namespace_definition__NAMESPACE__LEFT_BRACE__declaration_seq__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_definition__NAMESPACE__LEFT_BRACE__declaration_seq__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	decl_seq = (LinkedList)(semantic_stack.pop());
			//create an anonymous namespace
			Namespace	name_space = new Namespace();
			
			ListIterator	decl_iter = decl_seq.listIterator(0);
			while (decl_iter.hasNext() == true)
			{
				name_space.addDeclaration((Declaration)(decl_iter.next()));
			}

			semantic_stack.push(name_space);
		}

        return true;
    }

    protected boolean action____namespace_definition__NAMESPACE__IDENTIFIER__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_definition__NAMESPACE__IDENTIFIER__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		String		id_name		= ((GeneralSyntaxNode)(node.getChild(1))).getInfoString().trim();
		Namespace	name_space	= new Namespace(new Identifier(id_name));

		semantic_stack.push(name_space);
        return true;
    }

    protected boolean action____namespace_definition__NAMESPACE__IDENTIFIER__LEFT_BRACE__declaration_seq__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_definition__NAMESPACE__IDENTIFIER__LEFT_BRACE__declaration_seq__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }
		
		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	decl_seq	= (LinkedList)(semantic_stack.pop());
			String		id_name		= ((GeneralSyntaxNode)(node.getChild(1))).getInfoString().trim();
			Namespace	name_space	= new Namespace(new Identifier(id_name));			

			ListIterator	decl_iter	= decl_seq.listIterator(0);
			while (decl_iter.hasNext() == true)
			{
				name_space.addDeclaration((Declaration)(decl_iter.next()));
			}

			semantic_stack.push(name_space);
		}

        return true;
    }

    protected boolean action____namespace_definition__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____namespace_definition__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____namespace_definition__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____nested_name_specifier__class_name__SCOPE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____nested_name_specifier__class_name__SCOPE() NodeID = " + node.getNodeID());
        }

        errorExit("action____nested_name_specifier__class_name__SCOPE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____nested_name_specifier__class_name__SCOPE__nested_name_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____nested_name_specifier__class_name__SCOPE__nested_name_specifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____nested_name_specifier__class_name__SCOPE__nested_name_specifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____nested_name_specifier__class_name__SCOPE__TEMPLATE__nested_name_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____nested_name_specifier__class_name__SCOPE__TEMPLATE__nested_name_specifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____nested_name_specifier__class_name__SCOPE__TEMPLATE__nested_name_specifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____nested_name_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____nested_name_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____nested_name_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_declarator__ptr_operator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_declarator__ptr_operator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing here, since ptr_operator is already a specifier_seq
		}

        return true;
    }

    protected boolean action____new_declarator__ptr_operator__new_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_declarator__ptr_operator__new_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	new_decl	= (LinkedList)(semantic_stack.pop());
			LinkedList	ptr_op		= (LinkedList)(semantic_stack.peek());
			ptr_op.addAll(new_decl);
		}

        return true;
    }

    protected boolean action____new_declarator__direct_new_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_declarator__direct_new_declarator() NodeID = " + node.getNodeID());
        }

		//now construct an array specifier here
		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList		indices_expr	= (LinkedList)(semantic_stack.pop());
			ArraySpecifier	array_spec		= new ArraySpecifier(indices_expr);
			LinkedList		spec_list		= new LinkedList();
			spec_list.add(array_spec);
			semantic_stack.push(spec_list);
		}

        return true;
    }

    protected boolean action____new_declarator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_declarator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_declarator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__NEW__new_type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__new_type_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	spec_list = (List)(semantic_stack.pop());
			semantic_stack.push(new NewExpression(spec_list));
		}

        return true;
    }

    protected boolean action____new_expression__NEW__new_type_id__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__new_type_id__new_initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer	new_init	= (Initializer)(semantic_stack.pop());
			List		spec_list	= (List)(semantic_stack.pop());
			
			semantic_stack.push(new NewExpression(spec_list, new_init));
		}

		return true;
    }

    protected boolean action____new_expression__NEW__new_placement__new_type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__new_placement__new_type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__NEW__new_placement__new_type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__NEW__new_placement__new_type_id__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__new_placement__new_type_id__new_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__NEW__new_placement__new_type_id__new_initializer() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__SCOPE__NEW__new_type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__new_type_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	type_seq = (List)(semantic_stack.pop());
			NewExpression	new_expr = new NewExpression(type_seq);
			new_expr.setGlobal();
			semantic_stack.push(new_expr);
		}

        return true;
    }

    protected boolean action____new_expression__SCOPE__NEW__new_type_id__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__new_type_id__new_initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer	init		= (Initializer)(semantic_stack.pop());
			List		type_seq	= (List)(semantic_stack.pop());
			NewExpression	new_expr	= new NewExpression(type_seq, init);
			new_expr.setGlobal();
			semantic_stack.push(new_expr);
		}

        return true;
    }

    protected boolean action____new_expression__SCOPE__NEW__new_placement__new_type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__new_placement__new_type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__SCOPE__NEW__new_placement__new_type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__SCOPE__NEW__new_placement__new_type_id__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__new_placement__new_type_id__new_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__SCOPE__NEW__new_placement__new_type_id__new_initializer() hasn't been implemented yet.");
        return false;
    }

	//type_id is a list of specifiers
    protected boolean action____new_expression__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	type_id	= (List)(semantic_stack.pop());
			semantic_stack.push(new NewExpression(type_id));
		}

        return true;
    }

    protected boolean action____new_expression__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer init	= (Initializer)(semantic_stack.pop());
			List		type_id	= (List)(semantic_stack.pop());
			semantic_stack.push(new NewExpression(type_id, init));
		}

        return true;
    }

    protected boolean action____new_expression__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__SCOPE__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List			type_id		= (List)(semantic_stack.pop());
			NewExpression	new_expr	= new NewExpression(type_id);
			new_expr.setGlobal();
			semantic_stack.push(new_expr);
		}

        return true;
    }

    protected boolean action____new_expression__SCOPE__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Initializer		init		= (Initializer)(semantic_stack.pop());
			List			type_id		= (List)(semantic_stack.pop());
			NewExpression	new_expr	= (NewExpression)(semantic_stack.pop());
			new_expr.setGlobal();
			semantic_stack.push(new_expr);
		}

        return true;
    }

    protected boolean action____new_expression__SCOPE__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__SCOPE__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__SCOPE__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__SCOPE__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__SCOPE__NEW__new_placement__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS__new_initializer() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_initializer__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_initializer__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		Expression	expr = null;
		semantic_stack.push(new Initializer(expr));
        return true;
    }

    protected boolean action____new_initializer__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_initializer__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	expr_list	= (List)(semantic_stack.pop());
			semantic_stack.push(new Initializer(expr_list));
		}

        return true;
    }

    protected boolean action____new_initializer__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_initializer__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_initializer__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_placement__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_placement__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		//nothing here, since it's already a list of expressions
        return true;
    }

    protected boolean action____new_placement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_placement__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_placement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____new_type_id__type_specifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_type_id__type_specifier_seq() NodeID = " + node.getNodeID());
        }

		//nothing here, since there is a spec_seq on top of the stack
        return true;
    }

    protected boolean action____new_type_id__type_specifier_seq__new_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_type_id__type_specifier_seq__new_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//need to merge the two lists here
			LinkedList	new_decl		= (LinkedList)(semantic_stack.pop());
			LinkedList	type_spec_seq	= (LinkedList)(semantic_stack.peek());
			type_spec_seq.addAll(new_decl);
		}

        return true;
    }

    protected boolean action____new_type_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____new_type_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____new_type_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____operator___NEW(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___NEW() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.NEW);
        return true;
    }

    protected boolean action____operator___DELETE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___DELETE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.DELETE);
        return true;
    }

    protected boolean action____operator___NEW__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___NEW__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.NEW_ARRAY);
        return true;
    }

    protected boolean action____operator___DELETE__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___DELETE__LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.DELETE_ARRAY);
        return true;
    }

    protected boolean action____operator___PLUS_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___PLUS_SIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.ADD);
        return true;
    }

    protected boolean action____operator___MINUS_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___MINUS_SIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.SUBTRACT);
        return true;
    }

    protected boolean action____operator___ASTERISK(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___ASTERISK() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.MULTIPLY);
        return true;
    }

    protected boolean action____operator___SLASH(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___SLASH() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.DIVIDE);
        return true;
    }

    protected boolean action____operator___PERCENT_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___PERCENT_SIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.MODULUS);
        return true;
    }

    protected boolean action____operator___CARET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___CARET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.BITWISE_EXCLUSIVE_OR);
        return true;
    }

    protected boolean action____operator___AMPERSAND(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___AMPERSAND() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.BITWISE_AND);
        return true;
    }

    protected boolean action____operator___VERTICAL_BAR(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___VERTICAL_BAR() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.BITWISE_INCLUSIVE_OR);
        return true;
    }

    protected boolean action____operator___TILDE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___TILDE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.BITWISE_COMPLEMENT);
        return true;
    }

    protected boolean action____operator___BANG(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___BANG() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.LOGICAL_NEGATION);
        return true;
    }

    protected boolean action____operator___EQUAL_SIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___EQUAL_SIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.ASSIGN);
        return true;
    }

    protected boolean action____operator___LEFT_ANGLE_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___LEFT_ANGLE_BRACKET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.COMPARE_LT);
        return true;
    }

    protected boolean action____operator___RIGHT_ANGLE_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___RIGHT_ANGLE_BRACKET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.COMPARE_GT);
        return true;
    }

    protected boolean action____operator___ADD_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___ADD_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.ADD_ASSIGN);
        return true;
    }

    protected boolean action____operator___SUB_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___SUB_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.SUB_ASSIGN);
        return true;
    }

    protected boolean action____operator___MUL_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___MUL_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.MUL_ASSIGN);
        return true;
    }

    protected boolean action____operator___DIV_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___DIV_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.DIV_ASSIGN);
        return true;
    }

    protected boolean action____operator___MOD_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___MOD_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.MOD_ASSIGN);
        return true;
    }

    protected boolean action____operator___XOR_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___XOR_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.XOR_ASSIGN);
        return true;
    }

    protected boolean action____operator___AND_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___AND_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.AND_ASSIGN);
        return true;
    }

    protected boolean action____operator___OR_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___OR_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.OR_ASSIGN);
        return true;
    }

    protected boolean action____operator___LEFT_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___LEFT_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.LEFT_OP);
        return true;
    }

    protected boolean action____operator___RIGHT_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___RIGHT_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.RIGHT_OP);
        return true;
    }

    protected boolean action____operator___RIGHT_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___RIGHT_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.RIGHT_ASSIGN);
        return true;
    }

    protected boolean action____operator___LEFT_ASSIGN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___LEFT_ASSIGN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.LEFT_ASSIGN);
        return true;
    }

    protected boolean action____operator___EQ_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___EQ_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.EQ_OP);
        return true;
    }

    protected boolean action____operator___NE_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___NE_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.NE_OP);
        return true;
    }

    protected boolean action____operator___LE_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___LE_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.LE_OP);
        return true;
    }

    protected boolean action____operator___GE_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___GE_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.GE_OP);
        return true;
    }

    protected boolean action____operator___AND_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___AND_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.AND_OP);
        return true;
    }

    protected boolean action____operator___OR_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___OR_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.OR_OP);
        return true;
    }

    protected boolean action____operator___INC_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___INC_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.INC_OP);
        return true;
    }

    protected boolean action____operator___DEC_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___DEC_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.DEC_OP);
        return true;
    }

    protected boolean action____operator___COMMA(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___COMMA() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.COMMA);
        return true;
    }

    protected boolean action____operator___PTR_MEMBER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___PTR_MEMBER() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.MEMBER_ACCESS); //PTR_MEMBER);
        return true;
    }

    protected boolean action____operator___PTR_OP(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___PTR_OP() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.PTR_OP);
        return true;
    }

    protected boolean action____operator___LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.PARENTHESES);
        return true;
    }

    protected boolean action____operator___LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___LEFT_BRACKET__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(OperatorID.BRACKETS);
        return true;
    }

    protected boolean action____operator___default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator___default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____operator___default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____operator_function_id__OPERATOR__operator_(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator_function_id__OPERATOR__operator_() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing, keyword "operator" is already included in the OperatorID object
		}

        return true;
    }

    protected boolean action____operator_function_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____operator_function_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____operator_function_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__declarator_head(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__declarator_head() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_seq	= (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__declarator_head__EQUAL_SIGN__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__declarator_head__EQUAL_SIGN__assignment_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	assignment_expr = (Expression)(semantic_stack.pop());
			Initializer	init			= new Initializer(assignment_expr);

			Declarator	decl			= (Declarator)(semantic_stack.pop());
			decl.setInitializer(init);

			List		spec_seq		= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__EQUAL_SIGN__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__EQUAL_SIGN__assignment_expression() NodeID = " + node.getNodeID());
        }

		errorExit("parameter_declaration -> decl_spec decl_head decl_tail = assignment, NoldID = " + node.getNodeID());
		return false;
/*
		if (__action_status__ == __ACTION_AFTER__)
		{
		}

        return true;
*/    
	}

    protected boolean action____parameter_declaration__decl_specifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List	spec_seq = (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_seq));
		}

        return true;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__abstract_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator	decl		= (Declarator)(semantic_stack.pop());
			List		spec_seq	= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__EQUAL_SIGN__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__EQUAL_SIGN__assignment_expression() NodeID = " + node.getNodeID());
        }
		
		errorExit("action____parameter_declaration__decl_specifier_seq__EQUAL_SIGN__assignment_expression hasn't been implemented yet.");
		return false;
    }

    protected boolean action____parameter_declaration__decl_specifier_seq__abstract_declarator__EQUAL_SIGN__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__decl_specifier_seq__abstract_declarator__EQUAL_SIGN__assignment_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	assignment_expr = (Expression)(semantic_stack.pop());
			Initializer	init			= new Initializer(assignment_expr);

			Declarator	decl			= (Declarator)(semantic_stack.pop());
			decl.setInitializer(init);

			List		spec_seq		= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____parameter_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____parameter_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration_clause__empty(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_clause__empty() NodeID = " + node.getNodeID());
        }

		//just need an empty list here
		semantic_stack.push(new LinkedList());
        return true;
    }

    protected boolean action____parameter_declaration_clause__parameter_declaration_list(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_clause__parameter_declaration_list() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____parameter_declaration_clause__ELLIPSIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_clause__ELLIPSIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_declaration_clause__ELLIPSIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration_clause__parameter_declaration_list__ELLIPSIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_clause__parameter_declaration_list__ELLIPSIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_declaration_clause__parameter_declaration_list__ELLIPSIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration_clause__parameter_declaration_list__COMMA__ELLIPSIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_clause__parameter_declaration_list__COMMA__ELLIPSIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_declaration_clause__parameter_declaration_list__COMMA__ELLIPSIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration_clause__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_clause__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____parameter_declaration_clause__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____parameter_declaration_list__parameter_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_list__parameter_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration		decl		= (Declaration)(semantic_stack.pop());
			LinkedList		decl_list	= new LinkedList();
			decl_list.add(decl);
			semantic_stack.push(decl_list);
		}

        return true;
    }

    protected boolean action____parameter_declaration_list__parameter_declaration_list__COMMA__parameter_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_list__parameter_declaration_list__COMMA__parameter_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration		decl		= (Declaration)(semantic_stack.pop());
			LinkedList		decl_list	= (LinkedList)(semantic_stack.peek());
			decl_list.add(decl);
		}

        return true;
    }

    protected boolean action____parameter_declaration_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____parameter_declaration_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____parameter_declaration_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____pm_expression__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pm_expression__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing to do here
		}

        return true;
    }

    protected boolean action____pm_expression__pm_expression__DOT_MEMBER__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pm_expression__pm_expression__DOT_MEMBER__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	cast_expr	= (Expression)(semantic_stack.pop());
			Expression	pm_expr		= (Expression)(semantic_stack.pop());

			semantic_stack.push(new AccessExpression(pm_expr, AccessOperator.MEMBER_ACCESS, cast_expr));
		}

        return true;
    }

    protected boolean action____pm_expression__pm_expression__PTR_MEMBER__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pm_expression__pm_expression__PTR_MEMBER__cast_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	cast_expr	= (Expression)(semantic_stack.pop());
			Expression	pm_expr		= (Expression)(semantic_stack.pop());

			semantic_stack.push(new AccessExpression(pm_expr, AccessOperator.POINTER_ACCESS, cast_expr));
		}

        return true;
    }

    protected boolean action____pm_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____pm_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____pm_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__primary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__primary_expression() NodeID = " + node.getNodeID());
        }

		//there should be an expr on stack already, do nothing
        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr_index = (Expression)(semantic_stack.pop());
			Expression	expr_array = (Expression)(semantic_stack.pop());
			semantic_stack.push(new ArrayAccess(expr_array, expr_index));
		}

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression ftn_expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new FunctionCall(ftn_expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			List		param_list	= (List)(semantic_stack.pop());
			Expression	ftn_expr	= (Expression)(semantic_stack.pop());
			
			semantic_stack.push(new FunctionCall(ftn_expr, param_list));
		}

        return true;
    }

    protected boolean action____postfix_expression__simple_type_specifier__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__simple_type_specifier__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__simple_type_specifier__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__simple_type_specifier__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__simple_type_specifier__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__simple_type_specifier__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__TYPENAME__scoped_class_name__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__TYPENAME__scoped_class_name__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__TYPENAME__scoped_class_name__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__TYPENAME__scoped_class_name__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__TYPENAME__scoped_class_name__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__TYPENAME__scoped_class_name__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__TYPENAME__SCOPE__scoped_class_name__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__TYPENAME__SCOPE__scoped_class_name__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__TYPENAME__SCOPE__scoped_class_name__LEFT_PARENTHESIS__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__TYPENAME__SCOPE__scoped_class_name__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__TYPENAME__SCOPE__scoped_class_name__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__TYPENAME__SCOPE__scoped_class_name__LEFT_PARENTHESIS__expression_list__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__DOT__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__DOT__id_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			IDExpression	id_expr = (IDExpression)(semantic_stack.pop());
			Expression		left_expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new AccessExpression(left_expr, AccessOperator.MEMBER_ACCESS, id_expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__DOT__TEMPLATE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__DOT__TEMPLATE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__postfix_expression__DOT__TEMPLATE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__DOT__SCOPE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__DOT__SCOPE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__postfix_expression__DOT__SCOPE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__DOT__TEMPLATE__SCOPE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__DOT__TEMPLATE__SCOPE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__postfix_expression__DOT__TEMPLATE__SCOPE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__PTR_OP__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__PTR_OP__id_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			IDExpression	id_expr		= (IDExpression)(semantic_stack.pop());
			Expression		left_expr	= (Expression)(semantic_stack.pop());

			semantic_stack.push(new AccessExpression(left_expr, AccessOperator.POINTER_ACCESS, id_expr));
		}
		
        return true;
    }

    protected boolean action____postfix_expression__postfix_expression__PTR_OP__TEMPLATE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__PTR_OP__TEMPLATE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__postfix_expression__PTR_OP__TEMPLATE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__PTR_OP__SCOPE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__PTR_OP__SCOPE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__postfix_expression__PTR_OP__SCOPE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__PTR_OP__TEMPLATE__SCOPE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__PTR_OP__TEMPLATE__SCOPE__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__postfix_expression__PTR_OP__TEMPLATE__SCOPE__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__postfix_expression__INC_OP(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__postfix_expression__INC_OP() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new UnaryExpression(UnaryOperator.POST_INCREMENT, expr));
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
			Expression expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new UnaryExpression(UnaryOperator.POST_DECREMENT, expr));
		}		

        return true;
    }

    protected boolean action____postfix_expression__DYNAMIC_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__DYNAMIC_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		type_id_list = (List)(semantic_stack.pop());

			semantic_stack.push(new Typecast(Typecast.DYNAMIC, type_id_list, expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__STATIC_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__STATIC_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		type_id_list = (List)(semantic_stack.pop());

			semantic_stack.push(new Typecast(Typecast.STATIC, type_id_list, expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__REINTERPRET_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__REINTERPRET_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		type_id_list = (List)(semantic_stack.pop());

			semantic_stack.push(new Typecast(Typecast.REINTERPRET, type_id_list, expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__CONST_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__CONST_CAST__LEFT_ANGLE_BRACKET__type_id__RIGHT_ANGLE_BRACKET__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			List		type_id_list = (List)(semantic_stack.pop());

			semantic_stack.push(new Typecast(Typecast.CONST, type_id_list, expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__TYPEID__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__TYPEID__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Expression	expr = (Expression)(semantic_stack.pop());
			String		str_typeid	= new String(((GeneralSyntaxNode)(node.getChild(0))).getInfoString());
			LinkedList	spec_list = new LinkedList();
			spec_list.add(new UserSpecifier(new Identifier(str_typeid)));
			semantic_stack.push(new Typecast(spec_list, expr));
		}

        return true;
    }

    protected boolean action____postfix_expression__TYPEID__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__TYPEID__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__TYPEID__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__VA_ARG__LEFT_PARENTHESIS__expression__COMMA__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__VA_ARG__LEFT_PARENTHESIS__expression__COMMA__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____postfix_expression__VA_ARG__LEFT_PARENTHESIS__expression__COMMA__type_id__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____postfix_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____postfix_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____postfix_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____primary_expression__literal(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__literal() NodeID = " + node.getNodeID());
        }

		//nothing to do, there's already an expression (Literal) on the stack.
        return true;
    }

    protected boolean action____primary_expression__THIS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__THIS() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(Identifier.THIS);
        return true;
    }

    protected boolean action____primary_expression__SCOPE__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__SCOPE__id_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			IDExpression	id_expr = (IDExpression)(semantic_stack.peek());
			id_expr.setGlobal();
		}

        return true;
    }

    protected boolean action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

		//nothing to do, an expr on top of the stack already.
        return true;
    }

    protected boolean action____primary_expression__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__id_expression() NodeID = " + node.getNodeID());
        }

		//nothing to do, there should be an id-expr on top of the stack already.
        return true;
    }

    protected boolean action____primary_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____primary_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____primary_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ptr_operator__ASTERISK(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__ASTERISK() NodeID = " + node.getNodeID());
        }

		LinkedList	ptr_list	= new LinkedList();
		ptr_list.add(PointerSpecifier.UNQUALIFIED);
		semantic_stack.push(ptr_list);

		return true;
    }

    protected boolean action____ptr_operator__ASTERISK__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__ASTERISK__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	qualifier_seq = (LinkedList)(semantic_stack.peek());
			qualifier_seq.addFirst(PointerSpecifier.UNQUALIFIED);
		}

        return true;
    }

    protected boolean action____ptr_operator__AMPERSAND(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__AMPERSAND() NodeID = " + node.getNodeID());
        }

		LinkedList	ptr_list	= new LinkedList();
		ptr_list.add(Specifier.REFERENCE);
		semantic_stack.push(ptr_list);

		return true;
    }

    protected boolean action____ptr_operator__nested_name_specifier__ASTERISK(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__nested_name_specifier__ASTERISK() NodeID = " + node.getNodeID());
        }

        errorExit("action____ptr_operator__nested_name_specifier__ASTERISK() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ptr_operator__nested_name_specifier__ASTERISK__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__nested_name_specifier__ASTERISK__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____ptr_operator__nested_name_specifier__ASTERISK__cv_qualifier_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ptr_operator__SCOPE__nested_name_specifier__ASTERISK(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__SCOPE__nested_name_specifier__ASTERISK() NodeID = " + node.getNodeID());
        }

        errorExit("action____ptr_operator__SCOPE__nested_name_specifier__ASTERISK() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ptr_operator__SCOPE__nested_name_specifier__ASTERISK__cv_qualifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__SCOPE__nested_name_specifier__ASTERISK__cv_qualifier_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____ptr_operator__SCOPE__nested_name_specifier__ASTERISK__cv_qualifier_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____ptr_operator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____ptr_operator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____ptr_operator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____qualified_id__scoped_unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____qualified_id__scoped_unqualified_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			IDExpression	id_expr = (IDExpression)(semantic_stack.pop());
			LinkedList		id_expr_list = new LinkedList();
			id_expr_list.add(id_expr);
			semantic_stack.push(new QualifiedID(id_expr_list));
		}

        return true;
    }

    protected boolean action____qualified_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____qualified_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____qualified_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____qualified_namespace_specifier__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____qualified_namespace_specifier__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____qualified_namespace_specifier__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____qualified_namespace_specifier__SCOPE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____qualified_namespace_specifier__SCOPE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____qualified_namespace_specifier__SCOPE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____qualified_namespace_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____qualified_namespace_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____qualified_namespace_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____relational_expression__shift_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____relational_expression__shift_expression() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//nothing here
		}

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

        errorExit("action____relational_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_class_name__class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_class_name__class_name() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Identifier	id		= (Identifier)(semantic_stack.pop());
			LinkedList	id_list = new LinkedList();
			id_list.add(id);
			semantic_stack.push(new QualifiedID(id_list));
		}

        return true;
    }

    protected boolean action____scoped_class_name__class_name__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_class_name__class_name__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			QualifiedID		q_id	= (QualifiedID)(semantic_stack.pop());
			Identifier		id		= (Identifier)(semantic_stack.pop());

			LinkedList	id_list = new LinkedList();
			id_list.add(id);
			id_list.addAll(q_id.getIDExpressionList());

			semantic_stack.push(new QualifiedID(id_list));
		}

        return true;
    }

    protected boolean action____scoped_class_name__class_name__SCOPE__TEMPLATE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_class_name__class_name__SCOPE__TEMPLATE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_class_name__class_name__SCOPE__TEMPLATE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_class_name__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_class_name__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_class_name__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_id__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_id__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        String id_name = ((GeneralSyntaxNode)(node.getChild(0))).getInfoString().trim();
		LinkedList	id_list = new LinkedList();
		id_list.add(new Identifier(id_name));
		semantic_stack.push(new QualifiedID(id_list));

        return true;
    }

    protected boolean action____scoped_id__class_name__SCOPE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_id__class_name__SCOPE__scoped_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			QualifiedID	q_id	= (QualifiedID)(semantic_stack.pop());
			Identifier	id_name	= (Identifier)(semantic_stack.pop());

			LinkedList	id_list	= new LinkedList();
			id_list.add(id_name);
			id_list.addAll(q_id.getIDExpressionList());
			semantic_stack.push(new QualifiedID(id_list));
		}

        return true;
    }

    protected boolean action____scoped_id__class_name__SCOPE__TEMPLATE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_id__class_name__SCOPE__TEMPLATE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_id__class_name__SCOPE__TEMPLATE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_unqualified_id__class_name__SCOPE__unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_unqualified_id__class_name__SCOPE__unqualified_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			IDExpression	uq_id		= (IDExpression)(semantic_stack.pop());
			Identifier		class_name	= (Identifier)(semantic_stack.pop());

			LinkedList		id_list = new LinkedList();
			id_list.add(class_name);
			id_list.add(uq_id);
			semantic_stack.push(id_list);
		}

        return true;
    }

    protected boolean action____scoped_unqualified_id__class_name__SCOPE__TEMPLATE__unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_unqualified_id__class_name__SCOPE__TEMPLATE__unqualified_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_unqualified_id__class_name__SCOPE__TEMPLATE__unqualified_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_unqualified_id__class_name__SCOPE__scoped_unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_unqualified_id__class_name__SCOPE__scoped_unqualified_id() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			QualifiedID	q_id		= (QualifiedID)(semantic_stack.pop());
			Identifier	class_name	= (Identifier)(semantic_stack.pop());

			LinkedList	id_list = new LinkedList();
			id_list.add(class_name);
			id_list.addAll(q_id.getIDExpressionList());

			semantic_stack.push(id_list);
		}

        return true;
    }

    protected boolean action____scoped_unqualified_id__class_name__SCOPE__TEMPLATE__scoped_unqualified_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_unqualified_id__class_name__SCOPE__TEMPLATE__scoped_unqualified_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_unqualified_id__class_name__SCOPE__TEMPLATE__scoped_unqualified_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____scoped_unqualified_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____scoped_unqualified_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____scoped_unqualified_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____selection_statement__IF__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__IF__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	stmt = (Statement)(semantic_stack.pop());
			Expression	cond = (Expression)(semantic_stack.pop());

			if (stmt instanceof TW_StatementList)
			{
				errorExit("if_statement: if ()\nlabel: stmt\nis not supported !");
			}

			semantic_stack.push(new IfStatement(cond, stmt));
		}

        return true;
    }

    protected boolean action____selection_statement__IF__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement__ELSE__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__IF__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement__ELSE__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Statement	else_stmt	= (Statement)(semantic_stack.pop());
			Statement	then_stmt	= (Statement)(semantic_stack.pop());
			Expression	cond		= (Expression)(semantic_stack.pop());

			if (then_stmt instanceof TW_StatementList)
			{
				errorExit("if_statement: if ()\nlabel: stmt\nis not supported !");
			}
			if (else_stmt instanceof TW_StatementList)
			{
				errorExit("if_statement: if ()\n    ...\nelse\nlabel: stmt\n is not supported !");
			}

			semantic_stack.push(new IfStatement(cond, then_stmt, else_stmt));
		}

        return true;
    }

    protected boolean action____selection_statement__SWITCH__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____selection_statement__SWITCH__LEFT_PARENTHESIS__condition__RIGHT_PARENTHESIS__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			CompoundStatement	cmpd_stmt	= (CompoundStatement)(semantic_stack.pop());
			Expression			cond		= (Expression)(semantic_stack.pop());

			SwitchStatement	sw_stmt = new SwitchStatement(cond);
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

        errorExit("action____selection_statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____shift_expression__additive_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____shift_expression__additive_expression() NodeID = " + node.getNodeID());
        }
		
		//nothing here
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

        errorExit("action____shift_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__SEMICOLON(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__SEMICOLON() NodeID = " + node.getNodeID());
        }

		//empty, nothing to do here
        return true;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__SEMICOLON() NodeID = " + node.getNodeID());
        }

		List	spec_list = (List)(semantic_stack.pop());
		semantic_stack.push(new VariableDeclaration(new Declarator(new Identifier(""))));

        return true;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__attributes__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__attributes__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__attributes__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			LinkedList	spec_list = null;
			List		decl_list = (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_list, decl_list));
		}

        return true;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__SEMICOLON() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Declarator	decl = (Declarator)(semantic_stack.pop());
			List		spec_seq = (List)(semantic_stack.pop());
			semantic_stack.push(new VariableDeclaration(spec_seq, decl));
		}

        return true;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__attributes__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__attributes__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__attributes__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__COMMA__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__COMMA__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			LinkedList	init_decl_list	= (LinkedList)(semantic_stack.pop());
			Declarator	decl			= (Declarator)(semantic_stack.pop());
			init_decl_list.addFirst(decl);
			List		spec_seq		= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration(spec_seq, init_decl_list));
		}

        return true;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__attributes__COMMA__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__attributes__COMMA__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__attributes__COMMA__init_declarator_list__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__SEMICOLON() NodeID = " + node.getNodeID());
        }

		errorExit("in progress, simple_decl\n");
/*
        if (__action_status__ == __ACTION_AFTER__)
        {
			List		decl_tail_seq	= (List)(semantic_stack.pop());
			Declarator	decl			= (Declarator)(semantic_stack.pop());
			List		decl_spec_seq	= (List)(semantic_stack.pop());

			semantic_stack.push(new VariableDeclaration());
		}
*/
		return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__attributes__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__attributes__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__attributes__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__COMMA__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__COMMA__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__COMMA__init_declarator_list__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__attributes__COMMA__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__attributes__COMMA__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__attributes__COMMA__init_declarator_list__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__initializer__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__initializer__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__initializer__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__initializer__COMMA__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__initializer__COMMA__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__initializer__COMMA__init_declarator_list__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__initializer__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__initializer__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__initializer__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__initializer__COMMA__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__initializer__COMMA__init_declarator_list__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_declaration__decl_specifier_seq__declarator_head__declarator_tail_seq__initializer__COMMA__init_declarator_list__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____simple_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_type_specifier__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_type_specifier__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_type_specifier__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_type_specifier__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_type_specifier__CHAR(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__CHAR() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.CHAR);
        return true;
    }

    protected boolean action____simple_type_specifier__WCHAR_T(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__WCHAR_T() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.WCHAR_T);
        return true;
    }

    protected boolean action____simple_type_specifier__CBOOL(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__CBOOL() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.BOOL);
        return true;
    }

    protected boolean action____simple_type_specifier__SHORT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__SHORT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.SHORT);
        return true;
    }

    protected boolean action____simple_type_specifier__INT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__INT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.INT);
        return true;
    }

    protected boolean action____simple_type_specifier__LONG(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__LONG() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.LONG);
        return true;
    }

    protected boolean action____simple_type_specifier__SIGNED(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__SIGNED() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.SIGNED);
        return true;
    }

    protected boolean action____simple_type_specifier__UNSIGNED(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__UNSIGNED() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.UNSIGNED);
        return true;
    }

    protected boolean action____simple_type_specifier__FLOAT(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__FLOAT() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.FLOAT);
        return true;
    }

    protected boolean action____simple_type_specifier__DOUBLE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__DOUBLE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.DOUBLE);
        return true;
    }

    protected boolean action____simple_type_specifier__VOID(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__VOID() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.VOID);
        return true;
    }

    protected boolean action____simple_type_specifier__COMPLEX(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__COMPLEX() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_type_specifier__COMPLEX() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_type_specifier__TYPEOF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__TYPEOF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_type_specifier__TYPEOF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_type_specifier__TYPEOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__TYPEOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____simple_type_specifier__TYPEOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____simple_type_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____simple_type_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____simple_type_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____statement__labeled_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__labeled_statement() NodeID = " + node.getNodeID());
        }

        //nothing here, should be a statement on stack already
        return true;
    }

    protected boolean action____statement__expression_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__expression_statement() NodeID = " + node.getNodeID());
        }

        //nothing here
        return true;
    }

    protected boolean action____statement__compound_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__compound_statement() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____statement__selection_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__selection_statement() NodeID = " + node.getNodeID());
        }

        //nothing here
        return true;
    }

    protected boolean action____statement__iteration_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__iteration_statement() NodeID = " + node.getNodeID());
        }

        //nothing here
        return true;
    }

    protected boolean action____statement__jump_statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__jump_statement() NodeID = " + node.getNodeID());
        }

        //nothing here
        return true;
    }

    protected boolean action____statement__block_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__block_declaration() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declaration	decl = (Declaration)(semantic_stack.pop());
			semantic_stack.push(new DeclarationStatement(decl));
		}

        return true;
    }

    protected boolean action____statement__try_block(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__try_block() NodeID = " + node.getNodeID());
        }

		//nothing here
		//try block is already a statement instance

        return true;
    }

    protected boolean action____statement__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____statement__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____statement_seq__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement_seq__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
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

    protected boolean action____statement_seq__statement_seq__statement(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement_seq__statement_seq__statement() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			//System.out.println(" ---- before popping the stmt_list -> stmt_list stmt ----");
			//semantic_stack_display();
			//pick up the statement on the semantic stack and add it into the underlying compound statement
			Statement			stmt		= (Statement)(semantic_stack.pop());
			//add into the compound statement
			CompoundStatement	cmpd_stmt	= (CompoundStatement)(symbol_table_stack.peek());

			if (stmt instanceof TW_StatementList)
			{
				LinkedList		stmt_list	= ((TW_StatementList)stmt).getStatementList();
				ListIterator	iter		= stmt_list.listIterator(0);

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

    protected boolean action____statement_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____statement_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____statement_seq__default_semantic_action() hasn't been implemented yet.");
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

    protected boolean action____storage_class_specifier__EXTERN(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__EXTERN() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.EXTERN);
        return true;
    }

    protected boolean action____storage_class_specifier__MUTABLE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____storage_class_specifier__MUTABLE() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(Specifier.MUTABLE);
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

    protected boolean action____template_argument__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_argument__assignment_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_argument__assignment_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_argument__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_argument__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_argument__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_argument__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_argument__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____template_argument__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_argument_list__template_argument(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_argument_list__template_argument() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_argument_list__template_argument() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_argument_list__template_argument_list__COMMA__template_argument(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_argument_list__template_argument_list__COMMA__template_argument() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_argument_list__template_argument_list__COMMA__template_argument() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_argument_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_argument_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_argument_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_declaration__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_declaration__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_declaration__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_declaration__EXPORT__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_declaration__EXPORT__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_declaration__EXPORT__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_parameter__type_parameter(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_parameter__type_parameter() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_parameter__type_parameter() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_parameter__parameter_declaration(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_parameter__parameter_declaration() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_parameter__parameter_declaration() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_parameter__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_parameter__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____template_parameter__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_parameter_list__template_parameter(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_parameter_list__template_parameter() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_parameter_list__template_parameter() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_parameter_list__template_parameter_list__COMMA__template_parameter(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_parameter_list__template_parameter_list__COMMA__template_parameter() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_parameter_list__template_parameter_list__COMMA__template_parameter() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____template_parameter_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____template_parameter_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____template_parameter_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____throw_expression__THROW(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____throw_expression__THROW() NodeID = " + node.getNodeID());
        }

        errorExit("action____throw_expression__THROW() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____throw_expression__THROW__assignment_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____throw_expression__THROW__assignment_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____throw_expression__THROW__assignment_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____throw_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____throw_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____throw_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____translation_unit__declaration_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____translation_unit__declaration_seq() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_BEFORE__)
		{
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
		}
		else
		{
			LinkedList	decl_seq = (LinkedList)(semantic_stack.pop());
			TranslationUnit	tran_unit = (TranslationUnit)(symbol_table_stack.peek());

			//add the declarations into the translation unit one by one
			ListIterator	decl_iter = decl_seq.listIterator(0);
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
			System.out.println(TU_filename + " is empty.");
		}

        return true;
    }

    protected boolean action____translation_unit__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____translation_unit__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____translation_unit__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____try_block__TRY__compound_statement__handler_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____try_block__TRY__compound_statement__handler_seq() NodeID = " + node.getNodeID());
        }

        errorExit("action____try_block__TRY__compound_statement__handler_seq() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____try_block__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____try_block__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____try_block__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_id__type_specifier_seq(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_id__type_specifier_seq() NodeID = " + node.getNodeID());
        }

		//nothing to do here, there should be a list of specs on the stack already
        return true;
    }

    protected boolean action____type_id__type_specifier_seq__abstract_declarator(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_id__type_specifier_seq__abstract_declarator() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Declarator		decl = (Declarator)(semantic_stack.pop());
			UserSpecifier	spec = new UserSpecifier(decl.getSymbol());
			List			spec_seq = (List)(semantic_stack.peek());
			spec_seq.add(spec);
		}

        return true;
    }

    protected boolean action____type_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_id_list__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_id_list__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_id_list__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_id_list__type_id_list__COMMA__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_id_list__type_id_list__COMMA__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_id_list__type_id_list__COMMA__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_id_list__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_id_list__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_id_list__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__CLASS(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__CLASS() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__CLASS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__CLASS__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__CLASS__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__CLASS__IDENTIFIER() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__CLASS__EQUAL_SIGN__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__CLASS__EQUAL_SIGN__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__CLASS__EQUAL_SIGN__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__CLASS__IDENTIFIER__EQUAL_SIGN__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__CLASS__IDENTIFIER__EQUAL_SIGN__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__CLASS__IDENTIFIER__EQUAL_SIGN__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TYPENAME(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TYPENAME() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TYPENAME() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TYPENAME__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TYPENAME__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TYPENAME__IDENTIFIER() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TYPENAME__EQUAL_SIGN__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TYPENAME__EQUAL_SIGN__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TYPENAME__EQUAL_SIGN__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TYPENAME__IDENTIFIER__EQUAL_SIGN__type_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TYPENAME__IDENTIFIER__EQUAL_SIGN__type_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TYPENAME__IDENTIFIER__EQUAL_SIGN__type_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__IDENTIFIER(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__IDENTIFIER() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__IDENTIFIER() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__EQUAL_SIGN__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__EQUAL_SIGN__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__EQUAL_SIGN__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__IDENTIFIER__EQUAL_SIGN__id_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__IDENTIFIER__EQUAL_SIGN__id_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__TEMPLATE__LEFT_ANGLE_BRACKET__template_parameter_list__RIGHT_ANGLE_BRACKET__CLASS__IDENTIFIER__EQUAL_SIGN__id_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_parameter__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_parameter__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_parameter__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__simple_type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__simple_type_specifier() NodeID = " + node.getNodeID());
        }

		//nothing to do
        return true;
    }

    protected boolean action____type_specifier__CLASS__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		//this is weird, but let's take it as in the grammar

		//create a unique name first
		String	unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
		String	id_name		= unique_name.trim();

		ClassDeclaration	class_decl		= new ClassDeclaration(ClassDeclaration.CLASS, new Identifier(id_name));
		CompoundStatement	outer_cmpstmt	= (CompoundStatement)(symbol_table_stack.peek());

		outer_cmpstmt.addDeclaration(class_decl);

		semantic_stack.push(new UserSpecifier(new Identifier("class " + id_name)));
        return true;
    }

    protected boolean action____type_specifier__CLASS__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			String	unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
			String	id_name		= unique_name.trim();

			LinkedList		decl_list		= (LinkedList)(semantic_stack.pop());
			ListIterator	class_decl_iter	= decl_list.listIterator(0);

			ClassDeclaration	class_decl	= new ClassDeclaration(ClassDeclaration.CLASS, new Identifier(id_name));
			while (class_decl_iter.hasNext() == true)
			{
				class_decl.addDeclaration((Declaration)(class_decl_iter.next()));
			}

			CompoundStatement	outer_cmpstmt	= (CompoundStatement)(symbol_table_stack.peek());
			outer_cmpstmt.addDeclaration(class_decl);

			semantic_stack.push(new UserSpecifier(new Identifier("class " + id_name)));
		}

        return true;
    }

    protected boolean action____type_specifier__CLASS__base_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__base_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__base_clause__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__CLASS__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__CLASS__scoped_class_name__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__scoped_class_name__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__scoped_class_name__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__CLASS__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__CLASS__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__CLASS__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		String	unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
		String	id_name		= unique_name.trim();

		ClassDeclaration	struct_decl = new ClassDeclaration(ClassDeclaration.STRUCT, new Identifier(id_name));

		CompoundStatement	outer_cmpstmt	= (CompoundStatement)(symbol_table_stack.peek());
		outer_cmpstmt.addDeclaration(struct_decl);

		semantic_stack.push(new UserSpecifier(new Identifier("struct " + id_name)));
        return true;
    }

    protected boolean action____type_specifier__STRUCT__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			String	unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
			String	id_name		= unique_name.trim();

			LinkedList		decl_list		= (LinkedList)(semantic_stack.pop());
			ListIterator	struct_decl_iter	= decl_list.listIterator(0);

			ClassDeclaration	struct_decl	= new ClassDeclaration(ClassDeclaration.STRUCT, new Identifier(id_name));
			while (struct_decl_iter.hasNext() == true)
			{
				struct_decl.addDeclaration((Declaration)(struct_decl_iter.next()));
			}

			CompoundStatement	outer_cmpstmt	= (CompoundStatement)(symbol_table_stack.peek());
			outer_cmpstmt.addDeclaration(struct_decl);

			semantic_stack.push(new UserSpecifier(new Identifier("struct " + id_name)));
		}

        return true;
    }

    protected boolean action____type_specifier__STRUCT__base_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__base_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__base_clause__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__scoped_class_name__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__scoped_class_name__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__scoped_class_name__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		String	unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
		String	id_name		= unique_name.trim();

		ClassDeclaration	union_decl = new ClassDeclaration(ClassDeclaration.UNION, new Identifier(id_name));

		CompoundStatement	outer_cmpstmt	= (CompoundStatement)(symbol_table_stack.peek());
		outer_cmpstmt.addDeclaration(union_decl);

		semantic_stack.push(new UserSpecifier(new Identifier("union " + id_name)));
        return true;
    }

    protected boolean action____type_specifier__UNION__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			String	unique_name = TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
			String	id_name		= unique_name.trim();

			LinkedList		decl_list		= (LinkedList)(semantic_stack.pop());
			ListIterator	union_decl_iter	= decl_list.listIterator(0);

			ClassDeclaration	union_decl	= new ClassDeclaration(ClassDeclaration.UNION, new Identifier(id_name));
			while (union_decl_iter.hasNext() == true)
			{
				union_decl.addDeclaration((Declaration)(union_decl_iter.next()));
			}

			CompoundStatement	outer_cmpstmt	= (CompoundStatement)(symbol_table_stack.peek());
			outer_cmpstmt.addDeclaration(union_decl);

			semantic_stack.push(new UserSpecifier(new Identifier("union " + id_name)));
		}

        return true;
	}

    protected boolean action____type_specifier__UNION__base_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__base_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__base_clause__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__scoped_class_name__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__scoped_class_name__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__scoped_class_name__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__scoped_class_name__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__scoped_class_name__base_clause__LEFT_BRACE__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__scoped_class_name__base_clause__LEFT_BRACE__member_specification__RIGHT_BRACE() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		String		unique_name	= TU_filename.replace('.', '_') + "_" + Integer.toString(node.getNodeID());
		String		id_name		= unique_name;
		LinkedList	enum_list	= null;

		SymbolTable	sym_table	= (SymbolTable)(symbol_table_stack.peek());
		sym_table.addDeclaration(new cetus.hir.Enumeration(new Identifier(id_name), enum_list));
			
		semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));

		return true;
    }

    protected boolean action____type_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
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

    protected boolean action____type_specifier__ENUM__IDENTIFIER__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__LEFT_BRACE__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

		LinkedList	enum_list	= null;
		//need to make sure it's chile #1
		String		id_name		= (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();

		SymbolTable	sym_table	= (SymbolTable)(symbol_table_stack.peek());
		sym_table.addDeclaration(new cetus.hir.Enumeration(new Identifier(id_name), enum_list));
			
		semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));

        return true;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			List		enum_list	= (List)(semantic_stack.pop());
			//need to make sure it's chile #1
			String		id_name		= (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();

			SymbolTable	sym_table	= (SymbolTable)(symbol_table_stack.peek());
			sym_table.addDeclaration(new cetus.hir.Enumeration(new Identifier(id_name), enum_list));
			
			semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));
        }

        return true;
    }

    protected boolean action____type_specifier__CLASS__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__CLASS__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__CLASS__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__CLASS__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__STRUCT__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__STRUCT__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__STRUCT__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__UNION__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__UNION__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__UNION__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER() NodeID = " + node.getNodeID());
        }

		String	id_name	= (new String(((GeneralSyntaxNode)(node.getChild(1))).getInfoString())).trim();
		semantic_stack.push(new UserSpecifier(new Identifier("enum " + id_name)));

        return true;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER__SCOPE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__SCOPE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__ENUM__IDENTIFIER__SCOPE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET__SCOPE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET__SCOPE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET__SCOPE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET__SCOPE__TEMPLATE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET__SCOPE__TEMPLATE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__RIGHT_ANGLE_BRACKET__SCOPE__TEMPLATE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET__SCOPE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET__SCOPE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET__SCOPE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET__SCOPE__TEMPLATE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET__SCOPE__TEMPLATE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__ENUM__IDENTIFIER__BEGIN_TEMPLATE__template_argument_list__RIGHT_ANGLE_BRACKET__SCOPE__TEMPLATE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__ENUM__SCOPE__scoped_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__ENUM__SCOPE__scoped_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__ENUM__SCOPE__scoped_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__TYPENAME__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__TYPENAME__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__TYPENAME__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__TYPENAME__SCOPE__scoped_class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__TYPENAME__SCOPE__scoped_class_name() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__TYPENAME__SCOPE__scoped_class_name() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__cv_qualifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__cv_qualifier() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__cv_qualifier() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____type_specifier_seq__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier_seq__type_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Specifier	spec = (Specifier)(semantic_stack.pop());
			LinkedList	spec_list = new LinkedList();
			spec_list.add(spec);
			semantic_stack.push(spec_list);
		}

        return true;
    }

    protected boolean action____type_specifier_seq__type_specifier_seq__type_specifier(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier_seq__type_specifier_seq__type_specifier() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Specifier	spec		= (Specifier)(semantic_stack.pop());
			LinkedList	spec_list	= (LinkedList)(semantic_stack.peek());
			spec_list.add(spec);
		}

        return true;
    }

    protected boolean action____type_specifier_seq__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____type_specifier_seq__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____type_specifier_seq__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__postfix_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__postfix_expression() NodeID = " + node.getNodeID());
        }

		//nothing here
        return true;
    }

    protected boolean action____unary_expression__INC_OP__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__INC_OP__cast_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new UnaryExpression(UnaryOperator.PRE_INCREMENT, expr));
        }

		return true;
    }

    protected boolean action____unary_expression__DEC_OP__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__DEC_OP__cast_expression() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new UnaryExpression(UnaryOperator.PRE_DECREMENT, expr));
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
			Expression		expr	= (Expression)(semantic_stack.pop());
			UnaryOperator	op		= (UnaryOperator)(semantic_stack.pop());

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
			Expression	expr = (Expression)(semantic_stack.pop());
			semantic_stack.push(new SizeofExpression(expr));
        }

        return true;
    }

    protected boolean action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        if (__action_status__ == __ACTION_AFTER__)
        {
			List	type_list = (List)(semantic_stack.pop());

			semantic_stack.push(new SizeofExpression(type_list));
		}		

        return true;
    }

    protected boolean action____unary_expression__new_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__new_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__new_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__delete_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__delete_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__delete_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__ALIGNOF__unary_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__ALIGNOF__unary_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__ALIGNOF__unary_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__ALIGNOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__ALIGNOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__ALIGNOF__LEFT_PARENTHESIS__type_id__RIGHT_PARENTHESIS() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__REALPART__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__REALPART__cast_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__REALPART__cast_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__IMAGPART__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__IMAGPART__cast_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__IMAGPART__cast_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__EXTENSION__cast_expression(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__EXTENSION__cast_expression() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_expression__EXTENSION__cast_expression() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unary_expression__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_expression__default_semantic_action() NodeID = " + node.getNodeID());
        }

//------- You need to handle ambiguity here -------//
        errorExit("action____unary_expression__default_semantic_action() hasn't been implemented yet.");
        return false;
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

    protected boolean action____unary_operator__AMPERSAND(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__AMPERSAND() NodeID = " + node.getNodeID());
        }

		semantic_stack.push(UnaryOperator.ADDRESS_OF);
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

    protected boolean action____unary_operator__BANG(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__BANG() NodeID = " + node.getNodeID());
        }

        semantic_stack.push(UnaryOperator.LOGICAL_NEGATION);
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

    protected boolean action____unary_operator__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unary_operator__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____unary_operator__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unqualified_id__class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unqualified_id__class_name() NodeID = " + node.getNodeID());
        }

		//class_name should end up with an identifier on the stack. do nothing
        return true;
    }

    protected boolean action____unqualified_id__operator_function_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unqualified_id__operator_function_id() NodeID = " + node.getNodeID());
        }

		//nothing here, operator_id is also an id
        return true;
    }

    protected boolean action____unqualified_id__conversion_function_id(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unqualified_id__conversion_function_id() NodeID = " + node.getNodeID());
        }

        errorExit("action____unqualified_id__conversion_function_id() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____unqualified_id__TILDE__class_name(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unqualified_id__TILDE__class_name() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			Identifier	id = (Identifier)(semantic_stack.pop());
			semantic_stack.push(new DestructorID(id.toString()));
		}

		return true;
    }

    protected boolean action____unqualified_id__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____unqualified_id__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____unqualified_id__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_declaration__USING__scoped_unqualified_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_declaration__USING__scoped_unqualified_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

		if (__action_status__ == __ACTION_AFTER__)
		{
			QualifiedID	qualified_id = (QualifiedID)(semantic_stack.pop());
			errorExit("\nusing_declaration: the corresponding IR classes are not ready yet. NodeID = " + node.getNodeID() + "\n");
			//semantic_stack.push();
		}

        return true;
    }

    protected boolean action____using_declaration__USING__TYPENAME__scoped_unqualified_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_declaration__USING__TYPENAME__scoped_unqualified_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_declaration__USING__TYPENAME__scoped_unqualified_id__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_declaration__USING__SCOPE__scoped_unqualified_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_declaration__USING__SCOPE__scoped_unqualified_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_declaration__USING__SCOPE__scoped_unqualified_id__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_declaration__USING__TYPENAME__SCOPE__scoped_unqualified_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_declaration__USING__TYPENAME__SCOPE__scoped_unqualified_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_declaration__USING__TYPENAME__SCOPE__scoped_unqualified_id__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_declaration__USING__SCOPE__unqualified_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_declaration__USING__SCOPE__unqualified_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_declaration__USING__SCOPE__unqualified_id__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_declaration__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_declaration__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_declaration__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_directive__USING__NAMESPACE__scoped_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_directive__USING__NAMESPACE__scoped_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_directive__USING__NAMESPACE__scoped_id__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_directive__USING__NAMESPACE__SCOPE__scoped_id__SEMICOLON(GeneralSyntaxNode node, int __action_status__)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_directive__USING__NAMESPACE__SCOPE__scoped_id__SEMICOLON() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_directive__USING__NAMESPACE__SCOPE__scoped_id__SEMICOLON() hasn't been implemented yet.");
        return false;
    }

    protected boolean action____using_directive__default_semantic_action(GeneralSyntaxNode node)
    {
        if (debug_display == true)
        {
            System.out.println("Hit action____using_directive__default_semantic_action() NodeID = " + node.getNodeID());
        }

        errorExit("action____using_directive__default_semantic_action() hasn't been implemented yet.");
        return false;
    }

}


