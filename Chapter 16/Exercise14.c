
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define RECTANGLE 1
#define CIRCLE 2

struct point
{
	int x, y;
};

struct shape
{
	int shape_kind;
	struct point center;
	union
	{
		struct
		{
			int height, width;
		}	rectangle;
		struct
		{
			int radius;
		} circle;
	} u;
};

int area(struct shape s);
struct shape move(struct shape s, int x, int y);
struct shape scale(struct shape s, int c);

int main(void)
{
	struct shape s1 = {RECTANGLE, {150, 150}, .u.rectangle.height = 50, .u.rectangle.width = 60};
	struct shape s2 = {CIRCLE, {150, 150}, .u.circle.radius = 40};

	printf("Area of s1 is: %d\n", area(s1));
	printf("Area of s2 is: %d\n", area(s2));
	printf("Center point of s1: %d, %d\n", s1.center.x, s1.center.y);

	s1 = move(s1, 30, 45);
	s1 = scale(s1, 3);

	printf("Area of s1 after scaling: %d\n", area(s1));
	printf("Center point of s1 after moving it: %d, %d\n", s1.center.x, s1.center.y);

	return 0;
}

int area(struct shape s)
{
	if (s.shape_kind == RECTANGLE)
	{
		return (s.u.rectangle.height * s.u.rectangle.width);
	}
	else if(s.shape_kind == CIRCLE)
	{
		return ((s.u.circle.radius * 2) * M_PI);
	}
	else
		return 0;
}

struct shape move(struct shape s, int x, int y)
{
	s.center.x += x;
	s.center.y += y;

	return s;
}

struct shape scale(struct shape s, int c)
{
	if (s.shape_kind == RECTANGLE)
	{
		s.u.rectangle.height *= c;
		s.u.rectangle.width *= c;
		return s;
	}
	else if(s.shape_kind == CIRCLE)
	{
		s.u.circle.radius *= c;
		return s;
	}
	else
		return s;
}
