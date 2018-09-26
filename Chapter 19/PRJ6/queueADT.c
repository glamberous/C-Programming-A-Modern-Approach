//file name would be queue.c not Exercise3.c

#include "queueADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct node
{
  struct node *next;
  Item item_name[1];
};

struct queue_type
{
  struct node *top;
};

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    /*intentionally null*/;
  while (ch != '\n' && ch != EOF)
  {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';

  return i;
}

Queue create(void)
{
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL)
    terminate("Failed to find space for new Queue");

  q->top = NULL;
  return q;
}

void destroy(Queue q)
{
  make_empty(q);
  free(q);
}

void terminate(char *str)
{
  puts(str);
  exit(EXIT_FAILURE);
}

//Inserting an item at the end of the queue
void enter_queue(Queue q)
{
  if (is_full(q))
    terminate("Too many items in the queue.\n");

  Item temp[MAX_LEN];
  printf("Enter a phrase into the queue: ");
  struct node *new_node = malloc(sizeof(struct node) + read_line(temp, MAX_LEN) + 1);
  if(new_node == NULL)
    terminate("Not enough space to create new node.\n");
  strcpy(new_node->item_name, temp);
  new_node->next = q->top;
  q->top = new_node;
}

//Removing an item from the beginning of the queue
Item *exit_queue(Queue q)
{
  if (is_empty(q))
    terminate("No more items in queue.\n");

  struct node *cur_node = q->top, *prev_node = NULL;

  while(cur_node->next != NULL)
  {
    prev_node = cur_node;
    cur_node = cur_node->next;
  }

  Item *temp = cur_node->item_name;
  free(cur_node);
  if(prev_node != NULL)
    prev_node->next = NULL;
  else
    q->top = NULL;

  return temp;
}

//Returning the first item in the queue (without changing the queue)
Item *is_first(Queue q) //
{
  if(is_empty(q))
    return "ERR QUEUE EMPTY.\n";

  struct node *temp = q->top;
  while(temp->next != NULL)
    temp = temp->next;
  Item *temp_item = temp->item_name;
  return temp_item;
}

//Returning the last item to the queue (without changing the queue)
Item *is_last(Queue q) //
{
  if(is_empty(q))
    return "ERR QUEUE EMPTY.\n";

  Item *item = q->top->item_name;
  return item;
}

void make_empty(Queue q)
{
  while (!is_empty(q))
    exit_queue(q);
}

//Testing whether the queue is empty
bool is_empty(Queue q) //
{
  return (q->top == NULL);
}

bool is_full(Queue q) //
{
  return false;
}

Queue change_queue(Queue cur_q, Queue q1, Queue q2)
{
  return cur_q == q1 ? q2 : q1;
}
