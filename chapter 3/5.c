#include<stdio.h>

#define M 100	
void itob(int n,char s[],int b);
void reverse(char s[]);

main()
{
	int n=123456;
	int b=16;
	char s[M];
	
	itob(n,s,b);
	printf("\n\n%s\n\n",s);
}


void itob(int n,char s[],int b)
{
	int i=0,r;
	
	do{
		r=n%b;
		if(r>9)
			s[i]=(n%b)+'7';
		else
			s[i]=(n%b)+'0';
		++i;
	
	}while(n/=b);
	s[i]='\0';
	
	reverse(s);
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
