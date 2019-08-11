int ga, gb, gc, * gd, ge[8];
int foo(void );
int bar(void );
int func_with_loops(void )
{
int i, j, k, x;
int _ret_val;
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
{
_ret_val=x;
goto _done;
}

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

{
_ret_val=x;
goto _done;
}

_done:
return _ret_val;
}

