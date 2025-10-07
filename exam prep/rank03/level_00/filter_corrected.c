#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void filter_str(char *input, int input_len, char *sub, int sub_len);

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    char *sub = av[1];
    int sub_len = strlen(sub);
    if (sub_len == 0)
        return 1;  // empty substring not allowed

    // We'll simulate dynamic chunk size here (just for demo)
    // For example, start at 512 bytes and increase by 256 each iteration
    size_t chunk_size = 512;

    // Allocate initial buffer with space for overlap
    char *buffer = malloc(chunk_size + sub_len - 1);
    if (!buffer) {
        perror("malloc");
        return 1;
    }

    size_t overlap_len = 0;

    while (1)
    {
        // Resize buffer if chunk_size changed
        char *tmp = realloc(buffer, chunk_size + sub_len - 1);
        if (!tmp) {
            perror("realloc");
            free(buffer);
            return 1;
        }
        buffer = tmp;

        // Read into buffer after the overlap
        ssize_t bytes_read = read(STDIN_FILENO, buffer + overlap_len, chunk_size);
        if (bytes_read < 0) {
            perror("read");
            free(buffer);
            return 1;
        }
        if (bytes_read == 0)
            break; // EOF

        size_t total_len = overlap_len + bytes_read;
        size_t process_len = (total_len >= (size_t)(sub_len - 1)) ? total_len - (sub_len - 1) : 0;

        filter_str(buffer, process_len, sub, sub_len);

        // Save last sub_len - 1 bytes as overlap for next read
        if (total_len >= (size_t)(sub_len - 1)) {
            memmove(buffer, buffer + total_len - (sub_len - 1), sub_len - 1);
            overlap_len = sub_len - 1;
        } else {
            // Not enough data for full overlap, keep all
            memmove(buffer, buffer + total_len - total_len, total_len);
            overlap_len = total_len;
        }

        // For demo, increase chunk size dynamically (optional)
        chunk_size += 256;
    }

    // Process any remaining overlap bytes
    if (overlap_len > 0)
        filter_str(buffer, overlap_len, sub, sub_len);

    free(buffer);
    return 0;
}

void filter_str(char *input, int input_len, char *sub, int sub_len)
{
    char *current = input;
    char *match;

    match = memmem(current, input_len, sub, sub_len);
    while (match)
    {
        write(STDOUT_FILENO, current, match - current);
        for (int i = 0; i < sub_len; i++)
            write(STDOUT_FILENO, "*", 1);
        current = match + sub_len;
        input_len -= (current - input);
        input = current;
        match = memmem(current, input_len, sub, sub_len);
    }
    write(STDOUT_FILENO, current, input_len);
}

