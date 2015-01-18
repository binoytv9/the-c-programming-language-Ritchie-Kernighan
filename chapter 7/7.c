/*	Modify the pattern finding program of Chapter 5 to take its input from a set of
 *	named files or, if no files are named as arguments, from the standard input.
 *	usage : 
 *		find -xn pattern [filename1] [filename2] ...
 *	or
 *		find -x -n pattern [filename1] [filename2] ...
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ML 5000

int getLine(char *a, int max, FILE *fp);

main(int argc, char *argv[])
{
	FILE *fp;
	char *pat;
	char c, line[ML];
	int e, n, ln, found;

	found = e = n = 0;
	
	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0])
			switch(c){
				case 'x':
					e = 1; // except flag
					break;
				case 'n':
					n = 1; // line number flag
					break;
				default :
					fprintf(stderr,"\nInvalid Flag '%c'\n",c);
					argc = 0;
					found = -1;
					break;
			}
	}

	if(argc < 1){
		fprintf(stderr,"Usage: find [option] pattern [filename1] [filename2] ...");
		fprintf(stderr,"\noption : -x,-n or -xn\n");
		exit(1);
	}
	pat = *argv++;
	printf("\n\n");

	// if no filenames given, use stdin
	if(*argv == NULL){
		ln = 0;
		 while(getLine(line,ML,stdin) > 0){
			ln++;
			if((strstr(line,pat) != NULL) != e){
				printf("stdin:");
				if(n)
					printf("%d ",ln);
				printf("%s",line);
				found++;
			}
		}
	}

	// else
	while(*argv){
		if((fp = fopen(*argv,"r")) == NULL){
			fprintf(stderr,"\nerror : unable to open file %s\n",*argv);
			exit(2);
		}
		ln = 0;
		 while(getLine(line,ML,fp) > 0){
			ln++;
			if((strstr(line,pat) != NULL) != e){
				printf("%s:",*argv);
				if(n)
					printf("%d ",ln);
				printf("%s",line);
				found++;
			}
		}
		fclose(fp);
		++argv;
	}
	printf("\n\n");
	
	return found;
}

int getLine(char *a, int max, FILE *fp)
{
	if(fgets(a,max,fp) == NULL)
		return 0;
	else
		return strlen(a);
}
