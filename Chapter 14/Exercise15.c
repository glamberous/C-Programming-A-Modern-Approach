/*
Suppose that a program needs to display messages in either English, French, or Spanish.
Using conditional compilation, write a program fragment that displays one of the following
three messages, depending on whether or not the specified macro is defined
*/

#include <stdio.h>

//#define ENGLISH

int main (void)
{
#if defined(SPANISH)
printf("Inserte El Disco 1\n");

#elif defined(FRENCH)
printf("Inserez Le Disque 1\n");

#elif defined(ENGLISH)
printf("Insert Disk 1\n");

#else
printf("Language not defined.\n");
#endif

	return 0;
}
