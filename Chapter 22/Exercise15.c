
#include <stdio.h>
#include <stdlib.h>

/*
Write calls of fseek that perform the following file-positioning operations
on a binary file whose data is arranged in 64-byte "records." Use fp as the file
pointer in each case.
*/

int main(int argc, char *argv[])
{
// a) Move to the beginning of record n. (assume that the first record in the file is record 0)
  fseek(fp, n * 64L, SEEK_SET);

// b) Move to the beginning of the last record in the file.
  fseek(fp, -64L, SEEK_END);

// c) Move forward one record.
  fseek(fp, 64L, SEEK_CUR);

// d) Move backward two records.
  fseek(fp, -128L, SEEK_CUR);

}
