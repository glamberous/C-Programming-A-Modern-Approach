/* detects anagrams */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper & tolower

#define STR_MAX 20

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char str1[STR_MAX + 1], str2[STR_MAX +1];
	int i = 0;

	printf("Enter the first word: ");
	fgets(str1, STR_MAX, stdin);

	printf("Enter the second word: ");
	fgets(str2, STR_MAX, stdin);

	if (are_anagrams(str1, str2))
		printf("The words are anagrams. \n");
	else
		printf("The words are not anagrams. \n");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int alpha[26] = {0}, i = 0;

	for(i = 0; word1[i] != '\n'; i++)
	{
		if (islower(word1[i]))
			alpha[word1[i] - 'a']++;
		else if(isupper(word1[i]))
			alpha[word1[i] - 'A']++;
	}

	for(i = 0; word2[i] != '\n'; i++)
	{
		if (islower(word2[i]))
			alpha[word1[i] - 'a']--;
		else if(isupper(word2[i]))
			alpha[word1[i] - 'A']--;
	}

	for(i = 0; i < 26; i++)
	{
		if(alpha[i] != 0)
		{
			return false;
		}
	}
	return true;
}
