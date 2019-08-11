
package cetus.treewalk.codegen;

import java.lang.*;
import java.util.*;

import cetus.treewalk.*;

public class Production implements Comparable
{
  String    LHS;
  ArrayList  RHS;

  public Production(String _lhs)
  {
    LHS = new String(_lhs);
    RHS = new ArrayList(5);
  }

  public void addRHS(String _rhs)
  {
    RHS.add(new String(_rhs));
  }

  public int sizeOfRHS()
  {
    return RHS.size();
  }

  public int compareTo(Object _p)
  {
    return LHS.compareTo(((Production)_p).LHS);
  }
}
