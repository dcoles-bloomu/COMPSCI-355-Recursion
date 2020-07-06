/*
 * Simple illustration of recursive backtracking: print all subsets of a given array of
 * characters. An iterative implementation is also provided for the sake of comparison.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cmath>
using namespace std;

void print_subsets(char[], int); // recursive backtracker
void print_subsets2(char[], int); // utility wrapper around iterative version
void print_subsets2(char[], int, int, string); // iterative version

int main() {
    char set[] = {'A', 'B', 'C', 'D', 'E'};

    print_subsets(set, 5);

    cout << "\nPress any key to continue. ";
    cin.get();
    cout << endl;

    print_subsets2(set, 5);
    cout << endl;
    return 0;
}

void print_subsets(char set[], int size) {
    // Given a subset of n items, there are 2^n subsets, each of which can be identified
    // with an integer in the range [0, 2^n - 1]. The i-th item of the array is included
    // in a subset if the i-th bit of the corresponding integer is 1. 
    int max = pow(2, size);
    for (int i = 0; i < max; i++) { // iterate over all subsets

        // For subset i, print the k-th item in the array if the k-th bit of i is 1.  
        int j = i;
        for (int k = 0; k < size; k++) {
            cout << (j % 2 == 1 ? set[k] : '.');
            j /= 2;
        }
        cout << endl;
    }
}

void print_subsets2(char set[], int size) {
    print_subsets2(set, 0, size, "");
}

// i = index of current array item 
// result = current subset of array items included so far
void print_subsets2(char set[], int i, int size, string result) {
    if (i == size) {
        cout << result << endl;
        return;
    }
    print_subsets2(set, i + 1, size, result + '.'); // exclude i-th item in array
    print_subsets2(set, i + 1, size, result + set[i]); // include i-th item in array
}