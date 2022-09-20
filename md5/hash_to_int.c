#include <stdio.h>
#include <string.h>
#include "md5.h"

void print_hash(uint8_t *p){
	for(unsigned int i = 0; i < 16; ++i){
		printf("%02x", p[i]);
	}
	printf("\n");
}


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

unsigned int hash_to_int(char *key)
{
  unsigned int *hash;
  hash = (unsigned int*)md5String(key);

  unsigned int elm_int[4];

  for(int i = 0; i < 4; i++) {
    elm_int[i] = hash[i];
    print_bite(elm_int[i]);
  }

 unsigned int convered_int = elm_int[0] ^ elm_int[1] ^ elm_int[2] ^ elm_int[3]; 
 printf("convered_int --> %u\n", convered_int);


  return 0;
}


//unsigned int hash_to_int(char *key)
//{
//  uint8_t *hash;
//  hash = md5String(key);
//
//  unsigned int elm_int[4];
//  int loop_count = 0;
//
//  int shift_bit = 8;
//  for(int i = 0; i < 16; i +=4) {
//    unsigned int first_bite  = hash[i];
//    unsigned int second_int = hash[i + 1];
//    unsigned int second_bite = second_int << shift_bit | first_bite;
//
//    unsigned int third_int  = hash[i + 2];
//    unsigned int third_bite  = third_int << shift_bit * 2 | second_bite;
//
//    unsigned int fourth_int  = hash[i + 3];
//    unsigned int fourth_bite  = fourth_int << shift_bit * 3 | third_bite;
//
//    print_bite(fourth_bite);
//    elm_int[loop_count] = fourth_bite;
//    loop_count++;
//  }
//
//  unsigned int convered_int = elm_int[0] ^ elm_int[1] ^ elm_int[2] ^ elm_int[3]; 
//  printf("convered_int --> %u\n", convered_int);
//
//  return convered_int;
//}



//unsigned int hash_to_int(char *key)
//{
//  uint8_t *hash;
//  hash = md5String(key);
//
//  unsigned int elm_int[4];
//  int loop_count = 0;
//
//  int shift_bit = 8;
//  for(int i = 0; i < 16; i +=4) {
//    unsigned int first_bite  = hash[i];
//    unsigned int second_bite = hash[i + 1] | first_bite  << shift_bit;
//    unsigned int third_bite  = hash[i + 2] | second_bite << shift_bit;
//    unsigned int fourth_bite = hash[i + 3] | third_bite  << shift_bit;
//
//    //print_bite(fourth_bite);
//    elm_int[loop_count] = fourth_bite;
//    loop_count++;
//  }
//
//  unsigned int convered_int = elm_int[0] ^ elm_int[1] ^ elm_int[2] ^ elm_int[3]; 
//  printf("convered_int --> %u\n", convered_int);
//
//  return convered_int;
//}


int main()
{
  char key[256];
  uint8_t *hash;

  hash_to_int("abcdefghi");
  //strcpy(str, "abcdefghi");
  //hash = md5String(str);
  //hash_to_int(hash);

  //strcpy(str, "abcdefghi");
  //hash = md5String(str);
  //hash_to_int(hash);

  //strcpy(str, "abcdefghi");
  //hash = md5String(str);
  //hash_to_int(hash);

  //strcpy(str, "a");
  //hash = md5String(str);
  //hash_to_int(hash);

  return 0;
}

