/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


unsigned int gcd1(unsigned int m, unsigned int n)
{
	int remainder = 0;
	
	while(n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}
	return (m);
}

unsigned int gcd2(unsigned int m, unsigned int n)    //recursive version of gcd1
{	
	if (n == 0 )
		return (m);
	
	gcd2(n, (m % n));
}


int main(void)
{	
	unsigned int x = 0, y = 0;
	
	printf("Enter in x and y: ");
	scanf("%d %d", &x, &y);
	printf("Greatest common denominator is(with gcd1): %d\n", gcd1(x, y));
	printf("Greatest common denominator is(with gcd2): %d\n", gcd2(x, y));
	
	return (0);
}