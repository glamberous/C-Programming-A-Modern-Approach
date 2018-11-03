/*
(a) Write a program that converts a Windows text file to a UNIX text file. (See
Section 22.1 for a discussion of the differences between Windows and UNIX text
files.)

(b) Write a program that converts a UNIX text file to a Windows text file.

In each case, have the program obtain the names of both files from the command
line. Hint: Open the input file in "rb" mode and the output file in "wb" mode.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	int ch = 0;

	while((ch = fgetc(source_fp)) != EOF)
	{
		if(ch != '\r')
			fputc(ch, dest_fp);
	}

	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}
