package cetus.hir;

import java.util.*;

/**
 * Iterates over Traversable objects in breadth-first order.
 */
public class BreadthFirstIterator extends IRIterator
{
  private Vector queue;
  private HashSet prune_set;

  /**
   * Creates a new iterator.
   *
   * @param init The first object to visit.
   */
  public BreadthFirstIterator(Traversable init)
  {
    super(init);
    queue = new Vector();
    queue.add(init);
    prune_set = new HashSet();
  }

  public boolean hasNext()
  {
    return !queue.isEmpty();
  }

  public Object next()
  {
    Traversable t = null;

    try {
      t = (Traversable)queue.remove(0);
    } catch (ArrayIndexOutOfBoundsException e) {
      throw new NoSuchElementException();
    }

    if (t.getChildren() != null
        && !containsCompatibleClass(prune_set, t.getClass()))
    {
      Iterator iter = t.getChildren().iterator();
      while (iter.hasNext())
      {
        Object o = iter.next();
        if (o != null)
          queue.add(o);
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
    queue.clear();
    queue.add(root);
  }
}
