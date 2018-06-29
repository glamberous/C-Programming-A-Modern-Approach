/* creates a "magic square" */
#include <stdio.h>		// for typef & scanf


int polynomial(int n);

int main(void)
{	
	int n = 0;
	
	printf("This program runs the following polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\n");
	printf("Enter what number you would like to be x: ");
	scanf("%d", &n);													//stores a number, used for the size of the array
	
	printf("Answer to the equation: %d", polynomial(n));

}
	
int polynomial(int n)	
{
	return (3*(n * n * n * n * n) + 2*(n * n * n * n) - 5*(n * n * n) - (n * n) + 7*n - 6);
}