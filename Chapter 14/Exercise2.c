/* Write a macro NELEMS(a) that computes the number of elements in a
one-dimensional array. */

#define NOLEMS(arr) ((int)(sizeof(arr)/sizeof(arr[0])))

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main (void)
{
	char str[15] = "BillyJean";

	printf("str %s is %d characters long\n", str, NOLEMS(str));

}
