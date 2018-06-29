
/* Charge a package by weight or dimensional weight? */
int main(void)
{
  int height, length, width, volume, Dweight, weight;
  height = 8;
  length = 12;
  width = 10;
  volume = height * length * width;
  Dweight = (volume + 165) / 166;
  weight = 18;
  
  printf("Height = d%\n Length = d%\n Width = d%\n Total Volume = d%\n Weight = d% lb.\n", height, length, width, volume, weight);
  
  if(weight >= Dweight)
  {
	  printf("This Package would be charged by Weight.\n");
  }
  else
  {
	  printf("This Package would be charged by Dimensional Weight.\n");
  }
  
  return 0;
}