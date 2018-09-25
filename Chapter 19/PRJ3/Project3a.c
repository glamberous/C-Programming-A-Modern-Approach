#include <stdio.h>
#include <stdlib.h>
#include "Project3.h"

struct node
{
	Item data;
	int len;
	struct node *next;
};

struct stack_type
{
	struct node *top;
};

static void terminate (const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("Error in create: stack could not be created.");
	s->top = NULL;
	return s;
}

void destroy(Stack s)
{
	make_empty(s);
	free(s);
}

void make_empty(Stack s)
{
	while (!is_empty(s))
		pop(s);
}

bool is_empty(Stack s)
{
	return s->top == NULL;
}

bool is_full(Stack s)
{
	return false;
}

void push(Stack s)
{
	Item i = 0;
	printf("Please enter in a number: ");
	scanf("%d", &i);

	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = i;
	if(s->top == NULL)
		new_node->len = 1;
	else
		new_node->len = (s->top->len + 1);

	new_node->next = s->top;
	s->top = new_node;
}

Item pop(Stack s)
{
	struct node *old_top;
	Item i;

	if(is_empty(s))
		terminate("Error in pop: stack is empty.");

	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);
	//printf("len: %d\n", s->top->len);
	return i;
}

int length(Stack s)
{
	if(s->top == NULL)
		return 0;
	else
	{
		struct node *temp;
		temp = s->top;
		return temp->len;
	}
}

Stack change_stack(Stack cur_s, Stack s1, Stack s2)
{
  return cur_s == s1 ? s2 : s1;
}
