#include<stdio.h>

void qsort(int v[],int l,int r);
void swap(int v[],int i,int j);

main()
{
	int a[]={5,1,0,3,4,2};
	int i=0;
	printf("\nb4 sorting...\n");
	while(i<6)
		printf("%d  ",a[i++]);

	qsort(a,0,5);
	
	i=0;
	printf("\naftr sorting...\n");
	while(i<6)
		printf("%d  ",a[i++]);
}

void qsort(int v[],int l,int r)
{
	int last,i,j;
	if(l>=r)
		return ;
	
	swap(v,l,(l+r)/2);
	
	last=l;
	for(i=l+1;i<=r;++i)
		if(v[i]<v[l])
			swap(v,++last,i);
	
	swap(v,l,last);
	qsort(v,l,last-1);
	qsort(v,last+1,r);
}

void swap(int v[],int i,int j)
{
	int t;
	t=v[i];
	v[i]=v[j];
	v[j]=t;
}
