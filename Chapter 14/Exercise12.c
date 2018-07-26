
//Suppose that the macro M has been defined as follows:
#define M 10

//Which of the following tests will fail?
//#if M //Pass
//#ifdef M //Pass
//#ifndef M //Fail
//#if defined(M) //Pass
//#if !defined(M) //Fail


#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
	#if M
	printf("It passed!\n");
	return 0;
	#endif
	printf("It didn't pass.\n");
	return 0;
}
