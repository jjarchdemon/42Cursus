#include <stdlib.h>
#include <stdio.h>

void print_board(int *board, int n);
void nqueens(int n);
void solve(int *board, int row, int n);
int is_safe(int *board, int row, int col);
int ft_abs(int a);

int main (int ac, char **av)
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
	static int s = 1;
	if (row == n)
	{
		printf("so far %d :", s);
		print_board(board, n);
		s++;
		return;
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
	while (i < row)
	{
		if (board[i] == col)
			return 0;
		if (ft_abs(board[i] - col) == ft_abs(i - row))
			return 0;
		i++;
	}
	return 1;
}

int ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return a;
}

void print_board(int *board, int n)
{
	if (n == 0)
		return;
	printf("[");
	int i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n-1)
			printf(" ");
		i++;
	}
	printf("]\n");
}













