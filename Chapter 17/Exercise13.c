#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
}

int main (void)
{

	return 0;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
	struct node *cur = list, *prev = NULL;
	while (cur->value <= new_node->value)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new_node;
	new_node->next = cur;
	return list;
}

/* 	1. If new_node is to go at the end of the list the function will go into an infinite loop
 		1 fix. add in && cur-> value != NULL
		*/
