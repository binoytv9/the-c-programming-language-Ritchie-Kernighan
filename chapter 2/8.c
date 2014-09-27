#include<stdio.h>
#include<math.h>

unsigned rightrot(unsigned x,int n);

main()
{
	unsigned x=108;
	int n;
	n=3;
	
	printf("\nx=%d\n",x);
	x=rightrot(x,n);
	printf("x=%d\n\n",x);
	
}

unsigned rightrot(unsigned x,int n)
{
	int l=1,i=1;
	
	while((i=i*2)<=x)
		++l;
	return ((x & (~( (~0)<<n )))<<l-n) | (x>>n);
}
