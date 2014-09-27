#include<stdio.h>

main()
{
	int c=0;
	while(getchar()!=EOF)
	{
		++c;
	}
	printf("\n no of characters is %d \n",c);
}
