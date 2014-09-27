#include<stdio.h>

#define ML 10

void itoa(int a);

char s[ML];
int i=0;

main()
{
	int a=-123;

	itoa(a);
	s[i]='\0';
	printf("\n%s\n",s);
}

void itoa(int a)
{
	if(a<0){
		s[i++]='-';
		a=-a;
	}

	if(a/10)
		itoa(a/10);

	s[i++]=(a%10)+'0';
}
