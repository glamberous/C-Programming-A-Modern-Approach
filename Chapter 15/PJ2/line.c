

#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0)
  {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, i, j;
  short spaces_to_insert[(num_words - 1)];

  for(i = 0; i < num_words - 1; i++)
  {
    spaces_to_insert[i] = 1;
  }

  extra_spaces = space_remaining();
  while(extra_spaces > 0)
  {
    for(i = 0, j = num_words - 2; i <= j;)
    {
      spaces_to_insert[i++]++;

      if(--extra_spaces == 0)
        break;

      if(i <= j)
      {
        spaces_to_insert[j--]++;
      }

      if(--extra_spaces == 0)
        break;
    }
  }

  for (i = 0, j = 0; i < line_len; i++)
  {
    if (line[i] != ' ')
    {
      putchar(line[i]);
    }
    else
    {
      while(spaces_to_insert[j] > 0)
      {
        putchar(' ');
        spaces_to_insert[j]--;
      }
      j++;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  if(line_len > 0)
  {
    puts(line);
  }
  return;
}
