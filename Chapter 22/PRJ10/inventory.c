/*
Modify the inventory2.c program of Section 17.5 by adding the d (dump) and r
(restore) operations described in Programming Project 8. Since the part structures
aren't stored in an array, the d operation can't save them all by a single call of
fwrite. Instead, it will need to visit each node in the linked list. Writing the
part number, part name, and quantity on hand to a file. (Don't save the next
pointer, it won't be valid once the program terminates.) As it reads parts from a
file, the r operation will rebuild the list one node at a time.
*/

//Maintains a parts database (linked list version)

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

int main(void)
{
	char code;

	for(;;)
	{
		printf("enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n');
		switch (code)
		{
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'p': print(); break;
			case 'd': dump(); break;
			case 'r': restore(); break;
			case 'q': return 0;
			default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

struct part *find_part(int number)
{
	struct part *p;

	for (p = inventory; p != NULL && number > p->number; p = p->next);

	if(p != NULL && number == p->number)
		return p;
	return NULL;
}

void insert(void)
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if (new_node == NULL)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);

	for(cur = inventory, prev = NULL;
		cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next);

	if(cur != NULL && new_node->number == cur->number)
	{
		printf("Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);

	new_node->next = cur;
	if(prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

void search(void)
{
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL)
	{
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d]n", p->on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	struct part *p;

	printf("Part Number Part Name           "
				 "Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%11d %-25s%11d\n", p->number, p->name, p->on_hand);
}

void dump(void)
{
	FILE *savefile = NULL;
	const char *filename = "inventory.dat";
	struct part *p = NULL;

	if ((savefile = fopen(filename, "wb")) == NULL)
  {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }

	for(p = inventory; p != NULL ; p = p->next)
	{
		fwrite(&p->number, sizeof(p->number), 1, savefile);
		fwrite(p->name, NAME_LEN, 1, savefile);
		fwrite(&p->on_hand, sizeof(p->on_hand), 1, savefile);
	}

	printf("Successfully saved to %s\n", filename);
	fclose(savefile);
}

void restore(void)
{
	struct part *cur, *prev, *new_node;
	int ch = 0;
	FILE *savefile = NULL;
	const char *filename = "inventory.dat";

	if ((savefile = fopen(filename, "rb")) == NULL)
  {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }

	for(ch = fgetc(savefile); ch != EOF; ch = fgetc(savefile))
	{
		ungetc(ch, savefile);

		new_node = malloc(sizeof(struct part));
		if (new_node == NULL)
		{
			printf("Database is full; can't add more parts.\n");
			return;
		}

		fread(&new_node->number, sizeof(new_node->number), 1, savefile);

		for(cur = inventory, prev = NULL;
			cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next);

		if(cur != NULL && new_node->number == cur->number)
		{
			printf("Part already exists.\n");
			free(new_node);
			return;
		}

		fread(new_node->name, NAME_LEN, 1, savefile);
		fread(&new_node->on_hand, sizeof(new_node->on_hand), 1, savefile);

		new_node->next = cur;
		if(prev == NULL)
			inventory = new_node;
		else
			prev->next = new_node;
	}
	fclose(savefile);
}
