/* Double Commit */

/* Takes a first name and last name entered by the user and displays the last name,
a comma, and the first initial, followed by a period. */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_MAX 100

void reverse_name(char *);

int main(void)
{
	char str[STR_MAX + 1];

	printf ("Enter a first and last name: ");
	reverse_name(fgets(str, STR_MAX, stdin));

	return (0);
}

void reverse_name(char *name)
{
	int i;
	char initial = '\0';

	for (i = 0; name[i] == ' '; i++)
		/* intentionally null */;

	initial = name[i++];

	for (;name[i] != ' '; i++)
		/* intentionally null */;
	for (;name[i] == ' '; i++)
		/* intentionally null */;
	for (;name[i] != '\n'; i++)
		putchar(name[i]);

	printf (", %c.\n", initial);						//Prints the user's first initial

}
