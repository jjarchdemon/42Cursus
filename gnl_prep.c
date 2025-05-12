
// strjoin
// strlen
// strndup
// strchr
//



char *get_next_line(int fd)
{
	static char *carryover;
	char *line;

	//1.read data from file into carryover
	//2.extract single line from carryover
	if (!line)
	{
		free(carryover);
		return NULL;
	}
	//3.update carryover for next call
	return (line);
}

char *ft_strndup(char *s, size_t n)
{
	unsigned int i;
	char *new;

	new = malloc((n+1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < n)
	{
		new[i] = *s;
		i++;
		s++;
	}
	new[i] = '\0';
	return new;
}


char *ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

int ft_strlen(char *s)
{
	int len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);

	char *joined;
	int i = 0;

	joined = malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (*s1)
	{
		joined[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2;
		s2++;
		i++;
	}
	joined[i] = '\0';
	return(joined);
}

