/* Maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct {
		int dollars;
		int cents;
	} price;
};

int find_part(int number, struct part inventory[MAX_PARTS], int num_parts);
void insert(struct part inventory[MAX_PARTS], int *num_parts);
void search(struct part inventory[MAX_PARTS], int num_parts);
void update(struct part inventory[MAX_PARTS], int num_parts);
void print(struct part inventory[MAX_PARTS], int num_parts);
void update_price(struct part inventory[MAX_PARTS], int num_parts);

int main(void)
{
	struct part inventory[MAX_PARTS];
	int num_parts = 0;
	char code;
	for (;;)
	{
		printf("Enter operation code: ");
		scanf(" %c", &code);
		switch (code)
		{
			case 'i': insert(inventory, &num_parts); break;
			case 's': search(inventory, num_parts); break;
			case 'u': update(inventory, num_parts); break;
			case 'p': print(inventory, num_parts); break;
			case '$': update_price(inventory, num_parts); break;
			case 'q': return 0;
			default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

int find_part(int number, struct part inventory[MAX_PARTS], int num_parts)
{
	int i;

	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(struct part inventory[MAX_PARTS], int *num_parts)
{
	int part_number, i, j;

	if (*num_parts == MAX_PARTS)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number, inventory, *num_parts) >= 0)
	{
		printf("Part already exists.\n");
		return;
	}

	for(i = 0; i < *num_parts; i++)
	{
		if(inventory[i].number > part_number)
			break;
	}

	for(j = *num_parts; j > i; j--)
	{
		inventory[j] = inventory[j - 1];
	}
	inventory[i].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[i].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[i].on_hand);
	while (getchar() != '\n')
	/*intentionally null*/;
	printf("Enter the price for the part: ");
	scanf("$%d.%d", &inventory[i].price.dollars, &inventory[i].price.cents);
	while (getchar() != '\n')
	/*intentionally null*/;
	(*num_parts)++;
}

void search(struct part inventory[MAX_PARTS], int num_parts)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, inventory, num_parts);
	if (i >= 0)
	{
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
		printf("Part Price: %d.%.2d\n", inventory[i].price.dollars, inventory[i].price.cents);
	}
	else
		printf("Part not found.\n");
}

void update(struct part inventory[MAX_PARTS], int num_parts)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	while (getchar() != '\n')
	/*intentionally null*/;
	i = find_part(number, inventory, num_parts);
	if (i >= 0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void update_price(struct part inventory[MAX_PARTS], int num_parts)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	while (getchar() != '\n')
	/*intentionally null*/;
	i = find_part(number, inventory, num_parts);
	if (i >= 0)
	{
		printf("Enter the new price (example: $10.50): ");
		scanf("$%d.%d", &inventory[i].price.dollars, &inventory[i].price.cents);
	}
	else
		printf("Part not found.\n");
}

void print(struct part inventory[MAX_PARTS], int num_parts)
{
	int i;

	printf("Part Number		Part Name			    Quantity on Hand		Price\n");
	for (i = 0; i < num_parts; i++)
		printf("    %7d		%-25s %11d\t\t\t\t$%d.%.2d\n", inventory[i].number,
		inventory[i].name, inventory[i].on_hand, inventory[i].price.dollars,
		inventory[i].price.cents);
}
