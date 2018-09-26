//file name would be queue.c not Exercise3.c

#include "queueADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct queue_type
{
  Item item_list[MAX_ARRAY];
  int first;
  int last;
  int num_items;
};

Queue create(void)
{
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL)
    terminate("Failed to find space for new Queue");

  q->first = 0;
  q->last = 0;
  q->num_items = 0;
  return q;
}

void destroy(Queue q)
{
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
    terminate("Too many items in the queue.");
  q->num_items++;

  Item temp = 0;
  printf("Enter a number to enter into the queue: ");
  scanf("%d", &temp);
  q->item_list[q->last % MAX_ARRAY] = temp;
  q->last++;
}

//Removing an item from the beginning of the queue
Item exit_queue(Queue q)
{
  if (is_empty(q))
    terminate("No more items in queue.");
  q->num_items--;
  return q->item_list[q->first++ % MAX_ARRAY];
}

//Returning the first item in the queue (without changing the queue)
Item is_first(Queue q) //
{
  return q->item_list[q->first % MAX_ARRAY];
}

//Returning the last item to the queue (without changing the queue)
Item is_last(Queue q) //
{
  return q->item_list[(q->last % MAX_ARRAY) - 1];
}

//Testing whether the queue is empty
bool is_empty(Queue q) //
{
  return (q->num_items == 0);
}

bool is_full(Queue q) //
{
  return (q->num_items == MAX_ARRAY);
}

Queue change_queue(Queue cur_q, Queue q1, Queue q2)
{
  return cur_q == q1 ? q2 : q1;
}
