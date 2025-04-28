#include "validator_single.h"

bool check_row(int sudoku[9][9], int row) {
    bool seen[10] = { false };
    for (int i = 0; i < 9; i++) {
        int num = sudoku[row][i];
        if (num < 1 || num > 9 || seen[num]) return false;
        seen[num] = true;
    }
    return true;
}

bool check_col(int sudoku[9][9], int col) {
    bool seen[10] = { false };
    for (int i = 0; i < 9; i++) {
        int num = sudoku[i][col];
        if (num < 1 || num > 9 || seen[num]) return false;
        seen[num] = true;
    }
    return true;
}

bool check_grid(int sudoku[9][9], int startRow, int startCol) {
    bool seen[10] = { false };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = sudoku[startRow + i][startCol + j];
            if (num < 1 || num > 9 || seen[num]) return false;
            seen[num] = true;
        }
    }
    return true;
}

bool validate_sudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (!check_row(sudoku, i) || !check_col(sudoku, i))
            return false;
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!check_grid(sudoku, i, j))
                return false;
        }
    }
    return true;
}
