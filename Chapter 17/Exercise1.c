#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define GENERIC_MALLOC(type)							\
type * type##_malloc(int n)								\
{																					\
	type *p;																\
	p = malloc(n * (sizeof( type )) + 1);		\
	if (p != NULL) return p;								\
	else { 																	\
		printf("Allocation failed; take appropriate action.\n");\
		exit(0); 															\
	}																				\
}

GENERIC_MALLOC(long);

int main (void)
{
	long n = 0, i = 0, *p = 0;
	printf("Enter the length of an array you would like: ");
	scanf("%lu", &n);

	while(1)
	{
	p = long_malloc(n);
	}

	printf("Enter numbers to fill out your array: ");
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &p[i]);
	}
	printf("Here's your full array printed out: ");
	for (i = 0; i < n; i++)
	{
		printf("%ld ", p[i]);
	}
	putchar('\n');
	return 0;
}
