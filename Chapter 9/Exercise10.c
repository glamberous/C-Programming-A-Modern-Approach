/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int largest(unsigned short, int []);
double average(unsigned short, int []);
unsigned short positive(unsigned short, int []);

int main(void)
{	
	
	unsigned short n = 0;
	short i = 0;
	
	printf("Enter in the length of Array \"a\" you'd like to use for Exercise10: ");
	scanf("%hud", &n);
	
	int a[n];
	
	printf("Enter in the numbers to fill in the Array: ");
	for(i = 0; i < n; i++)
	{
	scanf("%d", &a[i]);
	}
	
	printf("The largest element of a: %d\n", largest(n, a));
	printf("The average of all elements in a: %.2f\n", average(n, a));
	printf("The number of positiver numbers in a: %hu\n", positive(n, a));
	
	return (0);
}

int largest(unsigned short n, int a[])
{	
	short i = 0;
	int largest = 0;
	
	for(i = 0; i < n; i++)
	{
		if (largest < a[i])
		{
		largest = a[i];
		}
	}
	
	return (largest);
}

double average(unsigned short n, int a[])
{
	short i = 0;
	double average = 0;
	for (i = 0; i < n; i++)
		average += a[i];
		
	return (average / n);
}

unsigned short positive(unsigned short n, int a[])
{
	short i;
	unsigned short countPositive = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			countPositive++;
		}
	}
		
	return (countPositive);
}


