/* Search through an array for a specific temperature */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time
#include <ctype.h>			//toupper

#define LENGTH 100

void clear_array (char ch[], int i);
void get_input(char ch[], int *count);
void reverse_print(char ch[], int count);
void exit_program();

int main (void)
{
	char ch[LENGTH];
	int count;
	
	while(1)
	{
		clear_array(ch, LENGTH);
		get_input(ch, &count);
		reverse_print(ch, count);
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
	*p = getchar();
	
	while(*p != '\n' && p < ch + LENGTH)
	{
		*(++p) = getchar();
		(*count)++;
		
	}
}

void reverse_print(char ch[], int count)
{
	char *p;
	
	for(p = ch + count; p >= ch; p--)
	{
		printf("%c", *p);
	}
	printf("\n");
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