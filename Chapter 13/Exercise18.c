/* Write the following function: void remove_filename(char *url) */


#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define true 1
#define false 0
#define STR_LENGTH 100

char *remove_filename(char *url);

int main (void)
{
	char s1[STR_LENGTH] = "http://www.knking.com/index.html";

	puts(remove_filename(s1));

	return 0;
}

char *remove_filename(char *url)
{
	int i = strlen(url);

	while(url[--i] != '/')
	/* intentionally null */;
	url[i] = '\0';

	return url;
}
