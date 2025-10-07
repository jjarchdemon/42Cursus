#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* nums, int numsSize, int** result, int* returnSize, int* current, int* used, int row) {
    if (row == numsSize) { // Check if the current permutation is complete
        result[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], current, numsSize * sizeof(int));
        (*returnSize)++;
        return;
    }

    int i = 0;
    while (i < numsSize) {
        if (used[i]) {
            i++;
            continue; // Skip already used elements
        }
        used[i] = 1;
        current[row] = nums[i];
        backtrack(nums, numsSize, result, returnSize, current, used, row + 1);
        used[i] = 0; // Backtrack
        i++;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = 1;
    int i = 1;
    while (i <= numsSize) {
        totalPermutations *= i; // Calculate factorial of numsSize
        i++;
    }

    int** result = malloc(totalPermutations * sizeof(int*));
    *returnColumnSizes = malloc(totalPermutations * sizeof(int));
    *returnSize = 0;

    int* current = malloc(numsSize * sizeof(int));
    int* used = calloc(numsSize, sizeof(int));

    backtrack(nums, numsSize, result, returnSize, current, used, 0);

    i = 0;
    while (i < *returnSize) {
        (*returnColumnSizes)[i] = numsSize;
        i++;
    }

    free(current);
    free(used);

    return result;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = 3;
    int returnSize;
    int* returnColumnSizes;
    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Permutations:\n");
    int i = 0;
    while (i < returnSize) {
        int j = 0;
        while (j < numsSize) {
            printf("%d ", result[i][j]);
            j++;
        }
        printf("\n");
        free(result[i]); // Free each permutation
        i++;
    }
    free(result);           // Free the result array
    free(returnColumnSizes); // Free the column sizes array
    return 0;
}
