#include "libftprintf.h"

int	pick_formatter(va_list ag, const char formatter)
{
	int	count;

	count = 0;
	if (formatter == 'c')
		count += ft_putchar(va_arg(ag, int));
	else if (formatter == 's')
		count += ft_putstr(va_arg(ag, const char *));
	else if (formatter == 'p')
		count += ft_putptr(va_arg(ag, unsigned long long));
	else if (formatter == 'd' || formatter == 'i')
		count += ft_putnumbr(va_arg(ag, int), 1);
	else if (formatter == 'u')
		count += ft_putnumbr(va_arg(ag, unsigned int), 0); //TODO fix this
	else if (formatter == 'x')
	{
		//count += ft_putstr("0x");
		count += ft_puthex(va_arg(ag, unsigned int), 'a');
	}
	else if (formatter == 'X')
	{
		//count += ft_putstr("0X");
		count += ft_puthex(va_arg(ag, unsigned int), 'A');
	}
	return (count);
}
