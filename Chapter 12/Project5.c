/* Takes a sentence and reverses it */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{	
	char ch[100] = {0}, punctuation = 0;
	int sentenceLength = 0, letterCounter = 0;
	char *p = ch, *i;
	
	
	printf ("Enter a sentence to be reversed: ");
	*p = getchar();

	while( *p != '\n' && *p != '.' && *p != '?' && *p != '!')						
	{
		sentenceLength++;
		*(++p) = getchar();
	}
	
	punctuation = *p;
	p = ch;
	
	for (;sentenceLength >= 0; sentenceLength--)				//Length of the sentence counts down
	{									
		if(*(p + sentenceLength) == ' ')						//Stops counting temporarily once it finds a space
		{
			for (i = ch + ((int)sentenceLength + 1); i < ch + ((int)sentenceLength + letterCounter); i++)	//uses the current position in "sentenceLength" and counter for finding words to print a word
			{
				putchar(*i);									//prints the word
			}
			putchar(' ');
			letterCounter = 0;									//resets the letter counter for the next word.
		}
		else if (sentenceLength == 0)
		{
			for (i = ch + sentenceLength; i < ch + ((int)sentenceLength + letterCounter); i++)	
				putchar(*i);													
		}
		letterCounter++;										//As it counts down, it counts letters for "words"
	}
	
	putchar(punctuation);										//tops it all off with a punctuation mark from the user's input.
	
	return (0);
}