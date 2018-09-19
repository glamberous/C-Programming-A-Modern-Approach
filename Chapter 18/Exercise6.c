#include <stdio.h>

void print_error(const char *);

int main(void)
{
	const char *str1 = "Koda", *str2 = "Gizmo";

	print_error(str1);
	print_error(str2);
}

void print_error(const char *message)
{
	static int n = 1;
	printf("Error %d: %s\n", n++, message);
}
