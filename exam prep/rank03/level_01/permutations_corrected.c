#include <stdio.h>

void ft_swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int ft_strlen(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void sort_str(char *str, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1])
                ft_swap(&str[j], &str[j + 1]);
        }
    }
}

// Reverse part of the array from start to end
void reverse(char *str, int start, int end) {
    while (start < end) {
        ft_swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

// Generates the next lexicographical permutation
int next_permutation(char *str, int len) {
    int i = len - 2;

    // Step 1: Find rightmost char that is smaller than its next
    while (i >= 0 && str[i] >= str[i + 1])
        i--;

    if (i < 0)
        return 0;  // no more permutations

    // Step 2: Find rightmost char greater than str[i]
    int j = len - 1;
    while (str[j] <= str[i])
        j--;

    // Step 3: Swap them
    ft_swap(&str[i], &str[j]);

    // Step 4: Reverse suffix
    reverse(str, i + 1, len - 1);

    return 1;  // next permutation exists
}

int main(int ac, char **av) {
    if (ac != 2)
        return 1;

    char *str = av[1];
    int len = ft_strlen(str);

    sort_str(str, len);  // start from lowest lex order
    puts(str);           // print the first permutation

    // Generate all remaining permutations in lexicographical order
    while (next_permutation(str, len))
        puts(str);

    return 0;
}

