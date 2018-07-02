/* Write a Capitalization function */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_LENGTH 100

void capitalize (char str[], int n);
int read_line(char[], int);

int main (void)
{
	char str[STR_LENGTH + 1];

	read_line(str, STR_LENGTH);
	capitalize(str, STR_LENGTH);

	puts(str);
}

void capitalize (char str[], int n) // Skips all blank spaces at the start.
{
	char *p = str;

	do
	{
		*p = toupper(*p);
	} while(++p != '\0' && p < str + n);
}

int read_line(char str[], int n) // Skips all blank spaces at the start.
{
	int ch, i = 0;

	while ((ch = getchar()) == ' ')
		/*intentionally null*/;
	str[i] = ch;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[++i] = ch;
	str[++i] = '\0';
	return i;
}
