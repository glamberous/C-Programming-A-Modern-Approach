/*
write a program that reads a series of phone numbers from a file and displays them
in a standard format. Each line of the file will contain a single phone number,
but the numbers may be in a variety of formats. You may assume that each line
contains 10 digits, possibly mixed with other characters (which should be ignored).
For example, suppose that the file contains the followings lines:

404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200

The output of the program should have the following appearance:

(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200

Have the program obtain the file name from the command line.
*/

#define LINE_LEN 50

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct phone_num {
	int area;
	int three_digit;
	int four_digit;
};

int main(int argc, char *argv[])
{
	FILE *source_fp;

	if(argc != 2) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	char line[LINE_LEN+1] = "";
	struct phone_num number;
	int ch = 0;

	while((ch = fgetc(source_fp)) != EOF)
	{
		if((isdigit(ch)) == 1)
			ungetc(ch, source_fp);
		line[0] = ' ';
		fgets((line + 1), LINE_LEN, source_fp);
		sscanf(line, "%*[^0123456789]%3d%*[^0123456789]%3d%*[^0123456789]%4d", &number.area,
			&number.three_digit, &number.four_digit);
		printf("(%d) %d-%d\n", number.area, number.three_digit, number.four_digit);
	}

	fclose(source_fp);
	return 0;
}
