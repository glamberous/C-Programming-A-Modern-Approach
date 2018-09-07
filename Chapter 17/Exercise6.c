#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	for(cur = list, prev = NULL;
		cur != NULL && cur ->value != n;
		prev = cur, cur = cur->next)
		/*intentionally null*/;

		for(cur = list;
		cur->next != NULL && cur->next->value != n;
		cur = cur->next)
		/*intentionally null*/;

	return 0;
}
