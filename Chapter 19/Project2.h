/* Modify Programming Project 6 from Chapter 10 so that it uses the stack ADT
described in Section 19.4. You may use any of the implementations of the ADT
described in that section. */

#ifndef PROJECT1_H
#define PROJECT1_H

typedef struct stack_type *Stack;

Stack create(void);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(int num, Stack s);
int pop(Stack s);
void stack_overflow(void);
void stack_underflow(void);

#endif
