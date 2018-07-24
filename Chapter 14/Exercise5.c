/* Define TOUPPER as: */

#define TOUPPER(c) ('a' <= (c)&&(c) <= 'z'?(c)-'a'+'A':(c))
//#define TOUPPER(c) ('a' <= (s[++i])&&(s[++i]) <= 'z'?(s[++i])-'a'+'A':(s[++i]))
/* Let s be a string and let i be an int variable. Show the output produced by
each of the following prgram fragments. */

#include <string.h>
#include <stdio.h>

#define STR_MAX 5

int main (void)
{
	char s[STR_MAX];
	int i = 0;

	strcpy(s, "abcd");
	i = 0;
	putchar(TOUPPER(s[++i]));
	putchar('\n');
	printf("I predicted it would output as \"aBCD\"\n");

	strcpy(s, "0123");
	i = 0;
	putchar(TOUPPER(s[++i]));
	putchar('\n');
	printf("I predicted it would output as \"0123\"\n");
}
