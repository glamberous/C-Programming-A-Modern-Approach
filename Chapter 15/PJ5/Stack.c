
#include <stdio.h>			//printf / scanf
#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return (top == 0);
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int num)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = num;
}

int pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Expression is too complex");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression");
	exit(EXIT_SUCCESS);
}
