#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

char	*create_replacement(size_t len)
{
	size_t	i = 0;
	char	*replace = NULL;

	replace = (char *)malloc(sizeof(char) * (len + 1));
	if(!replace)
	{
		perror("Error: malloc");
		return NULL;
	}
	while(i < len)
	{
		replace[i] = '*';
		i++;
	}
	replace[i] = '\0';
	return replace;
}

char	*read_data(void)
{
	char	*buffer = NULL;
	size_t	buffer_size = BUFFER_SIZE;
	size_t	buffer_used = 0;
	ssize_t	bytes_read = 0;

	buffer = (char *)malloc(sizeof(char) * buffer_size);
	if(!buffer)
	{
		perror("Error: malloc");
		return NULL;
	}
	while(1)
	{
		if(buffer_used >= buffer_size - 1)
		{
			buffer_size *= 2;
			buffer = realloc(buffer, buffer_size);
			if(!buffer)
			{
				perror("Error: realloc");
				return NULL;
			}	
		}
		bytes_read = read(0, buffer + buffer_used, buffer_size - buffer_used - 1);
		if(bytes_read == 0)
			break;
		if(bytes_read < 0)
		{
			perror("Error: read");
			return NULL;
		}
		buffer_used += bytes_read;
	}
	buffer[buffer_used] = '\0';
	return buffer;

}

void	clean_memory(char *buffer, char *replace)
{
	if(buffer)
		free(buffer);
	if(replace)
		free(replace);
}

int	safe_write(char	*data, size_t len)
{
	if(len == 0)
		return 0;
	if(write(1, data, len) < 0)
	{
		perror("Error: write");
		return 1;
	}
	return 0;
}
int	process_print(char *buffer, char *filter, char *replace)
{
	size_t	filter_len = 0;
	char	*found = NULL;
	char	*current = buffer;

	filter_len = strlen(filter);
	while((found = memmem(current, strlen(current), filter, filter_len)) != NULL)
	{
		if(safe_write(current, found - current))
			return 1;
		if(safe_write(replace, filter_len))
			return 1;
		current = found + filter_len;
	}
	if(safe_write(current, strlen(current)))
		return 1;
	return 0;
}

int	main(int argc, char **argv)
{
	char	*buffer;
	char	*filter;
	char	*replacement;

	if(argc != 2)
	{
		fprintf(stderr, "Usage: [%s] [string to be filtered]\n", argv[0]);
		return 1;
	}
	filter = argv[1];
	replacement = create_replacement(strlen(filter));
	if(!replacement)
		return 1;
	buffer = read_data();
	if(!buffer)
	{
		clean_memory(buffer, replacement);
		return 1;
	}
	if(process_print(buffer, filter, replacement))
	{
		clean_memory(buffer, replacement);
				return 1;
	}
	clean_memory(buffer, replacement);
	return 0;
}
