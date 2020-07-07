/*
 * Simple illustration of recursive backtracking: print all subsets of a given array of
 * characters. An iterative implementation is also provided for the sake of comparison.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <cmath>
using namespace std;

void iter_print_subsets(char[], int); 
void rec_print_subsets(char[], int, string); 

int main() {
    char set[] = {'A', 'B', 'C', 'D', 'E'};

    iter_print_subsets(set, 5);

    cout << "\nPress any key to continue. ";
    cin.get();
    cout << endl;

    rec_print_subsets(set, 5, "");
    cout << endl;
    return 0;
}

void iter_print_subsets(char set[], int size) {
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

void rec_print_subsets(char set[], int size, string subset) {
    int pos = subset.size();
    if (pos == size) {
        cout << subset << endl;
        return;
    }
    rec_print_subsets(set, size, subset + '.'); // exclude i-th item in array
    rec_print_subsets(set, size, subset + set[pos]); // include i-th item in array
}