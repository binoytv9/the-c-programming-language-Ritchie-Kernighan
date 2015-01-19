/*	Write a program to print a set of files, starting each new one on a new page,
 *	with a title and a running page count for each file
 */


#include<stdio.h>
#include<stdlib.h>

#define MAX 500

main(int argc, char *argv[])
{
	int lnum;
	FILE *fp;
	char line[MAX];

	if(argc == 1){
		fprintf(stderr,"usage : %s <filename1> <filename2> ...\n",*argv);
		exit(1);
	}

	while(*++argv){
		if((fp = fopen(*argv,"r")) == NULL){
			fprintf(stderr,"\nerror : unable to open file %s\n",*argv);
			exit(2);
		}

		system("clear");
		printf("\t\t\t********************************************************************\n");
		printf("\t\t\t*                        Title : %-10s                        *\n",*argv);
		printf("\t\t\t********************************************************************\n\n");
		lnum = 0;

		/* printing the content of file */
		while(fgets(line,MAX,fp) != NULL)
			printf("%d. %s",lnum++,line);
	}
	printf("\n\n");
}
