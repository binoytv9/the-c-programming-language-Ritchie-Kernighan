#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define NO 0
#define YES 1
#define ML 500
#define MBL 500

char getch(void);
void ungetch(char c);
char *strdupl(char *w);
int check(char c,char *w);
struct tnode *talloc(void);
int getword(char *w,int ml);
void tprint(struct tnode *p);
int cmp(char *w,struct tnode *p,char *pw,int num,int *found);
struct tnode *addtree(struct tnode *p,char *w,int n,int *found);

char buf[MBL],*bp=buf;

struct tnode{
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

main(int argc,char *argv[])
{
	int n;
	int found=NO;
	char word[ML];
	struct tnode *root=NULL;

	n = argv[1] ? atoi(argv[1]) : 6;

	while(getword(word,ML)!=EOF){
		if(isalpha(word[0]) && strlen(word)>=n)
			root=addtree(root,word,n,&found);
		found=NO;
	}

	tprint(root);
	printf("\n\n");
}

struct tnode *addtree(struct tnode *p,char *w,int n,int *found)
{
	int cond;

	if(p==NULL){
		p=talloc();
		p->word = strdupl(w);
		p->match=*found;
		p->left=p->right=NULL;
	}
	else if((cond=cmp(w,p,p->word,n,found))<0)
			p->left=addtree(p->left,w,n,found);
	else if(cond>0)
			p->right=addtree(p->right,w,n,found);
	return p;
}

int cmp(char *w,struct tnode *p,char *pw,int num,int *found)
{
	int i;

	for(i=1;*w==*pw;++pw,++w,++i)
		if(*w=='\0')
			return 0;

	if(i>=num){
		*found=YES;
		p->match=YES;
	}

	return *w-*pw;
}

void tprint(struct tnode *p)
{
	if(p!=NULL){
		tprint(p->left);
		if(p->match)
			printf("\n\t%s",p->word);
		tprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}

char *strdupl(char *w)
{
	char *p;
	p=(char *)malloc(strlen(w)+1);
	if(p!=NULL)
		strcpy(p,w);
	return p;
}

int getword(char *w,int ml)
{
	char c,*s=w;

	while(isspace(*w=getch()));
	
	if(c=check(*w,w))
		return c;

	for(++w;--ml>0;w++)
		if(!isalnum(*w=getch())){
			ungetch(*w);
			*w='\0';
			break;
		}

	return *s;
}

int check(char c,char *w)
{
	char last='1';

	switch(c){
		case '"':	/* skips string  constants */
			while((*++w = getch())!='"');
			*++w='\0';
			return '"';
		case '/':	/* checks if comment */
			switch(*++w=getch()){
				case '/':	/* skips single line comments */
					while((*++w=getch())!='\n');
					*++w='\0';
					return '/';
			
				case '*':	/* skips multiple line comments */
					while((*++w=getch())!=EOF){
						if(*w=='/' && last=='*')
							break;
						last=*w;
					}
					*++w='\0';
					return '/';
				default:		/* not a comment eg: /a 		*/
					ungetch(*w);	/* here 'a' is pushed back to input 	*/
					return '/';	/* and '/' is returned 			*/
			}
		default:
			if(!isalpha(c=*w++)){
			*w ='\0';
			return c;
			}
			else
				return 0;
	}
}



char getch(void)
{
	return bp-buf>0 ?  *--bp : getchar();
}

void ungetch(char c)
{
	bp-buf<MBL ? *bp++ = c : printf("\n\n\terror : stack full!!!\n");
}
