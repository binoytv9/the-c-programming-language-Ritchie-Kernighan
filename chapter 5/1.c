#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10
#define BUFERSIZE 10

int getch(void);
void ungetch(int);
int buf[BUFERSIZE];
int bufp=0;
int array[SIZE];

main()
{
	int n,i,getint(int *);

	for(n=0;n<SIZE && getint(&array[n])!=EOF;n++)
		;

	printf("\nn=%d\n",n);
	i=0;
	while(i<n)
		printf("\n%d",array[i++]);
	
	printf("\n");
}

int getint(int *pn)
{
	int c,d,sign;

	while(isspace(c=getch()))
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
		ungetch(c);
		return 0;
	}

	sign=(c=='-')?-1:1;

	if(c=='-'||c=='+'){
		d=c;
		if(!isdigit((c=getch())) && c!=EOF)
			ungetch(c);
		return c;
	}	

	for(*pn=0;isdigit(c);c=getch())
		*pn=10* *pn+(c-'0');

	*pn *=sign;
	if(c!=EOF)
		ungetch(c);

	return c;
}

void ungetch(int c)
{
	if (bufp>BUFERSIZE)
		printf("\nstack full\n");
	else
		buf[bufp++]=c;
}

int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}
