package cetus.treewalk;

import java.lang.*;
import java.util.*;

public class  GeneralSyntaxNode extends GeneralTreeNode
{
  int        NodeID = -1;  //newly added, need to be extra careful

  String      info;
  int        type_code;    // -1 ~ unrecognized

  int        src_file_id  = -1;  // where this node is from, -1 ~ invalid
  int        line_num  = -1;  // the line # in the src file, -1 ~ invalid

  CCTypeTable    local_type_table = null;
  CCTypeTable    additional_type_table = null;  //using namespace etc.

  public GeneralSyntaxNode(GeneralSyntaxNode _parent)
  {
    super(_parent);

    info = null;
    type_code = -1;  //since no info at all, unrecognized
  }
  public GeneralSyntaxNode(GeneralSyntaxNode _parent, String _info)
  {
    super(_parent);
    //info = new String(_info);
    info = _info.replaceAll("\\\\\"", "\"");

    CCTypeHash  type_hash = new CCTypeHash();
    type_code = type_hash.getEnumValue(info);

    if (type_code < 0)
    {
      System.out.println("CAUTION: GeneralSyntaxNode() type unknown: " + info + "\n" + _info);
    }
  }
  //also supplies the node_id in the original parser dump
  public GeneralSyntaxNode(int _NodeID, GeneralSyntaxNode _parent, String _info)
  {
    super(_parent);
    //info = new String(_info);
    info = _info.replaceAll("\\\\\"", "\"");

    CCTypeHash  type_hash = new CCTypeHash();
    type_code = type_hash.getEnumValue(info);

    if (type_code < 0)
    {
      System.out.println("CAUTION: GeneralSyntaxNode() type unknown: " + info + "\n" + _info);
    }

    NodeID = _NodeID;
  }

  //this approach saves a lot of memory and is much faster
  //it's not recommended from an soft-engr point of view because it may lead to incompatible _info and _type_code
  public GeneralSyntaxNode(GeneralSyntaxNode _parent, String _info, int _type_code)
  {
    super(_parent);
    //info = new String(_info);
    info = _info.replaceAll("\\\\\"", "\"");

    type_code = _type_code;
  }

  public void setInfo(String _info)
  {
    info = new String(_info);
  }

  public void setTypeCode(int _type_code)
  {
    type_code = _type_code;
  }

  public String getInfoString()
  {
    return info;
  }

  public int getTypeCode()
  {
    return type_code;
  }

  public int getNodeID()
  {
    return NodeID;
  }

  public int getLineNum()
  {
    return line_num;
  }
  public void setLineNum(int _line_num)
  {
    line_num = _line_num;
  }
  public int getSrcFileId()
  {
    return src_file_id;
  }
  public void setSrcFileId(int _src_file_id)
  {
    src_file_id = _src_file_id;
  }

/*--------------------- all about type table ------------------*/
  public CCTypeTable initLocalTypeTable()  //init a user type table associated with this node
  {
    if (local_type_table == null)
    {
      local_type_table = new CCTypeTable();
    }
    return local_type_table;    //return the existing one if it's already there
  }
  //if this node doesn't have a type table, returnt he nearest one in upper levels
  public CCTypeTable getTypeTable()
  {
    if (local_type_table != null)
    {
      return local_type_table;
    }
    else
    {
      GeneralSyntaxNode  parent_node = (GeneralSyntaxNode)getParent();
      return parent_node.getTypeTable();
    }
  }
  //returns true if the type is existing, false otherwise
  public boolean isType(String _type)
  {
    //simple type shouldn't cause any ambiguities

    GeneralSyntaxNode  node = this;
    while (true)
    {
      if (node.local_type_table != null)
      {
        if (node.local_type_table.containsType(_type) == true)
        {
          return true;
        }
        else if (additional_type_table != null)    //if namespace is used
        {
          if (additional_type_table.containsType(_type) == true)
          {
            return true;
          }
        }
      }

      //go up one level
      if (node.isRoot() == true)
      {
        break;
      }
      else
      {
        node = (GeneralSyntaxNode)(node.getParent());
      }
    }
    return false;
  }
  //return the previous additional type table, can be used to restore the original scope
  //to clear current scope, just set(null)
  public CCTypeTable set_AdditionalTypeTable(CCTypeTable  _type_table)
  {
    CCTypeTable old_type_table = additional_type_table;
    additional_type_table = _type_table;
    return old_type_table;
  }

//----------------------------for debugging purposes-----------------------------//
  public String toString()
  {
    /*
    String str = "(# of Children: " + numOfChildren() + ")\n" + "[" + info + "]";
    */
    CCTypeHash  typename_hash = new CCTypeHash();
    String  str = "";

    if (typename_hash.getEnumValue(info) < 0)
    {
      str = "Unrecognized: " + info + "\n";
    }
    else if (typename_hash.getEnumValue(info) == CCTypeEnum.__ambiguity__)
    {
      str = "Ambiguity: " + info + "\n";
    }
    else
    {
      str += info + "\n";
    }

    if (local_type_table != null)
    {
      str += "(*)Type Table: " + local_type_table.toString() + "\n";
    }

    return str;
  }
}
