/*  Modify  the qsort.c program of Section 9.6 so  that  the
quicksort  and split functions are in a separate file  named
quicksort.c.  Create  a header file named  quicksort.h  that
contains  prototypes  for  the two functions and  have  both
qsort.c and quicksort.c include this file. */

#include "quicksort.h"

void quicksort(int a[], int low, int high)
{
  int middle;

  if (low >= high) return;
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}
