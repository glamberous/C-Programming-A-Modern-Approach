
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void call_cmd(char * str);

void new_cmd(void) { printf("Called new_cmd.\n"); }
void open_cmd(void) { printf("Called open_cmd.\n"); }
void close_cmd(void) { printf("Called close_cmd.\n"); }
void close_all_cmd(void) { printf("Called close_all_cmd.\n"); }
void save_cmd(void) { printf("Called save_cmd.\n"); }
void save_as_cmd(void) { printf("Called save_as_cmd.\n"); }
void save_all_cmd(void) { printf("Called save_all_cmd.\n"); }
void print_cmd(void) { printf("Called print_cmd.\n"); }
void exit_cmd(void) { printf("Called exit_cmd.\n"); }

struct {
char *cmd_name;
void (*cmd_pointer)(void);
} file_cmd[] =
{{"new",          new_cmd},
 {"open",         open_cmd},
 {"close",        close_cmd},
 {"close all",    close_all_cmd},
 {"save",         save_cmd},
 {"save as ",     save_as_cmd},
 {"save all",     save_all_cmd},
 {"print",        print_cmd},
 {"exit",         exit_cmd}
};

int main(void)
{
  char input[20];
  printf("Enter function name: ");
  scanf("%s", input);
  call_cmd(input);

	return 0;
}

void call_cmd(char * str)
{
  int i;

  for(i = 0; i < (sizeof(file_cmd) / sizeof(file_cmd[0])); i++)
  {
    if(strcmp(file_cmd[i].cmd_name, str) == 0)
    {
      file_cmd[i].cmd_pointer();
      return ;
    }
  }
  return ;
}
