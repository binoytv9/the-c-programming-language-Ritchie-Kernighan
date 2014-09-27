#include<stdio.h>

#define ML 50

void stcat(char *,char *);

main()
{
	char a[ML]="binoy";
	char b[ML]=" t v";	
				
	stcat(a,b);
	printf("\n%s\n\n",a);
}


void stcat(char *a,char *b)
{
	while(*a++)
		;
	--a;
					
	while(*a++ = *b++)
		;
}
