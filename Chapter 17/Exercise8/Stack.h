#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct node {
  int value;
  struct node *next;
}

void make_empty(void);
bool is_empty(void);
bool push(int num);
int pop(void);
void stack_overflow(void)

#endif
