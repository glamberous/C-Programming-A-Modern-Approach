#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>
#include "Project1.h"

#define STACK_SIZE 100

struct stack_type
{
  char contents[STACK_SIZE];
  int top;
};

int main(void)
{
	char temp = 0;
	Stack braces_s = create();

	printf("Enter parentheses and/or braces: ");
	while (temp != '\n')
	{
		temp = getchar();

		if(temp == '(' || temp == '{')
			push(braces_s, temp);
		else if(temp == ')')
		{
			temp = pop(braces_s);
			if (temp != '(')
			{
				terminate("Parentheses/braces are not nested properly.\n");
			}
		}
		else if(temp == '}')
		{
			temp = pop(braces_s);
			if (temp != '{')
			{
				terminate("Parentheses/braces are not nested properly.\n");
			}
		}
	}
	terminate("Parentheses/braces are nested properly.\n");
}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("ERR Memory allocation failed.\n");
	s->top = 0;
	return s;
}

void terminate(const char *str)
{
	puts(str);
	exit(EXIT_SUCCESS);
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

void push(Stack s, char ch)
{
	if (is_full(s))
		stack_overflow();
	else
		s->contents[s->top++] = ch;
}

char pop(Stack s)
{
	if (is_empty(s))
		stack_underflow();
	else
		return s->contents[--s->top];
		
	return '\0';
}

void stack_overflow(void)
{
	printf("Stack overflow. Terminating program.\n");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Parentheses/braces are not nested properly\n");
	exit(EXIT_SUCCESS);
}
