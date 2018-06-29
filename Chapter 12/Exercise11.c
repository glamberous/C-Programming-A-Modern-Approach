#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator


int main (void)
{
	
	
	
	
}



int *find_largest(int a[], int n)
{
	int *p, *largest;
	
	largest = a;
	for(p = (a + 1); p < a + n; p++)
	{
		if (*p > *largest)
		{
			largest = p;
		}
	}
	return largest;
}

