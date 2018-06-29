#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <ctype.h>			//toupper
#include <time.h>			//calls time
#include <stdlib.h>			//Random number generator

//#define arraySize ((int) (sizeof(array) / sizeof(array[0][0])))

char board[10][10] = {'A'}, ch = 'B';			//Sets board[0][0] with 'A'
unsigned int randomNum = 0;
short i = 0, x = 0, y = 0;
bool blocked[4] = {0};

int main (void)
{
	
	srand((unsigned) time(NULL));
	
	while(ch <= 'Z')
	{
		randomNum = (rand() % 4);					//Creates a random number from 0 to 3

		
		if (blocked[0] && blocked[1] && blocked[2] && blocked[3])		//checks if all sides were blocked in the loop
		{
			break;
		}

		
		else if ((randomNum) == 0)					//x + 1 (up)
		{
			if (x < 9  && board[x+1][y] == 0)
				x++;
			else
			{
				blocked[0] = true;
				continue;
			}
		}
		else if ((randomNum) == 1)					//x - 1 (down)
		{
			if (x > 0 && board[x-1][y] == 0)
				x--;
			else
			{
				blocked[1] = true;
				continue;
			}
		}
		else if ((randomNum) == 2)					//y + 1 (right)
		{
			if (y < 9 && board[x][y+1] == 0)
				y++;
			else
			{
				blocked[2] = true;
				continue;
			}
		}
		else if ((randomNum) == 3)					//y - 1 (left)
		{
			if (y > 0 && board[x][y-1] == 0)
				y--;
			else
			{
				blocked[3] = true;
				continue;
			}
		}
		
		for(i = 0; i < 4; i++)						//resets the blocked counters
			blocked[i] = false;
		
		board[x][y] = ch++;							//Assigns a new letter to the board, first one starts with 'B'
	}
	
	for(x = 0; x < 10; x++)							//Prints out the results of the board
	{
		for(y = 0; y < 10; y++)
		{
			if (board[x][y] == 0)
				putchar('.');
			else
				putchar(board[x][y]);
		}
		putchar('\n');
	}

return (0);
}