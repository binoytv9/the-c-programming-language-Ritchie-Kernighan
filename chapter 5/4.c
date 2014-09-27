#include<stdio.h>
#include<string.h>

#define ML 50

int strend(char *,char *);

main()
{
	char a[ML]="binoy";
	char b[ML]="oy";	
	
	printf("\n%d\n\n",strend(a,b));
}

int strend(char *a,char *b)
{
	char *m;
	int k,l;
	k=strlen(a);
	l=strlen(b);
	
	m=a+k-l;
	while(*m && *b){
		if( *m++ != *b++)
			return 0;
	}
	
	if(*m=='\0' && *b=='\0')
		return 1;
	else{
		printf("\nstring error\n");
		return -1;
	}
}
