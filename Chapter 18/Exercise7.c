/* Suppose that we declare x to be a const object. Which one of the following
statements about x is false?

(a) If x is of type int, it can be used as the value of a case label in a switch statement.
(b) The compiler will check that no assignment is made to x.
(c) x is subject to the same scope rules as variables.
(d) x can be of any type.

a is false. WRONG - see below
*/

#include <stdio.h>

int main(void)
{
	const int i; // Turns out a is true and b is false.
	int input = 0;

	printf("Enter input: ");
	scanf("%d", &input);

	switch(input)
	{
		case 1: printf("Koda\n"); break;
		case i: printf("Gizmo\n"); break;
		default: printf("No cats\n"); break;
	}
}
