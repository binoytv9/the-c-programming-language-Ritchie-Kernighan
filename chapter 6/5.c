/*	function undef to remove a name and definition from the table maintained by lookup and install		*/


#include<stdio.h>
#include<string.h>

int undef(char *name):

int undef(char *name)
{
	unsigned hashval;
	struct nlist *np,np_prev;

	hashval=hash(name);
	np_prev=NULL;

	for(np=hashtab[hashval];np!=NULL;np=np->next){
		if(strcmp(np->name,name)==0)
			break;
		np_prev=np;
	}

	if(np!=NULL){
		if(np_prev==NULL)
			hashtab[hashval]=np->next;	/*	word is found at the beginning	*/
		else
			np_prev->next = np->next;

		free((void *)np->name);
		free((void *)np->defn);
		free((void *)np);

		return 1;
	}
	else
		return -1;				/*	word not found	*/
}
