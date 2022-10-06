#!/bin/bash

gcc -c hash_table.c
gcc -o hash_table hash_table.o md5.o
