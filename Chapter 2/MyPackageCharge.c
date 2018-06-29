
/* Charge a package by weight or dimensional weight? */
#include <stdio.h>

int main(void)
{
  int height = 9, length = 10, width = 5, volume, weight = 40;
  volume = height * length * width;
  
  printf("Height = %d \nLength = %d \nWidth = %d \nTotal Volume = %d \nWeight = %d lb. \nDimensional Weight = %d\n\n", height, length, width, volume, weight, (volume + 165) / 166);
  
  if(weight >= (volume + 165) / 166) /*weight >= Dimensional Weight*/
  {
	  printf("This Package would be charged by Weight.");
  }
  else
  {
	  printf("This Package would be charged by Dimensional Weight.");
  }
  
  return 0;
}