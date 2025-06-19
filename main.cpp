#include <iostream>
#include <fstream>
#include "array_ops.cpp"

using namespace std;
#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    const char* inputFilename = argv[1];
    std::ifstream in(inputFilename);
    if (!in) {
        std::cerr << "Error: unable to open input file " << inputFilename << "\n";
        return 1;
    }

    std::ofstream out("output.txt");
    if (!out) {
        std::cerr << "Error: unable to create output file\n";
        return 1;
    }

    int arr[MAX_SIZE];
    int size = 0;
    int value;
    while (in >> value) {
        if (size >= MAX_SIZE) {
            out << "Warning: reached MAX_SIZE, remaining values ignored.\n";
            break;
        }
        arr[size++] = value;
    }
    in.close();

    out << "Initialized array with " << size << " items.\n";

    // Example operations
    try {
        out << "Adding value 20...\n";
        add(arr, size, 20);

        out << "Modifying index 1 to 100...\n";
        int oldVal;
        modify(arr, size, 1, 100, oldVal);
        out << "Old value was " << oldVal << ", new value is " << arr[1] << "\n";

    } catch (const std::exception &e) {
        out << "Exception: " << e.what() << "\n";
    }

    out << "Removing index 0...\n";
    if (remove(arr, size, 0))
        out << "Removal successful.\n";
    else
        out << "Removal failed — invalid index.\n";

    out << "Final array contents:\n";
    for (int i = 0; i < size; ++i)
        out << arr[i] << "\n";

    out.close();

    std::cout << "Results written to output.txt\n";
    return 0;
}
