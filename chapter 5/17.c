#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define ML	500
#define MLEN	1000

int gl(char *l,int mlen);
int rl(char *lp[], int ml);
void wl(char *lp[], int nl);
void swap(void *v[],int left,int right);
void qsort2(void *v[],int left,int right,int (*cmpp)(void *,void *));
int numcmp(char *,char *);
int stcmp(char *a,char *b);
int nofdigit(int n);

int r,f,d,n,s,colm;

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
				case 'f':
					f=1;
					break;
				case 'd':
					d=1;
					break;
				case 's':
					if(colm=atoi(++argv[0])){
						s=1;
						argv[0]+=nofdigit(colm)-1;
					}
					else
						--argv[0];
					break;
					
				default:
					printf("\nusage: qsort [OPTION]");					
					printf("\n<empty>\tsort lines lexicographically\n");
					printf("\noptions:\n-n\tsort lines numerically (in ascending order)");
					printf("\n-r\tsort lines numerically (in descending order)");
					printf("\n-f\tfold upper and lower case together(i.e., a and A are same)");
					
					printf("\n-d\tdirectory order, ");
					printf("consider only blanks and alphanumeric characters");
					
					printf("\n-sN\tfield-searching capability, ");
					printf("sorts according to the characters starting at the Nth column \n\n");
					
					exit(0);
			}		
	
	if((nl=rl(lp,ML))>0){
		qsort2((void **)lp,0,nl-1,(int (*)(void*,void*))(n ? numcmp : stcmp));	/* n=1 switch to numcmp() */
		printf("\n\n---------sorted o/p---------\n\n");
		wl(lp,nl);
	}
	
}

int nofdigit(int n)
{
	int l=1;
	while(n/=10)
		++l;
	return l;
}

void qsort2(void *v[],int left,int right,int (*cmpp)(void *,void *))
{
	int last,i;
	if(left>=right)
		return;
	
	swap(v,left,(right+left)/2);
	last=left;
	
	for(i=last+1;i<=right;++i)
		if(r ? (*cmpp)(v[i],v[left])>0 : (*cmpp)(v[i],v[left])<0)	/* r=1 reverse order */
			swap(v,++last,i);
	
	swap(v,left,last);
	qsort2(v,left,last-1,cmpp);
	qsort2(v,last+1,right,cmpp);
}

int stcmp(char *a,char *b)
{
	int i=colm;
	
	if(s){
		while(--i>0){
			while(*a++!=' ')
				;
			while(*b++!=' ')
				;
		}
	}
	while(*a || *b){
		if(d){							/* only allows letters, numbers and blanks */
			while(*a && !isalnum(*a) && !isspace(*a))     /* skips characters that are not alphanum and blanks */
				++a;
			while(*b && !isalnum(*b) && !isspace(*b))
				++b;
		}
		if(*a==*b || (f ? abs(*a-*b) == 'a'-'A' : 'a'-'a')){	/* f=1 case insensitive */
			if(*a=='\0')
				return 0;
		}
		else
			return f ? (isupper(*a) ? *a-toupper(*b) : *a-tolower(*b)) : *a-*b;	/* f=1 case insensitive */
		++a;
		++b;
	}
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


/*
1, Justin Timberlake, Title 545, Price $7.30
2, Taylor Swift, Title 723, Price $7.90
3, Mick Jagger, Title 610, Price $7.90
4, Lady Gaga, Title 118, Price $7.30
5, Johnny Cash, Title 482, Price $6.50
6, Elvis Presley, Title 335, Price $7.30
7, John Lennon, Title 271, Price $7.90
8, Michael Jackson, Title 373, Price $5.50
*/
