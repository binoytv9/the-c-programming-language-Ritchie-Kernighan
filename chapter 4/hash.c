#include<stdio.h>

#define dp(expr1,expr2) printf(#expr2 #expr1)

main()
{
	int x=2,y=1;
	dp(x,y);
}
