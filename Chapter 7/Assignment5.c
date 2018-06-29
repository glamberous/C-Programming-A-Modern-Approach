#include <stdio.h>
#include <ctype.h>
/* figures out the amount of scrabble points a word is*/

int main() 
{
int ch, sum = 0;

printf("This program figures out the amount of scrabble points a word is.\n");
printf("Enter a word: ");

while (1)
{
	ch = getchar();
	ch = toupper(ch);
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'L' || ch == 'N' || ch == 'O' || ch == 'R' || ch == 'S' || ch == 'T' || ch == 'U')
	{
		ch = 1;
	}
	else if (ch == 'D' || ch == 'G')
	{
		ch = 2;
	}
	else if (ch == 'B' || ch == 'C' || ch == 'M' || ch == 'P')
	{
		ch = 3;
	}
	else if (ch == 'F' || ch == 'H' || ch == 'V' || ch == 'W' || ch == 'Y')
	{
		ch = 4;
	}
	else if (ch == 'K')
	{
		ch = 5;
	}
	else if (ch == 'J' || ch == 'X')
	{
		ch = 8;
	}
	else if (ch == 'Q' || ch == 'Z')
	{
		ch = 10;
	}
	else if (ch == '\n')
	{
		break;
	}
	else
	{
		ch = 0;
	}
	
	sum += ch;
}
   
printf("%d\n", sum);

return(0);
}