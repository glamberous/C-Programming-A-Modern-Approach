/* Write a program that asks the user to enter two integers, then calculates and displays their greatest common divisor (GCD) */
#include <stdio.h>

int main(void)
{
int input1, input2, remainder;

printf("Enter a number: ");
scanf("%d", &input1);
printf("Enter another number: ");
scanf("%d", &input2);

while (input1 > 0)
{
	remainder = input2 % input1;
	input2 = input1;
	input1 = remainder;
} 

printf("Greatest common divisor: %d", input2);	
	
return 0;
}