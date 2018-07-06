/* With f written as follows, answer what various input parameters output as */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int main (void)
{
	printf("%d\n", f("abcd", "babc"));
	printf("My guess is: ")
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
