/* shifts characters by an amount stated by the user */

/*
Modify Programming Project 15 from Chapter 8 so that the program prompts the user
to enter the name of a file containing the message to be encrypted:
Enter name of file to be encrypted: message.txt
Enter shift amount (1-25): 3
The program then writes the encrypted message to a file with the same name but
an added extension of .enc. In this example, the original file name is message.txt,
so the encrypted message will be stored in a file named message.txt.enc. There's
no limit on the size of the file to be encrypted or on the length of each line in
the file.
*/

#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *msg = NULL, *enc_msg = NULL;
	if ((msg = fopen(argv[1], "rb")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

	char filename_enc[strlen(argv[1]) + 4];
	strcpy(filename_enc, argv[1]);
	strcat(filename_enc, ".enc");

	if ((enc_msg = fopen(filename_enc, "wb")) == NULL) {
    printf("%s can't be opened\n", filename_enc);
    exit(EXIT_FAILURE);
  }

	int shift = 0;
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	printf ("Outputted encrypted message to file %s\n", filename_enc);

	int ch = 0;
	for(ch = fgetc(msg); ch != EOF; ch = fgetc(msg))
	{
		if (ch >= 'A' && ch <= 'Z')
			fputc(((ch - 'A') + shift) % 26 + 'A', enc_msg);
		else if(ch >= 'a' && ch <= 'z')
			fputc(((ch - 'a') + shift) % 26 + 'a', enc_msg);
		else
			fputc(ch, enc_msg);
	}

	return (0);
}
