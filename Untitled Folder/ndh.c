#include <stdio.h>
#include<stdlib.h>


main()
{ 	int lim = 40;
	int b = 0;
  static long a;
a = (unsigned int)time(NULL);

        a = (((a * 214013L + 2531011L) >> 16) & 32767);
    b = (a % lim) + 1;
    

printf("random no:%25d",b);

}
