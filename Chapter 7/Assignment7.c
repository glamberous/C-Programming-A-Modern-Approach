
// Chapter 7
// Assignment 7
// Adds, subtracts, multiplies, or divides two fractions

#include <stdio.h>

int main(void)
{
	int num1 = 0, denom1 = 0, num2 = 0, denom2 = 0, result_num = 0, result_denom = 0;
	char ch = 0;
	
	printf("This program will add, subtract, divide, or multiply two fractions.\n");
	printf("Enter two fractions separated by a plus sign, minus sign, division sign, or multiplication sign (example: 1/2+3/4):  ");
	
	
	scanf("%d/%d", &num1, &denom1);
	ch = getchar();
	scanf("%d/%d", &num2, &denom2);
	
	switch (ch)
	{
		case '+':
			result_num = (num1 * denom2) + (num2 * denom1);
			result_denom = denom1 * denom2;
			printf("The sum is %d/%d\n", result_num, result_denom);
			break;
		case '-':
			result_num = (num1 * denom2) - (num2 * denom1);
			result_denom = denom1 * denom2;		
			printf("The difference is %d/%d\n", result_num, result_denom);
			break;
		case '/':
			result_num = denom2 * num1;
			result_denom = denom1 * num2;				
			printf("The quotient is %d/%d\n", result_num, result_denom);
			break;
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;			
			printf("The product is %d/%d\n", result_num, result_denom);
			break;
		default:
		printf("Invalid Input");
	}
	return 0;
}