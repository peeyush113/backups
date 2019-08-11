# include <stdio.h>
# include<stdilb.h>


const int dimention = 5;

typedef struct chrome
{
	float x[dimention];
	float fitness;
}chrome;

float initpopcurrent()
{
	int i,j;

	for(i=0;i<6;i++)
	{
		for(j=0;j<4;j++)
		{
			popcurrent[i].x[j]=rand()%5.12;
		}
	}

	//printpop(popcurrent);
	printf("\n");



}


float evaluatefitness()
{

int i;
	int xvalue[6],yvalue[6];
	int funcvalue[6];



	
	for(i=0;i<6;i++)
	{
		funcvalue[i]=6*(xvalue[i]-yvalue[i]*yvalue[i])*(xvalue[i]-yvalue[i]*yvalue[i])+(1-yvalue[i])*(1-yvalue[i]);
		popcurrent[i].fitness=(funcvalue[i]-0);
	}

	int j;
	chrome temp;
	
	for(j=0;j<6;j++)
	{
		if(popcurrent[j+1].fitness>popcurrent[j].fitness)
		{
			temp=popcurrent[j+1];
			popcurrent[j+1]=popcurrent[j];
			popcurrent[j]=temp;
		} 
	}

	printf("\n");

}

void main ()
{
	chrome popcurrent[6];
	initpopcurrent();
	evaluatefitness();



}
