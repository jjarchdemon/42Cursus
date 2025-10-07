# include <stdio.h>
# include <stdlib.h>

int is_safe(int *board, int row, int col)
{
    int i;

    i = 0;
    while (i < row) 
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
        i++;
    }
    return 1;
}

void solve(int *board, int row, int n, int *solutions) 
{
    int col;    
    
    if (row == n) {              // Base case: All queens placed
        (*solutions)++;          // Step 3: Increment solutions
        return;
    }
    col = 0;
    while (col < n)
    {
        if (is_safe(board, row, col))
        {
            board[row] = col; // board[0] = 0, 1, 2, 3, board[1] = 0
            solve(board, row + 1, n, solutions); // Recursive step
        }
        col++;
    }
}

int nqueens(int n) 
{
    int solutions = 0;           // Step 1: Initialize solutions to 0
    int board[n];                // Array to represent the board (one queen per row)
    solve(board, 0, n, &solutions); // Step 2: Pass solutions by reference
    return solutions;            // Step 4: Return the final count of solutions
}

int main(void)
{
    int n;
    
    n = nqueens(10);
    printf("Number of solutions: %d\n", n);
    return (0);
}

