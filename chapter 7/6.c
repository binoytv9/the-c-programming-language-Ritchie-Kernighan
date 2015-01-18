/*	Write a program to compare two files, printing the first line where they differ       */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

int filecmp(FILE *fp1, char *line1, FILE *fp2, char *line2, int max);

main(int argc, char *argv[])
{
	char line1[MAX];
	char line2[MAX];
	FILE *fp1, *fp2;
	char *prog = *argv;

	if(argc != 3){
		printf("usage : compare <filename1> <filename2>\n");
		exit(1);
	}

	if((fp1 = fopen(*++argv,"r")) == NULL){
		fprintf(stderr,"\n%s : error reading file %s\n",prog,*argv);
		exit(2);
	}

	if((fp2 = fopen(*++argv,"r")) == NULL){
		fprintf(stderr,"\n%s : error reading file %s\n",prog,*argv);
		exit(2);
	}

	if(filecmp(fp1,line1,fp2,line2,MAX)){
		printf("\nfiles differs!!!");
		printf("\nin file %s :\n%s",*argv--,line2);
		printf("\nin file %s :\n%s",*argv--,line1);
	}
	else
		printf("\nfiles are same!!!");
	printf("\n\n");
}

/* compares two files line by line */
int filecmp(FILE *fp1, char *line1, FILE *fp2, char *line2, int max)
{
	while((fgets(line1,max,fp1) != NULL) && (fgets(line2,max,fp2) != NULL))
		if(strcmp(line1,line2) != 0)
			return 1;

	return 0;
}
