#include<stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

main()
{
	int f,c;
	
	printf("celsius\t\tfahrenheit\n");
	for(c=UPPER;c>=LOWER;c-=STEP){
		printf("%d\t\t%d\n",c,c*9/5+32);
	}
}
