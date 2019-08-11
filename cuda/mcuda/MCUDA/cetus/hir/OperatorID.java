package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * C++ overloaded operator IDs.
 */
public class OperatorID extends IDExpression
{
  private String name;

  public OperatorID(String name)
  {
    super(false);
    this.name = name;
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("operator " + name);
  }
}
