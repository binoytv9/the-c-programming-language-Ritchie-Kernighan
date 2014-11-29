#include<stdio.h>
#include<stdarg.h>

void minprintf(char *fmt,...);

main()
{
	char fmt[]="int %ld d %5.2f s %.4s";

	printf("\n\n"); 
	minprintf(fmt,10,15.7,"string");
	printf("\n\n"); 

/*	printf("int %.3d d %5.2f s %.4s",10,15.7,"string");
	printf("\n\n"); 
*/
}


void minprintf(char *fmt,...)
{
	int wid,pre;
	va_list ap;
	char arr[50],*arrp;
	char *p,*sval;
	int ival;
	double dval;

	va_start(ap,fmt);

	for(p=fmt;*p;++p){
		if(*p != '%'){
			putchar(*p);
			continue;
		}

		wid=0;
		pre=-1;

		arrp=arr;
		if(*++p == '-'){
			*arrp++ = '-';
			++p;
		}

		while(isdigit(*p))
			*arrp++ = *p++;
		*arrp='\0';
		wid=atoi(arr);

		arrp=arr;
		if(*p++ == '.'){
			while(isdigit(*p))
				*arrp++ = *p++;
			*arrp='\0';
			pre=atoi(arr);
		}	
		else
			--p;	

		switch(*p){
			case 'u':
				ival=va_arg(ap,int);
				printf("%*.*u",wid,pre,ival);
				break;
			case 'X':
			case 'x':
				ival=va_arg(ap,int);
				printf("%*.*x",wid,pre,ival);
				break;
			case 'o':
				ival=va_arg(ap,int);
				printf("%*.*o",wid,pre,ival);
				break;	
			case 'i':
			case 'd':
				ival=va_arg(ap,int);
				printf("%*.*d",wid,pre,ival);
				break;
			case 'f':
				dval=va_arg(ap,double);
				printf("%*.*f",wid,pre,dval);
				break;
			case 'E':
			case 'e':
				dval=va_arg(ap,double);
				printf("%*.*e",wid,pre,dval);
				break;
			case 'G':
			case 'g':
				dval=va_arg(ap,double);
				printf("%*.*g",wid,pre,dval);
				break;
			case 's':
				sval=va_arg(ap,char *);
				printf("%*.*s",wid,pre,sval);
				break;
			case '%':
				putchar('%');
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
