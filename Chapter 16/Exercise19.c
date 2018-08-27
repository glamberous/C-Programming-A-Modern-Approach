
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 40

struct pinball_machine {
	char name[MAX_LENGTH + 1];
	int year;
	enum {EM, SS} type;
	int players;
};

int main(void)
{
	struct pinball_machine one = {"Pinball wizard", 1996, EM, 4};

		printf("%d\n", one.year);
		printf("%s\n", one.name);
		printf("%d\n", one.players);
		printf("%d\n", one.type);
}
