/* Show what the following program will look like after preprocessing. Some lines of the
program may cause compilation errors; find all such errors.
*/

#include <stdio.h>

#define N 10
#define INC(x) ((x)+1)
#define SUB(x,y) ((x)-(y))
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

void f(void);

int main (void)
{
	int i = 2, j = 4, k = 6;
#ifdef N
	i = j;	// i = 4
#else
	j = i;
#endif

	i = 10 * INC(j); // i = 40
	i = SUB(j,k); // i = -2
	i = SQR(SQR(j)); // = 256
	i = CUBE(j); // 64
//	i = M1(j,k); // Error
	printf(M2(i,j)"\n"); //  "24"

#undef SQR
//	i = SQR(j);  // Error
#define SQR
//	i = SQR(j);  // Error

	return 0;
}
