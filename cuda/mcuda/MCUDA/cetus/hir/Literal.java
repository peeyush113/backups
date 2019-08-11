package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Represents an immediate value within the program.
 */
public abstract class Literal extends Expression
{
  protected Literal()
  {
    /* Literals are always leaves, so we can save
       a lot of memory by not making a child list. */
    children = null;
  }

  public Object clone()
  {
    Literal o = (Literal)super.clone();
    return o; 
  }
}
