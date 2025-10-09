#define BUFFER_SIZE 1000000
#include <string.h>
#include <unistd.h>

void ft_memset(char *str, char c, size_t bytes)
{
	size_t i =0;
	while (i<bytes)
	{
		str[i] =c;
		i++;
	}
}

void filter_str(char *str, char *filter, size_t len)
{
	char *pos = str;
	char *end = str + len;

	size_t filter_len = strlen(filter);
	while(pos<end && (pos=memmem(pos, end-pos, filter, filter_len)))
	{
		ft_memset(pos, '*', filter_len);
		pos += filter_len;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	
	static char buffer[BUFFER_SIZE];
	char *pos = buffer;
	char *end = buffer + BUFFER_SIZE -1;
	ssize_t bytes_read;

	while(pos<end && (bytes_read=read(0,pos,end-pos))>0)
		pos+=bytes_read;
	if (bytes_read < 0)
		return 1;

	size_t total_len = pos - buffer;
	buffer[total_len] = 0; //dont forget to close buffer

	filter_str(buffer, av[1], total_len);
	write(1,buffer, total_len);
	return 0;
}
