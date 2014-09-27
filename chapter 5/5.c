#include<stdio.h>
#include<string.h>

#define ML 50

char *stncpy(char *,char *,int);
char *stncat(char *,char *,int);
int stncmp(char *,char *,int);

main()
{
	char d[ML]="oyas";	
	char e[ML];	
		
	char a[ML]="binoy";
	char b[ML]="tv123";
	
	char f[ML]="binoy";	
	char g[ML]="biooo";
	
	printf("\nd & e\n%s\n",stncpy(e,d,5));
	
	printf("\na & b\n%s\n",stncat(a,b,3));
	
	printf("\nf & g\n%d\n",stncmp(f,g,3));	
}

char *stncpy(char *a,char *b,int n)
{
	char *c=a;
	while(n-- && *b)
		*a++=*b++;
	*a='\0';
	return c;
}

char *stncat(char *a,char *b,int n)
{
	char *c=a;
	while(*a)
		++a;
		
	while(n-- && *b)
		*a++=*b++;
		
	*a='\0';
	return c;
}

int stncmp(char *a,char *b,int n)
{
	while(n-- && *a && *b){
		if(*a != *b)
			return *a - *b;
		a++;
		b++;
	}

	return 0;
}

