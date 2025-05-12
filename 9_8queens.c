#include <stdio.h>

int board[8]; // board[i] = column position of queen in row i

int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Check if queens are in same column or same diagonals
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
        {
            return 0;
        }
    }
    return 1;
}

int solve(int row)
{
    if (row == 8)
        return 1; // All queens placed

    for (int col = 0; col < 8; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            if (solve(row + 1))
                return 1;
        }
    }
    return 0;
}

void printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf(j == board[i] ? "Q " : ". ");
        printf("\n");
    }
}

int main()
{
    solve(0);
    printBoard();
    return 0;
}
