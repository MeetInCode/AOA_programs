#include <stdio.h>

#define N 8  // 8x8 chessboard, 8 queens

int board[N][N];  // 0 = empty, 1 = queen

// Check if placing a queen at (row, col) is safe
int isSafe(int row, int col) {
    // Check column for another queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;  // Same column threat
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;  // Diagonal threat
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return 0;  // Diagonal threat
    }

    // No threats found, safe to place
    return 1;
}

// Recursive backtracking function to solve N-Queens
int solveNQueens(int row) {
    // Base case: all queens placed successfully
    if (row == N)
        return 1;

    // Try placing queen in all columns of current row
    for (int col = 0; col < N; col++) {
        // Check if queen can be placed here
        if (isSafe(row, col)) {
            board[row][col] = 1;  // Place queen

            // Recur to place next queen in next row
            if (solveNQueens(row + 1))
                return 1;  // Solution found

            board[row][col] = 0;  // Backtrack if needed
        }
    }

    // No valid position found in this row
    return 0;
}

// Print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    // Initialize the board to 0 (no queens)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Start solving from the first row
    if (solveNQueens(0))
        printBoard();  // Print the first solution found
    else
        printf("No solution exists.\n");

    return 0;
}
