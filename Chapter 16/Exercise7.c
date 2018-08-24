/* create a program that will convert total seconds into hour, min, second format */
// 26400 = 7:20am

#include <stdio.h>

struct fraction
{
	int num;
	int denom;
};

//int GCD(struct fraction);
struct fraction reduce(struct fraction);
struct fraction add(struct fraction, struct fraction);
struct fraction subtract(struct fraction, struct fraction);
struct fraction multiply(struct fraction, struct fraction);
struct fraction divide(struct fraction, struct fraction);

int main(void)
{
	struct fraction f, f1, f2;

	printf("Enter a numerator: ");
 	scanf("%d", &f1.num);
	printf("Enter a denominator: ");
	scanf("%d", &f1.denom);

	printf("Enter another numerator: ");
 	scanf("%d", &f2.num);
	printf("Enter another denominator: ");
	scanf("%d", &f2.denom);

 	f = reduce(f1);
	printf("Reduced fraction (f1): %d/%d\n", f.num, f.denom);
	f = reduce(f2);
	printf("Reduced fraction (f2): %d/%d\n", f.num, f.denom);

	f = add(f1, f2);
	printf("Fractions added: %d/%d\n", f.num, f.denom);

	f = subtract(f1, f2);
	printf("Fractions subtracted: %d/%d\n", f.num, f.denom);

	f = multiply(f1, f2);
	printf("Fractions multiplied: %d/%d\n", f.num, f.denom);

	f = divide(f1, f2);
	printf("Fractions divided: %d/%d\n", f.num, f.denom);
}

/*
int GCD(struct fraction x)
{

}
*/

struct fraction reduce(struct fraction x)
{
	int i, GCD = 1;

	for(i = 1; i <= (x.num / 2) || i <= (x.denom / 2); i++)
		if(x.num % i == 0 && x.denom % i == 0)
			GCD = i;

	x.num /= GCD;
	x.denom /= GCD;

	return x;
}


struct fraction add(struct fraction x, struct fraction y)
{
	x.num *= y.denom;
	y.num *= x.denom;
	x.denom *= y.denom;
	y.denom = x.denom;

	x.num += y.num;
	return reduce(x);
}


struct fraction subtract(struct fraction x, struct fraction y)
{
	x.num *= y.denom;
	y.num *= x.denom;
	x.denom *= y.denom;
	y.denom = x.denom;

	x.num -= y.num;
	return reduce(x);
}

struct fraction multiply(struct fraction x, struct fraction y)
{
	x.num *= y.num;
	x.denom *= y.denom;
	return reduce(x);
}

struct fraction divide(struct fraction x, struct fraction y)
{
	int temp = 0;

	temp = y.num;
	y.num = y.denom;
	y.denom = temp;
	return multiply(x, y);
}
