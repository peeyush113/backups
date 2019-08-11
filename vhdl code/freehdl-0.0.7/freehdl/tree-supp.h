// -*- c++ -*-

#ifndef LIBFIRE_TREE_SUPP_H
#define LIBFIRE_TREE_SUPP_H

#include <stddef.h>
#include <assert.h>

/* Run-time type information */

struct tree_base_node;

typedef struct tree_kind_info *tree_kind;

struct tree_chunk_info {
  int chunk_id;
  const char *name;

  int n_kinds;
  tree_kind *node_kinds;
};

struct tree_slot_info {
  tree_kind kind;
  const char *name;
  tree_base_node *(tree_base_node::*loc);
};

struct tree_kind_info {
  int kind_id;       // when kind_id is -1 then it is really a tree_ctype_info
  const char *name;

  tree_chunk_info *chunk;
  tree_kind base;
  tree_kind last_derived;
  tree_kind chunk_base;

  int n_links, n_slots;
  tree_slot_info *slot_info;

  size_t size;

  int next_prop_key;
  int next_derived_prop_key;
};

struct tree_ctype_info {
  int minus_one;    // always -1 to distinguish it from tree_kind_info
  const char *name;

  void (*print) (void *mem);  // XXX
};

bool tree_is (tree_kind kind, tree_kind base);
tree_kind tree_base (tree_kind kind);
const char *tree_kind_name (tree_kind);

struct tree_prop;

struct tree_propslot_info {
  tree_kind kind;
  const char *name;
  tree_base_node *(tree_prop::*loc);
};

struct tree_prop_info {
  int n_links, n_slots;
  tree_propslot_info *slot_info;
};

struct tree_prop {

  tree_prop ();
  virtual ~tree_prop ();

  virtual tree_prop_info *get_info () = 0;
};

int tree_uniq_prop_key (tree_kind kind);

struct tree_base_node {

  tree_base_node ();
  virtual ~tree_base_node ();

  virtual tree_kind kind () = 0;

  bool is (tree_kind base) { return this && tree_is (kind (), base); }
  const char *kind_name () { return tree_kind_name (kind ()); }

  tree_prop *get (int key);
  void put (int key, tree_prop *val);

private:
  struct tree_prop_tab {
    int n_props;
    tree_prop *props[1];
  };
  tree_prop_tab *proptab;
  void grow_props (int key);

  tree_base_node *next_living;

  void mark ();
  void setmarkbit () { proptab = (tree_prop_tab *)((long)proptab | 1); }
  void clrmarkbit () { proptab = (tree_prop_tab *)((long)proptab & ~1); }
  bool marked ()     { return (long)proptab & 1; }
  tree_prop_tab *gc_proptab () 
    { return (tree_prop_tab *)((long)proptab & ~1); }

  friend void tree_collect_garbage ();
};

void tree_protect (tree_base_node *n);
void tree_unprotect (tree_base_node *n);
void tree_protect_loc (tree_base_node **l);
void tree_unprotect_loc (tree_base_node **l);

void tree_block_garbage_collection ();
void tree_unblock_garbage_collection ();

void tree_collect_garbage ();
void tree_set_gc_thresh (int thresh);

void tree_print (const char *label, tree_base_node *n, int levels);

struct tree_chunk_tab {
  tree_chunk_info *chunk;
  int mtab_size;
  void *mtab;
};

// XXX - use a common implementation for all global generics (whose
// mtype can be casted to void* and back).

void *tree_find_mtab (tree_chunk_tab *ctab, int n_chunks, tree_kind *kind);
void tree_no_method (const char *genfunc, tree_kind kind);
void tree_conflicting_methods (const char *genfunc, tree_kind kind);

template<class mtype>
struct tree_generic {

  void init (const char *nm)
  {
    name = nm;
    ctab_size = 0;
    ctab = NULL;
  }

  mtype find (tree_kind kind)
  {
    tree_kind k = kind;
    mtype *mtab = (mtype *)tree_find_mtab (ctab, ctab_size, &k);
    if (mtab == NULL || mtab[k->kind_id] == NULL)
      tree_no_method (name, kind);
    return mtab[k->kind_id];
  }

  void merge (int s, tree_chunk_tab *tabs);
  
private:
  const char *name;
  int ctab_size;
  tree_chunk_tab *ctab;

  void merge_mtabs (tree_chunk_tab *ctab1, tree_chunk_tab *ctab2);
};

template<class mtype> void
tree_generic<mtype>::merge (int s, tree_chunk_tab *tabs)
{
  for (int j = 0; j < s; j++)
    {
      tree_chunk_tab *t = tabs+j;
      for (int i = 0; i < ctab_size; i++)
	if (ctab[i].chunk == t->chunk)
	  {
	    merge_mtabs (ctab+i, t);
	    goto next;
	  }
      {
	int n_size = ctab_size + 1;
	tree_chunk_tab *n_tab = new tree_chunk_tab[n_size];
	for (int i = 0; i < ctab_size; i++)
	  n_tab[i] = ctab[i];
	n_tab[ctab_size] = *t;
	delete[] ctab;
	ctab_size = n_size;
	ctab = n_tab;
      }
    next:
      ;
    }
}
template<class mtype> void
tree_generic<mtype>::merge_mtabs (tree_chunk_tab *ctab1, tree_chunk_tab *ctab2)
{
  mtype *mtab1 = (mtype *)ctab1->mtab;
  mtype *mtab2 = (mtype *)ctab2->mtab;
  mtype last1 = 0, last2 = 0, cur_m = 0;
  for (int i = 0; i < ctab1->mtab_size; i++)
    {
      if (last1 != mtab1[i] && last2 != mtab2[i])
	tree_conflicting_methods (name, ctab1->chunk->node_kinds[i]);
      if (last1 != mtab1[i])
	{
	  last1 = mtab1[i];
	  cur_m = last1;
	}
      else if (last2 != mtab2[i])
	{
	  last2 = mtab2[i];
	  cur_m = last2;
	}
      mtab1[i] = cur_m;
    }
}

void tree_register_chunk (tree_chunk_info *chunk);

void tree_set_verbose (bool);

struct tree_histogram {
  tree_histogram ();

  void enter (size_t size);
  void print ();

private:
  static const int N = 256;
  int sizes[N], min, max;
};

void *operator new (size_t size, tree_histogram *hist);

#endif
