#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * duplicate(const char *);

int main (void)
{
	const char * str = "Bweep bwoop.\n";
	char * p;

	printf("str length: %d\n", (int)strlen(str));
	printf("str is: %s", str);
	p = duplicate(str);
	printf("p length: %d\n", (int)strlen(p));
	printf("p is: %s", p);

	free(p);

	char * str2 = "lubba dubba dub dub!\n";
	printf("p length: %d\n", (int)strlen(p));
	printf("p is: %s", p);
	return 0;
}

char * duplicate(const char *str)
{
	char *p;
	p = malloc(strlen(str)+ 1);

if (p != NULL)
	{
		strcpy(p, str);
		return p;
	}
else
	{
		printf("Allocation failed; take appropriate action.\n");
		exit(0);
	}
}
