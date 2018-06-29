

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <ctype.h>			//toupper

char ch[50] = {0};
int i, j;

int main (void)
{
	printf("Enter message: ");
	
	for (i = 0; i < 50; i++)
	{
	ch[i] = getchar();
	ch[i] = toupper(ch[i]);
	if (ch[i] == '\n')
		break;
	}
	
	printf("In B1FF-speak: ");
	for (j = 0; j < i; j++)
	{
		if(ch[j] == 'A')
			ch[j] = '4';
		else if(ch[j] == 'B')
			ch[j] = '8';
		else if(ch[j] == 'E')
			ch[j] = '3';
		else if(ch[j] == 'I')
			ch[j] = '1';
		else if(ch[j] == 'O')
			ch[j] = '0';
		else if(ch[j] == 'S')
			ch[j] = '5';
		
		putchar(ch[j]);
	}
	printf("!!!!!!!!!!!!!!!!");
	
return (0);
}