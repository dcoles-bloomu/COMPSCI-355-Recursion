/*
 * Implementation file for Board class.
 *
 * Author: Drue Coles
 */

#include <iomanip>
#include "board.h"

Board::Board(int row_count, int col_count) {
    this->r_count = row_count;
    this->c_count = col_count;
    init(); // allocate memory for a new board
}

Board::Board(const Board& other) {
    r_count = other.r_count;
    c_count = other.c_count;
    init(); // allocate memory for a new board

    // copy contents of other board
    for (int i = 0; i < r_count; i++) {
        for (int j = 0; j < c_count; j++) {
            board[i][j] = other.board[i][j];
        }
    }
}

// allocate memory for a new board 
void Board::init() { 
    board = new int*[c_count];
    for (int i = 0; i < r_count; i++) {
        board[i] = new int[c_count];
        for (int j = 0; j < c_count; j++) {
            board[i][j] = 0; // empty
        }
    }
}

Board::~Board() {
    release();
}

void Board::release() {
    for (int i = 0; i < r_count; i++) {
        delete []board[i]; // deallocate each row
    }
    delete []board; // deallocate array of pointers to rows
}

Board& Board::operator=(const Board& other) {
    if (this == &other) {
        return *this;
    }

    // If dimensions do not match, reallocate storage.
    if (r_count != other.r_count || c_count != other.c_count) {
        release();
        r_count = other.r_count;
        c_count = other.c_count;
        init(); // allocate memory for empty board
        
        // copy contents of other board
        for (int i = 0; i < r_count; i++) {
            for (int j = 0; j < c_count; j++) {
                board[i][j] = other.board[i][j];
            }
        }
    }
    return *this;
}

int& Board::operator()(int r, int c) const {
    return board[r][c];
}

bool Board::valid(int r, int c) {
    return r >= 0 && c >= 0 && r < r_count && c < c_count;
}

ostream& operator<<(ostream& out, const Board& board) {
    for (int i = 0; i < board.row_count(); i++) {
        for (int j = 0; j < board.col_count(); j++) {
            out << setw(4) << board(i, j);
        }
        out << endl;
    }
    return out;
}