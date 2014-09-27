#include<stdio.h>
#include<ctype.h>

#define e 2.718281828

double atof(char s[]);
double powr(double val);

main()
{
	char s[]="100.00e1";
	printf("\n%f\n",atof(s));
}

double atof(char s[])
{
	double val,power,num;
	int i,sign,n=0;
	
	for(i=0;isspace(s[i]);i++);
	
	sign=(s[i]=='-') ? -1 : 1;
	
	if((s[i]=='-') || (s[i]=='+'))
		++i;
	for(val=0.0;isdigit(s[i]);++i)
		val=10*val+(s[i]-'0');

	if(s[i]=='.')
		++i;

	for(power=1.0;isdigit(s[i]);++i){
		val=10*val+(s[i]-'0');
		power*=10;
	}

	num=sign*val/power;

	if((s[i]=='e') || (s[i]=='E'))
		++i;
	
	if(s[i]=='-'){
		n=1;
		++i;
	}
	
	for(val=0.0;isdigit(s[i]);++i)
		val=10*val+(s[i]-'0');

	if(n==1)
		return num*(1/powr(val));
	else
		return num*powr(val);
}

double powr(double val)
{
	double exp=1;
	
	while(val--)
		exp*=e;
	return exp;
}
