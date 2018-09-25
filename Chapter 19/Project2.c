#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include "Project2.h"

#define STACK_SIZE 100

struct stack_type
{
	int *contents;
	int top;
	int size;
};

int main(void)
{
	Stack RPN_s = create();

	char ch = 0;
	int temp1 = 0, temp2 = 0;
	printf("Enter an RPN experession: ");

	do
	{
		scanf(" %c", &ch);

		if (ch >= '0' && ch <= '9')
		{
			ch = ch - '0';
			push((int)ch, RPN_s);
		}
		else if (ch == '+')
		{
			temp1 = pop(RPN_s);
			temp2 = pop(RPN_s);
			temp1 = temp2 + temp1;
			push(temp1, RPN_s);
		}
		else if (ch == '-')
		{
			temp1 = pop(RPN_s);
			temp2 = pop(RPN_s);
			temp1 = temp2 - temp1;
			push(temp1, RPN_s);
		}
		else if (ch == '*')
		{
			temp1 = pop(RPN_s);
			temp2 = pop(RPN_s);
			temp1 = temp2 * temp1;
			push(temp1, RPN_s);
		}
		else if (ch == '/')
		{
			temp1 = pop(RPN_s);
			temp2 = pop(RPN_s);
			temp1 = temp2 / temp1;
			push(temp1, RPN_s);
		}

	} while(ch != '=');

	printf("Value of expression: %d\n", pop(RPN_s));
}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL)
	{
		printf("ERR Memory allocation failed.\n");
		exit(EXIT_SUCCESS);
	}
	s->contents = malloc(sizeof(int) * STACK_SIZE);
	if (s->contents == NULL)
	{
		printf("ERR Memory allocation failed.\n");
		exit(EXIT_SUCCESS);
	}
	s->top = 0;
	s->size = STACK_SIZE;
	return s;
}

void make_empty(Stack s)
{
	s->top = 0;
}

bool is_empty(Stack s)
{
	return (s->top == 0);
}

bool is_full(Stack s)
{
	return s->top == STACK_SIZE;
}

void push(int num, Stack s)
{
	if (is_full(s))
		stack_overflow();
	else
		s->contents[s->top++] = num;
}

int pop(Stack s)
{
	if (is_empty(s))
		stack_underflow();
	else
		return s->contents[--s->top];
	return 0;
}

void stack_overflow(void)
{
	printf("Expression is too complex\n");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
	exit(EXIT_SUCCESS);
}
