#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 50
#define BUFERSIZE 50

int getch(void);
void ungetch(int);
int buf[BUFERSIZE];
int bufp=0;

main()
{
	int n,i,array[SIZE],getint(int *);

	for(n=0;n<SIZE && getint(&array[n])!=EOF;n++)
		;

	i=0;
	while(i<n)
		printf("\n%d",array[i++]);
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

int getint(int *pn)
{
	int c,sign;

	while(isspace(c=getch()))
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
		ungetch(c);
		return 0;
	}

	sign=(c=='-')?-1:1;

	if(c=='-'||c=='+')
		c=getch();

	for(*pn=0;isdigit(c);c=getch())
		*pn=10* *pn+(c-'0');

	*pn *=sign;
	if(c!=EOF)
		ungetch(c);

	return c;
}
