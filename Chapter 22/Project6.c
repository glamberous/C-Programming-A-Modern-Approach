/*
Write a program that displays the contents of a file as bytes and as characters.
Have the user specify the file name on the command line. Here's what the output
will look like when the program is used to diplsay the pun.c file of Section 2.1:

Each line shows 10 bytes from the file, as hexadecimal numbers and as characters.
The number in the Offset column indicates the position within the file of the
first byte on the line. Only printing characters (as determined by the isprint
function) are displayed; other characters are shown as periods. Note that the
appearance of a text file may vary, depending on the character set and the
operating system. The example above assumes that punc is a Windows file, so 0D
and 0A bytes (the ASCII carriage-return and line-feed characters) appear at the
end of each line. Hint: Be sure to open the file in "rb" mode.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_line(int *ch);

int main(int argc, char *argv[])
{
  FILE *fp;

  if ((fp = fopen(argv[1], "rb")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Offset\t            Bytes            \tCharacters\n"
         "------\t-----------------------------\t----------\n");

  int i = 0, ch[10] = {0};

  while((ch[i] = fgetc(fp)) != EOF)
  {
    i++;
    if(i == 10)
    {
      print_line(ch);
      i = 0;
    }
  }

  while(i < 10)
    ch[i++] = '\0';
  print_line(ch);

  fclose(fp);
  return 0;
}

void print_line(int *ch)
{
  int *chp = ch;
  static int offset = 0;

  printf("%6d\t", offset);
  for(chp = ch; chp < ch + (sizeof(char) * 10); chp++)
    printf("%02X ", *chp);
  putchar('\t');
  for(chp = ch; chp < ch + (sizeof(char) * 10); chp++)
    printf("%c", isprint(*chp) ? *chp : '.');
  putchar('\n');

  offset += 10;
}
