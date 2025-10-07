#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 25
# endif

char *ft_strjoin(char *first, char *second)
{
    char *result;
    int len_first;
    int len_second;
    int i;
    int j;

    if (!first || !first[0])
    {
        first = malloc(1 * sizeof(char));
        if (!first)
            return (NULL);
        first[0] = '\0';
    }
    if (!second || !second[0])
        return (first);
    len_first = strlen(first);
    len_second = strlen(second);
    result = malloc ((len_first + len_second + 1) * sizeof (char));
    if (!result)
       return (free (first), NULL);
    i = 0;
    while (i < len_first)
    {
        result[i] = first[i];
        i++;
    }
    j = 0;
    while (i < len_first + len_second)
    {
        result[i] = second[j];
        i++;
        j++;
    }
    result[i] = '\0';
    free (first);
    return (result);
}


char *clear_line(char *buffer)
{
    int i;
    int j;
    int len;
    char *new_buffer;
   
    if (!buffer || !strchr(buffer, '\n'))
    {
        free (buffer);
        return (NULL);
    }
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        i++;
    }
    if (buffer[i] = '\n')
        i++;
    j = 0;
    len = strlen(buffer + i);
    new_buffer = malloc ((len + 1) * sizeof (char));
    while (buffer[i + j])
    {
        new_buffer[j] = buffer[i + j];
        j++;
    }
    new_buffer[j] = '\0';
    free (buffer);
    return (new_buffer);
}

char *get_line(char *buffer)
{
    char *line;
    int i;
    int j;

    if (!buffer || !buffer[0])
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    line = malloc ((i + 1) * sizeof (char));
    if (!line)
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = buffer[j];
        j++;
    }
    line[j] = 0;
    return (line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char        reader[BUFFER_SIZE + 1];
    char        *line;
    int         bytes_read;

    bytes_read = 1;
    line = NULL;
    if (BUFFER_SIZE < 1)
        return (NULL);
    if (fd < 0)
        return (NULL);
    while (1)
    {
        bytes_read = read(fd, reader, BUFFER_SIZE);
        reader[bytes_read] = 0;
        buffer = ft_strjoin(buffer, reader);
        if (!buffer)
            return (NULL);
        if (strchr(reader, '\n') || bytes_read == 0)
            break ;
    }
    line = get_line(buffer);
    buffer = clear_line(buffer);
    return (line);
}

int main (void)
{
    char *result;
    int  fd;

    fd = open("floodfill.c", O_RDONLY);
    result = get_next_line(fd);
    while (result)
    {
        printf("%s", result);
        free (result);
        result = get_next_line(fd);
    }
    free (result);
    printf("\n");
    return (0);
}
