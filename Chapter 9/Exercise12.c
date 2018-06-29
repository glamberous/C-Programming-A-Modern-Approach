/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


double inner_product(double a[], double b[], unsigned short n);

int main(void)
{	
	
	unsigned short n = 0, i = 0;
	
	printf("How long will the arrays be? ");
	scanf("%hud", &n);
	
	double a[n], b[n];
	
	printf("Enter each number for array a: ");
	for(i = 0 ; i < n ; i++)
		scanf("%lf", &a[i]);
	
	printf("Enter each number for array b: ");
	for(i = 0 ; i < n ; i++)
		scanf("%lf", &b[i]);
	
	printf("The total product of the two arrays is: %.2f\n", inner_product(a, b, n));
	
	return (0);
}

double inner_product(double a[], double b[], unsigned short n)
{	
	unsigned short i;
	double sum = 0;
	for(i = 0; i < n; i++)
		sum += (a[i] * b[i]);
	
	return (sum);
}



