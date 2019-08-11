package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class ValueInitializer extends Initializer
{
  public ValueInitializer(Expression value)
  {
    children.add(value);
    value.setParent(this);
  }

  public Expression getValue()
  {
    return (Expression)children.get(0);
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print(" = ");
    getValue().print(stream);
  }
}
