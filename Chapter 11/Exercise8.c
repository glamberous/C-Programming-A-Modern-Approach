#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define ARRAY_SIZE 6


int *find_largest(int a[], int n);

int main(void)
{
	int a[ARRAY_SIZE] = {0}, i;
	
	printf("Please enter in %d numbers: ", ARRAY_SIZE);
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("Largest number in the array was: %d", *find_largest(a, ARRAY_SIZE));
}

int *find_largest(int a[], int n)
{
	int *temp = &a[0], i = 0;
	
	for(i = 1; i < n; i++)
	{
		if(*temp < a[i])
		{
			temp = &a[i];
		}
	}
	return temp;
}