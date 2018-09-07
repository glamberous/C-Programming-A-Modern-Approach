
#include <stdio.h>			//printf / scanf
#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

struct node *first = NULL;

void make_empty(void)
{
	struct node *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->next;
		free(temp);
	}
}

bool is_empty(void)
{
	return (first == NULL);
}

bool push(int num)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if (new_node != NULL)
	{
		new_node->next = first;
		first = new_node;
		first->value = num;
		return true;
	}
	else
		return false;
}

int pop(void)
{
	if (first == NULL)
		stack_underflow();
	else
	{
		int temp = first->value, *temp_p = first;

		first = first->next;
		free(temp_p);
		return temp;
	}
}

void stack_overflow(void)
{
	printf("ERROR: Stack Underflow");
	exit(EXIT_SUCCESS);
}
