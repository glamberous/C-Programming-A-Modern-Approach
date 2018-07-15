/* Write a program named sum.c that adds up its command-line argument from
string form to integer form. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 100

int main(int argc, char *argv[])
{
	int i, sum = 0;

	for(i = 0; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}

	printf("%d", sum);

	return 0;
}
