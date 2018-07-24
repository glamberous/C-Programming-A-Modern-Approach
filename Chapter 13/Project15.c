/*
Modify Programming project 6 from chapter 10 so that it includes the following
function:
int evaluate_RPN_expression(const char *expression);
The function returns the value of the RPN expression pointed to by expression.
*/
#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <ctype.h>

#define STACK_MAX 100
#define STR_MAX 100

int contents[STACK_MAX] = {0};
int top = 0;

int evaluate_RPN_expression(const char *expression);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int num);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);


int main(void)
{
	char str[STR_MAX + 1] = {'\0'};

	printf("Enter an RPN experession: ");
	fgets(str, STR_MAX, stdin);
	printf("Value of expression: %d\n", evaluate_RPN_expression(str));
}

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
	return top == STACK_MAX;
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
	return 0;
}

void stack_overflow(void)
{
	printf("Expression is too complex\n");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
	exit(EXIT_SUCCESS);
}

int evaluate_RPN_expression(const char *expression)
{
	int temp1 = 0, temp2 = 0, i = 0;

	for(i = 0; expression[i] != '='; i++)
	{
		if(expression[i] == ' ')
		{
			continue;
		}
		else if (isdigit(expression[i]))
		{
			push((int)expression[i] - '0');
		}
		else if (expression[i] == '+')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 + temp1;
			push(temp1);
		}
		else if (expression[i] == '-')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 - temp1;
			push(temp1);
		}
		else if (expression[i] == '*')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 * temp1;
			push(temp1);
		}
		else if (expression[i] == '/')
		{
			temp1 = pop();
			temp2 = pop();
			temp1 = temp2 / temp1;
			push(temp1);
		}
	}
	return pop();
}
