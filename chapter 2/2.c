#include<stdio.h>

#define lim 50

main()
{
	int i=0,b=1;
	char c,s[lim];
	
	while(b){
		if(c=getchar())==EOF)
			b=0;
		else if(i>=lim-1)
			b=0;
		else if(c=='\n')
			b=0;
		else
			s[i]=c;
		++i;
	}
	s[i]='\0';
	
	printf("\n%s\n",s);
}
