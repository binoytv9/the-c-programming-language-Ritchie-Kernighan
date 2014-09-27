#include<stdio.h>

main()
{
	int b,c;
	float cel,fa;
	fa=0;
	b=20;
	c=300;
	printf("Fahrenheit------------->Celsius\n");
	while(fa<=c){
		cel=5*(fa-32)/9;
		printf("%3.0f\t\t\t%3.1f\n",fa,cel);
		fa=fa+b;
	}
}
