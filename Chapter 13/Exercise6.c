/* Write a function named censor that modifies a string by replacing every
occurance of foo by xxx. For example, the string "food fool" would become
"xxxd xxxl". Make the function as short as possible without sacrificing clarity. */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_LENGTH 100

void capitalize (char str[], int n);
int read_line(char[], int);
void censor(char[], int);

int main (void)
{
	char str[STR_LENGTH + 1];

	read_line(str, STR_LENGTH);
	capitalize(str, STR_LENGTH);

	puts(str);
}

void censor (char str[], int n)
{
	char foo = "foo";
	char *strP = str, *fooP = foo;
	short count = 0;

	do //Working on this loop still
	{
		while(*strP + count == *fooP + count && count < 3)
			count++;

		if (count = 3)
		{
			*strP + count = 'x';
			--count;
		}
		count = 0;
	} while(++strP != '\0' && strP < str + n);
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
