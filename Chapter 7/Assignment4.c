#include <stdio.h>

/* Sums a series of numbers (using long variables) */

int main() 
{
int ch;

printf("This program translates an alphabetic phone number into numeric form.\n");
printf("Enter a alphabetic phone number: ");

do
{
	ch = getchar();
	if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'a' || ch == 'b' || ch == 'c')
	{
		ch = 2;
		printf("%d", ch);
	}
	else if (ch == 'D' || ch == 'E' || ch == 'F' || ch == 'd' || ch == 'e' || ch == 'f')
	{
		ch = 3;
		printf("%d", ch);
	}
	else if (ch == 'G' || ch == 'H' || ch == 'I' || ch == 'g' || ch == 'h' || ch == 'i')
	{
		ch = 4;
		printf("%d", ch);
	}
	else if (ch == 'J' || ch == 'K' || ch == 'L' || ch == 'j' || ch == 'k' || ch == 'l')
	{
		ch = 5;
		printf("%d", ch);
	}
	else if (ch == 'M' || ch == 'N' || ch == 'O' || ch == 'm' || ch == 'n' || ch == 'o')
	{
		ch = 6;
		printf("%d", ch);
	}
	else if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S' || ch == 'p' || ch == 'q' || ch == 'r' || ch == 's')
	{
		ch = 7;
		printf("%d", ch);
	}
	else if (ch == 'T' || ch == 'U' || ch == 'V' || ch == 't' || ch == 'u' || ch == 'v')
	{
		ch = 8;
		printf("%d", ch);
	}
	else if (ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z' || ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z')
	{
		ch = 9;
		printf("%d", ch);
	}
	else
	{
		putchar(ch);
	} 
}while (ch != '\n');
   
return(0);
}