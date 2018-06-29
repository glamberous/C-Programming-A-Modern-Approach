#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

int main (void)
{
	int i;
	bool weekend[7] = {true, [6] = true};
	
	for (i = 0; i < 7; i++)
		printf("%d ", weekend[i]);
	
return (0);
}