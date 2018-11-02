/* Formats a file of text */

/*
Modify the justify program of Section 15.3 so that it reads from one test file
and writes to another. Have the program obtain the names of both files from the
command line.
*/

#include <stdio.h>
#include <string.h>
#include "line.h"
#include "Word.h"
#include <stdlib.h>

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
  char word[MAX_WORD_LEN+2];
  int word_len;

  FILE *input = NULL, *output = NULL;
	if ((input = fopen(argv[1], "rb")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

	if ((output = fopen(argv[2], "wb")) == NULL) {
    printf("%s can't be opened\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  clear_line();
  for (;;)
  {
    read_word(word, MAX_WORD_LEN+1, input);
    word_len = strlen(word);
    if (word_len == 0)
    {
      flush_line(output);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
    {
      word[MAX_WORD_LEN] = '*';
    }
    if ((word_len + 1) > space_remaining())
    {
      write_line(output);
      clear_line();
    }
    add_word(word);
  }
}
