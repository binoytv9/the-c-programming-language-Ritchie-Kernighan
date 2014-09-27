#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ML	500
#define MLEN	1000

int gl(char *l,int mlen);
int rl(char *lp[], int ml);
void wl(char *lp[], int nl);
void swap(char *v[],int left,int right);
void qsort2(char *v[],int left,int right,int (*cmpp)(char *,char *));
int numcmp(char *,char *);

main(int argc,char *argv[])
{
	int nl,nc=0,i=0;
	char *lp[ML];
	
	while(argc>1 && strcmp(argv[++i],"-n")==0){
		nc=1;
		break;
	}
	
	if(argc>1 && nc==0){
		printf("\nusage: qsort [OPTION]\noptions:\n-n\tsort lines numerically");
		printf("\n<empty>\tsort lines lexicographically\n");
		exit(0);
	}
	
	
	if((nl=rl(lp,ML))>0){
		qsort2(lp,0,nl-1,(int (*)(char*,char*))(nc ? numcmp : strcmp));
		printf("\n\n---------sorted o/p---------\n\n");
		wl(lp,nl);
	}
	
}

void qsort2(char *v[],int left,int right,int (*cmpp)(char *,char *))
{
	int last,i;
	if(left>=right)
		return;
	
	swap(v,left,(right+left)/2);
	last=left;
	
	for(i=last+1;i<=right;++i)	
		if((*cmpp)(v[i],v[left])<0)
			swap(v,++last,i);
	
	swap(v,left,last);
	qsort2(v,left,last-1,cmpp);
	qsort2(v,last+1,right,cmpp);	
}

int numcmp(char *a,char *b)
{
	int x,y;
	x=atoi(a);
	y=atoi(b);
	
	return (x-y);
}

void swap(char *v[],int left,int right)
{
	char *tmp;
	
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
