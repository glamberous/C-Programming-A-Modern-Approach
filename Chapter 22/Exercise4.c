
/*
Show how each of the following numbers will look if displayed by printf with
%#012.5g as the conversion specification:

a) 83.7361
*0000083.736
00000083.736

b) 29748.6607
*00000029748
00000029749.

c) 1054932234.0
*1.054900000
001.0549e+09

d) 0.0000235218
002.3522e-05
002.3522e-05
*/

#include <stdio.h>

int main()
{
  printf("a)%#012.5g\n", 83.7361);
  printf("b)%#012.5g\n", 29748.6607);
  printf("c)%#012.5g\n", 1054932234.0);
  printf("d)%#012.5g\n", 0.0000235218);
}
