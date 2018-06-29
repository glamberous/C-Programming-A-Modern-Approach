#include <stdio.h>
#include <ctype.h>
/* figures out the amount of scrabble points a word is*/

int main() 
{
char ch[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10}, input = 0; 
int sum = 0;

printf("This program figures out the amount of scrabble points a word is.\n");
printf("Enter a word: ");

while (input != '\n')
{
	input = getchar();
	input = toupper(input);
	
	if (input >= 'A' && input <= 'Z')
		sum += ch[input - 'A'];

}
   
printf("%d\n", sum);

return(0);
}