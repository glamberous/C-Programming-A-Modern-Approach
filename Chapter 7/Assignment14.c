/* Uses Newton's method to compute the square root of a positive floating-point number */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <math.h>  		// for fabs

int main(void)
{	
	double x = 0, y = 1, xy = 0, average = 1;

	printf("Enter a positive number: ");
	scanf("%lf", &x);
	
	while ((y - average) >= .00001 || (y - average) <= 0)
	{
	    y = average;
		
		xy = x/y;
		average = (y + xy) / 2;
		
		average = fabs (average);
		y = fabs (y);
		
	}
	
	printf("Square root: %lf", average);
	
	return (0);
}