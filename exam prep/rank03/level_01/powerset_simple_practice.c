#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_subset(int *subset, int size);
void find_subsets(int *set, int set_size, int *subset, int subset_size, int sum, int index);

int main(int ac, char **av)
{
	if (ac != 3)
		return 1;

	int set[100];
	int subset[100];
	
	int sum = atoi(av[1]);

	int i = 0;
	char *token = strtok(av[2], " ");
	while (token != NULL)
	{
		set[i] = atoi(token);
		token = strtok(NULL, " ");
		i++;
	}
	int set_size = i;

	find_subsets(set, set_size, subset, 0, sum, 0);
	return 0;

}

void find_subsets(int *set, int set_size, int *subset, int subset_size, int sum, int index)
{
	int i = 0;
	int subset_sum;
	//base case
	if (index == set_size)
	{
		subset_sum = 0;
		while (i < subset_size)
		{
			subset_sum += subset[i];
			i++;
		}
                if (subset_sum == sum)
                        print_subset(subset, subset_size);
                return;
	}
	subset[subset_size] = set[index];
        find_subsets(set, set_size, subset, subset_size + 1, sum, index + 1);
        find_subsets(set, set_size, subset, subset_size, sum, index + 1);
}

void print_subset(int *subset, int size)
{
	printf("{");
	int i = 0;
	while (i < size)
	{
		if (i > 0)
			printf(" ");
		printf("%d",subset[i]);
		i++;
	}
	printf("}\n");
}
