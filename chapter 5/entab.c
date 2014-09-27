#include<stdio.h>

#define	ML	1000
#define	N	8

void entab(char *s);
int gl(char *s);

main()
{
	char line[ML];
		
	while(gl(line)>0){
		printf("\n\n");
		entab(line);
		printf("\n");
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

void entab(char *s)
{
	int m,b;
	
	for(m=1,b=0;*s!='\0';m++,s++){
		if(*s==' '){
			++b;
			if(m % N == 0){
				printf("\t");
				b=0;
			}
		}
		else{
			while(b--)
				printf(" ");
			printf("%c",*s);
			
			if(*s=='\t')
				while(m % N)
					m++;
			b=0;
		}
	}
	
}
