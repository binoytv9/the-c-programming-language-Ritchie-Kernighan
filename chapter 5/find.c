//find -xn pattern
// find -x -n pattern

#include<stdio.h>
#include<string.h>

#define ML 50

int gl(char []);

main(int argc,char *argv[])
{
	int e,n,ln,found;
	char c,line[ML];

	found=ln=e=n=0;
	
	while(--argc>0 && (*++argv)[0]=='-'){
		while(c=*++argv[0])
			switch(c){
				case 'x':
					e=1;
					break;
				case 'n':
					n=1;
					break;
				default :
					printf("\nInvalid Flag '%c'\n",c);
					argc=0;
					found=-1;
					break;
			}
	}
	
	if(argc!=1){
		printf("Usage: find [OPTION] PATTERN");
		printf("\nOPTION : -x,-n or -xn\n");
	}
	else{
		while(gl(line)>0){
			ln++;
			if((strstr(line,*argv)!=NULL)!=e){
				printf("\n\t\t");
				if(n)
					printf("\n\t\t%d ",ln);
				printf("%s\n",line);
				found++;
			}
		}
	}
	
	return found;
	
}

int gl(char a[])
{
	int i=0;
	char c;
	
	while(i<ML && (c=getchar())!=EOF && c!='\n')
		a[i++]=c;
		
	if(c=='\n')
		a[i]='\0';
	
	return i;
}
