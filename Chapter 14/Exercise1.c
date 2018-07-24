/* Write parameterized macros that compute the following values. */

//a. The cube of x
#define CUBED(x) ((x)*(x)*(x))

//b. The remainder when n is divided by 4.
#define REMAINDER(n) ((n)/(4))

//c. 1 if the product of x and y is less than 100.0 otherwise.
#define PRODUCT(x,y) ((x)*(y)<100?1:(x)*(y))
#define X 5
#define N -8
//#define Y 21

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main (void)
{
	float Y = 21.5;

	printf("x = %d; n = %d; y = %.2f\n", X, N, Y);
	printf("CUBED(x) = %d\n", CUBED(X - N));
	printf("REMAINDER(n) = %d\n", REMAINDER(N));
	printf("PRODUCT(x)(y) = %.2f\n", PRODUCT(X,Y));

}
