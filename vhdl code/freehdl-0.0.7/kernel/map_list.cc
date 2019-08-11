#define KERNEL
#include <freehdl/kernel-map-list.hh>
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-resolver-descriptor.hh>

// Stores the father signal(s) of port signals
port_signal_link_map_t port_signal_link_map;

// global temproary map list object 
map_list tmpml;


signal_link::signal_link()
{
  formal_aclp = NULL;
  formal_name = "";
  wrapper_fn_formal = NULL;
  actual_aclp = NULL;
  actual_signal = NULL;
  value = NULL;
  type = NULL;
  wrapper_fn_actual = NULL;
}

signal_link::~signal_link()
{
  if (formal_aclp) delete formal_aclp;
  if (actual_aclp) delete actual_aclp;
  if (value != NULL)
    type->remove(value);
}

// Returns type of actual 
type_info_interface *
signal_link::get_actual_type() 
{
  if (type != NULL)
    return type;
  if (actual_signal != NULL)
    return actual_signal->type;
  return NULL;
}


// Returns pointer to actual signal value or expression (in case of
// actual is an expression)
void *
signal_link::get_actual_value() 
{
  // If actual_signal points to NULL then an expression has been
  // specified as actual!
  return (actual_signal != NULL)? actual_signal->reader_pointer : value;
}


generic_link::generic_link()
{
  formal_aclp = NULL;
  formal_name = "";
  value = NULL;
  type = NULL;
}

generic_link::~generic_link()
{
  if (formal_aclp) delete formal_aclp;
  if (value != NULL)
    type->remove(value);
}

// Returns type of actual 
type_info_interface *
generic_link::get_actual_type() 
{
  return type;
}

// Returns pointer to generic value
void *
generic_link::get_actual_value() 
{
  return value;
}



map_list::map_list()
{
}

map_list::~map_list()
{
  void *pos = generic_maplist.begin();
  while (pos) { 
    delete generic_maplist.content(pos); 
    pos = generic_maplist.next(pos);
  }

  pos = signal_maplist.begin();
  while (pos) { 
    delete signal_maplist.content(pos);
    pos = signal_maplist.next(pos);
  }
}

// The generic map with expression
void map_list::generic_map(const char *formal, acl *formal_acl, 
			   const void *value, type_info_interface *type)
{
  generic_link *glink = new generic_link;

  glink->formal_name = string(formal);
  glink->formal_aclp = formal_acl->clone();
  glink->value = type->clone(value);
  glink->type = type;

  generic_maplist.push_back(glink);
}

// Adds a signal link to the signal_map list
void map_list::signal_map(const char *formal, acl *formal_acl, 
			  const char formal_mode, 
			  sig_info_base *actual, acl *actual_acl)
{
  signal_link *slink = new signal_link;

  slink->formal_name = string(formal);
  slink->formal_aclp = formal_acl->clone();
  slink->formal_mode = formal_mode;
  slink->actual_signal = actual;
  slink->actual_aclp = actual_acl->clone();

  signal_maplist.push_back(slink);
}


// the mapping with an expression
void map_list::signal_map(const char *formal, acl *formal_acl, 
			  const char formal_mode, const void *value, 
			  type_info_interface *type)
{
  signal_link *slink = new signal_link;

  slink->formal_name = string(formal);
  slink->formal_aclp = formal_acl->clone();
  slink->formal_mode = formal_mode;
  slink->value = type->clone(value);
  slink->type = type;

  signal_maplist.push_back(slink);
}


// the mapping with open
void map_list::signal_map(const char *formal, acl *formal_acl,
			  const char formal_mode)
{
  signal_link *slink = new signal_link;

  slink->formal_name = string(formal);
  slink->formal_aclp = formal_acl->clone();
  slink->formal_mode = formal_mode;

  signal_maplist.push_back(slink);
}

// the mapping with formal convert function
void map_list::signal_map(const char *formal, acl *formal_acl,
			  const char formal_mode,
			  void (*wrapper_fn_formal)(void *,void *), 
			  sig_info_base *actual, acl *actual_acl)
{
  signal_link *slink = new signal_link;

  slink->formal_name = string(formal);
  slink->formal_aclp = formal_acl->clone();
  slink->formal_mode = formal_mode;
  slink->wrapper_fn_formal = wrapper_fn_formal;
  slink->actual_signal = actual;
  slink->actual_aclp = actual_acl->clone();

  signal_maplist.push_back(slink);
}

