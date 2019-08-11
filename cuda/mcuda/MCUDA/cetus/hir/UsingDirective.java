package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

public class UsingDirective extends Declaration
{

  public List getDeclaredSymbols()
  {
    return new LinkedList();
  }
}
