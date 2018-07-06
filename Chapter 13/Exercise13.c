/* Write a build_index_url function */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

void build_index_url(const char *domain, char *index_url);

int main (void)
{
	const char website[STR_LENGTH] = "artoflamb.com";
	char index[STR_LENGTH];

	build_index_url(website, index);
	puts(index);
	putchar('\n');
}

void build_index_url(const char *domain, char *index_url)
{
	strcat(strcat(strcpy(index_url, "http://www."), domain), "/index.html");
}
