#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define	ML	1000
#define	N	8		/* default tab size */

void entab(char *s,int argvi[]);
void detab(char *s,int argi[]);
int gl(char *s);

main(int argc,char *argv[])
{
	char c,line[ML];
	int opt,i=0;
	int argi[ML];
	
	while(argv[++i]){	/* checks whether list consists of only numbers */
		if(!(argi[i-1]=atoi(argv[i]))){
			printf("Invalid Tab Stop : %s\n",argv[i]);
			printf("Usage: entab [TAB_STOP LIST]\nexample: entab 8 20 40 ,,,\n");
			exit(0);
		}
		argi[i]=0;
	}
	
	if(!argv[1])		/* to check whether list is empty*/
		argi[0]=0;
	
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
			while(argi[i] && m > argi[i])	/* m must be always less than tab stops*/
				++i;

			n=(argi[i]!=0) ? argi[i]	: N;	/* if list ends tab stop is set to default 'N' */

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
			while(argi[i] && m > argi[i])	/* m must be always less than tab stops*/
				++i;

			n = argi[i]!=0 ? argi[i] : N;	/* if list ends tab stop is set to default 'N' */

			if(m % n == 0){
				printf("\t");
				b=0;
			}
		}
		else{
			while(b--)
				printf(" ");
			
			printf("%c",*s);
			
			if(*s=='\t')			/* a tab in the input should be considered */
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
