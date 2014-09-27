#include<stdio.h>

main(int argc,char *argv[])
{
	int i=1;
	
	while(i<argc){
		printf(i<argc-1? "%s " : "%s\n",argv[i]);
		++i;
	}	
	
	return 0;
}
