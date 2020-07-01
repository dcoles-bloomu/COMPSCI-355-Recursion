/*
 * Header file for class representing a chessboard.
 *
 * Author: Drue Coles
 */

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
using namespace std;

class Board {
    // Writes contents of a board to output console.
    friend ostream& operator<<(ostream&, const Board&);

public:
    Board(int, int); // Constructs new board with specified dimensions.
    Board(const Board&);
    ~Board();
    Board& operator=(const Board&);

    // Returns reference to value at specified location.
    // Assumes zero-based indexing.
    int& operator()(int r, int c) const;

    int row_count() const {return r_count;}
    int col_count() const {return c_count;}

    // Returns true if specified location is value.
    // Assumes zero-based indexing.
    bool valid(int, int);

private:
    int** board;
    int r_count;
    int c_count;

    void init(); // Allocates table memory and fill with zeros.
    void release(); // Deallocates table memory.
};
#endif