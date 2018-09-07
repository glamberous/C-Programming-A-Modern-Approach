
#include <stdio.h>
#include <stdlib.h>

struct part{
int number;
const char *name;
int on_hand;
};

int compare_parts(const void *p, const void *q);

int main(void)
{
  struct part inventory[4] = {{45, "Jimmy Johns", 4},
                              {88, "Papa Johns", 2},
                              {22, "Johnny Rockets", 6},
                              {37, "Jumpin' Johns", 2}};

  int i = 0;

  qsort(inventory, 4, sizeof(struct part), compare_parts);

  for(i = 0; i < 4; i++)
  {
    printf("Inventory 1: %d\n", inventory[i].number);
  }

	return 0;
}

int compare_parts(const void *p, const void *q)
{
  const struct part *p1 = p;
  const struct part *q1 = q;

  if (p1->number > q1->number)
    return -1;
  else if (p1->number == q1->number)
    return 0;
  else
    return 1;
}
