#include<stdio.h>

void squeeze(char a[], char b[]);

main()
{
	char a[]="binoy";
	char b[]="bikly";
	
	printf("\na = %s\nb = %s\n",a,b);
	squeeze(a,b);	
	printf("\na = %s\nb = %s\n",a,b);

}


void squeeze(char a[], char b[])
{
	int i,j,k;

	for (i=k=0; b[i] != '\0'; i++){
		for(j=k=0;a[j]!='\0';j++){
			if (b[i] != a[j]){
				a[k++] = a[j];
				//printf("\ni=%d\tj=%d\tk=%d\tb=%s\ta=%s\n",i,j,k,b,a);
			}
			//else
			//	printf("\ni=%d\tj=%d\tk=%d\tb=%s\ta=%s\n",i,j,k,b,a);
		}
	}
	a[k] = '\0';
}
