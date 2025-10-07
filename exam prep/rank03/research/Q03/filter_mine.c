#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filter_string(const char *input, const char *substring)
{
    size_t sub_len = strlen(substring);
    if (sub_len == 0) // Nothing to filter
    {
        printf("%s", input);
        return;
    }

    const char *ptr = input;
    while (*ptr)
    {
        if (strncmp(ptr, substring, sub_len) == 0)
        {
            for (size_t i = 0; i < sub_len; i++)
                putchar('*');
            ptr += sub_len;
        }
        else
        {
            putchar(*ptr);
            ptr++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <substring>\n", argv[0]);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), stdin))
    {
        filter_string(line, argv[1]);
    }

    return 0;
}
