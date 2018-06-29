/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int evaluate_position(char board[][8]);

int main(void)
{	
	char board[8][8] = {
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		};
	
	printf("The evaluated chess position is: %d\n", evaluate_position(board));
	
	return (0);
}

double median(double x, double y, double z)
{
	double median = 0;
	
	if (x <= y && x <= z)
		median = y < z ? y : z;
	else if(y <= x && y <=z)
		median = x < z ? x : z;
	else 
		median = x < y ? x : y;
	
	return (median);
}



