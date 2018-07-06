/* Modify a custom strcmp to use pointer arithmetic */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int str_cmp(char *, char *);

int main (void)
{
	char s[STR_LENGTH] = "Jimmy";
	char t[STR_LENGTH] = "Jimmy";

	printf("%d", str_cmp(s, t));
	putchar('\n');
}

int str_cmp(char *s, char *t)
{
	while (*s == *t)
	{
		if (*s == '\0')
		{
			return 0;
		}
		s++; t++;
	}
	return *s - *t;
}
