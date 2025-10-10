#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A flag to track if at least one solution has been printed.
// 'static' ensures it's initialized to 0 and persists across function calls.
static int g_solution_found = 0;

// Simple swap function for sorting
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort to sort the input set.
// Sorting is crucial for handling duplicate numbers efficiently.
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Prints a given subset in the required format: {1 2 3}
void print_subset(int *subset, int size)
{
    g_solution_found = 1; // Mark that we found at least one solution
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", subset[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
    }
    printf("}\n");
}

// The core recursive function to find subsets
void find_subsets(int *set, int set_size, int *subset, int subset_size, int target_sum, int index)
{
    // Base case: A valid subset is found if the target sum is 0.
    if (target_sum == 0)
    {
        print_subset(subset, subset_size);
        return;
    }

    // Base case: If we've run out of numbers to check, stop this path.
    if (index >= set_size)
    {
        return;
    }

    // --- Recursive Step ---
    for (int i = index; i < set_size; i++)
    {
        // **Key logic for avoiding duplicate subsets**:
        // If the current number is the same as the previous one, skip it.
        // This works because the array is sorted. We only consider the first
        // occurrence of a number at any given decision point.
        if (i > index && set[i] == set[i - 1])
        {
            continue;
        }

        // 1. Include the number set[i] in our current subset
        subset[subset_size] = set[i];

        // 2. Recurse: look for the rest of the sum using numbers from i + 1 onwards
        find_subsets(set, set_size, subset, subset_size + 1, target_sum - set[i], i + 1);

        // 3. Backtrack: The "exclude" case is handled implicitly by the loop,
        // which moves on to the next number (i + 1) in the next iteration.
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        // Per instructions, we don't print an error message, just exit.
        return 1;
    }

    int target_sum = atoi(av[1]);
    char *set_str = av[2];
    int set_size = 0;

    // --- Step 1: Count the numbers to determine memory allocation size ---
    char *str_copy_for_count = strdup(set_str); // Use a copy for strtok
    if (str_copy_for_count == NULL) return 1; // strdup uses malloc internally

    char *token = strtok(str_copy_for_count, " ");
    while (token != NULL)
    {
        set_size++;
        token = strtok(NULL, " ");
    }
    free(str_copy_for_count);

    // Handle empty input set string
    if (set_size == 0) {
        if (target_sum == 0) {
             printf("{}\n"); // Empty set sums to 0
        } else {
             printf("\n"); // No solution
        }
        return 0;
    }

    // --- Step 2: Allocate memory dynamically ---
    int *set = malloc(sizeof(int) * set_size);
    int *subset = malloc(sizeof(int) * set_size);

    if (set == NULL || subset == NULL)
    {
        // Malloc error - exit with code 1 as required
        free(set);
        free(subset);
        return 1;
    }

    // --- Step 3: Parse the string again to fill the allocated array ---
    int i = 0;
    token = strtok(set_str, " ");
    while (token != NULL)
    {
        set[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // --- Step 4: Sort, Find, and Print ---
    bubble_sort(set, set_size);
    find_subsets(set, set_size, subset, 0, target_sum, 0);

    // --- Step 5: Handle the "no solution found" case ---
    if (!g_solution_found)
    {
        printf("\n");
    }

    // --- Step 6: Clean up allocated memory ---
    free(set);
    free(subset);

    return 0;
}
