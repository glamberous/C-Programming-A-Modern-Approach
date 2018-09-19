/* Let f be the following function. What will be the value of f(10) if f has never been
called before? What will be the value of f(10) if f has been called five times previously? */

int f(int i)
{
	static int j = 0;
	return i * j++;
}

//Never called before f == 0

//Called 5 times before f == 50
