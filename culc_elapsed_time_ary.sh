#!/bin/bash

gcc -c hash_table.c
gcc -o hash_table hash_table.o md5.o


for i in `seq 0 50`
do
  ./hash_table 10000 10000 1000000 >> ary_11.txt
  ./hash_table 10000 10000 5000000 >> ary_12.txt
  ./hash_table 10000 10000 10000000 >> ary_13.txt

  ./hash_table 100000 100000 1000000 >> ary_21.txt
  ./hash_table 100000 100000 5000000 >> ary_22.txt
  ./hash_table 100000 100000 10000000 >> ary_23.txt
done

cat ary_11.txt | awk '{sum+=$1} END {print sum/NR}' >> result_ary.txt
cat ary_12.txt | awk '{sum+=$1} END {print sum/NR}' >> result_ary.txt
cat ary_13.txt | awk '{sum+=$1} END {print sum/NR}' >> result_ary.txt

cat ary_21.txt | awk '{sum+=$1} END {print sum/NR}' >> result_ary.txt
cat ary_22.txt | awk '{sum+=$1} END {print sum/NR}' >> result_ary.txt
cat ary_23.txt | awk '{sum+=$1} END {print sum/NR}' >> result_ary.txt
