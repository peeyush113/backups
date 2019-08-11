package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class ConstructorInitializer extends Initializer
{
  public ConstructorInitializer(List values)
  {
    for (Object o : values)
    {
      children.add(o);
      ((Traversable)o).setParent(this);
    }
  }

  public void print(OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);
    p.print("(");
    Tools.printListWithCommas(children, stream);
    p.print(")");
  }
}
