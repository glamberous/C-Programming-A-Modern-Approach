/*Mans not hot*/
#include <stdio.h>

int main(void)
{
	float loanInput, interestRate, monthlyPayment, monthlyInterest, firstBalance, secondBalance, thirdBalance;

	printf("\nEnter amount of loan: ");
	scanf("%f", &loanInput);
	printf("\nEnter what the interest rate is: ");
	scanf("%f", &interestRate);
	printf("\nEnter how much you pay monthly: ");
	scanf("%f", &monthlyPayment);
	
	monthlyInterest = ((interestRate * .01) / 12) + 1;
	firstBalance = ((loanInput * monthlyInterest)-monthlyPayment);
	secondBalance = ((firstBalance * monthlyInterest)-monthlyPayment);
	thirdBalance = ((secondBalance * monthlyInterest)-monthlyPayment);
	
	printf("Balance remaining after the first payment: %.2f\n", firstBalance);
	printf("Balance remaining after the second payment: %.2f\n", secondBalance);
	printf("Balance remaining after the third payment: %.2f\n",  thirdBalance);
	
	return 0;
}