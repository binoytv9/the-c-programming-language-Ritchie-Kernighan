//reverse a string

#include<stdio.h>
#include<string.h>

#define ML 50

char *reverse(char *);

main()
{
	char s[ML]="binoytva";
	
	printf("\n%s\n",reverse(s));
}

char *reverse(char *s)
{
	int l=strlen(s);
	int i=0,j;
	char t;
	j=l-1;
	
	while(i<l/2){
		t=*(s+i);
		*(s+i)=*(s+j);
		*(s+j)=t;
		++i;
		--j;
	}
	
	return s;
}
