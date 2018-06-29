/* Takes a first name and last name entered by the user and displays the last name, 
a comma, and the first initial, followed by a period. */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper




int check(int x, int y)
{
	int n = 0;
	
	printf("Enter in the check number: ");
	scanf("%d", &n);
	
	return (x >= 0 && x =< n-1 && y >= 0 && y =< n-1);
}


int main(void)
{	
	int x = 0, y = 0;
	
	printf("Enter in x and y: ");
	scanf("%d %d", &x, &y);
	x = check(x, y);
	if (x)
		printf("x and y falls within range of n.");
	else
		printf("x and y doesn't fall within range of n.");
	
	return (0);
}