#!/bin/bash

gcc -c hash_table.c
gcc -o hash_table hash_table.o md5.o


for i in `seq 0 100`
do
  ./hash_table 10000 10000 1000000 >> hash_md5_11.txt
  ./hash_table 10000 10000 5000000 >> hash_md5_12.txt
  ./hash_table 10000 10000 10000000 >> hash_md5_13.txt

  ./hash_table 10000 100000 1000000 >> hash_md5_21.txt
  ./hash_table 10000 100000 5000000 >> hash_md5_22.txt
  ./hash_table 10000 100000 10000000 >> hash_md5_23.txt

  ./hash_table 10000 1000000 1000000 >> hash_md5_31.txt
  ./hash_table 10000 1000000 5000000 >> hash_md5_32.txt
  ./hash_table 10000 1000000 10000000 >> hash_md5_33.txt

  
  ./hash_table 100000 100000 1000000 >> hash_md5_41.txt
  ./hash_table 100000 100000 5000000 >> hash_md5_42.txt
  ./hash_table 100000 100000 10000000 >> hash_md5_43.txt

  ./hash_table 100000 1000000 1000000 >> hash_md5_51.txt
  ./hash_table 100000 1000000 5000000 >> hash_md5_52.txt
  ./hash_table 100000 1000000 10000000 >> hash_md5_53.txt

  ./hash_table 100000 10000000 1000000 >> hash_md5_61.txt
  ./hash_table 100000 10000000 5000000 >> hash_md5_62.txt
  ./hash_table 100000 10000000 10000000 >> hash_md5_63.txt
done

cat hash_md5_11.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_12.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_13.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt

cat hash_md5_21.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_22.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_23.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt

cat hash_md5_31.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_32.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_33.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt

cat hash_md5_41.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_42.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_43.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt

cat hash_md5_51.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_52.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_53.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt

cat hash_md5_61.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_62.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
cat hash_md5_63.txt | awk '{sum+=$1} END {print sum/NR}' >> result_hash_md5.txt
