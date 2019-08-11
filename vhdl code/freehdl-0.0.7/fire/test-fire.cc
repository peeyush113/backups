#include <iostream>
#include <stdio.h>
#include <freehdl/fire.h>

using namespace std;

extern tree_chunk_info fire_chunk_info;

void
print_size_histogram (tree_chunk_info *ch)
{
  const int N = 256;
  int sizes[N], min = N, max = 0;

  for (int i = 0; i < N; i++)
    sizes[i] = 0;
  for (int i = 0; i < ch->n_kinds; i++)
    {
      tree_kind k = ch->node_kinds[i];
      if (k->size > (size_t) max)
	max = k->size;
      if (k->size < (size_t) min)
	min = k->size;
      if (k->size < (size_t) N)
	sizes[k->size]++;
      if (k->size % 4 !=0)
	printf ("odd size: %d\n", k->size);
    }
  printf ("min = %d, max = %d\n", min, max);
  for (int i = min; i <= max && i < N; i+=4)
    printf (" %3d: %3d\n", i, sizes[i]);
}

int
main ()
{
  tree_histogram hist;

  print_size_histogram (&fire_chunk_info);
  tree_block_garbage_collection ();
  IIR *n = new(&hist) IIR_TextLiteral (new(&hist)
				      IIR_PosInfo_TextFile ("foo", 42),
				      IR_String("Yo!"));
  cout << "Allocated a `" << n << "' at " << n->pos << ".\n";
  cout << "Is it a literal?  " << (n->is (IR_LITERAL)? "yes":"no") << "\n";
  cout << "Exactly: " << n->kind_name () << ".\n";

  tree_print ("n", n, 5);

  tree_protect (n);
  tree_unblock_garbage_collection ();

  tree_collect_garbage ();

  cout << "Still: " << n->kind_name () << ".\n";

  tree_unprotect (n);
  tree_collect_garbage ();

  hist.print ();

  return 0;
}
