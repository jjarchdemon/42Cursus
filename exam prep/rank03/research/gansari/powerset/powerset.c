#include <stdio.h>
#include <stdlib.h>

void	print_solution(int *nums, int *selected, int size)
{
	int	i = -1;
	while(++i < size)
	{
		if (selected[i])
		{
			printf("%d", nums[i]);
			if ( i < size - 1)
				printf(" ");
		}
	}
	printf("\n");
}

void	find_combinations(int *nums, int *selected, int	index, int size, int target, int current_sum)
{
	if (index == size)
	{
		if (current_sum == target)
			print_solution(nums, selected, size);
		return ;
	}
	if (current_sum > target)
		return ;
	//don't use the current number
	selected[index] = 0; //not selected
	find_combinations(nums, selected, index + 1, size, target, current_sum);
	//use the number
	selected[index] = 1; //selected
	find_combinations(nums, selected, index + 1, size, target, current_sum + nums[index]);

}
int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: [%s] [num1] [num2] [...]\n", argv[0]);
		return (1);
	}
	int	target = atoi(argv[1]);
	int	size = argc - 2;
	int	nums[size];
	int	selected[size];
	int	i = -1;
	while (++i < size)
	{
		nums[i] =atoi(argv[i + 2]);
		selected[i] = 0;
	}
	find_combinations(nums, selected, 0, size, target, 0);
	return (0);
}
