/*	Write a private version of scanf analogous to minprintf from the previous section	*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

int minscanf(char input[], char fmt[], ...);

main()
{
	int n;
	int d;
	char c;
	double f;
	char s[50];

	char fmt[] = "i%d%s %c%f";
	char input[]="i12113 xyz         a12.34";

	printf("\ninput string\t: \"%s\"",input);
	printf("\nformat string\t: \"%s\"",fmt);


	n = minscanf(input,fmt,&d,s,&c,&f);

	printf("\n\noutput from minscanf"); 
	if(n == 1)
		printf("\nn = %d [%d]\n",n,d);
	else if(n == 2)
		printf("\nn = %d [%d] [%s]\n",n,d,s);
	else if(n == 3)
		printf("\nn = %d [%d] [%s] [%c]\n",n,d,s,c);
	else if(n == 4)
		printf("\nn = %d [%d] [%s] [%c] [%f]\n",n,d,s,c,f);
	else
		printf("\nn = %d\n",n);


	n = sscanf(input,fmt,&d,s,&c,&f);

	printf("\noutput from sscanf"); 
	if(n == 1)
		printf("\nn = %d [%d]\n",n,d);
	else if(n == 2)
		printf("\nn = %d [%d] [%s]\n",n,d,s);
	else if(n == 3)
		printf("\nn = %d [%d] [%s] [%c]\n",n,d,s,c);
	else if(n == 4)
		printf("\nn = %d [%d] [%s] [%c] [%f]\n",n,d,s,c,f);
	else
		printf("\nn = %d\n",n);
}

int minscanf(char input[], char fmt[], ...)
{
	int *dref;
	char *cref;
	char *wref;
	double *fref;

	char *arrp;
	char arr[100];
	int count = 0;
	char *p = fmt;
	char *in = input;

	va_list ap;
	va_start(ap,fmt);

	/* this specifies the maximum number of characters to be read in the 
	current reading operation */
	int wid;

	/* this is an optional starting asterisk indicates that the data is to 
	be read from the stream but ignored, i.e. it is not stored in the 
	corresponding argument */
	int ignore;

	/* this variable is used to indicate whether the variable 'in' is 
	incremented inside the switch block. if not incremented then we 
	have to increment it explicitly */
	int increment;


	for(p = fmt,in = input;*p && *in;++p){
		/* if there is a whitespace character in the fmt string then, 
		all the consecutive whitespace chars in the fmt as well as in the 
		input string are skipped */
		if(*p == ' '){
			while(isspace(*p))
				++p;
			while(isspace(*in))
				++in;
		}

		if(*p != '%'){
			if(*p == *in){
				in++;
				continue;
			}
			else
				return count;
		}

		int wid = -1;
		int ignore = 0;

		if(*++p == '*'){
			ignore = 1;
			++p;
		}

		arrp = arr;
		while(isdigit(*p))
			*arrp++ = *p++;
		*arrp = '\0';
		if(strcmp(arr,"") != 0)
			wid = atoi(arr);

		arrp = arr;
		increment = 0;
		switch(*p){
			case 'u':
			case 'X':
			case 'x':
			case 'o':
			case 'i':
			case 'd':
				dref = va_arg(ap,int *);
				while(isspace(*in)){
					++in;
					increment = 1;
				}
				while(isdigit(*in) && wid){
					*arrp++ = *in++;
					increment = 1;
					wid--;
				}
				*arrp = '\0';
				if(!strcmp(arr,""))
					return count;
				if(ignore)
					continue;
				*dref = atoi(arr);
				break;
			case 'f':
			case 'E':
			case 'e':
			case 'G':
			case 'g':
				fref = va_arg(ap,double *);
				while(isspace(*in)){
					++in;
					increment = 1;
				}
				while(isdigit(*in)){	// decimal part
					*arrp++ = *in++;
					increment = 1;
				}
				if(*in == '.')		// decimal point
					*arrp++ = *in++;
				while(isdigit(*in)){	// frational part
					*arrp++ = *in++;
					increment = 1;
				}
				*arrp = '\0';
				if(!strcmp(arr,"") || !strcmp(arr,"."))
					return count;
				if(ignore)
					continue;
				*fref = atof(arr);
				break;
			case 'c':
				wref = va_arg(ap,char *);
				if(*in == '\0')
					return count;
				if(ignore)
					continue;
				*wref = *in++;
				break;
			case 's':
				wref = va_arg(ap,char *);
				while(isspace(*in)){
					++in;
					increment = 1;
				}
				while(!isspace(*in) && wid){
					*arrp++ = *in++;
					increment = 1;
					wid--;
				}
				*arrp = '\0';
				if(!strcmp(arr,""))
					return count;
				if(ignore)
					continue;
				strcpy(wref,arr);
				break;
			case '%':
				if('%' == *in){
					in++;
					continue;
				}
				else
					return count;
				break;
			default:
				printf("\ninvalid conversion character %c\n\n",*p);
				return count;
				break;
		}

		count += 1;
		if(!increment)
			++in;
	}
	va_end(ap);

	return count;
}
