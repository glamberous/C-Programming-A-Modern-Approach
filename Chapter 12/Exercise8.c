#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

void store_zeros(int a[], int n)
{
	int *p;
	
	for (p = a; p < a + n; p++)
		*p = 0;
}

