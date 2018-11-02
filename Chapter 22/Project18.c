/*
Write a program that reads integers from a text file whose name is given as a
command-line argument. Each line of the file may contain any number of integers
(including none) separated by one or more spaces. Have the program display the
largest number in the file, the smallest number, and the median (the number
closest to the middle if the integers were sorted). If the file contains an even
number of integers, there will be two numbers in the middle; the program should
display their average (rounded down). You may assume that the file contains no
more than 10,000 integers. Hint: Store the integers in an array and then sort
the array.
*/

#define MAX_NUMBERS 10000
#define LINE_LEN 100

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int cmpfunc(const void *, const void *);

int main(int argc, char *argv[])
{
	FILE *source_fp;

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}


	int ch = 0, num_count = 0, numbers[MAX_NUMBERS] = {0};

	while((ch = fgetc(source_fp)) != EOF)
	{
		if((isdigit(ch)) == 1)
			ungetc(ch, source_fp);

		char line[LINE_LEN+1] = "";
		line[0] = ' ';
		fgets((line + 1), LINE_LEN, source_fp);
		if (sscanf(line, "%*[^0123456789]%d", &numbers[num_count]) == 1)
			num_count++;
	}

	qsort(numbers, num_count, sizeof(int), cmpfunc);

	printf("Smallest number: %d\nBiggest number: %d\n", numbers[0], numbers[num_count-1]);
	if((num_count % 2) == 0)
	{
		int median = 0;
		median = ((numbers[(num_count-1) / 2] + numbers[((num_count-1) / 2) + 1]) / 2);
		printf("Median number 1: %d\n", median);
	}
	else
		printf("Median number 2: %d\n", numbers[(num_count-1) / 2]);

	fclose(source_fp);
	return 0;
}

int cmpfunc (const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b );
}
