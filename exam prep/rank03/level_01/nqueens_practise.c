#include <stdlib.h>
#include <stdio.h>

void nqueens(int n);
int is_safe(int *board, int row, int col);
void solve(int *board, int row, int n);

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	int n = atoi(av[1]);

	nqueens(n);
	return 0;
}

void nqueens(int n)
{
	int board[n];

	solve(board, 0, n);
}

void solve(int *board, int row, int n)
{
	static int solution = 0;
	if (row == n)
	{
		solution++;
		printf("%d", solution);
	}

	int col = 0;
	while (col < n)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve(board, row+1, n);
		}
		col++;
	}
}

int is_safe(int *board, int row, int col)
{
	int i = 0;
	//i is row
	while (i < row)
	{
		if (board[i] == col)
			return 0;
		if (abs(board[i]-col) == abs(i - row))
			return 0;
		i++;
	}
	return 1;
}













