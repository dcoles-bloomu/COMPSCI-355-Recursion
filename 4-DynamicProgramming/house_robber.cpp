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
 * The program solves the problem for two test cases using two strategies, DP and recursion.
 * For the second (longer) test case, execution time is displayed to contrast the strategies 
 * in terms of efficiency.
 *
 * Output:
 *
 *      DP solution to test case 1: 26
 *      RE solution to test case 1: 26
 *      DP solution to test case 2: 3176 (0 ms)
 *      RE solution to test case 2: 3176 (4189 ms)
 *
 * Author: Drue Coles
 */

#include <cassert>
#include <iostream>
#include <algorithm> // for max function
#include <chrono> // for execution timing
using namespace std;
using namespace std::chrono;

int dp_house_robber(int money[], int num_houses); // DP solution
int rec_house_robber(int money[], int num_houses); // utilty wrapper around recursive solution
void rec_house_robber(int[], int, int, int, int&); // recursive solution

int main() {
    // CodeSignal test case (solution = 26)
    int money[] = {2, 1, 2, 6, 1, 8, 12, 10}; 
    cout << "DP solution to test case 1: " << dp_house_robber(money, 8) << endl; 
    cout << "RE solution to test case 1: " << rec_house_robber(money, 8) << endl; 
    

    // CodeSignal test case (solution = 3176)
    int money2[] = {104, 209, 137, 52, 158, 67, 213, 86, 141, 110, 151, 127, 238, 147, 169, 
        138, 240, 185, 246, 225, 147, 203, 83, 83, 131, 227, 54, 78, 165, 180, 214, 151, 
        111, 161, 233, 147, 124, 143}; 
    
    // output results with execution time for DP solution 
    auto start = high_resolution_clock::now();
    cout << "DP solution to test case 2: " << dp_house_robber(money2, 38); 
    auto stop = high_resolution_clock::now();
    long duration = duration_cast<milliseconds>(stop - start).count();
    cout << " (" << duration << " ms)" << endl;

    // output results with execution time for recursive solution
    start = high_resolution_clock::now();
    cout << "RE solution to test case 2: " << rec_house_robber(money2, 38); 
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start).count();
    cout << " (" << duration << " ms)" << endl;

    return 0;
}

int dp_house_robber(int money[], int num_houses) {
    if (num_houses == 0) {
        return 0;
    }
    if (num_houses == 1) {
        return money[0];
    }

    int a[num_houses];
    a[0] = money[0];
    a[1] = max(money[0], money[1]);

    // bottom up
    for (int j = 2; j < num_houses; j++) {
       a[j] = max(money[j] + a[j-2], a[j-1]);
    }
    return a[num_houses-1];
}

// utilty wrapper around recursive function
int rec_house_robber(int money[], int num_houses) {
    int max = 0;
    rec_house_robber(money, num_houses, 0, 0, max);
    return max;
}

// n = number of houses (size of money array)
// k = current index (currently at the k-th house)
// s = current sum (money stolen from the first k-1 houses)
void rec_house_robber(int money[], int n, int k, int s, int& max) {
    if (k < n) {
        rec_house_robber(money, n, k+1, s, max);
        rec_house_robber(money, n, k+2, s + money[k], max);
    }
    max = s > max ? s : max; 
}                                                                               