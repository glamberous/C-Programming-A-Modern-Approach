
/*
Write a call of printf that prints
1 widget
if the widget variable (of type int) has the value 1, and
n widgets
otherwise, where n is the value of widget. You are not allowed to use the if
statement or any other statement; the answer must be a single call of printf.
*/

#include <stdio.h>

int main()
{
  int widget = 5;
  printf("%d %s\n", widget, widget == 1 ? "widget" : "widgets");
}
