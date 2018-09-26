//file name would be queue.h not Exercise1.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_LEN 30

typedef char Item;
typedef struct queue_type *Queue;

#include <stdbool.h>

int read_line(char str[], int n);

Queue create(void);

void destroy(Queue q);

void terminate(char *str);

//Inserting an item at the end of the queue
void enter_queue(Queue);

//Removing an item from the beginning of the queue
Item *exit_queue(Queue);

//Returning the first item in the queue (without changing the queue)
Item *is_first(Queue);

//Returning the last item to the queue (without changing the queue)
Item *is_last(Queue);

//Testing whether the queue is empty
bool is_empty(Queue);

void make_empty(Queue);

bool is_full(Queue);

Queue change_queue(Queue, Queue, Queue);

#endif
