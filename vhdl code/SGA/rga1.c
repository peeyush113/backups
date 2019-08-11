/********************************************************************\
***                                                                ***
***                      GENETIC ALGORITHM                         ***
***                                                                ***
***               Developed By : Prof. Kalyanmoy Deb               ***
***               with assistance from his Students                ***
***                                                                ***
*** Last Edited : 06.10.2001                                       ***
***................................................................***
This is a GA implementation using binary and real coded 
variables. There is a sample input file (input) which can be used to run
this code. Default values are suggested in the input file.

Code your objective function at the end of the code (in objective()

Variable boundaries can be fixed or fleexible

Following selection opeartors are coded:
1. Tournament selection: Set MINM=1 for minimization and -1 for maximization
2 and 3. Roulette wheel or Stochastic remainder RW selection: 
        Only maximization is allows (ENSURE MINM = -1 and 
        the obj. func. is to be maximized). For minimizing f(x) use the
        following objective function for maximization:
                     Fitness = 1.0/(1.0+f(x))

Following crossover operators are allowed: 
Binary coded GAs : single-point crossover
Real-coded GAs: SBX-eta or BLX-0.5
1. All variables upto a site are crossed and rest swapped
2. 50% variables are swapped at random (preferred)
3. Crossover is performed on a line

Mutation: bit-wise for Binary coded GAs and polynomial mutation (with eta) for
          Real coded GAs

Constraints are handled using simple penalty function approach

Fitness sharing in parameter space is also allowed (Stochastic rem RW 
     is default selection opeartor) 

The execution creates a file `realga.out' for inspection.

Send Comments to De. K. Deb (deb@iitk.ac.in)    
**************************************************************************/

#include<stdio.h>
#include<math.h>
#define BITS_PER_BYTE 8
#define UINTSIZE (BITS_PER_BYTE*sizeof(unsigned))
#define INFINITY 1e7
#define EPSILON  1e-6
#define PI 3.1415927
#define MAXVECSIZE 30
#define MAXPOPSIZE 1000
#define TRUE 1
#define FALSE 0
#define BLX 0
#define SBX 1
#define ONESITE 1
#define UNIF 2
#define ONLINE 3
#define square(x)  ((x)*(x))
/***** Current Objective Function ******/
#define prob1  /* define your problem at the end in objfunc() */

/*=================
TYPE DEFINTIONS :
=================*/
struct indiv
            {  float x[MAXVECSIZE];     /* variables            */
               float obj;               /* objective fn. value  */
               float mod_obj;           /* modified objective   */
               unsigned *chrom;         /* chrosome string      */
               int parent1;
               int parent2;             /* s.no. of parents     */
               float cross_var;         /* cross over variable  */
            };
typedef struct indiv INDIVIDUAL ;
typedef INDIVIDUAL *POPULATION ;        /* array of individuals */

/*====================
FUNCTION PROTOTYPES :
====================*/
float   objective();
float   degraded_value();
float   randomperc();
float   get_beta();
float   get_delta();
double  noise();
float   rndreal();

/*==================
GLOBAL VARIABLES  :
==================*/
int     pop_size,               /* Population Size                      */
        gen_no,                 /* Current generation number            */
        max_gen,                /* Maximum no. of generations           */
        no_xover,               /* No. of cross overs done              */
        no_mutation,            /* No. of mutations done                */
        best_ever_gen,          /* Generation no. of best ever indiv.   */
        num_var,                /* Number of total design variables     */
        num_discr_var,          /* Number of discrete variables         */
        lchrom,                 /* Length of chromosome                 */
        chromsize,              /* Number of bytes needed to store
                                                lchrom strings          */
        cross_type,             /* Cross over type ( SBX / BLX )        */
        x_strategy,s_strategy,  /* Cross-over strategy UNIF,ONLINE etc. */
        maxrun,                 /* Maxm no. of GA runs for each set of
                                              parameter values          */
        run,                    /* Actual run no.                       */
        SHARING,                /* Flag for Sharing ( True / False)     */
        REPORT,                 /* Flag for Full reports (True/False)   */
        RIGID,                  /* Flag for rigid boundaries (T/F)      */
        BINGA,                  /* Flag for binary GA (T/F)             */
        REALGA,                 /* Flag for real-GA (T/F)               */
        READFILE,               /* Flag for reading input from file     */
        tourneylist[MAXPOPSIZE],/* List of indices of individuals for
                                        tournament selection routine    */
        tourneypos,             /* Current position of tournament       */
        tourneysize,            /* Tournament size ( = 2 for binary )   */
        MINM;
float   seed,                   /* Random seed number                   */
        basic_seed,             /* Basic seed number                    */
  n_distribution_c, n_distribution_m,
        p_xover,                /* Cross over probability               */
        p_mutation,             /* Mutation probability                 */
        sum_obj,                /* Sum of objective fn. values          */
        avg_obj,                /* Average of objective fn. values      */
        max_obj,                /* Maximum objective fn. value          */
        min_obj,                /* Minimum objective fn. value          */
        minx[MAXVECSIZE],       /* Minimum and maximum values of design */
        maxx[MAXVECSIZE],       /*        variables in a population     */
        x_lower[MAXVECSIZE],    /* Lower and Upper bounds on each       */
        x_upper[MAXVECSIZE],    /*        design variable               */
        sigma_share;            /* Sharing distance                     */

POPULATION oldpop, newpop;      /* Old and New populations              */
INDIVIDUAL best_ever;           /* Best fit individual till current gen.*/

