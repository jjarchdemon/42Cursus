#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Filters the input and replaces occurrences of `sub` with asterisks
void filter_memory(char *input, size_t input_len, char *sub, size_t sub_len)
{
    char *current = input;
    char *match;

	match = memmem(current, input_len, sub, sub_len);
    while (match)
    {
        // Write everything up to the match
        write(STDOUT_FILENO, current, match - current);

        // Write asterisks in place of the matched substring
        for (size_t i = 0; i < sub_len; i++)
            write(STDOUT_FILENO, "*", 1);

        // Move past the match
        current = match + sub_len;
		match = memmem(current, input_len, sub, sub_len);
    }

    // Write the rest of the input after the last match
    write(STDOUT_FILENO, current, input + input_len - current);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        const char *usage = "Usage: ./a.out <substring>\n";
        write(STDERR_FILENO, usage, strlen(usage));
        return 1;
    }

    char buffer[1024];
    size_t sub_len = strlen(argv[1]);

    if (sub_len == 0)
    {
        const char *error = "Error: Substring cannot be empty.\n";
        write(STDERR_FILENO, error, strlen(error));
        return 1;
    }

    ssize_t bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
    while (bytes_read > 0)
    {
        filter_memory(buffer, (size_t)bytes_read, argv[1], sub_len);
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
    }
    if (bytes_read < 0)
    {
        const char *error = "Error: Failed to read from stdin.\n";
        write(STDERR_FILENO, error, strlen(error));
        return 1;
    }

    return 0;
}
