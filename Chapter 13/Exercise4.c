/* Modify the read line function */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_LENGTH 10

int read_lineA(char[], int);
int read_lineB(char[], int);
int read_lineC(char[], int);
int read_lineD(char[], int);

int main (void)
{
	char s[STR_LENGTH + 1], ch;
	
	read_lineD(s, STR_LENGTH);
	
	puts(s);
}

int read_lineA(char str[], int n) // Skips all blank spaces at the start.
{
	int ch, i = 0;
	
	while ((ch = getchar()) == ' ')
		/*intentionally null*/;
	str[i] = ch;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[++i] = ch;
	str[++i] = '\0';
	return i;
}

int read_lineB(char str[], int n) // stops reading when it finds an empty space
{
	int ch, i = 0;
	
	while (isspace(ch = getchar()) == 0)
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

int read_lineC(char str[], int n) // Includes \n in the string
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i++] = ch;
	str[i] = '\0';
	return i;
}

int read_lineD(char str[], int n) // Have it leave behind characters it doesn't have room to store
{
	int ch, i = 0;
	
	do 
	{
		ch = getchar();
		if (ch == '\n')
			break;
		str[i++] = ch;
	}
	while (i < n);
		
	str[i] = '\0';
	return i;
}