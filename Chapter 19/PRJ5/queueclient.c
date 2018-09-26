#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queueADT.h"

int main (void)
{
  Queue q1, q2, cur_q;
  q1 = create();
  q2 = create();
  cur_q = q1;

  char command = '\0';

  printf("Valid Commands\nE = Enter Queue\nX = Exit Queue\nF = What's first in line?\n");
  printf("L = What's last in line?\nC = Change Queue\n Q = Quit\n");
  while(1)
  {
    printf("Enter a Command: ");
    scanf("%c", &command);
    command = toupper(command);
    switch(command)
    {
      case 'E': enter_queue(cur_q); break;
      case 'X': printf("Item popped was: %d\n", exit_queue(cur_q)); break;
      case 'F': printf("First in line is: %d\n", is_first(cur_q)); break;
      case 'L': printf("Last in line is: %d\n", is_last(cur_q)); break;
      case 'C': cur_q = change_queue(cur_q, q1, q2); break;
			case 'Q': destroy(q1); destroy(q2); exit(EXIT_SUCCESS);
      default: printf("Command not recognized. Try again.");
    }
    while(getchar() != '\n');
  }
}
