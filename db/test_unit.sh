#!/bin/bash

MEM_LIMIT_IN_BYTES=$2
NUM_PAIRS=$3
KEY_LENGTH=3
VALUE_LENGTH=10

# The runtime memory limit which will be set larger than the memory limit requirement.
MAX_ALLOWED_MEMORY_IN_KB=$2
echo "MAX ALLOWED MEMORY IN KB $MAX_ALLOWED_MEMORY_IN_KB"
max_mem=0

SCRIPT_DIR=$(cd "$(dirname "$0")"; pwd)

$SCRIPT_DIR/gen_test_data.py $MEM_LIMIT_IN_BYTES $NUM_PAIRS $KEY_LENGTH $VALUE_LENGTH > input.txt
FILENAME=input.txt
FILESIZE=$(stat -f%z "$FILENAME")
echo "Size of $FILENAME = $FILESIZE bytes."

$SCRIPT_DIR/brute_force.py < input.txt > output.txt

cat input.txt | $1 > test-output.txt & cmd_pid=$!

while true
do
  if ps -p $cmd_pid > /dev/null
  then
    # Get current memory that the process is using (in KB)
    current_mem=$((`ps u -p $cmd_pid | awk '{sum=sum+$6}; END {print sum}'`))
    max_mem=$((current_mem > max_mem ? current_mem : max_mem))
    if (( max_mem > MAX_ALLOWED_MEMORY_IN_KB ))
    then
      kill -9 $cmd_pid
      echo "Test failed! Peak memory usage was $max_mem kilobytes despite" \
        "allowed maximum of $MAX_ALLOWED_MEMORY_IN_KB."
      rm input.txt tempInput.txt tempFile* output.txt test-output.txt
      exit 0
    fi
    sleep 1
  else
    diff output.txt test-output.txt > /dev/null
    if [ $? -eq 0 ]; then
        echo "Test finished successfully! Peak memory usage was $max_mem kilobytes."
    else
        echo "Test failed! Peak memory usage was $max_mem kilobytes."
    fi
    rm input.txt tempInput.txt tempFile* output.txt test-output.txt
    exit 0
  fi
done
