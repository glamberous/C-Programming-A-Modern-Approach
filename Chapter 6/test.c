/*Mans not hot*/
#include <stdio.h>

int main(void)
{
int inputNum, largeNum;

inputNum = 1;
largeNum = 0;


while (inputNum > 0)
{
	printf("Enter a number: ");
	printf("%d", &inputNum);

	if (inputNum > largeNum)
	{
		largeNum = inputNum;
	}
} 

printf("The largest number entered was %d", largeNum);	
	
return 0;
}