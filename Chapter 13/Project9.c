/* Program counts the number of vowels in a user's input */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_MAX 100

int compute_vowel_count(const char *);

int main(void)
{
	char str[STR_MAX + 1];

	printf ("This program will count the number of vowels that are in your input\n");
	printf ("Enter a sentence: ");
	printf ("Your sentence contains %d vowels.\n", compute_vowel_count(fgets(str, STR_MAX, stdin)));

	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int i, vowels = 0;

	for (i = 0; sentence[i] != '\0'; i++)
	{
		switch (tolower(sentence[i]))
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': vowels++;
		}
	}

	return vowels;
}
