/* create a program that will convert total seconds into hour, min, second format */
// 26400 = 7:20am

#include <stdio.h>
#include <stdbool.h>

struct color
{
	int red;
	int green;
	int blue;
};

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(void)
{
	const struct color MAGENTA = {255, .blue = 255};

	struct color puke, vomit, bile;

	puke = make_color(220, 205, 130);
	vomit = make_color(200, 150, 130);
	bile = make_color(240, 30, 60);

	printf("MAGENTA: %d, %d, %d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);
	printf("Puke: %d, %d, %d\n", getRed(puke), puke.green, puke.blue);
	printf("Vomit: %d, %d, %d\n", getRed(vomit), vomit.green, vomit.blue);
	printf("Bile: %d, %d, %d\n", getRed(bile), bile.green, bile.blue);

	if(equal_color(puke, vomit))
	{
		printf("Puke is an equal color to vomit.\n");
	}
	else
	{
		printf("Puke is not an equal color to vomit.\n");
	}

	bile = brighter(bile);
	printf("Brightened Bile: %d, %d, %d\n", getRed(bile), bile.green, bile.blue);

	puke = darker(puke);
	printf("Darkened Puke: %d, %d, %d\n", getRed(puke), puke.green, puke.blue);
}

struct color make_color(int red, int green, int blue)
{
	if(red < 0)
		red = 0;
	else if(red > 255)
		red = 255;

	if(green < 0)
		green = 0;
	else if (green > 255)
		green = 255;

	if(blue < 0)
		blue = 0;
	else if(blue > 255)
		blue = 255;

	struct color x = {red, green, blue};
	return x;
}

int getRed(struct color c)
{
	return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
	if (color1.red != color2.red)
		return 0;
	if (color1.green != color2.green)
		return 0;
	if (color1.blue != color2.blue)
		return 0;
	return 1;
}

struct color brighter(struct color c)
{
	const float brighter = 0.7;

	if (c.red == 0 && c.green == 0 && c.blue == 0)
	{
		c.red = 3; c.green = 3; c.blue = 3;
		return c;
	}
	else
	{
		if (c.red < 3)
			c.red = 3;

		if (c.green < 3)
			c.green = 3;

		if (c.blue < 3)
			c.blue = 3;

		c.red /= brighter;
		c.green /= brighter;
		c.blue /= brighter;

		if (c.red > 255)
			c.red = 255;

		if (c.green > 255)
			c.green = 255;

		if (c.blue > 255)
			c.blue = 255;

		return c;
	}
}

struct color darker(struct color c)
{
	const float darker = 0.7;
	c.red *= darker;
	c.green *= darker;
	c.blue *= darker;

	return c;
}
