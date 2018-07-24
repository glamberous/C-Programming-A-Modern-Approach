/*
Suppose we want a macro that expands into a string containing the current line number
and file name. In other words, we'd like to write
const char *str = LINE_FILE;
and have it expand into
const char *str = "Line 10 of file foo.c";
Where foo.c is the file containing the program and 10 is the line on which the invocation
of LINE_FILE appears.
*/

#include <string.h>
#include <stdio.h>

#define GENERIC_MAX(type)					\
type type##_max(type x, type y)		\
{																	\
	return x > y ? x : y;						\
}

GENERIC_MAX(int)

int main (void)
{
	int x = 100, y = 300;

	printf("%d", int_max(x,y));

	return 0;
}
