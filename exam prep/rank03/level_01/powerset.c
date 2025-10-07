#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_subset(int *subset, int size)
{
	printf("{");
	int i = 0;
	while (i < size)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("}\n");
}

void find_subsets(int *set, int set_size, int *subset, int subset_size, int sum, int index)
{
	int i;
	int subset_sum;

	i = 0;
	if (index == set_size)
	{
		subset_sum = 0;
		while (i < subset_size)
			subset_sum += subset[i++];
		if (subset_sum == sum)
			print_subset(subset, subset_size);
		return;
	}
	subset[subset_size] = set[index];
	find_subsets(set, set_size, subset, subset_size + 1, sum, index + 1);
	find_subsets(set, set_size, subset, subset_size, sum, index + 1);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <sum> <set of numbers>\n", argv[0]);
		return 1;
	}
	
	int sum = atoi(argv[1]);
	
	int set[100];
	/*
	int *set = malloc(100 * sizeof(int));
	if (!set)
	{
		perror("malloc");
		return 1;
	}
	*/

	char *set_str = argv[2];
	// Split the input string into numbers and store them in the set array
	char *token = strtok(set_str, " ");  // Get the first number as a string
	int index = 0;                        // Track how many numbers we have

	while (token != NULL)                  // Continue until no more tokens
	{
	    int number = atoi(token);          // Convert the string to an integer
	    set[index] = number;               // Store the number in the array
	    index++;                            // Move to the next position in the array
	    token = strtok(NULL, " ");         // Get the next number
	}
	// set_size is the total number of numbers
	int set_size = index;
	
	int subset[100];
	/*
	int *subset = malloc(set_size * sizeof(int));
	if (!subset)
	{
		perror("malloc");
		free(set);
		return 1;
	}
	*/

	find_subsets(set, set_size, subset, 0, sum, 0);
	//free(set);
	//free(subset);
	return 0;
}