// the mapping with actual convert function
void map_list::signal_map(const char *formal, acl *formal_acl,
			  const char formal_mode, sig_info_base *actual, 
			  acl *actual_acl,
			  void (*wrapper_fn_actual)(void *,void *))
{
  signal_link *slink = new signal_link;

  slink->formal_name = string(formal);
  slink->formal_aclp = formal_acl->clone();
  slink->formal_mode = formal_mode;
  slink->actual_signal = actual;
  slink->actual_aclp = actual_acl->clone();
  slink->wrapper_fn_actual = wrapper_fn_actual;

  signal_maplist.push_back(slink);
}

// the mapping with formal/actual convert function
void map_list::signal_map(const char *formal, acl *formal_acl, 
			  const char formal_mode, 
			  void (*wrapper_fn_formal)(void *,void *), 
			  sig_info_base *actual, acl *actual_acl,
			  void (*wrapper_fn_actual)(void *,void *))
{
  signal_link *slink = new signal_link;

  slink->formal_name = string(formal);
  slink->formal_aclp = formal_acl->clone();
  slink->formal_mode = formal_mode;
  slink->wrapper_fn_formal = wrapper_fn_formal;
  slink->actual_signal = actual;
  slink->actual_aclp = actual_acl->clone();
  slink->wrapper_fn_actual = wrapper_fn_actual;

  signal_maplist.push_back(slink);
}


void map_list::reset()
{
  signal_maplist.reset();
  generic_maplist.reset();
}


bool 
query_generic(map_list *mlist, list<generic_link*> &result, const string &name)
{
  if (mlist == NULL)
    return false;
  void *tmp;
  generic_link *glink;
  
  tmp = mlist->generic_maplist.begin();
  while ( tmp != NULL ) {
    glink = mlist->generic_maplist.content(tmp);
    if ( glink->formal_name == name ) {
      result.push_back(glink);
    }
    tmp = mlist->generic_maplist.next(tmp);
  }
  if (result.size() != 0)
    return true;
  else
    return false;
}


bool 
query_signal(map_list *mlist, list<signal_link*> &result, const string &name)
{
  if (mlist == NULL)
    return false;
  void *tmp;
  signal_link *slink;
  
  tmp = mlist->signal_maplist.begin();
  while ( tmp != NULL ) {
    slink = mlist->signal_maplist.content(tmp);
    if ( slink->formal_name == name ) {
      result.push_back(slink);
    }
    tmp = mlist->signal_maplist.next(tmp);
  }
  if (result.size() != 0)
    return true;
  else
    return false;
}


