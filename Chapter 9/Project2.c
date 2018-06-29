/*Buns not hot*/
#include <stdio.h>

float incomeTax (float income);

int main(void)
{
	float income;
	
	printf ("Enter your yearly taxable income($xxx.xx format): ");
	scanf("$%f", &income);
	
	printf("Your tax due is:  ");
	printf("$%.2f.", incomeTax(income));
	
	return (0);
}

float incomeTax (float income)
{
	if (income < 750.00f)
		return (income * .01);
	else if (income < 2250.00f)
		return (7.50f + ((income - 750.00f) * .02));
	else if (income < 3750.00f)
		return (37.50f + ((income - 2250.00f) * .03));
	else if (income < 5250.00f)
		return (82.50f + ((income - 3750.00f) * .04));
	else if (income < 7000.00f)
		return (142.50f + ((income - 5250.00f) * .05));
	else
		return (230.00f + ((income - 7000.00f) * .06));
	
}