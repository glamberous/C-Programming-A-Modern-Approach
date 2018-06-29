/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int item, month, day, year;
	float cost;
	
	/*Collects the information from the user */
	printf("Enter item number: ");
	scanf("%d", &item);
	printf("Enter the item's cost: ");
	scanf("%f", &cost);
	printf("Enter the purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);
	
	/*Prints out the inputted data into a special format*/
	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%.2d/%.2d/%d ", item, cost, month, day, year);
	
	return 0;
}