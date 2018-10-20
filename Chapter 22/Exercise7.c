
/*
Suppose that scanf calls as follows:
n = scanf("%d%f%d", &i, &x, &j);
(i, j, and n are int variables and x is a float variable.) Assuming that the input
stream contains the characters show, give the values of i, j, n, and x after the call.
In addition, indicate which characters were consumed by the call.
*/

#include <stdio.h>

int main()
{
  int i = 0, j = 0, n = 0;
  float x = 0;

  n = scanf("%d%f%d", &i, &x, &j);
  printf("i = %d\n", i);
  printf("x = %f\n", x);
  printf("j = %d\n", j);
  printf("n = %d\n", n);
}

/*
a) i = 10, x = 20.00~, j = 30, n = 3

b) i = 1, x = 0.00000, j = 2, n = 3

c) i = 0, x = 0.10000, j = 0, n = 3

d) i = 0 (undefined), x = 0.100000, j = 0 (undefined), n = 1
Correct answer: all undefined. Nothing gathered.

*/
