

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stdtypes.h"
#include "fifo_list.h"
#include "str.h"
#include "sym.h"
#include "type.h"
#include "const.h"
#include "dsym.h"

main( int argc, char *argv[] )
{
    sym s;
    sym_type named_type;
    type_record rec_type;
    type_record * pRecType;

    pRecType = &rec_type;

    named_type.set_ty_type( pRecType );
} // main
