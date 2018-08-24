/* Learning how to initialize structures again! */

#include <stdio.h>

typedef struct
{
	double real;
	double imaginary;
} complex;

complex add_complex(complex, complex);
complex make_complex(double, double);

int main(void)
{

	complex c1, c2, c3;

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

complex make_complex(double x, double y)
{
	complex p;

	p.real = x;
	p.imaginary = y;

	return p;
}

complex add_complex(complex x, complex y)
{
	complex z;

	z.real = x.real + y.real;
	z.imaginary = x.imaginary + y.imaginary;

	return z;
}
