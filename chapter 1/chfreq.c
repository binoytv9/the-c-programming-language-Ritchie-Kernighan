#include<stdio.h>

main()
{
	char c,ch;
	int d[10],i;
	int a[26];
	
	for(i=0;i<10;++i)
	{
		d[i]=0;
	}
	
	for(i=0;i<26;++i)
	{
		a[i]=0;
	}
	
	while((c=getchar())!=EOF)
	{
		if(c>='0'||c<='9')
		{
			++d[c-'0'];
		}
		
		if(c>'a'||c<='z')
		{
			++a[c-'a'];
		}
	
	}
			
	printf("\n\nfrequency of characters are : \n\n");
	
	for(i=0;i<10;++i)
	{
		if(d[i]!=0)
		{
			printf("%d\t%d times\n",i,d[i]);
		}
	}
	
	ch='a';
	
	for(i=0;i<26;++i)
	{
		if(a[i]!=0)
		{
			printf("%c\t%d times\n",ch,a[i]);
			++ch;
		}
	}

}
			
		
