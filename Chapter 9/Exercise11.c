/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


double compute_GPA(char grades[], int n);

int main(void)
{	
	
	unsigned short n = 0, i = 0;
	
	printf("How many grades are you going to enter? ");
	scanf("%hud", &n);
	
	char grades[n];
	
	printf("Enter each letter grade (A, B, C, D, or F): ");
	while(i < n)
	{
		grades[i] = getchar();
		grades[i] = toupper(grades[i]);
		if (grades[i] >= 'A' && grades[i] <= 'Z')
			i++;
	}
	
	printf("The GPA of the total grades is: %.2f\n", compute_GPA(grades, n));
	
	return (0);
}

double compute_GPA(char grades[], int n)
{	
	unsigned short i;
	int average = 0;
	for(i = 0; i < n; i++)
	{
		switch (grades[i])
		{
		case 'A': average += 4; break;
		case 'B': average += 3; break;
		case 'C': average += 2; break;
		case 'D': average += 1; break;
		case 'F': average += 0; break;
		}
	}
	return ((double)average / n);
}



