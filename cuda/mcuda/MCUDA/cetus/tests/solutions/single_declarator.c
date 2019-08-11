int ga;
int gb;
int gc;
int * gd;
int ge[8];
int foo(void );
int bar(void );
int func_with_loops(void )
{
int i;
int j;
int k;
int x;
for (i=0; i<10;  ++ i)
{
for (j=0; j<10;  ++ j)
{
for (k=0; k<10;  ++ k)
{
x ++ ;
}

}

}

if ((x>500))
{
return x;
}

x+=(((foo()+foo())+bar())+bar());
for (i=0; i<10;  ++ i)
{
for (j=0; j<10;  ++ j)
{
for (k=0; k<10;  ++ k)
{
x ++ ;
}

}

}

return x;
}

