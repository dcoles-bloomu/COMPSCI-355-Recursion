/*
 * CodeSignal: interview practice -> dynamic programming -> houseRobber.
 * The following description has been modified for clarity.
 *
 * You are planning to rob houses on a specific street, and you know that
 * every house on the street has a certain amount of money hidden. The
 * only thing stopping you from robbing all of them in one night is that
 * adjacent houses on the street have a connected security system. The
 * system will automatically trigger an alarm if two adjacent houses are
 * broken into on the same night.
 *
 * Given an array of numbers representing the amount of money hidden in
 * each house, determine the maximum amount of money you can steal in one
 * night without triggering an alarm.
 *
 * For example, on input (2, 1, 2, 6, 1, 8, 12, 10) the output should be
 * 26. This total can be obtained as follows:
 *
 *      Money in houses: 2 1 2 6 1 8 12 10
 *        Houses robbed: *     *   *     *
 *
 * Implementation note: Recursive backtracking is used only for the sake
 * of demonstration. The second test case executed in main is noticeably
 * slow. A dynamic programming solution would be much more efficient. For
 * the sake of comparison, the execution time for the second test case is
 * displayed.
 *
 * Author: Drue Coles
 */

#include <cassert>
#include <iostream>
#include <algorithm> // for max
#include <chrono> // for timing
using namespace std;
using namespace std::chrono;

int max_stolen = 0;

/*
 * Recursive backtracking algorithm for determining the maximum
 * amount of money that can be stolen in one night. The result
 * is recorded in the global variable max_stolen.
 *
 * money[i] = amount hidden in the i-th house
 * k = index of current house
 * total = amount obtained from previously robbed houses
 */
void rec_house_robber(int money[], int num_houses, int k, int total);

// Wrapper around recursive backtracker.
void house_robber(int money[], int num_houses);

// Verifies correctness of recursive backtracking algorithm for two 
// test cases.
int main() {
    int money[] = {2, 1, 2, 6, 1, 8, 12, 10};
    int solution = 26;
    house_robber(money, 8);
    assert(max_stolen == solution);
    cout << "Test 1: PASSED\n" << endl;

    // a CodeSignal test case
    int money2[] = {104, 209, 137, 52, 158, 67, 213, 86, 141,
    		110, 151, 127, 238, 147, 169, 138, 240, 185, 246, 
		    225, 147, 203, 83, 83, 131, 227, 54, 78, 165, 180, 
		    214, 151, 111, 161, 233, 147, 124, 143}; 
    int solution2 = 3176;

    auto start = high_resolution_clock::now();
    house_robber(money2, 38);
    auto stop = high_resolution_clock::now();
    long duration = duration_cast<milliseconds>(stop - start).count();
    
    assert(max_stolen == solution2);
    cout << "Test 2: PASSED" << endl;
    cout << "Execution time: " << duration << " milliseconds." << endl;
    return 0;
}

void house_robber(int money[], int num_houses) {
    max_stolen = 0;
    rec_house_robber(money, num_houses, 0, 0);
}

void rec_house_robber(int money[], int num_houses, int k, int total) {
    if (k >= num_houses) {
        if (total > max_stolen) {
            max_stolen = total;
        }
        return;
    }
    rec_house_robber(money, num_houses, k + 1, total);
    rec_house_robber(money, num_houses, k + 2, total + money[k]);
}