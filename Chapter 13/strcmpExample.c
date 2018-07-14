#include <stdio.h>
#include <string.h>

int main () {
   char str1[30];
   char str2[30];
   int ret;


   strcpy(str1, "14:59 Miss the bus");
   strcpy(str2, "15:00 Catch the bus");

   ret = strcmp(str1, str2);

   if(ret < 0) {
      printf("str1 is less than str2\n");
   } else if(ret > 0) {
      printf("str2 is less than str1\n");
   } else {
      printf("str1 is equal to str2\n");
   }

   return(0);
}
