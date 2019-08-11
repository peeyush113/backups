#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <freehdl/tree-supp.h>

#include "timeval.h"

static bool verbose;

void
tree_set_verbose (bool v)
{
  verbose = v;
}

static tree_base_node *living_nodes = NULL;

/* Number of nodes allocated since last collection. */
static int n_alloced = 0;

/* Number of nodes allocated prior to last collection. */
static int n_alloced_tally = 0;

/* Number of nodes collected since start of program. */
static int n_collected = 0;

tree_base_node::tree_base_node ()
{
  proptab = NULL;
  next_living = living_nodes;
  living_nodes = this;
  n_alloced++;
}

tree_base_node::~tree_base_node ()
{
  if (proptab)
    {
      delete proptab;
    }
}

void
tree_base_node::grow_props (int key)
{
  if (proptab == NULL || key >= proptab->n_props)
    {
      tree_prop_tab *new_proptab = (tree_prop_tab *)
	operator new(sizeof(tree_prop_tab) + key*sizeof(tree_prop*));
      int old_size;
      if (proptab)
	{
	  old_size = proptab->n_props;
	  for (int i = 0; i < old_size; i++)
	    new_proptab->props[i] = proptab->props[i];
	  delete proptab;
	}
      else
	old_size = 0;
      for (int i = old_size; i <= key; i++)
	new_proptab->props[i] = NULL;
      proptab = new_proptab;
      proptab->n_props = key+1;
      assert (!marked());
    }
}

tree_prop::tree_prop ()
{
}

tree_prop::~tree_prop ()
{
}

int
tree_uniq_prop_key (tree_kind kind)
{
  int key = kind->next_derived_prop_key;
  for (tree_kind b = kind->base; b; b = b->base)
    if (b->next_prop_key > key)
      key = b->next_prop_key;
  kind->next_prop_key = key+1;
  for (tree_kind b = kind; b; b = b->base)
    b->next_derived_prop_key = key+1;
  return key;
}

tree_prop
*tree_base_node::get (int key)
{
  grow_props (key);
  return proptab->props[key];
}

void
tree_base_node::put (int key, tree_prop *val)
{
  grow_props (key);
  proptab->props[key] = val;
}

void
tree_base_node::mark ()
{
  if (marked ())
    return;

  // fprintf (stderr, "marking a %s\n", kind_name ());
  setmarkbit ();
  for (tree_kind k = kind (); k; k = k->base)
    for (int i = 0; i < k->n_links; i++)
      {
	tree_base_node *n = (this->*(k->slot_info[i].loc));
	if (n)
	  n->mark ();
      }

  // mark all props
  tree_prop_tab *pt = gc_proptab ();
  if (pt)
    for (int key = 0; key < pt->n_props; key++)
      {
	tree_prop *p = pt->props[key];
	if (p)
	  {
	    tree_prop_info *pi = p->get_info ();
	    for (int i = 0; i < pi->n_links; i++)
	      {
		tree_base_node *n = (p->*(pi->slot_info[i].loc));
		if (n)
		  n->mark ();
	      }
	  }
      }
}

static int n_collection_blocks = 0;
static bool collection_requested = false;

void
tree_block_garbage_collection ()
{
  n_collection_blocks++;
}

void
tree_unblock_garbage_collection ()
{
  n_collection_blocks--;
  if (n_collection_blocks == 0 && collection_requested)
    tree_collect_garbage ();
}

double
tv_to_secs (struct timeval *tv)
{
  return tv->tv_sec + 1e-6*tv->tv_usec;
}

struct protector_node : tree_base_node {
  tree_base_node *node;
  protector_node *link;

  tree_kind kind ();
};

struct root_loc {
  root_loc *link;
  tree_base_node **loc;
};
static root_loc *root_locs;

void
tree_protect_loc (tree_base_node **loc)
{
  root_loc *rl = new root_loc;
  rl->loc = loc;
  rl->link = root_locs;
  root_locs = rl;
}

void
tree_unprotect_loc (tree_base_node **loc)
{
  for (root_loc **rlp = &root_locs; *rlp; rlp = &(*rlp)->link)
    if ((*rlp)->loc == loc)
      {
	*rlp = (*rlp)->link;
	break;
      }
}

static tree_slot_info protector_node_slot_info[] = {
  { NULL, "node", (tree_base_node*tree_base_node::*)&protector_node::node },
  { NULL, "link", (tree_base_node*tree_base_node::*)&protector_node::link },
};

static tree_kind_info protector_node_kind_info = {
  0,
  "protector_node",
  NULL,
  0,
  &protector_node_kind_info,
  0,
  2, 2, protector_node_slot_info
};

tree_kind protector_node::kind () { return &protector_node_kind_info; }

static protector_node *root_node;

void
tree_protect (tree_base_node *node)
{
  protector_node *pn = new protector_node;
  pn->node = node;
  pn->link = root_node;
  root_node = pn;
}

void
tree_unprotect (tree_base_node *node)
{
  protector_node **ppn;
  for (ppn = &root_node; *ppn; ppn = &(*ppn)->link)
    if ((*ppn)->node == node)
      {
	*ppn = (*ppn)->link;
	break;
      }
}

static int gc_thresh = 50000;

void
tree_set_gc_thresh (int thresh)
{
  gc_thresh = thresh;
}

