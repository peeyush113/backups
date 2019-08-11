package cetus.analysis;

import cetus.hir.*;

/**
 * Represents an induction variable.
 */
public class InductionVariable
{
  public Expression variable;
  public int lower_bound;
  public int upper_bound;
  public int step;

  public InductionVariable()
  {
    this.variable    = null;
    this.lower_bound = 0;
    this.upper_bound = 0;
    this.step        = 0;
  }

  public int countSteps()
  {
    return ((upper_bound - lower_bound) / step) + 1;
  }

  public String toString()
  {
    return new String(variable.toString() +
                      " from " + Integer.toString(lower_bound) +
                      " to "   + Integer.toString(upper_bound) +
                      " step " + Integer.toString(step));
  }
}
