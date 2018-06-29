/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Eleven, Twelve, Thirteen, Fourteen, Fifteen, Sixteen,
	Row1, Row2, Row3, Row4, Column1, Column2, Column3, Column4, Diag1, Diag2;
	
	/*Collects the information from the user */
	printf("Enter the numbers from 1 to 16 in any order: ");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &One, &Two, &Three, &Four, &Five, &Six, &Seven, &Eight, &Nine, &Ten, &Eleven, &Twelve, &Thirteen, &Fourteen, &Fifteen, &Sixteen);
	
	Column1 = One + Five + Nine + Thirteen;
	Column2 = Two + Six + Ten + Fourteen;
	Column3 = Three + Seven + Eleven + Fifteen;
	Column4 = Four + Eight + Twelve + Sixteen;
	Row1 = One + Two + Three + Four;
	Row2 = Five + Six + Seven + Eight;
	Row3 = Nine + Ten + Eleven + Twelve;
	Row4 = Thirteen + Fourteen + Fifteen + Sixteen;
	Diag1 = One + Six + Eleven + Sixteen;
	Diag2 = Four + Seven + Ten + Thirteen;
	
	/*Prints out the inputted data into a grid*/
	printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n", One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, 
	Eleven, Twelve, Thirteen, Fourteen, Fifteen, Sixteen);
	printf("Row sums: %d %d %d %d\nColumn sums: %d %d %d %d\nDiagonal sums: %d %d\n", Row1, Row2, Row3, Row4, Column1, Column2, Column3, Column4, Diag1, Diag2);


	return 0;
}