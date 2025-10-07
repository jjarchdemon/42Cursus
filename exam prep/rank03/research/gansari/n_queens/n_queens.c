#include "n_queens.h"

void	print_solution(int *board, int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		printf("%d", board[i]);
		if(i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int	is_safe(int *board, int	col, int row)
{
	int	i;

	i = 0;
	while(i < col)
	{
		if(board[i] == row)
			return 0;
		if(board[i] - i == row - col)
			return 0;
		if(board[i] + i == row + col)
			return 0;
		i++;
	}
	return 1;
}

void	backtrack(int *board, int col, int n)
{
	int	row;

	if(col == n)
	{
		print_solution(board, n);
		return ;
	}
	row = 0;
	while(row < n)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			backtrack(board, col + 1, n);
		}
		row++;
	}
}

void	solve_nqueen(int n)
{
	int	board[n];
	int	i;

	i = 0;
	while(i < n)
	{
		board[i] = -1;
		i++;
	}
	backtrack(board, 0, n);
}

int	main(int argc, char **argv)
{
	int	n;

	if(argc != 2)
		return 1;
	n = atoi(argv[1]);
	if(n == 0)
		return 0;
	solve_nqueen(n);
	return 0;
}
