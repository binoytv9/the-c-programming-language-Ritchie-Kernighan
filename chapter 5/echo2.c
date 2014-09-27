#include<stdio.h>

main(int argc,char *argv[])
{
	
	while(argc>1){
		printf(argc>2? "%s " : "%s\n",*++argv);
		argc--;
	}
	
	return 0;
}
