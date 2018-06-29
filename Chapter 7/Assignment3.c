#include <stdio.h>

/* Sums a series of numbers (using long variables) */

int main() 
{
double n, sum = 0;

printf("This program sums a series of floats.\n");
printf("Enter floats (0 to terminate): ");
scanf("%lf", &n);			
while (n != 0) 
{
	sum += n;
	scanf("%lf", &n);
}
printf("The sum is: %f\n", sum);

   return(0);
}