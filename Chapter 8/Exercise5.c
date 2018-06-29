#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

#define fibbiLength ((int) (sizeof (fibbi) / sizeof(fibbi[0])))

int main (void)
{
	int fibbi[40] = {0, 1}, i;
	
	printf("%d ", fibbi[0]);
	
	for (i = 1; i < fibbiLength; i++)
	{
		fibbi[i + 1] = fibbi[i] + fibbi[i-1];
		printf("%d ", fibbi[i]);
		if (i % 10 == 0)
			putchar('\n');
	}
	
return (0);
}