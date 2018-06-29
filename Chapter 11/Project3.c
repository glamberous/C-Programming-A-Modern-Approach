/* reduces a fraction to its lowest terms*/
#include <stdio.h>


void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);


int main(void)
{

int numerator = 0, denominator = 0;

printf("Enter a fraction to reduce: ");
scanf("%d/%d", &numerator, &denominator);

reduce(numerator, denominator, &numerator, &denominator);

printf("Your fraction after being reduced is: %d/%d", numerator, denominator);	
	
return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int remainder = 0;
	
	while (numerator > 0)
	{
		remainder = denominator % numerator;
		denominator = numerator;
		numerator = remainder;
	} 
	
	*reduced_denominator /= denominator;
	*reduced_numerator /= denominator;
}