/*
Write a program that reads a date from the command line and displays it in the
following form:
September 13, 2010
Allow the user to enter the date as either 9-13-2010 or 9/13/2010; you may
assume that there are no spaces in the date. PRint an error message if the date
doesn't have one of the specified forms. Hint: use sscanf to extract the month,
day, and year from the command-line argument.
*/

#define LINE_LEN 50

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_year(int month, int day, int year);

int main(int argc, char *argv[])
{
  char line[LINE_LEN+1] = "";
  int month = 0, day = 0, year = 0;

  printf("Please enter a date: ");
  fgets(line, LINE_LEN, stdin);
  if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
    print_year(month, day, year);
  else if (sscanf(line, "%d-%d-%d", &month, &day, &year) == 3)
    print_year(month, day, year);
  else
    printf("Error: Date not in proper format\n");
}

void print_year(int month, int day, int year)
{
  switch(month)
  {
    case 1: printf("January "); break;
    case 2: printf("February "); break;
    case 3: printf("March "); break;
    case 4: printf("April "); break;
    case 5: printf("May "); break;
    case 6: printf("June "); break;
    case 7: printf("July "); break;
    case 8: printf("August "); break;
    case 9: printf("September "); break;
    case 10: printf("October "); break;
    case 11: printf("November "); break;
    case 12: printf("December "); break;
  }
  printf("%d, %d\n", day, year);
}
