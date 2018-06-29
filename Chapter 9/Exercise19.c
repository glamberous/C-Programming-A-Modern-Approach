/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


void pb(int n)
{
	if (n != 0)
	{
		pb(n / 2);
		putchar('0' + n % 2);
	}
}

int main(void)
{	
	int x = 0;
	
	printf("Lets give a number to function \"pb\": ");
	scanf("%d", &x);

	pb(x);
	
	return (0);
}