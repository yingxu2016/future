// C++ program to implement external sorting using
// merge sort
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;

// Store each input key and value
struct KVPair
{
    string key;
    string value;
};

struct MinHeapNode
{
    // The element to be stored
    KVPair element;

    // index of the array from which the element is taken
    int i;
};

// Self defined comparator to sort first by key then by value
auto comp = [](MinHeapNode& a, MinHeapNode& b){
    if(stoi(a.element.key) == stoi(b.element.key)) {
        return a.element.value > b.element.value;
    }
    return a.element.key > b.element.key;
};
priority_queue<MinHeapNode, vector<MinHeapNode>, decltype(comp)> pq(comp);

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(KVPair arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    KVPair L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if(L[i].key == R[j].key) {
            arr[k++] = L[i].value <= R[j].value ? L[i++] : R[j++];
        }
        else {
            arr[k++] = L[i].key < R[j].key ? L[i++] : R[j++];
        }
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
        arr[k++] = L[i++];

    /* Copy the remaining elements of R[], if there
       are any */
    while(j < n2)
        arr[k++] = R[j++];
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(KVPair arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

FILE* openFile(char* fileName, char* mode)
{
    FILE* fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Merges k sorted files.  Names of files are assumed
// to be 1, 2, 3, ... k
void mergeFiles(char *output_file, int n, int k)
{
    FILE* in[k];
    for (int i = 0; i < k; i++)
    {
        char fileName[20];

        // convert i to string
        snprintf(fileName, sizeof(fileName), "tempFile%d", i);

        // Open output files in read mode.
        in[i] = openFile(fileName, (char*)"r");
    }

    // FINAL OUTPUT FILE
    FILE *out = openFile(output_file, (char*)"w");

    int i;
    for (i = 0; i < k; i++) {
        // break if no output file is empty and
        // index i will be no. of input files
        int key = 0;
        int value = 0;
        if (fscanf(in[i], "%d %d\n", &key, &value) != 2)
            break;
        MinHeapNode node;
        node.element.key = to_string(key);
        node.element.value = to_string(value);
        node.i = i;
        pq.push(node);
    }

    int count = 0;

    MinHeapNode prev;
    // Now one by one get the minimum element from min
    // heap and replace it with next element.
    // run till all filled input files reach EOF
    bool firstLine = true;
    while (count != i)
    {
        // Get the minimum element and store it in output file
        MinHeapNode root = pq.top();
        pq.pop();

        if(root.element.key == prev.element.key) {
            fprintf(out, " %s", root.element.value.c_str());
        }
        else {
            if(firstLine) {
                fprintf(out, "%s %s", root.element.key.c_str(), root.element.value.c_str());
                firstLine = false;
            }
            else {
                fprintf(out, "\n%s %s", root.element.key.c_str(), root.element.value.c_str());
            }

        }

        prev = root;

        // Find the next element that will replace current
        // root of heap. The next element belongs to same
        // input file as the current min element.
        int key = 0;
        int value = 0;
        if (fscanf(in[root.i], "%d %d\n", &key, &value) != 2)
        {
            count++;
        }
        else {
            root.element.key = to_string(key);
            root.element.value = to_string(value);
            pq.push(root);
        }
    }

    // close input and output files
    for (int i = 0; i < k; i++)
        fclose(in[i]);

    fclose(out);
}

// Using a merge-sort algorithm, create the initial runs
// and divide them evenly among the output files
void createInitialRuns(char *input_file, int run_size,
                       int num_ways)
{
    // For big input file
    FILE *in = openFile(input_file, (char*)"r");

    // output scratch files
    FILE* out[num_ways];
    char fileName[20];
    for (int i = 0; i < num_ways; i++)
    {
        // convert i to string
        snprintf(fileName, sizeof(fileName), "tempFile%d", i);

        // Open output files in write mode.
        out[i] = openFile(fileName, (char*)"w");
    }

    // allocate a dynamic array large enough
    // to accommodate runs of size run_size
    KVPair* arr = (KVPair*)malloc(int(run_size * 1.2) * sizeof(KVPair));
    if(arr == NULL) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    bool more_input = true;
    int next_output_file = 0;

    int i;
    bool firstLine = true;
    while (more_input)
    {
        // write run_size elements into arr from input file
        for (i = 0; i < run_size; i++)
        {
            int key = 0;
            int value = 0;
            if (firstLine) {
                if(fscanf(in, "%d\n", &key) != 1) {
                    cout << "Error reading the first line - memory limitation!" << endl;
                    return;
                }
                firstLine = false;
            }
            if (fscanf(in, "%d %d\n", &key, &value) != 2)
            {
                more_input = false;
                break;
            }
            //cout << key << " " << value << endl;
            arr[i].key = to_string(key);
            arr[i].value = to_string(value);
            //cout << arr[i].key << "$" << arr[i].value << endl;
        }

        // sort array using merge sort
        mergeSort(arr, 0, i - 1);

        // write the records to the appropriate scratch output file
        // can't assume that the loop runs to run_size
        // since the last run's length may be less than run_size
        for (int j = 0; j < i; j++)
            fprintf(out[next_output_file], "%s %s\n", arr[j].key.c_str(), arr[j].value.c_str());

        next_output_file++;
    }

    // close input and output files
    for (int i = 0; i < num_ways; i++)
        fclose(out[i]);

    fclose(in);
}

// For sorting data stored on disk
void externalSort(char* input_file,  char *output_file,
                  int num_ways, int run_size)
{
    // read the input file, create the initial runs,
    // and assign the runs to the scratch output files
    createInitialRuns(input_file, run_size, num_ways);

    // Merge the runs using the K-way merging
    mergeFiles(output_file, run_size, num_ways);
}

ifstream::pos_type filesize(const char* filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg();
}

// Driver program to test above
int main()
{
    cout << "Started prcocess ... " << endl;
    // The size of each partition in term of key-value entries
    int run_size = 1000;
    int element_size = 6500;

    char input_file[] = "input.txt";
    char output_file[] = "output.txt";

    FILE* in = openFile(input_file, (char*)"w");

    srand(time(NULL));

    // generate input
    fprintf(in, "%d\n", run_size); // the first line is the memory limitation
    for (int i = 0; i < element_size; i++)
        fprintf(in, "%d %d\n", rand()%300, rand()%1000);
    fclose(in);

    //int fsize = filesize(input_file);
    // No. of Partitions of input file.
    int num_ways = ceil(double(element_size) / double(run_size));

    externalSort(input_file, output_file, num_ways, run_size);

    cout << "Finished successfully! Check output.txt for the results:-)" << endl;

    return 0;
}
