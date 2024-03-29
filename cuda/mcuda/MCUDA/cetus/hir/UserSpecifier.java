package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Represents the name of a user-defined type, such
 * as created by a typedef, class declaration, etc. */
public class UserSpecifier extends Specifier
{
  private IDExpression usertype;

  public UserSpecifier(IDExpression usertype)
  {
    this.usertype = usertype;
  }

  public IDExpression getIDExpression()
  {
    return usertype;
  }

  public boolean isStructure()
  {
    return toString().startsWith("struct ");
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    usertype.print(stream);
  }

  public String toString()
  {
    return usertype.toString();
  }
}
