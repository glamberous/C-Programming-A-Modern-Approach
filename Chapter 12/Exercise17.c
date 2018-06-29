/* Search through an array for a specific temperature */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time

#define WIDTH 5
#define HEIGHT 2

int find_sum (int[0], int);

int main (void)
{
	int aLength;
	int a[HEIGHT][WIDTH] = {{2, 2, 2, 2, 2},
							{2, 2, 2, 2, 2}};
						
	aLength = HEIGHT * WIDTH;
					
	printf("The sum is %d", find_sum(a[0], aLength));

}

int find_sum (int a[0], int n)
{
	int *p, sum = 0;
	
	for(p = a; p < a + n; p++)
	{
		sum += *p;
	}
	return sum;
}