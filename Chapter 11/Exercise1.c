#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator







int main(void)
{
	int i, *p = &i, *q = &i;
	
	i = 10;
	
	printf("1. %d\n", *p);
	printf("2. %d\n", *&i);
	printf("3. %d\n", i);
	printf("4. %d\n", p);
	printf("5. %d\n", &i);
	//printf("6. %d\n", &*p);
	//printf("7. %d\n", &i);
	//printf("8. error\n");
	
	//valid assignments, remember i is an int, p & q are pointers:
	p = &i; // pointer to pointer
	*p = i;	// int to int
	p = q; // pointer of an int to a pointer of an int
	
}



