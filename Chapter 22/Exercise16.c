
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Assume that str is a string that contains a "sales rank" immediately preceded by
the # symbol (other characters may precede the # and/or follow the sales rank).
A sales rank is a series of decimal digits possibly containing commas, such as
the following examples:
#989
#24,675
#1,162,620
Write a call of sscanf that extracts the sales rank (but not the # symbol) and
stores it in a string variable named sales_rank.
*/

int main(int argc, char *argv[])
{
  char str[50] = "\0", sales_rank[17] = "\0";
  FILE *fp;
  fp = fopen("config1.txt", "r");
  fgets(str, 50, fp);

  sscanf(str, "%*[^#]%*[#]%[1234567890,]", sales_rank);
  puts(sales_rank);
}
