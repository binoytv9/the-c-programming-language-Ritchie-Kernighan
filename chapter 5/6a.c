#include<stdio.h>

#define ML 50

int gl(char *);

main()
{
	char s[ML];
	
	while(gl(s)>0)
		printf("%s",s);

	printf("\n");
}

int gl(char *s)
{
	char c,*t=s;
	
	while(((s-t)<ML) && ((c=getchar())!=EOF) && (c!='\n'))
		*s++ = c;
	if(c=='\n')
		*s++='\n';
	*s='\0';
	return s-t;
}
