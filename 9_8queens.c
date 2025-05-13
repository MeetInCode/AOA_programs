#include <stdio.h>

// board[i] stores the column index of the queen placed in the i-th row
int board[8];

// Function to check if placing a queen at (row, col) is safe
int isSafe(int row, int col)
{  //row means current row // check evrything for all rows till current row
    for (int i = 0; i < row; i++)
    {
        // Check if another queen is in the same column,
        // or on the same diagonal
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
        {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Recursive function to solve the N-Queens problem
int solve(int row)
{
    // All 8 queens placed successfully
    if (row == 8)
        return 1;

    // Try placing queen in all columns one by one
    for (int col = 0; col < 8; col++)
    {
        // If placing queen at (row, col) is safe
        if (isSafe(row, col))
        {
            board[row] = col;   // Place queen
            if (solve(row + 1)) // Recurse for next row
                return 1;       // Solution found
        }
    }
    return 0; // No solution found for this row
}

// Function to print the 8x8 chessboard with queens
void printBoard()
{
    // Loop through each row of the board
    for (int i = 0; i < 8; i++)
    {
        // Loop through each column in the current row
        for (int j = 0; j < 8; j++)
        {
            // Check if the current position has a queen
            // Remember: board[i] stores the column where a queen is placed in row i
            if (j == board[i])
            {
                printf("Q "); // Print 'Q' for positions with a queen
            }
            else
            {
                printf(". "); // Print '.' for empty positions
            }
        }
        printf("\n"); // Move to the next line after printing a row
    }
}

int main()
{
    solve(0);     // Start solving from row 0
    printBoard(); // Display the solution
    return 0;
}
