/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define BoardSize 64

int evaluate_position(char board[0], int n);

int main(void)
{	
	char board[8][8] = {
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{'R', 'N', 0, 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		};
	
	printf("The evaluated chess position is: %d\n", evaluate_position(board[0], BoardSize));
	
	return (0);
}

int evaluate_position(char board[0], int n)
{	
	int sumW = 0, sumB = 0;
	char *p;

	for(p = board; p < board + n; p++)
	{
		switch (*p)
		{
			case 'Q': sumW += 9; break;
			case 'R': sumW += 5; break;
			case 'B': sumW += 3; break;
			case 'N': sumW += 3; break;
			case 'P': sumW += 1; break;
			case 'q': sumB += 9; break;
			case 'r': sumB += 5; break;
			case 'b': sumB += 3; break;
			case 'n': sumB += 3; break;
			case 'p': sumB += 1; break;
		}
	}
	return (sumW - sumB);
}



