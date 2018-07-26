/* Suppose we want a macro that expands into a string containing the current line
number and file name. In other words, we'd like to write
const char *str = LINE_FILE;
and have it expand into
const char *str = "Line 10 of file foo.c";
where foo.c is the file containing the program and 10 is the line on which the
invocation of LINE_FILE appears.
*/

#include <string.h>
#include <stdio.h>

#define xSTRINGIZE(x) #x
// Converts int to string

#define STRINGIZE(x) xSTRINGIZE(x)
// Converts __LINE__ to INT, without this it'd just stringize "__LINE__"

#define LINE_FILE "Line "STRINGIZE(__LINE__)" of file "__FILE__

int main (void)
{
	const char *str = LINE_FILE;

	puts(str);
}
