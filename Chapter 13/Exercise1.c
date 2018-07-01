/* Which lines print a new line properly */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper


int main (void)
{
	printf("%c", '\n');
	printf("1. New Line? Y; %%c calls a character and ' ' signifies a character. \n"); // Answer N, "multi-character constant"
	
	//printf("%c", "\n");
	//printf("New Line? N; %%c calls a character and \" \" signifies a string. \n"); // Answer N, was expecting a pointer
	
	//printf("%s", '\n');
	//printf("New Line? N; %%s calls a string and ' ' signifies a character. \n"); // Answer N, Looking for a Char pointer
	
	printf("%s", "\n");
	printf("2. New Line? Y; %%s calls a string and \" \" signifies a string. \n");
	
	//printf('\n');
	//printf("New Line? N; printf calls a string and ' ' signifies a character. \n"); // Answer N, is looking for a char pointer
	
	printf("\n");
	printf("3. New Line? Y; printf calls a string and \" \" signifies a string. \n");
	
	putchar('\n');
	printf("4. New Line? Y; putchar calls a charater and ' ' signifies a character. \n"); // Answer N, "multi-character constant"
	
	//putchar("\n");
	//printf("New Line? N; putchar calls a charater and " " signifies a string. \n"); // Answer N, Was expecting a char
	
	//puts('\n');
	//printf("New Line? N; puts calls a string and ' ' signifies a character. \n"); // Answer N, is looking for a char pointer
	
	puts("\n");
	printf("5. New Line? Y; puts calls a string and " " signifies a string. \n"); // Answer Y, but puts automatically puts a \n afterwards so this is two \n's
	
	puts("");
	printf("6. New Line? N; \\0 doesn't represent \\n\n"); // Answer Y, automatically puts \n at the end	
}