//file name would be queue.h not Exercise1.h
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_ARRAY 5

typedef struct stack_type *Stack;
typedef int Item;

#include <stdbool.h>

Stack create(void);

void destroy(Stack s);

void terminate(char *str);

//Inserting an item at the end of the queue
void enter_queue(Stack);

//Removing an item from the beginning of the queue
Item exit_queue(Stack);

//Returning the first item in the queue (without changing the queue)
Item is_first(Stack);

//Returning the last item to the queue (without changing the queue)
Item is_last(Stack);

//Testing whether the queue is empty
bool is_empty(Stack);

bool is_full(Stack);

Stack change_stack(Stack, Stack, Stack);

#endif
