//string to integer

#include<stdio.h>

long atoi (char *);

main()
{
	char a[]="1234";
	
	printf("\n%ld\n",atoi(a));
}

long atoi (char *s)
{
	long num=0,sign;
	while(isspace(*s))
		s++;
	
	sign = (*s=='-')?-1:1;
	
	if(*s=='-' || *s=='+')
		s++;
	
	while(isdigit(*s))
		num = num*10 + *s++-'0';

	return num*sign;
}
