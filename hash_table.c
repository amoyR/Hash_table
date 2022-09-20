#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5/md5.h"
#define length_of_associative_ary 256


typedef struct node_t
{
  char key[256];
  int value;
  struct node_t *next;
} node;


int init (node* associative_ary[])
{
  for (int i = 0; i < length_of_associative_ary; i++) {
    associative_ary[i] = NULL;
  }

  return 0;
}


unsigned int get_index(char *key)
{
  uint8_t *md5_val;
  md5_val = md5String(key);

  unsigned int elm_int[4];
  int loop_count = 0;

  int shift_bit = 8;
  for(int i = 0; i < 16; i +=4) {
    unsigned int first_bite  = md5_val[i];
    unsigned int second_int = md5_val[i + 1];
    unsigned int second_bite = second_int << shift_bit | first_bite;

    unsigned int third_int  = md5_val[i + 2];
    unsigned int third_bite  = third_int << shift_bit * 2 | second_bite;

    unsigned int fourth_int  = md5_val[i + 3];
    unsigned int fourth_bite  = fourth_int << shift_bit * 3 | third_bite;

    elm_int[loop_count] = fourth_bite;
    loop_count++;
  }

  unsigned int hash_val = elm_int[0] ^ elm_int[1] ^ elm_int[2] ^ elm_int[3]; 
  //printf("hash_val --> %u\n", hash_val);
  
  unsigned int index = hash_val % length_of_associative_ary;

  return index;
}


int insert (char *key, int value, node *associative_ary[]) 
{
  node *new_node;
  new_node = (node*)malloc(sizeof(node));
  strcpy(new_node->key, key);
  new_node->value = value;
  new_node->next = NULL;


  unsigned int index = get_index(key);
  //printf("index  -->  %u\n", index);

  if (associative_ary[index] == NULL) {
    associative_ary[index] = new_node;
  } else {
    node *parent_node;
    parent_node = associative_ary[index];
    while (parent_node->next != NULL) {
      parent_node = parent_node->next;
    }
    parent_node->next = new_node;
  }

  return 0;
}


int fetch_value (char *key, node* associative_ary[])
{
  unsigned int index = get_index(key);
  int value;
  node *current_node;
  current_node = associative_ary[index];
  while (current_node != NULL) {
    if (strcmp(key, current_node->key) == 0) {
      value = current_node->value;
      return value;
    } 
    current_node = current_node->next;
  }

  return NULL;
}
int delete (char *key, node* associative_ary[])
{


}

int display_hash_table (node* associative_ary[])
{
  node *current_node;
  for (int i = 0; i < length_of_associative_ary ; i++) {
    if (associative_ary[i] != NULL) {
      current_node = associative_ary[i];
      printf("value --> %d\n", current_node->value);
      while (current_node->next != NULL) {
        current_node = current_node->next;
        printf("  value --> %d\n", current_node->value);
      }
    }
  }
  return 0;
}



int main (void)
{
  node *associative_ary[length_of_associative_ary];

  init(associative_ary);

  insert("abc", 0, associative_ary);
  insert("abc", 0, associative_ary);
  insert("abd", 1, associative_ary);
  insert("abe", 2, associative_ary);
  insert("abg", 3, associative_ary);

  int val = fetch_value("abgaaa", associative_ary);
  if (val != NULL) {
    printf("value --> %d", val);
  } else {
    printf("The key isn't registered\n");
  }
  //display_hash_table(associative_ary);
  return 0;
}
