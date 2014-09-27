#include<stdio.h>

main()
{
	char i;
	
	i=getchar();
	
	printf("\n\n\n\n");
	
	while(i!=EOF){
		if(i=='\b'){
			printf("\\b");
			//putchar('\\');
			//putchar('b');
		}
		
		else if(i=='\t'){
			printf("\\t");
			//putchar('\\');
			//putchar('t');
		}
		
		else if(i=='\\'){
			printf("\\\\");
			//putchar('\\');
			//putchar('\\');
		}
		
		else
			putchar(i);
			
		i=getchar();
	}
	
}
