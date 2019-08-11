
package cetus.treewalk.codegen;
//this class gives the english name for a given symbol

import java.lang.*;
import java.util.*;

import cetus.treewalk.*;

public class  CCSymbol2Name
{
  Hashtable  symbol_2_name;

  public CCSymbol2Name()
  {
    symbol_2_name = new Hashtable();

    symbol_2_name.put(new String("~"), new String("TILDE"));
    symbol_2_name.put(new String("!"), new String("BANG"));
    symbol_2_name.put(new String("%"), new String("PERCENT_SIGN"));
    symbol_2_name.put(new String("^"), new String("CARET"));
    symbol_2_name.put(new String("&"), new String("AMPERSAND"));
    symbol_2_name.put(new String("#"), new String("SHARP"));
    symbol_2_name.put(new String("$"), new String("DOLLAR_SIGN"));
    symbol_2_name.put(new String("'"), new String("BACKTICK"));
    symbol_2_name.put(new String("@"), new String("AT_SIGN"));

    symbol_2_name.put(new String("("), new String("LEFT_PARENTHESIS"));
    symbol_2_name.put(new String(")"), new String("RIGHT_PARENTHESIS"));
    symbol_2_name.put(new String("["), new String("LEFT_BRACKET"));
    symbol_2_name.put(new String("]"), new String("RIGHT_BRACKET"));
    symbol_2_name.put(new String("<"), new String("LEFT_ANGLE_BRACKET"));
    symbol_2_name.put(new String(">"), new String("RIGHT_ANGLE_BRACKET"));
    symbol_2_name.put(new String("{"), new String("LEFT_BRACE"));
    symbol_2_name.put(new String("}"), new String("RIGHT_BRACE"));

    symbol_2_name.put(new String("+"), new String("PLUS_SIGN"));
    symbol_2_name.put(new String("-"), new String("MINUS_SIGN"));
    symbol_2_name.put(new String("*"), new String("ASTERISK"));
    symbol_2_name.put(new String("/"), new String("SLASH"));
    symbol_2_name.put(new String("="), new String("EQUAL_SIGN"));

    symbol_2_name.put(new String("."), new String("DOT"));
    symbol_2_name.put(new String(","), new String("COMMA"));
    symbol_2_name.put(new String("|"), new String("VERTICAL_BAR"));
    symbol_2_name.put(new String(":"), new String("COLON"));
    symbol_2_name.put(new String(";"), new String("SEMICOLON"));
    symbol_2_name.put(new String("?"), new String("QUESTION_MARK"));
  }

  public String getName(String _sym)
  {
    String sym_name = (String)(symbol_2_name.get(_sym));
    if (sym_name == null)  //did find any match
    {
      return (_sym);
    }
    else
    {
      return (new String(sym_name));
    }
  }
}
