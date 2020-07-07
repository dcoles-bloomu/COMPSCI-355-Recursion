/*
 * Prints all subsets of a given array of characters. The code was obtained by using a stack
 * to remove recursive calls from a previous version. 
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

void print_subsets_with_stack(char[], int); 

int main() {
    char set[] = {'A', 'B', 'C', 'D', 'E'};
    print_subsets_with_stack(set, 5);
    cout << endl;
    return 0;
}

void print_subsets_with_stack(char set[], int set_size) {
    stack<string> stack;
    string subset = "";
    stack.push(subset);
    int index = 0;

    while (!stack.empty()) {
        subset = stack.top();
        stack.pop();
        if (subset.size() == set_size) {
            cout << setw(2) << ++index << ". " << subset << endl;
        } else {
            int pos = subset.size();
            stack.push(subset + "."); // exclude element of set
            stack.push(subset + set[pos]); // include element of set
        }
    }    
}