/* (a) Write an implementation of the Stack type, assuming that Stack is a structure
containing a fixed-length array.

(b) Redo the Stack type, this time using a linked-list representation instead of an
array. (Show both stack.h and stack.c) */

//file name would be queue.c not Exercise3.c

#include "Exercise4a.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct stack_type {
  Item item_list[MAX_ARRAY];
  int last;
  int num_items;
  int first;
};

int main (void)
{
  Stack s1, s2, cur_stack;
  s1 = create();
  s2 = create();
  cur_stack = s1;

  char command = '\0';

  printf("Valid Commands\nS = Enter Queue\nE = Exit Queue\n");
  printf("F = First in line\nL = Last in line\nC = Change Stacks\nQ = Quit\n");
  while(1)
  {
    printf("Enter a Command: ");
    scanf("%c", &command);
    command = toupper(command);
    switch(command)
    {
      case 'Q': terminate(""); break;
      case 'S': enter_queue(cur_stack); break;
      case 'E': printf("Item was: %d\n", exit_queue(cur_stack)); break;
      case 'F': printf("First Item is: %d\n", is_first(cur_stack)); break;
      case 'L': printf("Last Item is: %d\n", is_last(cur_stack)); break;
      case 'C': cur_stack = change_stack(cur_stack, s1, s2); break;
      default: printf("Command not recognized. Try again.");
    }
    while(getchar() != '\n');
  }
}

Stack create(void)
{
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->first = 0;
  s->num_items = 0;
  s->last = 0;
  s->item_list[0] = 0;
  return s;
}

void destroy(Stack s)
{
  free(s);
}

void terminate(char *str)
{
  puts(str);
  exit(EXIT_FAILURE);
}

//Inserting an item at the end of the queue
void enter_queue(Stack s)
{
  if (is_full(s))
    terminate("Too many items in the queue.");
  s->num_items++;

  Item temp = 0;
  printf("Enter a number to enter into the queue: ");
  scanf("%d", &temp);
  s->item_list[s->last % MAX_ARRAY] = temp;
  s->last++;
}

//Removing an item from the beginning of the queue
Item exit_queue(Stack s)
{
  if (is_empty(s))
    terminate("No more items in queue.");
  s->num_items--;
  return s->item_list[s->first++ % MAX_ARRAY];
}

//Returning the first item in the queue (without changing the queue)
Item is_first(Stack s)
{
  return s->item_list[s->first % MAX_ARRAY];
}

//Returning the last item to the queue (without changing the queue)
Item is_last(Stack s)
{
  return s->item_list[(s->last % MAX_ARRAY) - 1];
}

//Testing whether the queue is empty
bool is_empty(Stack s)
{
  return (s->num_items == 0);
}

bool is_full(Stack s)
{
  return (s->num_items == MAX_ARRAY);
}

Stack change_stack(Stack cur_s, Stack s1, Stack s2)
{
  return cur_s == s1 ? s2 : s1;
}
