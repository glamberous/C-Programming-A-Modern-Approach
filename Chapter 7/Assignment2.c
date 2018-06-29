#include <stdio.h>

/* Prints a table of squares using an for statement */

int main() 
{
char ch;
int i, n;

printf("This program prints a table of squares.\n");
printf("Enter number of entries in table: ");
scanf("%d", &n);																										//Collects the number from the user for how many squares should be shown in the table
//ch = getchar();																											//Need this here to burn the '\n' from the initial user data entry

for (i = 1; i <= n; i++)																						//Compares i which is just a counter, to the number the user entered. So it counts up and stops at users input
{
	printf("%10d%10d\n", i, i * i);
	if (i % 24 == 0)																									//Every 24th square shown in the table, it'll stop to show "Press Enter to Continue..."
	{
		printf("Press Enter to continue...");
		//while((ch = getchar()) != '\n');																//This while loop collects and ignores any user inputs that's not '\n'. This also disposes of the unused chars for future "Press Enter" breaks
    scanf();
	}
}


   return(0);
}