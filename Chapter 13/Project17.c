/* Program checks if entry is a palindrome */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time
#include <ctype.h>			//toupper
#include <string.h>

#define STR_MAX 100

void clear_array (char *ch);
bool is_palindrome(char *message);
void exit_program();

int main (void)
{
	char str[STR_MAX];

	while(1)
	{
		clear_array(str);
		fgets(str, STR_MAX, stdin);

		if(is_palindrome(str))
			printf("Palindrome! \n\n");
		else
			printf("Not a palindrome. \n\n");

		exit_program();
	}
}

void clear_array (char *ch)
{
	char *p;

	for(p = ch; p < ch + STR_MAX; p++)
	{
		*p = '\0';
	}

}

bool is_palindrome(char *message)
{
	char *front = message, *end = message + ((strlen(message)) - 1);

	*(end--) = '\0';
	while(toupper(*front) == toupper(*end))
	{
		end--;
		front++;
		if(front >= end)
		{
			return true;
		}
	}

	return false;
}

void exit_program()
{
	char temp;

	while(1)
	{
		temp = 0;
		printf("Would you like to try again? (Y/N)");

		while(temp != '\n')
		{
			temp = getchar();
			temp = toupper(temp);

			if(temp == 'Y')
			{
				while(temp != '\n')
				{
					temp = getchar();
				}
				return;
			}
			else if(temp == 'N')
			{
				while(temp != '\n')
				{
					temp = getchar();
				}
				exit (EXIT_SUCCESS);
			}
		}

		printf("Invalid input.");
	}
}
