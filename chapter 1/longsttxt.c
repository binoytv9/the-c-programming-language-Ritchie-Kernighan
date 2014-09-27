#include<stdio.h>
#define ML 50

int getlin(char line[],int ml);
void cpy(char longst[],char line[]);

main()
{
	int l,max=0;
	char line[ML],longst[ML];
	
	while((l=getlin(line,ML))>0)
	{
		if(l>max)
		{
			max=l;
			cpy(longst,line);
		}
		
	}
	
	if(max>0)
		printf("\n\nlongest line is : %s\n\n",longst);
}


int getlin(char line[],int ml)
{
	int i=0;
	char c;
	
	while(((c=getchar())!=EOF)&&c!='\n'&&(i<ml))
	{
		line[i]=c;
		++i;
	}
	
	if(c=='\n')
	{
		line[i]='\n';
		++i;
	}
	
	line[i]='\0';
	return i;
}


void cpy(char longst[],char line[])
{
	int i=0;
	while((longst[i]=line[i])!='\0')
		++i;
}
