/*
 * Computes a knight's tour on a chessboard by recursive backtracking,
 * starting from a specified square.
 *
 * Execution snapshot:
 *
 *      Enter board dimensions: 8 8
 *      Enter zero-based indices of starting location: 0 0
 *
 *       1  12   9   6   3  14  17  20
 *      10   7   2  13  18  21   4  15
 *      31  28  11   8   5  16  19  22
 *      64  25  32  29  36  23  48  45
 *      33  30  27  24  49  46  37  58
 *      26  63  52  35  40  57  44  47
 *      53  34  61  50  55  42  59  38
 *      62  51  54  41  60  39  56  43
 *
 *      17739768 recursive calls.
 *
 * Note: For the 8x8 case, starting in the top-left corner, 44 knights
 * are placed before the first dead end is reached. See picture at end
 * of file.
 *
 * Author: Drue Coles
 */

#include <iostream>
#include <iomanip>
#include <cstdlib> // exit
#include "board.h"

using namespace std;

void tour(Board&, int r, int c, int n);

int main() {
    cout << "Enter board dimensions for a knight's tour: ";
    int row_count, col_count;
    cin >> row_count >> col_count;
    Board board(row_count, col_count);

    int start_row, start_col;
    cout << "Enter zero-based indices of starting location: ";
    cin >> start_row >> start_col;
    cout << endl;

    tour(board, start_row, start_col, 1);
    cout << "No knight's tour with these parameters." << endl;
    return 0;
}

// Places n-th knight on board at selected position and
// recursively places next knight.
void tour(Board& board, int r, int c, int n) {

    if (!board.valid(r, c) || board(r, c) != 0) {
        return;
    }

    static long int numberOfCalls = 0;
    numberOfCalls++;

    board(r, c) = n; // place n-th knight on the board

    if (n == board.row_count() * board.col_count()) {
        cout << "Knight's tour:\n" << endl;
        cout << board << endl;
        cout << numberOfCalls << " recursive calls." << endl;
        exit(0);  // Terminate the program.
    }

    // Place next knight recursively.
    tour(board, r - 2, c - 1, n + 1);
    tour(board, r - 2, c + 1, n + 1);
    tour(board, r - 1, c - 2, n + 1);
    tour(board, r - 1, c + 2, n + 1);
    tour(board, r + 1, c - 2, n + 1);
    tour(board, r + 1, c + 2, n + 1);
    tour(board, r + 2, c - 1, n + 1);
    tour(board, r + 2, c + 1, n + 1);

    // Dead end. Remove knight and return to previous level
    // of recursion.
    board(r, c) = 0;
}

/***********************************
  For the 8x8 case, starting in the
  top-left corner, 44 knights are
  placed before the first dead end
  is reached.

   1  12   9   6   3  14  17  20
  10   7   2  13  18  21   4  15
  31  28  11   8   5  16  19  22
  44  25  32  29  38  23  36   -
  33  30  27  24  35   -  39   -
  26  43  34   -  40  37   -   -
   -   -  41   -   -   -   -   -
  42   -   -   -   -   -   -   -
*************************************/