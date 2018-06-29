/* detects anagrams */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper & tolower
#include <stdbool.h>	//booleans
#include <stdlib.h>		//exit

void read_word(short alpha[26]);
bool equal_array(short alpha1[26], short alpha2[26]);

char ch = 0;

int main(void)
{	
	short alpha1[26] = {0}, alpha2[26] = {0};
	
	printf("Enter the first word: ");
	read_word(alpha1);
	
	printf("Enter the second word: ");
	read_word(alpha2);
	
	if(equal_array(alpha1, alpha2))
		printf("The words are anagrams.");
	else
		printf("The words are not anagrams.");
	
	exit(0);
}


void read_word(short alpha[26])
{	
	while (ch != '\n')
	{
		ch = getchar();
		ch = toupper(ch);
		if (isalpha(ch))
			alpha[ch - 'A']++;
	}
	ch = 0;
}

bool equal_array(short alpha1[26], short alpha2[26])
{
	short i;
	
	for(i = 0;i < 26;i++)
	{
		if(alpha1[i] != alpha2[i])
		{
			return(0);
		}
	}
	
	return(1);
}