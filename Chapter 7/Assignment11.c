/* Double Commit */

/* Takes a first name and last name entered by the user and displays the last name,
a comma, and the first initial, followed by a period. */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{	
	char ch = ' ', initial = 0;															
	
	printf ("Enter a first and last name: ");
	
	while (ch == ' ')									//Burns any spaces the user may have entered before the first name
		ch = getchar();	
		
	initial = ch;										//Stores the user's first initial
	
	while (ch != ' ')									//Burns the rest of the user's first name
		ch = getchar();

	while (ch == ' ')									//Burns any spaces the user may have entered between first and last name
		ch = getchar();												
	
	while (ch != '\n' && ch != ' ')						//Prints the User's last name
	{
		putchar(ch);
		ch = getchar();
	}
	
	printf (", %c.\n", initial);						//Prints the user's first initial
	
	return (0);
}
