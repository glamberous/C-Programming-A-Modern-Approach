#include <stdio.h>
#include <ctype.h>
/* figures out the amount of scrabble points a word is*/

#define STR_MAX 100

int compute_scrabble_value(const char *);

int main()
{

	char str[STR_MAX + 1];

	printf("This program figures out the amount of scrabble points a word is.\n");
	printf("Enter a word: ");
	printf("%d points!\n", compute_scrabble_value(fgets(str, STR_MAX, stdin)));

	return(0);
}

int compute_scrabble_value(const char *word)
{
	int sum = 0, i;

	for(i = 0; word[i] != '\0'; i++)
	{
		switch(tolower(word[i]))
		{
			case 'a': sum += 1; break;
			case 'b':
			case 'c': sum += 3; break;
			case 'd': sum += 2; break;
			case 'e': sum += 1; break;
			case 'f': sum += 4; break;
			case 'g': sum += 2; break;
			case 'h': sum += 4; break;
			case 'i': sum += 1; break;
			case 'j': sum += 8; break;
			case 'k': sum += 5; break;
			case 'l': sum += 1; break;
			case 'm': sum += 3; break;
			case 'n':
			case 'o': sum += 1; break;
			case 'p': sum += 3; break;
			case 'q': sum += 10; break;
			case 'r':
			case 's':
			case 't':
			case 'u': sum += 1; break;
			case 'v':
			case 'w': sum += 4; break;
			case 'x': sum += 8; break;
			case 'y': sum += 4; break;
			case 'z': sum += 10; break;
		}
	}
	return sum;
}
