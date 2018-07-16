/* Takes a sentence and reverses it */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define MAX_CHAR 20
#define MAX_WORDS 30

void fill_word_array(char [MAX_WORDS + 1][MAX_CHAR + 1], char *);

int main(void)
{
	char words[MAX_WORDS+1][MAX_CHAR+1] = {'\0'}, punctuation = '\0';
	int i = 0;


	printf ("Enter a sentence to be reversed: ");
	fill_word_array(words, &punctuation);

	/*for(i = 0; i < MAX_WORDS; i++)
	{
		printf("%s", words[i]);
	}*/
	puts(words[0]);
	puts(words[1]);
	puts(words[2]);
	putchar(punctuation);

	return 0;
}





void fill_word_array(char words[MAX_WORDS + 1][MAX_CHAR + 1], char *punctuation)
	{
		int i = 0;
		char *p = words[0], temp = '\0';

		while (1)
		{
			//*p = getchar();
			while (isalpha(temp) == 0)
			{
				if (temp == '!' || temp == '.' || temp == '?')
				{
					*punctuation = temp;
				}
				else if (temp == '\n')
				{
					return;
				}
				temp = getchar();
			}

			while (isalpha(temp) != 0)
			{
				*(p++) = temp;
				temp = getchar();
			}
			p = words[++i];
		}
	}
