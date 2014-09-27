#include<stdio.h>

#define ML 1000
#define N 8

int gl(char a[]);
void entab(char a[]);

int k=0;
char b[ML];

main()
{
	int l;
	char line[ML];
	
	while((l=gl(line))>0){
		entab(line);
	}
	
	printf("\n\ninput aftr entabbing is :\n\n%s\n\n\n",b);
}

void entab(char a[])
{
	int i,p,bl,t;
	p=1;
	i=bl=t=0;
	
	while(a[i]!='\0'){
		if(a[i]==' '){
			if(p%N!=0){
				++bl;
			}
			else{
				++t;
				bl=0;
			}
		}
		
		else{
			while(t>0){
				b[k]='\t';
				++k;
				--t;
			}
			
			if(a[i]=='\t'){
				bl=0;
				p=p+(N-(p%N));
			}
			
			else{
				while(bl>0){
					b[k]=' ';
					++k;
					--bl;
				}
			}
			
			b[k]=a[i];
			++k;
			
		}
		++i;
		++p;
	}
	b[k]='\0';
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
