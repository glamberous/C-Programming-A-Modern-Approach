/* Program checks if entry is a palindrome */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time
#include <ctype.h>			//toupper

#define LENGTH 100

void clear_array (char ch[], int i);
void get_input(char ch[], int *count);
bool palindrome_check(char ch[], int count);
void exit_program();

int main (void)
{
	char ch[LENGTH];
	int count;
	
	while(1)
	{
		clear_array(ch, LENGTH);
		get_input(ch, &count);
		
		if(palindrome_check(ch, count))
			printf("Palindrome! \n\n");
		else
			printf("Not a palindrome. \n\n");
		
		exit_program();
	}
}

void clear_array (char ch[], int i)
{
	char *p;
	
	for(p = ch; p < ch + i; p++)
	{
		*p = 0;
	}
	
}

void get_input(char ch[], int *count)
{
	char *p = ch;
	*count = 0;
	
	printf("Enter a message: ");
	
	while(*p != '\n' && p < ch + LENGTH)
	{
		*p = getchar();
		*p = toupper(*p);
		
		if (*p >= 'A' && *p <= 'Z')
		{
			p++;
			(*count)++;
		}
	}
}

bool palindrome_check(char ch[], int count)
{
	char *plow = ch + (int)((count/2)-1), *phigh = ch + (int)((count/2));
	
	if(count % 2)
	{
		phigh++;
	}
	
	count = count/2;
	
	while(*plow == *phigh)
	{
		plow--;
		phigh++;
		count--;
	}
	
	if(count == 0)
		return true;
	else
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