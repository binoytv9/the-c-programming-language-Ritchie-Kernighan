#include<stdio.h>
#include<ctype.h>
#include<stddef.h>

#define NKEY	(sizeof k / sizeof(struct key))		/* find value of NKEY at runtime */
#define WL	100
#define MBL	1000

struct key{
	char kwrd[WL];
	int c;		/* count no of keyword */
}k[]={
		{"auto",	0},
		{"break",	0},
		{"case",	0},
		{"char",	0},
		{"const",	0},
		{"continue",	0},
		{"default",	0},
		{"do",		0},
		{"double",	0},
		{"else",	0},
		{"enum",	0},
		{"extern",	0},
		{"float",	0},
		{"for",		0},
		{"goto",	0},
		{"if",		0},
		{"int",		0},	
		{"long",	0},
		{"register",	0},
		{"return",	0},
		{"short",	0},
		{"signed",	0},
		{"sizeof",	0},
		{"static",	0},
		{"struct",	0},
		{"switch",	0},
		{"typedef",	0},
		{"union",	0},
		{"unsigned",	0},
		{"void",	0},
		{"volatile",	0},
		{"while",	0},
	};
	
	

char getword(char *s);
int binarysearch(char *s,struct key *k);
char getch();
void ungetch(char);
int check(char c,char *s);

char buf[MBL],*bf=buf;

main()
{
	char word[WL];
	int i,n,f=0;

	printf("\nentr the C program : \n");			
	while(getword(word)!=EOF){				//printf("\n\"%s\"\n",word);
		if(isalpha(word[0]))
			if((n=binarysearch(word,k))>=0){	//printf("\n%d\n",n);
				++k[n].c;
				f++;			
			}
	}
	
	f ? printf("\ncount\tkeyword\n---------------------\n") : printf("\n\tno keywords found !!!\n\n");
	for(i=0;i<NKEY;++i)
		if(k[i].c>0)
			printf("\n%3d\t%s\n",k[i].c,k[i].kwrd);
}

int binarysearch(char *s,struct key *ky)
{
	int l,h,m,n;
	h=NKEY-1;
					
	for(l=0;l<=h;){
		m=(l+h)/2;		
		if((n=strcmp(s,ky[m].kwrd))<0)
			h=m-1;
		else if(n>0)
			l=m+1;
		else
			return m;
	}
	return -1;
}

char getword(char *s)
{
	char c,*p=s;
	int i;
	
	while(isspace((c=getch())));	/* skip blanks */
	
	if(c!=EOF)
		*s++ = c;

	if(check(c,s))				/*checks whether comment, string constant or preprocessor control lines*/
		return c;

	if(c!='_' && !isalnum(c)){
		*s='\0';
		return c;
	}
	
	for(i=1;i<WL;++i,++s)
		if((*s=getch())!='_' && !isalnum(*s)){
			ungetch(*s);
			break;
		}
	*s='\0';
	return *p;
}

int check(char c,char *s)/* return a positive no if its a comment, string constant. or preprocessor control lines else 0 */
{
	char last;

	switch(c){
		case '"':
			while((*s++ = getch())!='"');	/* if " is found skip till next " */
			*s='\0';
			return c;
		case '/':
			switch(*s = getch()){
				case '/':
					while((*++s=getch()) != '\n');	/* if // is found skip till newline */
					*++s='\0';
					return '/';
				case '*':
					last='a';
					while((*++s=getch())!=EOF){
						if(*s=='/' && last=='*'){
							*++s='\0';
							return '/';
						}
						last=*s;	/* stores the last character */
					}
				default:
					ungetch(*s);
					*++s='\0';
					return '/';
			}
			break;
		case '#':
			while((*s++ = getch())!='\n');		/* skips the preprocessor control lines */
			*s='\0';
			return '#';
	}

	return 0;

}

char getch()
{
	return (bf-buf)>0 ? *--bf : getchar();
}

void ungetch(char c)
{
	(bf-buf)<MBL ? *bf++ = c : printf("\nstack full!!!\n");
}
