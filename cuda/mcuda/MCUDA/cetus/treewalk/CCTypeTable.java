
package cetus.treewalk;

//this class holds the types declared so far, used to solve the ambiguities
import java.lang.*;
import java.util.*;

class  CCTypeTable
{
	HashSet type_set;

	public CCTypeTable()
	{
		type_set = new HashSet();
	}

	//add a "user type" into the type table of this scope
	//return true if no collision, false otherwise
	public boolean addType(String _type)
	{
		return type_set.add(new String(_type.trim()));
	}

	public boolean containsType(String _type)
	{
		return type_set.contains(_type);
	}
}
