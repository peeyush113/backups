
package cetus.cctreewalk;

import java.lang.*;
import java.util.*;

class GeneralTreeNode 
{
	GeneralTreeNode	parent;
	ArrayList			children = null;	//a list of children nodes, don't create till first insertion to save space for leaves

	int					trim_counter;		//counter used to remember when to do trimming

	//give the parent node when creating a new node
	//if null if the parent is unknown at this time, or if it's root
	public GeneralTreeNode(GeneralTreeNode _parent)
	{
		parent			= _parent;

		trim_counter	= 0;
	}
	
	//all about parent
	//set the new parent, it returns the old parent
	public GeneralTreeNode setParent(GeneralTreeNode _new_parent)
	{
		GeneralTreeNode	temp_par = parent;
		parent = _new_parent;
		return temp_par;
	}

	public GeneralTreeNode getParent()
	{
		return parent;
	}

	//all about children
	public int numOfChildren()
	{
		if (children == null)	//leaf
		{
			return 0;
		}
		else
		{
			return children.size();
		}
	}

	//it returns the # of children AFTER insertion
	public int addChildLast(GeneralTreeNode _new_child)
	{
		if (children == null)
		{
			children = new ArrayList(3);
		}

		children.add(_new_child);

		trimChildrenList();

		return children.size();
	}

	public int addChildFirst(GeneralTreeNode _new_child)
	{
		if (children == null)
		{
			children = new ArrayList(3);
		}

		children.add(0, _new_child);

		trimChildrenList();

		return children.size();
	}

	//the new child will become the _position-th child; return negative if _position is > # of children
	public int addChildAt(GeneralTreeNode _new_child, int _position)
	{
		if (children == null)
		{
			children = new ArrayList(3);
		}

		children.add(_position, _new_child);

		trimChildrenList();

		return children.size();
	}

	//returns the num of children after removal
	//only remove the first occurence of the object, use carefully !!
	public int removeChild(GeneralTreeNode _child)
	{
		if (children == null || _child == null)
		{
			return -1;
		}

		if (children.remove(_child) == false)
		{
			return -1;
		}

		trimChildrenList();

		return children.size();
	}

	//returns the node just removed
	public GeneralTreeNode removeChild(int _position)
	{
		if (children == null || _position >= children.size())
		{
			return null;
		}
		
		GeneralTreeNode	result = (GeneralTreeNode)children.remove(_position);
		
		trimChildrenList();
		
		return result;
	}

	//get the i-th child
	public GeneralTreeNode getChild(int _position)
	{
		if (children == null || _position >= children.size())
		{
			return null;
		}

		return (GeneralTreeNode)(children.get(_position));
	}

	//misc methods and supporting routines
	
	boolean	isRoot()
	{
		return (parent == null)? true : false;
	}

	boolean isLeaf()
	{
		if (children == null)
		{
			return true;
		}
		else if (children.size() <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//give some basic info about this node
	public String toString()
	{
		String info = "";

		info += "Number of Children: " + children.size();

		return info;
	}

	//don't want to waste space, don't want to waste too much time either
	protected void trimChildrenList()
	{
		trim_counter ++;
		trim_counter = trim_counter % 50000;	//to prevent overflow

		if (children == null)	//nothing to trim, in case called improperly
		{
			return;
		}

		int list_size = children.size();

		if (list_size < 50)
		{
			if (trim_counter % 5 == 0)
			{
				children.trimToSize();
			}
		}
		else if (list_size < 200)
		{
			if (trim_counter % 10 == 0)
			{
				children.trimToSize();
			}
		}
		else
		{
			if (trim_counter % 50 == 0)
			{
				children.trimToSize();				
			}
		}

		return;
	}
}

