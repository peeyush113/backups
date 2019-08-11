//Thursday 14 April 2011 04:23:03 PM IST 


//this is the program finding global minimum of rosenbrock`s function using GA
//it is a simple c program for the above benchmark function


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>

const int genes=4;
const int dimension=5;
const int population_number= 100;

float tot_fitness=0;
float max_fitness=0;
float min_fitness=0;
typedef struct chromosome
{																				//Define chromosome
	int x[5][4];
	float population_fitness;
}chromosome;


void *initialise_population(chromosome current_population[population_number])
{																				//Initialise population randomly
	int i,j,k;

	for(i=0;i<population_number;i++)
	{
		for(k=0;k<dimension;k++)
		{
			for(j=0;j<genes;j++)
			{
				current_population[i].x[k][j]=rand()%2;
			}
		}
	}

}

void *print_population(chromosome current_population[population_number])
{																				//Display current population
	int i,j,k;

	for(i=0;i<population_number;i++)
	{
		for(k=0;k<dimension;k++)
		{
			printf("x[%d]=",k);
			for(j=0;j<genes;j++)
			{
				printf("%d",current_population[i].x[k][j]);




			}

			printf("\t");

		}
		printf("\n");

		}
		
}






float x_value(int m,int n, chromosome current_population[population_number])
{																				//Convert binary to decimal
float vlaue;
/*if(current_population[m].x[n][3]==1)
{
vlaue = (-1)*(4*current_population[m].x[n][2]+2*current_population[m].x[n][1]+1*current_population[m].x[n][0]);

}
else*/
{
vlaue = (1)*(4*current_population[m].x[n][2]+2*current_population[m].x[n][1]+1*current_population[m].x[n][0]);


}

return(vlaue);

}


void *evaluate_population(chromosome current_population[population_number])
{																					//Evaluate fitness
	int m,n;
	float function_value[population_number];
	tot_fitness = 0;
	
	
	
	max_fitness=current_population[0].population_fitness;
	min_fitness=current_population[0].population_fitness;

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
		tot_fitness+=current_population[m].population_fitness;
		if(max_fitness<current_population[m].population_fitness)
			max_fitness=current_population[m].population_fitness;
			
		if(min_fitness>current_population[m].population_fitness)
			min_fitness=current_population[m].population_fitness;
			
	}

	/*for(m=0;m<population_number;m++)
	{
		printf("popfitness[%d]=%f\n",m,current_population[m].population_fitness);
	}*/

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
min_fitness=current_population[0].population_fitness;
//printf("min fitness : %f\n",min_fitness);


	/*for(m=0;m<population_number;m++)
	{
		printf("popfitness[%d]=%f\n",m,current_population[m].population_fitness);

	}*/
	
	printf("\n\nmin fitness : %f\n",min_fitness);
	printf("max fitness : %f\n",max_fitness);
	printf("total fitness: %f\n",tot_fitness);
	}




chromosome *parent_selection(chromosome current_population[population_number],chromosome selected_parent[2])
{																			//Selection of parents by roulette wheel criteria but here the population with lowest fitness is taken as highly fittest
int j,i,m;
chromosome temp;

for(j=0;j<2;j++)
{
int random = (rand()%(int)(tot_fitness-min_fitness+1))+min_fitness;

//printf("\n\nrandom number is: %d\n",random);

 int tf=0;

 	//chromosome selected_parent;

 	for(i=0;i<population_number;i++)
 	{
		 tf=tf+current_population[i].population_fitness;
		 //printf("\n\n\ntf=%d\n\n\n",tf);
		 if(tf>=random)
		 	 {selected_parent[j]=current_population[i];
		 	 goto exit;}
		 	 
 	}
exit:printf("selected parent is: %f\n",selected_parent[j].population_fitness);
}
}




