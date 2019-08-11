//Sunday 27 March 2011 01:16:15 AM IST 


//this is the program finding global minimum of rosenbrock`s function using GA 
//it is a simple c program for the above benchmark function


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>

const int geans=4;
const int dimension=5;
const int population_number= 6;

typedef struct chromosome
{
	int x[5][4];
	float population_fitness;
}chromosome;


void *initialise_population(chromosome current_population[population_number])
{
	int i,j,k;
	
	for(i=0;i<population_number;i++)
	{
		for(k=0;k<dimension;k++)
		{
			for(j=0;j<geans;j++)
			{
				current_population[i].x[k][j]=rand()%2;
			}
		}
	}
	
}

void *print_population(chromosome current_population[population_number])
{
	int i,j,k;
	
	for(i=0;i<population_number;i++)
	{
		for(k=0;k<dimension;k++)
		{
			printf("x[%d]=",k);
			for(j=0;j<geans;j++)
			{
				printf("%d",current_population[i].x[k][j]);
			
			
			
			
			}
			
			printf("\t");
			
		}
		printf("\n");
	
		}
		printf("\n");
		printf("\n");
}

	
	
	
	

float x_value(int m,int n, chromosome current_population[population_number])
{
float vlaue;
if(current_population[m].x[n][3]==1)
{
vlaue = (-1)*(4*current_population[m].x[n][2]+2*current_population[m].x[n][1]+1*current_population[m].x[n][0]);

}
else
{
vlaue = (1)*(4*current_population[m].x[n][2]+2*current_population[m].x[n][1]+1*current_population[m].x[n][0]);


}

return(vlaue);



}


void *evaluate_population(chromosome current_population[population_number])
{	
	int m,n;
	float function_value[population_number];

	for(m=0;m<population_number;m++)
	{	
		function_value[m]=0;
	}
	
	int tempo;
	
	for(m=0;m<(population_number);m++)
	{
		for(n=0;n<(dimension-1);n++)
		{ 
		tempo =100*x_value(m,n+1,current_population)-x_value(m,n,current_population)*x_value(m,n,current_population)*x_value(m,n+1,current_population)-x_value(m,n,current_population)*x_value(m,n,current_population);+(x_value(m,n,current_population)-1)*(x_value(m,n,current_population)-1);
		function_value[m]= function_value[m]+tempo;
			
		}
		
		printf("\n");
		current_population[m].population_fitness=(function_value[m]-0);
	}

	for(m=0;m<population_number;m++)
	{
		printf("popfitness[%d]=%f\n",m,current_population[m].population_fitness);
	}
	
	printf("\n");
	printf("\n");

	int j,i;
	chromosome temp;
	
	for (i=0;i<population_number-1;i++)
	{
		for(j=0;j<population_number-1;j++)
		{
	
			if(current_population[j+1].population_fitness < current_population[j].population_fitness)
			{
				temp=current_population[j+1];
				current_population[j+1]=current_population[j];
				current_population[j]=temp;
			} 
		}
	}


	for(m=0;m<population_number;m++)
	{
		printf("popfitness[%d]=%f\n",m,current_population[m].population_fitness);

	}
}

parrent_selection(chromosome current_population[population_number])
{
chromosome parrent_selected;







}

void *crossover()
{}


void *mutation()
{}

double getcputime(void)        
             { struct timeval tim;        
               struct rusage ru;        
               getrusage(RUSAGE_SELF, &ru);        
               tim=ru.ru_utime;        
               double t=(double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;        
               tim=ru.ru_stime;        
               t+=(double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;        
               return t; }        


main()
{

clock_t start, end;
     double cpu_time_used;
     clock();
     start = clock();
clock_t tms_utime;
printf("start time=%ld",start);
printf("\n");

	int k=1;
	
	chromosome current_population[population_number];
	
	initialise_population(current_population);
	print_population(current_population);
	evaluate_population(current_population);
	//do
	{
	parent_selection(current_population)
	crossover();
	mutation();
	//print_population(current_population);
	//evaluate_population(current_population);
	}//while(k=1);
	

end = clock();
printf("end time=%ld",end);
     cpu_time_used = getcputime() ;//((double) (end - start)) / CLOCKS_PER_SEC;
printf("\ntime used=%lf",cpu_time_used);
}
