/*Figure out which calendar date is sooner*/
#include <stdio.h>

int main(void)
{
float e, factorial;
int i, n;

e = 1;
factorial = 1;

printf ("How far would you like to compute e to? ");
scanf ("%d", &n);

for (i = 1; i <= n; i++)
{
	factorial *= i;
	e += ( 1 / factorial);
}

printf ("when e is computed to %d times: %f", n, e);

return 0;
}