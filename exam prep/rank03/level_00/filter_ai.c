#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void filter_memory(char *input, size_t input_len, char *sub, size_t sub_len)
{
    char *current = input;
    char *match;

    match = memmem(current, input_len, sub, sub_len);
    while (match)
    {
        // Write everything up to the match
        write(STDOUT_FILENO, current, match - current);

        // Write asterisks for the matched part
        for (size_t i = 0; i < sub_len; i++)
            write(STDOUT_FILENO, "*", 1);

        current = match + sub_len;
        match = memmem(current, input + input_len - current, sub, sub_len);
    }

    // Write remaining data
    write(STDOUT_FILENO, current, input + input_len - current);
}

int main(int argc, char **argv)
{
    if (argc != 2) return 1;

    size_t sub_len = strlen(argv[1]);
    if (sub_len == 0) return 1;

    size_t buffer_size = 4;
    char *buffer = malloc(buffer_size);
    if (!buffer) return 1;

    size_t data_in_buffer = 0;
    ssize_t bytes_read;

    while ((bytes_read = read(STDIN_FILENO, buffer + data_in_buffer, buffer_size - data_in_buffer)) > 0)
    {
        data_in_buffer += bytes_read;
        size_t processed = 0;

        char *current;
        while ((current = memmem(buffer + processed, data_in_buffer - processed, argv[1], sub_len)))
        {
            size_t offset = current - buffer;
            // Write everything before match
            write(STDOUT_FILENO, buffer + processed, offset - processed);

            // Write asterisks
            for (size_t i = 0; i < sub_len; i++)
                write(STDOUT_FILENO, "*", 1);

            processed = offset + sub_len;
        }

        // Move unprocessed tail to start of buffer (handles split matches)
        size_t remaining = data_in_buffer - processed;
        memmove(buffer, buffer + processed, remaining);
        data_in_buffer = remaining;

        // If buffer is almost full, double it
        if (buffer_size - data_in_buffer < 1024)  // leave room for next read
        {
            size_t new_size = buffer_size * 2;
            char *tmp = realloc(buffer, new_size);
            if (!tmp)
            {
                free(buffer);
                perror("realloc failed");
                return 1;
            }
            buffer = tmp;
            buffer_size = new_size;
        }
    }

    // Process any remaining data
    if (data_in_buffer > 0)
        filter_memory(buffer, data_in_buffer, argv[1], sub_len);

    free(buffer);

    if (bytes_read < 0)
    {
        perror("read failed");
        return 1;
    }

    return 0;
}
