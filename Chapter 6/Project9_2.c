/* Prints a calendar */
#include <stdio.h>

int main(void)
{
int payNum, i;
float loan, intRate, payAmount;

printf("Enter amount of loan: ");
scanf("%f", &loan);
printf("Enter interest rate: ");
scanf("%f", &intRate);
printf("Enter monthly payment: ");
scanf("%f", &payAmount);


intRate *= .01;
intRate /= 12;

for (i=0; loan > 0; i++)
{
	loan = loan - payAmount;
	loan += (loan * intRate);
	printf("Balance remaining after payment %d: %.2f\n", i, loan);
}	
	
	return 0;
}