/* a) Which of these following declarations are legal? (Assume PI is a macro
that represents 3.14159.) */

#define PI 3.14159

char c = 65; //a) Legal but gives a warning

static int i = 5, j = i * i; //b) Illegal

double d = 2 * PI; //c) Legal

double angles[] = {0, PI / 2, PI, 3 * PI / 2}; //d) Legal

int main(void)
{
	return 0;
}
