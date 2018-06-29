/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int GS1Prefix, GroupID, PubCode, ItemNum, CheckDigit;
	
	/*Collects the information from the user */
	printf("Enter ISBN: ");
	scanf("%d- %d- %d- %d- %d", &GS1Prefix, &GroupID, &PubCode, &ItemNum, &CheckDigit);
	
	/*Prints out the inputted data into a special format*/
	printf("GS1 prefix: %d\n", GS1Prefix);
	printf("Group identifier: %d\n", GroupID);
	printf("Publisher code: %d\n", PubCode);
	printf("Item Number: %d\n", ItemNum);
	printf("Check digit: %d\n", CheckDigit);

	return 0;
}

/* 
Example ISBN's:
978-3-16-148410-0
9971-5-0210-0
99921-58-10-7	
0-85131-041-9
0-684-84328-5
85-359-0277-5
0-8044-2957-X
*/