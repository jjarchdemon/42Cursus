
void find_subset(int *set, int set_size, int *subset, int subset_size, int sum, int index)
{
	int i = 0;
	int subset_sum;
	if (index == set_size)
	{
		subset_sum = 0;
		while (i < subset_size)
		{
			subset_sum += subset[i]; //subset
			i++;
		}
		if (subset_sum == sum)
			//print
		return;
	}

	subset[subset_size] = set[index];
	find_subset(set, set_size, subset, subset_size+1, sum, index+1);
	find_subset(set, set_size, subset, subset_size, sum, index+1);

}


void ft_print(int *subset, int subset_size)
{
	int i =0;
	printf("{");
	while (i < subset_size)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("}");
}


























