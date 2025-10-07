#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_parentheses(int n, int open, int close, char *buffer, int pos)
{
	if (pos == 2 * n)
	{
		buffer[pos] = '\0';
		printf("%s\n", buffer);
		return;
	}
	if (open < n)
	{
		buffer[pos] = '(';
		generate_parentheses(n, open + 1, close, buffer, pos + 1);
	}
	if (close < open)
	{
		buffer[pos] = ')';
		generate_parentheses(n, open, close + 1, buffer, pos + 1);
	}
}

int main(void)
{
	int		n = 2;
	char	*buffer;

	//printf("Enter the number of pairs of parentheses: ");
	//scanf("%d", &n);
	if (n <= 0)
	{
		printf("No valid combinations for n <= 0.\n");
		return 0;
	}
	buffer = malloc((2 * n + 1) * sizeof(char));
	if (!buffer)
	{
		perror("malloc failed");
		return 1;
	}
	generate_parentheses(n, 0, 0, buffer, 0);
	free(buffer);
	return 0;
}
