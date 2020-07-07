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
void move_tower(int n, char start, char finish, char spare);

// Writes a line of output.
void print_move(char, char);

int main() {
    int num_disks;
    cout << "How many disks are on the starting peg? ";
    cin >> num_disks;
	move_tower(num_disks, 'A', 'B', 'C');
	return 0;
}

void moveTower(int n, char start, char finish, char spare) {
    if (n == 1)
        print_move(start, finish);
    else {
        move_tower(n-1, start, spare, finish);
        print_move(start, finish);
        move_tower(n-1, spare, finish, start);
    }
}

void print_move(char start, char finish) {
    static int n = 0; // move number
    cout << setw(2) << ++n << ". " << start << " -> " << finish << endl;
}