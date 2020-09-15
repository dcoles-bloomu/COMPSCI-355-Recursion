/*
 * The purpose of this program is to compare the use of recurion and
 * dynamic programming to solve the Stair Climbing problem. 
 *
 * For a staircase with a given number of steps, how many ways are 
 * there to go from bottom to top taking either one or two steps at 
 * a time? This program prompts the user for the number of steps and 
 * outputs the answer.
 *
 * Execution snapshots: 
 *
 *      How many steps? 5
 *      Number of ways to reach the top (DP): 13
 *      Number of ways to reach the top (RE): 13
 *
 *      How many steps? 25
 *      Number of ways to reach the top (DP): 196418
 *      Number of ways to reach the top (RE): 196418
 *
 * Try input 40 to observe a difference in execution time.
 *
 * Author: Drue Coles
 */

#include <iostream>
using namespace std;

// Recursive solution to the Stair Climbing Problem.
long rec_num_climbs(int);

// Dynamic programming solution to the Stair Climbing problem.
long dp_num_climbs(int);

int main() {
    int num_steps;
    cout << "How many steps? ";
    cin >> num_steps;

    long x = dp_num_climbs(num_steps);
    cout << "Number of ways to reach the top (DP): " << x << endl;

    long y = rec_num_climbs(num_steps);
    cout << "Number of ways to reach the top (RE): " << y << endl;
    return 0;
}

long rec_num_climbs(int num_steps) { 
    if (num_steps == 0 || num_steps == 1)
        return 1;   
    return rec_num_climbs(num_steps - 1) + rec_num_climbs(num_steps - 2);
}

long dp_num_climbs(int num_steps) {
    if (num_steps < 2) {
        return num_steps;
    }
    long a[num_steps + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= num_steps; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[num_steps];
}