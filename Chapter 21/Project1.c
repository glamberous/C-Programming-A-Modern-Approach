
#include <stddef.h>
#include <stdio.h>

int main (void)
{
  struct abc {
    char a;
    int b[2];
    float c;
  };


  printf("offset of a: %lu\n", offsetof(struct abc, a));
  printf("offset of b: %lu\n", offsetof(struct abc, b));
  printf("offset of c: %lu\n", offsetof(struct abc, c));
  printf("Size of struct s: %lu\n", sizeof(struct abc));
}

/*
This outputted as;
offset of a: 0
offset of b: 4
offset of c: 12
Size of struct s: 16

a = 1 byte
3 empty bytes
b = 8 bytes
c = 4 bytes
*/
