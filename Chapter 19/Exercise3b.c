//file name would be queueb.c not Exercise3b.c

#include "Exercise1b.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

static struct node *first = NULL, *last = NULL;

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
      default: printf("Command not recognized. Try again.\n");
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

  struct node *new_node = malloc(sizeof(struct node));
  if(new_node == NULL)
    terminate("new_node could not allocate space.");

  if(last != NULL)
    last->next = new_node;

  printf("Enter a number to enter into the queue: ");
  scanf("%d", &new_node->item);
  new_node->next = NULL;

  if(is_empty())
    first = new_node;
  last = new_node;
}

//Removing an item from the beginning of the queue
Item exit_queue(void)
{
  if (is_empty())
    terminate("No more items in queue.");

  Item temp_item = first->item;
  struct node *temp_node = first;
  first = first->next;
  free(temp_node);
  temp_node = NULL;

  return temp_item;
}

//Returning the first item in the queue (without changing the queue)
Item is_first(void)
{
  return first->item;
}

//Returning the last item to the queue (without changing the queue)
Item is_last(void)
{
  return last->item;
}

//Testing whether the queue is empty
bool is_empty(void)
{
  return (first == NULL);
}

bool is_full(void)
{
  return 0;
}
