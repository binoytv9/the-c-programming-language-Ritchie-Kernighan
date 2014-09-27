#include<stdio.h>

float ftc(int);
float ctf(int);

main()
{
	int u,d,l;
	int cl,fa;

	l=0;
	u=300;
	d=20;
	
	printf("\n\nThe fahrenheit to celsius convertion is: \n");
	for(fa=l;fa<=u;fa+=d)
	{
		printf("%3d------->%.1f\n",fa,ftc(fa));
	}
	
	l=-17;
	u=148;
	d=11;
	
	printf("\n\nThe celsius to fahrenheit convertion is: \n");
	for(cl=l;cl<=u;cl+=d)
	{
		printf("%3d------->%.1f\n",cl,ctf(cl));
	}
}

float ftc(int fa)
{
	return(5.0*(fa-32)/9);
}


float ctf(int cl)
{
	return(cl*9.0/5+32);
}
	
