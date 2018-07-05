/* What will be the value of the string str after the following statements
have been executed? */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

int main (void)
{

char str[STR_LENGTH];

strcpy(str, "tire-bouchon");
printf("strcpy(str, \"tire-bouchon\") will equal \"tire-bouchon\"\n");
puts(str);

strcpy(&str[4], "d-or-wi");
printf("strcpy(&str[4], \"d-or-wi\") will equal \"tired-or-wi\"\n");
puts(str);

strcat(str, "red?");
printf("strcat(str, \"red?\") will equal \"tired-or-wired?\"\n");
puts(str);

}
