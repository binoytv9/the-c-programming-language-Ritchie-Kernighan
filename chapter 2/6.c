#include<stdio.h>

unsigned setbits(unsigned x,int p,int n,unsigned y);

main()
{
	unsigned x=54,y=59;
	int p,n;
	p=3;
	n=2;
	
	printf("\nx=%d\n",x);
	x=setbits(x,p,n,y);
	printf("\nx=%d\n",x);
	
}

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
	return ( (x & (~((~( (~0)<<n ))<<p+1-n))) | ((y & ( ~( (~0)<<n ) ))<<p+1-n) );
}


//	return ( (x & (~((~( (~0)<<n ))<<p+1-n))) | (y & (( ~( (~0)<<n ) )<<p+1-n)) );

