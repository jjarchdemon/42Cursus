
static long	ft_atol(char *s)
{
	long	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s <= 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num * sign);
}

static void	append_node(t_node **stack, int n)
{
}

void	init_stack_a(t_node **a, char **av)
{
	long	n;
	int	i;

	i = 0;
	while (*av)
	{
		if 
	}

}
