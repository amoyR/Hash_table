#!/bin/bash

gcc -c hash_table.c
gcc -o hash_table hash_table.o md5.o


for i in `seq 0 10`
do
  ./hash_table 100 100   100000 >> hash_md5_total_11.txt
  ./hash_table 100 1000  100000 >> hash_md5_total_12.txt
  ./hash_table 100 10000 100000 >> hash_md5_total_13.txt

  ./hash_table 1000 1000   100000 >> hash_md5_total_21.txt
  ./hash_table 1000 10000  100000 >> hash_md5_total_22.txt
  ./hash_table 1000 100000 100000 >> hash_md5_total_23.txt
done

cat hash_md5_total_11.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5_total.txt
cat hash_md5_total_12.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5_total.txt
cat hash_md5_total_13.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5_total.txt

cat hash_md5_total_21.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5_total.txt
cat hash_md5_total_22.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5_total.txt
cat hash_md5_total_23.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5_total.txt
