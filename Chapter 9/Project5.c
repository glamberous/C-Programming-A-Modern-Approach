/* creates a "magic square" */
#include <stdio.h>		// for typef & scanf


void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int x = 0, y = 0;

int main(void)
{	
	int n = 0;
	
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);													//stores an odd number, used for the size of the array
	
	while ((n % 2) != 1)												//in case the user doesn't put in an odd number
	{
		printf("Input was not an odd number. Enter a new number: ");
		scanf("%d", &n);
	}
	
	int square[n][n];													//sets the variable array based on user input

	create_magic_square(n, square);
	print_magic_square(n, square);
	
}
	
void create_magic_square(int n, int square[n][n])	
{
	int i = 0;
	
	for(x = 0; x < n ; x++)												//fills the variable array with 0's
	{
		for(y = 0; y < n ; y++)
		{
			square[x][y] = 0;
		}
	}
	
	y = (n/2);															//sets the starting place, middle of the top row
	x = 0;
	
	for(i = 0;i < (n * n) ;i++)
	{
		square[x][y] = i + 1;											//increments +1 for each number placed

		if (square[((x + n) - 1) % n][(y + 1) % n] == 0)				//Checks to see if one square above and to the right is available(including wrap arounds)
		{
			x = ((x + n) - 1) % n; 										//sets new value of x
			y = (y + 1) % n;											//sets new value of y
		}
		else															//if the spot is already taken, go down 1 from the last placed number
		{
			x = (x + 1) % n;
		}
	}
}

void print_magic_square(int n, int square[n][n])
{
	for(x = 0; x < n ; x++)												//prints the board
	{
		for(y = 0; y < n ; y++)
		{
			printf("%d\t", square[x][y]);
		}
		putchar('\n');
	}
}