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

struct node *find_last(struct node *list, int n)
{
	struct node *temp = NULL;

	while(list->value != NULL)
	{
		if(list->value == n)
			temp = list;
		list = list->next;
	}
	return temp;
}
