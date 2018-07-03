/* Write a function named censor that modifies a string by replacing every
occurance of foo by xxx. For example, the string "food fool" would become
"xxxd xxxl". Make the function as short as possible without sacrificing clarity. */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_LENGTH 100

void capitalize (char str[], int n);
int read_line(char[], int);
void censor (char *, int);

int main (void)
{
	char str[STR_LENGTH + 1];

	read_line(str, STR_LENGTH);
	censor(str, STR_LENGTH);

	puts(str);
}

void censor (char str[], int n)
{
	char const *fooP = "foo";
	char *strP = str;
	int count = 0;

	while(*strP != '\0' && strP < str + n)
	{
		while(*strP + count == *fooP + (count % 3))
		{
			count++;
		}

		printf("%d", count);

		if (count >= 3)
		{
			while(count-- > 0)
			{
				*(strP + count) = 'x';
			}
		}
		count = 0;
		strP++;
	}
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
