// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	long	number;
	long	number_orig;
	int		digits;
	char	*result;
	int		negative;
	int		i;

	digits = 0;
	if (nbr == 0)
		digits = 1;
	negative = 0;
	if (nbr < 0)
		negative = 1;
	number = (long) nbr;
	if (number < 0)
		number = number * -1;
	number_orig = number;
	while (number > 0)
	{
		number = number / 10;
		digits++;
	}
	number = number_orig;
	result = malloc (digits + negative + 1);
	if (!result)
		return (NULL);
	result[digits + negative] = '\0';
	i = 0;
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		result[digits + negative - 1] = number % 10 + '0';
		number = number / 10;
		digits--;
	}
	if (negative)
		result[0] = '-';
	return (result);
}

#include <stdio.h>
#include <limits.h>

int main (void)
{
	char *result;

	result = ft_itoa(INT_MIN);
	printf("Result: %s\n", result);
	free (result);
	result = ft_itoa(INT_MIN);
	printf("Result: %s\n", result);
	free (result);
	return (0);
}
