/* What will the values of i, s, and j be? */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int main (void)
{
	int i = 0, j = 0;
	char s[20];

	scanf("%d%s%d", &i, s, &j); // user inputs "12abc34 56def78", what will the value of i, s, and j be?
	
	printf("%d, %s, %d", i, s, j); // i predict this will print out as "12, abc34, 56"
	
}