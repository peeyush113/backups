package cetus.hir;

import java.util.*;

/**
 * Peforms a post-order traversal over a Traversable object.
 */
public class PostOrderIterator extends IRIterator
{
  private LinkedList queue;
  private HashSet prune_set;

  /**
   * Creates a new iterator.
   *
   * @param init The root object for the traversal.
   */
  public PostOrderIterator(Traversable root)
  {
    super(root);
    queue = new LinkedList();
    prune_set = new HashSet();

    reset();
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
    } catch (EmptyStackException e) {
      throw new NoSuchElementException();
    }

    return t;
  }

  private void populate(Traversable t)
  {
    if (t.getChildren() != null
        && !containsCompatibleClass(prune_set, t.getClass()))
    {
      for (Object obj : t.getChildren())
      {
        populate((Traversable)obj);
      }
    }

    queue.add(t);
  }

  public void pruneOn(Class c)
  {
    prune_set.add(c);
  }

  public void reset()
  {
    queue.clear();
    prune_set.clear();

    populate(root);
  }
}
