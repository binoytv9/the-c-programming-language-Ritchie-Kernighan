#include<stdio.h>

main()
{
	int c,t,l,b;
	char i;
	c=t=l=b=0;
	
	i=getchar();
	while(i!=EOF){
		++c;
		if(i=='\n')
			++l;
		if(i=='\t')
			++t;
		if(i==' ')
			++b;

		i=getchar();
	}
	
	printf("\n\nno of characters: %d\n\nno of tabs: %d\n\nno of blanks: %d\n\nno of lines: %d\n\n",c,t,b,l);

}
