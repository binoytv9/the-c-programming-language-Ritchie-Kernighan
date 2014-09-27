#include<stdio.h>

#define ML 100

void escape(char s[],char t[]);
int gl(char t[]);
void rev(char a[],char b[]);

int j=0,k=0;

main()
{
	char t[ML],s[ML],r[ML];
	int l;
	
	while((l=gl(t))>0){
		escape(s,t);
	}
	printf("\n\nconverting into visible characters : \n%s\n\n",s);
	rev(s,r);
	printf("\n\nconverting back into invisible characters : \n%s\n\n",r);

}

void rev(char a[],char b[])
{
	int i=0;

	while(a[i]!='\0'){
	
		if(a[i]=='\\'){
		
			if(a[i+1]=='n'){
				b[k]='\n';
				++i;
			}
				
			else if(a[i+1]=='t'){
				b[k]='\t';
				++i;
			}
				
			else
				b[k]='\\';	
		}
		else
			b[k]=a[i];
		
		++i;
		++k;
	}
	b[k]='\0';
}

void escape(char s[],char t[])
{
	int i;
	i=0;
	
	while(t[i]!='\0'){
		switch(t[i]){
			case '\n':
				s[j++]='\\';
				s[j++]='n';
				break;
			case '\t':
				s[j++]='\\';
				s[j++]='t';
				break;
			default:
				s[j++]=t[i];
			}
		++i;	
	}
	s[j]='\0';
}
	
int gl(char a[])
{
	int i=0;
	char c;
	
	while(i<ML&&((c=getchar())!=EOF)&&(c!='\n')){
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
