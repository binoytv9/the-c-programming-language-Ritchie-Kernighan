#include<stdio.h>
#include<string.h>

void getinput(int flag);

main(int argc,char *argv[])
{
	int f;

	if(argc > 1){
		if(strcmp(argv[1],"lower")==0)
			f=0;
		else if(strcmp(argv[1],"upper")==0)
			f=1;
		else{
			printf("\n\nInvalid argument '%s'\n\n",argv[1]);
			return;
		}
	}
	else{
		printf("\n\nInvalid usage!!");
		printf("\nusage : a.out <lower> or <upper>\n\n");
		return;
	}

	getinput(f);
}

void getinput(int f)
{
	int c;
	while((c=getchar())!=EOF)
		printf("%c",f==0 ? tolower(c) : toupper(c));
}
