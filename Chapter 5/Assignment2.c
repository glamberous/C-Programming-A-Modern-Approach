/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int inputH, inputM, outputH, outputM, amPm;
	printf ("Enter a 24-hour time: ");
	scanf ("%d :%d", &inputH, &inputM);
	
	if (inputH >= 00 && inputH < 12)
	{
		amPm = 0;
	}
	else
	{
		amPm = 1;
	}
	
	switch (inputH)
	{
		case 00: outputH = 12; break;
		case 13: outputH = 1; break;
		case 14: outputH = 2; break;
		case 15: outputH = 3; break;
		case 16: outputH = 4; break;
		case 17: outputH = 5; break;
		case 18: outputH = 6; break;
		case 19: outputH = 7; break;
		case 20: outputH = 8; break;
		case 21: outputH = 9; break;
		case 22: outputH = 10; break;
		case 23: outputH = 11; break;
		case 24: outputH = 12; break;
		default: outputH = inputH; break;
	}
	outputM = inputM;
	
	printf ("Equivalent 12-hour time: %d:%.2d", outputH, outputM);
	
	if (amPm == 0)
	{
		printf ("am");
	}
	else
	{
		printf ("pm");
	}
		
	
	return 0;
}