/* create a program that will convert total seconds into hour, min, second format */
// 26400 = 7:20am

#include <stdio.h>
#include <stdbool.h>

struct point
{
	int x, y;
};

struct rectangle
{
	struct point upper_left, lower_right;
};

int area(struct rectangle);
struct point center(struct rectangle);
struct rectangle move(struct rectangle, int, int);
bool lies_within(struct point, struct rectangle);

int main(void)
{
	struct rectangle r1 = {{120, 100}, {625, 200}};
	struct point p1 = {500, 250};
	struct point temp = {1, 1};

	printf("Area of r1: %d\n", area(r1));

	temp = center(r1);
	printf("Center of r1: %d, %d\n", temp.x, temp.y);

	r1 = move(r1, 100, 100);
	printf("r1.upper_left.x: %d\nr1.upper_left.y: %d\nr1.lower_right.x: %d\nr1.lower_right.y:%d\n",
	r1.upper_left.x, r1.upper_left.y, r1.lower_right.x, r1.lower_right.y);

	if(lies_within(p1, r1))
		printf("p1 is within r1.\n");
	else
		printf("p1 is not within r1.\n");
}

int area(struct rectangle r)
{
	r.lower_right.x -= r.upper_left.x;
	r.upper_left.x -= r.upper_left.x;

	r.lower_right.y -= r.upper_left.y;
 	r.upper_left.y -= r.upper_left.y;

	return r.lower_right.x * r.lower_right.y;
}

struct point center(struct rectangle r)
{
	r.upper_left.x = ((r.upper_left.x + r.lower_right.x) / 2);
	r.upper_left.y = ((r.upper_left.y + r.lower_right.y) / 2);

	return r.upper_left;
}

struct rectangle move(struct rectangle r, int x, int y)
{
	r.upper_left.x += x;
	r.lower_right.x += x;
	r.upper_left.y += y;
	r.lower_right.y += y;

	return r;
}

bool lies_within(struct point p, struct rectangle r)
{
	return (p.x > r.upper_left.x && p.x < r.lower_right.x && p.y > r.upper_left.y && p.y < r.lower_right.y);
}
