#include <stdio.h>

void rip(char *str, int i, int open, int close);
int ft_strlen(char *str);
int is_valid(char *str);

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	//mmr
	//mutable array, min open,close, recur
	//is valid
	
	int str_len = ft_strlen(av[1]);
	char str[str_len +1];
	int i = 0;
	while (av[1][i])
	{
		str[i] = av[1][i];
		i++;
	}
	str[i] = 0;	//i is now len+1
	
	int open = 0;
	int close = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}

	rip(str, 0, open, close);
	return 0;
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int is_valid(char *str)
{
	int bal = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			bal++;
		else if (str[i] == ')')
		{
			bal--;
			if (bal < 0)
				return 0;
		}
		i++;
	}
	return (bal == 0);
}


void rip(char *str, int i, int open, int close)
{
	if (open == close)
	{
		if (is_valid(str))
			puts(str);
		return;
	}

	while (str[i])
	{
		if (str[i] == '(' && open > 0)
		{
			str[i] = ' ';
			rip(str, i+1,open-1, close);
			str[i] = '(';
		}
		else if (str[i] == ')' && close > 0)
		{
			str[i] = ' ';
			rip(str, i+1,open, close-1);
			str[i] = ')';
		}
		i++;
	}
}






















