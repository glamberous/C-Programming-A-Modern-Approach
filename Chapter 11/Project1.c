#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define ARRAY_SIZE 6


void pay_amount(int dollarAmount, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
	int dollarAmount = 0, twenties = 0, tens = 0, fives = 0, ones = 0;
	
	printf("Enter a dollar amount: ");
	scanf("%d", &dollarAmount);
	
	pay_amount(dollarAmount, &twenties, &tens, &fives, &ones);
	
	printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d", twenties, tens, fives, ones);
}

void pay_amount(int dollarAmount, int *twenties, int *tens, int *fives, int *ones)
{
	while(dollarAmount >= 20)
	{
		dollarAmount -= 20;
		(*twenties)++;
	}
	while(dollarAmount >= 10)
	{
		dollarAmount -= 10;
		(*tens)++;
	}
	while(dollarAmount >= 5)
	{
		dollarAmount -= 5;
		(*fives)++;
	}
	while(dollarAmount >= 1)
	{
		dollarAmount -= 1;
		(*ones)++;
	}
}