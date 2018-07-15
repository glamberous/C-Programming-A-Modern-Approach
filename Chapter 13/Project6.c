/* Improve the planet.c program of Section 13.7 by having it ignore case when comparing command-line
arguments with strings in the planets array. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
											"Saturn", "Uranus", "Neptune", "Pluto"};
	char argv_temp[100] = {""}, planets_temp[9] = {""};
	int i, j, x;

	for (i = 1; i < argc; i++)
	{
		for(x = 0; argv[i][x] != '\0'; x++)
		{
			argv_temp[x] = tolower(argv[i][x]);
		}

		for(j = 0; j < NUM_PLANETS; j++)
		{
			for(x = 0; planets[j][x] != '\0'; x++)
			{
				planets_temp[x] = tolower(planets[i][x]);
			}

			if (strcmp(argv_temp, planets_temp) == 0)
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
