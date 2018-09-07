#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct point {int x, y; };
struct rectangle {struct point upper_left, lower_right; };

int main (void)
{
	struct rectangle *p;

	p = malloc(sizeof(struct rectangle));
	p->upper_left.x = 10; p->upper_left.y = 25;
	p->lower_right.x = 20; p->lower_right.y = 15;

	printf("upper_left x: %d\n", p->upper_left.x);

	return 0;
}
