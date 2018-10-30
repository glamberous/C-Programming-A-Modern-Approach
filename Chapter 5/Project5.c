/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	float income = 0, due = 0;
	
	printf ("Enter your yearly taxable income ($xxx.xx format): ");
	scanf("$%f", &income);
	
	if (income < 750.00f)
	{
		due = income * .01;
	}
	else if (income < 2250.00f)
	{
		due = 7.50f + ((income - 750.00f) * .02);
	}
	else if (income < 3750.00f)
	{
		due = 37.50f + ((income - 2250.00f) * .03);
	}
	else if (income < 5250.00f)
	{
		due = 82.50f + ((income - 3750.00f) * .04);
	}
	else if (income < 7000.00f)
	{
		due = 142.50f + ((income - 5250.00f) * .05);
	}
	else
	{
		due = 230.00f + ((income - 7000.00f) * .06);
	}
	
	printf("Your tax due is:  ");
	printf("$%.2f.", due);
	
	return 0;
}