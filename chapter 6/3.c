#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define ML 500
#define MBL 500
#define MLI 500

char getch(void);
void ungetch(char c);
char *strdupl(char *s);
struct tnode *talloc(void);
void tprint(struct tnode *p);
int noiseword(char **,char *,int);
int getword(char *w,int ml,int *ln);
struct tnode *addtree(struct tnode *p,char *word,int ln);

FILE *fptr;
int lineno=1;			/* to count no of lines  */
char buf[MBL],*bp=buf;

struct tnode{
	int pos;		/* to store the index of lnum  	*/
	char *word;
	int lnum[MLI];		/* to store line numbers 	*/
	struct tnode *left;
	struct tnode *right;
};

main()
{
	int len,ln=1;		/* stores the current line number */
	char word[ML];
	struct tnode *root=NULL;

			/* add or delete noise words here */
	char *nword[]=	{
					"the"	,
					"and"	,
					"a"	,
					"to"	,
					"of"	,
					"in"	,
					"i"	,
					"is"	,
					"that"	,
					"it"	,
					"on"	,
					"you"	,
					"this"	,
					"for"	,
					"but"	,
					"with"	,
					"are"	,
					"have"	,
					"be"	,
					"at"	,
					"or"	,
					"as"	,
					"was"	,
					"so"	,
					"if"	,
					"out"	,
					"not"
			};

	len = sizeof(nword)/sizeof(*nword);	/* no of noise words */

	fptr=fopen("input_filename","r");		/* "input_filename" is the name of the file */

	while(getword(word,ML,&ln)!=EOF)
		if(isalpha(word[0]) && noiseword(nword,word,27))
			root = addtree(root,word,ln);

	printf("\n\t    WORD    \tLINE_NUMBER\n");
	printf("_________________________________\n");

	tprint(root);
	printf("\n\n");

	fclose(fptr);
}

int noiseword(char **nw,char *w,int len)	/* skips noise words 	  */
{						/* return 0 if noise word */
	while(len--)				/* else return 1	  */
		if(strcmp(*nw++,w)==0)
			return 0;

	return 1;
}

int getword(char *w,int ml,int *ln)
{
	char c,*s=w;

	while((*w=getch())!='\n' && isspace(*w));

	if(*w=='\n')	/* checks end of line */
		*ln=++lineno;
	
	if(!isalpha(c=*w++)){
		*w='\0';
		return c;
	}

	for(;--ml>0;w++)
		if(!isalnum(*w=getch())){
			ungetch(*w);
			break;
		}

		*w='\0';
		return *s;
}

char getch(void)
{
	return bp-buf>0 ? *--bp : fgetc(fptr);		/* fgetc reads each character from the file "filename" */
}

void ungetch(char c)
{
	bp-buf<MBL ? *bp++ = c : printf("\n\terror : stack full!!!\n");
}

struct tnode *addtree(struct tnode *p,char *word,int ln)
{
	int cond;

	if(p==NULL){
		p=talloc();
		p->word=strdupl(word);
		*p->lnum = ln;
		p->pos=1;
		p->left=p->right=NULL;
	}
	else if((cond=strcmp(word,p->word))==0)
		p->lnum[p->pos++]=ln;
	else if(cond<0)
		p->left = addtree(p->left,word,ln);
	else
		p->right=addtree(p->right,word,ln);

	return p;
}

struct tnode *talloc(void)
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdupl(char *s)
{
	char *p;

	p=(char *)malloc(strlen(s)+1);

	if(p!=NULL)
		strcpy(p,s);

	return p;
}

void tprint(struct tnode *p)
{
	int *ln=p->lnum;

	if(p!=NULL){
		tprint(p->left);

		printf("\n%-20s\t",p->word);
		while(p->pos--)
			printf("%3d ",*ln++);
		printf("\n");

		tprint(p->right);
	}
}
