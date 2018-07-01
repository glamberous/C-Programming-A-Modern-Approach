/* Sorts an array of integers using Quicksort algorithm */
/* Also Testing Github */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define N 5

void max_min(int a[], int n, int *max, int *min);

int main (void)
{
	int b[N], *p, big = 0, small = 0;
	
	printf("Enter %d numbers: ", N);
	for (p = b; p < b+N; p++)
		scanf("%d", p);
	
	max_min(b, N, &big, &small);
	
	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);
	
	return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
	int *p = a;
	
	*max = *min = *p;
	
	for (p = a+1; p < a+n; p++)
	{
		if (*p > *max)
			*max = *p;
		else if (*p < *min)
			*min = *p;
	}
}