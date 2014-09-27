#include<stdio.h>
#include<string.h>

#define M 50

int gl(char a[]);
int strindex(char s[],char t[]);
int rmost(char t[]);

int k;

main()
{
	int l,p;
	char line[M];
	char t[]="abc pqrs xyz";
	
	while((l=gl(line))>0){
		p=strindex(line,t);
		if(p>=0)
			printf("\n\tfound at position %d!!!\n",p);
		else
			printf("\n\tnot found!!!\n");
	}
}

int rmost(char t[])
{
	int l;
	
	l=strlen(t);

	while((--l>=0) && (t[l]!=' '));
	return l+1;
}

int strindex(char s[],char t[])
{
	int i,j,l;
	
	k=rmost(t);
	
	for(i=0;s[i]!='\0';++i){
		for(j=i,l=0;(s[j]==t[k]) && (t[k]!='\0');++l,++j,++k);
	
	if((l>0) && (t[k]=='\0'))
		return i;
	}
		return -1;
}	



int gl(char a[])
{
	int i=0;
	char c;

	while((i<M) && ((c=getchar())!=EOF) && (c!='\n'))
		a[i++]=c;
	if(c=='\n')
		a[i++]='\n';
	a[i]='\0';

	return i;
}
