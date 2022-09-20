#include <stdio.h>

int main(void)
{
  int length = 256;
  int mod_1 = 660579410 % length;
  printf("mod  -->  %d\n", mod_1);
  int mod_2 = 660579410 % length;
  printf("mod  -->  %d\n", mod_2);
  int mod_3 = 3751604992 % length;
  printf("mod  -->  %d\n", mod_3);
  int mod_4 = 757695138 % length;
  printf("mod  -->  %d\n", mod_4);
  int mod_5 = 1883122972 % length;
  printf("mod  -->  %d\n", mod_5);

  return 0;
}
