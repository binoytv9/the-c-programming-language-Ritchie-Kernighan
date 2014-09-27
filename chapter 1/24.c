#include<stdio.h>

#define ML 1000

char b[ML];
int k=0;

int gl(char a[]);
void cpy(char a[]);
void err(char a[]);

main()
{
	int l;
	char line[ML];

	printf("\n\n");

	while((l=gl(line))>0){
		cpy(line);
	}
	err(b);
}

void err(char a[])
{
	while(b[i]!='\0'){
		if(b[i]=='{')
			++br;
		if(b[i]=='[')
			++b;
		if(b[i]=='(')
			++p;
		if(b[i]=='"')
			++d;
		if(b[i]=='\'')
			++s;
			
		if(b[i]=='}')
			--br;
		if(b[i]==']')
			--b;
		if(b[i]==')')
			--p;
		if(b[i]=='"')
			--d;
		if(b[i]=='\'')
			--s;
}
void cpy(char a[])
{
	int i=0;
	
	while(a[i]!='/0'){
		b[k]=a[i];
		++i;
		++k;
	}
	b[k]='/0';
}

int gl(char a[])
{
	int i=0;
	char c;
	
	while((i<ML)&&((c=getchar())!=EOF)&&(c!='\n')){
		a[i]=c;
		++i;
	}
	
	if(c=='\n'){
		a[i]='\n';
		++i;
	}
	
	a[i]='\0';
	
	return i;
}
