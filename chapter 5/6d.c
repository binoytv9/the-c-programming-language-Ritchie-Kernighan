//int to string

#include<stdio.h>

#define ML 50

char *itoa (long,char *);
char *p;
main()
{
	long a = -1234;
	char s[ML];
	
	printf("\n%s\n",itoa(a,s));
}

char *itoa (long a,char *s)
{
	p=s;
	
	if(a<0){
		*p++='-';
		a=-a;
	}
	
	if(a){
		itoa(a/10,p);
		*p++=a%10 + '0';
	}
	*p='\0';
	return s;
}
