#include<stdio.h>

main()
{
	int h,d;
	float cl,fa;
	cl=-17;
	d=11;
	h=148;
	printf("Celsius------>Fahrenheit\n");
	while(cl<=h){
		fa=9*cl/5+32;
		printf("%3.1f\t\t%3.3f\n",cl,fa);
		cl+=d;
	}
}

