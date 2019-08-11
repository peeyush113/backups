int ga, gb, gc, * gd, ge[8];
int foo(void );
int bar(void );
int func_with_loops(void )
{
int i, j, k, x;
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

{
int _tmp0;
int _tmp1;
int _tmp2;
int _tmp3;
_tmp0=foo();
_tmp1=foo();
_tmp2=bar();
_tmp3=bar();
x+=(((_tmp1+_tmp0)+_tmp2)+_tmp3);
}

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

