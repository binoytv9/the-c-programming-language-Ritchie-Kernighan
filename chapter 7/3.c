#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

void minprintf(char *fmt,...);

main()
{
	char fmt[] = "int-[%Ld] float-[%5.2lf] str-[%.4s] char-[%2c]";

	printf("\noutput from minprintf\n"); 
	minprintf(fmt,10,15.7,"string",'a');

	printf("\n\noutput from minprintf\n"); 
	printf(fmt,10,15.7,"string",'a');
	printf("\n\n"); 
}

void minprintf(char *fmt,...)
{
	int ival;
	char cval;
	double dval;
	int wid,pre;
	char *p,*sval;
	char arr[10],*arrp;

	va_list ap;		// argument pointer - refer to each argument in turn
	va_start(ap,fmt);	// initialising ap to point to first unnamed argument

	for(p = fmt;*p;++p){
		if(*p != '%'){
			putchar(*p);
			continue;
		}

		wid = 0;
		pre = -1;

		arrp = arr;
		if(*++p == '-'){
			*arrp++ = '-';
			++p;
		}

		while(isdigit(*p))
			*arrp++ = *p++;
		*arrp = '\0';
		wid = atoi(arr);			// minimum field width

		arrp = arr;
		if(*p == '.'){
			while(isdigit(*++p))
				*arrp++ = *p;
			*arrp = '\0';
				pre = atoi(arr);	// precision field
		}	

		switch(*p){
			case 'u':
				ival = va_arg(ap,int);
				printf("%*.*u",wid,pre,ival);
				break;
			case 'X':
			case 'x':
				ival = va_arg(ap,int);
				printf("%*.*x",wid,pre,ival);
				break;
			case 'o':
				ival = va_arg(ap,int);
				printf("%*.*o",wid,pre,ival);
				break;	
			case 'i':
				ival = va_arg(ap,int);
				printf("%*.*i",wid,pre,ival);
				break;
			case 'd':
				ival = va_arg(ap,int);
				printf("%*.*d",wid,pre,ival);
				break;
			case 'f':
				dval = va_arg(ap,double);
				printf("%*.*f",wid,pre,dval);
				break;
			case 'E':
			case 'e':
				dval = va_arg(ap,double);
				printf("%*.*e",wid,pre,dval);
				break;
			case 'G':
			case 'g':
				dval = va_arg(ap,double);
				printf("%*.*g",wid,pre,dval);
				break;
			case 'c':
				cval = va_arg(ap,int);
				printf("%*c",wid,cval);
				break;
			case 's':
				sval = va_arg(ap,char *);
				printf("%*.*s",wid,pre,sval);
				break;
			case '%':
				putchar('%');
				break;
			case 'l':
			case 'L':
				++p;
				switch(*p){
					long ival;
					case 'u':
						ival = va_arg(ap,long unsigned int);
						printf("%*.*lu",wid,pre,ival);
						break;
					case 'X':
					case 'x':
						ival = va_arg(ap,long int);
						printf("%*.*lx",wid,pre,ival);
						break;
					case 'o':
						ival = va_arg(ap,long int);
						printf("%*.*lo",wid,pre,ival);
						break;	
					case 'i':
						ival = va_arg(ap,int);
						printf("%*.*li",wid,pre,ival);
						break;
					case 'd':
						ival = va_arg(ap,long int);
						printf("%*.*ld",wid,pre,ival);
						break;
					case 'f':
						dval = va_arg(ap,double);
						printf("%*.*lf",wid,pre,dval);
						break;
					case 'E':
					case 'e':
						dval = va_arg(ap,double);
						printf("%*.*le",wid,pre,dval);
						break;
					case 'G':
					case 'g':
						dval = va_arg(ap,double);
						printf("%*.*lg",wid,pre,dval);
						break;
					default:
						printf("\ninvalid conversion character l%c\n\n",*p);
						return;
						break;
				}
				break;
			case 'h':
				++p;
				switch(*p){
					case 'u':
						ival = va_arg(ap,int);
						printf("%*.*hu",wid,pre,ival);
						break;
					case 'X':
					case 'x':
						ival = va_arg(ap,int);
						printf("%*.*hx",wid,pre,ival);
						break;
					case 'o':
						ival = va_arg(ap,int);
						printf("%*.*ho",wid,pre,ival);
						break;	
					case 'i':
						ival = va_arg(ap,int);
						printf("%*.*i",wid,pre,ival);
						break;
					case 'd':
						ival = va_arg(ap,int);
						printf("%*.*hd",wid,pre,ival);
						break;
					case 'f':
						dval = va_arg(ap,double);
						printf("%*.*f",wid,pre,dval);
						break;
					case 'E':
					case 'e':
						dval = va_arg(ap,double);
						printf("%*.*e",wid,pre,dval);
						break;
					case 'G':
					case 'g':
						dval = va_arg(ap,double);
						printf("%*.*g",wid,pre,dval);
						break;
					default:
						printf("\ninvalid conversion character h%c\n\n",*p);
						return;
						break;
				}
				break;
			default:
				printf("\ninvalid conversion character %c\n\n",*p);
				return;
				break;
		}
	}
	va_end(ap);
}
