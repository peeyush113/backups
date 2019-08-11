#include<stdio.h>
#include<stdlib.h>


void main()
{
unsigned int iseed = (unsigned int)time(NULL);
  srand (iseed);
int i,arr1[4],arr2[4],array[4];
//for(i=0;i<4;i++)
{
for(i=0;i<4;i++)
{
arr1[i]=rand()%2;
arr2[i]=rand()%2;
}
for(i=0;i<4;i++)
array[i]=arr2[i];
printf("\narr11=%d%d%d%d\tarr21=%d%d%d%d\n",arr1[0],arr1[1],arr1[2],arr1[3],arr2[0],arr2[1],arr2[2],arr2[3]);

int random=rand()%4;
printf("random=%d",random);
for(i=0;i<random;i++)
{
arr2[i+random]=arr1[i];
printf("\narr12=%d%d%d%d\tarr22=%d%d%d%d\n",arr1[0],arr1[1],arr1[2],arr1[3],arr2[0],arr2[1],arr2[2],arr2[3]);
arr1[i]=array[i];
printf("\narr13=%d%d%d%d\tarr23=%d%d%d%d\n",arr1[0],arr1[1],arr1[2],arr1[3],arr2[0],arr2[1],arr2[2],arr2[3]);
}


//for(i=0;i<random;i++)
{

}

printf("\narr14=%d%d%d%d\tarr24=%d%d%d%d\n",arr1[0],arr1[1],arr1[2],arr1[3],arr2[0],arr2[1],arr2[2],arr2[3]);
}




}
