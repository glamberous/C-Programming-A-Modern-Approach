/* Modify Programming Project 6 from Chapter 10 so that it has seperate
stack.h and stack.c files. As described in Section 15.2. */

#include <stdio.h>			//printf / scanf
#include "Stack.h"

int contents[STACK_SIZE] = {0};
int top = 0;

int main(void)
{
	char ch = 0;
	int temp1 = 0, temp2 = 0;

	printf("Enter an RPN experession: ");

	do
	{
		scanf(" %c", &ch);

		if (ch >= '0' && ch <= '9')
		{
			ch = ch - '0';
			push((int)ch);
		}
		else if (ch == '+')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 + temp1;
			push(temp1);
		}
		else if (ch == '-')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 - temp1;
			push(temp1);
		}
		else if (ch == '*')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 * temp1;
			push(temp1);
		}
		else if (ch == '/')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 / temp1;
			push(temp1);
		}

	} while(ch != '=');

	printf("Value of expression: %d", pop());
}
