/* Write a complete description of the type of x as specified by each of the
following declarations. */

char (*x[10])(int);

typedef char Fcn(int);
typedef Fcn *Fcn_ptr;
typedef Fcn_ptr Fcn_ptr_array[10];
Fcn_ptr_array x;

/* a)
x is an array
of pointers to
functions with an argument of type int
that returns type char
*/

int (*x(int))[5];

typedef int Array[5];
typedef Array *Fcn(int);
Fcn x;

/* b)
x is a function with argument type int
returning a pointer to
an array
of integers
*/

float *(*x(void))(int);

typedef float *Fcn(int);
typedef Fcn *Fcn2(void);
Fcn2 x;
/* c)
x is a function with no arguments
returns a pointer to
a function with an argument of int
which returns a float pointer
*/

void (*x(int, void (*y)(int)))(int);

typedef void Fnc(int);
typedef Fcn *Fcn2(int, void (*y)(int))
Fcn2 x;
/* d)
x is a fuction with arguments int, and a pointer to a function with an argument of int
returns a pointer
to a function with an argument of int
*/
