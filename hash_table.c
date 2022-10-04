#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "md5/md5.h"
#define length_of_associative_ary 10000
#define length_of_ary 10000


typedef struct node_t
{
  char key[256];
  int value;
  struct node_t *next;
} node;


typedef struct ary_node_t
{
  char key[256];
  int value;
} ary_node;


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


int push_ary (char *key, int value, ary_node *ary_to_compare[])
{
  ary_node *new_node;
  new_node = (ary_node*)malloc(sizeof(ary_node));
  strcpy(new_node->key, key);
  new_node->value = value;

  int i = 0;
  while (ary_to_compare[i] != NULL) {
    i++;
  }
  ary_to_compare[i] = new_node;

  return 0;
}


int fetch_value_from_ary (char *key, ary_node* ary_to_compare[])
{
  int i = 0;
  while (ary_to_compare[i] != NULL) {
    if (strcmp(key, ary_to_compare[i]->key) == 0) {
      return ary_to_compare[i]->value;
    }
    i++;
  }
  return -1;
}


int fetch_value (char *key, node* associative_ary[])
{
  struct timeval total_start_time;
  struct timeval total_end_time;
  struct timeval start_time;
  struct timeval end_time;

  struct timeval {
    time_t      tv_sec;     /* 秒 */
    suseconds_t tv_usec;    /* マイクロ秒 */
  };


  unsigned int index = get_index(key);
  int value;
  node *current_node;
  current_node = associative_ary[index];

  gettimeofday(&total_start_time, NULL);
  while (current_node != NULL) {
    if (strcmp(key, current_node->key) == 0) {
      value = current_node->value;
      return value;
    } 
    current_node = current_node->next;
  }
  gettimeofday(&total_end_time, NULL);

  double sec = (double)(total_end_time.tv_sec - total_start_time.tv_sec);
  double micro = (double)(total_end_time.tv_usec - total_start_time.tv_usec);
  double passed = sec + micro / 1000.0 / 1000.0;
  //printf("%lf\n", passed);

  return -1;
}


int delete (char *key, node* associative_ary[])
{
  unsigned int index = get_index(key);
  node *current_node;
  node *parent_node;
  current_node = associative_ary[index];

  while(current_node != NULL) {
    if (strcmp(key, current_node->key) == 0) {
      if (current_node == associative_ary[index]) {
        associative_ary[index] = current_node->next;
      } else {
        parent_node->next = current_node->next;
      }
      free(current_node);

      return 0;
    }
    parent_node = current_node;
    current_node = current_node->next;
  }

  return 0;
}


int display_hash_table (node* associative_ary[])
{
  node *current_node;
  for (int i = 0; i < length_of_associative_ary ; i++) {
    if (associative_ary[i] != NULL) {
      current_node = associative_ary[i];
      printf("%s : %d\n", current_node->key, current_node->value);
      while (current_node->next != NULL) {
        current_node = current_node->next;
        printf("  %s : %d\n", current_node->key, current_node->value);
      }
    }
  }
  return 0;
}

int display_ary (ary_node* ary_to_compare[])
{
  ary_node *current_node;
  for (int i = 0; i < length_of_ary ; i++) {
    if (ary_to_compare[i] != NULL) {
      current_node = ary_to_compare[i];
      printf("%s : %d\n", current_node->key, current_node->value);
    }
  }
  return 0;
}


int main (void)
{
  node *associative_ary[length_of_associative_ary];
  init(associative_ary);

  ary_node *ary_to_compare[length_of_ary]; 
  for (int i = 0; i < length_of_ary; i++) {
    ary_to_compare[i] = NULL;
  }

  int length_of_key = 256;
  srand((unsigned int)time(NULL));

  int num_elm_of_associative_ary = 10000;
  int num_elm_of_ary = 10000;
  int num_search = 1000000;
  char keys[num_elm_of_ary][9]; 

  for (int i = 0; i < num_elm_of_ary; i++) {
    char key[length_of_key];

    int value = rand();
    int j;
    for (j = 0; j < 8 ; j++) {
      key[j] = rand() % 26 + 'a';
    }
    key[j] = '\0';
    //printf("key = %s  value = %d\n", key, value);
    strcpy(keys[i], key);
    //insert(key, value, associative_ary);
    push_ary(key, value, ary_to_compare);
  }


  //for (int i = 0; i < 20; i++) {
  //  printf("keys ary = %s\n", keys[i]);
  //}

  struct timeval total_start_time;
  struct timeval total_end_time;
  struct timeval start_time;
  struct timeval end_time;

  struct timeval {
    time_t      tv_sec;     /* 秒 */
    suseconds_t tv_usec;    /* マイクロ秒 */
  };

  //start measuring elapsed time
  gettimeofday(&total_start_time, NULL);
  for (int i = 0; i < num_search; i++) {
    int index = rand() % num_elm_of_ary;
    //get_index(keys[index]);
    //fetch_value(keys[index], associative_ary);
    fetch_value_from_ary(keys[index], ary_to_compare);
  }
  gettimeofday(&total_end_time, NULL);
  //end

  double sec = (double)(total_end_time.tv_sec - total_start_time.tv_sec);
  double micro = (double)(total_end_time.tv_usec - total_start_time.tv_usec);
  double passed = sec + micro / 1000.0 / 1000.0;
  printf("%lf\n", passed);


  return 0;
}
