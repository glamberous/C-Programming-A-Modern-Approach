/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  char *word_list[MAX_WORDS];
  char input[MSG_LEN + 1];
  int i, num_words = 0;

  while(1)
  {
    if(num_words == MAX_WORDS)
    {
      printf("No more space left for words.");
      break;
    }

    printf("Enter word: ");
    read_line(input, MSG_LEN);

    if(input[0] == '\0')
      break;

    for(i = 0; i < num_words; i++)
      if(strcmp(input, word_list[i]) < 0)
        break;

    int j;
    for(j = num_words; j > i; j--)
      word_list[j] = word_list[j-1];

    word_list[i] = malloc(strlen(input) + 1);
    strcpy(word_list[i], input);

    if (word_list[i] == NULL)
    {
      printf("Not enough space for word_list mem allocation.");
      exit(0);
    }
    num_words++;
  }

  printf("In sorted order: ");
  for(i = 0; i < num_words; i++)
    printf("%s ", word_list[i]);

  putchar('\n');

  return 0;
}

int read_line (char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
