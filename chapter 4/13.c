#include<stdio.h>
#include<string.h>

#define ML 50

void reverse(char s[]);

int l;
int j;
int i=0;

main()
{
	char s[]="1234567890";
	l=strlen(s);		//printf("\n%d\n",l);
	j=l-1;
	reverse(s);
	printf("\n%s\n",s);
}

void reverse(char s[])
{
	int tmp;
	
	tmp=s[i];
	s[i++]=s[j];
	s[j--]=tmp;

	if(i<l/2)
		reverse(s);
}
