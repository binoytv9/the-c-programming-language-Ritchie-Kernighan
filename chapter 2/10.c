#include<stdio.h>

void lower(char c[]);

main()
{
	char c[]="BiNoY";
	printf("\nc=%s\n",c);
	lower(c);
	printf("c=%s\n",c);
}

void lower(char c[])
{
	int i=0;
	
	while(c[i]!='\0'){
		c[i]=((c[i]>='A')&&(c[i]<='Z')) ? c[i]+32 : c[i] ;
		++i;
	}
}
