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
        match = memmem(current, input_len - (current - input), sub, sub_len);
    }

    // Write the rest of the input after the last match
    write(STDOUT_FILENO, current, input + input_len - current);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    size_t sub_len = strlen(argv[1]);
    if (sub_len == 0)
        return 1;

    const size_t initial_buffer_size = 4096;
    char *buffer = malloc(initial_buffer_size);
    if (buffer == NULL)
        return 1;

    size_t current_buffer_size = initial_buffer_size;
    size_t data_in_buffer = 0;
    ssize_t bytes_read;

    while ((bytes_read = read(STDIN_FILENO, buffer + data_in_buffer, current_buffer_size - data_in_buffer)) > 0)
    {
        data_in_buffer += bytes_read;

        char *current = buffer;
        char *match;
        size_t processed_len = 0;

        while ((match = memmem(current, data_in_buffer - (current - buffer), argv[1], sub_len)))
        {
            // Calculate and write the part before the match
            write(STDOUT_FILENO, current, match - current);

            // Write asterisks for the matched part
            for (size_t i = 0; i < sub_len; i++)
                write(STDOUT_FILENO, "*", 1);
            
            // Advance the current pointer
            current = match + sub_len;
            processed_len = current - buffer;
        }

        // If there's a possibility of a split match at the end, move the remaining data
        if (data_in_buffer - processed_len > 0)
        {
            memmove(buffer, current, data_in_buffer - processed_len);
        }
        data_in_buffer -= processed_len;

        // The custom read function might require a larger buffer size.
        // For this example, we'll assume a fixed size, but here's where realloc would be used.
        // if (data_in_buffer + some_new_chunk_size > current_buffer_size) {
        //    current_buffer_size *= 2;
        //    char *temp = realloc(buffer, current_buffer_size);
        //    if (temp == NULL) {
        //        free(buffer);
        //        perror("Error: Failed to reallocate memory");
        //        return 1;
        //    }
        //    buffer = temp;
        // }
    }

    // Process the final remaining data in the buffer
    filter_memory(buffer, data_in_buffer, argv[1], sub_len);

    if (bytes_read < 0)
    {
        perror("Error: Failed to read from stdin");
        free(buffer);
        return 1;
    }

    free(buffer);
    return 0;
}
