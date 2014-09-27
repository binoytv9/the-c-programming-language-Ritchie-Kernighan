#include<stdio.h>

main()
{
	int d[10],i,c,ws,o;
	ws=o=0;
	
	for(i=0;i<10;++i)
		d[i]=0;
		
	while((c=getchar())!=EOF)
	{
		if(c>'0'&&c<'9')
			++d[c-'0'];
		
		else if(c=='\n'||c=='\t'||c==' ')
			++ws;
		
		else
			++o;
	}
	
	printf("\n\nno of digits:");

	for(i=0;i<10;++i)
		printf("\t\t\n%d\t%d\n",i,d[i]);

	printf("\n\nno of white spaces: %d",ws);
	
	printf("\n\nno of other characters: %d\n\n",o);

	
}
