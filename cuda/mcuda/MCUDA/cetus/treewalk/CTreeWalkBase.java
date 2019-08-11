
package cetus.treewalk;

import java.lang.*;
import java.util.*;

abstract public class CTreeWalkBase implements CTypeEnum
{
    protected static final int __ACTION_BEFORE__ = 0;
    protected static final int __ACTION_AFTER__ = 1;

    public CTreeWalkBase()
    {
    }

    public GeneralSyntaxNode run(GeneralSyntaxNode tree_root)
    {
        System.out.println("Start Walking the tree to solve ambiguities:");
        process_translation_unit(tree_root);

        return tree_root;
    }

    protected void errorExit(String _error_msg)
    {
        throw new TreeWalkException(_error_msg);
        //System.out.println(_error_msg);
        //System.exit(1);
    }

    protected boolean process_abstract_declarator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __pointer__)
            {
                boolean action_result_before = action____abstract_declarator__pointer(node, __ACTION_BEFORE__);

                boolean result_1 = process_pointer(child_1);

                boolean action_result_after = action____abstract_declarator__pointer(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [abstract_declarator] --> [pointer] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __direct_abstract_declarator__)
            {
                boolean action_result_before = action____abstract_declarator__direct_abstract_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_abstract_declarator(child_1);

                boolean action_result_after = action____abstract_declarator__direct_abstract_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [abstract_declarator] --> [direct_abstract_declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __pointer__
               &&child_2_type == __direct_abstract_declarator__)
            {
                boolean action_result_before = action____abstract_declarator__pointer__direct_abstract_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_pointer(child_1);
                boolean result_2 = process_direct_abstract_declarator(child_2);

                boolean action_result_after = action____abstract_declarator__pointer__direct_abstract_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [abstract_declarator] --> [pointer direct_abstract_declarator] returns false.");
                    return false;
                }
            }
        }

        return action____abstract_declarator__default_semantic_action(node);
    }

    protected boolean process_additive_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __multiplicative_expression__)
            {
                boolean action_result_before = action____additive_expression__multiplicative_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_multiplicative_expression(child_1);

                boolean action_result_after = action____additive_expression__multiplicative_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [additive_expression] --> [multiplicative_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __additive_expression__
               &&child_2_type == __PLUS_SIGN__
               &&child_3_type == __multiplicative_expression__)
            {
                boolean action_result_before = action____additive_expression__additive_expression__PLUS_SIGN__multiplicative_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_additive_expression(child_1);
                boolean result_3 = process_multiplicative_expression(child_3);

                boolean action_result_after = action____additive_expression__additive_expression__PLUS_SIGN__multiplicative_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [additive_expression] --> [additive_expression '+' multiplicative_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __additive_expression__
               &&child_2_type == __MINUS_SIGN__
               &&child_3_type == __multiplicative_expression__)
            {
                boolean action_result_before = action____additive_expression__additive_expression__MINUS_SIGN__multiplicative_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_additive_expression(child_1);
                boolean result_3 = process_multiplicative_expression(child_3);

                boolean action_result_after = action____additive_expression__additive_expression__MINUS_SIGN__multiplicative_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [additive_expression] --> [additive_expression '-' multiplicative_expression] returns false.");
                    return false;
                }
            }
        }

        return action____additive_expression__default_semantic_action(node);
    }

    protected boolean process_and_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __equality_expression__)
            {
                boolean action_result_before = action____and_expression__equality_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_equality_expression(child_1);

                boolean action_result_after = action____and_expression__equality_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [and_expression] --> [equality_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __and_expression__
               &&child_2_type == __AMPERSAND__
               &&child_3_type == __equality_expression__)
            {
                boolean action_result_before = action____and_expression__and_expression__AMPERSAND__equality_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_and_expression(child_1);
                boolean result_3 = process_equality_expression(child_3);

                boolean action_result_after = action____and_expression__and_expression__AMPERSAND__equality_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [and_expression] --> [and_expression '&' equality_expression] returns false.");
                    return false;
                }
            }
        }

        return action____and_expression__default_semantic_action(node);
    }

    protected boolean process_argument_expression_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __assignment_expression__)
            {
                boolean action_result_before = action____argument_expression_list__assignment_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_assignment_expression(child_1);

                boolean action_result_after = action____argument_expression_list__assignment_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [argument_expression_list] --> [assignment_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __argument_expression_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __assignment_expression__)
            {
                boolean action_result_before = action____argument_expression_list__argument_expression_list__COMMA__assignment_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_argument_expression_list(child_1);
                boolean result_3 = process_assignment_expression(child_3);

                boolean action_result_after = action____argument_expression_list__argument_expression_list__COMMA__assignment_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [argument_expression_list] --> [argument_expression_list ',' assignment_expression] returns false.");
                    return false;
                }
            }
        }

        return action____argument_expression_list__default_semantic_action(node);
    }

    protected boolean process_assignment_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __conditional_expression__)
            {
                boolean action_result_before = action____assignment_expression__conditional_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_conditional_expression(child_1);

                boolean action_result_after = action____assignment_expression__conditional_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_expression] --> [conditional_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __unary_expression__
               &&child_2_type == __assignment_operator__
               &&child_3_type == __assignment_expression__)
            {
                boolean action_result_before = action____assignment_expression__unary_expression__assignment_operator__assignment_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_unary_expression(child_1);
                boolean result_2 = process_assignment_operator(child_2);
                boolean result_3 = process_assignment_expression(child_3);

                boolean action_result_after = action____assignment_expression__unary_expression__assignment_operator__assignment_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2 && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_expression] --> [unary_expression assignment_operator assignment_expression] returns false.");
                    return false;
                }
            }
        }

        return action____assignment_expression__default_semantic_action(node);
    }

    protected boolean process_assignment_operator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __EQUAL_SIGN__)
            {
                boolean action_result = action____assignment_operator__EQUAL_SIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> ['='] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __MUL_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__MUL_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [MUL_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __DIV_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__DIV_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [DIV_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __MOD_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__MOD_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [MOD_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __ADD_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__ADD_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [ADD_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __SUB_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__SUB_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [SUB_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __LEFT_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__LEFT_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [LEFT_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __RIGHT_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__RIGHT_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [RIGHT_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __AND_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__AND_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [AND_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __XOR_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__XOR_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [XOR_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __OR_ASSIGN__)
            {
                boolean action_result = action____assignment_operator__OR_ASSIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [assignment_operator] --> [OR_ASSIGN] returns false.");
                    return false;
                }
            }
        }

        return action____assignment_operator__default_semantic_action(node);
    }

    protected boolean process_cast_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __unary_expression__)
            {
                boolean action_result_before = action____cast_expression__unary_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_unary_expression(child_1);

                boolean action_result_after = action____cast_expression__unary_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [cast_expression] --> [unary_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __LEFT_PARENTHESIS__
               &&child_2_type == __type_name__
               &&child_3_type == __RIGHT_PARENTHESIS__
               &&child_4_type == __cast_expression__)
            {
                boolean action_result_before = action____cast_expression__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS__cast_expression(node, __ACTION_BEFORE__);

                boolean result_2 = process_type_name(child_2);
                boolean result_4 = process_cast_expression(child_4);

                boolean action_result_after = action____cast_expression__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS__cast_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true && result_4)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [cast_expression] --> ['(' type_name ')' cast_expression] returns false.");
                    return false;
                }
            }
        }

        return action____cast_expression__default_semantic_action(node);
    }

    protected boolean process_compound_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __LEFT_BRACE__
               &&child_2_type == __RIGHT_BRACE__)
            {
                boolean action_result = action____compound_statement__LEFT_BRACE__RIGHT_BRACE(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [compound_statement] --> ['{' '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_BRACE__
               &&child_2_type == __statement_list__
               &&child_3_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____compound_statement__LEFT_BRACE__statement_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_2 = process_statement_list(child_2);

                boolean action_result_after = action____compound_statement__LEFT_BRACE__statement_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [compound_statement] --> ['{' statement_list '}'] returns false.");
                    return false;
                }
            }
        }

        return action____compound_statement__default_semantic_action(node);
    }

    protected boolean process_conditional_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __logical_or_expression__)
            {
                boolean action_result_before = action____conditional_expression__logical_or_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_logical_or_expression(child_1);

                boolean action_result_after = action____conditional_expression__logical_or_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [conditional_expression] --> [logical_or_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __logical_or_expression__
               &&child_2_type == __QUESTION_MARK__
               &&child_3_type == __expression__
               &&child_4_type == __COLON__
               &&child_5_type == __conditional_expression__)
            {
                boolean action_result_before = action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__conditional_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_logical_or_expression(child_1);
                boolean result_3 = process_expression(child_3);
                boolean result_5 = process_conditional_expression(child_5);

                boolean action_result_after = action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__conditional_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true && result_5)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [conditional_expression] --> [logical_or_expression '?' expression ':' conditional_expression] returns false.");
                    return false;
                }
            }
        }

        return action____conditional_expression__default_semantic_action(node);
    }

    protected boolean process_constant_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __conditional_expression__)
            {
                boolean action_result_before = action____constant_expression__conditional_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_conditional_expression(child_1);

                boolean action_result_after = action____constant_expression__conditional_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [constant_expression] --> [conditional_expression] returns false.");
                    return false;
                }
            }
        }

        return action____constant_expression__default_semantic_action(node);
    }

    protected boolean process_declaration(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __function_definition__)
            {
                boolean action_result_before = action____declaration__function_definition(node, __ACTION_BEFORE__);

                boolean result_1 = process_function_definition(child_1);

                boolean action_result_after = action____declaration__function_definition(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration] --> [function_definition] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __simple_declaration__)
            {
                boolean action_result_before = action____declaration__simple_declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_simple_declaration(child_1);

                boolean action_result_after = action____declaration__simple_declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration] --> [simple_declaration] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __SEMICOLON__)
            {
                boolean action_result = action____declaration__SEMICOLON(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration] --> [';'] returns false.");
                    return false;
                }
            }
        }

        return action____declaration__default_semantic_action(node);
    }

    protected boolean process_declaration_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __declaration__)
            {
                boolean action_result_before = action____declaration_list__declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration(child_1);

                boolean action_result_after = action____declaration_list__declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_list] --> [declaration] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_list__
               &&child_2_type == __declaration__)
            {
                boolean action_result_before = action____declaration_list__declaration_list__declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_list(child_1);
                boolean result_2 = process_declaration(child_2);

                boolean action_result_after = action____declaration_list__declaration_list__declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_list] --> [declaration_list declaration] returns false.");
                    return false;
                }
            }
        }

        return action____declaration_list__default_semantic_action(node);
    }

    protected boolean process_declaration_specifiers(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __storage_class_specifier__)
            {
                boolean action_result_before = action____declaration_specifiers__storage_class_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_storage_class_specifier(child_1);

                boolean action_result_after = action____declaration_specifiers__storage_class_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_specifiers] --> [storage_class_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __storage_class_specifier__)
            {
                boolean action_result_before = action____declaration_specifiers__declaration_specifiers__storage_class_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_storage_class_specifier(child_2);

                boolean action_result_after = action____declaration_specifiers__declaration_specifiers__storage_class_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_specifiers] --> [declaration_specifiers storage_class_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __type_specifier__)
            {
                boolean action_result_before = action____declaration_specifiers__type_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_type_specifier(child_1);

                boolean action_result_after = action____declaration_specifiers__type_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_specifiers] --> [type_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __type_specifier__)
            {
                boolean action_result_before = action____declaration_specifiers__declaration_specifiers__type_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_type_specifier(child_2);

                boolean action_result_after = action____declaration_specifiers__declaration_specifiers__type_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_specifiers] --> [declaration_specifiers type_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __type_qualifier__)
            {
                boolean action_result_before = action____declaration_specifiers__type_qualifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_type_qualifier(child_1);

                boolean action_result_after = action____declaration_specifiers__type_qualifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_specifiers] --> [type_qualifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __type_qualifier__)
            {
                boolean action_result_before = action____declaration_specifiers__declaration_specifiers__type_qualifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_type_qualifier(child_2);

                boolean action_result_after = action____declaration_specifiers__declaration_specifiers__type_qualifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declaration_specifiers] --> [declaration_specifiers type_qualifier] returns false.");
                    return false;
                }
            }
        }

        return action____declaration_specifiers__default_semantic_action(node);
    }

    protected boolean process_declarator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __pointer__
               &&child_2_type == __direct_declarator__)
            {
                boolean action_result_before = action____declarator__pointer__direct_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_pointer(child_1);
                boolean result_2 = process_direct_declarator(child_2);

                boolean action_result_after = action____declarator__pointer__direct_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declarator] --> [pointer direct_declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __direct_declarator__)
            {
                boolean action_result_before = action____declarator__direct_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_declarator(child_1);

                boolean action_result_after = action____declarator__direct_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [declarator] --> [direct_declarator] returns false.");
                    return false;
                }
            }
        }

        return action____declarator__default_semantic_action(node);
    }

    protected boolean process_direct_abstract_declarator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_PARENTHESIS__
               &&child_2_type == __abstract_declarator__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_2 = process_abstract_declarator(child_2);

                boolean action_result_after = action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> ['(' abstract_declarator ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __LEFT_BRACKET__
               &&child_2_type == __RIGHT_BRACKET__)
            {
                boolean action_result = action____direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> ['[' ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_BRACKET__
               &&child_2_type == __constant_expression__
               &&child_3_type == __RIGHT_BRACKET__)
            {
                boolean action_result_before = action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(node, __ACTION_BEFORE__);

                boolean result_2 = process_constant_expression(child_2);

                boolean action_result_after = action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> ['[' constant_expression ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __direct_abstract_declarator__
               &&child_2_type == __LEFT_BRACKET__
               &&child_3_type == __RIGHT_BRACKET__)
            {
                boolean action_result_before = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_abstract_declarator(child_1);

                boolean action_result_after = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> [direct_abstract_declarator '[' ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __direct_abstract_declarator__
               &&child_2_type == __LEFT_BRACKET__
               &&child_3_type == __constant_expression__
               &&child_4_type == __RIGHT_BRACKET__)
            {
                boolean action_result_before = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_abstract_declarator(child_1);
                boolean result_3 = process_constant_expression(child_3);

                boolean action_result_after = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> [direct_abstract_declarator '[' constant_expression ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __LEFT_PARENTHESIS__
               &&child_2_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result = action____direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> ['(' ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_PARENTHESIS__
               &&child_2_type == __parameter_type_list__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_2 = process_parameter_type_list(child_2);

                boolean action_result_after = action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> ['(' parameter_type_list ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __direct_abstract_declarator__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_abstract_declarator(child_1);

                boolean action_result_after = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> [direct_abstract_declarator '(' ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __direct_abstract_declarator__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __parameter_type_list__
               &&child_4_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_abstract_declarator(child_1);
                boolean result_3 = process_parameter_type_list(child_3);

                boolean action_result_after = action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_abstract_declarator] --> [direct_abstract_declarator '(' parameter_type_list ')'] returns false.");
                    return false;
                }
            }
        }

        return action____direct_abstract_declarator__default_semantic_action(node);
    }

    protected boolean process_direct_declarator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __IDENTIFIER__)
            {
                boolean action_result = action____direct_declarator__IDENTIFIER(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_declarator] --> [IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_PARENTHESIS__
               &&child_2_type == __declarator__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_2 = process_declarator(child_2);

                boolean action_result_after = action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_declarator] --> ['(' declarator ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __direct_declarator__
               &&child_2_type == __LEFT_BRACKET__
               &&child_3_type == __constant_expression__
               &&child_4_type == __RIGHT_BRACKET__)
            {
                boolean action_result_before = action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_declarator(child_1);
                boolean result_3 = process_constant_expression(child_3);

                boolean action_result_after = action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_declarator] --> [direct_declarator '[' constant_expression ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __direct_declarator__
               &&child_2_type == __LEFT_BRACKET__
               &&child_3_type == __RIGHT_BRACKET__)
            {
                boolean action_result_before = action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_declarator(child_1);

                boolean action_result_after = action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_declarator] --> [direct_declarator '[' ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __direct_declarator__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __parameter_type_list__
               &&child_4_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_declarator(child_1);
                boolean result_3 = process_parameter_type_list(child_3);

                boolean action_result_after = action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_declarator] --> [direct_declarator '(' parameter_type_list ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __direct_declarator__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_direct_declarator(child_1);

                boolean action_result_after = action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [direct_declarator] --> [direct_declarator '(' ')'] returns false.");
                    return false;
                }
            }
        }

        return action____direct_declarator__default_semantic_action(node);
    }

    protected boolean process_enum_specifier(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __ENUM__
               &&child_2_type == __LEFT_BRACE__
               &&child_3_type == __enumerator_list__
               &&child_4_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____enum_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_3 = process_enumerator_list(child_3);

                boolean action_result_after = action____enum_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enum_specifier] --> [ENUM '{' enumerator_list '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __ENUM__
               &&child_2_type == __IDENTIFIER__
               &&child_3_type == __LEFT_BRACE__
               &&child_4_type == __enumerator_list__
               &&child_5_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____enum_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_4 = process_enumerator_list(child_4);

                boolean action_result_after = action____enum_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && true && result_4 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enum_specifier] --> [ENUM IDENTIFIER '{' enumerator_list '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __ENUM__
               &&child_2_type == __IDENTIFIER__)
            {
                boolean action_result = action____enum_specifier__ENUM__IDENTIFIER(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enum_specifier] --> [ENUM IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        return action____enum_specifier__default_semantic_action(node);
    }

    protected boolean process_enumerator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __IDENTIFIER__)
            {
                boolean action_result = action____enumerator__IDENTIFIER(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enumerator] --> [IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __IDENTIFIER__
               &&child_2_type == __EQUAL_SIGN__
               &&child_3_type == __constant_expression__)
            {
                boolean action_result_before = action____enumerator__IDENTIFIER__EQUAL_SIGN__constant_expression(node, __ACTION_BEFORE__);

                boolean result_3 = process_constant_expression(child_3);

                boolean action_result_after = action____enumerator__IDENTIFIER__EQUAL_SIGN__constant_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enumerator] --> [IDENTIFIER '=' constant_expression] returns false.");
                    return false;
                }
            }
        }

        return action____enumerator__default_semantic_action(node);
    }

    protected boolean process_enumerator_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __enumerator__)
            {
                boolean action_result_before = action____enumerator_list__enumerator(node, __ACTION_BEFORE__);

                boolean result_1 = process_enumerator(child_1);

                boolean action_result_after = action____enumerator_list__enumerator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enumerator_list] --> [enumerator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __enumerator_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __enumerator__)
            {
                boolean action_result_before = action____enumerator_list__enumerator_list__COMMA__enumerator(node, __ACTION_BEFORE__);

                boolean result_1 = process_enumerator_list(child_1);
                boolean result_3 = process_enumerator(child_3);

                boolean action_result_after = action____enumerator_list__enumerator_list__COMMA__enumerator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [enumerator_list] --> [enumerator_list ',' enumerator] returns false.");
                    return false;
                }
            }
        }

        return action____enumerator_list__default_semantic_action(node);
    }

    protected boolean process_equality_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __relational_expression__)
            {
                boolean action_result_before = action____equality_expression__relational_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_relational_expression(child_1);

                boolean action_result_after = action____equality_expression__relational_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [equality_expression] --> [relational_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __equality_expression__
               &&child_2_type == __EQ_OP__
               &&child_3_type == __relational_expression__)
            {
                boolean action_result_before = action____equality_expression__equality_expression__EQ_OP__relational_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_equality_expression(child_1);
                boolean result_3 = process_relational_expression(child_3);

                boolean action_result_after = action____equality_expression__equality_expression__EQ_OP__relational_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [equality_expression] --> [equality_expression EQ_OP relational_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __equality_expression__
               &&child_2_type == __NE_OP__
               &&child_3_type == __relational_expression__)
            {
                boolean action_result_before = action____equality_expression__equality_expression__NE_OP__relational_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_equality_expression(child_1);
                boolean result_3 = process_relational_expression(child_3);

                boolean action_result_after = action____equality_expression__equality_expression__NE_OP__relational_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [equality_expression] --> [equality_expression NE_OP relational_expression] returns false.");
                    return false;
                }
            }
        }

        return action____equality_expression__default_semantic_action(node);
    }

    protected boolean process_exclusive_or_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __and_expression__)
            {
                boolean action_result_before = action____exclusive_or_expression__and_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_and_expression(child_1);

                boolean action_result_after = action____exclusive_or_expression__and_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [exclusive_or_expression] --> [and_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __exclusive_or_expression__
               &&child_2_type == __CARET__
               &&child_3_type == __and_expression__)
            {
                boolean action_result_before = action____exclusive_or_expression__exclusive_or_expression__CARET__and_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_exclusive_or_expression(child_1);
                boolean result_3 = process_and_expression(child_3);

                boolean action_result_after = action____exclusive_or_expression__exclusive_or_expression__CARET__and_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [exclusive_or_expression] --> [exclusive_or_expression '^' and_expression] returns false.");
                    return false;
                }
            }
        }

        return action____exclusive_or_expression__default_semantic_action(node);
    }

    protected boolean process_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __assignment_expression__)
            {
                boolean action_result_before = action____expression__assignment_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_assignment_expression(child_1);

                boolean action_result_after = action____expression__assignment_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [expression] --> [assignment_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __expression__
               &&child_2_type == __COMMA__
               &&child_3_type == __assignment_expression__)
            {
                boolean action_result_before = action____expression__expression__COMMA__assignment_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_expression(child_1);
                boolean result_3 = process_assignment_expression(child_3);

                boolean action_result_after = action____expression__expression__COMMA__assignment_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [expression] --> [expression ',' assignment_expression] returns false.");
                    return false;
                }
            }
        }

        return action____expression__default_semantic_action(node);
    }

    protected boolean process_expression_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __SEMICOLON__)
            {
                boolean action_result = action____expression_statement__SEMICOLON(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [expression_statement] --> [';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __expression__
               &&child_2_type == __SEMICOLON__)
            {
                boolean action_result_before = action____expression_statement__expression__SEMICOLON(node, __ACTION_BEFORE__);

                boolean result_1 = process_expression(child_1);

                boolean action_result_after = action____expression_statement__expression__SEMICOLON(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [expression_statement] --> [expression ';'] returns false.");
                    return false;
                }
            }
        }

        return action____expression_statement__default_semantic_action(node);
    }

    protected boolean process_function_definition(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __declarator__
               &&child_3_type == __compound_statement__)
            {
                boolean action_result_before = action____function_definition__declaration_specifiers__declarator__compound_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_declarator(child_2);
                boolean result_3 = process_compound_statement(child_3);

                boolean action_result_after = action____function_definition__declaration_specifiers__declarator__compound_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2 && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [function_definition] --> [declaration_specifiers declarator compound_statement] returns false.");
                    return false;
                }
            }
        }

        return action____function_definition__default_semantic_action(node);
    }

    protected boolean process_inclusive_or_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __exclusive_or_expression__)
            {
                boolean action_result_before = action____inclusive_or_expression__exclusive_or_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_exclusive_or_expression(child_1);

                boolean action_result_after = action____inclusive_or_expression__exclusive_or_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [inclusive_or_expression] --> [exclusive_or_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __inclusive_or_expression__
               &&child_2_type == __VERTICAL_BAR__
               &&child_3_type == __exclusive_or_expression__)
            {
                boolean action_result_before = action____inclusive_or_expression__inclusive_or_expression__VERTICAL_BAR__exclusive_or_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_inclusive_or_expression(child_1);
                boolean result_3 = process_exclusive_or_expression(child_3);

                boolean action_result_after = action____inclusive_or_expression__inclusive_or_expression__VERTICAL_BAR__exclusive_or_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [inclusive_or_expression] --> [inclusive_or_expression '|' exclusive_or_expression] returns false.");
                    return false;
                }
            }
        }

        return action____inclusive_or_expression__default_semantic_action(node);
    }

    protected boolean process_init_declarator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __declarator__)
            {
                boolean action_result_before = action____init_declarator__declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_declarator(child_1);

                boolean action_result_after = action____init_declarator__declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [init_declarator] --> [declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __declarator__
               &&child_2_type == __EQUAL_SIGN__
               &&child_3_type == __initializer__)
            {
                boolean action_result_before = action____init_declarator__declarator__EQUAL_SIGN__initializer(node, __ACTION_BEFORE__);

                boolean result_1 = process_declarator(child_1);
                boolean result_3 = process_initializer(child_3);

                boolean action_result_after = action____init_declarator__declarator__EQUAL_SIGN__initializer(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [init_declarator] --> [declarator '=' initializer] returns false.");
                    return false;
                }
            }
        }

        return action____init_declarator__default_semantic_action(node);
    }

    protected boolean process_init_declarator_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __init_declarator__)
            {
                boolean action_result_before = action____init_declarator_list__init_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_init_declarator(child_1);

                boolean action_result_after = action____init_declarator_list__init_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [init_declarator_list] --> [init_declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __init_declarator_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __init_declarator__)
            {
                boolean action_result_before = action____init_declarator_list__init_declarator_list__COMMA__init_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_init_declarator_list(child_1);
                boolean result_3 = process_init_declarator(child_3);

                boolean action_result_after = action____init_declarator_list__init_declarator_list__COMMA__init_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [init_declarator_list] --> [init_declarator_list ',' init_declarator] returns false.");
                    return false;
                }
            }
        }

        return action____init_declarator_list__default_semantic_action(node);
    }

    protected boolean process_initializer(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __assignment_expression__)
            {
                boolean action_result_before = action____initializer__assignment_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_assignment_expression(child_1);

                boolean action_result_after = action____initializer__assignment_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [initializer] --> [assignment_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_BRACE__
               &&child_2_type == __initializer_list__
               &&child_3_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____initializer__LEFT_BRACE__initializer_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_2 = process_initializer_list(child_2);

                boolean action_result_after = action____initializer__LEFT_BRACE__initializer_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [initializer] --> ['{' initializer_list '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __LEFT_BRACE__
               &&child_2_type == __initializer_list__
               &&child_3_type == __COMMA__
               &&child_4_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____initializer__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_2 = process_initializer_list(child_2);

                boolean action_result_after = action____initializer__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [initializer] --> ['{' initializer_list ',' '}'] returns false.");
                    return false;
                }
            }
        }

        return action____initializer__default_semantic_action(node);
    }

    protected boolean process_initializer_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __initializer__)
            {
                boolean action_result_before = action____initializer_list__initializer(node, __ACTION_BEFORE__);

                boolean result_1 = process_initializer(child_1);

                boolean action_result_after = action____initializer_list__initializer(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [initializer_list] --> [initializer] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __initializer_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __initializer__)
            {
                boolean action_result_before = action____initializer_list__initializer_list__COMMA__initializer(node, __ACTION_BEFORE__);

                boolean result_1 = process_initializer_list(child_1);
                boolean result_3 = process_initializer(child_3);

                boolean action_result_after = action____initializer_list__initializer_list__COMMA__initializer(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [initializer_list] --> [initializer_list ',' initializer] returns false.");
                    return false;
                }
            }
        }

        return action____initializer_list__default_semantic_action(node);
    }

    protected boolean process_iteration_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __WHILE__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __expression__
               &&child_4_type == __RIGHT_PARENTHESIS__
               &&child_5_type == __statement__)
            {
                boolean action_result_before = action____iteration_statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_expression(child_3);
                boolean result_5 = process_statement(child_5);

                boolean action_result_after = action____iteration_statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && true && result_5)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [iteration_statement] --> [WHILE '(' expression ')' statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 7)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();
            GeneralSyntaxNode	child_6 = (GeneralSyntaxNode)(node.getChild(5));
            int	child_6_type = child_6.getTypeCode();
            GeneralSyntaxNode	child_7 = (GeneralSyntaxNode)(node.getChild(6));
            int	child_7_type = child_7.getTypeCode();

            if (child_1_type == __DO__
               &&child_2_type == __statement__
               &&child_3_type == __WHILE__
               &&child_4_type == __LEFT_PARENTHESIS__
               &&child_5_type == __expression__
               &&child_6_type == __RIGHT_PARENTHESIS__
               &&child_7_type == __SEMICOLON__)
            {
                boolean action_result_before = action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON(node, __ACTION_BEFORE__);

                boolean result_2 = process_statement(child_2);
                boolean result_5 = process_expression(child_5);

                boolean action_result_after = action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true && true && result_5 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [iteration_statement] --> [DO statement WHILE '(' expression ')' ';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 6)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();
            GeneralSyntaxNode	child_6 = (GeneralSyntaxNode)(node.getChild(5));
            int	child_6_type = child_6.getTypeCode();

            if (child_1_type == __FOR__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __expression_statement__
               &&child_4_type == __expression_statement__
               &&child_5_type == __RIGHT_PARENTHESIS__
               &&child_6_type == __statement__)
            {
                boolean action_result_before = action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__RIGHT_PARENTHESIS__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_expression_statement(child_3);
                boolean result_4 = process_expression_statement(child_4);
                boolean result_6 = process_statement(child_6);

                boolean action_result_after = action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__RIGHT_PARENTHESIS__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && result_4 && true && result_6)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [iteration_statement] --> [FOR '(' expression_statement expression_statement ')' statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 7)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();
            GeneralSyntaxNode	child_6 = (GeneralSyntaxNode)(node.getChild(5));
            int	child_6_type = child_6.getTypeCode();
            GeneralSyntaxNode	child_7 = (GeneralSyntaxNode)(node.getChild(6));
            int	child_7_type = child_7.getTypeCode();

            if (child_1_type == __FOR__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __expression_statement__
               &&child_4_type == __expression_statement__
               &&child_5_type == __expression__
               &&child_6_type == __RIGHT_PARENTHESIS__
               &&child_7_type == __statement__)
            {
                boolean action_result_before = action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_expression_statement(child_3);
                boolean result_4 = process_expression_statement(child_4);
                boolean result_5 = process_expression(child_5);
                boolean result_7 = process_statement(child_7);

                boolean action_result_after = action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && result_4 && result_5 && true && result_7)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [iteration_statement] --> [FOR '(' expression_statement expression_statement expression ')' statement] returns false.");
                    return false;
                }
            }
        }

        return action____iteration_statement__default_semantic_action(node);
    }

    protected boolean process_jump_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __GOTO__
               &&child_2_type == __IDENTIFIER__
               &&child_3_type == __SEMICOLON__)
            {
                boolean action_result = action____jump_statement__GOTO__IDENTIFIER__SEMICOLON(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [jump_statement] --> [GOTO IDENTIFIER ';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __CONTINUE__
               &&child_2_type == __SEMICOLON__)
            {
                boolean action_result = action____jump_statement__CONTINUE__SEMICOLON(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [jump_statement] --> [CONTINUE ';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __BREAK__
               &&child_2_type == __SEMICOLON__)
            {
                boolean action_result = action____jump_statement__BREAK__SEMICOLON(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [jump_statement] --> [BREAK ';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __RETURN__
               &&child_2_type == __SEMICOLON__)
            {
                boolean action_result = action____jump_statement__RETURN__SEMICOLON(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [jump_statement] --> [RETURN ';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __RETURN__
               &&child_2_type == __expression__
               &&child_3_type == __SEMICOLON__)
            {
                boolean action_result_before = action____jump_statement__RETURN__expression__SEMICOLON(node, __ACTION_BEFORE__);

                boolean result_2 = process_expression(child_2);

                boolean action_result_after = action____jump_statement__RETURN__expression__SEMICOLON(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [jump_statement] --> [RETURN expression ';'] returns false.");
                    return false;
                }
            }
        }

        return action____jump_statement__default_semantic_action(node);
    }

    protected boolean process_labeled_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __IDENTIFIER__
               &&child_2_type == __COLON__
               &&child_3_type == __statement__)
            {
                boolean action_result_before = action____labeled_statement__IDENTIFIER__COLON__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_statement(child_3);

                boolean action_result_after = action____labeled_statement__IDENTIFIER__COLON__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [labeled_statement] --> [IDENTIFIER ':' statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __CASE__
               &&child_2_type == __constant_expression__
               &&child_3_type == __COLON__
               &&child_4_type == __statement__)
            {
                boolean action_result_before = action____labeled_statement__CASE__constant_expression__COLON__statement(node, __ACTION_BEFORE__);

                boolean result_2 = process_constant_expression(child_2);
                boolean result_4 = process_statement(child_4);

                boolean action_result_after = action____labeled_statement__CASE__constant_expression__COLON__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true && result_4)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [labeled_statement] --> [CASE constant_expression ':' statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __DEFAULT__
               &&child_2_type == __COLON__
               &&child_3_type == __statement__)
            {
                boolean action_result_before = action____labeled_statement__DEFAULT__COLON__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_statement(child_3);

                boolean action_result_after = action____labeled_statement__DEFAULT__COLON__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [labeled_statement] --> [DEFAULT ':' statement] returns false.");
                    return false;
                }
            }
        }

        return action____labeled_statement__default_semantic_action(node);
    }

    protected boolean process_logical_and_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __inclusive_or_expression__)
            {
                boolean action_result_before = action____logical_and_expression__inclusive_or_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_inclusive_or_expression(child_1);

                boolean action_result_after = action____logical_and_expression__inclusive_or_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [logical_and_expression] --> [inclusive_or_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __logical_and_expression__
               &&child_2_type == __AND_OP__
               &&child_3_type == __inclusive_or_expression__)
            {
                boolean action_result_before = action____logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_logical_and_expression(child_1);
                boolean result_3 = process_inclusive_or_expression(child_3);

                boolean action_result_after = action____logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [logical_and_expression] --> [logical_and_expression AND_OP inclusive_or_expression] returns false.");
                    return false;
                }
            }
        }

        return action____logical_and_expression__default_semantic_action(node);
    }

    protected boolean process_logical_or_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __logical_and_expression__)
            {
                boolean action_result_before = action____logical_or_expression__logical_and_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_logical_and_expression(child_1);

                boolean action_result_after = action____logical_or_expression__logical_and_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [logical_or_expression] --> [logical_and_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __logical_or_expression__
               &&child_2_type == __OR_OP__
               &&child_3_type == __logical_and_expression__)
            {
                boolean action_result_before = action____logical_or_expression__logical_or_expression__OR_OP__logical_and_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_logical_or_expression(child_1);
                boolean result_3 = process_logical_and_expression(child_3);

                boolean action_result_after = action____logical_or_expression__logical_or_expression__OR_OP__logical_and_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [logical_or_expression] --> [logical_or_expression OR_OP logical_and_expression] returns false.");
                    return false;
                }
            }
        }

        return action____logical_or_expression__default_semantic_action(node);
    }

    protected boolean process_multiplicative_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __cast_expression__)
            {
                boolean action_result_before = action____multiplicative_expression__cast_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_cast_expression(child_1);

                boolean action_result_after = action____multiplicative_expression__cast_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [multiplicative_expression] --> [cast_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __multiplicative_expression__
               &&child_2_type == __ASTERISK__
               &&child_3_type == __cast_expression__)
            {
                boolean action_result_before = action____multiplicative_expression__multiplicative_expression__ASTERISK__cast_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_multiplicative_expression(child_1);
                boolean result_3 = process_cast_expression(child_3);

                boolean action_result_after = action____multiplicative_expression__multiplicative_expression__ASTERISK__cast_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [multiplicative_expression] --> [multiplicative_expression '*' cast_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __multiplicative_expression__
               &&child_2_type == __SLASH__
               &&child_3_type == __cast_expression__)
            {
                boolean action_result_before = action____multiplicative_expression__multiplicative_expression__SLASH__cast_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_multiplicative_expression(child_1);
                boolean result_3 = process_cast_expression(child_3);

                boolean action_result_after = action____multiplicative_expression__multiplicative_expression__SLASH__cast_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [multiplicative_expression] --> [multiplicative_expression '/' cast_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __multiplicative_expression__
               &&child_2_type == __PERCENT_SIGN__
               &&child_3_type == __cast_expression__)
            {
                boolean action_result_before = action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__cast_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_multiplicative_expression(child_1);
                boolean result_3 = process_cast_expression(child_3);

                boolean action_result_after = action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__cast_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [multiplicative_expression] --> [multiplicative_expression '%' cast_expression] returns false.");
                    return false;
                }
            }
        }

        return action____multiplicative_expression__default_semantic_action(node);
    }

    protected boolean process_parameter_declaration(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __declarator__)
            {
                boolean action_result_before = action____parameter_declaration__declaration_specifiers__declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_declarator(child_2);

                boolean action_result_after = action____parameter_declaration__declaration_specifiers__declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_declaration] --> [declaration_specifiers declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __abstract_declarator__)
            {
                boolean action_result_before = action____parameter_declaration__declaration_specifiers__abstract_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_abstract_declarator(child_2);

                boolean action_result_after = action____parameter_declaration__declaration_specifiers__abstract_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_declaration] --> [declaration_specifiers abstract_declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __declaration_specifiers__)
            {
                boolean action_result_before = action____parameter_declaration__declaration_specifiers(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);

                boolean action_result_after = action____parameter_declaration__declaration_specifiers(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_declaration] --> [declaration_specifiers] returns false.");
                    return false;
                }
            }
        }

        return action____parameter_declaration__default_semantic_action(node);
    }

    protected boolean process_parameter_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __parameter_declaration__)
            {
                boolean action_result_before = action____parameter_list__parameter_declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_parameter_declaration(child_1);

                boolean action_result_after = action____parameter_list__parameter_declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_list] --> [parameter_declaration] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __parameter_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __parameter_declaration__)
            {
                boolean action_result_before = action____parameter_list__parameter_list__COMMA__parameter_declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_parameter_list(child_1);
                boolean result_3 = process_parameter_declaration(child_3);

                boolean action_result_after = action____parameter_list__parameter_list__COMMA__parameter_declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_list] --> [parameter_list ',' parameter_declaration] returns false.");
                    return false;
                }
            }
        }

        return action____parameter_list__default_semantic_action(node);
    }

    protected boolean process_parameter_type_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __parameter_list__)
            {
                boolean action_result_before = action____parameter_type_list__parameter_list(node, __ACTION_BEFORE__);

                boolean result_1 = process_parameter_list(child_1);

                boolean action_result_after = action____parameter_type_list__parameter_list(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_type_list] --> [parameter_list] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __parameter_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __ELLIPSIS__)
            {
                boolean action_result_before = action____parameter_type_list__parameter_list__COMMA__ELLIPSIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_parameter_list(child_1);

                boolean action_result_after = action____parameter_type_list__parameter_list__COMMA__ELLIPSIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [parameter_type_list] --> [parameter_list ',' ELLIPSIS] returns false.");
                    return false;
                }
            }
        }

        return action____parameter_type_list__default_semantic_action(node);
    }

    protected boolean process_pointer(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __ASTERISK__)
            {
                boolean action_result = action____pointer__ASTERISK(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [pointer] --> ['*'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __ASTERISK__
               &&child_2_type == __type_qualifier_list__)
            {
                boolean action_result_before = action____pointer__ASTERISK__type_qualifier_list(node, __ACTION_BEFORE__);

                boolean result_2 = process_type_qualifier_list(child_2);

                boolean action_result_after = action____pointer__ASTERISK__type_qualifier_list(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [pointer] --> ['*' type_qualifier_list] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __ASTERISK__
               &&child_2_type == __pointer__)
            {
                boolean action_result_before = action____pointer__ASTERISK__pointer(node, __ACTION_BEFORE__);

                boolean result_2 = process_pointer(child_2);

                boolean action_result_after = action____pointer__ASTERISK__pointer(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [pointer] --> ['*' pointer] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __ASTERISK__
               &&child_2_type == __type_qualifier_list__
               &&child_3_type == __pointer__)
            {
                boolean action_result_before = action____pointer__ASTERISK__type_qualifier_list__pointer(node, __ACTION_BEFORE__);

                boolean result_2 = process_type_qualifier_list(child_2);
                boolean result_3 = process_pointer(child_3);

                boolean action_result_after = action____pointer__ASTERISK__type_qualifier_list__pointer(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [pointer] --> ['*' type_qualifier_list pointer] returns false.");
                    return false;
                }
            }
        }

        return action____pointer__default_semantic_action(node);
    }

    protected boolean process_postfix_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __primary_expression__)
            {
                boolean action_result_before = action____postfix_expression__primary_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_primary_expression(child_1);

                boolean action_result_after = action____postfix_expression__primary_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [primary_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __LEFT_BRACKET__
               &&child_3_type == __expression__
               &&child_4_type == __RIGHT_BRACKET__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);
                boolean result_3 = process_expression(child_3);

                boolean action_result_after = action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression '[' expression ']'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);

                boolean action_result_after = action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression '(' ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __argument_expression_list__
               &&child_4_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__argument_expression_list__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);
                boolean result_3 = process_argument_expression_list(child_3);

                boolean action_result_after = action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__argument_expression_list__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression '(' argument_expression_list ')'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __DOT__
               &&child_3_type == __IDENTIFIER__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__DOT__IDENTIFIER(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);

                boolean action_result_after = action____postfix_expression__postfix_expression__DOT__IDENTIFIER(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression '.' IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __PTR_OP__
               &&child_3_type == __IDENTIFIER__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__PTR_OP__IDENTIFIER(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);

                boolean action_result_after = action____postfix_expression__postfix_expression__PTR_OP__IDENTIFIER(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression PTR_OP IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __INC_OP__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__INC_OP(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);

                boolean action_result_after = action____postfix_expression__postfix_expression__INC_OP(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression INC_OP] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __postfix_expression__
               &&child_2_type == __DEC_OP__)
            {
                boolean action_result_before = action____postfix_expression__postfix_expression__DEC_OP(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);

                boolean action_result_after = action____postfix_expression__postfix_expression__DEC_OP(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [postfix_expression] --> [postfix_expression DEC_OP] returns false.");
                    return false;
                }
            }
        }

        return action____postfix_expression__default_semantic_action(node);
    }

    protected boolean process_primary_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __IDENTIFIER__)
            {
                boolean action_result = action____primary_expression__IDENTIFIER(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [primary_expression] --> [IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __CONSTANT__)
            {
                boolean action_result = action____primary_expression__CONSTANT(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [primary_expression] --> [CONSTANT] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __STRING_LITERAL__)
            {
                boolean action_result = action____primary_expression__STRING_LITERAL(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [primary_expression] --> [STRING_LITERAL] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __LEFT_PARENTHESIS__
               &&child_2_type == __expression__
               &&child_3_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_2 = process_expression(child_2);

                boolean action_result_after = action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [primary_expression] --> ['(' expression ')'] returns false.");
                    return false;
                }
            }
        }

        return action____primary_expression__default_semantic_action(node);
    }

    protected boolean process_relational_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __shift_expression__)
            {
                boolean action_result_before = action____relational_expression__shift_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_shift_expression(child_1);

                boolean action_result_after = action____relational_expression__shift_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [relational_expression] --> [shift_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __relational_expression__
               &&child_2_type == __LEFT_ANGLE_BRACKET__
               &&child_3_type == __shift_expression__)
            {
                boolean action_result_before = action____relational_expression__relational_expression__LEFT_ANGLE_BRACKET__shift_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_relational_expression(child_1);
                boolean result_3 = process_shift_expression(child_3);

                boolean action_result_after = action____relational_expression__relational_expression__LEFT_ANGLE_BRACKET__shift_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [relational_expression] --> [relational_expression '<' shift_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __relational_expression__
               &&child_2_type == __RIGHT_ANGLE_BRACKET__
               &&child_3_type == __shift_expression__)
            {
                boolean action_result_before = action____relational_expression__relational_expression__RIGHT_ANGLE_BRACKET__shift_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_relational_expression(child_1);
                boolean result_3 = process_shift_expression(child_3);

                boolean action_result_after = action____relational_expression__relational_expression__RIGHT_ANGLE_BRACKET__shift_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [relational_expression] --> [relational_expression '>' shift_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __relational_expression__
               &&child_2_type == __LE_OP__
               &&child_3_type == __shift_expression__)
            {
                boolean action_result_before = action____relational_expression__relational_expression__LE_OP__shift_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_relational_expression(child_1);
                boolean result_3 = process_shift_expression(child_3);

                boolean action_result_after = action____relational_expression__relational_expression__LE_OP__shift_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [relational_expression] --> [relational_expression LE_OP shift_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __relational_expression__
               &&child_2_type == __GE_OP__
               &&child_3_type == __shift_expression__)
            {
                boolean action_result_before = action____relational_expression__relational_expression__GE_OP__shift_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_relational_expression(child_1);
                boolean result_3 = process_shift_expression(child_3);

                boolean action_result_after = action____relational_expression__relational_expression__GE_OP__shift_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [relational_expression] --> [relational_expression GE_OP shift_expression] returns false.");
                    return false;
                }
            }
        }

        return action____relational_expression__default_semantic_action(node);
    }

    protected boolean process_selection_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __IF__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __expression__
               &&child_4_type == __RIGHT_PARENTHESIS__
               &&child_5_type == __statement__)
            {
                boolean action_result_before = action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_expression(child_3);
                boolean result_5 = process_statement(child_5);

                boolean action_result_after = action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && true && result_5)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [selection_statement] --> [IF '(' expression ')' statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 7)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();
            GeneralSyntaxNode	child_6 = (GeneralSyntaxNode)(node.getChild(5));
            int	child_6_type = child_6.getTypeCode();
            GeneralSyntaxNode	child_7 = (GeneralSyntaxNode)(node.getChild(6));
            int	child_7_type = child_7.getTypeCode();

            if (child_1_type == __IF__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __expression__
               &&child_4_type == __RIGHT_PARENTHESIS__
               &&child_5_type == __statement__
               &&child_6_type == __ELSE__
               &&child_7_type == __statement__)
            {
                boolean action_result_before = action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement__ELSE__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_expression(child_3);
                boolean result_5 = process_statement(child_5);
                boolean result_7 = process_statement(child_7);

                boolean action_result_after = action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement__ELSE__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && true && result_5 && true && result_7)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [selection_statement] --> [IF '(' expression ')' statement ELSE statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __SWITCH__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __expression__
               &&child_4_type == __RIGHT_PARENTHESIS__
               &&child_5_type == __statement__)
            {
                boolean action_result_before = action____selection_statement__SWITCH__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_BEFORE__);

                boolean result_3 = process_expression(child_3);
                boolean result_5 = process_statement(child_5);

                boolean action_result_after = action____selection_statement__SWITCH__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && true && result_5)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [selection_statement] --> [SWITCH '(' expression ')' statement] returns false.");
                    return false;
                }
            }
        }

        return action____selection_statement__default_semantic_action(node);
    }

    protected boolean process_shift_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __additive_expression__)
            {
                boolean action_result_before = action____shift_expression__additive_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_additive_expression(child_1);

                boolean action_result_after = action____shift_expression__additive_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [shift_expression] --> [additive_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __shift_expression__
               &&child_2_type == __LEFT_OP__
               &&child_3_type == __additive_expression__)
            {
                boolean action_result_before = action____shift_expression__shift_expression__LEFT_OP__additive_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_shift_expression(child_1);
                boolean result_3 = process_additive_expression(child_3);

                boolean action_result_after = action____shift_expression__shift_expression__LEFT_OP__additive_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [shift_expression] --> [shift_expression LEFT_OP additive_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __shift_expression__
               &&child_2_type == __RIGHT_OP__
               &&child_3_type == __additive_expression__)
            {
                boolean action_result_before = action____shift_expression__shift_expression__RIGHT_OP__additive_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_shift_expression(child_1);
                boolean result_3 = process_additive_expression(child_3);

                boolean action_result_after = action____shift_expression__shift_expression__RIGHT_OP__additive_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [shift_expression] --> [shift_expression RIGHT_OP additive_expression] returns false.");
                    return false;
                }
            }
        }

        return action____shift_expression__default_semantic_action(node);
    }

    protected boolean process_simple_declaration(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __SEMICOLON__)
            {
                boolean action_result_before = action____simple_declaration__declaration_specifiers__SEMICOLON(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);

                boolean action_result_after = action____simple_declaration__declaration_specifiers__SEMICOLON(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [simple_declaration] --> [declaration_specifiers ';'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __declaration_specifiers__
               &&child_2_type == __init_declarator_list__
               &&child_3_type == __SEMICOLON__)
            {
                boolean action_result_before = action____simple_declaration__declaration_specifiers__init_declarator_list__SEMICOLON(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_specifiers(child_1);
                boolean result_2 = process_init_declarator_list(child_2);

                boolean action_result_after = action____simple_declaration__declaration_specifiers__init_declarator_list__SEMICOLON(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [simple_declaration] --> [declaration_specifiers init_declarator_list ';'] returns false.");
                    return false;
                }
            }
        }

        return action____simple_declaration__default_semantic_action(node);
    }

    protected boolean process_specifier_qualifier_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __type_specifier__)
            {
                boolean action_result_before = action____specifier_qualifier_list__type_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_type_specifier(child_1);

                boolean action_result_after = action____specifier_qualifier_list__type_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [specifier_qualifier_list] --> [type_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __specifier_qualifier_list__
               &&child_2_type == __type_specifier__)
            {
                boolean action_result_before = action____specifier_qualifier_list__specifier_qualifier_list__type_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_specifier_qualifier_list(child_1);
                boolean result_2 = process_type_specifier(child_2);

                boolean action_result_after = action____specifier_qualifier_list__specifier_qualifier_list__type_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [specifier_qualifier_list] --> [specifier_qualifier_list type_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __type_qualifier__)
            {
                boolean action_result_before = action____specifier_qualifier_list__type_qualifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_type_qualifier(child_1);

                boolean action_result_after = action____specifier_qualifier_list__type_qualifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [specifier_qualifier_list] --> [type_qualifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __specifier_qualifier_list__
               &&child_2_type == __type_qualifier__)
            {
                boolean action_result_before = action____specifier_qualifier_list__specifier_qualifier_list__type_qualifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_specifier_qualifier_list(child_1);
                boolean result_2 = process_type_qualifier(child_2);

                boolean action_result_after = action____specifier_qualifier_list__specifier_qualifier_list__type_qualifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [specifier_qualifier_list] --> [specifier_qualifier_list type_qualifier] returns false.");
                    return false;
                }
            }
        }

        return action____specifier_qualifier_list__default_semantic_action(node);
    }

    protected boolean process_statement(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __labeled_statement__)
            {
                boolean action_result_before = action____statement__labeled_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_labeled_statement(child_1);

                boolean action_result_after = action____statement__labeled_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [labeled_statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __compound_statement__)
            {
                boolean action_result_before = action____statement__compound_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_compound_statement(child_1);

                boolean action_result_after = action____statement__compound_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [compound_statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __expression_statement__)
            {
                boolean action_result_before = action____statement__expression_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_expression_statement(child_1);

                boolean action_result_after = action____statement__expression_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [expression_statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __selection_statement__)
            {
                boolean action_result_before = action____statement__selection_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_selection_statement(child_1);

                boolean action_result_after = action____statement__selection_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [selection_statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __iteration_statement__)
            {
                boolean action_result_before = action____statement__iteration_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_iteration_statement(child_1);

                boolean action_result_after = action____statement__iteration_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [iteration_statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __jump_statement__)
            {
                boolean action_result_before = action____statement__jump_statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_jump_statement(child_1);

                boolean action_result_after = action____statement__jump_statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [jump_statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __simple_declaration__)
            {
                boolean action_result_before = action____statement__simple_declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_simple_declaration(child_1);

                boolean action_result_after = action____statement__simple_declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement] --> [simple_declaration] returns false.");
                    return false;
                }
            }
        }

        return action____statement__default_semantic_action(node);
    }

    protected boolean process_statement_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __statement__)
            {
                boolean action_result_before = action____statement_list__statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_statement(child_1);

                boolean action_result_after = action____statement_list__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement_list] --> [statement] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __statement_list__
               &&child_2_type == __statement__)
            {
                boolean action_result_before = action____statement_list__statement_list__statement(node, __ACTION_BEFORE__);

                boolean result_1 = process_statement_list(child_1);
                boolean result_2 = process_statement(child_2);

                boolean action_result_after = action____statement_list__statement_list__statement(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [statement_list] --> [statement_list statement] returns false.");
                    return false;
                }
            }
        }

        return action____statement_list__default_semantic_action(node);
    }

    protected boolean process_storage_class_specifier(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __AUTO__)
            {
                boolean action_result = action____storage_class_specifier__AUTO(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [storage_class_specifier] --> [AUTO] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __EXTERN__)
            {
                boolean action_result = action____storage_class_specifier__EXTERN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [storage_class_specifier] --> [EXTERN] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __REGISTER__)
            {
                boolean action_result = action____storage_class_specifier__REGISTER(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [storage_class_specifier] --> [REGISTER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __STATIC__)
            {
                boolean action_result = action____storage_class_specifier__STATIC(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [storage_class_specifier] --> [STATIC] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __TYPEDEF__)
            {
                boolean action_result = action____storage_class_specifier__TYPEDEF(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [storage_class_specifier] --> [TYPEDEF] returns false.");
                    return false;
                }
            }
        }

        return action____storage_class_specifier__default_semantic_action(node);
    }

    protected boolean process_struct_declaration(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __specifier_qualifier_list__
               &&child_2_type == __struct_declarator_list__
               &&child_3_type == __SEMICOLON__)
            {
                boolean action_result_before = action____struct_declaration__specifier_qualifier_list__struct_declarator_list__SEMICOLON(node, __ACTION_BEFORE__);

                boolean result_1 = process_specifier_qualifier_list(child_1);
                boolean result_2 = process_struct_declarator_list(child_2);

                boolean action_result_after = action____struct_declaration__specifier_qualifier_list__struct_declarator_list__SEMICOLON(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declaration] --> [specifier_qualifier_list struct_declarator_list ';'] returns false.");
                    return false;
                }
            }
        }

        return action____struct_declaration__default_semantic_action(node);
    }

    protected boolean process_struct_declaration_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __struct_declaration__)
            {
                boolean action_result_before = action____struct_declaration_list__struct_declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_declaration(child_1);

                boolean action_result_after = action____struct_declaration_list__struct_declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declaration_list] --> [struct_declaration] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __struct_declaration_list__
               &&child_2_type == __struct_declaration__)
            {
                boolean action_result_before = action____struct_declaration_list__struct_declaration_list__struct_declaration(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_declaration_list(child_1);
                boolean result_2 = process_struct_declaration(child_2);

                boolean action_result_after = action____struct_declaration_list__struct_declaration_list__struct_declaration(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declaration_list] --> [struct_declaration_list struct_declaration] returns false.");
                    return false;
                }
            }
        }

        return action____struct_declaration_list__default_semantic_action(node);
    }

    protected boolean process_struct_declarator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __declarator__)
            {
                boolean action_result_before = action____struct_declarator__declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_declarator(child_1);

                boolean action_result_after = action____struct_declarator__declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declarator] --> [declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __COLON__
               &&child_2_type == __constant_expression__)
            {
                boolean action_result_before = action____struct_declarator__COLON__constant_expression(node, __ACTION_BEFORE__);

                boolean result_2 = process_constant_expression(child_2);

                boolean action_result_after = action____struct_declarator__COLON__constant_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declarator] --> [':' constant_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __declarator__
               &&child_2_type == __COLON__
               &&child_3_type == __constant_expression__)
            {
                boolean action_result_before = action____struct_declarator__declarator__COLON__constant_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_declarator(child_1);
                boolean result_3 = process_constant_expression(child_3);

                boolean action_result_after = action____struct_declarator__declarator__COLON__constant_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declarator] --> [declarator ':' constant_expression] returns false.");
                    return false;
                }
            }
        }

        return action____struct_declarator__default_semantic_action(node);
    }

    protected boolean process_struct_declarator_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __struct_declarator__)
            {
                boolean action_result_before = action____struct_declarator_list__struct_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_declarator(child_1);

                boolean action_result_after = action____struct_declarator_list__struct_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declarator_list] --> [struct_declarator] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 3)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();

            if (child_1_type == __struct_declarator_list__
               &&child_2_type == __COMMA__
               &&child_3_type == __struct_declarator__)
            {
                boolean action_result_before = action____struct_declarator_list__struct_declarator_list__COMMA__struct_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_declarator_list(child_1);
                boolean result_3 = process_struct_declarator(child_3);

                boolean action_result_after = action____struct_declarator_list__struct_declarator_list__COMMA__struct_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_declarator_list] --> [struct_declarator_list ',' struct_declarator] returns false.");
                    return false;
                }
            }
        }

        return action____struct_declarator_list__default_semantic_action(node);
    }

    protected boolean process_struct_or_union(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __STRUCT__)
            {
                boolean action_result = action____struct_or_union__STRUCT(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union] --> [STRUCT] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __UNION__)
            {
                boolean action_result = action____struct_or_union__UNION(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union] --> [UNION] returns false.");
                    return false;
                }
            }
        }

        return action____struct_or_union__default_semantic_action(node);
    }

    protected boolean process_struct_or_union_specifier(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __struct_or_union__
               &&child_2_type == __IDENTIFIER__
               &&child_3_type == __LEFT_BRACE__
               &&child_4_type == __struct_declaration_list__
               &&child_5_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____struct_or_union_specifier__struct_or_union__IDENTIFIER__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_or_union(child_1);
                boolean result_4 = process_struct_declaration_list(child_4);

                boolean action_result_after = action____struct_or_union_specifier__struct_or_union__IDENTIFIER__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true && result_4 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union_specifier] --> [struct_or_union IDENTIFIER '{' struct_declaration_list '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 5)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();
            GeneralSyntaxNode	child_5 = (GeneralSyntaxNode)(node.getChild(4));
            int	child_5_type = child_5.getTypeCode();

            if (child_1_type == __struct_or_union__
               &&child_2_type == __USERTYPE__
               &&child_3_type == __LEFT_BRACE__
               &&child_4_type == __struct_declaration_list__
               &&child_5_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____struct_or_union_specifier__struct_or_union__USERTYPE__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_or_union(child_1);
                boolean result_4 = process_struct_declaration_list(child_4);

                boolean action_result_after = action____struct_or_union_specifier__struct_or_union__USERTYPE__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && true && result_4 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union_specifier] --> [struct_or_union USERTYPE '{' struct_declaration_list '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __struct_or_union__
               &&child_2_type == __LEFT_BRACE__
               &&child_3_type == __struct_declaration_list__
               &&child_4_type == __RIGHT_BRACE__)
            {
                boolean action_result_before = action____struct_or_union_specifier__struct_or_union__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_or_union(child_1);
                boolean result_3 = process_struct_declaration_list(child_3);

                boolean action_result_after = action____struct_or_union_specifier__struct_or_union__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union_specifier] --> [struct_or_union '{' struct_declaration_list '}'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __struct_or_union__
               &&child_2_type == __IDENTIFIER__)
            {
                boolean action_result_before = action____struct_or_union_specifier__struct_or_union__IDENTIFIER(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_or_union(child_1);

                boolean action_result_after = action____struct_or_union_specifier__struct_or_union__IDENTIFIER(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union_specifier] --> [struct_or_union IDENTIFIER] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __struct_or_union__
               &&child_2_type == __USERTYPE__)
            {
                boolean action_result_before = action____struct_or_union_specifier__struct_or_union__USERTYPE(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_or_union(child_1);

                boolean action_result_after = action____struct_or_union_specifier__struct_or_union__USERTYPE(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [struct_or_union_specifier] --> [struct_or_union USERTYPE] returns false.");
                    return false;
                }
            }
        }

        return action____struct_or_union_specifier__default_semantic_action(node);
    }

    protected boolean process_translation_unit(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __declaration_list__)
            {
                boolean action_result_before = action____translation_unit__declaration_list(node, __ACTION_BEFORE__);

                boolean result_1 = process_declaration_list(child_1);

                boolean action_result_after = action____translation_unit__declaration_list(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [translation_unit] --> [declaration_list] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 0)
        {
            boolean action_result = action____translation_unit__empty(node);
            if (action_result == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return action____translation_unit__default_semantic_action(node);
    }

    protected boolean process_type_name(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __specifier_qualifier_list__)
            {
                boolean action_result_before = action____type_name__specifier_qualifier_list(node, __ACTION_BEFORE__);

                boolean result_1 = process_specifier_qualifier_list(child_1);

                boolean action_result_after = action____type_name__specifier_qualifier_list(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_name] --> [specifier_qualifier_list] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __specifier_qualifier_list__
               &&child_2_type == __abstract_declarator__)
            {
                boolean action_result_before = action____type_name__specifier_qualifier_list__abstract_declarator(node, __ACTION_BEFORE__);

                boolean result_1 = process_specifier_qualifier_list(child_1);
                boolean result_2 = process_abstract_declarator(child_2);

                boolean action_result_after = action____type_name__specifier_qualifier_list__abstract_declarator(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_name] --> [specifier_qualifier_list abstract_declarator] returns false.");
                    return false;
                }
            }
        }

        return action____type_name__default_semantic_action(node);
    }

    protected boolean process_type_qualifier(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __CONST__)
            {
                boolean action_result = action____type_qualifier__CONST(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_qualifier] --> [CONST] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __VOLATILE__)
            {
                boolean action_result = action____type_qualifier__VOLATILE(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_qualifier] --> [VOLATILE] returns false.");
                    return false;
                }
            }
        }

        return action____type_qualifier__default_semantic_action(node);
    }

    protected boolean process_type_qualifier_list(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __type_qualifier__)
            {
                boolean action_result_before = action____type_qualifier_list__type_qualifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_type_qualifier(child_1);

                boolean action_result_after = action____type_qualifier_list__type_qualifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_qualifier_list] --> [type_qualifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __type_qualifier_list__
               &&child_2_type == __type_qualifier__)
            {
                boolean action_result_before = action____type_qualifier_list__type_qualifier_list__type_qualifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_type_qualifier_list(child_1);
                boolean result_2 = process_type_qualifier(child_2);

                boolean action_result_after = action____type_qualifier_list__type_qualifier_list__type_qualifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_qualifier_list] --> [type_qualifier_list type_qualifier] returns false.");
                    return false;
                }
            }
        }

        return action____type_qualifier_list__default_semantic_action(node);
    }

    protected boolean process_type_specifier(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __VOID__)
            {
                boolean action_result = action____type_specifier__VOID(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [VOID] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __CHAR__)
            {
                boolean action_result = action____type_specifier__CHAR(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [CHAR] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __SHORT__)
            {
                boolean action_result = action____type_specifier__SHORT(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [SHORT] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __INT__)
            {
                boolean action_result = action____type_specifier__INT(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [INT] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __LONG__)
            {
                boolean action_result = action____type_specifier__LONG(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [LONG] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __FLOAT__)
            {
                boolean action_result = action____type_specifier__FLOAT(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [FLOAT] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __DOUBLE__)
            {
                boolean action_result = action____type_specifier__DOUBLE(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [DOUBLE] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __SIGNED__)
            {
                boolean action_result = action____type_specifier__SIGNED(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [SIGNED] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __UNSIGNED__)
            {
                boolean action_result = action____type_specifier__UNSIGNED(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [UNSIGNED] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __struct_or_union_specifier__)
            {
                boolean action_result_before = action____type_specifier__struct_or_union_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_struct_or_union_specifier(child_1);

                boolean action_result_after = action____type_specifier__struct_or_union_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [struct_or_union_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __enum_specifier__)
            {
                boolean action_result_before = action____type_specifier__enum_specifier(node, __ACTION_BEFORE__);

                boolean result_1 = process_enum_specifier(child_1);

                boolean action_result_after = action____type_specifier__enum_specifier(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [enum_specifier] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __USERTYPE__)
            {
                boolean action_result = action____type_specifier__USERTYPE(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [USERTYPE] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __VA_LIST__)
            {
                boolean action_result = action____type_specifier__VA_LIST(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [VA_LIST] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __WCHAR_T__)
            {
                boolean action_result = action____type_specifier__WCHAR_T(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [type_specifier] --> [WCHAR_T] returns false.");
                    return false;
                }
            }
        }

		return action____type_specifier__default_semantic_action(node);
    }

    protected boolean process_unary_expression(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __postfix_expression__)
            {
                boolean action_result_before = action____unary_expression__postfix_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_postfix_expression(child_1);

                boolean action_result_after = action____unary_expression__postfix_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_expression] --> [postfix_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __INC_OP__
               &&child_2_type == __unary_expression__)
            {
                boolean action_result_before = action____unary_expression__INC_OP__unary_expression(node, __ACTION_BEFORE__);

                boolean result_2 = process_unary_expression(child_2);

                boolean action_result_after = action____unary_expression__INC_OP__unary_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_expression] --> [INC_OP unary_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __DEC_OP__
               &&child_2_type == __unary_expression__)
            {
                boolean action_result_before = action____unary_expression__DEC_OP__unary_expression(node, __ACTION_BEFORE__);

                boolean result_2 = process_unary_expression(child_2);

                boolean action_result_after = action____unary_expression__DEC_OP__unary_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_expression] --> [DEC_OP unary_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __unary_operator__
               &&child_2_type == __cast_expression__)
            {
                boolean action_result_before = action____unary_expression__unary_operator__cast_expression(node, __ACTION_BEFORE__);

                boolean result_1 = process_unary_operator(child_1);
                boolean result_2 = process_cast_expression(child_2);

                boolean action_result_after = action____unary_expression__unary_operator__cast_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (result_1 && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_expression] --> [unary_operator cast_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 2)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();

            if (child_1_type == __SIZEOF__
               &&child_2_type == __unary_expression__)
            {
                boolean action_result_before = action____unary_expression__SIZEOF__unary_expression(node, __ACTION_BEFORE__);

                boolean result_2 = process_unary_expression(child_2);

                boolean action_result_after = action____unary_expression__SIZEOF__unary_expression(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && result_2)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_expression] --> [SIZEOF unary_expression] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 4)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();
            GeneralSyntaxNode	child_2 = (GeneralSyntaxNode)(node.getChild(1));
            int	child_2_type = child_2.getTypeCode();
            GeneralSyntaxNode	child_3 = (GeneralSyntaxNode)(node.getChild(2));
            int	child_3_type = child_3.getTypeCode();
            GeneralSyntaxNode	child_4 = (GeneralSyntaxNode)(node.getChild(3));
            int	child_4_type = child_4.getTypeCode();

            if (child_1_type == __SIZEOF__
               &&child_2_type == __LEFT_PARENTHESIS__
               &&child_3_type == __type_name__
               &&child_4_type == __RIGHT_PARENTHESIS__)
            {
                boolean action_result_before = action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS(node, __ACTION_BEFORE__);

                boolean result_3 = process_type_name(child_3);

                boolean action_result_after = action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS(node, __ACTION_AFTER__);

                if ((action_result_before && action_result_after) == false)
                {
                    return false;
                }
                if (true && true && result_3 && true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_expression] --> [SIZEOF '(' type_name ')'] returns false.");
                    return false;
                }
            }
        }

        return action____unary_expression__default_semantic_action(node);
    }

    protected boolean process_unary_operator(GeneralSyntaxNode node)
    {
        int num_of_children = node.numOfChildren();

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __AMPERSAND__)
            {
                boolean action_result = action____unary_operator__AMPERSAND(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_operator] --> ['&'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __ASTERISK__)
            {
                boolean action_result = action____unary_operator__ASTERISK(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_operator] --> ['*'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __PLUS_SIGN__)
            {
                boolean action_result = action____unary_operator__PLUS_SIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_operator] --> ['+'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __MINUS_SIGN__)
            {
                boolean action_result = action____unary_operator__MINUS_SIGN(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_operator] --> ['-'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __TILDE__)
            {
                boolean action_result = action____unary_operator__TILDE(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_operator] --> ['~'] returns false.");
                    return false;
                }
            }
        }

        if (num_of_children == 1)
        {
            GeneralSyntaxNode	child_1 = (GeneralSyntaxNode)(node.getChild(0));
            int	child_1_type = child_1.getTypeCode();

            if (child_1_type == __BANG__)
            {
                boolean action_result = action____unary_operator__BANG(node);

                if (action_result == false)
                {
                    return false;
                }
                if (true)
                {
                    return true;
                }
                else
                {
                    System.out.println("CAUTION: [unary_operator] --> ['!'] returns false.");
                    return false;
                }
            }
        }

        return action____unary_operator__default_semantic_action(node);
    }

    abstract protected boolean action____abstract_declarator__pointer(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____abstract_declarator__direct_abstract_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____abstract_declarator__pointer__direct_abstract_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____abstract_declarator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____additive_expression__multiplicative_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____additive_expression__additive_expression__PLUS_SIGN__multiplicative_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____additive_expression__additive_expression__MINUS_SIGN__multiplicative_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____additive_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____and_expression__equality_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____and_expression__and_expression__AMPERSAND__equality_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____and_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____argument_expression_list__assignment_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____argument_expression_list__argument_expression_list__COMMA__assignment_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____argument_expression_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_expression__conditional_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____assignment_expression__unary_expression__assignment_operator__assignment_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____assignment_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__EQUAL_SIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__MUL_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__DIV_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__MOD_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__ADD_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__SUB_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__LEFT_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__RIGHT_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__AND_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__XOR_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__OR_ASSIGN(GeneralSyntaxNode node);
    abstract protected boolean action____assignment_operator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____cast_expression__unary_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____cast_expression__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS__cast_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____cast_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____compound_statement__LEFT_BRACE__RIGHT_BRACE(GeneralSyntaxNode node);
    abstract protected boolean action____compound_statement__LEFT_BRACE__statement_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____compound_statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____conditional_expression__logical_or_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____conditional_expression__logical_or_expression__QUESTION_MARK__expression__COLON__conditional_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____conditional_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____constant_expression__conditional_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____constant_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____declaration__function_definition(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration__simple_declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration__SEMICOLON(GeneralSyntaxNode node);
    abstract protected boolean action____declaration__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____declaration_list__declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_list__declaration_list__declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____declaration_specifiers__storage_class_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_specifiers__declaration_specifiers__storage_class_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_specifiers__type_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_specifiers__declaration_specifiers__type_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_specifiers__type_qualifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_specifiers__declaration_specifiers__type_qualifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declaration_specifiers__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____declarator__pointer__direct_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declarator__direct_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____declarator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__abstract_declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node);
    abstract protected boolean action____direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node);
    abstract protected boolean action____direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__direct_abstract_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_abstract_declarator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____direct_declarator__IDENTIFIER(GeneralSyntaxNode node);
    abstract protected boolean action____direct_declarator__LEFT_PARENTHESIS__declarator__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_declarator__direct_declarator__LEFT_BRACKET__constant_expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_declarator__direct_declarator__LEFT_BRACKET__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__parameter_type_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_declarator__direct_declarator__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____direct_declarator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____enum_specifier__ENUM__LEFT_BRACE__enumerator_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____enum_specifier__ENUM__IDENTIFIER__LEFT_BRACE__enumerator_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____enum_specifier__ENUM__IDENTIFIER(GeneralSyntaxNode node);
    abstract protected boolean action____enum_specifier__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____enumerator__IDENTIFIER(GeneralSyntaxNode node);
    abstract protected boolean action____enumerator__IDENTIFIER__EQUAL_SIGN__constant_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____enumerator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____enumerator_list__enumerator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____enumerator_list__enumerator_list__COMMA__enumerator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____enumerator_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____equality_expression__relational_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____equality_expression__equality_expression__EQ_OP__relational_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____equality_expression__equality_expression__NE_OP__relational_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____equality_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____exclusive_or_expression__and_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____exclusive_or_expression__exclusive_or_expression__CARET__and_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____exclusive_or_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____expression__assignment_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____expression__expression__COMMA__assignment_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____expression_statement__SEMICOLON(GeneralSyntaxNode node);
    abstract protected boolean action____expression_statement__expression__SEMICOLON(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____expression_statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____function_definition__declaration_specifiers__declarator__compound_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____function_definition__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____inclusive_or_expression__exclusive_or_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____inclusive_or_expression__inclusive_or_expression__VERTICAL_BAR__exclusive_or_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____inclusive_or_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____init_declarator__declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____init_declarator__declarator__EQUAL_SIGN__initializer(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____init_declarator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____init_declarator_list__init_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____init_declarator_list__init_declarator_list__COMMA__init_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____init_declarator_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____initializer__assignment_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____initializer__LEFT_BRACE__initializer_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____initializer__LEFT_BRACE__initializer_list__COMMA__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____initializer__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____initializer_list__initializer(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____initializer_list__initializer_list__COMMA__initializer(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____initializer_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____iteration_statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____iteration_statement__DO__statement__WHILE__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__SEMICOLON(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____iteration_statement__FOR__LEFT_PARENTHESIS__expression_statement__expression_statement__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____iteration_statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____jump_statement__GOTO__IDENTIFIER__SEMICOLON(GeneralSyntaxNode node);
    abstract protected boolean action____jump_statement__CONTINUE__SEMICOLON(GeneralSyntaxNode node);
    abstract protected boolean action____jump_statement__BREAK__SEMICOLON(GeneralSyntaxNode node);
    abstract protected boolean action____jump_statement__RETURN__SEMICOLON(GeneralSyntaxNode node);
    abstract protected boolean action____jump_statement__RETURN__expression__SEMICOLON(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____jump_statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____labeled_statement__IDENTIFIER__COLON__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____labeled_statement__CASE__constant_expression__COLON__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____labeled_statement__DEFAULT__COLON__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____labeled_statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____logical_and_expression__inclusive_or_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____logical_and_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____logical_or_expression__logical_and_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____logical_or_expression__logical_or_expression__OR_OP__logical_and_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____logical_or_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____multiplicative_expression__cast_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____multiplicative_expression__multiplicative_expression__ASTERISK__cast_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____multiplicative_expression__multiplicative_expression__SLASH__cast_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____multiplicative_expression__multiplicative_expression__PERCENT_SIGN__cast_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____multiplicative_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____parameter_declaration__declaration_specifiers__declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_declaration__declaration_specifiers__abstract_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_declaration__declaration_specifiers(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_declaration__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____parameter_list__parameter_declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_list__parameter_list__COMMA__parameter_declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____parameter_type_list__parameter_list(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_type_list__parameter_list__COMMA__ELLIPSIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____parameter_type_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____pointer__ASTERISK(GeneralSyntaxNode node);
    abstract protected boolean action____pointer__ASTERISK__type_qualifier_list(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____pointer__ASTERISK__pointer(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____pointer__ASTERISK__type_qualifier_list__pointer(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____pointer__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____postfix_expression__primary_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__LEFT_BRACKET__expression__RIGHT_BRACKET(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__LEFT_PARENTHESIS__argument_expression_list__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__DOT__IDENTIFIER(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__PTR_OP__IDENTIFIER(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__INC_OP(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__postfix_expression__DEC_OP(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____postfix_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____primary_expression__IDENTIFIER(GeneralSyntaxNode node);
    abstract protected boolean action____primary_expression__CONSTANT(GeneralSyntaxNode node);
    abstract protected boolean action____primary_expression__STRING_LITERAL(GeneralSyntaxNode node);
    abstract protected boolean action____primary_expression__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____primary_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____relational_expression__shift_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____relational_expression__relational_expression__LEFT_ANGLE_BRACKET__shift_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____relational_expression__relational_expression__RIGHT_ANGLE_BRACKET__shift_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____relational_expression__relational_expression__LE_OP__shift_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____relational_expression__relational_expression__GE_OP__shift_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____relational_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____selection_statement__IF__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement__ELSE__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____selection_statement__SWITCH__LEFT_PARENTHESIS__expression__RIGHT_PARENTHESIS__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____selection_statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____shift_expression__additive_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____shift_expression__shift_expression__LEFT_OP__additive_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____shift_expression__shift_expression__RIGHT_OP__additive_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____shift_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____simple_declaration__declaration_specifiers__SEMICOLON(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____simple_declaration__declaration_specifiers__init_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____simple_declaration__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____specifier_qualifier_list__type_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____specifier_qualifier_list__specifier_qualifier_list__type_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____specifier_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____specifier_qualifier_list__specifier_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____specifier_qualifier_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____statement__labeled_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__compound_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__expression_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__selection_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__iteration_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__jump_statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__simple_declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____statement_list__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement_list__statement_list__statement(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____statement_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____storage_class_specifier__AUTO(GeneralSyntaxNode node);
    abstract protected boolean action____storage_class_specifier__EXTERN(GeneralSyntaxNode node);
    abstract protected boolean action____storage_class_specifier__REGISTER(GeneralSyntaxNode node);
    abstract protected boolean action____storage_class_specifier__STATIC(GeneralSyntaxNode node);
    abstract protected boolean action____storage_class_specifier__TYPEDEF(GeneralSyntaxNode node);
    abstract protected boolean action____storage_class_specifier__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____struct_declaration__specifier_qualifier_list__struct_declarator_list__SEMICOLON(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declaration__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____struct_declaration_list__struct_declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declaration_list__struct_declaration_list__struct_declaration(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declaration_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____struct_declarator__declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declarator__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declarator__declarator__COLON__constant_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declarator__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____struct_declarator_list__struct_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declarator_list__struct_declarator_list__COMMA__struct_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_declarator_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____struct_or_union__STRUCT(GeneralSyntaxNode node);
    abstract protected boolean action____struct_or_union__UNION(GeneralSyntaxNode node);
    abstract protected boolean action____struct_or_union__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____struct_or_union_specifier__struct_or_union__IDENTIFIER__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_or_union_specifier__struct_or_union__USERTYPE__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_or_union_specifier__struct_or_union__LEFT_BRACE__struct_declaration_list__RIGHT_BRACE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_or_union_specifier__struct_or_union__IDENTIFIER(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_or_union_specifier__struct_or_union__USERTYPE(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____struct_or_union_specifier__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____translation_unit__declaration_list(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____translation_unit__empty(GeneralSyntaxNode node);
    abstract protected boolean action____translation_unit__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____type_name__specifier_qualifier_list(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____type_name__specifier_qualifier_list__abstract_declarator(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____type_name__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____type_qualifier__CONST(GeneralSyntaxNode node);
    abstract protected boolean action____type_qualifier__VOLATILE(GeneralSyntaxNode node);
    abstract protected boolean action____type_qualifier__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____type_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____type_qualifier_list__type_qualifier_list__type_qualifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____type_qualifier_list__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__VOID(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__CHAR(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__SHORT(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__INT(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__LONG(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__FLOAT(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__DOUBLE(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__SIGNED(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__UNSIGNED(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__struct_or_union_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____type_specifier__enum_specifier(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____type_specifier__USERTYPE(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__VA_LIST(GeneralSyntaxNode node);
	abstract protected boolean action____type_specifier__WCHAR_T(GeneralSyntaxNode node);
    abstract protected boolean action____type_specifier__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____unary_expression__postfix_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____unary_expression__INC_OP__unary_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____unary_expression__DEC_OP__unary_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____unary_expression__unary_operator__cast_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____unary_expression__SIZEOF__unary_expression(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____unary_expression__SIZEOF__LEFT_PARENTHESIS__type_name__RIGHT_PARENTHESIS(GeneralSyntaxNode node, int __action_status__);
    abstract protected boolean action____unary_expression__default_semantic_action(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__AMPERSAND(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__ASTERISK(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__PLUS_SIGN(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__MINUS_SIGN(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__TILDE(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__BANG(GeneralSyntaxNode node);
    abstract protected boolean action____unary_operator__default_semantic_action(GeneralSyntaxNode node);

}


