#include<stdio.h>

main()
{
	char s[]="123456";
	int i=0,n=0;		
	for(i=0;s[i]>='0'&&s[i]<='9';++i){
		n=10*n+(s[i]-'0');
	printf("\n%d\n",n);
	}
	printf("\n%d\n",n);
}
