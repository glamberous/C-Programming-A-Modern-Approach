/* Improve the planet.c program of Section 13.7 by having it ignore case when comparing command-line
arguments with strings in the planets array. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

bool string_equal(char *, char *);

int main(int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
											"Saturn", "Uranus", "Neptune", "Pluto"};
	int i, j;

	for (i = 1; i < argc; i++)
	{
		for(j = 0; j < NUM_PLANETS; j++)
		{
			if (string_equal(argv[i], planets[j]))
			{
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}
		if (j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}
	return 0;
}

bool string_equal(char *input, char *planet)
{
	int i;

	for(i = 0; tolower(input[i]) == tolower(planet[i]); i++)
	{
		if (input[i] == '\0')
		{
			return true;
		}
	}
	return false;
}
