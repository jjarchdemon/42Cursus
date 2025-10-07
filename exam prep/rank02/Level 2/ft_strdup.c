#include <stdlib.h>

char *ft_strdup(char *src)
{
	int len =0;
	char *temp;
	while (*src)
		len++;
	temp = malloc((sizeof(char)*len)+ 1);
	if (!temp)
		return (NULL);
	char *retemp = temp;
	while (*src)
		{
			*temp = *src;
			src++;
			temp++;
		}
	*temp = '\0';
	return (retemp);
}