void
tree_collect_garbage ()
{
  if (n_alloced <= gc_thresh)
    return;

  if (n_collection_blocks > 0)
    {
      if (verbose)
	fprintf (stderr, "collection blocked.\n");
      collection_requested = true;
      return;
    }

  struct timeval start, stop;

  if (verbose)
    {
      fprintf (stderr, "garbage collect:\n");
      gettimeofday (&start, NULL);
    }

  collection_requested = false;

  // mark
  if (root_node)
    root_node->mark ();
  for (root_loc *rl = root_locs; rl; rl = rl->link)
    if (*(rl->loc))
      (*(rl->loc))->mark ();
  
  // sweep
  int n_collected_prev = n_collected;
  tree_base_node **np = &living_nodes;
  while (*np)
    {
      tree_base_node *n = *np;
      if (n->marked ())
	{
	  n->clrmarkbit ();
	  np = &n->next_living;
	}
      else
	{
	  *np = n->next_living;
	  // fprintf (stderr, "deleting a %s %p\n", n->kind_name (), n);
	  n_collected++;
	  n->clrmarkbit ();
	  delete n;
	}
    }

  if (verbose)
    {
      gettimeofday (&stop, NULL);
      fprintf (stderr, " alloced totally:       %8d\n",
	       n_alloced_tally + n_alloced);
      fprintf (stderr, " since last collection: %8d\n", n_alloced);
      fprintf (stderr, " collected totally:     %8d\n", n_collected);
      fprintf (stderr, " this collection:       %8d\n",
	       n_collected - n_collected_prev);
      fprintf (stderr, " time: %g\n", tv_to_secs(&stop) - tv_to_secs(&start));
    }

  n_alloced_tally += n_alloced;
  n_alloced = 0;
}

static int next_dynamic_chunk_id = 0;

void
tree_register_chunk (tree_chunk_info *chunk)
{
  chunk->chunk_id = next_dynamic_chunk_id++;
}

bool
tree_is (tree_kind kind, tree_kind base)
{
  while (kind->chunk != base->chunk)
    {
      kind = kind->chunk_base;
      if (kind == NULL)
	return false;
    }

  return kind->kind_id >= base->kind_id
    && kind->kind_id <= base->last_derived->kind_id;
}

tree_kind
tree_base (tree_kind kind)
{
  return kind->base;
}

const char*
tree_kind_name (tree_kind kind)
{
  return kind->name;
}

/* Return a string of L spaces, but at most 30.  
 */
static const char *
spaces (int l)
{
  if (l < 0)
    return "<<";
  if (l > 30)
    l = 30;
  return "                              " + (30-l);
}

static void tree_print_1 (const char *label, tree_base_node *n, int l, int max_l);

static void
tree_print_ctype (const char *label, void *mem, int l, tree_ctype_info *info)
{
  printf ("%s%s (%s):\n%s", spaces(2*l), label, info->name, spaces(2*l+2));
  if (info->print)
    info->print (mem);
  else
    printf ("???");
  printf ("\n");
}

static void
tree_print_children (tree_base_node *n, tree_kind k, int l, int max_l)
{
  if (k->base)
    tree_print_children (n, k->base, l, max_l);
  for (int i = 0; i < k->n_slots; i++)
    {
      if (i < k->n_links)
	{ 
	  tree_base_node *c = (n->*(k->slot_info[i].loc));
	  tree_print_1 (k->slot_info[i].name, c, l+1, max_l);
	}
      else
	{
	  void *mem = (void *)&(n->*(k->slot_info[i].loc));
	  tree_print_ctype (k->slot_info[i].name, mem, l+1,
			    (tree_ctype_info*)k->slot_info[i].kind);
	}
    }
}

static void
tree_print_1 (const char *label, tree_base_node *n, int l, int max_l)
{
  if (l < max_l)
    {
      if (n == NULL)
	printf ("%s%s: NULL\n", spaces(2*l), label);
      else 
	{
	  tree_kind k = n->kind ();
	  printf ("%s%s (%s)%c\n",
		  spaces(2*l), label, k->name, (l+1<max_l)?':':'.');
	  tree_print_children (n, k, l, max_l);
	}
    }
}

void
tree_print (const char *label, tree_base_node *n, int levels)
{
  tree_print_1 (label, n, 0, levels);
}

static inline tree_chunk_tab *
find_ctab (tree_chunk_tab *ctab, int n_chunks, tree_kind kind)
{
  tree_chunk_info *ch = kind->chunk;
  for (int i = 0; i < n_chunks; i++)
    {
      if (ctab[i].chunk == ch)
	return &ctab[i];
    }
  return NULL;
}

void *
tree_find_mtab (tree_chunk_tab *ctab, int n_chunks, tree_kind *kind)
{
  tree_chunk_tab *t;
  tree_kind k = *kind;

  while ((t = find_ctab (ctab, n_chunks, k)) == NULL)
    {
      k = k->chunk_base;
      if (k == NULL)
	return NULL;
    }

  *kind = k;
  return t->mtab;
}

void
tree_no_method (const char *genfunc, tree_kind k)
{
  fprintf (stderr, "generic function `%s' undefined for node kind %s.\n",
	   genfunc, tree_kind_name (k));
  abort ();
}

void
tree_conflicting_methods (const char *genfunc, tree_kind k)
{
  fprintf (stderr, "conflicting methods for generic function `%s'"
	   " and node kind %s.\n", genfunc, tree_kind_name (k));
  abort ();
}

void *
operator new (size_t size, tree_histogram *hist)
{
  hist->enter (size);
  return operator new(size);
}

tree_histogram::tree_histogram ()
{
  min = N;
  max = 0;
  for (int i = 0; i < N; i++)
    sizes[i] = 0;
}

void
tree_histogram::enter (size_t size)
{
  if (size > (size_t) max)
    max = size;
  if (size < (size_t) min)
    min = size;
  if (size < (size_t) N)
    sizes[size]++;
  if (size % 4 !=0)
    printf ("odd size: %d\n", size);
}
 
void
tree_histogram::print ()
{
  printf ("min = %d, max = %d\n", min, max);
  for (int i = min; i <= max && i < N; i+=4)
    printf (" %3d: %6d\n", i, sizes[i]);
}
