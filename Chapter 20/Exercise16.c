#include <stdio.h>
/*
Starting with the 386 processor, x86 CPUs have 32-bit registers named EAX, EBX,
ECX, and EDX. The second half (the least significant bits) of these registers is
the same as AX, BX, CX, and DX, respectively. Modify the regs union so that it
includes these registers as well as the older ons. Your union should be set up so
that modifying EAX changes AX and modifying AX changes the second half of EAX.
(The other new registers will work in a similar fashion.) You'll need to add some
"dummy" members to the word and byte structures, corresponding to the other half
of EAX, EBX, ECX, and EDX. Declare the type of the new registers to be DWORD
(double word), which should be defined as unsigned long. Don't forget that the x86
architecture is little-endian.
*/

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

int main (void)
{
  union {
    struct {
      DWORD edx, ecx, ebx, eax;
    } dword;
    struct {
      WORD dx;
      unsigned int: 16;
      WORD cx;
      unsigned int: 16;
      WORD bx;
      unsigned int: 16;
      WORD ax;
      unsigned int: 16;
    } word;
    struct {
      BYTE dl, dh;
      unsigned int: 16;
      BYTE cl, ch;
      unsigned int: 16;
      BYTE bl, bh;
      unsigned int: 16;
      BYTE al, ah;
      unsigned int: 16;
    } byte;
  } rege;
  char ch = '\0';

  printf("Enter in EAX (8 hex): ");
  scanf("%X", &rege.dword.eax);
  while(getchar() != '\n');

  printf("Modify AX? (Y/N): ");
  ch = getchar();
  if(ch == 'Y')
  {
    printf("Enter in AX (4 hex): ");
    scanf("%hX", &rege.word.ax);
  }
  while(getchar() != '\n');

  printf("Modify AH? (Y/N): ");
  ch = getchar();
  if(ch == 'Y')
  {
    printf("Enter in AH (2 hex): ");
    scanf("%hhX", &rege.byte.ah);
  }
  while(getchar() != '\n');

  printf("Modify AL? (Y/N): ");
  ch = getchar();
  if(ch == 'Y')
  {
    printf("Enter in AL (2 hex): ");
    scanf("%hhX", &rege.byte.al);
  }
  while(getchar() != '\n');

  printf("Final EAX Hex: %X\n", rege.dword.eax);
}
