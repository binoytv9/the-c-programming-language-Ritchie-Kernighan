#include<stdio.h>

#define ML 100

int gl(char a[],int ml);
void cpy(char a[],char b[]);

main()
{
	int l,m=0;
	char lng[ML],line[ML];
	
	while((l=gl(line,ML))>0)
	{
		printf("\t LENGTH IS: %d\n",l);
		if(l>m)
		{
			m=l;
			cpy(lng,line);
		}
		
	}
	
	if(m>0)
	{
		printf("\n\n the longest line is : %s\n\tLENGTH IS: %d\n\n",lng,m);
	}
	else
	{
		printf("\n\n no lines were inputed!!!\n\n");
	}
}


int gl(char line[],int ml)
{
	int i=0;
	char c;
	
	while( (i<ml)&& ((c=getchar())!=EOF) && (c!='\n') )
	{
		line[i]=c;
		++i;
	}
	
	if(c=='\n')
	{
		line[i]=c;
		++i;
	}
	line[i]='\0';
	
	return i;
}

void cpy(char a[],char b[])
{
	int i=0;
	
	while((a[i]=b[i])!='\0')
	{
		++i;
	}
}
