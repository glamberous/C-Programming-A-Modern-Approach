#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define ARRAY_SIZE 10


void find_two_largest(int a[], int n, int *largest, int *second_largest);


int main(void)
{
	int a[ARRAY_SIZE] = {0};
	int i, large, kinda_large;
	
	printf("Please enter in %d numbers: ", ARRAY_SIZE);
	
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &a[i]);
	}

	find_two_largest(a, ARRAY_SIZE, &large, &kinda_large);
	
	printf("Largest: %d\tSecond Largest: %d", large, kinda_large);

}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	int i;
	
	*largest = 0;
	*second_largest = 0;
	
	for(i = 0; i < n; i++)
	{
		if (a[i] > *largest)
		{
			*second_largest = *largest;
			*largest = a[i];
		}
		else if (a[i] > *second_largest)
		{
			*second_largest = a[i];
		}
	}
}

