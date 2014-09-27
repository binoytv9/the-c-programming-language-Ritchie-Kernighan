#include<stdio.h>

#define ML 100

long htoi(char a[]);
void lowr(char a[]);
long powr(int a,int b);

main()
{
	char d[ML],c[]="123AB";
	long dec;
	int i=0;
	
	while((d[i]=c[i])!='\0')
		++i;
	d[i]='\0';
	
	lowr(c);
	dec=htoi(c);	
	printf("\n\ninteger representation of %s is %ld\n\n",d,dec);
}

void lowr(char a[])
{
	int i=0;
	
	while(a[i]!='\0'){
		if((a[i]>='A')&&(a[i]<='Z'))
			a[i]=a[i]+32;
		++i;
	}
}

long htoi(char s[])
{
	long dec=0;
	int i,j;
	
	i=j=0;
	
	while(s[i]!='\0')
		++i;
	
	while(i>0){
		if((s[j]>='0')&&(s[j]<='9')){
			dec=dec+((s[j]-'0')*powr(16,i-1));
			printf("\ndec=%ld\n",dec);
		}
		else
			dec=dec+((9+s[j]-2*'0')*powr(16,i-1));
		++j;
		--i;
	}
	return dec;
}

long powr(int a,int b)
{
	long p=1;
	int i=0;
	while(i<b){
		p=p*a;
		++i;printf("\np=%ld\n",p);
	}
	return p;
}