template<class T>
int 
get_unconstrained_link_array_bounds(list<T*> *mlist, const string &name, array_info *ainfo, 
				    vector<int> &left, vector<range_direction> &dir, vector<int> &right)
{
  int error_num = 0;

  /* First, determine how many dimensions the unconstrained array
   * consists of */
  int dim_counter = 0;
  array_info *ai = ainfo;
  while (ai != NULL) {
    if (ai->length != -1)
      break;
    dim_counter++;
    if (ai->element_type->id != ARRAY)
      break;
    ai = (array_info*)ai->element_type;
  }

  /* Resize left, dir and right arrays so that they contain a
   * separate entry for each dimension. Index 0 is associated with the
   * first dimension, ... */
  left.resize(dim_counter);
  dir.resize(dim_counter);
  right.resize(dim_counter);
  
  /* Create a set of vector that will be used to hold the newly
   * determined ranges */
  vector<int> new_left(dim_counter), new_right(dim_counter);
  vector<range_direction> new_dir(dim_counter);

  /* Next, get max bounds from index type of formal */
  ai = ainfo;
  for (int dim = 0; dim < dim_counter; dim++, ai = (array_info*)ai->element_type)
    /* Get max array bounds as defined by the unconstrained array type */
    ai->index_type->get_bounds(left[dim], dir[dim], right[dim]);

  /* Test whether the entire formal is mapped */
  if (mlist->size() == 1 &&
      mlist->front()->get_formal_aclp()->end()) 
    {
      T* link = mlist->front();
      /* Get last acl description for actual and test whether it is a
         range. Note that a range can occure only if the formal is a
         one-dimensional array */
      pacl actual_aclp = link->get_actual_aclp();
      pacl actual_last_aclp = get_level(actual_aclp, count_levels(actual_aclp));
      if (!actual_last_aclp->end() &&
	  actual_last_aclp->get() == ACL_RANGE) {
	/* Only permitted if formal is a one-dimensional array */
	assert(dim_counter == 1);
	get_entry_data(actual_last_aclp, new_left[0], new_dir[0], new_right[0]); 

      } else {
	/* Ok, the actual is a complete array of appropriate dimension */
	array_info *actual_ainfo = 
	  (array_info*)link->get_actual_type()->get_info(link->get_actual_value(), actual_aclp);
	for (int dim = 0; dim < dim_counter; dim++) {
	  /* Extract array bounds from actual array */
	  new_left[dim] = actual_ainfo->left_bound;
	  new_dir[dim] = actual_ainfo->index_direction;
	  new_right[dim] = actual_ainfo->right_bound;
	}
      }

    } else if (dim_counter == 1) {
      /* Ok, we have a one-dimensional formal and the formal is
       * associated individually, .i.e., parts of the formal are
       * assigned element (range) wise. */
      vector<int> left_vec, right_vec;
      vector<range_direction> dir_vec;
      range_direction final_formal_dir = dir[0];
      bool dir_specified = false;
      /* Check out all formal acls in order to determine formal range */
      typedef typename list<T*>::iterator pos_type_t;
      for (pos_type_t pos = mlist->begin(); pos != mlist->end(); pos++) {
	T* link = *pos;
	int tmp_left, tmp_right;
	range_direction tmp_dir;
	pacl formal_aclp = link->get_formal_aclp();
	assert(!formal_aclp->end());
	get_entry_data(formal_aclp, tmp_left, tmp_dir, tmp_right);
	/* Check whether a range has been given and whether the range
         * direction conflict with a previously given range */
	if (formal_aclp->get() == ACL_RANGE)
	  if (!dir_specified) {
	    dir_specified = true;
	    final_formal_dir = tmp_dir;
	  } else if (final_formal_dir != tmp_dir) {
	    error_num = -1;
	    error(ERROR_ARRAY_INDEX);
	    return error_num;
	  }
	/* Do not considere any ranges that are actually null ranges */
	if (range_to_length(tmp_left, tmp_dir, tmp_right) <= 0) continue;
	/* Next, test whether the new range confilics with a
         * previously defined range */
	for (unsigned int i = 0; i < left_vec.size(); i++)
	  if (! ((max(tmp_left, tmp_right) < min(left_vec[i], right_vec[i])) ||
		 (min(tmp_left, tmp_right) > max(left_vec[i], right_vec[i]))) ) {
	    error_num = -1;
	    error(ERROR_ARRAY_INDEX);
	    return error_num;
	  }
	left_vec.push_back(tmp_left); 
	dir_vec.push_back(tmp_dir);
	right_vec.push_back(tmp_right);
      } 
      /* Finally, check out whether there are any "gaps" in the
       * range. Since we already proved that the ranges do not overlap
       * we can sort the left_vec and right_vec array in order to
       * search for holes. */
      sort(left_vec.begin(), left_vec.end());
      sort(right_vec.begin(), right_vec.end());
      const int diff = final_formal_dir == to? 1 : -1;
      for (unsigned int i = 0; i < left_vec.size() - 1; i++)
	if (right_vec[i] + diff != left_vec[i + 1]) {
	  error_num = -1;
	  error(ERROR_ARRAY_INDEX);
	  return error_num;
	}

      new_left[0] = left_vec.front();
      new_dir[0] = final_formal_dir;
      new_right[0] = right_vec.back();

    } else {
      /* Ok, we have a multi-dimensional formal and the formal is
       * associated individually, .i.e., parts of the formal are
       * assigned element wise (note that no "ranges" are possible in
       * this case). First, read in formal index groups. Each index
       * group specifies one formal array element. */
      vector<vector<int> > dim_vec;
      vector<int> min_index(dim_counter), max_index(dim_counter);
      fill(min_index.begin(), min_index.end(), INT_MAX);
      fill(max_index.begin(), max_index.end(), INT_MIN);
      typedef typename list<T*>::iterator pos_type_t;
      for (pos_type_t pos = mlist->begin(); pos != mlist->end(); pos++) {
	T* link = *pos;
	int tmp_left, tmp_right;
	range_direction tmp_dir;
	pacl formal_aclp = link->get_formal_aclp();
	vector<int> index_group;
	int i = 0;
	while (!formal_aclp->end()) {
	  assert(formal_aclp->get() != ACL_RANGE);
	  formal_aclp = get_entry_data(formal_aclp, tmp_left, tmp_dir, tmp_right);
	  index_group.push_back(tmp_left);
	  min_index[i] = min(min_index[i], tmp_left);
	  max_index[i] = max(max_index[i], tmp_left);
	  i++;
	}
	assert(index_group.size() == dim_counter);
	/* Check whether no index group has been specified more than
	 * once. */
	for (unsigned int i = 0; i < dim_vec.size(); i++)
	  if (index_group == dim_vec[i]) {
	    error_num = -1;
	    error(ERROR_ARRAY_INDEX);
	    return error_num;
	  }
	/* Finally, add index group to dim_vec */
	dim_vec.push_back(index_group);
      }
      /* Next, determine number of elements from min and max index
       * values */
      unsigned int array_element_count = 1;
      for (int dim = 0; dim < dim_counter; dim++)
	array_element_count *= max_index[dim] - min_index[dim] + 1;
      /* Finally, check whether there were enough elements specified
       * */
      if (array_element_count != dim_vec.size()) {
	error_num = -1;
	error(ERROR_ARRAY_INDEX);
	return error_num;
      }
      /* Finally, use index direction of formal type to setup new left
       * and right bounds */
      for (int dim = 0; dim < dim_counter; dim++) {
	new_dir[dim] = dir[dim];
	new_left[dim] = dir[dim] == to? min_index[dim] : max_index[dim];
	new_right[dim] = dir[dim] == to? max_index[dim] : min_index[dim];
      }
    }


  /* Check whether new index values are not out of bounds */
  for (int dim = 0; dim < dim_counter; dim++)
    if (!check_bounds(left[dim], right[dim], new_left[dim]) ||
	!check_bounds(left[dim], right[dim], new_right[dim])) {
      error_num = -1;
      error(ERROR_ARRAY_INDEX);
      return error_num;
    } else {
      left[dim] = new_left[dim];
      dir[dim] = new_dir[dim];
      right[dim] = new_right[dim];
    }

  return 0; /* Return ok */
}


