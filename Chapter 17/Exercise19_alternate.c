
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int call_cmd(char * str);

int new_cmd(void) { return 1; }
int open_cmd(void) { return 2; }
int close_cmd(void) { return 3; }
int close_all_cmd(void) { return 4; }
int save_cmd(void) { return 5; }
int save_as_cmd(void) { return 6; }
int save_all_cmd(void) { return 7; }
int print_cmd(void) { return 8; }
int exit_cmd(void) { return 9; }

struct {
char *cmd_name;
int (*cmd_pointer)(void);
} file_cmd[] =
{{"new",          new_cmd},
 {"open",         open_cmd},
 {"close",        close_cmd},
 {"close all",    close_all_cmd},
 {"save",         save_cmd},
 {"save as",      save_as_cmd},
 {"save all",     save_all_cmd},
 {"print",        print_cmd},
 {"exit",         exit_cmd}
};

int main(void)
{
  char * input = "save as";
  //printf("Enter function name: ");
  //scanf("%s", input);
  printf("Function: %d\n", call_cmd(input));

	return 0;
}

int call_cmd(char * str)
{
  int i;

  for(i = 0; i < (sizeof(file_cmd) / sizeof(file_cmd[0])); i++)
  {
    if(strcmp(file_cmd[i].cmd_name, str) == 0)
    {
      return file_cmd[i].cmd_pointer();
    }
  }
  return 0;
}
