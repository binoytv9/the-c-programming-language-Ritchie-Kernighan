#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define	ML	1000
#define	N	8		/* default tab size */

void entab(char *s,int argvi[]);
void detab(char *s,int argi[]);
int gl(char *s);

int argi[ML];

main(int argc,char *argv[])
{
	char c,line[ML];
	int opt,valid=1,i=0;
	
	while((argc <= 3) && argv[++i]){
		if(argv[i][0]=='-'){
			if(!(argi[0]=-atoi(argv[i])))
				valid=0;
		}
		else if(argv[i][0]=='+'){
			if(!(argi[1]=atoi(argv[i])))
				valid=0;
		}
		else
			valid=0;
	}
	if(argc>3)
		valid=0;
		
	if(!valid){
		printf("Invalid Shorthand!\n");
		printf("Usage: entab -m +n\nmeans tab stops every 'n' columns, starting at column 'm'\n");
		exit(0);
	}
	
	if(!argv[1]){
		argi[0]=1;
		argi[1]=N;
	}
	
	
	printf("\n\t    MENU\n\t------------\n\t1. ENTAB\n\t2. DETAB\n\n\t\tenter ur choice (1 or 2) : ");
	c=getchar();
		
	switch(c){
		case '1':
			opt=1;
			break;
		case '2':
			opt=0;
			break;
		case EOF:
			putchar('\n');
			exit(0);
		default:
			printf("\nInvalid Entry! Exiting...\n");
			exit(0);
	}
	
	while(gl(line)>0){
		printf("\n");
		opt==1 ? entab(line,argi) : detab(line,argi);
		printf("\n");
	}
	
	return 0;
}

		
void detab(char *s,int argi[])
{
	int m,n,i;
	
	for(m=1,i=0;*s!='\0';s++){
    		if(*s=='\t'){
			
			if(argi[0])
				n=(m<argi[0]) ? N : argi[1];
			else
				n=argi[1];
				
			while(m++ % n)
				printf(" ");
			printf(" ");
		}
		else{		
			printf("%c",*s);
			m++;
		}
	}
	
}
		
void entab(char *s,int argi[])
{
	int m,n,i,b;
	
	for(m=1,i=0,b=0;*s!='\0';s++,m++){
    		if(*s==' '){
    			++b;
    			
			if(argi[0])
				n=(m<argi[0]) ? N : argi[1];
			else
				n=argi[1];
				
			if(m % n == 0){
				printf("\t");
				b=0;
			}
		}
		else{
			while(b--)
				printf(" ");
			
			printf("%c",*s);
			
			if(*s=='\t')			/* tab in the input should be considered */
				while(m % N)
					m++;
			b=0;
		}
	}
	
}


int gl(char *s)
{
	char *t=s;
	char c;
	
	while((s-t)<ML && (c=getchar())!=EOF && c!='\n')
		*s++ = c;
	
	if(c=='\n')
		*s++ = '\n';
	
	*s='\0';
	
	return s-t;
}
