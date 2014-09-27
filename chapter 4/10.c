#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define ML 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop (void);
int getch(void);
void ungetch(int);
int gl(char []);

int sp=0;
double val[MAXVAL];
char in[ML];
int j=0;

main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type=getop(s))!=EOF){
		switch(type){
			case NUMBER:
					push(atof(s));
					break;
			case '+':
					push(pop()+pop());
					break;
			case '*':
					push(pop()*pop());
					break;
			case '-':
					op2=pop();
					push(pop()-op2);
					break;
			case '/':
					op2=pop();
					if(op2!=0.0)
						push(pop()/op2);
					else
						printf("error:zero divisor\n");
					break;
			case '%':
					op2=pop();
					push((long)pop()%(long)op2);
					break;
			case '\n':
					printf("\t%.8g\n",pop());
					break;
			default:
					printf("error:unknown command %s\n",s);
					break;
		}
	}
	return 0;
}

void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stack full,can't puush %g\n",f);
}

double pop(void)
{
	if(sp>0)
		return val[--sp];
	else{
		printf("error:stack empty\n");
		return 0.0;
	}
}

int gl(char in[])
{	
	int i=0;
	char c;
	
	while((i<ML) && ((c=getchar())!=EOF) && (c!='\n'))
		in[i++]=c;

	if(c=='\n')
		in[i++]='\n';

	in[i]='\0';

	return i;
}

int getop(char s[])
{
	int i,c;
	
	if(in[j]=='\0')
		if(gl(in)==0)
			return EOF;
		else
			j=0;
			
	while((s[0]=c=in[j++])==' '||c=='\t')
		;
	s[1]='\0';
	if((!isdigit(c)) && (c!='.'))
		return c;

	i=0;
			
	if(isdigit(c))
		while(isdigit(s[++i]=c=in[j++]))
			;
	if(c=='.')
		while(isdigit(s[++i]=c=in[j++]))
			;
	s[i]='\0';
	--j;
	return NUMBER;
}
