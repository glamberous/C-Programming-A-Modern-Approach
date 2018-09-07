#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int * create_array(int n, int initial_value);

int main (void)
{
	int n = 0, i = 0, *p;

	printf("Enter how long you want the array to be: ");
	scanf("%d", &n);
	p = create_array(n, 40);

	for(i = 0; i < n; i++)
		printf("%d ", p[i]);

	return 0;
}

int * create_array(int n, int initial_value)
{
	int i, *p;
	p = malloc(n * (sizeof(int)));

if (p != NULL)
	{
		for(i = 0; i < n; i++)
			p[i] = initial_value;
		return p;
	}
else
	{
		printf("Allocation failed; take appropriate action.\n");
		exit(0);
	}
}
