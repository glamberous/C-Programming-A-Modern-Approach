/* Write a program that reverses the user's input */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 100

int main(int argc, char *argv[])
{
	int i = argc;

	while(i-- > 1)
	{
		printf("%s ", argv[i]);
	}

	return 0;
}
