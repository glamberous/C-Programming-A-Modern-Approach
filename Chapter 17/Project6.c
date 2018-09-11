/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);
int qsort_cmp (const void *s1, const void *s2);

int main(void)
{
  char *word_list[MAX_WORDS];
  char input[MSG_LEN + 1];
  int num_words = 0;

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

    word_list[num_words] = malloc(strlen(input) + 1);
    if (word_list[num_words] == NULL)
    {
      printf("Not enough space for word_list mem allocation.");
      exit(0);
    }
    strcpy(word_list[num_words], input);

    num_words++;
  }

  qsort(word_list, num_words, sizeof(const char *), qsort_cmp);

  int i;
  printf("In sorted order: ");
  for(i = 0; i < num_words; i++)
    printf("%s ", word_list[i]);

  putchar('\n');

  return 0;
}

int qsort_cmp (const void *s1, const void *s2)
{
  const char *ss1 = *(const char **)s1;
  const char *ss2 = *(const char **)s2;
  return strcmp(ss1, ss2);
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
