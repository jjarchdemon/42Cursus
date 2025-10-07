//scale
//search copy append length empty

#define BUFFER_SIZE 5
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int str_length(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int str_search(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return -1;
}

void str_empty(char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}

void str_copy(char *dest, const char *src, int len)
{
	int i = 0;
	if (len >= 0)
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
}

void str_append(char *dest, const char *src, int len)
{
	int i = 0, j = 0;
	while (dest[i])
		i++;
	while (j < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
}


char *get_next_line(int fd)
{
	static char	hold[1000000];
	char		temp[1000000];
	char		buffer[BUFFER_SIZE + 1];
	char		*line = NULL;
	int		bytes = 0;
	int		location;

	while (str_search(hold, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buffer[bytes] = '\0';
		str_append(hold, buffer, bytes);// !!you had put -1 before
	}
	if (str_length(hold) == 0)
		return NULL; 		//why do we do this
	location = str_search(hold,'\n');
	if (location >= 0)
	{
		line = malloc(sizeof(char) * (location + 2));
		str_copy(line, hold, location + 1);
		line[location + 1] = '\0'; //uhhh
		str_copy(temp, hold, -1);
		str_empty(hold);
		str_copy(hold, &temp[location + 1], -1); //think with example
	}
	else
	{
		line = malloc(sizeof(char) * (str_length(hold)+1) );
		str_copy(line, hold, -1);
		line[str_length(hold)] = '\0';
		str_empty(hold);
	}
	return line;

}


int main(void)
{
	int fd = open("example.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	close(fd);
	return 0;

}


