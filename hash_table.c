#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5/md5.h"
#define SIZE 10

typedef struct node_t
{
  char key[256];
  int value;
  struct node_t *next;
} node;


int init (node* hash_ary[])
{
  for (int i = 0; i < SIZE; i++) {
    hash_ary[i] = NULL;
  }

  return 0;
}


unsigned int get_hash (char *key)
{
  uint8_t *hash;
  hash = md5String(key);

  unsigned int elm_int[4];
  int loop_count = 0;

  int shift_bit = 8;
  for(int i = 0; i < 16; i +=4) {
    unsigned int first_bite  = hash[i];
    unsigned int second_bite = hash[i + 1] | first_bite  << shift_bit;
    unsigned int third_bite  = hash[i + 2] | second_bite << shift_bit;
    unsigned int fourth_bite = hash[i + 3] | third_bite  << shift_bit;

    //print_bite(fourth_bite);
    elm_int[loop_count] = fourth_bite;
    loop_count++;
  }

  unsigned int convered_int = elm_int[0] ^ elm_int[1] ^ elm_int[2] ^ elm_int[3]; 
  printf("convered_int --> %u\n", convered_int);

  return convered_int;
}


//int get_value (int key, node* hash_ary[]) 
//{
//  int hash_index = get_hash_index(key);
//  node *current_node;
//  current_node = hash_ary[hash_index];
//  while (current_node->next != NULL) {
//    current_node = current_node->next;
//  }
//  if (key == current_node->key) {
//    return current_node->value;
//  }
//  return 0;
//}
//
//
//int display_hash_table (node* hash_ary[])
//{
//  //printf("value --> %d\n", hash_ary[1]->num);
//  //printf("value --> %d\n", hash_ary[1]->next->num);
//  node *current_node;
//  for (int i = 0; i < SIZE; i++) {
//    if (hash_ary[i] != NULL) {
//      current_node = hash_ary[i];
//      printf("value --> %d\n", current_node->value);
//      while (current_node->next != NULL) {
//        current_node = current_node->next;
//        printf("  value --> %d\n", current_node->value);
//      }
//    }
//  }
//  return 0;
//}
//
//
//int insert (int key, int value, node *hash_ary[]) 
//{
//  node *new_node;
//  new_node = (node*)malloc(sizeof(node));
//  new_node->key = key;
//  new_node->value = value;
//  new_node->next = NULL;
//  //printf("%p\n", new_node);
//  //printf("key --> %d  value --> %d\n", new_node->key, new_node->value);
//
//  //printf("key --> %d  value --> %d\n", new_node->key, new_node->value);
//  int hash_index = get_hash_index(key);
//  //printf("key --> %d  value --> %d\n", new_node->key, new_node->value);
//
//  if (hash_ary[hash_index] == NULL) {
//    hash_ary[hash_index] = new_node;
//    //printf("key --> %d  value --> %d\n", hash_ary[hash_index]->key, hash_ary[hash_index]->value);
//  } else {
//    node *parent_node;
//    parent_node = hash_ary[hash_index];
//    //printf("key --> %d  value --> %d\n", hash_ary[hash_index]->key, hash_ary[hash_index]->value);
//    //printf("key --> %d  value --> %d\n", parent_node->key, parent_node->value);
//    while (parent_node->next != NULL) {
//      parent_node = parent_node->next;
//    }
//    parent_node->next = new_node;
//  }
//
//  //if (hash_ary[hash_index]->next != NULL) {
//  //  printf("key --> %d  value --> %d\n", hash_ary[hash_index]->next->key, hash_ary[hash_index]->next->value);
//  //}
//  //printf("%p\n", hash_ary[hash_index]->next);
//  return 0;
//}
//
//
//int delete ()
//{
//
//}


int main (void)
{
  node *hash_ary[SIZE];

  node head;
  char tst[256] = "abcdefghi";
  strcpy(head.key, tst);
  head.value = 1;
  init(hash_ary);

  unsigned int hash = get_hash(head.key);
  printf("hash int --> %u", hash);
  
  //insert(1, 1, hash_ary);
  //insert(9, 9, hash_ary);
  //insert(10, 10, hash_ary);
  //insert(11, 11, hash_ary);
  //insert(21, 21, hash_ary);

  //display_hash_table(hash_ary);


  //int x = get_value(2, hash_ary);

  //printf("%d", x);
  return 0;
}
