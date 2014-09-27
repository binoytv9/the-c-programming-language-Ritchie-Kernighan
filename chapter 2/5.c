#include<stdio.h>

int squeeze(char a[], char b[]);

main()
{
	char a[]="binoy";
	char b[]="acd";
	int p;
	
	p=any(a,b);
	if(p>=0)
		printf("\nfirst common charactr is \'%c\' & itz position is at %d\n",a[p],p+1);
	else
		printf("\nno common charactr!!!\n");

}


int any(char a[], char b[])
{
	int i,j;

	for (i=0; b[i] != '\0'; i++)
		for(j=0;a[j]!='\0';j++)
			if (b[i] == a[j])
				return j;
	return -1;				
}
