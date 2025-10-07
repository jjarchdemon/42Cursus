#include <unistd.h>

void	print_string(char *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &array[i++], 1);
	}
	write(1, "\n", 1);
}

void swap (char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	generate_permutations(char *arr, int start, int size)
{

	if (start == size)
	{
		print_string(arr, size);
		return ;
	}
	int	i = start;
	while (i < size)
	{
		swap(&arr[start], &arr[i]);
		generate_permutations(arr, start + 1, size);
		swap(&arr[start], &arr[i]);
		i++;
	}
}

//bubble sort
void sort_alpha(int size, char *input)
{
    // Repeat passes through the array
    for (int i = 0; i < size - 1; i++)
    {
        // Compare each pair of adjacent elements
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (input[j] > input[j + 1])
                swap(&input[j], &input[j+1]);// Swap if out of order
        }
    }
}


int main(int ac, char **av)
{

	int 	size;
	char	*input;

	if (ac != 2)
		return (0);
	input = av[1];
	size = 0;
	while (input[size])
		size++;
	sort_alpha(size, input);
	generate_permutations(input, 0, size);
	return (0);
}
