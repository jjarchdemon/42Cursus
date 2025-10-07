#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while(s[len])
		len++;
	return len;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!str)
		return NULL;
	i = 0;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return str;
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	i;

	if(!s)
		return NULL;
	size = ft_strlen(s);
	if (start > size)
		len = 0;
	if (size - start < len)
		len = size - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while ( i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return str;
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char)c;
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if(c == '\0')
		return ((char *)&s[i]);
	return NULL;
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if(!str)
		return NULL;
	i = 0;
	while(s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

char	*read_data(char *buffer, char *str, int fd)
{
	size_t	read_bytes;
	char	*temp;

	while(!ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes == 0 && str[0] == '\0')
		{
			free(str);
			return NULL;
		}
		if(read_bytes <= 0)
			return str;
		buffer[read_bytes] = '\0';
		temp = str;
		str = ft_strjoin(temp, buffer);
		free(temp);
	}
	return str;
}

char	*get_line(char *str, size_t *line_init)
{
	char	*line;
	size_t	i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if(str[i] ==  '\n')
		*line_init = i + 1;
	else
		*line_init = i;
	line = ft_substr(str, 0, *line_init);
	return line;
}

char	*update_str(char *str, size_t line_init)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(str) - line_init;
	if(len <= 0)
	{
		free(str);
		return NULL;
	}
	new_str = ft_substr(str, line_init, len);
	free(str);
	return new_str;
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*str;
	char	*line;
	size_t	line_init;

	if( fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return NULL;
	if (!str)
		str = ft_strdup("");
	str = read_data(buffer, str, fd);
	if(!str)
	{
		free(buffer);
		return NULL;
	}
	line = get_line(str, &line_init);
	if(!line)
	{
		free(buffer);
		return NULL;
	}
	str = update_str(str, line_init);
	free(buffer);
	return line;
}
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int	main(void)
{
	/*
	char	s1[] = "Hello ";
	char	s2[] = "World!";
	
	char	*joined;
	char	*sub;
	char	*my_search;
	char    *org_search;
	char	*my_dup;
	char	*org_dup;

	joined = ft_strjoin(s1, s2);
	printf("ft_strjoin: %s\n", joined);
	sub = ft_substr(joined, 6, 80);
	printf("ft_substr: %s\n", sub);
	my_search = ft_strchr(joined, 'o');
	printf("ft_strchr: %s\n", my_search);
	org_search = strchr(joined, 'o');
	printf("strchr: %s\n", org_search);
	my_dup = ft_strdup(joined);
	printf("ft_strdup: %s\n", my_dup);
	org_dup = strdup(joined);
	printf("strdup: %s\n", org_dup);
	free(joined);
	free(sub);
	free(my_dup);
	free(org_dup);
	*/
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if(fd < 0)
		return 1;
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if(line)
		free(line);
	close(fd);
	return 0;
}
