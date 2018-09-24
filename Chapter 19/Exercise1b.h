//file name would be queue.h not Exercise1.h
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_ARRAY 5

typedef int Item;

struct node {
  Item item;
  struct node *next;
};

#include <stdbool.h>

void terminate(char *str);

//Inserting an item at the end of the queue
void enter_queue(void);

//Removing an item from the beginning of the queue
Item exit_queue(void);

//Returning the first item in the queue (without changing the queue)
Item is_first(void);

//Returning the last item to the queue (without changing the queue)
Item is_last(void);

//Testing whether the queue is empty
bool is_empty(void);

bool is_full(void);

#endif
