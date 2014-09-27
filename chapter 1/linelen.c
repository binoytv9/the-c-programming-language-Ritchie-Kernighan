#include<stdio.h>

main()
{
	char c,l[50];
	int i,j;
	i=0;
	
	while(((c=getchar())!=EOF)&&(i<50)&&(c!='\n'))
	{
		l[i]=c;
		++i;
	}

	
	printf("\n\ninput is: \n");
	
	for(j=0;j<=i;++j)
	{
		printf("%c ",l[j]);
	}

	printf("\nlength of line : %d\n",i);

}
