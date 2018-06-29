#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define N 10

int main(void)
{
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = &a[0], *q = &a[N-1], temp;
	
	while (p < q) {
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}
	
	
	printf("What I think the answer is: ");
	printf("10 9 8 7 6 5 4 3 2 1\n");
	
	for (temp = 0; temp < N; temp++)
	{
		printf("%d ", *(a+temp));
	}

	
}

