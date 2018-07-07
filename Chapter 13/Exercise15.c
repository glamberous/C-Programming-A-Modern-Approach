/* With f written as follows, answer what various input parameters output as */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int f(char *s, char *t);

int main (void)
{
	printf("%d\n", f("abcd", "babc"));
	printf("My guess was: 3\n");

	printf("%d\n", f("abcd", "bcd"));
	printf("My guess was: 0\n");

	printf("Function f returns the position of the first character that doesn't\n"
					"have a matching character in the two strings.\n");
	return 0;
}

int f(char *s, char *t)
{
	char *p1, *p2;

	for (p1 = s; *p1; p1++)
	{
		for (p2 = t; *p2; p2++)
		{
			if (*p1 == *p2) break;
		}
		if (*p2 == '\0') break;
	}
	return p1 - s;
}
