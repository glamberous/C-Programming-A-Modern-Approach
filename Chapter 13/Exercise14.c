/* What does the following program print? */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int main (void)
{
	char s[] = "Hsjodi", *p;

	for (p = s; *p; p++)
		--*p;
	puts(s);
	return 0;
}
