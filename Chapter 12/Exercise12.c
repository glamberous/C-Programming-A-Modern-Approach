#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator


void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main (void)
{
	int n = 0, largest = 0, second_largest = 0, *p;
	
	printf("how long should the array be? ");
	scanf("%d", &n);
	
	int a[n];
	
	printf("Enter %d numbers for the array \n", n);
	
	for(p = a; p < a + n; p++)
	{
		scanf("%d", p); 
	}
	find_two_largest(a, n, &largest, &second_largest);
	
	printf("Largest: %d\n", largest);
	printf("Second Largest: %d\n", second_largest);
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
	int *p;
	
/*	if (*a > *(a + 1))
	{
		largest = *a;
		second_largest = *(a + 1);
	}
	else
	{
		largest = *(a + 1);
		second_largest = *a;
	}*/
	
	*largest = 0;
	*second_largest = 0;
	
	for (p = a; p < a + n; p++)
	{
		if (*p > *largest)
		{
			*second_largest = *largest;
			*largest = *p;
		}
		else if (*p > *second_largest)
		{
			*second_largest = *p;
		}
	}
}

