#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MBL 50

int isop(char *s);
void push(double a);
double pop();
int isnum(char *s);

double buf[MBL];
int bl=0;
int valid=1;

main(int argc,char *argv[])
{
	int i=0;
	char c;
	double op2;
	
	while(argv[++i]){
		if(c=isop(argv[i])){
			switch(c){
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
					if(op2)
						push(pop()/op2);
					else{
						printf("\nWarning:Division by '0'\n");
						valid=0;
					}
					break;
				case '%':
					op2=pop();
					if(op2)
						push((long)pop()%(long)op2);
					else{
						printf("\nWarning:Division by '0'\n");
						valid=0;
					}
					break;
			}
		}
		
		else if(isnum(argv[i]))
			push(atof(argv[i]));
		
		else{
			printf("\nInvalid Input: %s \nExample:\texpr 2 3 4 + *\n\t\tevaluates 2 * (3+4).\n",argv[i]);
			valid=0;
		}
	}

	if(!argv[1]){
		printf("\nInvalid Input \nExample:\texpr 2 3 4 + *\n\t\tevaluates 2 * (3+4).\n");
		valid=0;
	}

	if(valid==1)	
		printf("\nOutput is %f\n",pop());

}

int isnum(char *s)
{
	if(*s=='-' || *s=='+')
		s++;

	while(isdigit(*s))
		++s;

	if(*s=='.')
		s++;
		
	while(isdigit(*s))
		++s;

	if(*s=='\0')
		return 1;
	else
		return 0;
}
	
void push(double a)
{
	(bl<MBL) ? buf[bl++]=a : printf("\nBuffer Full\n");
}

double pop()
{
	if(bl>0)
		return buf[--bl];
	else{
		printf("\nBuffer Empty\n");
		valid=0;
		return 0;
	}
}	

int isop(char *s)
{
	int c;
	
	if(*s=='+' || *s=='-' || *s=='/' || *s=='*' || *s=='%'){
		c=*s++;
		if(*s=='\0')
			return c;
	}
	
	return 0;
}
