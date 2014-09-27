#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASHVAL 101

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name,char *def);

struct nlist{
	struct nlist *next;
	char *name;
	char *def;
};

struct nlist *hashtab[HASHVAL];

main()
{
}

unsigned hash(char *s)
{
	unsigned hashval;

	for(hashval=1;s!=NULL;++s)
		hashval = *s + 31 * hashval;

	return hashval%HASHVAL;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for(np=hashtab[hash(s)];np!=NULL;np=np->next)
		if(strcmp(s,np->name)==0)
			return np;

	return NULL;
}

struct nlist *install(char *name,char *def)
{
	unsigned hashval;
	struct nlist *np;

	if((np=lookup(name))==NULL){
		np=(struct nlist *)malloc(sizeof(struct nlist *));

		if(np==NULL || (np->name=strdup(name))==NULL)
			return NULL;

		hashval=hash(name);
		np->next=hashtab[hashval];
		hashtab[hashval]=np;
	}
	else
		free((void *)np->def);

	if((np->def=strdup(def))==NULL)
		return NULL;

	return np;
}
