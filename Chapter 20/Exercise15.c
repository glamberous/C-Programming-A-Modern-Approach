#include <stdio.h>

int main (void)
{
//Assume that the variable s has been declared as follows:
struct {
  unsigned int flag: 1;
  } s;

  s.flag = 1;
  printf("%d\n", s.flag);

  /*
  With some compilers, executing the following statements causes 1 to be displayed,
  but with other compilers, the output is -1. Explain the reasoning for this behavior.

  This is because unsigned and signed is not specified. If you specify unsigned
  it'll always be 1, or if you specify signed it'll always be -1.

  Solve this problem by specifying unsigned.
  */
}
