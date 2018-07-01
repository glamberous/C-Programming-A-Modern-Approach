/* Modify the read line function */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int main (void)
{
	
	
	
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}