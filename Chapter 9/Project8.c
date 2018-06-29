/* craps */
#include <stdio.h>		// for typef & scanf
#include <stdbool.h>	//booleans
#include <time.h>		//calls time
#include <stdlib.h>		//Random number generator
#include <ctype.h>		//toupper

int roll_dice(void);
bool play_game(void);

int main(void)
{	
	bool boo = false;
	short win = 0, lose = 0;
	char playAgain = 0;
	
	srand((unsigned) time(NULL));
	
	while(1)
	{
		boo = play_game();
		if(boo)
		{
			printf("You win!\n\n");
			win++;
		}
		else
		{
			printf("You lose!\n\n");
			lose++;
		}
		printf("Play again? ");
		playAgain = getchar();
		playAgain = toupper(playAgain);
		
		if(playAgain != 'Y')
		{
			break;
		}
		getchar(); //burns the \n
	}
	
	printf("\n\nWins: %d\tLosses: %d", win, lose);
}
	
int roll_dice(void)	
{
	unsigned int roll = 0;
	
	roll = ((rand() % 6) + 1) + ((rand() % 6) + 1);
	printf("You rolled: %d\n", roll);
	
	return roll;
}	

bool play_game(void)
{
	int point = 0, temp = 0;
	
	point = roll_dice();
	if (point == 7 || point == 11)
		return 1;
	else if (point == 2 || point == 3 || point == 12)
		return 0;
	else
	{
		printf("Your point is: %d\n", point);		
		while(1)
		{
			temp = roll_dice();
			if(temp == point)
				return 1;
			else if(temp == 7)
				return 0;
		}
	}
}