
#include "type.h"
#include "sym.h"

pSym type_record::find_elem( STRING name ) 
{
  FIFO_LIST<pSym>::handle h;
  pSym elem_sym;
  pSym tmp;
	
  elem_sym = NULL;
  for (h = elem_list.first(); h != NULL; h = elem_list.next( h )) {
    tmp = elem_list.get_item( h );
    if (tmp->get_name().GetText() == name.GetText()) {
      elem_sym = tmp;
      break;
    }
  }
  return elem_sym;
} // find_elem
