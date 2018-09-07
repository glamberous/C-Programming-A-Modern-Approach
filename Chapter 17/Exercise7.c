#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	for (p = first; p != NULL; p = p->next)
		free(p);
	/* problem is that p is freed up before using p->next making it undefined */


	for(cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next)
		free(prev);
	free(cur);
	/* my answer, essentially taking the cur and prev pointers from the previous
	exercise and clearing prev as we move forward. End it with a free(cur) call if
	desired as I can see there be use in keeping the final node as is. */

	struct node *temp;

	p = first;
	while (p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
	/* books answer, this is best for what the assignment actually asked for. Deleting
	all the things.~ */

	return 0;
}
