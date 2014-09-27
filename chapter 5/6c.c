//string to float

#include<stdio.h>

double atoi (char *);

main()
{
	char a[]="-1234.123";
	
	printf("\n%f\n",atoi(a));
}

double atoi (char *s)
{
	double num=0.0,l,sign;
	
	while(isspace(*s))
		s++;
	
	sign = (*s=='-')?-1:1;
	
	if(*s=='-' || *s=='+')
		s++;
	
	while(isdigit(*s))
		num = num*10 + *s++-'0';

	if(*s=='.')
		++s;
	
	for(l=1.0;isdigit(*s);l*=10)
		num = num*10 + *s++-'0';

	return sign*num/l;
}
