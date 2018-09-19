/* Write a complete description of the type of x as specified by each of the
following declarations. */

char (*x[10])(int);
/* a)
x is an array
of pointers to
functions with an argument of type int
that returns type char
*/
int (*x(int))[5];
/* b)
x is a function with argument type int
returning a pointer to
an array
of integers
*/
float *(*x(void))(int);
/* c)
x is a function with no arguments
returns a pointer to
a function with an argument of int
which returns a float pointer
*/
void (*x(int, void (*y)(int)))(int);
/* d)
x is a fuction with arguments int, and a pointer to a function with an argument of int
returns a pointer
to a function with an argument of int
*/
