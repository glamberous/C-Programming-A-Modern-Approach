#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

int main(void)
{
	int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
	int *p = &a[1], *q = &a[5];
	
	printf("a. %d\n", *(p+3));
	printf("b. %d\n", *(q-3));
	printf("c. %d\n", (q - p));
	printf("d. ");
	
	if (p < q)
		printf("True\n");
	else
		printf("False\n");
	
	printf("e. ");
	if (*p < *q)
		printf("True\n");
	else
		printf("False\n");
	
	
	printf("My answers were:\na. 14\nb. 34\nc. Undefined\nd. True\ne. False");
}

