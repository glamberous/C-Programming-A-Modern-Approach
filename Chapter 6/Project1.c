/* determine the largest number from user input */
#include <stdio.h>

int main(void)
{
float inputNum, largeNum;

inputNum = 1;
largeNum = 0;


while (inputNum > 0)
{
	printf("Enter a number: ");
	scanf("%f", &inputNum);

	if (inputNum > largeNum)
	{
		largeNum = inputNum;
	}
} 

printf("The largest number entered was %f", largeNum);	
	
return 0;
}