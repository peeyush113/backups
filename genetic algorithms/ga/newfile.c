 #include<stdio.h>
 #include<conio.h>
 #include<math.h>
 #include<stdlib.h>
 typedef struct Chrom
 {
 short int bit[6];
 int fit;
 }chrom;
   
 void *evpop(chrom popcurrent[4]);
 int x(chrom popcurrent);
 int y(int x);
 void *pickchroms(chrom popcurrent[4]);
 void *crossover(chrom popnext[4]);
 void *mutation(chrom popnext[4]);
 
   void main()
   {
     int num;
     int i,j;
  
    printf("\nWelcome to the Genetic Algorithm coded by Luay Al-wesi : www.luay.info\nThe Algorithm is based on the function y = -x^2 + 5 to find the maximum value of the function...\n");
     enter: printf("\nPlease enter the no. of iterations:  ");
     scanf("%d",&num);
   
     chrom popcurrent[4];
     chrom popnext[4];
     if(num<1)
     goto enter;
     evpop(popcurrent);
    for(i=0;i<num;i++)
   {
 
    printf("\ni = %d\n",i);
 
   for(j=0;j<4;j++)
     popnext[j]=popcurrent[j];
  
       pickchroms(popnext);
       crossover(popnext);
       mutation(popnext);

       for(j=0;j<4;j++)
 47       popcurrent[j]=popnext[j];
 48  
 49  
 50  
 51  
 52  
 53  
 54  
 55      }
 56     printf("\nPress any key to end ! ");
 57     flushall();
 58     getche();
 59  
 60  }
 61  
 62  void *evpop(chrom popcurrent[4])
 63  {
 64      int i,j,value;
 65     int random;
 66     for(j=0;j<4;j++)
 67      {  for(i=0;i<6;i++)
 68          {
 69              random=rand();
 70              random=(random%2);
 71              popcurrent[j].bit[i]=random;
 72          }
 73          value=x(popcurrent[j]);
 74          popcurrent[j].fit=y(x(popcurrent[j]));
 75          printf("\n popcurrent[%d]=%d%d%d%d%d%d    value=%d     fitness = %d",j,popcurrent[j].bit[5],popcurrent[j].bit[4],popcurrent[j].bit[3],popcurrent[j].bit[2],popcurrent[j].bit[1],popcurrent[j].bit[0],value,popcurrent[j].fit);
 76      }
 77    return(0);
 78  }
 79  
 80  int x(chrom popcurrent)
 81  {
 82      int z;
 83     z=(popcurrent.bit[0]*1)+(popcurrent.bit[1]*2)+(popcurrent.bit[2]*4)+(popcurrent.bit[3]*8)+(popcurrent.bit[4]*16);
 84     if(popcurrent.bit[5]==1)
 85     z=z*(-1);
 86     return(z);
 87  }
 88  
 89  int y(int x)
 90  {
 91      int y;
 92     y=-(x*x)+5;
 93     return(y);
 94  }
 95  
 96  void *pickchroms(chrom popcurrent[4])
 97  {
 98  
 99      int i,j;
100     chrom temp;
101  
102      for(i=0;i<3;i++)
103            for(j=0;j<3;j++)
104           {
105              if(popcurrent[j+1].fit>popcurrent[j].fit)
106              {
107                  temp=popcurrent[j+1];
108                  popcurrent[j+1]=popcurrent[j];
109                      popcurrent[j]=temp;
110  
111              }
112           }
113        for(i=0;i<4;i++)
114          printf("\nSorting:popnext[%d] fitness=%d",i,popcurrent[i].fit);
115          printf("\n");
116        flushall();
117          return(0);
118  }
119  
120  void *crossover(chrom popnext[4])
121  {
122      int random;
123     int i;
124     random=rand();
125     random=((random%5)+1);
126     for(i=0;i<random;i++)
127          {
128          popnext[2].bit[i]=popnext[0].bit[i];
129           popnext[3].bit[i]=popnext[1].bit[i];
130        }
131      for(i=random;i<6;i++)
    {
       popnext[2].bit[i]=popnext[1].bit[i];
        popnext[3].bit[i]=popnext[0].bit[i];
       }
      for(i=0;i<4;i++)
        popnext[i].fit=y(x(popnext[i]));
      for(i=0;i<4;i++)
        printf("\nCrossOver popnext[%d]=%d%d%d%d%d%d    value=%d     fitness = %d",i,popnext[i].bit[5],popnext[i].bit[4],popnext[i].bit[3],popnext[i].bit[2],popnext[i].bit[1],popnext[i].bit[0],x(popnext[i]),popnext[i].fit);
        return(0);
     }

  void *mutation(chrom popnext[4])
  {
    int random;
   int row,col,value;
    random=rand()%50;

   if(random==25) /* 1Suppusiong Probability of mutation is 2 % */
    {
      col=rand()%6;
     row=rand()%4;
       if(popnext[row].bit[col]==0)
       popnext[row].bit[col]=1 ;
     else if(popnext[row].bit[col]==1)
        popnext[row].bit[col]=0;
       popnext[row].fit=y(x(popnext[row]));
       value=x(popnext[row]);
         printf("\nMutation occured in popnext[%d] bit[%d]:=%d%d%d%d%d%d    value=%d   fitness=%d",row,col,popnext[row].bit[5],popnext[row].bit[4],popnext[row].bit[3],popnext[row].bit[2],popnext[row].bit[1],popnext[row].bit[0],value,popnext[row].fit);
     }
    return(0);
  }
