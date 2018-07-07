/* Use the techniques of Section 13.6 to condense the count_spaces function
of Section13.4. In particular, replace the for statement by a while loop. */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int f(char *s, char *t);

int main (void)
{

	return 0;
}

int count_spaces(const char s[])
{
	int count = 0, i = 0;

	while(s[i++])
		if (s[i] == ' ')
			count++;

	return count;
}
