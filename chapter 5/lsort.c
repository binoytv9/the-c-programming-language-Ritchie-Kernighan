#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MLI 5000
#define ML 1000
#define MBL 10000

char *lp[ML];
char b[MBL];
char *bp=b;

char *alloc(int);
int gl(char *,int);
int rl(char *lp[],int nl);
void wl(char *pl[],int nl);
void qs(char *lp[],int l,int r);

main()
{
	int nl;

	if((nl=rl(lp,MLI))>=0){
		qs(lp,0,nl-1);
		printf("\n---------------sorted lines---------------\n");
		wl(lp,nl);
		return 0;
	}
	else{
		printf("error:input too big to sort\n");
		return 1;
	}
}

int gl(char *l,int ml)
{
	char c,*k;
	
	k=l;
	
	while((l-k)<ml && (c=getchar())!=EOF && c!='\n')
		*l++=c;
		
	if(c=='\n')
		*l++='\n';
	return l-k;
}

int rl(char *lp[],int mli)
{
	int len,nl;
	char *p,line[ML];

	nl=0;

	while((len=gl(line,ML))>0)
		if(nl>=mli || (p=alloc(len))==NULL)
			return -1;
		else{
			line[len-1]='\0';
			strcpy(p,line);
			lp[nl++]=p;
		}
	return nl;
}

char *alloc(int len)
{
	if((b+MBL-bp)>=len){
		bp+=len;
		return bp-len;
	}
	else{
		printf("\nBuffer Full!!!\n");
		return NULL;
	}
}
void wl(char *lp[],int nl)
{
	int i;
	for(i=0;i<nl;++i)
		printf("%s\n",lp[i]);
}

void qs(char *v[],int l,int r)
{
	int i,last;
	void swap(char *v[],int i,int j);

	if(l>=r)
		return;

	swap(v,l,(l+r)/2);
	last =l;

	for(i=l;i<=r;i++)
		if(strcmp(v[i],v[l])<0)
			swap(v,++last,i);

	swap(v,l,last);
	qs(v,l,last-1);
	qs(v,last+1,r);
}

void swap(char *v[],int i,int j)
{
	char *t;

	t=v[i];
	v[i]=v[j];
	v[j]=t;
}
