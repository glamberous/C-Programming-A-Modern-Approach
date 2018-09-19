/* Write declarations for the following variables and functions */

/* a) p is a pointer to a function with a character pointer argument that
returns a character pointer. */

char *(*p)(char *);

/* b) f is a function with two arguments: p, a pointer to a structure with tag t,
and n, a long integer. f returns a pointer to a function that has no arguments
and returns nothing. */

void (*f(struct t *p, long int n))(void);

/* c) a is an array of four pointers to functions that have no arguments and return
nothing. The elements of a initially point to functions named insert, search, update,
and print. */

void (*a[])(void) = {insert, search, update, print};

/* d) b is an array of 10 pointers to functions with two int arguments that return
structures with tag t. */

struct t (*b[10])(int, int);
