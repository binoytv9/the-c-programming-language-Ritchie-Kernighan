#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define N	10					/* default no of lines to print */
#define ML	500

int gl(char *s);

main(int argc,char *argv[])
{
	int valid,n,i,l;
	char *lp[ML],*p;
	char line[ML];
	
	valid=1;
	i=0;
	
	while(argv[++i])
		if(argv[i][0]=='-'){
			if(!(n=-atoi(argv[i])))
				valid=0;
		}
		else
			valid=0;

	if(argc==1)
		n=N;
		
	if(!valid){
		printf("Usage: tail [-n]\nprints the last n lines.\n");
		exit(0);
	}

	i=0;
	while((l=gl(line))>0){
		if(p=malloc(l)){
			strcpy(p,line);
			lp[i++]=p;
		}
		else{
			printf("\nerror: unable to allocate memmory!\n");
			exit(0);
		}
	}lp[i]='\0';
	
	if(i>=n){
		printf("\n\nlast %d lines are :\n",n);
		while(n)
			printf("\n%s",lp[i-n--]);
		}
	else{
		printf("\n\nonly %d lines are available; they are :\n",i);
		i=0;
		while(lp[i])
			printf("\n%s",lp[i++]);
	}
	printf("\n");	

}

int gl(char *s)
{
	char c;
	char *p=s;
	
	while((s-p)<ML && (c=getchar())!=EOF && c!='\n')
		*s++ = c;
	if(c=='\n')
		*s='\0';
	
	return s-p;
}

