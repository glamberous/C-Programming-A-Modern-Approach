/* function to get the power of a number */
#include <stdio.h>		// for typef & scanf


int power(int x, int n);

int main(void)
{	
	int n = 0, x = 0;
	
	printf("Program gives you the result for x^n\n");
	printf("Enter what number you would like to be x: ");
	scanf("%d", &x);
	printf("Enter what number you would like to be n: ");
	scanf("%d", &n);
	
	printf("Answer to the equation: %d", power(x, n));

}
	
int power(int x, int n)	
{
	if (n == 0)
		return 1;
	else
	{
		if (n % 2)
		{
			return x * power(x, n - 1);
		}
		else
		{
			return power(x, n/2) * power(x, n/2);
		}
	}
}	