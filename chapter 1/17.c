#include<stdio.h>

#define ML 1000
#define LEN 5

int gl(char a[],int ml);
void cpy(char a[],char b[],int s,int sl);

main()
{
	int l,s=0;
	char line[ML],lng[ML];
	
	while( (l=gl(line,ML)) > 0 )
	{
		printf("\tLENGTH IS : %d\n",l-1);
		if(l>LEN)
		{	
			cpy(lng,line,s,s+l);
			s=s+l;
			//printf("\n%s\n",line);
		}
	}

	if(s>0)
	{
		lng[s]='\0';
		printf("\n\nlines with %d characters or more are :\n%s\n\n",LEN,lng);
	}
	else
	{
		printf("\n\nno lines greater than %d!!!\n\n",LEN);
	}
}

void cpy(char a[],char b[],int s,int sl)
{
	int i=0;
	while(i<sl)
	{
		a[s]=b[i];
		++s;
		++i;
	}
}

int gl(char a[],int ml)
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
	
	return i;
}
