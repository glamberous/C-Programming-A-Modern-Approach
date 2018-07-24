/* For each of the following macros, give an example that illustrates
a problem with the macro and show how to fix it. */




#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main (void)
{
	//Example of AVG not functioning as intended
	#define AVG(x,y) (x+y)/2
	printf("a1: %d\n", 40%AVG(12,24));
	//How to fix it:
	#define AVG(x,y) (((x)+(y))/2)
	printf("a2: %d\n", 40%AVG(12,24));

	//Example of AREA not functioning as intended
	#define AREA(x,y) (x)*(y)
	printf("b1: %dsqft.\n", 6%AREA(11,8));
	//How to fix it:
	#define AREA(x,y) ((x)*(y))
	printf("b2: %dsqft.\n", 6%AREA(11,8));

}
