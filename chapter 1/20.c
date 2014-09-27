#include<stdio.h>

#define ML 1000
#define N 8

int gl(char a[]);
void detab(char a[]);

char b[ML];
int k=0;

main()
{
	int l;
	char line[ML];
	
	while((l=gl(line))>0){
		detab(line);
	}
	
	printf("\n\ninput aftr detabbing is :\n\n%s\n\n\n",b);
}

void detab(char a[])
{
	int i=0,j,l=0;
	
	while(a[i]!='\0'){
		if(a[i]=='\t'){
			for(j=0;j<(N-(l%N));++j,++k){
				b[k]=' ';
			}
			l=l+j;
		}
		else{
			b[k]=a[i];
			++k;
			++l;
		}
		++i;
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
