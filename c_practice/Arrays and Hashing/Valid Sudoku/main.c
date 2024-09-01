#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int* hash = calloc(10, sizeof(int)); 

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            if (hash[board[i][j] - '0'] == 1) {
                free(hash); 
                return false; 
            }
            hash[board[i][j] - 48] = 1; 
        }
        memset(hash, 0, 10 * sizeof(int));
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[j][i] == '.') continue;
            if (hash[board[j][i] - 48] == 1) {
                free(hash); 
                return false; 
            }
            hash[board[j][i] - 48] = 1; 
        }
        memset(hash, 0, 10 * sizeof(int));
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (board[i + x][j + y] != '.') {
                        if (hash[board[i + x][j + y] - '0'] == 1) {
                            free(hash);
                            return false;
                        }
                        hash[board[i + x][j + y] - '0'] = 1;
                    }
                }
            }
            memset(hash, 0, 10 * sizeof(int));
        }
    }

    free(hash); 
    return true; 
}

void testIsValidSudoku() {
    // Test case 1: Valid Sudoku board
    char validBoard[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    if (isValidSudoku(validBoard)) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
    }

    // Test case 2: Invalid Sudoku board (repeating number in a row)
    char invalidBoardRow[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'5', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    if (!isValidSudoku(invalidBoardRow)) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
    }

    // Test case 3: Invalid Sudoku board (repeating number in a column)
    char invalidBoardColumn[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'5', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    if (!isValidSudoku(invalidBoardColumn)) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
    }

    // Test case 4: Invalid Sudoku board (repeating number in a sub-box)
    char invalidBoardSubBox[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    if (!isValidSudoku(invalidBoardSubBox)) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
    }
}

int main() {
    testIsValidSudoku();
    return 0;
}
