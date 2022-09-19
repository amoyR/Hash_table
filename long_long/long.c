#include <stdio.h>

int main (void)
{
  int x;
  unsigned int x_unsigned;
  unsigned long int x_unsigned_long;

  printf("int    %lu\n", sizeof(x));
  printf("unsigned int    %lu\n", sizeof(x_unsigned));
  printf("unsigned long int  %lu\n", sizeof(x_unsigned_long));
  return 0;
}
