#include<stdio.h>

#define ML 1000
#define N 20

char a[ML];

int gl(char a[]);
void fold(char b[]);

main()
{
	int l;
	char line[ML];

	printf("\n\n");

	while((l=gl(line))>0){
		fold(line);
		printf("\n\nfolded line is :\n\n%s\n",a);
	}
}

void fold(char b[])
{
	int i,k,j;
	i=k=0;
	char last;
	int l,p;
	l=p=0;
	
	while(b[k]!='\0'){
		
		for(j=0;(b[l]!='\0')&&j<N;++j,++l){
			if(b[l]!=' '){
				last=b[l];
				p=j;
			}
		}

		++p;	//printf("\nlast=%c\n",last);printf("\np=%d\n",p);

		for(j=0;(b[k]!='\0')&&j<p;++j,++i,++k){
			a[i]=b[k];
			

		}
		a[i]='\n';
		++i;
		
		/*for(j=0;(b[k]!='\0')&&j<(N-p);++j,++i,++k){
			a[i]=b[k];

		}*/
		
		l=k;
	}
	
	a[i]='\0';
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
