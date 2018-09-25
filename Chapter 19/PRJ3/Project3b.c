#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Project3.h"

int main (void)
{
  Stack s1, s2, cur_stack;
  s1 = create();
  s2 = create();
  cur_stack = s1;

  char command = '\0';

  printf("Valid Commands\nP = Push\nO = Pop\n");
  printf("L = Length\nC = Change Stacks\nQ = Quit\n");
  while(1)
  {
    printf("Enter a Command: ");
    scanf("%c", &command);
    command = toupper(command);
    switch(command)
    {
      case 'P': push(cur_stack); break;
      case 'O': printf("Popped item: %d\n", pop(cur_stack)); break;
      case 'L': printf("Length is: %d\n", length(cur_stack)); break;
      case 'C': cur_stack = change_stack(cur_stack, s1, s2); break;
			case 'Q': exit(EXIT_SUCCESS);
      default: printf("Command not recognized. Try again.");
    }
    while(getchar() != '\n');
  }
}
