#include <stdio.h>


int ft_abs(int a)
{
    if (a < 0)
        return (a * -1);
    else
        return a;
}

int is_safe(int *board, int row, int col)
{
    int i;

    i = 0;
    while (i < row)
    {
        if (board[i] == col || ft_abs(board[i]-col) == ft_abs(i - row))
            return (0);
        i++;
    }
    return (1);
}


void place_queens (int *board, int row, int n, int *solutions)
{
    int     col;
    
    if (row == n)
    {
        (*solutions)++;
        return ;
    }
    col = 0;
    while (col < n)
    {
        if (is_safe(board, row, col))
        {
            board[row] = col;
            place_queens(board, row + 1, n, solutions);
        }
        col++;
    }
}

int nqueens(int n)
{
    int solutions;
    int board[n];

    solutions = 0;
    place_queens(board, 0, n, &solutions);
    return (solutions);
}

int main(void)
{
    int i;

    i = nqueens(7);
    printf("Solutions: %d", i);
    return (0);
}