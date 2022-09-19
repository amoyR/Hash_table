#include <stdio.h>
 
int print_bite(unsigned int value)
{
  unsigned int bit = (1 << (sizeof(int) * 8 - 1));

  printf( "value の 2進表記は " );

  for ( ; bit != 0 ; bit >>= 1 ){
    if ( value & bit ){
      putchar('1');
    }
    else{
      putchar('0');
    }
  }
  printf( " です。\n" );

  return 0;
}

int main(void)
{
	unsigned int a = 0;
	unsigned int b = 255 | a << 8;;


  print_bite(a);
  print_bite(b);

  return 0;
}
