#include<stdio.h>

unsigned bitcount(unsigned x);

main()
{
	unsigned x=108;
	int n;
	
	printf("\nx=%d\n",x);
	n=bitcount(x);
	printf("no of bits : %d\n\n",n);
	
}

unsigned bitcount(unsigned x)
{
	int b=0;
	
	while(x!=0){
		++b;
		x&=x-1;
	}
	return b;
}
