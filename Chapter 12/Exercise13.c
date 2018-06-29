#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define N 5

void identity_matrix(double ident[][N]);
void print_matrix(double ident[][N]);

int main (void)
{
	double ident[N][N];
	

	identity_matrix(ident);
	print_matrix(ident);
}

void identity_matrix(double ident[][N])
{
	double *p;
	int count = N;
	
	for(p = ident[0]; p <= ident[N-1] + (N-1); p++)
	{
		if (count == N)
		{
			*p = 1.0;
			count = 0;
		}
		else
		{
			*p = 0.0;
			count++;
		}
	}
}

void print_matrix(double ident[][N])
{
	double *p;
	int count = 0;
	
	for(p = ident[0]; p <= ident[N-1] + (N-1); p++)
	{
		printf("%.2f\t", *p);
		if (count == N - 1)
		{
			printf("\n");
			count = 0;
		}
		else
		{
			count++;
		}
	}
}