/*====================================================================
SUBROUTINE FOR INPUTTING GLOBAL PARAMETERS :
====================================================================*/
input_parameters()
{
   int k;
   char ans;

   printf("       ");
   puts("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
   printf("       ");
   puts("::::::::       REAL-CODED GENETIC ALGORITHM        :::::::");
   printf("       ");
   puts("::::::::       ============================        :::::::");
   printf("       ");
   puts("::::::::     (c) R.B.Agrawal and K.Deb, 1995;      :::::::");
   printf("       ");
   puts("::::::::            All rights reserved.           :::::::");
   printf("       ");
   puts("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");

   printf("\n ARE YOU READING IT THROUGH A COMMENTED FILE (y/n) ?");
   do { ans = getchar(); } while (ans!= 'y' && ans !='n');
   if (ans == 'y')      READFILE = TRUE;
   else                 READFILE = FALSE;

   if (READFILE) printf("\n Reading data from file ............");
   if (!READFILE) printf("\nHow many generations ? ------------- : ");
   ignore_comment();
   scanf("%d",&max_gen);
   if (!READFILE)  printf("\nPopulation Size ? ------------------ : ");
   ignore_comment();
   scanf("%d", &pop_size );
   if (pop_size > MAXPOPSIZE)
   {
        printf("\n Increase the value of MAXPOPSIZE in program");
        printf("  and re-run the program");
        exit(-1);
   }
   if (!READFILE) printf("\nCross Over Probability ? ( 0 to 1 )  : ");
   ignore_comment();
   scanf("%f",&p_xover);
   if (!READFILE) printf("\nMutation Probability ? ( 0 to 1 ) -- : ");
   ignore_comment();
   scanf("%f",&p_mutation);
   if (!READFILE)
        printf("\nNumber of variables (Maximum %d) ---- : ",MAXVECSIZE);
   ignore_comment();
   scanf("%d",&num_var);
   BINGA = REALGA = FALSE;
   if (!READFILE) printf("\n Binary or Real-coded parameters? (b for binary, r for real-coded) ");
   ignore_comment();
   do { ans = getchar(); } while (ans!= 'b' && ans !='r');
   if (ans == 'b') BINGA = TRUE;
   else            REALGA = TRUE;
   if (BINGA) num_discr_var = num_var;
   ignore_comment(); 
   for (k=0; k<= num_var-1; k++)
     {
       if (!READFILE) printf("\nLower and Upper bounds of x[%d] ----- : ",k+1);
       scanf("%f %f",&x_lower[k],&x_upper[k]);
     }
   if (REALGA) {
     if (!READFILE) printf("\n Are these bounds rigid ? (y/n)");
     ignore_comment();
     do { ans = getchar(); } while (ans!= 'y' && ans !='n');
     if (ans == 'y')      RIGID = TRUE;
     else  RIGID = FALSE;
   } else {
     if (READFILE) {
       ignore_comment();
       ans = getchar();
       RIGID = TRUE;
     }
   }
   if (BINGA)
     {
       if (!READFILE) printf("\n Total string length (each variable has equal string length)?");
	 ignore_comment();
	 scanf("%d",&lchrom);
     }
   else 
     if (READFILE) {
       ignore_comment();
       scanf("%d",&lchrom);
       lchrom=0;
     }
   if (!READFILE) printf("\nSharing to be done ? (y/n) --------- :");
   ignore_comment();
   do { ans = getchar(); } while (ans!= 'y' && ans !='n');
   if (ans == 'y')
   { SHARING = TRUE;
     if (!READFILE) printf("\nSigma share value  ? --------------- :");
     scanf("%f",&sigma_share);
   }
   else  SHARING = FALSE;
   if (!READFILE) printf ("\n Reports to be printed ? (y/n) ");
   ignore_comment();
   do { ans = getchar(); } while (ans!= 'y' && ans !='n');
   if (ans == 'y') REPORT = TRUE;
   else            REPORT = FALSE;
   if (!READFILE) printf("\n How many runs ?");
   ignore_comment();
   scanf("%d",&maxrun);
   if (!READFILE) 
     {
       printf("\n Enter selection operator --> ");
       printf("\n  1 : Tournament selection (min or max set by MINM in the code)");
       printf("\n  2 : Roulette wheel selection (always max)");
       printf("\n  3 : Stochastic remainder roulette wheel selection (always max)");
       printf("\n  Give your choice :");
     }
   ignore_comment();
   scanf("%d",&s_strategy);
   if (s_strategy == 1) {
     if (!READFILE) printf("\n Enter tournament size ");
     ignore_comment();
     scanf("%d", &tourneysize);
   } else 
     if (READFILE) {
       ignore_comment();
       scanf("%d",&tourneysize);
       tourneysize=0;
     }
   if (SHARING) s_strategy = 3; /* Stoch. Rem. RW is default */
   printf("TTTTT  %d \n",tourneysize);
   if (REALGA)
     {
       if (!READFILE)
	 {
	   printf("\n  Give the strategy for X-over");
	   printf("\n  1 : Polynomial distribution in one variable");
	   printf("\n  2 : Polynomial distribution in all variables");
	   printf("\n  3 : Polynomial distribution on a straight line");
	   printf("\n  Give your choice :");
	 }
       ignore_comment();
       scanf("%d",&x_strategy);
       
       if (!READFILE) printf("\n Type of cross over ? ( s for SBX, b for BLX) ");
       ignore_comment();
       do { ans = getchar(); } while (ans!= 's' && ans !='b');
       if (ans == 's') cross_type = SBX;
       else            cross_type = BLX;
       if (cross_type == SBX)
	 {
	   if (!READFILE) printf("\n Give eta for SBX and mutation?");
	   ignore_comment();
	   scanf("%f %f",&n_distribution_c,&n_distribution_m);
	 }
     }
   else {
     ignore_comment();
     scanf("%d",&x_strategy);
     x_strategy = 1; /* binary crossover */
     ignore_comment();
     ans = getchar();
     ignore_comment();
     scanf("%f %f",&n_distribution_c,&n_distribution_m);
     n_distribution_c = 0; n_distribution_m = 0;
   }
   if (!READFILE) printf("\n Give random seed (0 to 1.0)");
   ignore_comment();
   scanf("%f",&basic_seed);

   input_app_parameters();
}
/*====================================================================
  Ignores the comment from input ( ended by a ':')
====================================================================*/
ignore_comment()
{
    if (READFILE == FALSE) return;

    do
    {}
    while (getchar() != ':');
}
/*====================================================================
Initialses zero'th generation and global parameters
====================================================================*/
initialize()
{
   float u;
   int k,k1,i,j,j1,stop;
   double temp[MAXVECSIZE],coef;
   unsigned mask=1,nbytes;

   randomize();
   app_initialize();
   oldpop = (INDIVIDUAL *)malloc(pop_size*sizeof(INDIVIDUAL));
   newpop = (INDIVIDUAL *)malloc(pop_size*sizeof(INDIVIDUAL));
   if (oldpop == NULL) nomemory("oldpop in initialize()");
   if (newpop == NULL) nomemory("newpop in initialize()");

   chromsize = (lchrom/UINTSIZE);
   if(lchrom%UINTSIZE) chromsize++;
   nbytes = chromsize*sizeof(unsigned);
   for(j = 0; j < pop_size; j++)
   {
      if((oldpop[j].chrom = (unsigned *) malloc(nbytes)) == NULL)
        nomemory("oldpop chromosomes");

      if((newpop[j].chrom = (unsigned *) malloc(nbytes)) == NULL)
        nomemory("newpop chromosomes");
   }
   if((best_ever.chrom = (unsigned *) malloc(nbytes)) == NULL)
      nomemory("best_ever chromosomes");

   for (k=0; k<= pop_size-1; k++)
   {
      oldpop[k].parent1 = oldpop[k].parent2 = 0;
      for (j=num_discr_var; j<=num_var-1; j++)
      {
         u = randomperc();
         oldpop[k].x[j] = x_lower[j] * (1-u) + x_upper[j] * u;
      }
      for(k1 = 0; k1 < chromsize; k1++)
      {
            oldpop[k].chrom[k1] = 0;
            if(k1 == (chromsize-1))
                stop = lchrom - (k1*UINTSIZE);
            else
                stop = UINTSIZE;
            /* A fair coin toss */
            for(j1 = 1; j1 <= stop; j1++)
            {
               if(flip(0.5))
                  oldpop[k].chrom[k1] = oldpop[k].chrom[k1]|mask;
               if (j1 != stop) oldpop[k].chrom[k1] = oldpop[k].chrom[k1]<<1;
            }
      }
   }
   no_xover = no_mutation = 0;
   copy_individual(&oldpop[0],&best_ever);
   decode_string(&best_ever);
   best_ever.obj = objective(best_ever.x);

}

/*====================================================================
Decodes the string of the individual (if any) and puts the values in
the array of floats.
====================================================================*/
decode_string(ptr_indiv)
INDIVIDUAL *ptr_indiv;
{
   double *temp,coef;
   int j;

   if (ptr_indiv == NULL) error_ptr_null("ptr_indiv in decode_string");
   if (BINGA)
   {
     temp = (double *) malloc(num_discr_var * sizeof(double));
     for(j=0; j<=num_discr_var - 1; j++) temp[j] = 0.0;
     decodevalue(ptr_indiv->chrom,temp);
     coef = pow(2.0,(double)(lchrom/num_discr_var)) - 1.0;
     for(j=0; j<=num_discr_var - 1; j++)
     {
        temp[j] = temp[j]/coef;
        ptr_indiv->x[j] = temp[j]*x_upper[j] + (1.0 - temp[j])*x_lower[j];
     }
     free(temp);
   }
}
/*====================================================================
Prints an error message and terminates the program
====================================================================*/
nomemory(string)
char *string;
{
   printf("\nmalloc: out of memory making %s!!\n",string);
   printf("\n Program is halting .....");
   exit(-1);
}
/*==============================================================
Gives error message of null pointer  and terminates the program.
==============================================================*/
error_ptr_null(string)
char *string;
{
   printf("\n Error !! Pointer %s found Null !",string);
   printf("\n Program is halting .....");
   exit(-1);
}
/*====================================================================
Copys contents of one individual into another.
====================================================================*/
copy_individual(indiv1,indiv2)
INDIVIDUAL *indiv1, *indiv2;
{
   int k;

   if (indiv1==NULL) error_ptr_null("indiv1 in copy_individual");
   if (indiv2==NULL) error_ptr_null("indiv2 in copy_individual");
   for (k=0; k<= MAXVECSIZE-1; k++)
      indiv2->x[k] = indiv1->x[k];
   indiv2->mod_obj = indiv1->mod_obj;
   indiv2->obj = indiv1->obj;
   indiv2->parent1 = indiv1->parent1;
   indiv2->parent2 = indiv1->parent2;
   indiv2->cross_var = indiv1->cross_var;
   for (k=0; k<= chromsize; k++)
        indiv2->chrom[k] = indiv1->chrom[k];
}
/*====================================================================
Calculates statistics of current generation :
====================================================================*/
statistics(gen)
int gen;
{
   INDIVIDUAL current_best;
   int k,j;
   float f;
   double pow(),bitpow,coef,temp[MAXVECSIZE];

   for (k=0; k<=pop_size-1; k++)
   {
     decode_string(&oldpop[k]);
     oldpop[k].obj = objective(oldpop[k].x);

     if (SHARING)
        oldpop[k].mod_obj = degraded_value(oldpop[k].obj,oldpop[k].x,oldpop);
     else oldpop[k].mod_obj = oldpop[k].obj;
   }
   if ( gen == 0)
   {
     if (SHARING)
        best_ever.mod_obj = degraded_value(best_ever.obj,best_ever.x,oldpop);
     else best_ever.mod_obj = best_ever.obj;
   }

   current_best = oldpop[0];
   sum_obj = avg_obj = oldpop[0].obj;
   max_obj = min_obj = oldpop[0].obj;
   for (k=0;  k<= num_var-1 ; k++) maxx[k] = minx[k] = oldpop[0].x[k];

   for(k=1; k<= pop_size-1; k++)
   {
     if(MINM * current_best.obj  >  MINM * oldpop[k].obj)
                   current_best = oldpop[k];
     if(MINM * max_obj < MINM * oldpop[k].obj)
                   max_obj = oldpop[k].obj;
     if(MINM * min_obj > MINM * oldpop[k].obj)
                   min_obj = oldpop[k].obj;
     sum_obj += oldpop[k].obj;
     for (j=0; j<= num_var-1; j++)
     {
        if (MINM * maxx[j] < MINM * oldpop[k].x[j]) maxx[j] = oldpop[k].x[j];
        if (MINM * minx[j] > MINM * oldpop[k].x[j]) minx[j] = oldpop[k].x[j];
     }
   };
   avg_obj = sum_obj/pop_size;
   if (MINM * current_best.obj < MINM * best_ever.obj)
   { copy_individual(&current_best, &best_ever);
     best_ever_gen = gen;
   }
   app_statistics();
}

/*====================================================================
Decodes the value of a group of binary strings and puts the decoded
values into an array 'value'.
====================================================================*/
decodevalue(chrom,value)
unsigned *chrom;
double value[];
{
    int k,j,stop,tp,bitpos,mask=1,position,bits_per_var;
    double pow(), bitpow;

    if (BINGA == FALSE) return;
    if (chrom == NULL) error_ptr_null("chrom in decodevalue");

    bits_per_var = lchrom/num_discr_var;
    for(k = 0; k < chromsize; k++)
    {
        if(k == (chromsize-1))
            stop = lchrom-(k*UINTSIZE);
        else
            stop = UINTSIZE;
        /* loop thru bits in current byte */
        tp = chrom[k];
        for(j = 0; j < stop; j++) {
            bitpos = j + UINTSIZE*k;
            /* test for current bit 0 or 1 */
            if((tp&mask) == 1) {
                position = bitpos / bits_per_var;
                bitpos -= position * bits_per_var;
                bitpow = pow(2.0,(double)(bits_per_var- bitpos-1));
                value[position] += bitpow;
            }
            tp = tp>>1;
        }
    }
}
/*====================================================================
DEGRADED VALUE (DUE TO SHARING) OF ACUTAL OBJECTIVE FUNCTION VALUE :
====================================================================*/
float degraded_value(f,x,pop)
float f, x[];
POPULATION pop;
{
   int k,j;
   float summation,dist,dist_sq;

   if (pop == NULL) error_ptr_null("pop in degraded_value");
   if (x ==NULL) error_ptr_null("x in degraded_value");
   summation = 0;
   for (k=0; k<= pop_size-1; k++)
   {
      dist_sq = 0;
      for (j=0; j<= num_var-1; j++)
         dist_sq += (x[j] - pop[k].x[j]) * (x[j] - pop[k].x[j]) ;
      dist = sqrt(dist_sq);
      if (dist <= sigma_share) summation += 1.0 - dist/sigma_share;
   }
   if (summation < 1.0) summation = 1.0;
   return (f/summation);
}

/*====================================================================
GENERATION OF NEW POPULATION through SELECTION, XOVER & MUTATION :
====================================================================*/
generate_new_pop()
{
   int k,mate1,mate2;

   app_computation();
   switch (s_strategy)
     {
     case 1 : preselect_tour(); break;
     case 2 : preselect_rw(); break;
     case 3 : preselect_sr(); break;
     }
   for (k=0; k<= pop_size-1; k +=2)
   {
     switch (s_strategy)
     {
     case 1 :  mate1 = tour_select(); mate2 = tour_select(); break;
     case 2 :  mate1 = rw_select(); mate2 = rw_select(); break;
     case 3 :  mate1 = sr_select(); mate2 = sr_select(); break;
     }
     switch( x_strategy)
     {
       case ONESITE :  cross_over_1_site(mate1,mate2,k,k+1); break;
       case UNIF :  cross_over_unif(mate1,mate2,k,k+1); break;
       case ONLINE: cross_over_line(mate1,mate2,k,k+1); break;
     }
     mutation(&newpop[k]);
     mutation(&newpop[k+1]);
     newpop[k].parent1 = newpop[k+1].parent1 = mate1+1;
     newpop[k].parent2 = newpop[k+1].parent2 = mate2+1;
   }
}

/*====================================================================
Binary cross over routine.
====================================================================*/
binary_xover (parent1, parent2, child1, child2)
unsigned *parent1, *parent2, *child1, *child2;
/* Cross 2 parent strings, place in 2 child strings */
{
    int j, jcross, k;
    unsigned mask, temp;

    if (BINGA == FALSE) return;
    if (parent1 == NULL) error_ptr_null("parent1 in binary_xover");
    if (parent2 == NULL) error_ptr_null("parent2 in binary_xover");
    if (child1== NULL) error_ptr_null("child1 in binary_xover");
    if (child2== NULL) error_ptr_null("child2 in binary_xover");

    jcross = rnd(1 ,(lchrom - 1));/* Cross between 1 and l-1 */
    for(k = 1; k <= chromsize; k++)
    {
            if(jcross >= (k*UINTSIZE))
            {
                child1[k-1] = parent1[k-1];
                child2[k-1] = parent2[k-1];
            }
            else if((jcross < (k*UINTSIZE)) && (jcross > ((k-1)*UINTSIZE)))
            {
                mask = 1;
                for(j = 1; j <= (jcross-1-((k-1)*UINTSIZE)); j++)
                {
                    temp = 1;
                    mask = mask<<1;
                    mask = mask|temp;
                }
                child1[k-1] = (parent1[k-1]&mask)|(parent2[k-1]&(~mask));
                child2[k-1] = (parent1[k-1]&(~mask))|(parent2[k-1]&mask);
            }
            else
            {
                child1[k-1] = parent2[k-1];
                child2[k-1] = parent1[k-1];
            }
    }
}
/*====================================================================
Creates two children from parents p1 and p2, stores them in addresses
pointed by c1 and c2.  low and high are the limits for x values and
rand_var is the random variable used to create children points.
====================================================================*/
create_children(p1,p2,c1,c2,low,high,rand_var)
float p1,p2,*c1,*c2,low,high,*rand_var;
{
    float difference,x_mean,beta;
    float u,distance,umax,temp,alpha;
    int flag;

    if (c1 == NULL) error_ptr_null("c1 in create_children");
    if (c2 == NULL) error_ptr_null("c2 in create_children");
    if (rand_var == NULL) error_ptr_null("rand_var in create_children");
    flag = 0;
    if ( p1 > p2) { temp = p1; p1 = p2; p2 = temp; flag = 1; }
    x_mean = ( p1 + p2) * 0.5;
    difference = p2 - p1;
    if ( (p1-low) < (high-p2) ) distance = p1-low;
    else                        distance = high-p2;
    if (distance < 0.0) distance = 0.0;
    if (RIGID && (difference > EPSILON))
    {
      alpha = 1.0 + (2.0*distance/difference);
      umax = 1.0 - (0.5 / pow((double)alpha,(double)(n_distribution_c+1.0)));
      *rand_var = umax * randomperc();
    }
    else *rand_var = randomperc();
    beta = get_beta(*rand_var);
    if (fabs(difference*beta) > INFINITY) beta = INFINITY/difference;
    *c2 = x_mean + beta * 0.5 * difference;
    *c1 = x_mean - beta * 0.5 * difference;
    if (flag == 1) { temp = *c1; *c1 = *c2; *c2 = temp; }
}
/*====================================================================
cross over using strategy of 1 cross site with swapping .
  A random variable is chosen and crossed over. The variables on left
  side are passed as it is and those on right are swapped between the
  two parents.
====================================================================*/
cross_over_1_site(first,second,childno1,childno2)
int first,second,childno1,childno2;
{
    int k,site;
    float u;

    if (flip(p_xover))   /* Cross over has to be done */
    {
      no_xover++;
      if (BINGA)
      binary_xover(oldpop[first].chrom,oldpop[second].chrom,
                   newpop[childno1].chrom,newpop[childno2].chrom);
      if ( REALGA )
      {
        site = rnd(num_discr_var,num_var-1);
        for (k=0; k<=site-1; k++)
        {
          newpop[childno1].x[k] = oldpop[first].x[k];
          newpop[childno2].x[k] = oldpop[second].x[k];
        }
        for (k=site+1; k<=num_var-1; k++)
        {
          newpop[childno2].x[k] = oldpop[first].x[k];
          newpop[childno1].x[k] = oldpop[second].x[k];
        }
        create_children(oldpop[first].x[site],oldpop[second].x[site],
                      &(newpop[childno1].x[site]),&(newpop[childno2].x[site]),
                      x_lower[site],x_upper[site],&u);
        newpop[childno1].cross_var = newpop[childno2].cross_var = u;
      }

    }                 /* Cross over done */

    else              /* Passing x-values straight */
    {
      if (BINGA)
      for (k=0; k<=chromsize; k++)
      {
        newpop[childno1].chrom[k] = oldpop[first].chrom[k];
        newpop[childno2].chrom[k] = oldpop[second].chrom[k];
      }
      for (k=0; k<=num_var-1; k++)
      {
        newpop[childno1].x[k] = oldpop[first].x[k];
        newpop[childno2].x[k] = oldpop[second].x[k];
      }
    }
}
/*====================================================================
CROSS - OVER  USING strategy of uniform 50% variables
  For one variable problem, it is crossed over as usual.
  For multivariables, each variable is crossed over with a probability
  of 50 % , each time generating a new random beta.
====================================================================*/
cross_over_unif(first,second,childno1,childno2)
int first,second,childno1,childno2;
{
    float difference,x_mean,beta;
    float u = 0.0;
    int site,k;

    if (flip(p_xover))   /* Cross over has to be done */
    {
     no_xover++;
     if (BINGA)
     binary_xover(oldpop[first].chrom,oldpop[second].chrom,
                  newpop[childno1].chrom,newpop[childno2].chrom);
     if (REALGA)
     {
      for (site = num_discr_var; site<=num_var-1; site++)
      {
       if(flip(0.5) || (num_var==1))
       {
         create_children(oldpop[first].x[site],oldpop[second].x[site],
                      &(newpop[childno1].x[site]),&(newpop[childno2].x[site]),
                      x_lower[site],x_upper[site],&u);
       }
       else
       {
        newpop[childno1].x[site] = oldpop[first].x[site];
        newpop[childno2].x[site] = oldpop[second].x[site];
       }
      }               /* for loop */
     newpop[childno1].cross_var = newpop[childno2].cross_var = u;
     }                /* if REALGA      */
    }                 /* Cross over done */

    else              /* Passing x-values straight */
    {
      if (BINGA)
      for (k=0; k<=chromsize; k++)
      {
        newpop[childno1].chrom[k] = oldpop[first].chrom[k];
        newpop[childno2].chrom[k] = oldpop[second].chrom[k];
      }
      for (site=0; site<=num_var-1; site++)
      {
        newpop[childno1].x[site] = oldpop[first].x[site];
        newpop[childno2].x[site] = oldpop[second].x[site];
      }
    }
}
/*====================================================================
CROSS - OVER strategy  ON A STRAIGHT LINE
  A random beta is generated and used to decide all the design
  variables for children. The effect is that offsprings are generated
  on a straight line joining the parents.
====================================================================*/
cross_over_line(first,second,childno1,childno2)
int first,second,childno1,childno2;
{
    float difference,x_mean,beta;
    float u,distance,dist1,dist2,alpha,min_alpha,umax;
    float p1,p2,temp;
    int site,k;

    if (flip(p_xover))   /* Cross over has to be done */
    {
     if (RIGID)
     {
        min_alpha = INFINITY;
        for (site=0; site <= num_var-1; site++)
        {
                p1 = oldpop[first].x[site];
                p2 = oldpop[second].x[site];
                if ( p1 > p2) {  temp = p1; p1 = p2; p2 = temp; }
                difference = p2 -p1;
                dist1 = p1 - x_lower[site] ;
                dist2 = x_upper[site] - p2;
                if (dist1 < dist2) distance = dist1; else distance = dist2;
                if (distance < 0.0) distance = 0.0;
                if (difference > EPSILON)
                {
                        alpha = 1.0 + (2.0*distance/difference);
                        if (min_alpha > alpha) min_alpha = alpha;
                }
        }
        if ( min_alpha < 0.0) min_alpha = 0.0;
        umax = 1.0- (0.5/pow((double)min_alpha,(double)(n_distribution_c+1.0)));
        u = umax * randomperc();
     }
     else u = randomperc();
     beta = get_beta(u);
     no_xover++;
     if (BINGA)
     binary_xover(oldpop[first].chrom,oldpop[second].chrom,
                  newpop[childno1].chrom,newpop[childno2].chrom);
     newpop[childno1].cross_var = newpop[childno2].cross_var = u;
     if (REALGA)
     {
       for (site = 0; site<=num_var-1; site++)
       {
         x_mean = (oldpop[first].x[site] + oldpop[second].x[site]) * 0.5;
         difference = oldpop[second].x[site] - oldpop[first].x[site];
         if (fabs(difference*beta) > INFINITY) beta = INFINITY/difference;
         newpop[childno1].x[site] = x_mean + beta * 0.5 * difference;
         newpop[childno2].x[site] = x_mean - beta * 0.5 * difference;
       }              /* for loop */
     }                /* if REALGA*/
    }                 /* Cross over done */

    else              /* Passing x-values straight */
    {
      if (BINGA)
      for (k=0; k<=chromsize; k++)
      {
        newpop[childno1].chrom[k] = oldpop[first].chrom[k];
        newpop[childno2].chrom[k] = oldpop[second].chrom[k];
      }
      for (site=0; site<=num_var-1; site++)
      {
        newpop[childno1].x[site] = oldpop[first].x[site];
        newpop[childno2].x[site] = oldpop[second].x[site];
      }
    }
}
/*===================================================================
Calculates beta value for given random number u (from 0 to 1)
If input random numbers (u) are uniformly distributed for a set of
inputs, this results in uniform distribution of beta values in case
of BLX , and Binary Probability distribution simulation in case of
SBX.
====================================================================*/
float get_beta(u)
float u;
{
   float beta;

   if (cross_type == BLX) return(2.0*u);
   if (1.0-u < EPSILON ) u = 1.0 - EPSILON;
   if ( u < 0.0) u = 0.0;
   if (u < 0.5) beta = pow(2.0*u,(1.0/(n_distribution_c+1.0)));
   else beta = pow( (0.5/(1.0-u)),(1.0/(n_distribution_c+1.0)));
   return beta;
}
/*==================================================================
For given u value such that   -1 <= u <= 1, this routine returns a
value of delta from -1 to 1. Exact value of delta depends on specified
n_distribution. This is called by mutation().
====================================================================*/
float get_delta(u)
float u;
{
   float delta;
   int negative = FALSE;   /* Flag for negativeness of delta */

   if (cross_type == BLX) return(u);
   if(u <= -1.0) u = -1.0;
   if(u >1.0)  u =  1.0;
   if(u < 0.0)  {  u = -u;
                   negative = TRUE;
                }
   delta = 1.0 - pow((1.0 - u),(1.0 / (n_distribution_m + 1.0)));
   if(negative)  return (-delta);
   else          return delta;

}
/*==================================================================
Binary mutation routine ( borrowed from sga.c )
====================================================================*/
binmutation(child)
unsigned *child;
/* Mutate an allele w/ pmutation, count # of mutations */
{
    int j, k, stop;
    unsigned mask, temp = 1;

    if (BINGA == FALSE) return;
    if (child== NULL) error_ptr_null(" child in binmutation");
    for(k = 0; k < chromsize; k++)
    {
        mask = 0;
        if(k == (chromsize-1))
            stop = lchrom - ((k-1)*UINTSIZE);
        else
            stop = UINTSIZE;
        for(j = 0; j < stop; j++)
        {
            if(flip(p_mutation))
            {
                mask = mask|(temp<<j);
            }
        }
        child[k] = child[k]^mask;
    }
}
/*===================================================================
Mutation Using polynomial probability distribution. Picks up a random
site and generates a random number u between -1 to 1, ( or between
minu to maxu in case of rigid boudaries) and calls the routine
get_delta() to calculate the actual shift of the value.
====================================================================*/
mutation(indiv)
INDIVIDUAL  *indiv;
{
   float distance1,distance2,x,delta,minu,maxu,u;
   int k, site;

   if (indiv == NULL) error_ptr_null("indiv in mutation");
   if(flip (p_mutation) && REALGA)
   {
        site = rnd(num_discr_var,num_var - 1);
        no_mutation++;
        if(fabs(x_upper[site] -x_lower[site]) < EPSILON) return;

        /* calculation of bounds on delta */
        if(RIGID)
        { x = indiv->x[site];
          distance1 = x - x_lower[site];
          distance2 = x_upper[site] - x;

          delta = 2.0 * distance1 / (x_upper[site] - x_lower[site]);
          if (delta > 1.0)   delta = 1.0;
          minu = -1.0 + pow((1.0 - delta),(n_distribution_m + 1.0));

          delta = 2.0 * distance2 / (x_upper[site] - x_lower[site]);
          if (delta > 1.0)   delta = 1.0;
          maxu = 1.0 - pow((1.0 - delta),(n_distribution_m + 1.0));
          u = rndreal(minu,maxu);
        }
        else u = rndreal(-1.0,1.0);

        /* calculation of actual delta value */
        delta = get_delta(u) *  0.5 * (x_upper[site] - x_lower[site]);
        indiv->x[site] += delta;
  }    /* if flip() */
  if (BINGA) binmutation(indiv->chrom);
}
/*====================================================================
Reporting the user-specified parameters :
fp is the file pointer to output file.
====================================================================*/
initreport(fp)
FILE *fp;
{
   int k;

   if (fp == NULL) error_ptr_null(" File fp in initreport");
   fprintf(fp,"\n\n=============================================");
   fprintf(fp,"\n             INITIAL REPORT                  ");
   fprintf(fp,"\n=============================================");
   if (BINGA) fprintf(fp,"\n BINARY-CODED GA ");
   if (REALGA)
   {
      if (cross_type ==SBX) fprintf(fp,"\n REAL-CODED GA (SBX)");
      else                  fprintf(fp,"\n REAL-CODED GA (BLX)");
   }
   switch (s_strategy) 
     {
     case 1 : fprintf(fp,"\n Tournament Selection Used (Size = %d)",tourneysize); break;
     case 2 : fprintf(fp,"\n Roulette Wheel Selection Used"); break;
     case 3 : fprintf(fp,"\n Stochastic Remainder RW Selection Used"); break;
     }
   switch (x_strategy)
   {

    case ONESITE : fprintf(fp,"\n Crossover Strategy : 1 xsite with swapping"); break;
    case UNIF  : fprintf(fp,"\n Crossover Strategy : Uniformly all variables 50 \% ");
                 break;
    case ONLINE : fprintf(fp,"\n Crossover Strategy : On a straight line"); break;
    default   : fprintf(fp,"\n CROSSOVER NOT SET CORRECTLY "); break;
   }
   if (BINGA) 
     fprintf(fp,"\n Mutation Strategy: Bit-wise Mutation");
   else
     fprintf(fp,"\n Mutation Strategy: Polynomial Mutation");
   fprintf(fp,"\n Variable Boundaries : ");
   if (RIGID) fprintf(fp," Rigid");
   else       fprintf(fp," Flexible");
   fprintf(fp,"\n Population size            : %d",pop_size);
   fprintf(fp,"\n Total no. of generations   : %d",max_gen);
   fprintf(fp,"\n Cross over probability     : %6.4f",p_xover);
   fprintf(fp,"\n Mutation probability       : %6.4f",p_mutation);
   if (SHARING)
   {
        fprintf(fp,"\n Sharing to be done :");
        fprintf(fp,"\n Sigma-share value          : %6.4f",sigma_share);
   }
   if (BINGA)
      fprintf(fp,"\n String length              : %d",lchrom);
   fprintf(fp,"\n Number of variables        : %d",num_var);
   fprintf(fp,"\n Total Runs to be performed : %d",maxrun);
   if ((REALGA) && (cross_type == SBX)) {
     fprintf(fp,"\n Exponent (n for SBX)       : %7.2f",n_distribution_c);
     fprintf(fp,"\n Exponent (n for Mutation)  : %7.2f",n_distribution_m);
   }
   if (s_strategy == 1)
   fprintf(fp,"\n Lower and Upper bounds     :");
   for (k=0; k<=num_var-1; k++)
     fprintf(fp,"\n   %8.4f   <=   x%d   <= %8.4f",x_lower[k],k+1,x_upper[k]);
   fprintf(fp,"\n=================================================\n");
   app_initreport();
}
/*====================================================================
Writes a given string of 0's and 1's
puts a `-` between each substring (one substring for one variable)
Leftmost bit is most significant bit.
====================================================================*/
writechrom(chrom,fp)
unsigned *chrom;
FILE *fp;
{
    int j, k, stop,bits_per_var,count=0;
    unsigned mask = 1, tmp;

   if (fp == NULL) error_ptr_null(" File fp in initreport");
   if (BINGA == FALSE) return;
   if (chrom == NULL) error_ptr_null("chrom in writechrom");
    bits_per_var = lchrom/num_discr_var;
    for(k = 0; k < chromsize; k++)
    {
        tmp = chrom[k];
        if(k == (chromsize-1))
            stop = lchrom - (k*UINTSIZE);
        else
            stop = UINTSIZE;

        for(j = 0; j < stop; j++)
        {
            if(tmp&mask)
                fprintf(fp,"1");
            else
                fprintf(fp,"0");
            count++;
            if (( (count % bits_per_var) == 0) && (count < lchrom))
                     fprintf(fp,"-");
            tmp = tmp>>1;
        }
    }
}
/*====================================================================
Reporting the statistics of current population ( gen. no. 'num'):
  fp is file pointer to output file.
====================================================================*/
report(fp,num)
FILE *fp;
int num;
{
  int k,j;
  FILE *fp_x, *fp_y;
  char string[30];


  if (fp == NULL) error_ptr_null(" file fp in report()");
  if (REPORT)
    {
      /* ----------------------------------------- */
      /* WRITING IN THE OUTPUT FILE FOR INSPECTION */
      /* ----------------------------------------- */
      fprintf(fp,"\n========== Generation No. : %3d ===================",num);
      fprintf(fp,"\n  No.      x       Fitness     Parents     random  ");
      fprintf(fp,"\n===================================================");
      for (k=0; k<= pop_size-1; k++)
	{
	  fprintf(fp,"\n %3d. [%8.5f] ->",k+1,oldpop[k].x[0]);
	  for (j= 1; j<=num_var-1; j++)
	    fprintf(fp,"\n      [%8.5f] ->",oldpop[k].x[j]);
	  fprintf(fp,"  %8.5f  (%3d %3d)  %8.5f", oldpop[k].obj,
		  oldpop[k].parent1,oldpop[k].parent2,oldpop[k].cross_var);
	  if (num_discr_var >= 1)
	    {  fprintf(fp,"\n String = ");
	    writechrom(oldpop[k].chrom,fp); }
	}
    }
  if ((REPORT) || (num==max_gen))
    {
      fprintf(fp,"\n===================================================");
      fprintf(fp,"\nMax = %8.5f  Min = %8.5f   Avg = %8.5f",
	      max_obj,min_obj,avg_obj);
      fprintf(fp,"\nNo. of mutations = %d ;  No. of x-overs = %d",
	      no_mutation,no_xover);
      
      fprintf(fp,"\nBest ever = %f -> fitness: %f (from generation : %d)",
	      best_ever.x[0],best_ever.obj,best_ever_gen);
      for (j=1; j<=num_var-1; j++)
	fprintf(fp,"\n            %f",best_ever.x[j]);
      if (num_discr_var) { fprintf(fp,"\nBest_ever String = ");
      writechrom(best_ever.chrom,fp); }
      fprintf(fp,"\n===================================================");
      fprintf(fp,"\n\n");
    }
  
  app_report();
}
/*====================================================================
Releases the memory for all mallocs
====================================================================*/
free_all()
{
  int i;

  for(i = 0; i < pop_size; i++)
  {
      free(oldpop[i].chrom);
      free(newpop[i].chrom);
  }
  free(oldpop);
  free(newpop);
  free(best_ever.chrom);
  app_free();
}

/*==================================================================
Writes the results of GA run in the output file
===================================================================*/
write_in_file(fp,sno,x,obj,trials)
FILE *fp;
int sno, trials;
float *x,obj;
{
   int k;

   if (fp == NULL) error_ptr_null(" file fp in write_in_file");
   if (x == NULL) error_ptr_null(" x in write_in_file");

   fprintf(fp,"\n%3d.   %10.7f  %6d   %10.6f to %10.6f",
                             sno,x[0],trials,minx[0],maxx[0]);
   for (k =1; k<= num_var-1; k++)
       fprintf(fp,"\n       %10.7f           %10.6f to %10.6f",
                             x[k],minx[k],maxx[k]);
   if (num_discr_var) { fprintf(fp,"  ");
                        writechrom(best_ever.chrom,fp); }
   fprintf(fp,"\n          OBJECTIVE = %10.7f                ",obj);
   fprintf(fp,"\n       Random Seed Number : %6.4f                 ",seed);
   printf("  After %d Generations : ",trials/pop_size);
   printf("\n          OBJECTIVE = %10.7f                ",obj);
   printf("\n Random Seed Number : %6.4f                 ",seed);
}

/*====================================================================
MAIN PROGRAM ;
====================================================================*/
main()
{
   FILE *fp_out;                /* File pointer for output file         */
   int runno=0, k;
   POPULATION   temp;           /* A temporary pointer of population    */

/*---------------------------*/
/* Program starts here :     */
/*---------------------------*/
   input_parameters();
   fp_out = fopen("realga.out","w+");
   
   select_memory();
   select_memory_rw();
   select_memory_sr();
   initreport(fp_out);
   for (run = 1; run<= maxrun; run++)
     {
       printf("\nRun No. %d :  Wait Please .........",run);
       fprintf(fp_out,"\nRun No. %d ",run);
       seed = basic_seed + (1.0-basic_seed)*(float)(run-1)/(float)maxrun;
       if (seed > 1.0) printf("\n Warning !!! seed number exceeds 1.0");
       gen_no = 0;
       initialize();
       statistics(gen_no);
       report(fp_out,0);
       for(gen_no = 1; gen_no<=max_gen; gen_no++)
	 {
	   generate_new_pop();
	   
	   temp = oldpop;
	   oldpop = newpop;
	   newpop = temp;
	   
	   statistics(gen_no);
	   report(fp_out,gen_no);
	 };                        /* One GA run is over  */
       free_all();
     }                      /* for loop of run  */
   
   fclose(fp_out);
   app_closure();
   select_free_sr();
   select_free_rw();
   printf("\n Results are stored in file 'realga.out' ");
   puts("\n O.K Good bye !!!");
}

/**************** End of Main Program ***************************/

/*-------------------------------------------------------  */
/* random.c - contains random number generator and related */
/* utilities,                                              */
/* Source : sga.c  (c) E.Goldberg 1986
/*-------------------------------------------------------  */


/* variables are declared static so that they cannot       */
/* conflict with names of other global variables in other  */
/* files.  See K&R, p 80, for scope of static              */

static double oldrand[55];   /* Array of 55 random numbers */
static int jrand;                 /* current random number */
static double rndx1,rndx2;    /* used with random normal deviate */
static int rndcalcflag; /* used with random normal deviate */

initrandomnormaldeviate()
/* initialization routine for randomnormaldeviate */
{
    rndcalcflag = 1;
}

double noise(mu ,sigma)
/* normal noise with specified mean & std dev: mu & sigma */
double mu, sigma;
{
    double randomnormaldeviate();

    return((randomnormaldeviate()*sigma) + mu);
}

double randomnormaldeviate()
/* random normal deviate after ACM algorithm 267 / Box-Muller Method */
{
    double sqrt(), log(), sin(), cos();
    float randomperc();
    double t;

    if(rndcalcflag)
    {
        rndx1 = sqrt(- 2.0*log((double) randomperc()));
        t = 6.2831853072 * (double) randomperc();
        rndx2 = sin(t);
        rndcalcflag = 0;
        return(rndx1 * cos(t));
    }
    else
    {
        rndcalcflag = 1;
        return(rndx2 * rndx1);
    }
}

advance_random()
/* Create next batch of 55 random numbers */
{
    int j1;
    double new_random;

    for(j1 = 0; j1 < 24; j1++)
    {
        new_random = oldrand[j1] - oldrand[j1+31];
        if(new_random < 0.0) new_random = new_random + 1.0;
        oldrand[j1] = new_random;
    }
    for(j1 = 24; j1 < 55; j1++)
    {
        new_random = oldrand [j1] - oldrand [j1-24];
        if(new_random < 0.0) new_random = new_random + 1.0;
        oldrand[j1] = new_random;
    }
}

int flip(prob)
/* Flip a biased coin - true if heads */
float prob;
{
    float randomperc();

    if(randomperc() <= prob)
        return(1);
    else
        return(0);
}

randomize()
/* Get seed number for random and start it up */
{
    int j1;

    for(j1=0; j1<=54; j1++) oldrand[j1] = 0.0;
    jrand=0;

    warmup_random(seed);
    initrandomnormaldeviate();
}

float randomperc()
/* Fetch a single random number between 0.0 and 1.0 -  */
/* Subtractive Method . See Knuth, D. (1969), v. 2 for */
/* details.Name changed from random() to avoid library */
/* conflicts on some machines                          */
{
    jrand++;
    if(jrand >= 55)
    {
        jrand = 1;
        advance_random();
    }
    return((float) oldrand[jrand]);
}

int rnd(low, high)
/* Pick a random integer between low and high */
int low,high;
{
    int i;
    float randomperc();

    if(low >= high)
        i = low;
    else
    {
        i = (randomperc() * (high - low + 1)) + low;
        if(i > high) i = high;
    }
    return(i);
}

float rndreal(lo ,hi)
/* real random number between specified limits */
float lo, hi;
{
    return((randomperc() * (hi - lo)) + lo);
}

warmup_random(random_seed)
/* Get random off and running */
float random_seed;
{
    int j1, ii;
    double new_random, prev_random;

    oldrand[54] = random_seed;
    new_random = 0.000000001;
    prev_random = random_seed;
    for(j1 = 1 ; j1 <= 54; j1++)
    {
        ii = (21*j1)%54;
        oldrand[ii] = new_random;
        new_random = prev_random-new_random;
        if(new_random<0.0) new_random = new_random + 1.0;
        prev_random = oldrand[ii];
    }

    advance_random();
    advance_random();
    advance_random();

    jrand = 0;
}
/*----------------------------------------------------------*/
/* Files for tournament selection :                         */
/* Source : sga.c (c) E.Goldberg                            */
/*----------------------------------------------------------*/

select_memory()
{
  unsigned nbytes;

  if(tourneysize > pop_size)
    {
      printf("FATAL: Tournament size (%d) > pop_size (%d)\n",
              tourneysize,pop_size);
      exit(-1);
    } ;
}


preselect_tour()
{
    reset1();
    tourneypos = 0;
}


int tour_select()
{
    int pick, winner, i;

    /* If remaining members not enough for a tournament, then reset list */
start_select :
    if((pop_size - tourneypos) < tourneysize)
    {
        reset1();
        tourneypos = 0;
    }

    /* Select tourneysize structures at random and conduct a tournament */
    winner=tourneylist[tourneypos];
/* Added by RBA */
    if( winner < 0 || winner > pop_size-1) {
                                             printf("\n Warning !! ERROR1");
                                             printf(" tourpos = %d",tourneypos);
                                             printf(" winner = %d",winner);
                                             preselect_tour();
                                             goto start_select; }
    for(i=1; i<tourneysize; i++)
    {
        pick=tourneylist[i+tourneypos];
/* Added by RBA */
        if (pick < 0 || pick > pop_size-1) { preselect_tour();
                                             printf("\n Warning !! ERROR2");
                                             goto start_select; }
        if(MINM * oldpop[pick].mod_obj < MINM * oldpop[winner].mod_obj) winner=pick;
    }

    /* Update tourneypos */
    tourneypos += tourneysize;
    return(winner);
}

/* Selection routines */

/* Roulette Wheel selection */

select_memory_rw() 
{ 
} 
 
select_free_rw() 
{ 
} 
 
preselect_rw() 
{ 
    int j; 
 
    sum_obj = 0; 
    for(j = 0; j < pop_size; j++) sum_obj += oldpop[j].obj; 
} 
 
 
int rw_select() 
/* roulette-wheel selection */ 
{ 
    extern float randomperc(); 
    float sum, pick; 
    int i; 
 
    pick = randomperc(); 
    sum = 0; 
 
    if(sum_obj != 0) 
    { 
        for(i = 0; (sum < pick) && (i < pop_size); i++) 
            sum += oldpop[i].obj/sum_obj; 
    } 
    else 
        i = rnd(0,pop_size-1); 
 
    return(i-1); 
} 




/* Stochastic Remainder Roulette Wheel */
static int *choices, nremain; 
static float *fraction; 
 
select_memory_sr() 
{ 
  /* allocates auxiliary memory for stochastic remainder selection */ 
 
  unsigned nbytes; 
  int j; 
 
  nbytes = pop_size*sizeof(int); 
  if((choices = (int *) malloc(nbytes)) == NULL) 
    nomemory(stderr,"choices"); 
  nbytes = pop_size*sizeof(float); 
  if((fraction = (float *) malloc(nbytes)) == NULL) 
    nomemory(stderr,"fraction"); 
} 
   
select_free_sr() 
{ 
  /* frees auxiliary memory for stochastic remainder selection */ 
  free(choices); 
  free(fraction); 
} 
 
preselect_sr() 
/* preselection for stochastic remainder method */ 
{ 
    int j, jassign, k; 
    float expected; 
 
    if(avg_obj == 0) 
    { 
        for(j = 0; j < pop_size; j++) choices[j] = j; 
    } 
    else 
    { 
        j = 0; 
        k = 0; 
 
        /* Assign whole numbers */ 
        do  
        { 
            expected = ((oldpop[j].obj)/avg_obj); 
            jassign = expected;  
            /* note that expected is automatically truncated */ 
            fraction[j] = expected - jassign; 
            while(jassign > 0) 
            { 
                jassign--; 
                choices[k] = j; 
                k++; 
            } 
            j++; 
        } 
        while(j < pop_size); 
         
        j = 0; 
        /* Assign fractional parts */ 
        while(k < pop_size) 
        {  
            if(j >= pop_size) j = 0; 
            if(fraction[j] > 0.0) 
            { 
                /* A winner if true */ 
                if(flip(fraction[j]))  
                { 
                    choices[k] = j; 
                    fraction[j] = fraction[j] - 1.0; 
                    k++; 
                } 
            } 
            j++; 
        } 
    } 
    nremain = pop_size - 1;
}

int sr_select() 
/* selection using remainder method */ 
{ 
    int jpick, slect; 
 
    jpick = rnd(0, nremain); 
    slect = choices[jpick]; 
    choices[jpick] = choices[nremain]; 
    nremain--; 
    return(slect); 
}


reset1()
/* Name changed from reset because of clash with lib. function - RBA */
/* Shuffles the tourneylist at random */
{
    int i, rand1, rand2, temp_site;

    for(i=0; i<pop_size; i++) tourneylist[i] = i;

    for(i=0; i < pop_size; i++)
    {
        rand1= rnd(0,pop_size-1);
        rand2=  rnd(0,pop_size-1);
        temp_site = tourneylist[rand1];
        tourneylist[rand1]=tourneylist[rand2];
        tourneylist[rand2]=temp_site;
    }
}
/******************* APPLICATION ORIENTED ROUTINES ***************/
/**** Change these routines for your particular application ******/

input_app_parameters()
/* Input your application dependent parameters here and put the
 output in global variables */
{
}
app_computation()
/* this routine should contain any application-dependent computations */
/* that should be performed before each GA cycle.
   called by generate_new_pop    */
{
}

app_free()
/* application dependent free() calls, called by free_all() */
{
}

app_initialize()
/* application dependent initialization routine called by intialize() */
{
}

app_initreport()
/* Application-dependent initial report called by initreport() */
{
}

app_report()
/* Application-dependent report, called by report() */
{
}


app_statistics()
/* Application-dependent statistics calculations called by statistics() */
{
}

app_closure()
/* Application-dependent work which should be done before closure of
   the main program. called by main() */
{
}
/*====================================================================
OBJECTIVE FUNCTION  ( Supposed to be minimized) :
Change it for different applications
====================================================================*/
float objective(x)
float *x;
{

  float term1,term2, term3, pi;
  float g, penalty_coef;
  
   if (x == NULL) error_ptr_null("x in objective()");

#ifdef prob1
   MINM  = -1;
   term1 = (x[0]*x[0]+x[1]-11.0)*(x[0]*x[0]+x[1]-11.0);
   term2 = (x[0]+x[1]*x[1]- 7.0)*(x[0]+x[1]*x[1]- 7.0);
   term3 = term1+term2;
   
   penalty_coef = 0.0;
   g = (square(x[0]-5.0) + square(x[1]))/26.0 - 1.0;
   if (g < 0.0) term3 = term3 + penalty_coef * g * g;
   return(1.0/(1.+term3));
#endif

#ifdef can
   MINM = 1;
   pi = 4.0 * atan(1.0);
   term3 = pi * x[0] * x[0]/2.0 + pi * x[0] * x[1];

   penalty_coef = 1.0e4;
   g = (pi * x[0] * x[0] * x[1]/4.0 - 400.0)/400.0;
   if (g < 0.0) term3 = term3 + penalty_coef * g * g;
   return(term3);
#endif
}

/********************** END  OF  FILE **************************/
