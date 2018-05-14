# External GroupBy

### Make

There is a Makefile in the folder. To compile the source code, simply do
```
$ make
```
which will generate "externalGroupBy" executable. Note c++11 is needed.

To clean up the environment, type
```
$ make clean
```

### Run

"externalGroupBy" accept input from stdin and output to stdout.
To run, use the following command
```
$ cat <intput file> | ./externalGroupBy > <output file>
```

### Test

I prepared some tests. Run the following script
```
$ ./run_tests.sh
```
The test scripts are modified based on the examples you provide. Please find the associated scripts for more details.

Note: some tests might failed due to memory consumption reached limitation. It might be my program's problem or the memory profiling method is not so accurate. I plan to use Valgrind in the future to do the profiling as time allows.

### Algorithm

1. Accept the input from stdin and store them to a temp file as the input file
2. Split the input file to small batches, such that each batch is smaller than memory limitation
3. For each batch, sort them in memory based on key (if keys are the same, then base on value). Time complexity O(nlogn)
4. Write out the sorted results of each batch to individual files
5. Use K Merge Sort merge the files together with the help of priority queue (pq). The priority queue's order is also based on key (if keys same, base on value). Time complexity O(nlogn)
6. K merge sort is a classical problem and I will not go into details. One thing to point out, is generating the final results. I keep a previous element storing the last popped element. If the current element's key (popped from pq) is the same as the previous element's key, then only need to output the current element's value. Otherwise, if the keys are different, then a newline is needed and the current element's key and value are both outputted. Afterwards, the current element's value will be assigned to the previous element.

**Please feel free to let me know if you have any questions by reaching ziqifan16@gmail.com**