/*
Of the many techniques for compressing the contents of a file, one of the simplest
and fastest is known as run-length encoding. This technique compresses a file by
replacing sequences of identical bytes by a pair of bytes: a repetition count
followed by a byte to be repeated. For example, suppose that the file to be
compressed begins with the following sequence of bytes (shown in hexadecimal):
46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20
The compressed file will contain the following bytes:
01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20
Run-length encoding works well if the original file contains many long sequences
of identical bytes. In the worst case (a file with no repeated bytes). run-length
encoding can actually double the length of the file.

(a) Write a program named compress_file that uses run-length encoding to compress
a file. To run compress_file, we'd use a command of the form
compress_file original-file
compress_file will write the compressed version of original-file to original-file.rle.
For example, the command
compress_file foo.txt
will cause compress_file to write a compressed version of foo.txt to a file named
foo.txt.rle. Hint: the program described in Programming Project 6 could be useful
for debugging.

(b) Write a program named uncompress_file that reverses the compression performed
by the compress_file program. The uncompress_file command will have the form
uncompress_file compressed-file
compressed-file should have the extension .rle. For example, the command
uncompress_file foo.txt.rle
will cause uncompress_file to open the file foo.txt.rle and write an uncompressed
version of its contents to foo.txt. uncompress_file should display an error
massage if its command-line argument doesn't end with the .rle extension.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_line(int *ch);

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;

  if ((fp1 = fopen(argv[1], "rb")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char *filename = argv[1];
  filename[(strlen(filename) - 4)] = '\0';

  if ((fp2 = fopen(filename, "wb")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  unsigned int ch = 0, seq_bytes = 0;

  for(seq_bytes = fgetc(fp1); ch != EOF && seq_bytes != EOF; seq_bytes = fgetc(fp1))
    for (ch = fgetc(fp1); seq_bytes > 0; seq_bytes--)
      fputc(ch, fp2);

  fclose(fp1);
  fclose(fp2);
  return 0;
}
