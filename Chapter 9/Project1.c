/* Sorts an array with a recursive loop. Puts the largest number into the final slot */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int i = 0;												//used for counting

int selection_sort(int x[], int n)
{
	int placeholder = 0;
	
	if(n <= 0)
	{
		return(0);										//ends the recursion
	}
	else
	{
		for(i = 0;i < n - 1;i++)						//searches the array and sets the largest number as x[n]
		{
			if(x[i] > x[i+1])
			{
				placeholder = x[i+1];					//Swaps i+1 with i if i is larger than i+1
				x[i+1] = x[i];
				x[i] = placeholder;
			}
		}
		selection_sort(x,n - 1);						//calls the array again to continue sorting
	}
}

int main(void)
{	
	int n = 0;
	
	printf("Enter how long the array should be: ");	
	scanf("%d", &n);

	int x[n];											//initiates an array based on user input
	
	printf("Enter in the numbers for the array: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);								//user puts in the numbers to fill the array
	}
	
	selection_sort(x, n);
	
	for(i = 0;i < n; i++)
	{
		printf("%d ", x[i]);
	}
	
	
	return (0);
}