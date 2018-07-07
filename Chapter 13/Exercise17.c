/* Write the following function (test_extention) */


#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat

#define true 1
#define false 0
#define STR_LENGTH 100

void get_extension(const char *file_name, char *extension);
int test_extension(const char *file_name, const char *extension);

int main (void)
{
	char s1[STR_LENGTH] = "test.exe", s2[STR_LENGTH] = "EXe";

	if(test_extension(s1, s2))
		printf("true");
	else
		printf("false");

	return 0;
}

int test_extension(const char *file_name, const char *extension)
{
	char temp[STR_LENGTH];
	int i = 0;

	get_extension(file_name, temp);
	while(temp[i++])
		if(toupper(temp[i]) != toupper(extension[i]))
			return false;

	return true;
}

void get_extension(const char *file_name, char *extension)
{
	int i = strlen(file_name);

	while(file_name[i--] != '.')
	{
		if (i == 0)
		{
			strcpy(extension, "");
			return;
		}
	}
	strcpy(extension, &file_name[i + 2]);
	return;
}
