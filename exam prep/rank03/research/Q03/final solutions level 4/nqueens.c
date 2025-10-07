# include <stdio.h>
# include <stdlib.h>

int	is_safe(int *board, int row, int col)
{
	int i;//i is the row index of sorts here

	i = 0;
	while (i < row)
	{
		if (board[i] == col || abs(board[i] - col) == abs(i - row))
			return 0;
		else
		{
			i++;
		}
	}
	return 1;
}

void solve(int *board, int row, int n, int *solutions)
{
	int col;

	if (row == n)
	{
		(*solutions)++;
		return ;
	}
	else
	{
		col = 0;
		while (col < n)
		{
			if (is_safe(board, row, col))
			{
				board[row] = col;
				solve(board, row + 1, n, solutions);
			}
			col++;
		}
	}
}

int	nqueens(int n)
{
	int	board[n];
	int	solutions;

	solutions = 0;
	solve(board, 0, n, &solutions);
	return (solutions);
}

int main(void)
{
	int no_of_solutions;

	no_of_solutions = nqueens(4);
	printf("Number of solutions: %d\n", no_of_solutions);
	return (0);
}
