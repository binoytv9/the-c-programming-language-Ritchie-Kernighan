#include<stdio.h>

main()
{
	char c=getchar();
	int b;
	printf("\n\n\n\n\n");
	while(c!=EOF){
		if(c==' '){
			++b;
			if(b==1){
				putchar(c);
			}
		}
		else{
			putchar(c);
			b=0;
		}		

		c=getchar();
		
	}
}
