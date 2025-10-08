#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

//scale

int str_len(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void str_empty(char *str)
{
	int i =0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	str[i] = 0;
}

int str_search(char *str, char c)
{
	int i =0;
	while(str[i])
	{
		if (c == str[i])
			return i;
		i++;
	}
	return -1;
}

void str_append(char *dest, char *src, int len)
{
	int i = 0;
	int j = 0;
	while(dest[i])
		i++;
	if (len > 0)
	{
		while (j < len)
		{
			dest[i] = src[j];
			i++;j++;
		}
	}
	dest[i] = 0;
}

void str_copy(char *dest, char *src, int len)
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
		while (str[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
}


char *gnl(int fd)
{
	static char hold[1000000];
	char temp[1000000];
	char buffer[BUFFER_SIZE + 1];
	char *line = NULL;
	int bytes = 0;
	int location;
	
	while (str_search(hold, '\n') == -1)	//if or while
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buffer[bytes] = 0;
		str_append(hold, buffer, bytes);
	}	

	if (str_len(hold) == 0)
		return NULL;

	location = str_search(hold, '\n');
	if (location >= 0)
	{
		line = malloc(sizeof(char) * location+2);
		str_copy(line, hold, location+1);
		line[location+1] = 0;
		str_copy(temp, hold, -1);
		str_empty(hold);
		str_copy(hold, &temp[location+1], -1);
	}
	else
	{
		line = malloc(sizeof(char) * str_len(hold)+1);
		str_copy(line, hold, -1);
		line[str_len(hold)] = 0;
		str_empty(hold);
	}
	return line;
}

int main(void)
{
	int fd = read("example.txt", O_RDONLY);

	int i = 0;
	while (i < 4)
	{
		printf("%s", gnl(fd));
		i++;
	}
	return 0;
}

































