/* copyies a file */

/*
Modify the fcopy.c program of Section 22.4 so that is uses fread and fwrite to
copy the file in blocks of 512 bytes. (The last block may contain fewer than 512
bytes, of course.)
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;

	if(argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	char bytes[512] = {0};
	int num_copied = 1;
	while(num_copied != 0)
	{
		num_copied = fread(bytes, 1, 512, source_fp);
		fwrite(bytes, 1, num_copied, dest_fp);
	}

	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}
