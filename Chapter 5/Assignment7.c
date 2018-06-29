/* Determines Highest and Lowest number */
#include <stdio.h>

int main(void)
{
	int i1, i2, i3, i4,
		largest, smallest,
		smallA, smallB, largeA, largeB;
	
	printf("\nEnter four integers: ");
	scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
	
	//Bracket A
	if (i1 < i2)
	{
		smallA = i1;
		largeA = i2;
	}
	else
	{
		smallA = i2;
		largeA = i1;
	}
	
	//Bracket B
	if (i3 < i4)
	{
		smallB = i3;
		largeB = i4;
	}
	else
	{
		smallB = i4;
		largeB = i3;
	}
	
	//Smallest Grand Finals
	smallest = smallA < smallB ? smallA : smallB;
	
	//Largest Losers Bracket
	largest = largeA > largeB ? largeA : largeB;
	
	printf("Largest: %d\n", largest);
	printf("Smallest: %d\n", smallest);
	
	return 0;
}