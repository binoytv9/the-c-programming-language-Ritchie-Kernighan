#include<stdio.h>
#include<limits.h>
#include<float.h>

main()
{
	printf("\nlimit of Data types:\n");
	
	
	printf("\nchar\n");
	printf("0 or %d < char < %d\n",CHAR_MIN,UCHAR_MAX);
	printf("%d < unsigned char < %u\n",0,UCHAR_MAX);
	printf("%d < signed char < %d\n",CHAR_MIN,CHAR_MAX);

	
	printf("\nint\n");
	printf("%d < int < %d\n",INT_MIN,INT_MAX);
	printf("%d < unsigned int < %u\n",0,UINT_MAX);
	printf("%d < signed int < %d\n",INT_MIN,INT_MAX);



	printf("\nlong\n");
	printf("%ld < long < %ld\n",LONG_MIN,LONG_MAX);
	printf("%d < unsigned long < %lu\n",0,ULONG_MAX);
	printf("%ld < signed long < %ld\n",LONG_MIN,LONG_MAX);


	printf("\nshort\n");
	printf("%d < short < %d\n",SHRT_MIN,SHRT_MAX);
	printf("%d < unsigned short < %u\n",0,USHRT_MAX);
	printf("%d < signed short < %d\n",SHRT_MIN,SHRT_MAX);

}
