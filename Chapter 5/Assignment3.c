/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	float commission, value, sharesVal, rivalCommission;
	int shares;
	
	printf ("Enter number of shares: ");
	scanf("%d", &shares);
	printf ("Enter the value of a share: ");
	scanf("%f", &sharesVal);
	
	value = sharesVal * shares;
	
	if (shares < 2000)
		rivalCommission = 33.00f + 0.03f * shares;
	else
		rivalCommission = 33.00f + 0.02f * shares;
	
	if (value < 25000.00f)
		commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission = 76.00f + .0022f * value;
	else if (value < 50000.00f)
		commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission = 155.00f + .0011f * value;
	else
		commission = 255.00f + .0009f * value;
	
	if (commission < 39.00f)
		commission = 39.00f;
	
	printf ("Commission for the A Dudes: $%.2f\n", commission);
	printf ("Commission for the B Dudes: $%.2f\n", rivalCommission);
	
	return 0;
}