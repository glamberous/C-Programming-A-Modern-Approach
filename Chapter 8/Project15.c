/* Takes a sentence and reverses it */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{	
	char ch[80] = {0};
	short i = 0, n = 0, x = 0;;
	
	
	printf ("Enter message to be encrypted: ");
	
	ch[i] = getchar();
	
	while(ch[i] != '\n')
	{
		ch[++i] = getchar();
		x++;
	}

	printf("Enter shift amount (1-25): ");
	scanf("%hd", &n);
	
	printf ("Encrypted message: ");
	
	for(i = 0; i < x; i++)
	{
		if (ch[i] >= 'A' && ch[i] <= 'Z')
			putchar(((ch[i] - 'A') + n) % 26 + 'A');
		else if(ch[i] >= 'a' && ch[i] <= 'z')
			putchar(((ch[i] - 'a') + n) % 26 + 'a');
		else
			putchar(i);
		
	}
	
	
	return (0);
}