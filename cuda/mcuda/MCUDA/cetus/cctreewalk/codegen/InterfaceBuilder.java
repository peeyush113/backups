
/*
This is the improved version for Interface Generator, it generates:
CCTypeEnum.java
CCTypeHash.java

generation of the tree walker is now in TreeWalkerBuilder.java 
in order to provide more clear separation of two different missions.
*/

import java.lang.*;
import java.io.*;
import java.util.*;

public class InterfaceBuilder
{
	BufferedReader	grammar_input;
	BufferedWriter	enum_output;
	BufferedWriter	hash_output;

	public static void main(String[] args) 
	{
		InterfaceBuilder	app = new InterfaceBuilder(args);
		app.run();
	}

	public InterfaceBuilder(String[] args)
	{		
		if (args.length < 1)
		{
			printUsage();
			System.exit(1);
		}

		System.out.println("\nInput Grammar File: " + args[0] + "\nOutput Java File: CCTypeEnum.java, CCTypeHash.java\n");

		try
		{
			grammar_input	= new BufferedReader(new FileReader(args[0]));
			enum_output		= new BufferedWriter(new FileWriter("CCTypeEnum.java"));
			hash_output		= new BufferedWriter(new FileWriter("CCTypeHash.java"));

			if (grammar_input == null)
			{
				System.out.println("Unable to open input file: " + args[0]);
				System.exit(1);
			}
			if (enum_output == null)
			{
				System.out.println("Unable to open enum_output file: CCTypeEnum.java");
				System.exit(1);
			}
			if (hash_output == null)
			{
				System.out.println("Unable to open hash_output file: CCTypeHash.java");
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
		ArrayList	list_of_nonterminal_types = new ArrayList(150);

		int		enum_coutner = 0;	//used to assign unique numbers for the types

		//read the grammar rules in and add the LHS into the interface 
		String enum_src = "\n/*\nThis interface gives an int value (1 ~ 999) for each non-terminal in the grammar file.\nValues >= 1000 are simple types (e.g. char, int, float, etc.)\nValues >= 2000 are operators, signs, etc. (e.g. +, -, etc.)\n*/\n\n";
		enum_src		+= "import java.lang.*;\n\n" + "public interface CCTypeEnum\n{\n";

		String hash_src = "\n/*\nThis hashtable gives a mapping from name (String) to its type code.\n*/\n\n";
		hash_src		+= "import java.lang.*;\nimport java.util.*;\n\npublic class CCTypeHash implements CCTypeEnum\n{\n    Hashtable   name2enum;\n\n    public int getEnumValue(String _name)\n    {\n        Integer value = (Integer)name2enum.get(_name);\n        if (value == null)\n        {\n            if (isStringLiteral(_name) == true)\n            {\n                return __STRING_LITERAL__;\n            }\n            else if (isConstant(_name) == true)\n            {\n                return __CONSTANT__;\n            }\n            else if (isIdentifier(_name) == true)\n            {\n                return __IDENTIFIER__;\n            }\n            else\n            {\n                return -1;\n            }\n        }\n        return value.intValue();\n    }\n\n    public CCTypeHash()\n    {\n        name2enum = new Hashtable();\n\n";

		try
		{
			enum_src	+= "    public static final int __UNKNOWN_TYPE__ = -1;\n";
			enum_src	+= "    public static final int __" + "ambiguity" + "__ = " + enum_coutner + ";\n\n";

			hash_src	+= "        name2enum.put(new String(\"" + "ambiguity" + "\"), new Integer(__" + "ambiguity" + "__));\n\n";

			enum_coutner ++;

			String line;

			while ((line = grammar_input.readLine()) != null)
			{
				line = line.trim();
				if (line.length() > 0)
				{
					if (line.endsWith(":"))
					{
						String typename = line.substring(0, line.length()-1);

						list_of_nonterminal_types.add(typename);
					}
				}
			}

			int num_types			= list_of_nonterminal_types.size();
			Object[] array_of_types = list_of_nonterminal_types.toArray();
			Arrays.sort(array_of_types);

			for (int i=0; i<num_types; i++)
			{
				String typename = (String)array_of_types[i];
				enum_src		+= "    public static final int __" + typename + "__ = " + enum_coutner + ";\n";
				hash_src		+= "        name2enum.put(new String(\"" + typename + "\"), new Integer(__" + typename + "__));\n";

				enum_coutner ++;
			}

			//now need to add the keywords, simple types, etc.
			enum_src += enum_addKeywords();
			hash_src += hash_addKeywords();

			enum_src += "\n}";
            hash_src += "    }\n\n";

			hash_src += "    protected boolean isStringLiteral(String _str)\n    {\n        String str_exp = \"L?\\\"(\\\\.|[^\\\"])*\\\"\";\n\n        if (_str.matches(str_exp) == true)\n        {\n            return true;\n        }\n        else\n        {\n            return false;\n        }\n    }\n\n";			
			hash_src += "    protected boolean isConstant(String _str)\n    {\n        String	D = \"[0-9]\";\n        String	L = \"[a-zA-Z_]\";\n        String  H = \"[a-fA-F0-9]\";\n        String  E = \"[Ee][+-]?(\" + D + \")+\";\n        String  FS	= \"(f|F|l|L)\";\n        String  IS	= \"(u|U|l|L)*\";\n\n        String const1 = \"0[xX](\" + H + \")+(\" + IS + \")?\";\n        String const2 = \"0(\" + D + \")+(\" + IS + \")?\";\n        String const3 = \"(\" + D + \")+(\" + IS+ \")?\";\n        String const4 = L + \"?'(\\\\.|[^\\\\'])+'\";	//weird\n        String const5 = \"(\" + D + \")+(\" + E + \")(\" + FS + \")?\";\n        String const6 = \"(\" + D + \")*.(\" + D + \")+(\" + E + \")?\" + FS + \"?\";\n        String const7 = \"(\" + D + \")+.(\" + D + \")*(\" + E + \")?\" + FS + \"?\";\n\n        String num_exp = const1 + \"|\" + const2 + \"|\" + const3 + \"|\" + const4 + \"|\" + const5 + \"|\" + const6 + \"|\" + const7;\n\n        if (_str.matches(num_exp) == true)\n        {\n            return true;\n        }\n        else\n        {\n            return false;\n        }\n    }\n\n";
			hash_src += "    protected boolean isIdentifier(String _str)\n    {\n        String	D = \"[0-9]\";\n        String	L = \"[a-zA-Z_]\";\n        String id_exp = \"(\" + L + \")((\" + L + \")|(\" + D + \"))*\";\n\n        if (_str.matches(id_exp) == true)\n        {\n            return true;\n        }\n        else\n        {\n            return false;\n        }\n    }\n\n";
			hash_src += "}\n";
			
			writeMessage(enum_output, enum_src);
		    writeMessage(hash_output, hash_src);
		}
		catch (IOException err)
		{
			System.out.println("I/O Error in run(): " + err.toString());
			System.exit(1);			
		}

		end();
	}

	//this part is done manually, so look out for bugs :(
	protected String enum_addKeywords()
	{
		String	src = "\n";
		int		enum_counter = 1000;

		String	token_sequence = "IDENTIFIER CONSTANT STRING_LITERAL SIZEOF PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN TYPEDEF EXTERN STATIC AUTO REGISTER CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID STRUCT UNION ENUM ELLIPSIS CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN "; //ANSI C
		token_sequence += "ASM CBOOL CATCH CLASS CONST_CAST DELETE DYNAMIC_CAST EXPLICIT EXPORT CFALSE FRIEND INLINE MUTABLE NAMESPACE NEW OPERATOR PRIVATE PROTECTED PUBLIC REINTERPRET_CAST STATIC_CAST TEMPLATE THIS THROW CTRUE TRY TYPEID TYPENAME USING VIRTUAL WCHAR_T SCOPE DOT_MEMBER PTR_MEMBER "; //beyond ANSI C
		token_sequence += "ALIGNOF ATTRIBUTE COMPLEX EXTENSION IMAGPART REALPART RESTRICT TYPEOF VA_ARG "; //gcc extensions
		token_sequence += "BEGIN_TEMPLATE ";	//special token
		token_sequence += "USERTYPE VA_LIST";

		//add all the symbols (+, -, *, /, etc.)
		//refer to CCSymbol2Name for more details
		String signs = "TILDE BANG PERCENT_SIGN CARET AMPERSAND SHARP DOLLAR_SIGN BACKTICK AT_SIGN ";
		signs += "LEFT_PARENTHESIS RIGHT_PARENTHESIS LEFT_BRACKET RIGHT_BRACKET LEFT_ANGLE_BRACKET RIGHT_ANGLE_BRACKET LEFT_BRACE RIGHT_BRACE ";
		signs += "PLUS_SIGN MINUS_SIGN ASTERISK SLASH EQUAL_SIGN ";
		signs += "DOT COMMA VERTICAL_BAR COLON SEMICOLON QUESTION_MARK ";

		StringTokenizer st = new StringTokenizer(token_sequence);

		while (st.hasMoreTokens() == true)
		{
			src += "    public static final int __" + st.nextToken() + "__ = " + enum_counter + ";\n";
			enum_counter ++;
		}
		src += "\n";

		enum_counter = 2000;
		st = new StringTokenizer(signs);
		while (st.hasMoreTokens() == true)
		{
			src += "    public static final int __" + st.nextToken() + "__ = " + enum_counter + ";\n";
			enum_counter ++;
		}

		return src;
	}

	protected String hash_addKeywords()
	{
/*haven't got a good solution for class->method() or class.method()*/
		String	src = "\n";
		int		enum_counter = 1000;
		String	leave_blank = "__blank__";

		//ANSI C tokens
		String	token_sequence = "IDENTIFIER __blank__ CONSTANT __blank__ STRING_LITERAL __blank__ ";
		token_sequence += "SIZEOF sizeof PTR_OP -> INC_OP ++ DEC_OP -- ";
		token_sequence += "LEFT_OP << RIGHT_OP >> LE_OP <= GE_OP >= EQ_OP == NE_OP != NE_OP not_eq AND_OP && AND_OP and OR_OP || OR_OP or ";
		token_sequence += "MUL_ASSIGN *= DIV_ASSIGN /= MOD_ASSIGN %= ADD_ASSIGN += SUB_ASSIGN -= LEFT_ASSIGN <<= RIGHT_ASSIGN >>= AND_ASSIGN &= AND_ASSIGN and_eq XOR_ASSIGN ^= XOR_ASSIGN xor_eq OR_ASSIGN |= OR_ASSIGN or_eq ";
		token_sequence += "TYPEDEF typedef EXTERN extern STATIC static AUTO auto REGISTER register ";
		token_sequence += "CHAR char SHORT short INT int LONG long SIGNED signed SIGNED __signed SIGNED __signed__ UNSIGNED unsigned FLOAT float DOUBLE double CONST const CONST __const__ CONST __const VOLATILE volatile VOLATILE __volatile VOLATILE __volatile__ VOID void STRUCT struct UNION union ENUM enum ELLIPSIS ... ";
		token_sequence += "CASE case DEFAULT default IF if ELSE else SWITCH switch WHILE while DO do FOR for GOTO goto CONTINUE continue BREAK break RETURN return ";

		//beyond C tokens
		token_sequence += "ASM __asm ASM __asm__ CBOOL bool CATCH catch CLASS class CONST_CAST const_cast DELETE delete DYNAMIC_CAST dynamic_cast EXPLICIT explicit ";
		token_sequence += "EXPORT export CFALSE false FRIEND friend INLINE inline INLINE __inline INLINE __inline__ MUTABLE mutable NAMESPACE namespace NEW new OPERATOR operator ";
		token_sequence += "PRIVATE private PROTECTED protected PUBLIC public REINTERPRET_CAST reinterpret_cast STATIC_CAST static_cast TEMPLATE template ";
		token_sequence += "THIS this THROW throw CTRUE TRUE TRY try TYPEID typeid TYPENAME typename USING using VIRTUAL virtual WCHAR_T wchar_t SCOPE :: DOT_MEMBER __blank__ PTR_MEMBER __blank__ ";

		//gcc entensions
		token_sequence += "ALIGNOF __alignof ALIGNOF __alignof__ ATTRIBUTE __attribute ATTRIBUTE __attribute__ COMPLEX __complex COMPLEX __complex__ EXTENSION __extension__ IMAGPART __imag IMAGPART __imag__ REALPART __real REALPART __real__ RESTRICT __restrict RESTRICT __restrict__ TYPEOF typeof TYPEOF __typeof TYPEOF __typeof__ VA_ARG __builtin_va_arg ";

		token_sequence += "BEGIN_TEMPLATE BEGIN_TEMPLATE ";	//special token

//>>>>>>> BE CAREFUL, I HAVEN'T FIGURED OUT HOW TO HANDLE USERTYPE AND VA_LIST <<<<<<<
		token_sequence += "USERTYPE __blank__ VA_LIST __blank__";

		StringTokenizer st = new StringTokenizer(token_sequence);

		while (st.hasMoreTokens() == true)
		{
			String str1 = st.nextToken();
			String str2 = st.nextToken();
			if (str2.equals(leave_blank))
			{
				continue;
			}
			src += "        name2enum.put(new String(\"" + str2 + "\"), new Integer(__" + str1 + "__));\n";
		}
		src += "\n";

		//now add all the symbols
		String signs = "TILDE ~ BANG ! PERCENT_SIGN % CARET ^ AMPERSAND & SHARP # DOLLAR_SIGN $ BACKTICK ` AT_SIGN @ ";
		signs += "LEFT_PARENTHESIS ( RIGHT_PARENTHESIS ) LEFT_BRACKET [ RIGHT_BRACKET ] LEFT_ANGLE_BRACKET < RIGHT_ANGLE_BRACKET > LEFT_BRACE { RIGHT_BRACE } ";
		signs += "PLUS_SIGN + MINUS_SIGN - ASTERISK * SLASH / EQUAL_SIGN = ";
		signs += "DOT . COMMA , VERTICAL_BAR | COLON : SEMICOLON ; QUESTION_MARK ? ";

		st = new StringTokenizer(signs);

		while (st.hasMoreTokens() == true)
		{
			String str1 = st.nextToken();
			String str2 = st.nextToken();
			if (str2.equals(leave_blank))
			{
				continue;
			}
			src += "        name2enum.put(new String(\"" + str2 + "\"), new Integer(__" + str1 + "__));\n";			
		}

		return src;
	}

	protected void end()
	{
		try
		{
			grammar_input.close();
			enum_output.close();			
            hash_output.close();
		}
		catch (IOException err)
		{
			System.out.println("Error, Unable to close files: " + err.toString());
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
		catch (IOException	err)
		{
			System.out.println("I/O Error: " + err.toString());
			System.exit(1);
		}
	}

	protected void printUsage()
	{
		System.out.println("Usage: java InterfaceBuilder input_grammar_file");
	}
}
