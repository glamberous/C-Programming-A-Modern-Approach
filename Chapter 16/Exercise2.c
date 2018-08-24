/* Learning how to initialize structures */

#include <stdio.h>

int main(void)
{
	struct imagi_real
	{
		double real;
		double imaginary;
	}
	c1 = {0.0, 1.0},
	c2 = {1.0, 0.0},
	c3;

	c1 = c2;
	c3.real = c2.real + c1.real;
	c3.imaginary = c2.imaginary + c3.imaginary;

	printf("c1.real: %f\tc2.real: %f\tc3.real: %f\n", c1.real, c2.real, c3.real);
	printf("c1.imaginary: %f\tc2.imaginary: %f\tc3.imaginary: %f\n",
	c1.imaginary, c2.imaginary, c3.imaginary);

	struct imagi_real c4 = {0.0, 1.1};

	printf("c4.real: %f\tc4.imaginary: %f\n", c4.real, c4.imaginary);

	return 0;
}
