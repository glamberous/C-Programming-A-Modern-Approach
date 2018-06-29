#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define STACK_SIZE 100

int contents[STACK_SIZE] = {0};
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int num);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return (top == 0);
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int num)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = num;
}

int pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Expression is too complex");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression");
	exit(EXIT_SUCCESS);
}

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
