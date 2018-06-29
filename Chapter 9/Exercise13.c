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

int evaluate_position(char board[][8])
{	
	unsigned short x = 0, y = 0, sumW = 0, sumB = 0;

	for(x = 0; x < 8; x++)
	{
		for(y = 0; y < 8 ; y++)
		{
			switch (board[x][y])
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
	}
	return (sumW - sumB);
}



