/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper




int gcd(int m, int n)
{
	short remainder = 0;
	
	while(n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}
	return (m);
}


int main(void)
{	
	int x = 0, y = 0;
	
	printf("Enter in x and y: ");
	scanf("%d %d", &x, &y);
	printf("Greatest common denominator is: %d", gcd(x, y));
	
	return (0);
}