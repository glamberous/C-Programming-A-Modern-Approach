#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

#define MAX_DIGITS 10

char display[(MAX_DIGITS * 4)][3];
const bool digitalNumbers[10][7] = 	{{1, 1, 0, 1, 1, 1, 1},	//0
									{0, 0, 0, 1, 0, 0, 1},	//1
									{1, 0, 1, 1, 1, 1, 0},	//2
									{1, 0, 1, 1, 0, 1, 1},	//3
									{0, 1, 1, 1, 0, 0, 1},	//4
									{1, 1, 1, 0, 0, 1, 1},	//5
									{1, 1, 1, 0, 1, 1, 1},	//6
									{1, 0, 0, 1, 0, 0, 1},	//7
									{1, 1, 1, 1, 1, 1, 1},	//8
									{1, 1, 1, 1, 0, 1, 1}};	//9

void clear_digits_array(void);
void process_digit(int digit, short position);
void print_digits_array(void);

void clear_digits_array(void)										//sets the full array to 0
{
	int x, y;
	for(x = 0; x < 4; x++)
	{
		for(y = 0; y < (MAX_DIGITS * 4); y++)
		{
			display[y][x] = ' ';
		}
	}
}

void process_digit(int digit, short position)						//fills the array with the user entered numbers
{
	short x;
	char temp;
	position *= 4;
	
	for (x = 0; x < 7; x++)
	{
		temp = (x == 0 || x == 2 || x == 5) ? '_' : '|';
		
		if (digitalNumbers[digit][x] && x == 0)						//first row
		{
			display[position + 1][0] = temp;
		}
		else if (digitalNumbers[digit][x] && x >= 1 && x <= 3)		//second row
		{
			display[(position + x) - 1][1] = temp;
		}
		else if (digitalNumbers[digit][x] && x >= 4 && x <= 6)		//third row
		{
			display[(position + x) - 4][2] = temp;
		}
	}
}

void print_digits_array(void)										//prints the array
{
	int x, y;
	
	for(y = 0; y < 3; y++)
	{
		for(x = 0; x < (MAX_DIGITS * 4); x++)
		{
			
			printf("%c", display[x][y]);
		}
		printf("\n");
	}
}

int main(void)
{
	char ch = 0;
	short position = 0;
	
	clear_digits_array();
	
	printf("Enter a number: ");
	while(ch != '\n')
	{
		ch = getchar();
		
		if (ch >= '0' && ch <= '9' && position < MAX_DIGITS)		//ignores characters that aren't numbers and anything beyond the array limit
		{
			ch = ch - '0';
			process_digit((short)ch, position);
			position++;
		}
	}
	
	print_digits_array();
}
