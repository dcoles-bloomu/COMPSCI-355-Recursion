/*
 * Outputs a solution to the Towers of Hanoi problem for a
 * user-specified number of disks.
 *
 * Execution snapshot:
 *
 *      How many disks are on the starting peg? 3
 *      1. A -> B
 *      2. A -> C
 *      3. B -> C
 *      4. A -> B
 *      5. C -> A
 *      6. C -> B
 *      7. A -> B
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Outputs a sequence of moves for transferring n disks
// from the start peg to the finish peg, using the spare
// peg as a temporary resting spot.
void moveTower(int n, char start, char finish, char spare);

// Writes a line of output.
void printMove(char, char);

int main() {
    int numDisks;
    cout << "How many disks are on the starting peg? ";
    cin >> numDisks;
	moveTower(numDisks, 'A', 'B', 'C');
	return 0;
}

void moveTower(int n, char start, char finish, char spare) {
    if (n == 1)
        printMove(start, finish);
    else {
        moveTower(n-1, start, spare, finish);
        printMove(start, finish);
        moveTower(n-1, spare, finish, start);
    }
}

void printMove(char start, char finish) {
    static int move_num = 0;
    cout << setw(2) << ++move_num << ". " << start << " -> "
         << finish << endl;
}