#include<stdio.h>

main()
{	
	char c[]="BiNoY";
	int i=0;
	while(c[i]!='\0'){
		if((c[i]>='A')&&(c[i]<='Z')){
			c[i]=c[i]+32;		//32='a'-'A'
		}
		++i;
	}
	printf("\n%s\n",c);
}

