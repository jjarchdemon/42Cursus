#include <unistd.h>

void ft_putnbr(int nbr)
{
	char c;
	if (nb < 0)
	{
		write(1,"-",1);
		//case for nb = INT_MAX
		nb = -nb;
	}
	if (nbr < 10)
	{
		c = (nbr%10)+ '0';
		write(1,&c,1);
	}
	else
		ft_putnbr(nbr/10);
}

