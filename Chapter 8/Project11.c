#include <stdio.h>
#include <ctype.h>

/* Converts an alphabetic phone number into numeric form. */

int main() 
{
char ch[15];
short x = 0;

printf("This program translates an alphabetic phone number into numeric form.\n");
printf("Enter a alphabetic phone number: ");

for(x = 0; x < 15; x++)
{
	ch[x] = getchar();
	ch[x] = toupper(ch[x]);
	switch(ch[x])
	{
		case 'A': ; case 'B': ; case 'C':
		putchar('2');
		break;
		
		case 'D': ; case 'E': ; case 'F':
		putchar('3');
		break;
		
		case 'G': ; case 'H': ; case 'I':
		putchar('4');
		break;
		
		case 'J': ; case 'K': ; case 'L':
		putchar('5');
		break;
		
		case 'M': ; case 'N': ; case 'O':
		putchar('6');
		break;
		
		case 'P': ; case 'Q': ; case 'R': ; case 'S':
		putchar('7');
		break;
		
		case 'T': ; case 'U': ; case 'V':
		putchar('8');
		break;
		
		case 'W': ; case 'X': ; case 'Y': ; case 'Z':
		putchar('9');
		break;
		
		default:
		putchar(ch[x]);
	}	
}
   
return(0);
}