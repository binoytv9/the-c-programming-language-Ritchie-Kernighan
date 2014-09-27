#include<stdio.h>
#include<string.h>

#define ML 50

main(int argc,char *argv[])
{
	char line[ML];
	int found=0;
	
	if(argc!=2)
		printf("\nUsage: to find a string in another string\n\n");
	
	else
		while(gl(line)>0)
			if(strstr(line,argv[1])!=NULL){
				printf("\n%s\n",line);
				found++;
			}
			
	return found;
}

int gl(char a[])
{
	int i=0;
	char c;
	
	while(i<ML && (c=getchar())!=EOF && c!='\n' )
		a[i++]=c;
	
	if(c=='\n')
		a[i++]='\0';
		
	return i;
}
		
