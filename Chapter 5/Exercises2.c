/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int input;
	printf ("Enter in your Area Code: ");
	scanf ("%d", &input);
	printf ("Your Area Code is for ");
	switch (input)
	{
		case 229: printf ("Albany"); break; 
		case 404: printf ("Atlanta"); break; 
		case 470: printf ("Atlanta"); break; 
		case 478: printf ("Macon"); break; 
		case 678: printf ("Atlanta"); break; 
		case 706: printf ("Columbus"); break; 
		case 762: printf ("Columbus"); break; 
		case 770: printf ("Altanta"); break; 
		case 912: printf ("Savannah"); break;
		case 253: printf ("Auburn"); break;
		default: printf ("Area Code not recognized"); break;
	}
	return 0;
}