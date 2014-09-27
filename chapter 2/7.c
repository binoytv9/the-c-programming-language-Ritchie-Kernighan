#include<stdio.h>

unsigned reverse(unsigned x,int p,int n);

main()
{
	unsigned x=54;
	int p,n;
	p=3;
	n=2;
	
	printf("\nx=%d\n",x);
	x=reverse(x,p,n);
	printf("\nx=%d\n",x);
	
}

unsigned reverse(unsigned x,int p,int n)
{
	return ( x ^ ((~( (~0)<<n ))<<p+1-n) );
}

