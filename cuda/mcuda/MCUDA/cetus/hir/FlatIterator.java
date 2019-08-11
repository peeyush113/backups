package cetus.hir;

import java.util.*;

/**
 * Iterates over the immediate children of a Traversable object.
 */
public class FlatIterator extends IRIterator
{
  private ListIterator iter;

  /**
   * Creates a new iterator.
   *
   * @param parent The parent of the children to visit.
   */
  public FlatIterator(Traversable parent)
  {
    super(parent);
    iter = parent.getChildren().listIterator();
  }

  /**
   * Adds an object after the last object that was returned
   * by next or previous.
   *
   * @param t The object to add.
   */
  public void add(Traversable t)
  {
    iter.add(t);
    t.setParent(root);
    root.setChild(iter.nextIndex() - 1, t);
  }

  public boolean hasNext()
  {
    return iter.hasNext();
  }

  public boolean hasPrevious()
  {
    return iter.hasPrevious();
  }
 
  public Object next()
  {
    return iter.next();
  }

  public Object previous()
  {
    return iter.previous();
  }

  /**
   * Removes the last object that was returned by next or previous.
   */
  public void remove()
  {
    ((Traversable)root.getChildren().get(iter.nextIndex() - 1)).setParent(null);
    iter.remove();
  }

  public void reset()
  {
    iter = root.getChildren().listIterator();
  }
}