int 
get_unconstrained_port_array_bounds(list<signal_link*> *mlist, const string &name, 
				    array_info *ainfo, vector<int> &left, vector<range_direction> &dir, 
				    vector<int> &right)
{
  return get_unconstrained_link_array_bounds<signal_link>(mlist, name, ainfo, left, dir, right);
}

int 
get_unconstrained_generic_array_bounds(list<generic_link*> *mlist, const string &name, 
				       array_info *ainfo, vector<int> &left, vector<range_direction> &dir, 
				       vector<int> &right)
{
  return get_unconstrained_link_array_bounds<generic_link>(mlist, name, ainfo, left, dir, right);
}


array_info *
create_array_info_for_unconstrained_link_array(array_info *unc_array_info,
					       vector<int> &left, vector<range_direction> &dir, 
					       vector<int> &right, const int rc)
{
  // Note that the array may be a multi-dimensional array. Hence,
  // we have do do a little bit more here... First, collect all
  // array info pointer that belong to the (multi-dimensional)
  // array.
  vector<array_info *> ainfo_vec; 
  ainfo_vec.push_back(unc_array_info);
  for (unsigned int dim = 1; dim < dir.size(); dim++)
    ainfo_vec.push_back((array_info*)ainfo_vec.back()->element_type);
  // Next, create a appropriate chain of array infos. Note that
  // e.g. a 2-dimensional array is actually an array of arrays...
  type_info_interface *type = ainfo_vec.back()->element_type;
  for (int dim = dir.size() - 1; dim >= 0; dim--)
    type = new array_info(type, ainfo_vec[dim]->index_type, left[dim], dir[dim], right[dim], rc);

  return (array_info*)type;
}
