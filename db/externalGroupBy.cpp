// C++ program to implement External GroupBy
// Author: Ziqi Fan
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;

static int memoryLimitInBytes = 0;
static int num_ways = 0;

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
auto comp = [](MinHeapNode& a, MinHeapNode& b) {
    if(a.element.key == b.element.key) {
        return a.element.value > b.element.value;
    }
    return a.element.key > b.element.key;
};
priority_queue<MinHeapNode, vector<MinHeapNode>, decltype(comp)> pq(comp);

FILE* openFile(char* fileName, char* mode) {
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
void mergeFiles(char *output_file) {
    FILE* in[num_ways];
    for (int i = 0; i < num_ways; i++) {
        char fileName[20];

        // convert i to string
        snprintf(fileName, sizeof(fileName), "tempFile%d", i);

        // Open output files in read mode.
        in[i] = openFile(fileName, (char*)"r");
    }

    // FINAL OUTPUT FILE
    FILE *out = openFile(output_file, (char*)"w");

    int i;
    char key[100];
    char value[100];
    for (i = 0; i < num_ways; i++) {
        // break if no output file is empty and
        // index i will be no. of input file
        if (fscanf(in[i], "%s %s\n", key, value) != 2)
            break;
        MinHeapNode node;
        node.element.key = key;
        node.element.value = value;
        node.i = i;
        pq.push(node);
    }

    int count = 0;

    // Now one by one get the minimum element from min
    // heap and replace it with next element.
    // run till all filled input files reach EOF
    bool firstLine = true;
    MinHeapNode prev;
    while (count != i) {
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
        if (fscanf(in[root.i], "%s %s\n", key, value) != 2) {
            count++;
        }
        else {
            root.element.key = key;
            root.element.value = value;
            pq.push(root);
        }
    }

    // close input and output files
    for (int i = 0; i < num_ways; i++) {
        fclose(in[i]);
    }

    fprintf(out, "\n");

    fclose(out);
}

ifstream::pos_type filesize(const char* filename) {
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg();
}

// Using a merge-sort algorithm, create the initial runs
// and divide them evenly among the output files
void createInitialRuns(char *input_file) {
    // For big input file
    FILE *in = openFile(input_file, (char*)"r");

    if(fscanf(in, "%d\n", &memoryLimitInBytes) != 1) {
        cout << "Error reading the first line - memory limitation!" << endl;
        return;
    }
    cout << "Memory limitation (bytes) specified in the input file is " << memoryLimitInBytes << endl;

    int fsize = filesize(input_file);
    cout << "Input file size in bytes is " << fsize << endl;
    // No. of Partitions of input file.
    num_ways = ceil(double(fsize) / double(memoryLimitInBytes));
    cout << "Number of intermediate files needed is " << num_ways << endl;

    // output scratch files
    FILE* out[num_ways];
    char fileName[20];
    for (int i = 0; i < num_ways; i++) {
        // convert i to string
        snprintf(fileName, sizeof(fileName), "tempFile%d", i);

        // Open output files in write mode.
        out[i] = openFile(fileName, (char*)"w");
    }

    // Creat a vector of KVPairs to store the input
    vector<KVPair> arr;

    bool more_input = true;
    int next_output_file = 0;

    int i;
    while (more_input) {
        arr.clear();
        long long byteCount = 0;
        // make sure not breaking the memory limit
        for (i = 0; byteCount < memoryLimitInBytes; i++) {
            char key[100];
            char value[100];
            if (fscanf(in, "%s %s\n", key, value) != 2) {
                more_input = false;
                break;
            }
            KVPair k;
            k.key = key;
            k.value = value;
            arr.push_back(k);
            byteCount += k.key.size() + k.value.size();
        }

        // sort array by comparing key first. If draw, compare value.
        sort(arr.begin(),arr.end(), [](KVPair& a, KVPair& b) {
            if(a.key ==b.key) {
                return a.value < b.value;
            }
            return a.key < b.key;
        });

        // Write the records to the output file
        for (int j = 0; j < i; j++) {
            fprintf(out[next_output_file], "%s %s\n", arr[j].key.c_str(), arr[j].value.c_str());
        }

        next_output_file++;
    }

    // close input and output files
    for (int i = 0; i < num_ways; i++) {
        fclose(out[i]);
    }
    fclose(in);
}

// For sorting data stored on disk
void externalSort(char* input_file,  char *output_file) {
    // read the input file, create the initial runs,
    // and assign the runs to the output file
    createInitialRuns(input_file);

    // Merge the runs using the K-way merging
    mergeFiles(output_file);
}

void generateInput(char* input_file) {
    // The size of each partition in term of bytes
    memoryLimitInBytes = 20000;
    int element_size = 6500;
    FILE* in = openFile(input_file, (char*)"w");

    srand(time(NULL));

    // generate input
    fprintf(in, "%s\n", to_string(memoryLimitInBytes).c_str()); // the first line is the memory limitation
    for (int i = 0; i < element_size; i++)
        fprintf(in, "%s %s\n", to_string(rand()%300).c_str(), to_string(rand()%1000).c_str());
    fclose(in);
}

static void show_usage(string name) {
    std::cerr << "Usage: " << name << " <input file> <output file>" << endl;
    std::cerr << "Usage: " << name << " --test" << endl << "Test mode will generate input file automatically.";
}

// Driver program to test above
int main(int argc, char *argv[]) {
    if(argc != 2 && argc != 3) {
        show_usage(argv[0]);
        return 1;
    }

    if(argc == 2) {
        string test = argv[1];
        if(test != "--test") {
            show_usage(argv[0]);
            return 1;
        }
        char input_file[] = "testInput.txt";
        char output_file[] = "testOutput.txt";
        generateInput(input_file);

        externalSort(input_file, output_file);

        cout << "Test Finished successfully!" << endl;
        cout << "Check " << input_file << " for input, and "<<output_file << " for the results:-)" << endl;
    }

    if(argc == 3) {
        cout << "Started processing ... " << endl;

        string input = argv[1];
        char *input_file = new char[input.length() + 1];
        strcpy(input_file, input.c_str());

        string output = argv[2];
        char *output_file = new char[input.length() + 1];
        strcpy(output_file, output.c_str());

        externalSort(input_file, output_file);
        delete[] input_file;
        delete[] output_file;

        cout << "Finished successfully!" << endl;
        cout << "Check " << argv[2] << " for the results:-)" << endl;
    }

    return 0;
}
