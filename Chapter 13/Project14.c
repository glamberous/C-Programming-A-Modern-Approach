/* detects anagrams */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper & tolower

int main(void)
{
	char ch = 0;
	short alpha[26] = {0}, i = 0;

	printf("Enter the first word: ");
	while (ch != '\n')
	{
		ch = getchar();
		ch = toupper(ch);
		if (isalpha(ch))
			alpha[ch - 'A']++;
	}

	ch = 0;							//resets ch

	printf("Enter the second word: ");
	while (ch != '\n')
	{
		ch = getchar();
		ch = toupper(ch);
		if (isalpha(ch))
			alpha[ch - 'A']--;
	}

	for(i = 0;i < 26;i++)
	{
		if(alpha[i] != 0)
		{
			printf("The words are not anagrams. \n");
			return(0);
		}
	}

	printf("The words are anagrams. \n");

	return (0);
}
