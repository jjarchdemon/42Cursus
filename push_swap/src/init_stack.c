
static long	ft_atol(char *s)
{
	long	result;
	int	sign;

	result = 0;
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
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
