#include "libftprintf.h"

int     ft_putnumbr(int nb) //TODO for unsigned int ?
{
        long   num;
        int     count;

        num = (long)nb;//TODO error handling
        count = 0;
        if (issigned)
        {   
                if (num < 0)
                {   
                        count += ft_putchar('-');
                        num = -num;
                }   
        }   
        if (num == 0 && count == 0)
                count += ft_putchar('0');
        if (num >= 10) 
                count += ft_putnumbr(num / 10, issigned);
        count += ft_putchar((num % 10) + '0');
        return (count);
}

int     ft_putunumbr(unsigned int nb) //TODO for unsigned int ?
{
        unsigned long   num;
        int     count;

        num = (long)nb;//TODO error handling
        count = 0;
        if (issigned)
        {   
                if (num < 0)
                {   
                        count += ft_putchar('-');
                        num = -num;
                }   
        }   
        if (num == 0 && count == 0)
                count += ft_putchar('0');
        if (num >= 10) 
                count += ft_putnumbr(num / 10, issigned);
        count += ft_putchar((num % 10) + '0');
        return (count);
}
