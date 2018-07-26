/*
Suppose that a program needs to display messages in either English, French, or Spanish.
Using conditional compilation, write a program fragment that displays one of the following
three messages, depending on whether or not the specified macro is defined
*/

#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main (void)
{

	IDENT(foo)
// After macro expansion it'll look like:
// ident "foo"


	return 0;
}
