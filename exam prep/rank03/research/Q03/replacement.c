// Write a C function that:

//     Accepts a string, a character to find, and a replacement character as input.
//     Searches the string for all occurrences of the target character.
//     Replaces each occurrence of the target character with the replacement character.
//     Returns the modified string.

// Function Prototype

// void replace_char(char *str, char find, char replace);

// Additional Requirements:

//     The input string is modified in place (no additional memory allocation is needed).
//     Handle edge cases, such as when the string is empty or the target 
//     character does not exist in the string.

void    replace_char(char *str, char find, char replace)
{
    int i;

    i = 0;
    if (!str || !str[i])
        return ;
    while (str[i])
    {
        if (str[i] == find)
            str[i] = replace;
        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char str[6] = "Hallo";

    replace_char(str, 'a', 'L');
    printf("%s\n", str);
//    free (str);
    return (0);
}