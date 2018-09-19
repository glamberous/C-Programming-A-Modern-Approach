/* a) Write a complete description of the type of the function f. assuming that it's
declared as follows: */

int (*f(float (*)(long), char *))(double);
/*
f is a function with two arguments
argument 1: a pointer to a function with argument long and returns a float
argument 2: a char pointer (possibly a string literal)
that returns a pointer to a function with a double argument and returns an int
*/

// b) Give and example showing how f would be called.

take_shot(random_num_gen_2, soldier_name)(hit_chance())
/* function take_shot which calls a random number generator (2) that calls current time
for a seed (long).
Second iteration because it's programmed in a way that shows the user may want to change it.
Needs a string of the soldier name taking a shot in order to output "Jimmy" takes a shot.
Needs a double to determine
the hit percent chance.
Compares the random number generator result with the double hit percent chance then
outputs 1 or 0 depending on if the attack hits
*/
