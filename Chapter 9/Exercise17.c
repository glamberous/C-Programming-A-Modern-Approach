/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int fact1(int n);
int fact2(int n);
int fact3(int n);

int main(void)
{	
	int n = 0;
	
	printf("Enter a number for n: ");
	scanf("%d", &n);
	
	printf("fact1 results: %d\n", fact1(n));
	printf("fact2 results: %d\n", fact2(n));
	printf("fact3 results: %d\n", fact3(n));
	
	return (0);
}

int fact1(int n)									//Original from the book
{
	if (n <= 1)
		return 1;
	else
		return n * fact1(n-1);
}

int fact2(int n)									//Reorganized into a ternary operator
{
	return ((n <= 1) ? 1 : (n * fact2(n -1)));
}

int fact3(int n)									//Removed the recursion
{
	unsigned int i = 0;
	int x = 1;
	
	for(i = 2; i <= n; i++)
	{
		x *= i;
	}
	return (x);
}

