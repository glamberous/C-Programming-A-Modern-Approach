/* Let DOUBLE be the following macro: */

#define DOUBLE(x) 2*x

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main (void)
{
	//What is the value of DOUBLE(1+2)?
	printf("(a). %d\n", DOUBLE(1+2));
	//What is the value of 4/DOUBLE(2)?
	printf("(b). %d\n", 4/DOUBLE(2));
	//Fix the definition of DOUBLE.

	#define DOUBLE(x) (2*(x))

	printf("(c1). %d\n", DOUBLE(1+2));
	printf("(c2). %d\n", 4/DOUBLE(2));
}
