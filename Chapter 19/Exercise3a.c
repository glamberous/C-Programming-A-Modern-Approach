//file name would be queue.c not Exercise3.c

#include "Exercise1.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

static int first = 0, num_items = 0, last = 0;
static Item item_list[MAX_ARRAY] = {0};

int main (void)
{
  char command = '\0';

  printf("Valid Commands\nS = Enter Queue\nE = Exit Queue\n");
  printf("F = First in line\nL = Last in line\nQ = Quit\n");
  while(1)
  {
    printf("Enter a Command: ");
    scanf("%c", &command);
    command = toupper(command);
    switch(command)
    {
      case 'S': enter_queue(); break;
      case 'E': printf("Item was: %d\n", exit_queue()); break;
      case 'F': printf("First Item is: %d\n", is_first()); break;
      case 'L': printf("Last Item is: %d\n", is_last()); break;
      case 'Q': terminate(""); break;
      default: printf("Command not recognized. Try again.");
    }
    while(getchar() != '\n');
  }
}

void terminate(char *str)
{
  puts(str);
  exit(EXIT_FAILURE);
}

//Inserting an item at the end of the queue
void enter_queue(void)
{
  if (is_full())
    terminate("Too many items in the queue.");
  num_items++;

  Item temp = 0;
  printf("Enter a number to enter into the queue: ");
  scanf("%d", &temp);
  item_list[last % MAX_ARRAY] = temp;
  last++;
}

//Removing an item from the beginning of the queue
Item exit_queue(void)
{
  if (is_empty())
    terminate("No more items in queue.");
  num_items--;
  return item_list[first++ % MAX_ARRAY];
}

//Returning the first item in the queue (without changing the queue)
Item is_first(void)
{
  return item_list[first % MAX_ARRAY];
}

//Returning the last item to the queue (without changing the queue)
Item is_last(void)
{
  return item_list[(last % MAX_ARRAY) - 1];
}

//Testing whether the queue is empty
bool is_empty(void)
{
  return (num_items == 0);
}

bool is_full(void)
{
  return (num_items == MAX_ARRAY);
}
