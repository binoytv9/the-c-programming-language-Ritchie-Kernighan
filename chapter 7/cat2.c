/*	program 'cat' which concatenates a set of named files into the standard output	*/

#include<stdio.h>
#include<stdlib.h>

void filecopy(FILE *, FILE *);

main(int argc, char *argv[])
{
	FILE *fp;

	if(argc == 1)	/* no args; copy standard input */
		filecopy(stdin,stdout);
	else
		while(--argc > 0)
			if((fp = fopen(*++argv,"r")) == NULL){
				fprintf(stderr,"\n%s : can't open %s\n","cat",*argv);
				exit(1);
			}
			else{
				filecopy(fp,stdout);
				fclose(fp);
			}
	if(ferror(stdout)){
		fprintf(stderr,"\n%s : error writing stdout\n","cat");
		exit(2);
	}
		
	exit(0);
}

/* copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while((c = getc(ifp)) != EOF)
		putc(c,ofp);
}
