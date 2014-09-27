#include<stdio.h>

#define M 100	

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
	int n=-10000000000;
	char s[M];
	
	itoa(n,s);
	printf("\n\n%s\n\n",s);
}

void reverse(char s[])
{
	int i=0,j;
	char a[M];
	
	while((a[i]=s[i])!='\0')
		++i;

	for(j=0;i>0;--i,++j)
		s[j]=a[i-1];

}

void itoa(int n,char s[])
{
	int i=0,sign;
	if ((sign=n)<0)
		n=-n;
	
	do {
		s[i++]=abs(n%10)+'0'; 
	} while ((n/=10)!=0);

	if (sign < 0)
		s[i++] = '-';
		
	s[i] = '\0';
	
	reverse(s);
}
