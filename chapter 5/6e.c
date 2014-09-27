//float to string

#include<stdio.h>

#define ML 50

char *p;
main()
{
	double a = -1234.13;
	char s[ML];
	
	printf("\n%s\n",ftoa(a,s));
}

char *ftoa (double a,char *s)
{
	p=s;
	
	if(a<0){
		*p++='-';
		a=-a;
	}
	
	

	return s;
}
