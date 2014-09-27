#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define ML 500
#define MBL 500
#define MAL 500

char getch(void);
void ungetch(char);
char *strdupl(char *);
int getword(char *,int);
struct tnode *talloc(void);
void swap(struct tnode *[],int,int);
void qksort(struct tnode *[],int,int);
struct tnode *addtree(struct tnode *,char *,struct tnode *[]);

int len;
char buf[MBL],*bp=buf;

struct tnode{
	int count;
	char *word;
	struct tnode *left;
	struct tnode *right;
};

main()
{
	int i=0;
	char word[ML];
	struct tnode *array[MAL];	/* array to store structure address of all the words */
	struct tnode *root=NULL;

	while(getword(word,ML)!=EOF)
		if(isalpha(word[0]))
			root = addtree(root,word,array);

	qksort(array,0,len-1);

	while(i<len)
		printf("\n%d\t%s",array[i++]->count,array[i]->word);
	printf("\n\n");
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
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}

	*w='\0';
	return *s;
}

char getch(void)
{
	return bp-buf>0 ? *--bp : getchar();
}

void ungetch(char c)
{
	bp-buf<MBL ? *bp++ = c : printf("\nerror : stack full!!!");
}

struct tnode *addtree(struct tnode *p,char *word,struct tnode *array[])
{
	int cond;

	if(p==NULL){
		p=talloc();
		p->word=strdupl(word);
		p->count=1;
		p->left=p->right=NULL;

		array[len++]=p;		/* storing address of each structure */
	}
	else if((cond=strcmp(word,p->word))==0)
		p->count++;
	else if(cond<0)
		p->left=addtree(p->left,word,array);
	else
		p->right=addtree(p->right,word,array);

	return p;
}

struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}

char *strdupl(char *p)
{
	char *s;

	s=(char *)malloc(strlen(p)+1);

	if(s!=NULL)
		strcpy(s,p);

	return s;
}

void qksort(struct tnode *array[],int l,int r)
{
	int last,i,j;

	if(l>=r)
		return ;

	swap(array,l,(l+r)/2);
	
	last=l;
	for(i=l+1;i<=r;++i)
		if(array[i]->count > array[l]->count)	/* to sort in  decreasing order of count */
			swap(array,++last,i);
	
	swap(array,l,last);
	qksort(array,l,last-1);
	qksort(array,last+1,r);
}

void swap(struct tnode *array[],int i,int j)
{
	struct tnode *tmp;

	tmp=array[i];
	array[i]=array[j];
	array[j]=tmp;
}
