#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10
#define BUFERSIZE 10

int getch(void);
void ungetch(int);
int buf[BUFERSIZE];
int bufp=0;
float array[SIZE];

main()
{
	int n,i,getfloat(float *);

	for(n=0;n<SIZE && getint(&array[n])!=EOF;n++)
		;

	printf("\nn=%d\n",n);
	i=0;
	while(i<n)
		printf("\n%f",array[i++]);
	
	printf("\n");
}

int getint(float *pn)
{
	int c,sign;
	float d;
	
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

	if(c=='.')
		c=getch();
	
	for(d=1.0;isdigit(c);c=getch(),d*=10)
		*pn=10* *pn+(c-'0');
	
	*pn/=d;
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
