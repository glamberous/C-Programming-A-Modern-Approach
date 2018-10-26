/*
Project 8: Modify the inventory.c program of Section 16.3 by adding two new operations:
- Save the database in a specified file.
- Load the database from a specified file.
Use the codes d (dump) and r (restore), respectively, to represent these operations.
The interaction with the user should have the following appearance:
Enter operation code: d
Enter name of output file: inventory.dat

Enter operation code: r
Enter name of input file: inventory.dat

Hint: use fwrite to write the array containing the parts to a binary file. Use
fread to restore the array by reading it from a file.

--------------------------------------------------------------------------------

Project 9: Write a program that merges two files containing part records stored
by the inventory.c program(See programming project 8). Assume that the records
in each file are sorted by part number, and that we want the resulting file to be
stored as well. If both files have a part with the same number, combine the
quantities stored in the records. (As a consistency check, have the program compare
part names and have the program print an error message if they don't match.) Have
the program obtain names of the input files and merged file from the command line.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct money {
	int dollars;
	int cents;
};

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct money price;
};

void open_savefile(FILE *, const char *);
int choose_operation(const char *filename);
int find_part(int number);
int is_full(void);
int get_number(void);
void get_name(char *name);
int get_quantity(void);
struct money get_price(void);
void insert_merge(struct part *new_part);
void insert_stdin(void);
void insert(struct part *new_part);
void search(void);
void update(void);
void print(void);
void update_price(void);
void dump(const char *);
void restore(FILE *);
int (*sortp)(const void *v1, const void * v2);
int sort_inventory(const void *v1, const void * v2);

static struct part inventory[MAX_PARTS];
static int num_parts = 0;

int main(int argc, char *argv[])
{
	FILE *savefile = NULL;
	open_savefile(savefile, argv[1]);

	//printf("%d\n", num_parts);
	//sortp = sort_inventory;
	while(choose_operation(argv[1]));
}

void open_savefile(FILE *savefile, const char *filename)
{
	if ((savefile = fopen(filename, "rb")) == NULL)
  {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }

	restore(savefile);
}

int choose_operation(const char *filename)
{
	char code;
	printf("Enter operation code: ");
	scanf(" %c", &code);
	switch (code)
	{
		case 'i': insert_stdin(); return 1;
		case 's': search(); return 1;
		case 'u': update(); return 1;
		case 'p': print(); return 1;
		case '$': update_price(); return 1;
		case 'd': dump(filename); return 1;
		//case 'r': restore(); return 1;
		case 'q': dump(filename); return 0;
		default: printf("Illegal code\n"); return 1;
	}
	printf("\n");
}

int find_part(int number)
{
	int i;

	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

int is_full(void)
{
	if (num_parts == MAX_PARTS)
	{
		printf("Database is full; can't add more parts.\n");
		return 1;
	}
	return 0;
}

int get_number(void)
{
	int number;

	printf("Enter part number: ");
	scanf("%d", &number);
	return number;
}

void get_name(char *name)
{
	printf("Enter part name: ");
	read_line(name, NAME_LEN);

	return;
}

int get_quantity(void)
{
	int quantity = 0;

	printf("Enter quantity on hand: ");
	scanf("%d", &quantity);

	return quantity;
}

struct money get_price(void)
{
	struct money price;

	printf("Enter the price for the part: ");
	scanf("$%d.%d", &price.dollars, &price.cents);

	printf("%d.%d\n", price.dollars, price.cents);
	return price;
}

//gathers part info from file
void insert_merge(struct part *new_part)
{
	if(is_full())
		return;

	int dupe_num = 0;
	dupe_num = find_part(new_part->number);

	if (dupe_num >= 0)
	{
		if(strcmp(new_part->name, inventory[dupe_num].name) != 0)
			printf("Unnable to merge %s (part %d)\n", new_part->name, new_part->number);
		else
			inventory[dupe_num].on_hand += new_part->on_hand;
	}
	else
		insert(new_part);
}

//gathers part info from stdin
void insert_stdin(void)
{
	if(is_full())
		return;

	struct part new_part;

	new_part.number = get_number();
	if (find_part(new_part.number) >= 0)
	{
		printf("Part already exists.\n");
		return;
	}

	get_name(new_part.name);

	new_part.on_hand = get_quantity();
	while (getchar() != '\n');

	new_part.price = get_price();
	while (getchar() != '\n');

	insert(&new_part);
}

void insert(struct part *new_part)
{
	int i, j;

	for(i = 0; i < num_parts; i++) {
		if(new_part->number < inventory[i].number)
			break;
	}

	for(j = num_parts; j > i; j--)
		inventory[j] = inventory[j - 1];

	inventory[i] = *new_part;
	num_parts++;
	//qsort(inventory, num_parts, sizeof(inventory[0]), sortp);
}

void search(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
		printf("Part Price: %d.%.2d\n", inventory[i].price.dollars, inventory[i].price.cents);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	while (getchar() != '\n')
	/*intentionally null*/;
	i = find_part(number);
	if (i >= 0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void update_price(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	while (getchar() != '\n')
	/*intentionally null*/;
	i = find_part(number);
	if (i >= 0)
	{
		printf("Enter the new price (example: $10.50): ");
		scanf("$%d.%d", &inventory[i].price.dollars, &inventory[i].price.cents);
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	int i;

	printf("Part Number		Part Name			    Quantity on Hand		Price\n");
	for (i = 0; i < num_parts; i++)
		printf("    %7d		%-25s %11d\t\t\t\t$%d.%.2d\n", inventory[i].number,
		inventory[i].name, inventory[i].on_hand, inventory[i].price.dollars,
		inventory[i].price.cents);
}

void dump(const char *filename)
{
	FILE *savefile = NULL;

  if ((savefile = fopen(filename, "wb")) == NULL)
  {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }

	fwrite(inventory, sizeof(inventory[0]), num_parts, savefile);

	fclose(savefile);
	return;
}

void restore(FILE *fp)
{
	if(num_parts == 0)
		num_parts = fread(inventory, sizeof(inventory[0]), sizeof(inventory) / sizeof(inventory[0]), fp);
	else
	{
		struct part temp_inventory[MAX_PARTS];
		int merge_parts = 0, i = 0;
		merge_parts = fread(temp_inventory, sizeof(inventory[0]), sizeof(inventory) / sizeof(inventory[0]), fp);
		for(i = 0; i < merge_parts; i++)
			insert_merge(&temp_inventory[i]);
	}

	fclose(fp);
	//qsort(inventory, num_parts, sizeof(inventory[0]), sortp);
	return;
}

int sort_inventory(const void *v1, const void * v2)
{
	const struct part *s1 = v1;
	const struct part *s2 = v2;
	return s1->number > s2->number ? 1 : 0;
}
