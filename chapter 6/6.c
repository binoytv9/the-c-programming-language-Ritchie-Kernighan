#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MWL	500
#define MBL	500
#define HASHVAL	101

char getch(void);
void ptable(void);
int undef(char *);
void getdefn(void);
void ungetch(char);
void skipblank(void);
unsigned hash(char *);
int getword(char *,int);
int getidentifier(char *);
void error(char *,char *);
struct nlist *lookup(char *);
struct nlist *install(char *,char *);


struct nlist{
	char *name;
	char *defn;
	struct nlist *next;
};

char buf[MBL],*bp=buf;
struct nlist *hashtab[HASHVAL];

main()
{
	char word[MWL];

	while(getword(word,MWL)!=EOF)
		if(word[0]=='#')
			getdefn();

	ptable();	/* to print the table	*/
}


int getword(char *w,int ml)
{
	char c,*s=w;

	while(isspace(*w=getch()));

	if(!isalpha(c=*w++)){
		*w='\0';
		return c;
	}

	for(;--ml;++w)
		if(!isalnum(*w=getch())){
			ungetch(*w);
			break;
		}

	*w='\0';

	return *s;
}

void getdefn(void)
{

	char c,*d;
	char word[MWL],name[MWL],defn[MWL];

	d=defn;

	if(!getidentifier(word)){
		error(word,"invalid preprocessing directive #");
		return;
	}
	
	if(strcmp(word,"define")==0){		/* #	define	name	defn	*/
		if(!getidentifier(name)){
			error(name,"macro names must be identifiers : ");
			return;
		}

		skipblank();

		while((c=getch())!='\n')
			*d++=c;

		*d='\0';
		install(name,defn);
	}
	else if(strcmp(word,"undef")==0){	/* #	undef	name	*/
		if(!getidentifier(name)){
			error(name,"macro names must be identifiers  : ");
			return;
		}

		if(undef(name)==-1)
			error(name,"not found in the table : ");
	}


}

int getidentifier(char *w)
{
	char c;

	skipblank();

	if(isalpha(c=getch()))
		for(*w++=c;isalnum(c=getch());++w)	
			*w=c;
	*w='\0';

	if(c!=' ' && c!='\t'){	/* not a valid identifier	*/

		for(*w++=c;(c=getch())!='\n';w++)
			*w=c;
		*w='\0';
		return 0;
	}
	else
		return 1;	/* valid identifier		*/
}

struct nlist *install(char *name,char *defn)
{
	unsigned hashval;
	struct nlist *np;

	if((np=lookup(name))==NULL){		/*	not found	*/
		np=(struct nlist *)malloc(sizeof(struct nlist));

		if(np==NULL || (np->name=strdup(name))==NULL)
			return NULL;

		hashval=hash(name);
		np->next= hashtab[hashval];
		hashtab[hashval]=np;
	}
	else					/* already there	*/
		free((void *)np->defn);

		if((np->defn=strdup(defn))==NULL)
			return NULL;

	return np;
}

int undef(char *name)
{
	int cond;
	unsigned hashval;
	struct nlist *np,*np_prev;

	np_prev=NULL;
	hashval=hash(name);

	for(np=hashtab[hashval];np!=NULL;np=np->next){
		if((cond=strcmp(np->name,name))==0)
			break;
		np_prev=np;
	}

	if(np!=NULL){		/* name found		*/
		if(np_prev == NULL)
			hashtab[hashval]=np->next;
		else
			np_prev->next = np->next;

		free((void *)np->name);
		free((void *)np->defn);
		free((void *)np);

		return 1;
	}
	else 			/* name not found	*/
		return -1;
}

struct nlist *lookup(char *name)
{
	struct nlist *np;

	for(np=hashtab[hash(name)];np!=NULL;np=np->next)
		if(strcmp(np->name,name)==0)
			return np;	/* found at np	*/

	return NULL;			/* not found	*/
}

unsigned hash(char *name)
{
	unsigned hashval;

	for(hashval=1;*name!='\0';++name)
		hashval= *name+31*hashval;

	return hashval%HASHVAL;
}

void skipblank(void)
{
	char c;

	while((c=getch())==' ' || c=='\t');
	ungetch(c);
}

void error(char *name,char *msg)
{
	printf("\n\terror : %s%s\n",msg,name);
}

char getch(void)
{
	return bp-buf>0 ? *--bp : getchar();
}

void ungetch(char c)
{
	bp-buf<MBL ? *bp++ = c : printf("\nerror : stack full!!!\n");
}

void ptable(void)
{
	int i=0;
	struct nlist *np;
	
	printf("\n\n\tTABLE\n\n");
	while(i<HASHVAL)
		for(np=hashtab[i++];np!=NULL;np=np->next)
			printf("%s\t\t\t%s\n",np->name,np->defn);
}
