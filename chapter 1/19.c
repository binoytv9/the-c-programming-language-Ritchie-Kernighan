#include<stdio.h>

#define ML 1000

void reverse(char s[]);
int gl(char a[]);


main()
{
	int l;
	char line[ML];
	
	while((l=gl(line))>0)
	{
		//printf("\nline=%s",line);
		reverse(line);
	
		printf("\n\treversed input is: %s\n",line);
	}

}


void reverse(char a[])
{
	int i,j;
	char b[ML];
	
	i=j=0;
	
	//printf("\na=%s",a);
	//printf("\nb=%s",b);
	
	while((b[i]=a[i])!='\0')
	{
		++i;
	}	//printf("\ni=%d\n",i);
	
	while((i-1)>=0)
	{
		a[j]=b[i-1];
		--i;
		++j;
	}
}


int gl(char a[])
{
	int i=0;
	char c;
	
	while( (i<ML) && ((c=getchar())!=EOF) && (c!='\n') )
	{
		a[i]=c;
		++i;
	}
	
	if(c=='\n')
	{
		a[i]=c;
		++i;
	}
	
	a[i]='\0';
	
	return i;
}
