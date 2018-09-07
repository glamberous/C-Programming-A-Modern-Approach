#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct
{
	union
	{
		char a, b;
		int c;
	} d;
	int e[5];
} f, *p = &f;

int main (void)
{
	//p->b = ' '; //not legal, should be p->d.b
	p->d.b = ' ';
	p->e[3] = 10; //legal
	(*p).d.a = '*'; //legal
	//p->d->c = 20; //not legal, should be p->d.c
	p->d.c = 20;

	return 0;
}
