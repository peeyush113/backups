package cetus.hir;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/**
 * Represents an exception handling block (try-catch-finally block)
 * in a C++ or Java program.  This class is derived from CompoundStatement
 * because in C++ it is legal to have a procedure whose body is an
 * exception handler. An exception handler has a try block followed by
 * at least one catch block followed optionally by a finally block.
 */
public class ExceptionHandler extends CompoundStatement
{
  private static Method class_print_method;

  static
  {
    Class[] params = new Class[2];

    try {
      params[0] = ExceptionHandler.class;
      params[1] = OutputStream.class;
      class_print_method = params[0].getMethod("defaultPrint", params);
    } catch (NoSuchMethodException e) {
      throw new InternalError();
    }
  }

  private boolean has_finally;

  /**
   * Creates an exception handler.
   */
  public ExceptionHandler(CompoundStatement try_block, List catch_blocks)
  {
    object_print_method = class_print_method;
    has_finally = false;

    children.add(try_block);
    children.addAll(catch_blocks);
  }

  /**
   * Creates an exception handler.
   */
  public ExceptionHandler(CompoundStatement try_block, List catch_blocks,
                          CompoundStatement finally_block)
  {
    object_print_method = class_print_method;
    has_finally = true;

    children.add(try_block);
    children.addAll(catch_blocks);
    children.add(finally_block);
  }

  /**
   * Appends a catch block to the list of catch blocks.
   *
   * @param catch_block The block to add.
   */
  public void addCatchBlock(CompoundStatement catch_block)
  {
    int last_catch = children.size();

    if (has_finally)
      last_catch--;

    children.add(catch_block);
  }

  public void addFinallyBlock(CompoundStatement finally_block)
  {
    if (has_finally)
      throw new IllegalStateException("cannot have more than one finally block");

    has_finally = true;
    children.add(finally_block);
  }

  /**
   * Prints a statement to a stream.
   *
   * @param stmt The statement to print.
   * @param stream The stream on which to print the statement.
   */
  public static void defaultPrint(ExceptionHandler stmt, OutputStream stream)
  {
    PrintStream p = new PrintStream(stream);

    p.println("try");
    ((Statement)stmt.children.get(0)).print(stream);

    int n = stmt.children.size() - 1;
    if (stmt.has_finally)
      n--;

    for (int i = 1; i <= n; ++i)
    {
      p.println("catch");
      ((Statement)stmt.children.get(i)).print(stream);
    }

    if (stmt.has_finally)
    {
      p.println("finally");
      ((Statement)stmt.children.get(n + 1)).print(stream);
    }
  }
}
