#include <stdio.h>
void	print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		printf("%d ", array[i++]);
	}
	printf("%d\n", array[i]);
}

void swap (int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	generate_permutations(int *arr, int start, int size)
{
	int	i;

	if (start == size)
	{
		print_array(arr, size);
		return ;
	}
	i = start;
	while (i < size)
	{
		swap(&arr[start], &arr[i]);
		generate_permutations(arr, start + 1, size);
		swap(&arr[start], &arr[i]);
		i++;
	}
}



int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("All permutations of the array:\n");
    generate_permutations(arr, 0, size);

    return 0;
}
