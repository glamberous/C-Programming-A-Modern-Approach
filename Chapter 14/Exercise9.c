/* Write the following parameterized macros
(a) CHECK(x,y,n) Has the value 1 if both x and y fall between 0 and n-1. inclusive.
(b) MEDIAN(x,y,z) Finds the median of x, y, and z.
(c) POLYNOMIAL(x) Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define CHECK(x,y,n) ((x) <= ((n)-1) && 0 <= (x) && (y) <= ((n)-1) && 0 <= (y))
#define MEDIAN(x,y,z) ((x>y)?((x>z)?((z>y)?z:y):x):((y>z)?((z>x)?z:x):y))
#define POLYNOMIAL(x) ((3*((x)*(x)*(x)*(x)*(x))) + (2*((x)*(x)*(x)*(x))) - (5*((x)*(x)*(x))) - ((x)*(x)) + (7*(x)) - 6)
															96							+				32	             -     40            - 4     + 14 - 6
int main (void)
{
	int x = 2, y = 9, n = 1, z = 11;

	printf("CHECK = %d\n", CHECK(x,y,n));
	printf("MEDIAN = %d\n", MEDIAN(x,y,z));
	printf("POLYNOMIAL = %d\n", POLYNOMIAL(x));
}
