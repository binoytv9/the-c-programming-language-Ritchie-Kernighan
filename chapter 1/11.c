#include<stdio.h>

main()
{
	char c;
	int w,n;
	
	w=n=0;
	c=getchar();
		
	while(c!=EOF)
	{
		if(c==' '||c=='\t'||c=='\n')
		{
			++n;
			if(n==1)
				++w;
		}
		
		else
			n=0;
		
		c=getchar();
		
		if(c==EOF)
			++w;
	}
	
	printf("\n\nno of words: %d\n\n",w);
}
