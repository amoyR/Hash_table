#!/bin/bash

gcc -c hash_table.c
gcc -o hash_table hash_table.o md5.o


for i in `seq 0 100`
do
  ./hash_table >> ary_10000.txt
done

cat ary_10000.txt | awk '{sum+=$1} END {print sum/NR}' >> result.txt
