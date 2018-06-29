/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int i, j, k;
	// A
	i = 3; j = 4; k = 5;
	printf("The answer was:%d\n", i < j || ++j <k);
	printf("i = %d; j = %d; k = %d\n", i, j, k);
	printf("My guess was 1; i = 3; j = 5; k = 5.\n\n");
	// B
	i = 7; j = 8; k = 9;
	printf("The answer was:%d\n", i - 7 && j++ < k);
	printf("i = %d; j = %d; k = %d\n", i, j, k);
	printf("My guess was 0; i = 7; j = 9; k = 9.\n\n");
	// C
	i = 7; j = 8; k = 9;
	printf("The answer was:%d\n", (i = j) || (j = k));
	printf("i = %d; j = %d; k = %d\n", i, j, k);
	printf("My guess was 1; i = 8; j = 9; k = 9.\n\n");
	// D
	i = 1; j = 1; k = 1;
	printf("The answer was:%d\n", ++i || ++j && ++k);
	printf("i = %d; j = %d; k = %d\n", i, j, k);
	printf("My guess was 1; i = 2; j = 2; k = 2.\n\n");
	
	return 0;
}