#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator


int main (void)
{
	
	
	
	
}



double inner_product (const double *a, const double *b, int n)
{
	double *p, sum;
	
	while (a < a + n)
	{
		sum += (*a * *b);
		a++;
		b++;
	}
	return sum;
}

