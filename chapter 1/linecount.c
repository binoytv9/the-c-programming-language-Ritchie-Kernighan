#include <stdio.h>

main()
{
	double c,l;
	int a=getchar();
	c=l=0;
	while(a!=EOF)
	{
		++c;
		if (a=='\n')
		{
			++l;
		}
	a=getchar();

	}
	
	printf("\n\nno of characters : %.0f\n\nno of lines: %.0f \n\n",c,l);
}
