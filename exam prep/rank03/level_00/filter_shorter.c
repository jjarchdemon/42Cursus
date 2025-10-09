#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1048576

void ft_memset(char *ptr, char c, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
}

void filter_string(char *str, char *filter, size_t len)
{
	size_t filter_len = strlen(filter);
	if (!filter_len)
		return;
	char *pos = str;
	char *end = str + len;
	while (pos < end && (pos = memmem(pos, end - pos, filter, filter_len)))
	{
		ft_memset(pos, '*', filter_len);
		pos += filter_len;
	}
	return;
}

int main(int argc, char **argv)
{
	static char buffer[BUFFER_SIZE];
	char *pos = buffer;
	char *end = buffer + BUFFER_SIZE - 1;
	ssize_t bytes_read;
	
	if (argc != 2)
		return 1;
		
	while (pos < end && (bytes_read = read(0, pos, end - pos)) > 0)
		pos += bytes_read;
	if (bytes_read < 0)
		return 1;

	size_t total_len = pos - buffer;//total len of bytes read
	buffer[total_len] = 0;
	
	filter_string(buffer, argv[1], total_len);
	
	write(1, buffer, total_len);
	return 0;
}