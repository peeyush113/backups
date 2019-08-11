package cetus.hir;

import java.util.*;

/**
 * Iterates over Traversable objects in depth-first order.
 */
public class DepthFirstIterator extends IRIterator
{
  private Vector stack;
  private HashSet prune_set;

  /**
   * Creates a new iterator.
   *
   * @param init The first object to visit.
   */
  public DepthFirstIterator(Traversable init)
  {
    super(init);
    stack = new Vector();
    stack.add(init);
    prune_set = new HashSet();
  }

  public boolean hasNext()
  {
    return !stack.isEmpty();
  }
 
  public Object next()
  {
    Traversable t = null;

    try {
      t = (Traversable)stack.remove(0);
    } catch (EmptyStackException e) {
      throw new NoSuchElementException();
    }

    if (t.getChildren() != null
        && !containsCompatibleClass(prune_set, t.getClass()))
    {
      int i = 0;
      Iterator iter = t.getChildren().iterator();
      while (iter.hasNext())
      {
        Object o = iter.next();
        if (o != null)
          stack.add(i++, o);
      }
    }

    return t;
  }

  public void pruneOn(Class c)
  {
    prune_set.add(c);
  }

  public void reset()
  {
    stack.clear();
    stack.add(root);
  }
}
