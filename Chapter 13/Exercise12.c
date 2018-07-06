/* Write a get_extension function */

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define STR_LENGTH 100

void get_extension(const char *file_name, char *extension);

int main (void)
{
	const char file[STR_LENGTH] = "File.exe";
	char extension[STR_LENGTH];

	get_extension(file, extension);
	puts(extension);
	putchar('\n');
}

void get_extension(const char *file_name, char *extension)
{
	int i = strlen(file_name);

	while(file_name[i] != '.')
	{
		if (i == 0)
		{
			strcpy(extension, "");
			return;
		}
		i--;
	}

	strcpy(extension, &file_name[i + 1]);

	return;
}
