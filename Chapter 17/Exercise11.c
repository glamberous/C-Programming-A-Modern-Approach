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

int count_occurances(struct node *list, int n)
{
	int counter = 0;

	while(list->value != NULL)
	{
		if(list->value == n)
			counter++;

		list = list->next;
	}
	return counter;
}
