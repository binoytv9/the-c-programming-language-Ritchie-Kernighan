/*	Write a program that will print arbitrary input in a sensible way. As a minimum,
 *	it should print non-graphic characters in octal or hexadecimal according to local
 *	custom, and break long text lines.
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define OCT 8
#define HEX 16
#define MAX 100
#define DEFAULT_BASE HEX	// change here to print non graphic chars in OCT or HEX
#define DEFAULT_LINE_LEN 10	// maximum number of chars in a line

void itoa(int code,char *buf, int base);

main()
{
	int num;
	char *in;
	char buf[MAX];
	char input[] = "a0sd wewe	kwer\n1231\r2$#%#$% ";

	printf("\ninput is :%s",input);

	printf("\n\nafter processing :\n\n");
	for(in = input,num = 1;*in;++in){
		if(!isgraph(*in)){
			itoa(*in,buf,DEFAULT_BASE);
			printf(" %s ",buf);
		}
		else
			putchar(*in);

		if(num == DEFAULT_LINE_LEN){
			putchar('\n');
			num = 0;
		}
		else
			num++;
	}
	printf("\n\n");
}

void itoa(int code,char *buf, int base)
{
	int rem;
	char *sp;
	char *str;
	char s[MAX];

	sp = s;
	while(code){
		rem = code % base;
		if(rem >= 10)
			*sp++ = rem -10 + 'A';
		else
			*sp++ = rem + '0';
		code /= base;
	}

	// adding the '\0' for OCT or '\0x' for HEX
	if(base == OCT)
		str = "\\0";
	else if(base == HEX)
		str = "\\0x";
	while(*str)
		*buf++ = *str++;

	// adding content of s to buf in reverse order
	while(--sp != s)
		*buf++ = *sp;
	*buf++ = *sp;
	*buf = '\0';	
}
