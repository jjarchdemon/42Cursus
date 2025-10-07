#include <stdio.h>   // for printf - used to print the final result
#include <stdlib.h>  // for abs - used to compute absolute difference of ints

/* 
 * Check if placing a queen at (row, col) is safe given the partial board.
 * board[i] == c means there's a queen at row i, column c for i < row.
 */
int is_safe(int *board, int row, int col) {            // function header
    int i;                                             // loop variable for earlier rows
    i = 0;
    while (i < row){                        // check every previously-filled row
        if (board[i] == col) {                         // if any earlier queen is in same column
            return 0;                                  // not safe -> return false (0)
        }
        /* 
         * if the horizontal distance (columns) equals vertical distance (rows),
         * the queens are on the same diagonal -> not safe.
         */
        if (abs(board[i] - col) == abs(row - i)) {          // diagonal conflict check
            return 0;                                  // not safe -> return false (0)
        }
	i++;
    }
    return 1;                                          // no conflicts found -> safe (true/1)
}

void solve(int *board, int row, int n, int *solutions) { // recursive backtracking function
    int col;                                           // column loop variable
    if (row == n) {                                    // base case: placed queens on all rows
        (*solutions)++;                                // found a full valid solution -> increment count
        return;                                        // return to try other possibilities
    } else {                                           // still have rows to fill
        col = 0;                                       // start trying columns from 0
        while (col < n) {                              // try each column in the current row
            if (is_safe(board, row, col)) {            // only proceed if (row,col) is safe
                board[row] = col;                      // place the queen at this column for current row
                solve(board, row + 1, n, solutions);   // recursively place queens in the next row
                /* 
                 * no explicit "undo" needed: we will overwrite board[row] when we try
                 * another column in this row, so the previous placement is effectively undone.
                 */
            }
            col++;                                     // try the next column
        }
    }
}

int nqueens(int n) {                                  // helper that prepares and starts the solver
    int board[n];                                      // board[row] = column of queen in that row (variable-length array)
    int solutions;                                     // counter for number of solutions found

    solutions = 0;                                     // initialize counter to zero
    solve(board, 0, n, &solutions);                    // start recursion at row 0
    return (solutions);                                // return the total count
}

int main(void) {                                      // program entry point
    int n;                                             // variable to receive the returned solution count

    n = nqueens(9);                                    // compute number of solutions for 9×9 board
    printf("Number of solutions: %d\n", n);            // print the result
    return (0);                                        // return success status to the OS
}
