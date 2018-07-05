/* What will be the value of the string s1 after the following statements
have been executed? */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int main (void)
{

char s1[STR_LENGTH];
char s2[STR_LENGTH];

strcpy(s1, "computer");
strcpy(s2, "science");
if (strcmp(s1, s2) < 0)
	strcat(s1, s2);
else
	strcat(s2, s1);
s1[strlen(s1) - 6] = '\0';

printf("My guess is \"computers\"\n");
puts(s1);

}
