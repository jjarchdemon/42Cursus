#include <unistd.h>

int	ft_strlen(char *s)
{
	int	len = 0;
	while(s[len])
		len++;
	return len;
}

int	count_unbalance(char *str)
{
	int	i = 0;
	int	open = 0;
	int	close = 0;

	while(str[i])
	{
		if(str[i] == '(')
			open++;
		else if(str[i] == ')')
		{
			if(open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	print_solution(char *str, int *remove_pos, int remove_count)
{
	int	i = 0;

	while(str[i])
		{
				int     should_skip = 0;
				int     j = 0;

				while(j < remove_count)
				{
						if(i == remove_pos[j])
						{
								should_skip = 1;
								break;
						}
						j++;
				}
				if(!should_skip)
						write(1, &str[i], 1);
		else
			write(1, " ", 1);
				i++;
		}
	write(1, "\n", 1);
}

void	check_combination(char *str, int *remove_pos, int remove_count)
{
	char	temp[1000];
	int	i = 0, j = 0;

	while(str[i])
	{
		int	should_skip = 0;
		int	k = 0;

		while(k < remove_count)
		{
			if(i == remove_pos[k])
			{
				should_skip = 1;
				break;
			}
			k++;
		}
		if(!should_skip)
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	if(count_unbalance(temp) == 0)
	{
		print_solution(str, remove_pos, remove_count);
	}
}

void	try_combinations(char *str, int *remove_pos, int remove_count, int len, int selected_pos, int start)
{
	if(selected_pos == remove_count)
	{
		check_combination(str, remove_pos,  remove_count);
		return;
	}
	int i = start;
	while(i < len)
	{
		remove_pos[selected_pos] = i;
		try_combinations(str, remove_pos, remove_count, len, selected_pos + 1, i + 1);
		i++;
	}
}

void	solve(char *str)
{
	int	len = ft_strlen(str);
	int	remove_count = count_unbalance(str);

	if(remove_count == len)
	{
		int	i = 0;
		while(str[i])
		{
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		return;
	}
	int	remove_pos[1000] = {0};
	try_combinations(str, remove_pos, remove_count, len, 0, 0);
}

int	main(int argc, char **argv)
{
	char	*str;

	if(argc != 2)
		return 1;
	str = argv[1];
	if(count_unbalance(str) == 0)
	{
		int	i = 0;
		while(str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n",1);
		return 0;
	}
	solve(str);
	return 0;
}
