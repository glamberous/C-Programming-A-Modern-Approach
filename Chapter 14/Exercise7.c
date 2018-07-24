/*
Let GENERIC_MAX be the following macro:
*/
#include <string.h>
#include <stdio.h>

#define GENERIC_MAX(type)					\
type type##_max(type x, type y)		\
{																	\
	return x > y ? x : y;						\
}

GENERIC_MAX(int)

int main (void)
{
	int x = 100, y = 300;

	printf("%d", int_max(x,y));

	return 0;
}
