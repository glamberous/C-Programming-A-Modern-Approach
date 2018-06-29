#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

#define arraySize ((int) (sizeof(redBlack) / sizeof(redBlack[0][0])))

int main (void)
{
	unsigned char i, j, redBlack[8][8] = {0};
	
	for (i = 0; i < arraySize / 8; i++)
	{
		for (j = 0; j < arraySize / 8; j++)
		{
			if ((i + j) % 2 == 0)
				redBlack[i][j] = 'B';
			else
				redBlack[i][j] = 'R';
			
			putchar(redBlack[i][j]);	
		}
	printf("\n");
	}
return (0);
}