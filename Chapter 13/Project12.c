/* Takes a sentence and reverses it */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define MAX_CHAR 20
#define MAX_WORDS 30

void fill_word_array(char [MAX_WORDS + 1][MAX_CHAR + 1]);

int main(void)
{
	char words[MAX_WORDS+1][MAX_CHAR+1], punctuation = '\0';
	int i = 0;


	printf ("Enter a sentence to be reversed: ");
	fill_word_array(words);

	for(i = 0; i < MAX_WORDS; i++)
	{
		printf("%s", words[i]);
	}

	return 0;
}





void fill_word_array(char words[MAX_WORDS + 1][MAX_CHAR + 1])
	{
		int i = 1;
		char *p = &words[0][0];

		while (1)
		{
			//*p = getchar();
			while (isalpha(*p) == 0)
			{
				if (*p == '\n')
				{
					return;
				}
				*(p++) = getchar();
			}

			while (isalpha(*p) != 0)
			{
				*(p++) = getchar();
			}
			p = words[i++];
		}
	}
