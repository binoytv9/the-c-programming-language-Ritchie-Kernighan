#include<stdio.h>

#define M 100

int gl(char s1[]);
void expand(char s1[],char s2[]);

int p=0;

main()
{
	int l;
	char s1[M],s2[M];
	
	while( (l=gl(s1)>0) ){
		expand(s1,s2);
	}

	printf("\naftr expanding shorthand notations in s1 : \n%s\n",s2);
}

int gl(char s1[])
{
	int i=0;
	char c;
	
	while((i<M) && ((c=getchar())!=EOF) && (c!='\n'))
		s1[i++]=c;
	if(c=='\n')
		s1[i++]='\n';
	s1[i]='\0';
	return i;
}

void expand(char s1[],char s2[])
{
	int i=0;
	int j,k;
	
	while(s1[i]!='\0'){
		if(s1[i]=='-'){
			if( ((s1[i-1]>='a')&&(s1[i-1]<='z')&&(s1[i+1]>='a')&&(s1[i+1]<='z')) || 
			    ((s1[i-1]>='A')&&(s1[i-1]<='Z')&&(s1[i+1]>='A')&&(s1[i+1]<='Z')) || 
			    ((s1[i-1]>='0')&&(s1[i-1]<='9')&&(s1[i+1]>='0')&&(s1[i+1]<='9'))    ){
				if(s1[i-1]<=s1[i+1]){		//a-z=abc...xyz
					j=s1[i-1]+1;
					k=s1[i+1];
					while(j<k)
						s2[p++]=j++;
				}
				else{				//z-a=zyx...cba
					j=s1[i-1]-1;
					k=s1[i+1];
					while(j>k)
						s2[p++]=j--;
				}				
			}
			else
				s2[p++]=s1[i];
		}
		else
			s2[p++]=s1[i];
		s2[p]='\0';
		++i;
	}
}
