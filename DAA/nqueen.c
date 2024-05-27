#include <stdio.h>
#include <stdbool.h>

#define N 4 // Change N to the desired number of queens

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check upper diagonal on right side
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// A recursive utility function to solve N Queen problem
bool solveNQUtil(int board[N][N], int row) {
    // Base case: If all queens are placed, return true
    if (row >= N) {
        return true;
    }

    // Consider this row and try placing this queen in all columns one by one
    for (int col = 0; col < N; col++) {
        // Check if the queen can be placed on board[row][col]
        if (isSafe(board, row, col)) {
            // Place this queen in board[row][col]
            board[row][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, row + 1)) {
                return true;
            }

            // If placing queen in board[row][col] doesn't lead to a solution, then backtrack
            board[row][col] = 0; // Remove queen from board[row][col]
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

// This function solves the N Queen problem using Backtracking
bool solveNQ() {
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}

// Driver code
int main() {
    solveNQ();
    return 0;
}
