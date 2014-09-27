#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ML	500
#define MLEN	1000

int gl(char *l,int mlen);
int rl(char *lp[], int ml);
void wl(char *lp[], int nl);
void swap(void *v[],int left,int right);
void qsort2(void *v[],int left,int right,int (*cmpp)(void *,void *));
int numcmp(char *,char *);

int r;

main(int argc,char *argv[])
{
	int nl,n=0,i=0;
	char *lp[ML];
	char c;
	
	while(--argc > 0 && (*++argv)[0]=='-')
		while(c = *++argv[0])
			switch(c){
				case 'n':
					n=1;
					break;
				case 'r':
					r=1;
					break;
				default:
					
					printf("\nusage: qsort [OPTION]\noptions:\n-n\tsort lines numerically (in ascending order)");
					printf("\n-r\tsort lines numerically (in descending order)");
					printf("\n<empty>\tsort lines lexicographically\n");
					exit(0);
			}		
	
	if((nl=rl(lp,ML))>0){
		qsort2((void **)lp,0,nl-1,(int (*)(void*,void*))(n ? numcmp : strcmp));
		printf("\n\n---------sorted o/p---------\n\n");
		wl(lp,nl);
	}
	
}

void qsort2(void *v[],int left,int right,int (*cmpp)(void *,void *))
{
	int last,i;
	if(left>=right)
		return;
	
	swap(v,left,(right+left)/2);
	last=left;
	
	for(i=last+1;i<=right;++i)	
		if(r ? (*cmpp)(v[i],v[left])>0 : (*cmpp)(v[i],v[left])<0)
			swap(v,++last,i);
	
	swap(v,left,last);
	qsort2(v,left,last-1,cmpp);
	qsort2(v,last+1,right,cmpp);	
}

int numcmp(char *a,char *b)
{
	double x,y;
	x=atof(a);
	y=atof(b);
	
	if(x<y)
		return -1;
	else if(x>y)
		return 1;
	else
		return 0;
}

void swap(void *v[],int left,int right)
{
	void *tmp;
	
	tmp=v[left];
	v[left]=v[right];
	v[right]=tmp;
}


void wl(char *lp[], int nl)
{
	while(*lp)
		printf("%s\n",*lp++);
}

int rl(char *lp[], int ml)
{
	int l,nl=0;
	char *p,line[MLEN];
	
	while((l=gl(line,MLEN))){
		if(nl>ml || (p=malloc(l))==NULL){
			printf("\nerror:either maximum lines or no memory available to allocate\n");
			lp[nl]='\0';
			return nl;
		}
		else{
			strcpy(p,line);
			lp[nl++]=p;
		}
	}
	lp[nl]='\0';
	return nl;
}
	
int gl(char *l,int mlen)
{
	char *s=l;
	char c;
	
	while((l-s)<mlen && (c=getchar())!=EOF && c!='\n')
		*l++=c;
	if(c=='\n')
		*l='\0';
	
	return l-s;
}
