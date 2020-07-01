/*
 * Implementation file for Board class.
 *
 * Author: Drue Coles
 */

#include <iomanip>
#include "board.h"

// Initializes empty board.
Board::Board(int row_count, int col_count) {
    this->r_count = row_count;
    this->c_count = col_count;
    board = new int*[col_count];
    init();
}

Board::Board(const Board& board) {
    r_count = board.r_count;
    c_count = board.c_count;
    init();
}

Board::~Board() {
    release();
}

Board& Board::operator=(const Board& board) {
    if (this == &board) {
        return *this;
    }

    // If dimensions do not match, reallocate storage.
    if (r_count != board.r_count || c_count != board.c_count) {
        release();
        r_count = board.r_count;
        c_count = board.c_count;
        init();
    }
    return *this;
}

int& Board::operator()(int r, int c) const {
    return board[r][c];
}

bool Board::valid(int r, int c) {
    return r >= 0 && c >= 0 && r < r_count && c < c_count;
}

void Board::init() {
    for (int i = 0; i < r_count; i++) {
        board[i] = new int[c_count];
        for (int j = 0; j < c_count; j++) {
            board[i][j] = 0;
        }
    }
}

void Board::release() {
    for (int i = 0; i < r_count; i++) {
        delete []board[i]; // deallocate each row
    }
    delete []board; // deallocate array of pointers to rows
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