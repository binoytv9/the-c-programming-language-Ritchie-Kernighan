#include<stdio.h>

main()
{
	int c;
	int n=0;
	
	c=getchar();
	//printf("\n\n\n");
		
	while(c!=EOF)
	{
		if(c==' '||c=='\t'||c=='\n')
		{
			n=1;
			if(n==1)
				putchar('\n');
		}
		
		else
		{
			putchar(c);
			n=0;
		}
			
		c=getchar();
	}
}						
