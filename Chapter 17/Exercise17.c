
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main(void)
{
	int array[100];
	qsort(&array[50], 50, sizeof(array[0]), cmpfunc);

	return 0;
}
