#include <stdio.h>
#include <stdlib.h>

int nqueens(int n);
void solve(int *board, int row, int n, int *solutions);
int is_safe(int row, int col, int *board);
void print_line(int i, int n);
void print_board(int *board, int n);

int main(int ac, char **av)
{
	int no_of_solutions;
	if (ac == 2)
	{
		no_of_solutions = nqueens(atoi(av[1]));
		printf("there are %d solutions\n", no_of_solutions);
	}
	return 0;
}

int nqueens(int n)
{
	int board[n];
	int solutions = 0;

	solve(board, 0, n, &solutions); //0 is the row
	return(solutions);
}

void solve(int *board, int row, int n, int *solutions)
{
	int col;

	//base case
	if (row == n)
	{
		(*solutions)++;
		print_board(board, n);
		return;
	}
	col = 0;
	while (col < n)
	{
		if (is_safe(row, col, board)) //uh_oh
		{
			board[row] = col; //placing the queen
			solve(board, row + 1, n, solutions);//+1 to sink further into next
							     //level of recursion
		}
		col++;
	}
}

int is_safe(int row, int col, int *board)
{
	int i = 0;//row index of sorts
	while (i < row)
	{
		//condition of queen placement-same col or diagonally
		if (board[i] == col || abs(board[i] - col) == abs(i - row))
			return 0;
		i++;
	}
	return 1;
}

// board = {0,1,2,3}    Q***
// 			*Q**
// 			**Q*
// 			***Q
void print_board(int *board, int n)
{
	int i = 0;
	while (i < n)
	{
		print_line(board[i], n);
		i++;
	}
	printf("\n");
}

void print_line(int i, int n)
{
	char line[n];
	
	int index = 0;
	while(index < n)
	{
		if (index == i)
			line[index] = 'Q';
		else
			line[index] = '*';
		index++;
	}
	line[n] = 0;
	printf("%s\n", line);
}
















