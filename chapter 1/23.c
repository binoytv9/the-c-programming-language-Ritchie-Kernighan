#include<stdio.h>

#define ML 1000

int gl(char a[]);
void dis(char a[]);
void uncomnt(char a[]);
void cpy(char a[]);

char b[ML];
int k=0,X=0,Y=1,Z=1;

main()
{
	int l;
	char line[ML];
	
	printf("\n\n___________________________________\n\n");
	
	while((l=gl(line))>0){		//printf("\tl=%d\n",l);
		uncomnt(line);
		cpy(line);
	}
	
	printf("\n\n___________________________________\n\n");
	dis(b);
	
}

void cpy(char a[])
{
	int i=0;
	while(a[i]!='\0'){
		b[k]=a[i];
		++k;
		++i;
	}
	b[k]='\0';
}

void uncomnt(char a[])
{
	int i=0;
	
	while(a[i]!='\0'){
		if(X==0){
			if(a[i]=='"'){
				X=1;
				Y=1;
				Z=1;
			}
			else if((a[i]=='/')&&(a[i+1]=='*')){
				a[i]=' ';
				a[i+1]=' ';
				X=1;
				Y=0;
				Z=0;
			}
			else if((a[i]=='/')&&(a[i+1]=='/')){
				a[i]='\n';
				a[i+1]='\0';
			}
		}
		else{
			if((Z==1)&&(a[i]=='"')){
				X=0;
				Y=0;
				}
			else if(Y==0){
				if((a[i]=='*')&&(a[i+1]=='/')){
					a[i]=a[i+1]=' ';
					X=0;
				}
				else{
					if(a[i]!='\n')
						a[i]=' ';
				}
			}
		}
		
		++i;
	}
}

void dis(char a[])
{
	printf("\nprogram removing comments is :\n___________________________________\n\n%s\n___________________________________\n\n",a);
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
