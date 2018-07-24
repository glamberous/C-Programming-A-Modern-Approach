/*
Write a macro DISP(f,x) that expands into a call of printf that displays the
value of the function f when called with argument x. For example,
DISP(sqrt, 3.0);
should expand into
printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));
*/

#define DISP(f,y) printf("sqrt(%g) = %g\n", y, f(y))
#define DISP2(x,y,f) printf("sqrt(%s,%s) ", x, y); printf("= %s\n", f(x,y))

#include <string.h>
#include <stdio.h>

#define STR_MAX 5

int main (void)
{
	float y = 9;
	char str1[6] = {"B"}, str2[6] = {"leep"};

	DISP(sqrt,y);
	DISP2(str1, str2, strcat);
}
