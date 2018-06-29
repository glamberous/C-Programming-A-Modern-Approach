#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator




void swap(int *p, int *q);


int main(void)
{
	int x, y;
	
	printf("Please enter two numbers (x then y): ");
	scanf("%d", &x);
	scanf("%d", &y);
	
	swap(&x, &y);
	
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}

void swap(int *p, int *q)
{
	int temp = 0;
	
	temp = *p;
	*p = *q;
	*q = temp;
	
}

