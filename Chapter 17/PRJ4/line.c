

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
	struct node *next;
  char word_str[];
} *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  struct node *temp;

  while(line != NULL)
  {
    temp = line;
    line = line->next;
    free(temp);
  }
  line_len = 0;
  num_words = 0;
}

void add_word(const char *arg_word)
{
  int word_mem = strlen(arg_word) + 1;

  struct node *new_word;
  new_word = malloc(sizeof(struct node) + word_mem);
  if (new_word == NULL)
  {
    printf("new_word malloc allocation failed.");
    exit(0);
  }
  strcpy(new_word->word_str, arg_word);
  new_word->next = NULL;

  if (line == NULL)
  {
    line = new_word;
  }
  else
  {
    struct node *cur;
    for(cur = line; cur->next != NULL; cur = cur->next)
    /* intentionally null */;
    cur->next = new_word;
  }
  line_len += strlen(new_word->word_str);
  if(num_words > 0)
    line_len++;
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
  /* num_words - 1 accounts for spaces */
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, j;
  struct node *cur = line;

  extra_spaces = space_remaining();

  while(cur != NULL)
  {
    printf("%s", cur->word_str);
    if(num_words > 1)
    {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
    }
    num_words--;
    cur = cur->next;
  }
  putchar('\n');
}

void flush_line(void)
{
  if(line != NULL)
  {
    struct node *cur;
    for(cur = line; cur != NULL; cur = cur->next)
    {
      printf("%s", cur->word_str);
      if(cur->next != NULL)
        putchar(' ');
    }
    putchar('\n');
  }
  return;
}
