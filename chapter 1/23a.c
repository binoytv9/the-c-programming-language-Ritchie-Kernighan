#include<stdio.h>

#define ML 1000

int gl(char a[]);
void cpy(char a[],char b[],int s,int sl);
int dcomnt(char a[],int s,int sl);

main()
{
	int l,d,s=0;
	char lng[ML],line[ML];
	
	while((l=gl(line))>0)
	{								//printf("\tl=%d\n",l);
		d=dcomnt(line,s,s+l);					//printf("\td=%d\n",d);	
		if(d==0)
		{
			cpy(lng,line,s,s+l);
			s=s+l;
		}
		else
		{
			cpy(lng,line,s,s+d);
			s=s+d;
			lng[s+d]='\n';				//printf("\tlng[%d]=nl\n",s);
			++s;
		}

	}
	
	lng[s]='\0';						//printf("\tlng[%d]=\\0\n",s);
	printf("\n\nprogrm without comments is: \n");
	int i=0;
	while(i<s)
	{
		printf("%c",lng[i]);
		++i;
	}
	
	
}

int dcomnt(char a[],int s,int sl)
{
	int i=0;
	while(s<sl)
	{
		if((a[i]=='/')&&(a[i+1]=='/'))
		{
			return i;
		}
		++s;
		++i;
	}
	return 0;
}

void cpy(char a[],char b[],int s,int sl)
{
	int i=0,r=0;					//printf("\ts=%d\n",s);printf("\tsl=%d\n",sl);
	while(s<sl)
	{
		a[s]=b[i];				//printf("\na[%d]=b[%d]=%c\n",s,i,b[i]);
		++s;
		++i;
	}
}

int gl(char a[])
{
	int i=0;
	char c;
	
	while((i<ML)&&((c=getchar())!=EOF)&&(c!='\n'))
	{
		a[i]=c;
		++i;
	}
	
	if(c=='\n')
	{
		a[i]='\n';
		++i;
	}

	a[i]='\0';
	
	return i;	
}
