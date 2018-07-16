/*
Modify Programming Project 15 from Chapter 8 so that it includes
the following function:
void encrypt(char *message, int shift);
The function expects message to point to a string containing the
message to be encrypted; shift represents the amount by which
each letter in the message is to be shifted
*/

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_MAX 100

void encrypt(char *message, int shift);

int main(void)
{
	char str[STR_MAX] = {'\0'};
	int shift = 0;


	printf ("Enter message to be encrypted: ");
	fgets(str, STR_MAX, stdin);

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	encrypt(str, shift);

	printf ("Encrypted message: %s", str);

	return (0);
}

void encrypt(char *message, int shift)
{
	int i = 0;

	for(i = 0; message[i] != '\0'; i++)
	{
		if (isupper(message[i]))
			message[i] = (((message[i] - 'A') + shift) % 26 + 'A');
		else if(islower(message[i]))
			message[i] = (((message[i] - 'a') + shift) % 26 + 'a');
	}
}
