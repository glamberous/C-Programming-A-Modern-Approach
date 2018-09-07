#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

void delete_from_list(struct node **list, int n);

int main (void)
{
  struct node *p, *begin = NULL;
	int i = 0, value = 5;

	for(i = 0; i < 6; i++)
	{
		p = malloc(sizeof(struct node));
		p->value = value++;
		p->next = begin;
		begin = p;
	}

  /* print node list */
  printf("\n");
  for (p = begin; p != NULL; p = p->next)
    printf("%d%s", p->value, p->next != NULL ? ", " : "");
  printf("\n");

  /* delete item from list */
  delete_from_list(&begin, 5);

  /* print node list again */
  for (p = begin; p != NULL; p = p->next)
    printf("%d%s", p->value, p->next != NULL ? ", " : "");
  printf("\n\n");

  return 0;
}

void delete_from_list(struct node **list, int n)
{
	struct node *cur = *list, *prev = NULL;

	while(cur != NULL && cur->value != n)
	{
		prev = cur;
		cur = cur->next;
	}
	if(cur == NULL)
	;
	if(prev == NULL)
		*list = (*list)->next;
	else
		prev->next = cur->next;
	free(cur);
}
