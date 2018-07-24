/* Search through an array for a specific temperature */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time
#include <ctype.h>			//toupper
#include <string.h>			//strlen

#define STR_MAX 100

void reverse(char *message);
void clear_array (char ch[]);
void exit_program();

int main (void)
{
	char str[STR_MAX + 1] = {"\0"};

	while(1)
	{
		clear_array(str);
		printf("Please enter a sentence: ");
		fgets(str, STR_MAX, stdin);
		reverse(str);
		puts(str);
		exit_program();
	}
}

void clear_array (char *ch)
{
	char *chP = ch;

	while(chP < ch + STR_MAX)
	{
		*chP = '\0';
		chP++;
	}
}

void reverse(char *message)
{
	char *front = message, *end = message + ((strlen(message)) - 1), temp = '\0';

	*(end--) = temp;				//removes /n from the end of the string.
	while(front < end)
	{
		temp = *front; *front = *end; *end = temp; //Swaps front with end
		front++; end--;
	}
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
