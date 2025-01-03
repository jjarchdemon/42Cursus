/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:47:52 by jambatt           #+#    #+#             */
/*   Updated: 2025/01/03 12:56:53 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//joins two strings and frees the first
//returns new string
char	*join_free(char *str1, char *str2)
{
	char	*result;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (result);
}

//extract portion of buffer after the first line
//frees original buffer
//returns extracted portion
char	*trim_buffer_after_line(char *buffer)
{
	int		i;
	int		j;
	char	*remaining_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remaining_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		remaining_buffer[j++] = buffer[i++];
	free(buffer);
	return (remaining_buffer);
}

// isolates first line from buffer
char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

//reads file incrementally by BUFFER_SIZE 
//appends read data to res
//stops if \n is encountered or end of file
char	*read_expand_buffer(int fd, char *buffer_collector)
{
	char	*buffer;
	int		byte_read;

	if (!buffer_collector)
		buffer_collector = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(buffer_collector);
			return (NULL);
		}
		buffer[byte_read] = 0;
		buffer_collector = join_free(buffer_collector, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buffer_collector);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_expand_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = trim_buffer_after_line(buffer);
	return (line);
}
