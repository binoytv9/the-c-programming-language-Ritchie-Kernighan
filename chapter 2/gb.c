#include<stdio.h>

unsigned getbits(unsigned x,int p,int n);

main()
{
	unsigned x=3,s=5;
	int p,n;
	p=4;
	n=3;
	
	printf("\nx=%d\n",x);
	//x=getbits(x,p,n);
	printf("\nx=%d\n",x|s);
	
}

unsigned getbits(unsigned x,int p,int n)
{
	return (x>>(p+1-n)) & ~(~0<<n);
}
