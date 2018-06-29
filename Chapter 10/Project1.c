#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define STACK_SIZE 100

char contents[STACK_SIZE] = {0};
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);
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

void push(char ch)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = ch;
}

char pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow. Terminating program.");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	printf("Parentheses/braces are not nested properly");
	exit(EXIT_SUCCESS);
}

int main(void)
{
	char temp = 0;
	
	printf("Enter parentheses and/or braces: ");
	while (temp != '\n')
	{
		temp = getchar();
		
		if(temp == '(' || temp == '{')
			push(temp);
		else if(temp == ')')
		{
			temp = pop();
			if (temp != '(')
			{
				printf("Parentheses/braces are not nested properly");
				exit(EXIT_SUCCESS);
			}
		}
		else if(temp == '}')
		{
			temp = pop();
			if (temp != '{')
			{
				printf("Parentheses/braces are not nested properly");
				exit(EXIT_SUCCESS);
			}
		}
	}
	printf("Parentheses/braces are nested properly.");
	exit(EXIT_SUCCESS);
}