chromosome crossover(chromosome selected_parent[2],chromosome child_generated[2])
{
int i,j,random;
for(i=0;i<2;i++)
{
child_generated[i]=selected_parent[i];
}
//int random_dim=rand()%5;
for(j=0;j<dimension;j++)
{
random = rand()%4;
int rando = (3-random);
for(i=0;i<random;i++)
		{
			child_generated[1].x[j][rando+i]=selected_parent[0].x[j][i];
			child_generated[1].x[j][i]=selected_parent[0].x[j][rando+i];
			child_generated[0].x[j][rando+i]=selected_parent[1].x[j][i];
			child_generated[0].x[j][i]=selected_parent[1].x[j][rando+i];
		}

}

}


void *mutation(chromosome child_generated[2])
{
int j,col,i;
//int rand_dim=rand()%5;
for(i=0;i<2;i++)
{
for(j=0;j<dimension;j++)
{

//if(rand()%10<=7)
		{	
			if(child_generated[i].x[j][0]==1)
			{
			col=rand()%3;
			if(child_generated[i].x[j][col+1]==0)
				child_generated[i].x[j][col+1]=1;
			else if(child_generated[i].x[j][col+1]==1)
				child_generated[i].x[j][col+1]=0;
			}
			else
			{
			child_generated[i].x[j][0]=1;
			
			/*col=rand()%4;
			if(child_generated[i].x[rand_dim][col]==0)
				child_generated[i].x[rand_dim][col]=1;
			else if(child_generated[i].x[rand_dim][col]==1)
				child_generated[i].x[rand_dim][col]=0;
			*/}			

}
}
}


}

double getcputime(void)
             { struct timeval tim;
               struct rusage ru;
               getrusage(RUSAGE_SELF, &ru);
               tim=ru.ru_utime;
               double t=(double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;
               tim=ru.ru_stime;
               t+=(double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;
               return t; }

void print_parent(chromosome selected_parent[2])
{
int i,j,k;

	for(i=0;i<2;i++)
	{
		for(k=0;k<dimension;k++)
		{
			printf("x[%d]=",k);
			for(j=0;j<genes;j++)
			{
				printf("%d",selected_parent[i].x[k][j]);




			}

			printf("\t");

		}
		printf("\n");

		}




}

main()
{

	clock_t start, end;
	double cpu_time_used;
	clock();
	start = clock();
	clock_t tms_utime;

	unsigned int iseed = (unsigned int)time(NULL);
	srand (iseed);


	printf("start time=%ld",start);
	printf("\n");

	int k,i,j;

	chromosome current_population[population_number];
	chromosome selected_parent[2];
	chromosome child_generated[2];
	chromosome next_population[population_number];
	
	initialise_population(current_population);
	printf("\ncurrent population generated randomly\n");
	print_population(current_population);
	printf("\ncurrent population after evoultion\n");
	evaluate_population(current_population);
	
	
	
	for(k=0;k<2000;k++)
	{
	printf("\nga started\n");
	
	for(i=0;i<population_number/2;i++)
	{
	parent_selection(current_population,selected_parent);
	printf("\nparent selected\n");
	//print_parent( selected_parent);
	crossover(selected_parent,child_generated);
	printf("\nchild after crossover\n");
	//print_parent( child_generated);
	mutation(child_generated);
	printf("\nchild after mutation\n");
	//print_parent( child_generated);
	for(j=0;j<2;j++)
	{
	next_population[i*2]=child_generated[j];
	next_population[i*2+1]=child_generated[j+1];
	}
	}
	for(i=0;i<population_number;i++)
	{
	
	current_population[i]=next_population[i];
	
	
	
	}
	printf("\nnext population\n");
	print_population(current_population);
	evaluate_population(current_population);
	for (i=0; i<population_number; i++)
		{
			if (current_population[i].population_fitness == 00.0f)
			{
				printf("\nsolution found %dth population",i);
				goto exit;
			}
		}
	printf("\n\nnumber of itrations:%d\n\n",k);
	}

exit: printf("\n\nend of all itration:\n\n");
end = clock();
printf("end time=%ld",end);
     cpu_time_used = getcputime() ;//((double) (end - start)) / CLOCKS_PER_SEC;
printf("\ntime used=%lf",cpu_time_used);
}
