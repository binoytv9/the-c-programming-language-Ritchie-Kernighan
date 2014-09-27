#include<stdio.h>

int power(int,int);

main()
{
	int n;
	int i=0;
	
	for(i=0;i<10;++i)
	{
		printf("2^%d is %d\n",i,power(2,i));
	}
}

int power(int b,int n)
{
	int i,a=1;
	
	for(i=0;i<n;++i)
	{
		a=a*b;
	}
	
	return a;
}
