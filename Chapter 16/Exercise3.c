/* Learning how to initialize structures again! */

#include <stdio.h>

struct complex
{
	double real;
	double imaginary;
};

struct complex add_complex(struct complex x, struct complex y);
struct complex make_complex(double x, double y);

int main(void)
{

	struct complex c1, c2, c3;

	c1 = make_complex(1.0, 1.5);
	c2 = make_complex(1.1, 1.6);
	c3 = make_complex(1.2, 1.7);

	printf("c1.real: %f\tc2.real: %f\tc3.real: %f\n", c1.real, c2.real, c3.real);
	printf("c1.imaginary: %f\tc2.imaginary: %f\tc3.imaginary: %f\n", c1.imaginary,
	 c2.imaginary, c3.imaginary);

	c3 = add_complex(c1, c2);

	printf("c1.real: %f\tc2.real: %f\tc3.real: %f\n", c1.real, c2.real, c3.real);
	printf("c1.imaginary: %f\tc2.imaginary: %f\tc3.imaginary: %f\n", c1.imaginary,
	 c2.imaginary, c3.imaginary);

	return 0;
}

struct complex make_complex(double x, double y)
{
	struct complex p;

	p.real = x;
	p.imaginary = y;

	return p;
}

struct complex add_complex(struct complex x, struct complex y)
{
	struct complex z;

	z.real = x.real + y.real;
	z.imaginary = x.imaginary + y.imaginary;

	return z;
}
