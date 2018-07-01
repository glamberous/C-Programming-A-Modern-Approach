/* Which function calls are legal? */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int main (void)
{
	char *p = "abc";

	//putchar(p); // Legal? N, putchar is expecting a char not a pointer to a char // I was correct
	putchar(*p); // Legal? Y, output will be "a"
	puts(p); // Legal? Y, output will be "abc"
	//puts(*p); // Legal? N, puts is expecting a char pointer not a char // I was correct
	
}