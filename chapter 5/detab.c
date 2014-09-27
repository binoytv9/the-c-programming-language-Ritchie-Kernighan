#include<stdio.h>

#define	ML	1000
#define	N	8

void detab(char *s);
int gl(char *s);

main()
{
	char line[ML];
	
	while(gl(line)>0){
		printf("\n\n");
		detab(line);
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

void detab(char *s)
{
	int m,i;
	
	for(m=1;*s!='\0';m++,s++){
    		if(*s=='\t'){
			i=N-m+1;
			while(i--)
				printf(" ");
			m=0;
		}
		else{		
			printf("%c",*s);
			m%=N;
		}
	}
	
}
