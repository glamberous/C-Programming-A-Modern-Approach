#include <stdio.h>
#include <ctype.h>
/* Program prints the sizeof for all the things (ints, longs, doubles, ect.)*/

int main() 
{

printf("size of int: %zd\n", (int) sizeof(int));
printf("size of short: %zd\n", (int)sizeof(short));
printf("size of long int: %zd\n",(int) sizeof(long));
printf("size of float: %zd\n", (int)sizeof(float));
printf("size of double: %zd\n", (int)sizeof(double));
printf("size of long double: %zd\n", (int)sizeof(long double));

return(0);
}