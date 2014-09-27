#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define ML 500
#define MBL 500

char getch(void);
void ungetch(char);
char *strdupl(char *);
struct tnode *talloc(void);
int getword(char *w,int ml);
void tprint(struct tnode *p);
struct tnode *addtree(struct tnode *p,char *w);

char buf[MBL],*bp=buf;

struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

main()
{
	char word[ML];
	struct tnode *root=NULL;

	while(getword(word,ML)!=EOF)
		if(isalpha(word[0]))
			root=addtree(root,word);

	tprint(root);
}

int getword(char *w,int ml)
{
	int i=0;
	char c;

	while(isspace(c=getch()));

	if(!isalpha(*w++ = c)){
		*w='\0';
		return c;
	}

	for(i=1;i<ml && isalnum(c = getch());++i)
		*w++ = c;
	*w='\0';

	if(c!=EOF)
		ungetch(c);


	return c;
}

struct tnode *addtree(struct tnode *p,char *w)
{
	int cond;

	if(p==NULL){
		p=talloc();
		p->word=strdupl(w);
		p->count=1;
		p->left=p->right=NULL;
	}
	else if((cond=strcmp(w,p->word))==0)
		p->count++;
	else if(cond<0)
		p->left=addtree(p->left,w);
	else
		p->right=addtree(p->right,w);

	return p;
}

void tprint(struct tnode *p)
{
	if(p!=NULL){
		tprint(p->left);
		printf("%d %s\n",p->count,p->word);
		tprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupl(char *w)
{
	char *p;
	p=(char *)malloc(strlen(w)+1);
	if(p!=NULL)
		strcpy(p,w);

	return p;
}

char getch(void)
{
		return bp-buf>0 ? *--bp : getchar();
}
	
void ungetch(char c)
{
	bp-buf<MBL ? *bp++ = c : printf("\n\t\terror : stack full!!!\n");
}
