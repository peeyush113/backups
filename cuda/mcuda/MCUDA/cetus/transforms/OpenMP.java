package cetus.transforms;

import cetus.analysis.*;
import cetus.exec.*;
import cetus.hir.*;

import java.util.*;

/**
 * This pass looks for Annotations that provide
 * enough information to add OpenMP pragmas and
 * then inserts those pragmas.
 */
public class OpenMP extends TransformPass
{
  public OpenMP(Program program)
  {
    super(program);
  }

  public String getPassName()
  {
    return new String("[OpenMP]");
  }

  public void start()
  {
    LinkedList<Annotation> note_list = new LinkedList<Annotation>();

    /* iterate over everything, with particular attention to annotations */

    DepthFirstIterator iter = new DepthFirstIterator(program);

    while (iter.hasNext())
    {
      Object obj = iter.next();

      if (obj instanceof Annotation)
      {
        /* extract information from the annotation */
        Annotation note = (Annotation)obj;
        note_list.add(note);
      }
      else if (obj instanceof Loop)
      {
        /* use extracted information to put an OpenMP pragma before the loop */
      
        boolean parallel = false;
        String omp_pragma = "omp ";
        String reduction = "";
        String privatization = "";

        Loop loop = (Loop)obj;

        for (Annotation note : note_list)
        {
          if (note.getText().compareTo("DDT") == 0)
          {
            if (((String)note.getMap().get("result")).compareTo("parallel") == 0)
              parallel = true;
          }
          else if (note.getText().compareTo("reduce") == 0)
          {
            Map<String, List<Expression>> map = Reduction.getOperatorToVariablesMap(note);
            Iterator<Map.Entry<String, List<Expression>>> map_pairs = map.entrySet().iterator();

            while (map_pairs.hasNext())
            {
              Map.Entry<String, List<Expression>> pair = map_pairs.next();
              String op = pair.getKey();
              List<Expression> vars = pair.getValue();

              String vars_string = vars.toString();
              vars_string = vars_string.substring(1, vars_string.length() - 1);

              if (reduction.compareTo("") != 0)
                reduction += ", ";
              reduction += "reduction(" + op + ": " + vars_string + ")";
            }
          }
          else if (note.getText().compareTo("private") == 0)
          {
            String vars = Privatization.getPrivateString(Privatization.getPrivateSet(note));

            privatization += "private(" + vars + ")";
          }
        }

        if (parallel)
        {
          omp_pragma += "parallel ";

          if (privatization != null && privatization.compareTo("") != 0)
          {
            omp_pragma += privatization;
            if (reduction != null && reduction.compareTo("") != 0)
              omp_pragma += ", ";
          }

          if (reduction != null && reduction.compareTo("") != 0)
            omp_pragma += reduction;

          Annotation note = new Annotation(omp_pragma);
          note.setPrintMethod(Annotation.print_as_pragma_method);

          ((CompoundStatement)((Statement)loop).getParent()).addStatementBefore((Statement)loop, new DeclarationStatement(note));
        }

        /* clear the information */
        note_list.clear();
      }
    }
  }
}
