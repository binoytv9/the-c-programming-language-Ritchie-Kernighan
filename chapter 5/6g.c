#include<stdio.h>

long strindex(char *,char *);

main()
{
	char a[]="binoytv";
	char b[]="v";
	
	printf("\n%ld\n",strindex(a,b));
}

long strindex(char *a,char *b)
{
	char *c=a;
	long l;
	
	while(*a && *b){
		l=0;
		
		while(*b == *a){
			++b;
			l++;
			
			if(*b=='\0')
				return a-c-l+1;
			
			++a;
		}
		
		++a;
	}
	
	return -1;
}
