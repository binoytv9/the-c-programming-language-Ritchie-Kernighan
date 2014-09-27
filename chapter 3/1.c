#include<stdio.h>

#define N 6

int search(char v[],char x);

main()
{
	int low,mid,high,r;
	char v[]="abcdef";
	char x='c';

	r=search(v,x);
	printf("\np=%d\n",r);	
}
	
int search(char v[],char x)
{	
	
	int low=0,high=N;
	while(low<high){
		if(v[low]==x)
			return low+1;
		++low;
	}
	return -1;
}
