#include<stdio.h>

#define ML 1000

int gl(char a[]);
void cpy(char a[],char b[],int c,int d);

main()
{
	int l,s=0;
	char line[ML],lng[ML];
	
	while( (l=gl(line))>0)
	{
		if(line[0]!='\n')	//to avoid blank lines
		{
			cpy(lng,line,s,s+l);
			s=s+l;
		}	
	}
	
	if(s>0)
	{
		lng[s]='\0';
		printf("\n\nlines with no blanks, tabs b4 inputline and without blankline are :\n%s\n\n",lng);
	}
	else
	{
		printf("\n\nno lines inputted!!!\n\n");
	}	
}

void cpy(char a[],char b[],int s,int sl)
{
	int i=0;
	
	while(s<sl)
	{
		a[s]=b[i];
		++s;
		++i;
	}
}

int gl(char a[])
{
	int i,p,q;
	char c;

	i=p=q=0;
	
	while( (i<ML) && ((c=getchar())!=EOF) && (c!='\n') )
	{
		if(q==0)		//to elliminate trailing blanks and tabs b4 the starting character
		{
			if( (c!=' ')&&(c!='\t') )
			{
				p=q=1;
			}
		}
		if(p==1)
		{
			a[i]=c;
			++i;
		}
	}
	
	if(c=='\n')
	{
		a[i]='\n';
		++i;
	}


	return i;
}
