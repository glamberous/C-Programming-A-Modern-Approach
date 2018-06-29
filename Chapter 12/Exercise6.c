#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

int sum_array(const int a[], int n)
{
	int *p, sum;
	sum = 0;
	for (p = a; p < a + n; p++)
		sum += *p;
	return sum;
}

