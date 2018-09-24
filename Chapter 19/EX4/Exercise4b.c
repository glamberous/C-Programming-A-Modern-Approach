/* (a) Write an implementation of the Stack type, assuming that Stack is a structure
containing a fixed-length array.

(b) Redo the Stack type, this time using a linked-list representation instead of an
array. (Show both stack.h and stack.c) */

//file name would be queue.c not Exercise3.c

#include "Exercise4b.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct node {
  Item item;
  struct node *next;
};

struct stack_type
{
  struct node *top;
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
  s->top = NULL;
  return s;
}

void destroy(Stack s)
{
  make_empty(s);
  free(s);
}

void terminate(char *str)
{
  puts(str);
  exit(EXIT_FAILURE);
}

//Inserting an item at the end of the queue
void enter_queue(Stack s) //Push
{
  if (is_full(s))
    terminate("Too many items in the queue.");

  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Not enough memory to create new_node");

  printf("Enter a number to enter into the queue: ");
  scanf("%d", &new_node->item);

  new_node->next = s->top;
  s->top = new_node;
}

//Removing an item from the beginning of the queue
Item exit_queue(Stack s) //Pop
{
  if (is_empty(s))
    terminate("No items in queue.");

  struct node *pop = s->top, *prev_pop = NULL;
  while(pop->next != NULL)
  {
    prev_pop = pop;
    pop = pop->next;
  }
  if(prev_pop != NULL)
    prev_pop->next = NULL;
  else
    s->top = NULL;

  Item pop_item = pop->item;
  free(pop);
  return pop_item;
}

//Returning the first item in the queue (without changing the queue)
Item is_first(Stack s)
{
  if (is_empty(s))
    terminate("No items in queue.");

  struct node *temp = s->top;
  while(temp->next != NULL)
    temp = temp->next;

  return temp->item;
}

//Returning the last item to the queue (without changing the queue)
Item is_last(Stack s)
{
  if (is_empty(s))
    terminate("No items in queue.");

  return s->top->item;
}

//Testing whether the queue is empty
bool is_empty(Stack s)
{
  return (s->top == NULL);
}

bool is_full(Stack s)
{
  return false;
}

void make_empty(Stack s)
{
  while(!is_empty(s))
    exit_queue(s);
  return;
}

Stack change_stack(Stack cur_s, Stack s1, Stack s2)
{
  return cur_s == s1 ? s2 : s1;
}
