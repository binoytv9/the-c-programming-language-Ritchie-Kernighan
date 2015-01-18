#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getch(void);
void push(double);
double pop (void);
void ungetch(int);
int getop(char []);

int sp = 0;
int bufp = 0;
char buf[BUFSIZE];
double val[MAXVAL];

main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
					sscanf(s,"%lf",&op2); // number conversion using sscanf
					push(op2);
					break;
			case '+':
					push(pop() + pop());
					break;
			case '*':
					push(pop() * pop());
					break;
			case '-':
					op2 = pop();
					push(pop() - op2);
					break;
			case '/':
					op2 = pop();
					if(op2 != 0.0)
						push(pop() / op2);
					else
						printf("\nerror : division by zero");
					break;
			case '\n':
					printf("\t%.8g\n",pop());
					break;
			default:
					printf("\nerror : unknown command '%s'",s);
					break;
		}
	}
	printf("\n");
	return 0;
}

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("\nerror : stack full, can't push %g",f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else{
		printf("\nerror : stack empty");
		return 0.0;
	}
}

int getop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	char c;
	if(bufp > 0)
		return  buf[--bufp];
	else{
		if(scanf("%c",&c) == EOF)
			return EOF;
		return c;
	}
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("\nungetch : too many characters");
	else
		buf[bufp++] = c;
}
