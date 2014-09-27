#include<stdio.h>

main()
{
	char c;
	int n=0,b=0,i;
	
	c=getchar();
	
	while(c!=EOF)
	{
		if(c==' '||c=='\n'||c=='\t')
		{
			++b;
			if(b==1)
			{
				for(i=0;i<(15-n);++i)
				{
					putchar(' ');
				}
				
				for(i=0;i<n;++i)
				{
					putchar('*');
				}
				
				putchar('\n');
			}
			
			n=0;
		}
		
		else
		{
			putchar(c);
			++n;
			b=0;
		}
	
		c=getchar();
	}
	
}
