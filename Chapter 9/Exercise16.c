/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int fact1(int n);
int fact2(int n);

int main(void)
{	
	int n = 0;
	
	printf("Enter a number for n: ");
	scanf("%d", &n);
	
	printf("fact1 results: %d\n", fact1(n));
	printf("fact2 results: %d\n", fact2(n));
	
	return (0);
}

int fact1(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fact1(n-1);
}

int fact2(int n)
{
	return ((n <= 1) ? 1 : (n * fact2(n -1)));
}



