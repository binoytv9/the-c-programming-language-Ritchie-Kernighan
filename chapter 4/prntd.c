#include<stdio.h>

void printd(int a);

main()
{
	int a=-651315123;
	printf("\n");
	printd(a);
	printf("\n");
}


void printd(int a)
{
	if(a<0){
		putchar('-');
		a=-a;
	}
	
	if(a/10)
		printd(a/10);
	printf("%d",a%10);
}
