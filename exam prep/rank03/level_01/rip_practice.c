#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str);
void rip(char *str, int n, int open, int close);

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	
	int len = ft_strlen(av[1]);
	char str[len+1];
	
	//mmr
	//m
	int i = 0;
	while(av[1][i])
	{
		str[i] = av[1][i];
		i++;
	}
	str[i] = 0;
	//m
	int open = 0;
	int close = 0;
	i =0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if(str[i] == ')')
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
	int i = 0;
	int bal = 0;
	while (str[i])
	{
		if (str[i] == '(')
			bal++;
		else if (str[i] == ')')
		{
			bal--;
			if (bal<0)
				return 0;
		}
		i++;
	}
	return (bal == 0);
}

void rip(char *str, int n, int open, int close)
{
	if (open == close)
	{
		if (is_valid(str))
			puts(str);
		return;
	}
	int i = n;
	while (str[i])
	{
		if (str[i] == '(' && open>0)
		{
			str[i] = ' ';
			rip(str, i+1, open-1, close);
			str[i] = '(';
		}
		else if (str[i] == ')' && close>0)
		{
			str[i] = ' ';
			rip(str, i+1, open, close-1);
			str[i] = ')';
		}
		i++;
	}
}





















