
/*
Write a program that formats product information entered by the user. A session
with the program should look like this:
Enter item number: 583
Enter Unit price: 13.5
Enter Purchase date (mm/dd/yyyy): 10/24/2010
item    Unit       Purchase
        price      Date
583     $13.50     10/24/2005
The item number and date should be left justified; the unit price should be
right justified. Allow dollar amounts up to $9999.99. Hint: Use tabs to line up
the columns.
----------------------------------------------

Modify Programming Project 2 from Chapter 3 so that the program reads a series of
items from a file and displays the data in columns. Each line of the file will
have the following form:
item,price,mm/dd/yyyy
For example, suppose that the file contains the following lines:
583,13.5,10/24/2005
3912,599.99,7/27/2008
The output of the program should have the following appearance:
item    Unit       Purchase
        price      Date
583     $13.50     10/24/2005
3912    $599.99    7/27/20088
Have the program obtain the file name from the command line.
*/

#define LINE_LEN 50

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct part {
	int item_num;
	float unit_price;
  struct date {
    int month;
    int day;
    int year;
  } purchase_date;
	struct part *next;
};

struct part *inventory = NULL;

void load_save(const char *filename);
void print_list(void);

int main(int argc, char *argv[])
{
  load_save(argv[1]);
  print_list();
	/*Prints out the inputted data into a special format*/
	return 0;
}

void load_save(const char *filename)
{
  FILE *input;

  if ((input = fopen(filename, "rb")) == NULL)
  {
    printf("%s can't be opened\n", filename);
    exit(EXIT_FAILURE);
  }

  struct part *cur, *prev, *new_node;
  int ch = 0, line_count = 0;

  while((ch = fgetc(input)) != EOF)
  {
    ungetc(ch, input);

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
  		printf("Database is full; can't add more parts.\n");
  		return;
  	}

    char line[LINE_LEN + 1] = "";
    fgets(line, LINE_LEN, input);
    if (sscanf(line, "%d,%f,%d/%d/%d", &new_node->item_num, &new_node->unit_price,
      &new_node->purchase_date.month, &new_node->purchase_date.day, &new_node->purchase_date.year) != 5) {
      printf("Unnable to read line %d\n", line_count);
      continue;
    }

    for(cur = inventory, prev = NULL; cur != NULL &&
      new_node->item_num > cur->item_num; prev = cur, cur = cur->next);

    if(cur != NULL && new_node->item_num == cur->item_num)
  	{
    	printf("Duplicate %d part data detected.\nDuplicate part data was omitted\n", new_node->item_num);
    	free(new_node);
    	continue;
    }

    new_node->next = cur;
  	if(prev == NULL)
  		inventory = new_node;
  	else
  		prev->next = new_node;

    line_count++;
  }
}

void print_list(void)
{
  struct part *cur = NULL;

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  for(cur = inventory; cur != NULL; cur = cur->next)
    printf("%d\t\t$%7.2f\t%.2d/%.2d/%d\n", cur->item_num, cur->unit_price,
      cur->purchase_date.month, cur->purchase_date.day, cur->purchase_date.year);

  return;
}
