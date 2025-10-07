// Write a C program that:

//     Reads an entire line of text from standard input
//      (up to a newline character '\n' or EOF).
//     Dynamically allocates memory for the string using malloc.
//     Transfers the data from the buffer to the dynamically allocated string.
//     Prints the dynamically allocated string to the console.
//     Frees the allocated memory after use.

// Additional Requirements:

//     You cannot use getline() or other high-level functions for dynamic input handling.
//     Your program must handle the case where the user inputs a very long
//      string (longer than the initial buffer size).
//     Ensure proper error handling for malloc and other potential edge cases.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 20
#endif

char *ft_clear_line(char *line_buffer);

char   *ft_strjoin(char *existing, char *add)
{
    int existing_length;
    int add_length;
    int result_length;
    char *result;
    int i, j;

    if (!existing)
    {
        existing = malloc (1);
        existing[0] = '\0';
    }
    existing_length = strlen(existing);
    add_length = strlen(add);
    if (!add)
        return (existing);
    result = malloc (sizeof(char) * (existing_length + add_length + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (existing[i])
    {
        result[i] = existing[i];
        i++;
    }
    j = 0;
    while (add[j])
    {
        result[i] = add[j];
        i++;
        j++;
    }
    result[i] = '\0';
    free (existing);
    return (result);
}

char *ft_get_line(char *line_buffer)
{
    int i;
    char *line;
    int j;

    i = 0;
    if (!line_buffer[i])
        return (NULL);
    while (line_buffer[i] && line_buffer[i] != '\n')
    {
        i++;
    }
    if (line_buffer[i] == '\n')
        i++;
    line = malloc (sizeof(char) * (i + 1));
    if (!line)
    {
        free (line_buffer);
        return (NULL);
    }
    j = 0;
    while (j < i )
    {
        line[j] = line_buffer[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

char    *get_next_line(int fd)
{
    int bytes_read;
    char *reader;
    static char *line_buffer;
    char *line;

    bytes_read = 1;
    reader = malloc (sizeof(char) * (BUFFER_SIZE + 1));
    if (!reader)
        return (NULL);
    while (bytes_read != 0 && (!line_buffer || strchr(line_buffer, '\n') == NULL))
    {
        bytes_read = read(fd, reader, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free (reader);
            free (line_buffer);
            return (NULL);
        }
        reader[bytes_read] = '\0';
        line_buffer = ft_strjoin(line_buffer, reader);
        if (!line_buffer)
        {
            free (reader);
            free (line_buffer);
            return (NULL);
        }
    }
    free (reader);
    line = ft_get_line(line_buffer);
	line_buffer = ft_clear_line(line_buffer);
    return (line);
}

char *ft_clear_line(char *line_buffer)
{
	int	i;
	int j;
	int	buffer_length;
	char *new_buffer;

	i = 0;
	if (!line_buffer || !line_buffer[0])
	{
		free (line_buffer);
		return (NULL);
	}
	buffer_length = strlen(line_buffer);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
    if (line_buffer[i] == '\n')
        i++;
	new_buffer = malloc(sizeof(char) * (buffer_length - i + 1));
	j = 0;
	while (i < buffer_length)
	{
		new_buffer[j] = line_buffer[i];
		i++;
		j++;
	}
	new_buffer[j] = '\0';
	free(line_buffer);
	return (new_buffer);
}

int main (void)
{
    char    *line;
	int fd;

	fd = open("replacement.c", O_RDONLY);
//    fd = 0;
    line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
    return (0);
}
